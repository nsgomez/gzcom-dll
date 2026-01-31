/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISTEOverlayManager.h
 *
 * Copyright (C) 2026 Nicholas Hayes
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
#include "cS3DVector2.h"

class cGZPersistResourceKey;
class cIGZString;
class cISC4CachedStringTexture;
class cS3DBoundingBox;
class cS3DTextureBinding;
class cS3DTransform;
class cS3DVector3;

class cISTEOverlayManager : public cIGZUnknown
{
public:
	class cDecalInfo
	{
	public:
		cS3DVector2 position; 	// 0x0
		float scale; 			// 0x8
		float unknown3;			// 0xc
		float unknown4;			// 0x10
		float unknown5; 		// 0x14
		float unknown6;			// 0x18
		uint32_t unknown7;		// 0x1c
		uint32_t unknown8;		// 0x20
	};

	virtual uint32_t AddDecal(uint32_t textureIID, cS3DVector2 const& position, float scale, float rotation) = 0;
	virtual uint32_t AddDecal(cGZPersistResourceKey const& textureKey, cS3DVector2 const& position, float scale, float rotation) = 0;
	virtual uint32_t AddDecal(cS3DTextureBinding const* texture, cS3DVector2 const& position, float scale, float rotation) = 0;
	virtual uint32_t AddDecal(cISC4CachedStringTexture const* texture, cS3DVector2 const& position, float scale, float rotation) = 0;

	virtual uint32_t AddRingDecal(uint32_t textureIID, cS3DVector2 const& position, float scale, float rotation) = 0;
	virtual uint32_t AddHeightMap(uint32_t textureIID) = 0;

	virtual uint32_t AddShadowDecal(uint32_t textureIID, cS3DVector2 const& unknown2, float unknown3, float unknown4, bool unknown5) = 0;
	virtual uint32_t AddShadowDecal(cGZPersistResourceKey const& textureKey, cS3DVector2 const& unknown2, float unknown3, float unknown4, bool unknown5) = 0;
	virtual uint32_t AddShadow(cS3DTextureBinding const* pBinding, int unknown2, cS3DVector3 const* unknown3, cS3DVector2 const* unknown4, cS3DBoundingBox const& unknown5, cS3DTransform const& unknown6) = 0;

	virtual void MoveDecal(uint32_t id, cS3DVector2 const& position) = 0;
	virtual void UpdateDecalInfo(uint32_t id, cDecalInfo const& info) = 0;
	virtual void DecalInfo(uint32_t id, cDecalInfo* info) const = 0;

	virtual void RemoveOverlay(uint32_t id) = 0;

	virtual void SetOverlayEnabled(uint32_t id, bool enabled) = 0;
	virtual void SetOverlayAlpha(uint32_t id, float alpha) = 0;
	virtual void SetOverlayColor(uint32_t id, cS3DVector3 const& color) = 0;
	virtual void SetOverlayDrawMode(uint32_t id, uint8_t /*tDrawMode*/ mode) = 0;
	virtual void SetOverlayFlags(uint32_t id, uint32_t flags) = 0;

	virtual void SetHeightMapParams(uint32_t id, float unknown2, float unknown3) = 0;

	virtual bool OverlayIsEnabled(uint32_t id) const = 0;
	virtual float OverlayAlpha(uint32_t id) const = 0;
	virtual bool OverlayColor(uint32_t id, cS3DVector3& color) const = 0;
	virtual uint8_t OverlayDrawMode(uint32_t id) const = 0;
	virtual uint32_t OverlayFlags(uint32_t id) const = 0;

	virtual void GetStatsString(cIGZString& destination) = 0;
};