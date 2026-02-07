/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4LightingManager.h
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

class cS3DVector3;
class cS3DVector2;
class cIS3DModelInstance;
class cISCPropertyHolder;
class cS3DTransform;
class cS3DMatrix3;
class cS3DMatrix4;
class cS3DBoundingBox;
class cRZRect;
class cS3DColorARGB;

class cISC4LightingManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual float GetTimeOfDay() const = 0;
	virtual bool SetTimeOfDay(float time) = 0;

	virtual void SetLightingTint(cS3DVector3 const&, float) = 0;
	virtual void ResetLightingTint() = 0;

	virtual bool IsNight() const = 0;

	virtual void GetGlobalLight(cS3DVector3& outLight) const = 0;
	virtual bool GetModelLight(cIS3DModelInstance* modelInstance, cS3DVector3& outLight) const = 0;
	virtual void GetTerrainLighting(cS3DVector3 const& position, unsigned char& outR, unsigned char& outG, unsigned char& outB) const = 0;

	virtual void GetShadowDirection(cS3DVector3& outDirection) const = 0;
	virtual void GetShadowParams(float& outUnknown, float& outShadowThreshold, cS3DVector3& outColor) const = 0;	// outUnknown is always -1.0f hardcoded
	virtual float GetShadowStrengthFromLocation(cS3DVector2& location) const = 0;
	/**
	 * @param propertyHolder Optional property holder to use to retrieve the decal shadow parameters. If null, will return hardcoded values
	 * @param outShadowTextureId Reads from property 0x085489C8 (Shadow Texture ID) or defaults to 0x0917660E if property holder not present
	 * @param outShadowStrength Reads from property 0x085489CC (Shadow strength) or defaults to -1.0 if property holder not present
	 * @param outShadowThreshold Reads from property 0x085489CD (Shadow threshold) or defaults to an unknown value if property holder not present
	 * @param outShadowSize Reads from property 0x085489CA (Shadow size) or default to 8.0f if property holder not present
	 * @param outShadowOffset Offset in (X, Z). Reads from property 0x085489C9 (Shadow offset) or defaults to unknown values if property holder not present
	 * @param outShadowColor Color in (R, G, B). Reads from property 0x085489CB (Shadow color) or defaults to unknown values if property holder not present
	 */
	virtual void GetDecalShadowParams(cISCPropertyHolder* propertyHolder,
	                                  unsigned long& outShadowTextureId,
	                                  float& outShadowStrength,
	                                  float& outShadowThreshold,
	                                  float& outShadowSize,
	                                  cS3DVector2& outShadowOffset,
	                                  cS3DVector3& outShadowColor) const = 0;
	/**
	 * @param pointCount Number of sample points
	 * @param points Sample points in 3D
	 * @param shadowUV Corresponding 2D shadow/UV coordinates
	 * @param objectTransform Model/world transform
	 * @param outMatrix Resulting shadow projection matrix
	 * @return Calculation successful or not
	 */
	virtual bool CalcShadowProjection(int pointCount, cS3DVector3 const* points, cS3DVector2 const* shadowUV, cS3DTransform const& objectTransform, cS3DMatrix4& outMatrix) const = 0;
	/**
	 * @param pointCount Number of sample points (unused in recent builds?)
	 * @param points Sample points in 3D (unused in recent builds?)
	 * @param shadowBox 3D axis-aligned bounding box of the model's shadow (in world space)
	 * @param outRect Output rectangle on the terrain grid that corresponds to the area covered by the model's shadow
	 * @return Calculation successful or not
	 */
	virtual bool CalcShadowTerrainRect(int pointCount, cS3DVector3 const* points, cS3DBoundingBox const& shadowBox, cRZRect& outRect) = 0;

	// NOTE: The ordering of these overloaded methods is reversed in the Windows v641 binary compared to the MacOS x86 binary.
	// This header follows the Windows v641 vtable.
	virtual void GetColor(cS3DVector3 const& position, cS3DVector3 const& normal, unsigned char& outR, unsigned char& outG, unsigned char& outB) const = 0;
	virtual void GetColor(cS3DVector3 const& normal, unsigned char& outR, unsigned char& outG, unsigned char& outB) const = 0;
	virtual void GetColor(unsigned char& outR, unsigned char& outG, unsigned char& outB) const = 0;
	virtual cS3DVector3 GetColor(cS3DVector3 const& normal, cS3DVector3 const& position) const = 0;
	virtual cS3DVector3 GetColor(cS3DVector3 const& normal) const = 0;
	virtual cS3DVector3 GetColor() const = 0;

	virtual void GetTerrainColor(cS3DVector3 const& position, cS3DVector3 const& normal, unsigned char& outR, unsigned char& outG, unsigned char& outB) const = 0;
	virtual void GetTerrainColorFloor(cS3DVector3 const& position, cS3DVector3 const& normal, unsigned char& outR, unsigned char& outG, unsigned char& outB) const = 0;

	virtual void GetVertexColors(int vertexCount,
								 cS3DVector3 const* vertexNormals,
								 int normalStride,
								 unsigned char* outColors,	// ARGB8 per vertex
								 int colorStride,
								 cS3DMatrix3 const& normalToLightFrame) const = 0;
	virtual void GetTerrainVertexColors(int tileX,
										int tileZ,
										int vertexCount,
										cS3DVector3 const* vertexNormals,
										int normalStride,
										unsigned char* outVertexColors, // R0,G0,B0 (terrain lightmap),R1,G1,B1 (terrain floor/ambient) per vertex
										int colorStride) const = 0;
};