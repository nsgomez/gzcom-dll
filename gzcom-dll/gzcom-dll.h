#include "stdafx.h"

// Defines an export declaration
#define EXPORTED __declspec(dllexport)

// Constants as seen in EmptyPluginCOMDirector.cpp
static const DWORD kEmptyPluginCOMDirectorDirectorID = 0x06dcbef1;
static const DWORD kGZCLSID_cSomeObject              = 0x46dcc1fc;

// Forward a class declaration
class cRZCOMDllDirector;

// Define access functions to the DLL director
                    cRZCOMDllDirector * RZGetCOMDllDirector();
extern "C" EXPORTED cRZCOMDllDirector * GZDllGetGZCOMDirector();