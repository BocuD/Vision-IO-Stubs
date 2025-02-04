#include <windows.h>
#include <format>

extern "C" void __stdcall StartWatchingDevice()
{
}

extern "C" void __stdcall EndWatchingDevice()
{
}

extern "C" bool __stdcall IsTouchPanelEnable()
{
    return true;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}

