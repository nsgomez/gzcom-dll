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
		// World-space center of the decal footprint (terrain X/Z).
		// If you want it to cover an uneven number of tiles, the center should be in a tile center (i.e. 520x520)
		// If you want it to cover an even number of tiles, the center should be in a tile node (i.e. 512x512)
		cS3DVector2 center;					// 0x0

		// Base footprint size in world units (i.e. meters). If this is smaller than one tile, the texture will be
		// stretched towards the southwest corner of the tile. Larger values make the decal occupy more terrain area.
		// To cover a number of tiles, the base size should be a multiple of the 16.0f (the tile size).
		float baseSize = 16.0f; 			// 0x8

		// Rotation in turns (fractions of a full circle): 0.25 = 90 deg, 0.5 = 180 deg, 1.0 = 360 deg.
		// Rotations other than these values can cause stretch artifacts
		float rotationTurns = 0.0f;			// 0xc

		// Footprint aspect multiplier (applied with texture aspect ratio).
		// > 1 stretches along one axis, < 1 compresses it.
		float aspectMultiplier = 1.0f;		// 0x10

		// U-axis UV scale. Affects texture stretching/tiling across the decal.
		float uvScaleU = 1.0f; 				// 0x14

		// V-axis UV scale. Affects texture stretching/tiling across the decal.
		float uvScaleV = 1.0f;				// 0x18

		// Uniform UV translation bias added to both texture axes.
		// This shifts the sampled part of the texture without moving the decal in world space.
		float uvOffset = 0.0f;				// 0x1c

		// Copied/stored by the overlay manager and returned by DecalInfo().
		// Does not seem to be consumed anywhere in Windows x86 v641, nor the available Mac x86 and PPC builds
		float unknown8 = 0.0f;				// 0x20
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