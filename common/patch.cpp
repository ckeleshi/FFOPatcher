#include "patch.h"
#include "byte_pattern.h"
#include "injector/hooking.hpp"
#include <optional>

#pragma comment(lib, "winmm.lib")

//提高Sleep函数的精度
class time_period_guard
{
public:
    time_period_guard()
    {
        std::memset(&_caps, 0, sizeof(_caps));
        timeGetDevCaps(&_caps, sizeof(_caps));
        timeBeginPeriod(_caps.wPeriodMin);
    }

    ~time_period_guard()
    {
        timeEndPeriod(_caps.wPeriodMin);
    }

private:
    TIMECAPS _caps;
};

std::optional<time_period_guard> g_period_guard;

//单个进程只进行一次patch
class inprocess_singleton
{
public:
    inprocess_singleton()
    {
        wchar_t mutex_name_buffer[MAX_PATH];

        std::swprintf(mutex_name_buffer, L"FFOPATCHER_MUTEX_%u", GetCurrentProcessId());

        auto mutex = CreateMutexW(nullptr, FALSE, mutex_name_buffer);

        if (mutex != nullptr && GetLastError() != ERROR_ALREADY_EXISTS)
        {
            _mutex = mutex;
        }
    }

    ~inprocess_singleton()
    {
        if (_mutex)
        {
            CloseHandle(_mutex);
        }
    }

    bool is_first_load() const {
        return _mutex != nullptr;
    }

private:
    HANDLE _mutex;
} g_singleton;

//提高时间戳的精度
DWORD WINAPI accurate_timeGetTime()
{
    return static_cast<DWORD>(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now() - std::chrono::steady_clock::time_point{}).count());
}


UINT ReadInterval(HMODULE module)
{
    wchar_t cPath[MAX_PATH];
    std::filesystem::path cppPath;

    GetModuleFileNameW(module, cPath, MAX_PATH);
    cppPath = cPath;
    cppPath = cppPath.parent_path() / L"ffopatcher.ini";

    return std::clamp(GetPrivateProfileIntW(L"FFOPatcher", L"FrameInterval", 15u, cppPath.wstring().c_str()), 0u, 29u);
}

void Patch(HMODULE module)
{
    if (!g_singleton.is_first_load())
    {
        return;
    }

    g_period_guard.emplace();

    auto frame_interval = static_cast<unsigned char>(ReadInterval(module));

    byte_pattern patterner;

    patterner.find_pattern("83 F8 1D 73 0D 6A 1D");
    if (patterner.has_size(1))
    {
        //修改帧间隔，0x1D为游戏默认值29
        injector::WriteMemory<unsigned char>(patterner.get_first().i(2), frame_interval, true);
        injector::WriteMemory<unsigned char>(patterner.get_first().i(6), frame_interval, true);

        //想要极限帧数时，Sleep 0而不是Sleep 1
        if (frame_interval == 0) {
            /*
             add eax, 0xA; 83 C0 0A
             改为
             nop;          90
             xor eax eax;  33 C0
             */
            unsigned char asm_bytes[] = { 0x90,0x33,0xC0 }; //nop; xor eax,eax;
            injector::WriteMemoryRaw(patterner.get_first().i(0x20), asm_bytes, sizeof(asm_bytes), true);
        }
    }

    //完全替换游戏使用的所有timeGetTime函数为较高精度版本
    patterner.find_pattern("8B 35 ? ? ? ? 59 FF D6");
    if (patterner.has_size(1))
    {
        injector::WriteMemory(*patterner.get_first().p<std::uintptr_t>(2), &accurate_timeGetTime, true);
    }
}
