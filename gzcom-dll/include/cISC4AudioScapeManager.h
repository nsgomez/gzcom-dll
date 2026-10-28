/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4AudioScapeManager.h
 *
 * Copyright (C) 2026 Casper Van Gheluwe
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
#include "SC4Rect.h"

class cIGZString;
class cS3DVector3;

static const uint32_t GZIID_cISC4AudioScapeManager = 0x29e39db4;

class cISC4AudioScapeManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual bool CreateLayer(cIGZString const& name, uint32_t layerID, uint32_t, float) = 0;
	virtual bool DestroyLayer(uint32_t layerID) = 0;
	virtual bool ClearLayer(uint32_t layerID) = 0;
	virtual bool ClearAllLayers(uint32_t, bool) = 0;
	virtual bool GetDistributedGroupPositionsAvgIntersected(uint32_t layerID, uint32_t, SC4Rect<float>& rect, cS3DVector3* positions, int32_t&, int32_t&, bool) = 0;
	virtual bool GetDistributedGroupPositionsAvg(uint32_t layerID, SC4Rect<float>& rect, cS3DVector3* positions, int32_t&, int32_t&, bool) = 0;
	virtual bool GetGroupPositions(uint32_t layerID, cS3DVector3* positions, int32_t&, int32_t&) = 0;
	// Forwards to the longer overload with false and 0 for the extra arguments.
	virtual bool InsertInstance(uint32_t layerID, uint32_t instanceID, cS3DVector3 const& position, float) = 0;
	virtual bool InsertInstance(uint32_t layerID, uint32_t instanceID, bool, uint32_t, cS3DVector3 const& position, float) = 0;
	virtual bool RemoveInstance(uint32_t layerID, uint32_t instanceID) = 0;
	virtual bool UpdateInstance(uint32_t layerID, uint32_t instanceID, cS3DVector3 const& position, float) = 0;
	virtual bool RegisterLayerSound(uint32_t layerID, uint32_t soundID, bool, int32_t, int32_t, int32_t) = 0;
	virtual bool UnregisterLayerSound(uint32_t layerID, uint32_t soundID) = 0;
};
