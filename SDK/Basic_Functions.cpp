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

	//---------------------------------------------------------------------------------------------------
	// 
	//	----------	[SECTION] GLOBALS
	//
	//---------------------------------------------------------------------------------------------------

    bool InitSdk() { return InitSdk("EldenRing.exe"); }
	bool InitSdk(const std::string& moduleName)
	{
		auto mBaseAddress = reinterpret_cast<uintptr_t>(GetModuleHandleA(moduleName.c_str()));
		if (!mBaseAddress)
			return false;

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