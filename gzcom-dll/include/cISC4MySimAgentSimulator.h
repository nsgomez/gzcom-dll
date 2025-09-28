/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4MySimAgentSimulator.h
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
#include "cIGZUnknown.h"
#include "cISC4MySim.h"

template <typename T> class SC4Vector;

class cISC4MySimAgentSimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool GetActiveMySims(SC4Vector<cISC4MySim*>& sims) = 0;
	virtual void MoveIn(cIGZString& personalName, bool isMale, cISC4MySim::ZodiacSign sign, SC4String& bio, uint32_t bitmapID, SC4String& bitmapImagePath, uint8_t slot) = 0;

	virtual void TrackLocation(cISC4MySim* pSim) = 0;
	virtual void HideLocation() = 0;

	virtual cISC4MySim* MySimLivesHere(cISC4BuildingOccupant* pBuilding) = 0;
	virtual void CancelMoveIn() = 0;

	virtual void SetActiveUIPanelSim(int32_t slot) = 0;
	virtual bool GetActiveUIPanelSim(int32_t& slot) = 0;
};