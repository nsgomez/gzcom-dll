#pragma once
#include "cIGZUnknown.h"
#include "cS3DVector3.h"

class cS3DCamera : public cIGZUnknown
{
	public:
		// vtable [0-3]
		uint32_t __pad0[87]; // [4-351]
		cS3DVector3 vPos; // [352-363]
};