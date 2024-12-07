#include "patch.h"
#include "byte_pattern.h"
#include "injector/hooking.hpp"

#pragma comment(lib, "winmm.lib")

//���Sleep�����ľ���
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

//���ʱ����ľ���
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

    //�޸�֡�����0x1DΪ��ϷĬ��ֵ29
    patterner.find_pattern("83 F8 1D 73 0D 6A 1D");
    if (patterner.has_size(1))
    {
        injector::WriteMemory<unsigned char>(patterner.get_first().i(2), frame_interval, true);
        injector::WriteMemory<unsigned char>(patterner.get_first().i(6), frame_interval, true);
    }

    //��ȫ�滻��Ϸʹ�õ�����timeGetTime����Ϊ�ϸ߾��Ȱ汾
    patterner.find_pattern("8B 35 ? ? ? ? 59 FF D6");
    if (patterner.has_size(1))
    {
        injector::WriteMemory(*patterner.get_first().p<std::uintptr_t>(2), &accurate_timeGetTime, true);
    }
}
