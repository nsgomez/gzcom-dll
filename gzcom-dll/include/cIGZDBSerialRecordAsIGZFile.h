#pragma once
#include "cIGZUnknown.h"

class cIGZPersistDBSerialRecord;
class cIGZFile;

static const uint32_t GZCLSID_cIGZDBSerialRecordAsIGZFile = 0xa32c0da;
static const uint32_t GZIID_cIGZDBSerialRecordAsIGZFile = 0x8a32c0ac;

class cIGZDBSerialRecordAsIGZFile : public cIGZUnknown
{
public:
	virtual bool SetDBSerialRecord(cIGZPersistDBSerialRecord* pRecord) = 0;
	virtual cIGZPersistDBSerialRecord* GetDBSerialRecord() = 0;

	virtual cIGZFile* AsIGZFile() = 0;
};