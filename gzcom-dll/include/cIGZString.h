#pragma once
#include "cIGZUnknown.h"

// The prototypes for the functions in this class are mostly known, but what's
// unknown is what methods are actually in the pure virtual interface, and in
// what order. Everything here is a best guess and odds are that none of this
// actually works.
class cIGZString : public cIGZUnknown
{
	public:
		virtual uint32_t Copy(cIGZString const& szCopyFrom) = 0;
		
		/* ------- start RZSZ section ---- */
		virtual cIGZString* SplitToken(char const* pszToken) = 0;
		virtual cIGZString* SplitTokenDelimited(char cDelimiter) = 0;
		virtual cIGZString* SplitTokenDelimited(char cDelimiter, cIGZString& szUnknown) = 0;
		virtual cIGZString* Strncpy(char const* pszSource, uint32_t dwLen) = 0;
		virtual cIGZString* Strcat(char const* pszSource) = 0;
		/* -------- end RZSZ section ----- */

		/* ------- start RZSZ section ---- */
		/* -------- end RZSZ section ----- */
		
		virtual uint32_t LTrim(void) = 0;
		virtual uint32_t RTrim(void) = 0;
		virtual uint32_t Trim(void) = 0;
		virtual uint32_t FromChar(char const* pszSource, uint32_t dwLen) = 0;
		virtual bool IsEqual(cIGZString const& szOther, bool bUnknown) = 0;

		/* ------- start RZSZ section ---- */
		virtual cIGZString* Append(char const* pszSource, uint32_t dwLen) = 0;
		virtual cIGZString* Append(cIGZString const& szSource) = 0;
		virtual cIGZString* Insert(uint32_t dwPos, char const* pszSource, uint32_t dwLen) = 0;
		virtual cIGZString* Insert(uint32_t dwPost, cIGZString const& szSource) = 0;
		virtual cIGZString* Replace(uint32_t dwPos, char const* pszSource, uint32_t dwLen) = 0;
		virtual cIGZString* Replace(uint32_t dwPos, cIGZString const& szSource) = 0;
		virtual cIGZString* Erase(uint32_t dwStart, uint32_t dwEnd) = 0;
		/* -------- end RZSZ section ----- */

		virtual int32_t Resize(uint32_t dwNewLen) = 0;
		virtual char const* ToChar(void) const = 0;

		/* ------- start RZSZ section ---- */
		virtual uint32_t SplitTokenSeparated(char cToken, cIGZString& szUnknown) = 0;
		/* -------- end RZSZ section ----- */

		virtual int32_t Strlen(void) = 0;
		virtual bool BeginsWith(char const* pszBegin, uint32_t dwLen) = 0;
		virtual bool EndsWith(char const* pszEnd, uint32_t dwLen) = 0;
		//virtual int32_t Data(void) = 0;
		
		/* ------- start RZSZ section ---- */
		/*virtual cIGZString* Mid(uint32_t dwStart, uint32_t dwEnd) = 0;
		virtual cIGZString* Right(uint32_t dwCount) = 0;
		virtual cIGZString* Left(uint32_t dwCount) = 0;
		virtual cIGZString* Sprintf(char const* pszFormat, ...) = 0;*/
		/* -------- end RZSZ section ----- */

		/*virtual bool FromChar(char const* pszSource) = 0;
		virtual bool MakeUpper(void) = 0;
		virtual bool MakeLower(void) = 0;
		virtual int32_t RFind(cIGZString const& szOther, uint32_t dwUnknown, bool bUnknown) = 0;
		virtual int32_t RFind(char const* szOther, uint32_t dwUnknown, bool bUnknown) = 0;
		virtual int32_t Find(cIGZString const& szOther, uint32_t dwUnknown, bool bUnknown) = 0;
		virtual int32_t Find(char const* szOther, uint32_t dwUnknown, bool bUnknown) = 0;
		virtual int32_t CompareTo(cIGZString const& szOther, uint32_t dwUnknown, bool bUnknown) = 0;
		virtual int32_t CompareTo(char const* szOther, uint32_t dwUnknown, bool bUnknown) = 0;
		virtual bool IsEqual(cIGZString const& szOther, uint32_t dwUnknown, bool bUnknown) = 0;
		virtual bool IsEqual(char const* szOther, uint32_t dwUnknown, bool bUnknown) = 0;*/
};