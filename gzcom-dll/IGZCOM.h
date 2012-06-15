#include "stdafx.h"
#ifndef IGZCOM_H

	#define IGZCOM_H

	// Forward a class definition
	class cIGZFrameWork;

	// Include class definitions and types
	#include "Framework.h"

	// Declare a class prototype for the time being
	class cIGZCOM
	{
		public:
			cIGZFrameWork* FrameWork();

		protected:
			cIGZFrameWork* mpFrameWork;
	};

#endif