/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISTETerrainView.h
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
#include "cISTETerrain.h"

class cGZPersistResourceKey;
class cISTEOverlayManager;
class cRZCmdLine;
class cS3DVector2;
class cS3DVector3;
class SC4DrawContext;

template <typename T> class SC4Point;
template <typename T> class SC4Rect;
template <typename T> class SC4Vector;

class cISTETerrainView : public cIGZUnknown
{
public:
	enum class tOverlayManagerType
	{
		Unknown1 = 0,
		Unknown2 = 1,
		Unknown3 = 2,
		Unknown4 = 3,
	};

	virtual bool Pick(cS3DVector3 const&, cS3DVector3 const&, SC4DrawContext*, float*, bool) = 0;

	virtual bool MarkSelected(SC4Vector<SC4Point<int>>&, cISTETerrain::eHilightColorType, bool clearPreviousSelections) = 0;
	virtual bool MarkSelected(SC4Rect<int>&, cISTETerrain::eHilightColorType, bool clearPreviousSelections) = 0;
	virtual bool MarkSelected(SC4Point<int> const&, cISTETerrain::eHilightColorType, bool clearPreviousSelections) = 0;
	virtual bool MarkSelected(SC4Point<int> const&, cGZPersistResourceKey const& textureKey, uint8_t, bool, cISTETerrain::eHilightColorType, uint8_t alpha, bool clearPreviousSelections) = 0;
	virtual bool MarkSelected(SC4Point<int> const&, cGZPersistResourceKey const& textureKey, uint8_t, bool, uint32_t, int32_t /*cGDCombiner::tOp*/, bool clearPreviousSelections) = 0;
	virtual void ClearCurrentSelections() = 0;

	virtual bool SetAutomaticCellCursorUpdateStatus(bool) = 0;
	virtual bool IsWaterGlareEnabled() const = 0;
	virtual void SetWaterGlareStatus(bool) = 0;
	virtual void SetLightingUpdateRect(SC4Rect<int> const*) = 0;

	virtual void DrawTerrainQuad(SC4DrawContext*, uint32_t, uint32_t) = 0;
	virtual void DrawTexturedTerrainQuad(SC4DrawContext*, uint32_t, uint32_t, cS3DVector2*, float, bool) = 0;
	virtual void LevelCell(int, int, float) = 0;
	virtual void RemoveCellLevelling(int, int) = 0;

	virtual cISTEOverlayManager* GetOverlayManager(cISTETerrainView::tOverlayManagerType) const = 0;

	virtual bool HandleCheatCommand(cRZCmdLine&) = 0;

	virtual bool GetDisplayGridFlag() const = 0;
	virtual void SetDisplayGridFlag(bool) = 0;
};