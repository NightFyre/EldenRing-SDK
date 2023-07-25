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
	uint32_t ChrIns::GetHP()
	{
		// Get Modules
		ChrModules* modules = this->Modules;
		if (modules == nullptr)
			return -1;

		// Obtain Unit Data
		UnitData* unitData = modules->UnitData;
		if (unitData == nullptr)
			return -1;

		//	Get Current Health
		return unitData->Health;
	}

	uint32_t ChrIns::GetMaxHP()
	{
		// Get Modules
		ChrModules* modules = this->Modules;
		if (modules == nullptr)
			return -1;

		// Obtain Unit Data
		UnitData* unitData = modules->UnitData;
		if (unitData == nullptr)
			return -1;

		return unitData->MaxHealth;
	}

	Vector3 ChrIns::GetPos()
	{
		// Get Modules
		ChrModules* modules = this->Modules;
		if (modules == nullptr)
			return { 0, 0, 0 };

		// Obtain physics
		ChrPhysics* physics = modules->Physics;
		if (physics == nullptr)
			return { 0, 0, 0 };

		return physics->Pos;
	}

	void ChrIns::SetPos(Vector3 In)
	{
		// Get Modules
		ChrModules* modules = this->Modules;
		if (modules == nullptr)
			return;

		// Obtain physics
		ChrPhysics* physics = modules->Physics;
		if (physics == nullptr)
			return;

		physics->Pos = In;
	}

	float ChrIns::GetDistance(Vector3 Other)
	{
		return GetPos().DistTo(Other);
	}
}
#pragma pack(pop)