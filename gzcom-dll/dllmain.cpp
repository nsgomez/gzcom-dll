#include "stdafx.h"

// Simply alerts us when the library is freed, and disables thread library
//     calls when attached to the process.
BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls( hModule );
			break;

		case DLL_PROCESS_DETACH:
			DebugMessageBox( "Dismounted." );

			#ifdef DEBUG
			{
				// Let's just get this over with
				ExitProcess( 0x8675309 );
			}
			#endif

			break;
	}
	
	return TRUE;
}

