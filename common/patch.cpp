#include "patch.h"
#include "byte_pattern.h"
#include "injector/hooking.hpp"

DWORD WINAPI accruate_timeGetTime()
{
	auto time_point_in_ms = std::chrono::steady_clock::now();

	return static_cast<DWORD>(std::chrono::duration_cast<std::chrono::milliseconds>(time_point_in_ms - std::chrono::steady_clock::time_point{}).count());
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
		injector::WriteMemory(*patterner.get_first().p<std::uintptr_t>(2), &accruate_timeGetTime, true);
	}
}
