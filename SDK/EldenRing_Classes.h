#pragma once

/**
 * Name: Elden Ring
 * Version: ~
 * Engine: ~
*/

#pragma pack(push, 0x01)
namespace HEXINTON
{
    class ChrPhysics 
    {
    public:
		char                pad_0000[84];					//0x0000
		float               Azimuth;						//0x0054
		char                pad_0058[24];					//0x0058
        Vector3             Pos;							//
        char                pad2[0x157];					//
        bool                GravityEnabled;					//
    };

    class UnitData 
    {
    public:
        char                pad[0x138];                     // 0x0
        uint32_t            Health;                         // 0x138
        uint32_t            pad2;                           // 0x13C
        uint32_t            MaxHealth;                      // 0x140
        uint32_t            BaseMaxHealth;                  // 0x144
        uint32_t            mana;                           // 0x148
        uint32_t            maxmana;                        // 0x14C
        uint32_t            basemaxmana;                    // 0x150
        uint32_t            stamina;                        // 0x154
        uint32_t            maxstamina;                     // 0x158
        uint32_t            basemaxstamina;                 // 0x15C
    };

    class ChrModules 
    {
    public:
        class UnitData*     UnitData;
        uint64_t            actionflag;
        uint64_t            behaviorscript;
        uint64_t            timeact;
        uint64_t            resist;
        uint64_t            behavior;
        uint64_t            behaviorsync;
        uint64_t            ai;
        uint64_t            playersuperarmor;
        uint64_t            playertoughness;
        uint64_t            talk;
        uint64_t            event;
        uint64_t            playermagic;
        class ChrPhysics*   Physics;
        uint64_t            fall;
        uint64_t            playerladder;
        uint64_t            actionrequest;
        uint64_t            chrthrow;
        uint64_t            hitstop;
        uint64_t            playerdamage;
        uint64_t            playermaterial;
        uint64_t            playerknockback;
        uint64_t            sfx;
        uint64_t            vfx;
        uint64_t            behaviordata;
    };

	class FaceData 
    {
	public:
		uint32_t            FaceModelId;
		uint32_t            HairModelId;
		uint32_t            EyeModelId;
		uint32_t            EyebrowModelId;
		uint32_t            BeardModelId;
		uint32_t            AccModelId;
		uint32_t            DecalModelId;
		uint32_t            EyelashModelId;
	};

	struct ChrStats 
    {
	public:
		uint32_t            Vigor;                          // 0x0
		uint32_t            Mind;                           // 0x4
		uint32_t            Endurance;                      // 0x8
		uint32_t            Strength;                       // 0xC
		uint32_t            Dexterity;                      // 0x10
		uint32_t            Intelligence;                   // 0x14
		uint32_t            Faith;                          // 0x18
		uint32_t            Arcane;                         // 0x1C
	};

	struct ChrAsm 
    {
	public:
		uint8_t             ArmStyle;                       // 0x328 (GameData + 0x328)
		uint8_t             pad[3];                         // 0x329
		uint32_t            CurrentWepSlotOffsetL;          // 0x32C
		uint32_t            CurrentWepSlotOffsetR;          // 0x330
		uint32_t            CurrentWepSlotOffsetLArrow;     // 0x334
		uint32_t            CurrentWepSlotOffsetRArrow;     // 0x338
		uint32_t            CurrentWepSlotOffsetLBolt;      // 0x33C
		uint32_t            CurrentWepSlotOffsetRBolt;      // 0x340
		char                pad2[0x44];                     // 0x344
		uint32_t            Accessory1;                     // 0x388
		uint32_t            Accessory2;                     // 0x38C
		uint32_t            Accessory3;                     // 0x390
		uint32_t            Accessory4;                     // 0x394
		uint32_t            Accessory5;                     // 0x398
		uint32_t            PrimaryWeaponL;                 // 0x39C
		uint32_t            PrimaryWeaponR;                 // 0x3A0
		uint32_t            SecondaryWeaponL;               // 0x3A4
		uint32_t            SecondaryWeaponR;               // 0x3A8
		uint32_t            TertiaryWeaponL;                // 0x3AC
		uint32_t            TertiaryWeaponR;                // 0x3B0
		uint32_t            PrimaryArrow;                   // 0x3B4
		uint32_t            PrimaryBolt;                    // 0x3B8
		uint32_t            SecondaryArrow;                 // 0x3BC
		uint32_t            SecondaryBolt;                  // 0x3C0
		uint32_t            TertiaryArrow;                  // 0x3C4
		uint32_t            TertiaryBolt;                   // 0x3C8
		uint32_t            Helmet;                         // 0x3CC
		uint32_t            Chest;                          // 0x3D0
		uint32_t            Gloves;                         // 0x3D4
		uint32_t            Legs;                           // 0x3D8
		uint32_t            Hair;                           // 0x3DC
	};

	class ChrGameData 
    {
	public:
		char                pad[0x10];                      // 0x0
		uint32_t            Health;                         // 0x10
		uint32_t            MaxHealth;                      // 0x14
		uint32_t            BaseMaxHealth;                  // 0x18
		uint32_t            Mana;                           // 0x1C
		uint32_t            MaxMana;                        // 0x20
		uint32_t            BaseMaxMana;                    // 0x24
		uint32_t            unk;                            // 0x28
		uint32_t            Stamina;                        // 0x2C
		uint32_t            MaxStamina;                     // 0x30
		uint32_t            BaseMaxStamina;                 // 0x34
		uint32_t            unk_;                           // 0x38
		class ChrStats      Stats;                          // 0x3C
		int                 pad2[2];                        // 0x58
		uint32_t            RuneArc;                        // 0x64
		uint32_t            Level;                          // 0x68
		uint32_t            CurrentRunes;                   // 0x6C
		uint32_t            TotalRunes;                     // 0x70
		int                 unk2;                           // 0x74
		uint32_t            Immunity1;                      // 0x78
		uint32_t            Immunity2;                      // 0x7C
		uint32_t            Robustness;                     // 0x80
		uint32_t            Vitality;                       // 0x84
		uint32_t            Robustness2;                    // 0x88
		uint32_t            Focus;                          // 0x8C
		uint32_t            Focus2;                         // 0x90
		int                 pad3[2];                        // 0x94
		char                Name[19];                       // 0x9C
		char                pad4[0xF];                      // 0xAF
		PlayerGender		Gender;                         // 0xBE
		PlayerClass			Class;                          // 0xBF
		uint8_t             Appearance;                     // 0xC0
		uint8_t             unk3;                           // 0xC1
		uint8_t             Voice;                          // 0xC2
		uint8_t             StartingGift;                   // 0xC3
		char                pad5[0x3B];                     // 0xC4;
		uint8_t             GreaterRuneState;               // 0xFF
		char                unk_ad6[0x228];                 // 0x100
		class ChrAsm        ChrAsm;                         // 0x328
	};

    class ChrIns
	{
	public:
		uint64_t            _;
		uint32_t            LocalId;                        // 0x8
		char                pad[0x54];                      // 0xC
		uint32_t            ParamId;                        // 0x60
		uint32_t            pad2[2];                        // 0x64
		uint8_t             TeamId;                         // 0x6C
		char                pad3[0x7];                      // 0x6D
		uint32_t            GlobalId;                       // 0x74
		char                pad4[0x118];                    // 0x78
		class ChrModules*   Modules;                        // 0x190

	public:
		uint32_t			GetHP();
		uint32_t			GetMaxHP();
		Vector3				GetPos();
		void				SetPos(Vector3 In);
		float				GetDistance(Vector3 Other);
	};
}
#pragma pack(pop)