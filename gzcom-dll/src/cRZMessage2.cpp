/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZMessage2.cpp
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

#include "../include/cRZMessage2.h"

cRZMessage2::cRZMessage2() {
	m_dwType = 0;
}

bool cRZMessage2::QueryInterface(uint32_t riid, void** ppvObj) {
	if (riid == 0x65297976) {
		*ppvObj = this;
		AddRef();
		return true;
	}
	else if (riid == 0xa52294b4) {
		*ppvObj = static_cast<cIGZMessage2*>(this);
		AddRef();
		return true;
	}
	else {
		return cRZUnknown::QueryInterface(riid, ppvObj);
	}
}

bool cRZMessage2::Create(uint32_t dwType, void** ppUnknown) const {
	cRZMessage2* pMessage = new cRZMessage2();
	if (pMessage == NULL || !pMessage->QueryInterface(dwType, ppUnknown))
		return false;

	pMessage->SetType(GetType());
	return true;
}

uint32_t cRZMessage2::GetType(void) const {
	return m_dwType;
}

uint32_t cRZMessage2::SetType(uint32_t dwType) {
	m_dwType = dwType;
	return m_dwType;
}

bool cRZMessage2::operator==(cIGZMessage2 const& msgOther) const {
	return m_dwType == msgOther.GetType();
}

bool cRZMessage2::operator<(cIGZMessage2 const& msgOther) const {
	return m_dwType < msgOther.GetType();
}