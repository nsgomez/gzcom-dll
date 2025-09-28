/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cS3DVector2.h
 *
 * Copyright (C) 2025 Nicholas Hayes
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

class cS3DVector2
{
	public:
		cS3DVector2(void) {
			fX = 0.0f;
			fY = 0.0f;
		}

		cS3DVector2(float fValue) {
			fX = fValue;
			fY = fValue;
		}

		cS3DVector2(float fX, float fY) {
			this->fX = fX;
			this->fY = fY;
		}

		float Length(void);
		cS3DVector2* Normalize(void);
		cS3DVector2* SetLength(float fNewLength);

		bool operator!=(cS3DVector2 const& sOther);
		bool operator==(cS3DVector2 const& sOther);

		cS3DVector2& operator/=(float fDivisor);

	public:
		float fX, fY;
};