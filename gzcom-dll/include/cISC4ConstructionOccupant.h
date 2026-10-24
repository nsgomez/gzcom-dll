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

class cISC4Lot;
class cISC4Occupant;

class cISC4ConstructionOccupant : public cIGZUnknown
{
	public:
		// The game's interface has only these two methods. The occupant methods
		// (Init, GetPosition, Draw, ...) are cISC4Occupant's: call them through AsOccupant().
		virtual cISC4Occupant* AsOccupant(void) = 0;
		virtual bool SetLot(cISC4Lot*) = 0;
};
