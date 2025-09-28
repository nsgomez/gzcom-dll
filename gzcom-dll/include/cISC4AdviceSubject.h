/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4AdviceSubject.h
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

/**
 * @brief An interface for descriptors of advice targets
 *
 * Generally used for pointing to places that are affected by a piece of
 * advice, such as a disaster location or a high-crime tile.
 */
class cISC4AdviceSubject : public cIGZUnknown
{
	public:
		virtual bool SetLocation(float x, float z) = 0;
		virtual float GetLocationX(void) = 0;
		virtual float GetLocationZ(void) = 0;
		virtual bool HasLocation(void) = 0;

		virtual bool SetObject(cIGZUnknown* pObject) = 0;
		virtual cIGZUnknown* GetObjectA(void) = 0;

		virtual uint32_t GetData1(void) = 0;
		virtual bool SetData1(uint32_t dwData) = 0;

		virtual uint32_t GetData2(void) = 0;
		virtual bool SetData2(uint32_t dwData) = 0;
};