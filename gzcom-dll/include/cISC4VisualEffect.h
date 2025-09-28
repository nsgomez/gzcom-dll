/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4VisualEffect.h
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

class cS3DTransform;
class cS3DVector3;
class cISC4ComponentEffect;
class cISC4Occupant;

class cISC4VisualEffect : public cIGZUnknown
{
public:
	enum class tTransitionType : int32_t
	{
		Unknown1 = 0,
		Unknown2 = 1,
		Unknown3 = 2,
	};

	typedef uint32_t tParamType;

	virtual void Start(tTransitionType type) = 0;
	virtual void Stop(tTransitionType type) = 0;
	virtual bool IsStarted() = 0;
	virtual bool IsStopping() = 0;

	virtual void SetEffectTransform(cS3DTransform const& transform) = 0;
	virtual void SetSourceTransform(cS3DTransform const& transform) = 0;

	virtual bool SetModelFromOccupant(cISC4Occupant* pOccupant) = 0;
	virtual void SetFinishNotifyMessage(uint32_t messageType, uint32_t data1) = 0;

	virtual bool SetVectorParams(tParamType paramType, cS3DVector3 const* data, int dataCount) = 0;
	virtual bool SetFloatParams(tParamType paramType, float const* data, int dataCount) = 0;
	virtual bool SetVoidParams(tParamType paramType, void** data, int dataCount) = 0;

	virtual void GetEffectTransform(cS3DTransform& transform) = 0;
	virtual void GetSourceTransform(cS3DTransform& transform) = 0;

	virtual bool AddComponentEffect(cISC4ComponentEffect* pEffect, cS3DTransform* unknown2) = 0;

	virtual bool CheckEffectFlag(uint32_t flag) = 0;
};