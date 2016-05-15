#pragma once
#include "cIGZString.h"
#include <string>

// There are many things that are wrong with this that should be fairly obvious.
class cRZDummyString : public cIGZString
{
	public:
		cRZDummyString& operator=(const cRZDummyString& szOther) {
			memcpy(this, &szOther, sizeof(cRZDummyString));
			return *this;
		}

		cRZDummyString& operator=(const cIGZString& szOther) {
			// This could probably blow up the program
			const cRZDummyString* pszOther = (const cRZDummyString*)&szOther;
			
			memcpy(this, pszOther, sizeof(cRZDummyString));
			return *this;
		}

		virtual bool QueryInterface(uint32_t riid, void** ppvObj) {
			return false;
		}

		virtual uint32_t AddRef(void) {
			return 0;
		}

		virtual uint32_t Release(void) {
			return 0;
		}

		virtual uint32_t Copy(cIGZString const& szCopyFrom) {
			return ~0;
		}
		
		virtual cIGZString* SplitToken(char const* pszToken) {
			return nullptr;
		}

		virtual cIGZString* SplitTokenDelimited(char cDelimiter) {
			return nullptr;
		}

		virtual cIGZString* SplitTokenDelimited(char cDelimiter, cIGZString& szUnknown) {
			return nullptr;
		}

		virtual cIGZString* Strncpy(char const* pszSource, uint32_t dwLen) {
			return nullptr;
		}

		virtual cIGZString* Strcat(char const* pszSource) {
			return nullptr;
		}
		
		virtual uint32_t LTrim(void) {
			return 0;
		}

		virtual uint32_t RTrim(void) {
			return 0;
		}

		virtual uint32_t Trim(void) {
			return 0;
		}

		virtual uint32_t FromChar(char const* pszSource, uint32_t dwLen) {
			return 0;
		}

		virtual bool IsEqual(cIGZString const& szOther, bool bUnknown) {
			return false;
		}


		virtual cIGZString* Append(char const* pszSource, uint32_t dwLen) {
			return nullptr;
		}

		virtual cIGZString* Append(cIGZString const& szSource) {
			return nullptr;
		}

		virtual cIGZString* Insert(uint32_t dwPos, char const* pszSource, uint32_t dwLen) {
			return nullptr;
		}

		virtual cIGZString* Insert(uint32_t dwPost, cIGZString const& szSource) {
			return nullptr;
		}

		virtual cIGZString* Replace(uint32_t dwPos, char const* pszSource, uint32_t dwLen) {
			return nullptr;
		}

		virtual cIGZString* Replace(uint32_t dwPos, cIGZString const& szSource) {
			return nullptr;
		}

		virtual cIGZString* Erase(uint32_t dwStart, uint32_t dwEnd) {
			return nullptr;
		}

		virtual int32_t Resize(uint32_t dwNewLen) {
			return 0;
		}

		virtual char const* ToChar(void) const {
			return nullptr;
		}

		virtual uint32_t SplitTokenSeparated(char cToken, cIGZString& szUnknown) {
			return 0;
		}

		virtual int32_t Strlen(void) {
			return 0;
		}

		virtual bool BeginsWith(char const* pszBegin, uint32_t dwLen) {
			return false;
		}

		virtual bool EndsWith(char const* pszEnd, uint32_t dwLen) {
			return false;
		}

		virtual int32_t Data(void) {
			return 0;
		}
		
		virtual cIGZString* Mid(uint32_t dwStart, uint32_t dwEnd) {
			return nullptr;
		}

		virtual cIGZString* Right(uint32_t dwCount) {
			return nullptr;
		}

		virtual cIGZString* Left(uint32_t dwCount) {
			return nullptr;
		}

		virtual cIGZString* Sprintf(char const* pszFormat, ...) {
			return nullptr;
		}

		virtual bool FromChar(char const* pszSource) {
			return false;
		}

		virtual bool MakeUpper(void) {
			return false;
		}

		virtual bool MakeLower(void) {
			return false;
		}

		virtual int32_t RFind(cIGZString const& szOther, uint32_t dwUnknown, bool bUnknown) {
			return ~0;
		}

		virtual int32_t RFind(char const* szOther, uint32_t dwUnknown, bool bUnknown) {
			return ~0;
		}

		virtual int32_t Find(cIGZString const& szOther, uint32_t dwUnknown, bool bUnknown) {
			return ~0;
		}

		virtual int32_t Find(char const* szOther, uint32_t dwUnknown, bool bUnknown) {
			return ~0;
		}

		virtual int32_t CompareTo(cIGZString const& szOther, uint32_t dwUnknown, bool bUnknown) {
			return ~0;
		}

		virtual int32_t CompareTo(char const* szOther, uint32_t dwUnknown, bool bUnknown) {
			return ~0;
		}

		virtual bool IsEqual(cIGZString const& szOther, uint32_t dwUnknown, bool bUnknown) {
			return false;
		}

		virtual bool IsEqual(char const* szOther, uint32_t dwUnknown, bool bUnknown) {
			return false;
		}

	protected:
		// https://github.com/Fatbag/Niotso/blob/master/Tools/TSOSimulatorClient/TSOSimulatorClient.hpp#L24
		uint32_t   Zero1;
		uint32_t   Zero2;
		void *     vtable5;
		char **    Strings1;
		char **    Strings2;
		char **    Strings3;
		uint32_t   Zero3;
		uint32_t   Zero4;
		uint32_t   Zero5;
		void **    Pointer1; //12 bytes
		void **    Pointer2; //4 bytes
		void **    Pointer3;
		uint32_t   Flags;
		uint32_t * Pointer4; //4 bytes
		void *     Pointer5;
		void *     Pointer6;
		uint32_t   Unknown11;
		uint32_t   Unknown12;
};