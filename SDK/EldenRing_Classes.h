#pragma once

/**
 * Name: Elden Ring
 * Version: ~
 * Engine: ~
*/

#pragma pack(push, 0x01)
namespace HEXINTON
{
	// Template class for obtaining globals
	class CGlobals
	{
	public:
		static class GameManager**				GGameMan;
		static class GameDataManager**			GGameDataMan;
		static class WorldCharacterManager**	GWorldCharMan;
		static class WorldCharManDebugFlags**	GWorldCharManDbgFlgs;
	};

	//	AOB : 48 8B 05 ??	?? ?? ?? 80 B8 ?? ?? ?? ?? 0D 0F94 C0 C3
	class GameManager
	{
	private:	
		char									pad_0000[2752];			//0x0000
		char									N0000458E;				//0x0AC0
		char									pad_0AC1[111];			//0x0AC1
		int										LastGrace;				//0x0B30
		char									pad_0B34[8];			//0x0B34
		int										TargetGrace;			//0x0B3C
	
	public:
	};

	//	AOB : 48 8B 05 ?? ?? ?? ?? 48 85 C0 74 05 48 8B 40 58 C3 C3
	class GameDataManager
	{
	private:	
		char									pad_0000[8];			//0x0000
		class  CSPlayerGameData*				pCSPlayerGameData;		//0x0008
		char									pad_0010[144];			//0x0010
		int										PlayTime_ms;			//0x00A0
		char									pad_00A4[124];			//0x00A4
		int										NGplus;					//0x0120
		char									pad_0124[92];			//0x0124
	
	public:
	};
	
	//	AOB : 48 8B 05 ?? ?? ?? ?? 48 85 C0 74 0F 48 39 88
	class WorldCharacterManager
	{
	private:	
		char								pad_0008[69360];			//0x0008
		class LocalPlayer*					pLocalPlayer;				//0x10EF8
		char								pad_10F00[58032];			//0x10F00
		ElementArray<class PlayerInstance*>		pEntArray;				//0x1F1B0
	
	private:
		virtual void						vf_Function0();

	public:
		class LocalPlayer*					GetLocalPlayer();
		class PlayerInstance*				GetLocalPlayerInstance();
		class CharacterModules*				GetLocalPlayerCharModules();
		class CSCharData*					GetLocalPlayerCharData();
		class CSCharPhysics*				GetLocalPlayerCharPhysics();
		ElementArray<class PlayerInstance*>	GetEntityArray();
		DebugArray<class PlayerInstance*>	dbg_GetEntityArray();
	};	//Size: 0x10F00
	
	//	AOB : 80 3D ?? ?? ?? ?? 00 0F 85 ?? ?? ?? ?? 32 C0 48
	class WorldCharManDebugFlags
	{
	private:
		bool									PlayerNoDead;			//0x0000
		bool									HorseNoDead;			//0x0001
		bool									PlayerExterminate;		//0x0002
		bool									AllNoGoodsConsume;		//0x0003
		bool									AllNoStaminaConsume;	//0x0004
		bool									AllNoFPConsume;			//0x0005
		bool									AllNoArrowsConsume;		//0x0006
		bool									AllNoMagicConsume;		//0x0007
		bool									PlayerHide;				//0x0008
		bool									PlayerSilence;			//0x0009
		bool									AllNoDead;				//0x000A
		bool									AllNoDamage;			//0x000B
		bool									AllNoHit;				//0x000C
		bool									AllNoAttack;			//0x000D
		bool									AllNoMove;				//0x000E
		bool									AllNoUpdateAi;			//0x000F
		bool									AllNoWeaponProtDurabilityDamage;	//0x0010
		bool									AllNoAshofWarConsume;				//0x0011
		bool									AllNoGoodsConsume2;					//0x0012
		char									pad_0013[21];	//0x0013
		class CSWorldChrManDbgImp*				pCSWorldChrManDbgImp;	//0x0028
		class WorldChrManDbg*					pWorldCharManDbg;		//0x0030

	public:

	};	//Size: 0x0038

	class CSPlayerGameData
	{
	private:
		char									pad_0000[16];			//0x0000
		int										Health;					//0x0010
		int										MaxHealth;				//0x0014
		int										BaseMaxHealth;			//0x0018
		int										Mana;					//0x001C
		int										MaxMana;				//0x0020
		int										BaseMaxMana;			//0x0024
		char									pad_0028[4];			//0x0028
		int										Stamina;				//0x002C
		int										MaxStamina;				//0x0030
		int										BaseMaxStamina;			//0x0034
		char									pad_0038[4];			//0x0038
		int										Vigor;					//0x003C
		int										Mind;					//0x0040
		int										Endurance;				//0x0044
		int										Strength;				//0x0048
		int										Dexterity;				//0x004C
		int										Intelligence;			//0x0050
		int										Faith;					//0x0054
		int										Arcane;					//0x0058
		int										Humanity;				//0x005C
		char									pad_0060[8];			//0x0060
		int										Level;					//0x0068
		int										Souls;					//0x006C
		int										TotalSouls;				//0x0070
		char									pad_0074[4];			//0x0074
		int										Immunity;				//0x0078
		int										Immunity_;				//0x007C
		int										Robustness;				//0x0080
		int										Vitality;				//0x0084
		int										Robustness_;			//0x0088
		int										Focus;					//0x008C
		int										Focus_;					//0x0090
		char									pad_0094[8];			//0x0094
		wchar_t									N00004846[19];			//0x009C
		char									pad_00C2[29];			//0x00C2
		bool									FurcallingFinger;		//0x00DF
		char									pad_00E0[2];			//0x00E0
		int										WeaponLevel;			//0x00E2
		char									pad_00E6[25];			//0x00E6
		char									GreatRune;				//0x00FF
		char									pad_0100[1];			//0x0100
		char									MaxEstusHP;				//0x0101
		char									MaxEstusMP;				//0x0102
		char									pad_0103[133];			//0x0103
		char									SwordArtPoint_Strength;		//0x0188
		char									SwordArtPoint_Dexterity;	//0x0189
		char									SwordArtPoint_Int;		//0x018A
		char									SwordArtPoint_Faith;	//0x018B
		char									pad_018C[252];			//0x018C
		int										Vigor_cor;				//0x0288
		int										Mind_cor;				//0x028C
		int										Endurance_cor;			//0x0290
		char									pad_0294[4];			//0x0294
		int										Strength_cor;			//0x0298
		int										Dexterity_cor;			//0x029C
		int										Intelligence_cor;		//0x02A0
		int										Faith_cor;				//0x02A4
		int										Arcane_cor;				//0x02A8
		char									pad_02AC[124];			//0x02AC
		char									ArmStyle;				//0x0328
		char									pad_0329[3];			//0x0329
		int										CurrentWepSlotOffset_Left;			//0x032C
		int										CurrentWepSlotOffset_Right;			//0x0330
		int										CurrentWepSlotOffset_LeftArrow;		//0x0334
		int										CurrentWepSlotOffset_RightArrow;	//0x0338
		int										CurrentWepSlotOffset_LeftBolt;		//0x033C
		int										CurrentWepSlotOffset_RightBolt;		//0x0340
		char									pad_0344[88];			//0x0344
		int										PrimaryLeftWep;			//0x039C
		int										PrimaryRightWep;		//0x03A0
		int										SecondaryLeftWep;		//0x03A4
		int										SecondaryRightWep;		//0x03A8
		int										TertiaryLeftWep;		//0x03AC
		int										TertiaryRightWep;		//0x03B0
		int										PrimaryArrow;			//0x03B4
		int										PrimaryBolt;			//0x03B8
		int										SecondaryArrow;			//0x03BC
		int										SecondaryBolt;			//0x03C0
		int										TertiaryArrow;			//0x03C4
		int										TertiaryBolt;			//0x03C8
		int										Helmet;					//0x03CC
		int										Armor;					//0x03D0
		int										Gauntlet;				//0x03D4
		int										Leggings;				//0x03D8
		int										Hair;					//0x03DC
		int										Accessory_1;			//0x03E0
		int										Accessory_2;			//0x03E4
		int										Accessory_3;			//0x03E8
		int										Accessory_4;			//0x03EC
		int										Accessory_5;			//0x03F0

	public:
	};	//Size: 0x03F4

	class LocalPlayer
	{
	private:
		class PlayerInstance*				pPlayer;					//0x0000
		int32_t								dwflag;						//0x0008

	public:
		PlayerInstance*						GetPlayerInstance();
	};	//Size: 0x000C

	class PlayerInstance
	{
	private:
		int32_t								HandleID;					//0x0008
		char								pad_000C[4];				//0x000C
		class LocalPlayer*					pLocalPlayer;				//0x0010
		char								pad_0018[16];				//0x0018
		class CharRes*						pCharRes;					//0x0028
		char								pad_0030[32];				//0x0030
		class CSCharModelIns*				pCharModelInstance;			//0x0050
		class CSPlayerCtrl*					pPlayerCtrl;				//0x0058
		char								pad_0060[8];				//0x0060
		int32_t								CharacterType;				//0x0068
		int32_t								TeamType;					//0x006C
		char								pad_0070[80];				//0x0070
		class CSTargetVelocityRecorder*		pTargetVelocityRecorder;	//0x00C0
		char								pad_00C8[40];				//0x00C8
		class PlayerInstance*				pPlayerInstance;			//0x00F0
		char								pad_00F8[128];				//0x00F8
		class CSSpecialEffect*				pSpecialEffects;			//0x0178
		char								pad_0180[8];				//0x0180
		int32_t								CharacterID;				//0x0188
		char								pad_018C[4];				//0x018C
		class CharacterModules*				pCharModules;				//0x0190


	private:
		virtual void						vf_Function0();

	public:
		CharacterModules*					GetCharacterModules();
		int32_t								GetCharType();
		int32_t								GetTeam();
		void								SetCharType(const int32_t newType);
		void								SetTeam(const int32_t newTeam);
		bool								GetHP(int32_t& outHealth);
		bool								GetPos(Vector3& outPos);
		float								GetDistance(const Vector3 Other);
		void								SetHP(const int32_t value);
		void								SetPos(const Vector3 In);
	};	//Size: 0x0198

	class CharacterModules
	{
	private:
		class CSCharData*					pCharData;					//0x0000
		class CSCharActionFlags*			pCharActionFlags;			//0x0008
		class CSCharBehaviorScripts*		pCharBehavScripts;			//0x0010
		class CSCharTimeAct*				pCharTimeAct;				//0x0018
		class CSCharResist*					pCharResist;				//0x0020
		class CSCharBehavior*				pCharBehavior;				//0x0028
		class CSCharBehaviorSync*			pCharBehaviorSync;			//0x0030
		class CSCharAi*						pCharAI;					//0x0038
		class CSPlayerSuperArmor*			pCharSuperArmor;			//0x0040
		class CSPlayerToughness*			pPlayerToughness;			//0x0048
		class CSCharTalk*					pCharTalk;					//0x0050
		class CSCharEvent*					pCharEvent;					//0x0058
		class CSPlayerMagic*				pPlayerMagic;				//0x0060
		class CSCharPhysics*				pCharPhysics;				//0x0068
		class CSCharFall*					pCharFall;					//0x0070
		class CSPlayerLadder*				PlayerLadder;				//0x0078
		class CSCharActionRequest*			pCharActionRequest;			//0x0080
		class CSCharThrow*					pCharThrow;					//0x0088
		class CSCharHitStop*				pCharHitStop;				//0x0090
		class CSPlayerDamage*				pPlayerDamage;				//0x0098

	public:
		CSCharData*							GetCharData();
		CSCharPhysics*						GetCharPhysics();
		CSPlayerDamage*						GetPlayerDamage();
	};	//Size: 0x00A0
	
	class CSCharData
	{
	private:
		char								pad_0008[304];				//0x0008
		int32_t								CurrentHealth;				//0x0138
		int32_t								N000035E3;					//0x013C
		int32_t								MaxHealth;					//0x0140
		int32_t								BaseMaxHealth;				//0x0144
		int32_t								CurrentMana;				//0x0148
		int32_t								MaxMana;					//0x014C
		int32_t								BaseMaxMana;				//0x0150
		int32_t								CurrentStamina;				//0x0154
		int32_t								MaxStamina;					//0x0158
		int32_t								BaseMaxStamina;				//0x015C

	private:
		virtual void Function0();

	public:
		int32_t								GetHealth();
		int32_t								GetMaxHealth();
		void								SetHealth(const int32_t& value);
		int32_t								GetMana();
		int32_t								GetMaxMana();
		void								SetMana(const int32_t& value);
		int32_t								GetStamina();
		int32_t								GetMaxStamina();
		void								SetStamina(const int32_t& value);
	};	//Size: 0x0160

	class CSCharPhysics
	{
	private:
		class PlayerInstance*				pPlayerInstance;			//0x0008
		class PlayerInstance*				pPlayerInstance2;			//0x0010
		class CSCharPhysics*				pCharPhysics;				//0x0018
		class CSCharData*					pCharData;					//0x0020
		class hknpCapsuleShape*				pHKCapsule;					//0x0028
		char								pad_0030[36];				//0x0030
		float								sinAzimuth;					//0x0054
		char								pad_0058[4];				//0x0058
		float								cosAzimuth;					//0x005C
		char								pad_0060[16];				//0x0060
		Vector3								RelativePosition;			//0x0070
		char								pad_007C[343];				//0x007C
		bool								bNoGravity;					//0x01D3

	private:
		virtual void						vf_Function0();

	public:
		Vector3								GetLocalPosition();
		void								SetLocalPosition(Vector3 newPosition);
		void								ToggleGravity();
	};	//Size: 0x01D4

	class CSWorldChrManDbgImp
	{
	private:
		char								pad_0000[102];				//0x0000
		bool								AllDrawHit;					//0x0066
		bool								HeadHitBoxDraw;				//0x0067
		char								pad_0068[48];				//0x0068
		bool								HitStop;					//0x0098
		char								pad_0099[3];				//0x0099
		float								HitStopTime_sec;			//0x009C
		float								HitStopTime2_sec;			//0x00A0
		char								pad_00A4[4];				//0x00A4
		class CSPadManipulator*				pCSPadMan;					//0x00A8
		class CSPlayerSessionHolder*		pCSPlayerSession;			//0x00B0
		char								pad_00B8[10];				//0x00B8
		bool								NewKnockbackMode;			//0x00C2
		char								pad_00C3[61];				//0x00C3
		bool								HeadDraw;					//0x0100
		char								pad_0101[143];				//0x0101
		class CSChrCam*						pChrCamera;					//0x0190

	public:
	};	//Size: 0x0198

	class WorldChrManDbg
	{
	private:
		char								pad_0008[16];				//0x0008
		class DLKRDLSystemHeapImpl*			pDLKRDLSystemHeapImpl;		//0x0018
		char								pad_0020[24];				//0x0020
		char*								czClassName;				//0x0038
		wchar_t*							czClassNameW;				//0x0040
		char								pad_0048[8];				//0x0048
		unsigned __int64					dwFlag;						//0x0050

	private:
		virtual void Function0();

	public:
	};	//Size: 0x0058

	class DLKRDLSystemHeapImpl
	{
	private:
		virtual void Function0();

	public:
	};	//Size: 0x0008

	class CSPadManipulator
	{
	private:
		virtual void Function0();

	public:
	};	//Size: 0x0008

	class CSPlayerSessionHolder
	{
	private:
		virtual void Function0();

	public:
	};	//Size: 0x0008

	class CSChrCam
	{
	private:
		virtual void Function0();

	public:
	};	//Size: 0x0008

}
#pragma pack(pop)