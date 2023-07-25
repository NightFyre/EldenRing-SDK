// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

void WINAPI MainThread(HMODULE hInst)
{
    // Initialize SDK
    HEXINTON::InitSdk();
    
    // Access class variables & hook functions


    // Shutdown SDK
    HEXINTON::ShutdownSdk();

    FreeLibraryAndExitThread(hInst, EXIT_SUCCESS);
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        reinterpret_cast<void*>(CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hModule, NULL, NULL));

    return TRUE;
}

