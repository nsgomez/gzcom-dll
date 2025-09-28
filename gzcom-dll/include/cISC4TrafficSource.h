/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4TrafficSource.h
 *
 * Copyright (C) 2016 Nelson Gomez
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
#include "cIGZUnknown.h"

class cSC4TripData;

template <typename T> class SC4List;
template <typename T> class SC4Rect;

class cISC4TrafficSource : public cIGZUnknown
{
	public:
		virtual SC4List<cSC4TripData>* GetTripDataList(void) = 0;
		virtual bool UpdateTrafficVolume(void) = 0;
		virtual bool GetSourceCells(SC4Rect<uint32_t>& sCellRect) = 0;
};