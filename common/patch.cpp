#include "patch.h"
#include "byte_pattern.h"
#include "injector/hooking.hpp"

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
} g_period_guard;

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

    return std::clamp(GetPrivateProfileIntW(L"FFOPatcher", L"FrameInterval", 15u, cppPath.wstring().c_str()), 1u, 29u);
}

void Patch(HMODULE module)
{
    auto frame_interval = static_cast<unsigned char>(ReadInterval(module));

    byte_pattern patterner;

    //修改帧间隔，0x1D为游戏默认值29
    patterner.find_pattern("83 F8 1D 73 0D 6A 1D");
    if (patterner.has_size(1))
    {
        injector::WriteMemory<unsigned char>(patterner.get_first().i(2), frame_interval, true);
        injector::WriteMemory<unsigned char>(patterner.get_first().i(6), frame_interval, true);
    }

    //完全替换游戏使用的所有timeGetTime函数为较高精度版本
    patterner.find_pattern("8B 35 ? ? ? ? 59 FF D6");
    if (patterner.has_size(1))
    {
        injector::WriteMemory(*patterner.get_first().p<std::uintptr_t>(2), &accurate_timeGetTime, true);
    }
}
