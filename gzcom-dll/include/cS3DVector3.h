/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cS3DVector3.h
 *
 * Copyright (C) 2016 Nelson Gomez
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

#pragma once

class cS3DVector3
{
	public:
		cS3DVector3(void) {
			fX = 0.0f;
			fY = 0.0f;
			fZ = 0.0f;
		}

		cS3DVector3(float fValue) {
			fX = fValue;
			fY = fValue;
			fZ = fValue;
		}

		cS3DVector3(float fX, float fY, float fZ) {
			this->fX = fX;
			this->fY = fY;
			this->fZ = fZ;
		}

		float Length(void);
		cS3DVector3* Normalize(void);
		cS3DVector3* SetLength(float fNewLength);

		bool operator!=(cS3DVector3 const& sOther);
		bool operator==(cS3DVector3 const& sOther);

		cS3DVector3& operator/=(float fDivisor);

	public:
		float fX, fY, fZ;
};