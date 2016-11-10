#pragma once
#include "cIGZUnknown.h"

class cIGZUnknownEnumerator;

/**
 * @brief An interface for lists of cIGZUnknown and unknown-derived objects
 */
class cIGZUnknownList : public cIGZUnknown
{
	public:
		virtual size_t GetSize(void) = 0;
		
		virtual bool GetElement(uint32_t dwOffset, uint32_t riid, void** ppvObj) = 0;
		virtual bool EnumElements(cIGZUnknown& sEnum, cIGZUnknown* pUnknown, uint32_t riid) = 0;

		virtual bool Push_Front(cIGZUnknown* pElem) = 0;
		virtual bool Push_Front(cIGZUnknownList const& sList) = 0;

		virtual bool Push_Back(cIGZUnknown* pElem) = 0;
		virtual bool Push_Back(cIGZUnknownList const& sList) = 0;

		virtual bool Peek_Front(uint32_t riid, void** ppvObj) = 0;
		virtual bool Peek_Back(uint32_t riid, void** ppvObj) = 0;
		virtual bool Pop_Front(uint32_t riid, void** ppvObj) = 0;
		virtual bool Pop_Back(uint32_t riid, void** ppvObj) = 0;

		virtual bool Clear(void) = 0;
		virtual bool CopyFrom(cIGZUnknownList const& sList) = 0;
		virtual bool CreateClone(cIGZUnknownList** ppList) = 0;

		virtual bool ConstEnumElements(cIGZUnknownEnumerator& sEnum, cIGZUnknown* pUnknown, uint32_t riid) = 0;

};