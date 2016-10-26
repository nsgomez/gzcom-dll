#pragma once
#include "cIGZSerializable.h"

class cGZPersistResourceKey;
class cISCPropertyHolder;
class cISCResExemplarCohort;

class cISCResExemplar : public cIGZSerializable
{
	public:
		virtual cISCPropertyHolder* AsISCPropertyHolder(void) = 0;
		virtual cISCPropertyHolder* AsISCPropertyHolder(void) const = 0;

		virtual bool IsPropertyLocal(uint32_t dwProperty) = 0;

		virtual cISCResExemplarCohort* GetCohort(void) = 0;
		virtual bool SetCohort(cISCResExemplarCohort* pCohort, bool bSendMsg) = 0;

		virtual bool GetKey(cGZPersistResourceKey& sKey) = 0;
		virtual bool SetKey(cGZPersistResourceKey const& sKey) = 0;

		virtual bool CompactProperties(void) = 0;
};