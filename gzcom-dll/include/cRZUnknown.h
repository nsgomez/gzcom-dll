/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZUnknown.h
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
#include <cassert>

class cRZUnknown : public cIGZUnknown
{
	public:
		cRZUnknown() {
			mnRefCount = 0;
		}

		bool QueryInterface(uint32_t riid, void** ppvObj) override {
			if (riid == 1) {
				*ppvObj = static_cast<cIGZUnknown*>(this);
				AddRef();
				return true;
			}
			else {
				return false;
			}
		}

		uint32_t AddRef(void) override {
			return ++mnRefCount;
		}

		uint32_t Release(void) override {
			assert(mnRefCount > 0);
			if (mnRefCount > 0) {
				--mnRefCount;
			}

			return mnRefCount;
		}

	protected:
		uint32_t mnRefCount;
};