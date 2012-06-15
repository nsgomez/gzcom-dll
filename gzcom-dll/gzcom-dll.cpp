#include "stdafx.h"
#include "gzcom-dll.h"
#include "RZCOM.h"

// Declares a (hopefully) GZCOM-compatible class.
class cGZSimmasterDllDirector : public cRZCOMDllDirector
{
	public:
		cGZSimmasterDllDirector()
		{
			// We won't concern ourselves with the AddCls call
			//     that was here. (for now)
			DebugMessageBox( "cGZSimmasterDllDirector spawn." );
		}

		virtual ~cGZSimmasterDllDirector()
		{
			// God knows what we're supposed to do with this.
			DebugMessageBox( "cGZSimmasterDllDirector destroy." );
		}

		// Returns the constant director ID we set earlier.
		DWORD GetDirectorID() const { return kEmptyPluginCOMDirectorDirectorID; }

		// Does something when we get called
		bool OnStart( cIGZCOM* pCOM )
		{
			// pCOM is currently a void pointer because we do
			//     not have a prototype for cIGZCOM*, the original
			//     type.

			// Instead, we'll just get the hell out of here.
			DebugMessageBox( "cGZSimmasterDllDirector::OnStart." );
			return true;
		}

		// <todo>
		//     For some reason this is called automatically and the
		//     game crashes.
		bool PreAppShutdown()
		{
			DebugMessageBox
			(
				"cGZSimmasterDllDirector::PreAppShutdown\n"
				"\n"
				"If you are getting this message immediately, something\n"
				"is VERY WRONG."
			);

			return true;
		}

	protected:
		// ALL of our variables (should) go here.

	private:
		// If you declare private variables in a GZCOM DLL,
		// YOU'RE GOING TO HAVE A BAD TIME
};

// Get the DLL director.
cRZCOMDllDirector * RZGetCOMDllDirector()
{
	DebugMessageBox
	(
		"SimCity 4 -> cRZCOMDllDirector * RZGetCOMDllDirector().\n"
		"\n"
		"Getting static cGZSimmasterDllDirector instance"
	);

	static cGZSimmasterDllDirector sDirector;
	return &sDirector;
}

extern "C" EXPORTED cRZCOMDllDirector * GZDllGetGZCOMDirector() { return RZGetCOMDllDirector(); }