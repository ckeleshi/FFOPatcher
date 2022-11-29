#include "../common/stdinc.h"
#include "../common/patch.h"

HMODULE DDRAWModule;
FARPROC fnDirectDrawCreate;

__declspec(naked) void* WINAPI DirectDrawCreate_stub(UINT SDKVersion)
{
    __asm { jmp fnDirectDrawCreate }
}

void LoadDDRAW()
{
    WCHAR* szSystemPath = nullptr;

    SHGetKnownFolderPath(FOLDERID_System, 0, NULL, &szSystemPath);

    std::wstring wstr = szSystemPath;

    CoTaskMemFree(szSystemPath);

    DDRAWModule = LoadLibraryW((wstr + L"\\ddraw.dll").c_str());
    fnDirectDrawCreate = GetProcAddress(DDRAWModule, "DirectDrawCreate");
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        LoadDDRAW();
        Patch(hModule);
        break;
    }

    default:
        break;
    }

    return TRUE;
}
