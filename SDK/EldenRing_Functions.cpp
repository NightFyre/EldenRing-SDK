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

	// --------------------------------------------------
	// # WorldCharacterManager
	// --------------------------------------------------
	LocalPlayer* WorldCharacterManager::GetLocalPlayer() 
	{
		LocalPlayer* result = nullptr;

		if (this->pLocalPlayer != nullptr)
			result = this->pLocalPlayer;

		return result;
	}

	// --------------------------------------------------
	// # LocalPlayer
	// --------------------------------------------------
	PlayerInstance* LocalPlayer::GetPlayerInstance() 
	{ 
		PlayerInstance* result = nullptr;

		if (this->pPlayer != nullptr)
			result = this->pPlayer;

		return result;
	}

	// --------------------------------------------------
	// # PlayerInstance
	// --------------------------------------------------
	CharacterModules* PlayerInstance::GetCharacterModules() 
	{ 
		CharacterModules* result = nullptr;

		if (this->pCharModules != nullptr)
			result = this->pCharModules;

		return result;
	}
	
	int32_t	PlayerInstance::GetCharType() { return this->CharacterType; }
	int32_t	PlayerInstance::GetTeam() { return this->TeamType; }
	void PlayerInstance::SetCharType(const int32_t newType) { this->CharacterType = newType; }
	void PlayerInstance::SetTeam(const int32_t newTeam) { this->TeamType = newTeam; }

	bool PlayerInstance::GetHP(int32_t& outHealth)
	{
		bool result = FALSE;

		// Get Modules
		CharacterModules* modules = this->pCharModules;
		if (modules == nullptr)
			return result;

		// Obtain Unit Data
		CSCharData* charData = modules->GetCharData();
		if (charData == nullptr)
			return result;

		//	Get Current Health
		outHealth = charData->GetHealth();
		return TRUE;
	}

	void PlayerInstance::SetHP(int32_t value)
	{
		bool result = FALSE;

		// Get Modules
		CharacterModules* modules = this->pCharModules;
		if (modules == nullptr)
			return;

		// Obtain Unit Data
		CSCharData* charData = modules->GetCharData();
		if (charData == nullptr)
			return;

		//	Get Current Health
		charData->SetHealth(value);
	}

	bool PlayerInstance::GetPos(Vector3& out)
	{
		bool result = FALSE;

		// Get Modules
		CharacterModules* modules = this->pCharModules;
		if (modules == nullptr)
			return result;

		// Obtain physics
		CSCharPhysics* physics = modules->GetCharPhysics();
		if (physics == nullptr)
			return result;

		out = physics->GetLocalPosition();
		return TRUE;
	}

	void PlayerInstance::SetPos(Vector3 In)
	{
		bool result = FALSE;

		// Get Modules
		CharacterModules* modules = this->pCharModules;
		if (modules == nullptr)
			return;

		// Obtain physics
		CSCharPhysics* physics = modules->GetCharPhysics();
		if (physics == nullptr)
			return;

		physics->SetLocalPosition(In);
	}

	float PlayerInstance::GetDistance(Vector3 Other)
	{
		Vector3 cPos;
		GetPos(cPos);
		return cPos.DistTo(Other);
	}


	// --------------------------------------------------
	// # CSCharModules
	// --------------------------------------------------
	CSCharData* CharacterModules::GetCharData() 
	{
		CSCharData* result = nullptr;

		if (this->pCharData != nullptr)
			result = this->pCharData;

		return result;
	}

	CSCharPhysics* CharacterModules::GetCharPhysics() 
	{
		CSCharPhysics* result = nullptr;

		if (this->pCharPhysics != nullptr)
			result = this->pCharPhysics;

		return result;
	}

	CSPlayerDamage* CharacterModules::GetPlayerDamage() 
	{
		CSPlayerDamage* result = nullptr;

		if (this->pPlayerDamage != nullptr)
			result = this->pPlayerDamage;

		return result;
	}

	// --------------------------------------------------
	// # CSCharData
	// --------------------------------------------------
	int32_t CSCharData::GetHealth() { return this->CurrentHealth; }
	void CSCharData::SetHealth(const int32_t& value) { this->CurrentHealth = value; }
	int32_t CSCharData::GetMana() { return this->CurrentMana; }
	void CSCharData::SetMana(const int32_t& value) { this->CurrentMana = value; }
	int32_t CSCharData::GetStamina() { return this->CurrentStamina; }
	void CSCharData::SetStamina(const int32_t& value) { this->CurrentStamina = value; }

	// --------------------------------------------------
	// # CSCharPhysics
	// --------------------------------------------------
	Vector3 CSCharPhysics::GetLocalPosition() { return this->RelativePosition; }
	void CSCharPhysics::SetLocalPosition(Vector3 newPosition) { this->RelativePosition = newPosition; }
	void CSCharPhysics::ToggleGravity() { this->bNoGravity ^= 1; }
}
#pragma pack(pop)