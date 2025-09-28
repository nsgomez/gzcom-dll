/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZAutoRefCount.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2024, 2025 Nicholas Hayes
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
#include <type_traits>

template<class T>
class cRZAutoRefCount
{
	static_assert(std::is_base_of<cIGZUnknown, T>::value, "T must extend cIGZUnknown");
	public:
		cRZAutoRefCount() {
			pObject = nullptr;
		}

		cRZAutoRefCount(T* pObject) {
			this->pObject = pObject;
		}

		enum AddRef { kAddRef };

		cRZAutoRefCount(T* pObject, AddRef addRef) {
			this->pObject = pObject;

			if (this->pObject) {
				this->pObject->AddRef();
			}
		}

		cRZAutoRefCount(const cRZAutoRefCount<T>& other) {
			this->pObject = other.pObject;

			if (this->pObject) {
				this->pObject->AddRef();
			}
		}

		cRZAutoRefCount(cRZAutoRefCount<T>&& other) noexcept {
			this->pObject = other.pObject;
			other.pObject = nullptr;
		}

		virtual ~cRZAutoRefCount() {
			Reset();
		}

		cRZAutoRefCount<T>& operator=(T* pOther) {
			if (pObject != pOther) {
				if (pObject) {
					pObject->Release();
				}

				pObject = pOther;
				if (pOther) {
					pOther->AddRef();
				}
			}

			return *this;
		}

		cRZAutoRefCount<T>& operator=(const cRZAutoRefCount<T>& other) {
			return operator=(other.pObject);
		}

		cRZAutoRefCount<T>& operator=(cRZAutoRefCount<T>&& other) noexcept {
			this->pObject = other.pObject;
			other.pObject = nullptr;
			return *this;
		}

		void Reset() {
			if (pObject) {
				pObject->Release();
				pObject = nullptr;
			}
		}

		void** AsPPVoid() {
			return reinterpret_cast<void**>(AsPPObj());
		}

		T** AsPPObj() {
			Reset();

			return &pObject;
		}

		T* operator->() const { return pObject; }
		T& operator*() const { return *pObject; }
		operator T*() const { return pObject; }

	protected:
		T* pObject;
};