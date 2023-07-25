// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

static bool g_running = FALSE;
void WINAPI MainThread(LPVOID hInst)
{
    // Initialize SDK
	g_running = HEXINTON::InitSdk();
	
	do
	{
		//	Test Access Player Health
		if (GetAsyncKeyState(VK_NUMPAD0) & 1)
		{
			// Get World Char Man
			auto worldCharMan = *HEXINTON::CGlobals::GWorldCharMan;
			if (worldCharMan != nullptr)
			{
				// Get Local Player
				auto localPlayer = worldCharMan->GetLocalPlayer();
				if (localPlayer != nullptr)
				{
					// Get Player Instance
					auto playerInstance = localPlayer->GetPlayerInstance();
					if (playerInstance != nullptr)
					{
						// Get char modules
						auto charModules = playerInstance->GetCharacterModules();
						if (charModules != nullptr)
						{
							//	Get char data
							auto charData = charModules->GetCharData();
							if (charData != nullptr)
								charData->SetHealth(NULL);	// kills the local player
						}
					}
				}
			}
		}

		// Shutdown SDK & EXIT
		if (GetAsyncKeyState(VK_END) & 1)
		{
			HEXINTON::ShutdownSdk();
			g_running = FALSE;
		}

	} while (g_running);

	//	Exit
    FreeLibraryAndExitThread(static_cast<HMODULE>(hInst), g_running);
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        reinterpret_cast<void*>(CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hModule, NULL, NULL));

    return TRUE;
}

