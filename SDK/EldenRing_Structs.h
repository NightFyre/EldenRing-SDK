#pragma once
#pragma pack(push, 0x01)
namespace HEXINTON
{
    struct Alliance 
    {
		int                 None = 0;
		int                 Player = 1;
		int                 Enemy = 6;
		int                 Boss = 7;
		int                 Decoy = 10;
		int                 Friendly = 26;
		int                 Object = 30;
	};

	struct ChrObject 
    {
		char                pad_0000[8];	    //0x0000
		int                 LOCALID;	        //0x0008
		char                pad_000C[84];	    //0x000C
		int                 PARAMID;	        //0x0060
		char                pad_0064[8];	    //0x0064
		char                ALLIANCE;	        //0x006C
		char                pad_006D[7];	    //0x006D
		unsigned __int16    GLOBALID;	        //0x0074
		char                ad_0076[282];	    //0x0076
		unsigned __int64    EntObjectPTR;	    //0x0190
	};	//Size: 0x0198  

	struct ChrData  
    {   
		char                pad_0000[312];	    //0x0000
		int                 Health;	            //0x0138
		int                 MaxHealth;	        //0x013C
		int                 BaseMaxHealth;	    //0x0140
		int                 unk;	            //0x0144
		int                 Mana;	            //0x0148
		int                 MaxMan;	            //0x014C
		int                 BaseMaxMana;	    //0x0150
		int                 Stamina;	        //0x0154
		int                 MaxStamina;	        //0x0158
		int                 BaseMaxStamina;	    //0x015C
	};	//Size: 0x0160  

	struct ChrFall  
    {   
		char                pad_0000[6404];	    //0x0000
		bool                DrawSkeleton;	    //0x1904
	};	//Size: 0x1905  

	struct ChrTimeAct   
    {   
		char                pad_0000[64];       // 0x0000
		int32_t             Animation;          // 0x0040
	};	//Size: 0x0040
}
#pragma pack(pop)