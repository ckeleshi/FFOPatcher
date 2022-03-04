#include "patch.h"
#include "byte_pattern.h"
#include "injector/hooking.hpp"

std::uint64_t g_ran_count = 0;

DWORD WINAPI accurate_timeGetTime()
{
    if (g_ran_count < std::numeric_limits<std::uint64_t>::max())
    {
        ++g_ran_count;
    }

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

    auto interval = GetPrivateProfileIntW(L"FFOPatcher", L"FrameInterval", 29, cppPath.wstring().c_str());

    if (interval < 1)
        interval = 1;

    if (interval > 29)
        interval = 29;

    return interval;
}

void Patch(HMODULE module)
{
    auto frame_interval = static_cast<unsigned char>(ReadInterval(module));

    byte_pattern patterner;

    patterner.find_pattern("83 F8 1D 73 0D 6A 1D");
    if (patterner.has_size(1))
    {
        injector::WriteMemory<unsigned char>(patterner.get_first().i(2), frame_interval, true);
        injector::WriteMemory<unsigned char>(patterner.get_first().i(6), frame_interval, true);
    }

    patterner.find_pattern("8B 35 ? ? ? ? 59 FF D6");
    if (patterner.has_size(1))
    {
        injector::WriteMemory(*patterner.get_first().p<std::uintptr_t>(2), &accurate_timeGetTime, true);
    }
}

void Finalize(HMODULE module)
{
    wchar_t cPath[MAX_PATH];
    std::filesystem::path cppPath;

    GetModuleFileNameW(module, cPath, MAX_PATH);
    cppPath = cPath;
    cppPath = cppPath.parent_path() / L"ffopatcher_log.txt";

    auto out = std::fopen(cppPath.string().c_str(), "w");
    if (!out)
    {
        return;
    }

    std::fprintf(out, "%llu", g_ran_count);

    std::fflush(out);
    std::fclose(out);
}
