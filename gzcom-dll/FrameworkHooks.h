#include "stdafx.h"

#ifndef HOOKS_H
	#define HOOKS_H

	// Forward classes
	class cIGZCOM;

	// Include types and class definitions
	#include "IGZCOM.h"

	// Defines framework hooks
	class cIGZFrameWorkHooks
	{
		public:
			// Get an instance of cIGZCOM
			cIGZCOM * GZCOM();

		public:
			// Inheritable framework hooks
			bool PreFrameWorkInit()          { return true; }
			bool PreAppInit()                { return true; }
			bool PostAppInit()               { return true; }
			bool PreAppShutdown()            { return true; }
			bool PostAppShutdown()           { return true; }
			bool PostSystemServiceShutdown() { return true; }
			bool AbortiveQuit()              { return true; }
			bool OnInstall()                 { return true; }
	};

#endif