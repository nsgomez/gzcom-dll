#include "stdafx.h"

// If debugging is enabled, displays debug message boxes
void DebugMessageBox( LPCSTR szText )
{
	// Only enable if the DEBUG directive is defined
	#ifdef DEBUG
	{
		// Spawn a message box
		MessageBoxA( NULL, szText, "GZCOM DLL Debugging", MB_ICONINFORMATION | MB_OK );
	}
	#endif
	
	// <end>
}