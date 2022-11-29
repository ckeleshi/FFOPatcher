#include "../common/stdinc.h"
#include "../common/patch.h"

HMODULE D3D8Module;
FARPROC fnDirect3DCreate8;

__declspec(naked) void* WINAPI Direct3DCreate8_stub(UINT SDKVersion)
{
    __asm { jmp fnDirect3DCreate8 }
}

void LoadD3D8()
{
    WCHAR* szSystemPath = nullptr;

    SHGetKnownFolderPath(FOLDERID_System, 0, NULL, &szSystemPath);

    std::wstring wstr = szSystemPath;

    CoTaskMemFree(szSystemPath);

    D3D8Module = LoadLibraryW((wstr + L"\\d3d8.dll").c_str());
    fnDirect3DCreate8 = GetProcAddress(D3D8Module, "Direct3DCreate8");
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
        LoadD3D8();
        Patch(hModule);
        break;
    }

    default:
        break;
    }

    return TRUE;
}
