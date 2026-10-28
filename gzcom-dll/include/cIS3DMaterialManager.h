/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIS3DMaterialManager.h
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

class cIGZString;
class cS3DMaterial;
class cS3DResMaterial;

static const uint32_t GZIID_cIS3DMaterialManager = 0xfac0e21a;

class cIS3DMaterialManager : public cIGZUnknown
{
public:
	// Builds a material from its resource description. The new material is
	// returned through ppMaterial.
	virtual bool CreateMaterial(cS3DResMaterial const& resMaterial, cS3DMaterial** ppMaterial) = 0;

	// Always fails in 1.1.641, the game ships a stub that returns false.
	virtual bool CreateMaterialVariant(cS3DMaterial* pMaterial, uint32_t variant, cS3DMaterial** ppVariant) = 0;

	// Writes "Nothing to report" into the string.
	virtual void GetStatsString(cIGZString& stats) = 0;
};
