#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZBuffer;
class cIGZFile;
class cIGZPersistDBSegment;
class cIGZPersistDBSerialRecord;
class cIGZString;
template<typename T> class SC4Rect;

static const uint32_t GZCLSID_cIGZGimexFactory = 0xa2ffb5d3;
static const uint32_t GZIID_cIGZGimexFactory = 0x02ffbb60;

class cIGZGimexFactory : public cIGZUnknown
{
public:
	virtual bool LoadFromFile(cIGZString const& path, cIGZBuffer* pBuffer, cGZBufferType bufferType) = 0;
	virtual bool LoadFromFile(cIGZString const& path, cIGZBuffer** outBuffer, cGZBufferType bufferType) = 0;

	virtual bool SaveToFile(cIGZString const& path, cIGZBuffer* pBuffer, SC4Rect<int32_t>& area, uint32_t formatID) = 0;
	virtual bool SaveToFile(cIGZString const& path, cIGZBuffer* pBuffer, uint32_t formatID) = 0;
	virtual bool LoadFromFile(cIGZFile* pFile, uint32_t gimexIndex, cIGZBuffer* pBuffer, cGZBufferType bufferType) = 0;
	virtual bool CreateFromFile(cIGZFile* pFile, uint32_t gimexIndex, cIGZBuffer** outBuffer, cGZBufferType bufferType) = 0;

	virtual bool LoadFromResource(cGZPersistResourceKey& key, uint32_t gimexIndex, cIGZBuffer* pBuffer, cGZBufferType bufferType) = 0;
	virtual bool CreateFromResource(cGZPersistResourceKey& key, uint32_t gimexIndex, cIGZBuffer** outBuffer, cGZBufferType bufferType) = 0;
	virtual bool LoadFromSerialRecord(cIGZPersistDBSerialRecord* pRecord, uint32_t gimexIndex, cIGZBuffer* pBuffer, cGZBufferType bufferType) = 0;
	virtual bool CreateFromSerialRecord(cIGZPersistDBSerialRecord* pRecord, uint32_t gimexIndex, cIGZBuffer** outBuffer, cGZBufferType bufferType) = 0;

	virtual bool SaveToFile(cIGZFile* pFile, uint32_t gimexIndex, cIGZBuffer* pBuffer, SC4Rect<int32_t>& area, uint32_t formatID) = 0;
	virtual bool SaveToFile(cIGZFile* pFile, uint32_t gimexIndex, cIGZBuffer* pBuffer, uint32_t formatID) = 0;
	virtual bool SaveToResource(cGZPersistResourceKey& key, cIGZPersistDBSegment* pSegment, uint32_t gimexIndex, cIGZBuffer* pBuffer, SC4Rect<int32_t>& area, uint32_t formatID) = 0;
	virtual bool SaveToResource(cGZPersistResourceKey& key, cIGZPersistDBSegment* pSegment, uint32_t gimexIndex, cIGZBuffer* pBuffer, uint32_t formatID) = 0;
	virtual bool SaveToSerialRecord(cIGZPersistDBSerialRecord* pRecord, uint32_t gimexIndex, cIGZBuffer* pBuffer, SC4Rect<int32_t>& area, uint32_t formatID) = 0;
	virtual bool SaveToSerialRecord(cIGZPersistDBSerialRecord* pRecord, uint32_t gimexIndex, cIGZBuffer* pBuffer, uint32_t formatID) = 0;
};