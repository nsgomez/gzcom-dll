#pragma once
#include "cIGZSerializable.h"

class cGZPersistResourceKey;
class cISCPropertyHolder;

static const uint32_t GZIID_cISCResExemplarCohort = 0x452160FB;

class cISCResExemplarCohort : public cIGZSerializable
{
	public:
		virtual cISCResExemplarCohort* GetParent(void) = 0;
		virtual bool SetParent(cISCResExemplarCohort* pCohort, bool bSendMsg) = 0;

		virtual cISCPropertyHolder* AsISCPropertyHolder(void) = 0;
		virtual cISCPropertyHolder* AsISCPropertyHolder(void) const = 0;

		virtual bool IsPropertyLocal(uint32_t dwProperty) = 0;

		virtual bool GetKey(cGZPersistResourceKey& sKey) = 0;
		virtual bool SetKey(cGZPersistResourceKey const& sKey) = 0;

		virtual bool CompactProperties(void) = 0;
};
