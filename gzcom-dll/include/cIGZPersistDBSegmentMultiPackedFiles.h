#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZPersistDBSegment;
class cIGZPersistResourceKeyFilter;
class cIGZString;

static const uint32_t GZCLSID_cGZPersistDBSegmentMultiPackedFiles = 0x90F8619;
static const uint32_t GZIID_cIGZPersistDBSegmentMultiPackedFiles = 0xE90F85F3;

class cIGZPersistDBSegmentMultiPackedFiles : public cIGZUnknown
{
public:
	virtual void SetPathFilter(cIGZString const&) = 0;

	virtual int32_t ConsolidateDatabaseRecords(cIGZPersistDBSegment*, cIGZPersistResourceKeyFilter*) = 0;
	virtual int32_t ConsolidateDatabaseRecords(cIGZString const&, cIGZPersistResourceKeyFilter*) = 0;

	virtual bool FindDBSegment(cGZPersistResourceKey const&, cIGZPersistDBSegment**) = 0;
	virtual uint32_t GetSegmentCount() = 0;
	virtual cIGZPersistDBSegment* GetSegmentByIndex(uint32_t) = 0;

	virtual void AddedResource(cGZPersistResourceKey const&, cIGZPersistDBSegment*) = 0;
	virtual void RemovedResource(cGZPersistResourceKey const&, cIGZPersistDBSegment*) = 0;
};
