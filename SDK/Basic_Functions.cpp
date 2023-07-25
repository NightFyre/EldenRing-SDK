#pragma once
#include "../SDK.h"

/**
 * Name: Elden Ring
 * Version: ~
 * Engine: ~
*/

#pragma pack(push, 0x01)
namespace HEXINTON
{

	GameManager* CGlobals::GGameMan;
	GameDataManager* CGlobals::GGameDataMan;
	WorldCharacterManager* CGlobals::GWorldCharMan;

	//---------------------------------------------------------------------------------------------------
	// 
	//	----------	[SECTION] GLOBALS
	//
	//---------------------------------------------------------------------------------------------------

    bool InitSdk() { return InitSdk("EldenRing.exe", 0x3CE0708, 0x3CD4D88, 0x3CDCDD8); }
	bool InitSdk(const std::string& moduleName, uintptr_t gGameMan, uintptr_t gGameDataMan, uintptr_t gWorldCharMan)
	{
		auto mBaseAddress = reinterpret_cast<uintptr_t>(GetModuleHandleA(moduleName.c_str()));
		if (!mBaseAddress)
			return false;

		CGlobals::GGameMan = reinterpret_cast<HEXINTON::GameManager*>(*(reinterpret_cast<__int64*>(mBaseAddress + gGameMan)));
		CGlobals::GGameDataMan = reinterpret_cast<HEXINTON::GameDataManager*>(*(reinterpret_cast<__int64*>(mBaseAddress + gGameDataMan)));
		CGlobals::GWorldCharMan = reinterpret_cast<HEXINTON::WorldCharacterManager*>(*(reinterpret_cast<__int64*>(mBaseAddress + gWorldCharMan)));

		return TRUE;
	}

	void ShutdownSdk()
	{

	}

	unsigned int GetVtblOffset(void* czInstance, const char* dwModule)
	{
		uintptr_t moduleBase = (uintptr_t)GetModuleHandleA(NULL);
		return ((*(unsigned int*)czInstance) - moduleBase);
	}

	int GetVtblIndex(void* fncPtr, void* vTblAddr) { return (((__int64)fncPtr - (__int64)vTblAddr) / sizeof(void*)) - 1; }
}
#pragma pack(pop)