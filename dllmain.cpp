// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

static bool g_running		= FALSE;		//	SDK State
static bool bInfHealth		= FALSE;		//	infinite health cheat toggle
static bool bInfMana		= FALSE;		//	infinite mana cheat toggle
static bool bInfStamina		= FALSE;		//	infinite stamina cheat toggle

//	Template function for toggling options by passed boolean reference
//	includes a nice sound effect to notify users of an on and off state
void ToggleOption(bool& ref)
{
	ref ^= 1;
	switch (ref)
	{
		case TRUE:	Beep(300, 300);	break;	//	ACTIVATED
		case FALSE: Beep(200, 300);	break;	//	DE-ACTIVATED
	}
}

//	Background thread for executing cheat methods.
//	not really necessary here, though its been included as an example
void CheatThread()
{
	while (g_running)
	{
		auto worldCharMan = *HEXINTON::CGlobals::GWorldCharMan;
		
		//	Set health to max health
		if (bInfHealth)
		{
			if (worldCharMan != nullptr)
			{
				auto charData = worldCharMan->GetLocalPlayerCharData();
				if (charData != nullptr)
				{
					auto maxHP = charData->GetMaxHealth();
					if (maxHP > NULL)
						charData->SetHealth(maxHP);
				}
			}
		}

		//	Set mana to max mana
		if (bInfMana)
		{
			if (worldCharMan != nullptr)
			{
				auto charData = worldCharMan->GetLocalPlayerCharData();
				if (charData != nullptr)
				{
					auto maxMP = charData->GetMaxMana();
					if (maxMP > NULL)
						charData->SetMana(maxMP);
				}
			}
		}

		//	Set stamina to max stamina
		if (bInfStamina)
		{
			if (worldCharMan != nullptr)
			{
				auto charData = worldCharMan->GetLocalPlayerCharData();
				if (charData != nullptr)
				{
					auto maxSP = charData->GetMaxStamina();
					if (maxSP > NULL)
						charData->SetStamina(maxSP);
				}
			}
		}
	}
}

static 
void WINAPI MainThread(LPVOID hInst)
{
	g_running = HEXINTON::InitSdk();

	std::thread ThreadWorker(CheatThread);
	
	do
	{
		// Toggle health cheat
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
			ToggleOption(bInfHealth);

		//	toggle mana cheat
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
			ToggleOption(bInfMana);

		//	toggle stamina cheat
		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
			ToggleOption(bInfStamina);

		// Shutdown SDK & EXIT
		if (GetAsyncKeyState(VK_END) & 1)
			ToggleOption(g_running);

	} while (g_running);

	ThreadWorker.join();

	HEXINTON::ShutdownSdk();

	//	Exit
    FreeLibraryAndExitThread(static_cast<HMODULE>(hInst), g_running);
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        reinterpret_cast<void*>(CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hModule, NULL, NULL));

    return TRUE;
}

