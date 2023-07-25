# EldenRing-SDK
Development Kit for Elden Ring Enhancements  

## USAGE
- include `Basic_Functions.cpp` to project DLL Project
- call `initSDK` to initialize the main class pointer

## EXAMPLE
```cpp
//  Initialize SDK
HEXINTON::InitSDK();  //  Use this version if the offsets in the function are up to date
HEXINTON::InitSDK("EldenRing.exe", gGameMan, gGameDataMan, gWorldCharMan);  //  Use this version to include your own offsets via signature scan or whatever.

//  Obtain WorldCharMan
auto world = *HEXINTON::CGlobals::GWorldCharMan;  //  result should be non nullptr.

//  navigate class members 
```

### CONTRIBUTORS
- [koalabear](https://github.com/koalabear420/EROverlay)  
- [NBOTT42](https://github.com/TempAccountNull)  
- [Team Hexington](https://discord.gg/invite/fpJQhEbtHB)  
