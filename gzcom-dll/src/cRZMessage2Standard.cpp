#include "../include/cRZMessage2Standard.h"

#define FIELD_DATA1     (1 << 0)
#define FIELD_DATA2     (1 << 1)
#define FIELD_DATA3     (1 << 2)
#define FIELD_DATA4     (1 << 3)
#define FIELD_STRING    (1 << 4)
#define FIELD_UNKNOWN   (1 << 5)
#define FIELD_EXTRA     (1 << 6)

cRZMessage2Standard::cRZMessage2Standard() {
	m_uDataFlags = 0;
	m_pUnknown = NULL;

	memset(m_dwData, 0, sizeof(m_dwData));
}

bool cRZMessage2Standard::GetHasData1(void) const {
	return IsDataFieldSet(FIELD_DATA1);
}

intptr_t cRZMessage2Standard::GetData1(void) const {
	return m_dwData[0];
}

void* cRZMessage2Standard::GetVoid1(void) const {
	return (void*)GetData1();
}

cIGZMessage2Standard* cRZMessage2Standard::SetData1(intptr_t ulData) {
	m_dwData[0] = ulData;
	m_uDataFlags |= FIELD_DATA1;
	return this;
}

cIGZMessage2Standard* cRZMessage2Standard::SetVoid1(void* pData) {
	return SetData1((intptr_t)pData);
}

bool cRZMessage2Standard::GetHasData2(void) const {
	return IsDataFieldSet(FIELD_DATA2);
}

intptr_t cRZMessage2Standard::GetData2(void) const {
	return m_dwData[1];
}

void* cRZMessage2Standard::GetVoid2(void) const {
	return (void*)GetData2();
}

cIGZMessage2Standard* cRZMessage2Standard::SetData2(intptr_t ulData) {
	m_dwData[1] = ulData;
	m_uDataFlags |= FIELD_DATA2;
	return this;
}

cIGZMessage2Standard* cRZMessage2Standard::SetVoid2(void* pData) {
	return SetData2((intptr_t)pData);
}

bool cRZMessage2Standard::GetHasData3(void) const {
	return IsDataFieldSet(FIELD_DATA3);
}

intptr_t cRZMessage2Standard::GetData3(void) const {
	return m_dwData[2];
}

void* cRZMessage2Standard::GetVoid3(void) const {
	return (void*)GetData3();
}

cIGZMessage2Standard* cRZMessage2Standard::SetData3(intptr_t ulData) {
	m_dwData[3] = ulData;
	m_uDataFlags |= FIELD_DATA3;
	return this;
}

cIGZMessage2Standard* cRZMessage2Standard::SetVoid3(void* pData) {
	return SetData3((intptr_t)pData);
}

bool cRZMessage2Standard::GetHasData4(void) const {
	return IsDataFieldSet(FIELD_DATA4);
}

intptr_t cRZMessage2Standard::GetData4(void) const {
	return m_dwData[3];
}

void* cRZMessage2Standard::GetVoid4(void) const {
	return (void*)GetData4();
}

cIGZMessage2Standard* cRZMessage2Standard::SetData4(intptr_t ulData) {
	m_dwData[3] = ulData;
	m_uDataFlags |= FIELD_DATA4;
	return this;
}

cIGZMessage2Standard* cRZMessage2Standard::SetVoid4(void* pData) {
	return SetData4((intptr_t)pData);
}

bool cRZMessage2Standard::GetHasString(void) const {
	return IsDataFieldSet(FIELD_STRING);
}

bool cRZMessage2Standard::GetString(uint32_t dwMaxLen, void** ppStringOut) const {
	if (!GetHasString()) {
		return false;
	}

	memcpy(*ppStringOut, m_szDataString.Data(), dwMaxLen);
	return true;
}

cIGZMessage2Standard* cRZMessage2Standard::SetString(cIGZString* pString) {
	m_szDataString.Copy(*pString);
	m_uDataFlags |= FIELD_STRING;
	return this;
}

bool cRZMessage2Standard::GetHasIGZUnknown(void) const {
	return IsDataFieldSet(FIELD_UNKNOWN);
}

cIGZUnknown* cRZMessage2Standard::GetIGZUnknown(void) const {
	return m_pUnknown;
}

cIGZMessage2Standard* cRZMessage2Standard::SetIGZUnknown(cIGZUnknown* pObj) {
	if (pObj == NULL)
		m_uDataFlags &= ~(FIELD_UNKNOWN);
	else
		m_uDataFlags |= FIELD_UNKNOWN;

	m_pUnknown = pObj;
	return this;
}

bool cRZMessage2Standard::GetHasExtra(void) const {
	return IsDataFieldSet(FIELD_EXTRA);
}

uint32_t cRZMessage2Standard::GetExtra(uint32_t dwLen, void** ppOut) const {
	throw std::string("UNIMPLEMENTED");
	return (~0);
}

bool cRZMessage2Standard::SetExtra(cIGZSerializable* pSerializable) {
	throw std::string("UNIMPLEMENTED");
	return false;
}