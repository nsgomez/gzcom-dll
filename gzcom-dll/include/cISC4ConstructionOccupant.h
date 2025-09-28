/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4ConstructionOccupant.h
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
#include "cIGZUnknown.h"

class cIGZIStream;
class cIGZMessage2;
class cIGZOStream;
class cISC4Lot;
class cISC4Occupant;
class cS3DBoundingBox;
class cS3DTransform;
class SC4DrawContext;

class cISC4ConstructionOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;
		virtual bool SetLot(cISC4Lot*) = 0;

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool Write(cIGZOStream&) = 0;
		virtual bool Read(cIGZIStream&) = 0;
		virtual uint32_t GetGZCLSID(void) = 0;

		virtual bool GetPosition(float*) = 0;
		virtual void SetPosition(float const*) = 0;

		virtual bool GetBoundingBox(float*, float*) = 0;

		virtual cIGZUnknown* GetOwner(void) = 0;
		virtual void SetOwner(cIGZUnknown*) = 0;
		
		virtual bool GetBounds(cS3DBoundingBox&) = 0;
		virtual bool GetWorldBounds(cS3DBoundingBox&) = 0;

		virtual bool GetTransform(cS3DTransform&) = 0;
		virtual bool SetTransform(cS3DTransform const&) = 0;

		virtual bool GetSortValue(uint32_t&) = 0;

		virtual bool Draw(SC4DrawContext*, bool) = 0;
		virtual bool DoMessage(cIGZMessage2*) = 0;
};
