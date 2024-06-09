#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class SC4String;

static const uint32_t GZIID_cIGZFile = 0xe0203645;

class cIGZFile : public cIGZUnknown
{
public:
	enum class AccessMode : uint32_t
	{
		None = 0,
		Read = 1,
		Write = 2,
		ReadWrite = Read | Write,
	};

	enum class CreationMode : uint32_t
	{
		CreateNew = 0,
		CreateAlways = 1,
		OpenExisting = 2,
		OpenAlways = 3,
		TruncateExisting = 4,
	};

	enum class ShareMode : uint32_t
	{
		None = 0,
		Read = 1,
		ReadWrite = 2,
	};

	enum class SeekMethod : int32_t
	{
		Begin = 0,
		Current = 1,
		End = 2,
	};

	virtual bool Open(AccessMode accessMode, CreationMode creationMode, ShareMode shareMode) = 0;
	virtual bool IsOpen() const = 0;
	virtual bool Close() = 0;

	virtual int32_t Position() = 0;
	virtual uint32_t Length() = 0;
	virtual bool SetLength(uint32_t length) = 0;

	virtual uint32_t SeekToBegin() = 0;
	virtual uint32_t SeekToEnd() = 0;
	virtual uint32_t SeekToRelativePosition(int32_t position) = 0;
	virtual uint32_t SeekToPosition(uint32_t position) = 0;

	virtual uint32_t Seek(int32_t position, SeekMethod mode) = 0;

	virtual bool Read(void* outBuffer, uint32_t byteCount) = 0;
	virtual bool ReadWithCount(void* outBuffer, uint32_t& byteCount) = 0;

	virtual bool Write(void* buffer, uint32_t byteCount) = 0;
	virtual bool WriteWithCount(void* buffer, uint32_t& byteCount) = 0;

	virtual bool Flush() = 0;
	virtual bool Remove() = 0;
	virtual bool Rename(cIGZString const& newName) = 0;
	virtual bool Exists() = 0;

	virtual bool Copy(cIGZString const& newPath, bool overwriteExisting) = 0;
	virtual bool Copy(cIGZFile const& newFile, bool overwriteExisting) = 0;

	virtual bool GetPath(cIGZString& path) const = 0;
	virtual SC4String* GetPath() const = 0;
	virtual const char* const GetPathCStr() const = 0;

	virtual void SetPath(cIGZString const& path) = 0;
	virtual void SetPath(const char* path) = 0;

	virtual bool GetOpenModes(AccessMode& accessMode, CreationMode& creationMode, ShareMode& shareMode) const = 0;

	virtual void GetBuffering(uint32_t& readBufferSize, uint32_t& writeBufferSize) const = 0;
	virtual bool SetBuffering(uint32_t readBufferSize, uint32_t writeBufferSize) = 0;
};