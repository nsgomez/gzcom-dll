#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZFile;
class cIGZPersistDBRecord;
class cIGZPersistDBSegment;
class cIGZPersistResourceKeyFilter;
class cIGZString;

static const uint32_t GZCLSID_cGZDBSegmentPackedFile = 0x86D4A89;
static const uint32_t GZIID_cIGZDBSegmentPackedFile = 0x286D4A6A;

class cIGZDBSegmentPackedFile : public cIGZUnknown
{
public:
	virtual cIGZPersistDBSegment* AsIGZPersistDBSegment() = 0;

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual uint32_t GetFileStartingOffset() = 0;
	virtual bool SetFileStartingOffset(uint32_t offset) = 0;

	virtual void GetPath(cIGZString& path) = 0;
	virtual bool SetPath(cIGZString const& path) = 0;

	virtual void GetCurrentUserVersion(uint32_t& majorVersion, uint32_t& minorVersion) = 0;
	virtual void GetNextUserVersion(uint32_t& majorVersion, uint32_t& minorVersion) = 0;
	virtual void SetNextUserVersion(uint32_t majorVersion, uint32_t minorVersion) = 0;

	virtual bool SetFileBuffering(uint32_t readBufferSize, uint32_t writeBufferSize) = 0;

	virtual bool SetHoleUseFlags(long flags) = 0;
	virtual void SetHoleCompactionMinimumRatio(float minRatio) = 0;

	virtual bool IsRecordOpen(cGZPersistResourceKey const& key) = 0;

	virtual bool GetRecordAsIGZFile(cIGZPersistDBRecord* record, cIGZFile** outFile) = 0;
	virtual uint32_t GetRecordSizeRaw(cGZPersistResourceKey const& key) = 0;
	virtual uint32_t ReadRecordRaw(cGZPersistResourceKey const& key, void* buffer, uint32_t& recordSize) = 0;
	virtual bool WriteRecordRaw(cGZPersistResourceKey const& key, void* buffer, uint32_t recordSize) = 0;
	virtual uint32_t GetRecordPosition(cGZPersistResourceKey const& key) = 0;

	virtual uint32_t GetUsedTypeCount() = 0;
	virtual uint32_t GetUsedGroupCount() = 0;
	virtual void EnableUsedTypeAndGroupCounting(bool enabled) = 0;

	virtual uint32_t CopyDatabaseRecords(cIGZPersistDBSegment* targetSegment, cIGZPersistResourceKeyFilter* filter, bool unknown3, bool keepOriginalRecords) = 0;
	virtual uint32_t CopyDatabaseRecords(cIGZString const& targetPath, cIGZPersistResourceKeyFilter* filter, bool unknown3, bool keepOriginalRecords) = 0;

	virtual bool CompactDatabase() = 0;
	virtual bool VerifyDatabase() = 0;

	virtual bool EnableCompressionForAllRecords(bool value) = 0;
	virtual bool EnableCompressionByType(uint32_t type, bool value) = 0;
	virtual bool EnableCompressionByGroup(uint32_t group, bool value) = 0;

	virtual bool GetRecordCompressed(cGZPersistResourceKey const& key) = 0;
	virtual void SetRecordCompressed(cGZPersistResourceKey const& key, bool compress, uint32_t uncompresedSize) = 0;
	virtual uint32_t GetCompressedRecordLength(cGZPersistResourceKey const& key) = 0;

	virtual bool AllocateSpace(uint32_t& unknown1, uint32_t unknown2) = 0;
	virtual bool FreeSpace(uint32_t unknown1, uint32_t unknown2) = 0;
	virtual bool ReallocateSpace(cGZPersistResourceKey const& key, uint32_t& unknown2, uint32_t unknown3) = 0;
	virtual bool GetFreeSpaceMetrics(uint32_t& unknown1, uint32_t& unknown2) = 0;
};