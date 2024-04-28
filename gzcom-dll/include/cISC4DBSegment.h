#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZPersistDBSegment;
class cISC4COMSerializer;
class cISC4DBSegmentIStream;
class cISC4DBSegmentOStream;

static const uint32_t GZIID_cISC4DBSegment = 0x499899da;

class cISC4DBSegment : public cIGZUnknown
{
public:
	virtual cIGZPersistDBSegment* AsIGZPersistDBSegment() = 0;

	virtual cISC4COMSerializer* GetCOMSerializer() = 0;

	virtual bool OpenIStream(cGZPersistResourceKey const& key, cISC4DBSegmentIStream** ppStream) = 0;
	virtual void CloseIStream(cISC4DBSegmentIStream* pStream) = 0;

	virtual bool LoadClassObjects() = 0;

	virtual bool OpenOStream(cGZPersistResourceKey const& key, cISC4DBSegmentOStream** ppStream, bool bUnknown) = 0;
	virtual void CloseOStream(cISC4DBSegmentOStream* pStream) = 0;

	virtual bool SaveClassObjects() = 0;

	virtual uint32_t GetLastError() = 0;

	virtual float GetPercentageCompletion() = 0;
	virtual void SetPercentageCompletion(float percentage) = 0;
};