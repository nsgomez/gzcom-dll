/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cS3DVector3.cpp
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2024 Nicholas Hayes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

#include "cS3DVector3.h"
#include <math.h>

float cS3DVector3::Length(void) {
	float fX2 = fX * fX;
	float fY2 = fY * fY;
	float fZ2 = fZ * fZ;

	return sqrtf(fX2 + fY2 + fZ2);
}

cS3DVector3* cS3DVector3::Normalize(void) {
	float fLength = Length();
	float fMultiplier = 0.0f;

	if (fLength > 0.0f) {
		fMultiplier = 1 / fLength;
	}

	fX *= fMultiplier;
	fY *= fMultiplier;
	fZ *= fMultiplier;

	return this;
}

cS3DVector3* cS3DVector3::SetLength(float fNewLength) {
	float fLength = Length();
	if (fLength > 0.0f) {
		float fMultiplier = fNewLength / fLength;

		fX *= fMultiplier;
		fY *= fMultiplier;
		fZ *= fMultiplier;
	}

	return this;
}

bool cS3DVector3::operator!=(cS3DVector3 const& sOther) {
	return !(operator==(sOther));
}

bool cS3DVector3::operator==(cS3DVector3 const& sOther) {
	float fDiffX = (float)fabs(sOther.fX - fX);
	float fDiffY = (float)fabs(sOther.fY - fY);
	float fDiffZ = (float)fabs(sOther.fZ - fZ);

	return fDiffX <= 0.0001 && fDiffY <= 0.0001 && fDiffZ <= 0.0001;
}

cS3DVector3& cS3DVector3::operator/=(float fDivisor) {
	float fMultiplier = 1 / fDivisor;
	fX *= fMultiplier;
	fY *= fMultiplier;
	fZ *= fMultiplier;

	return *this;
}