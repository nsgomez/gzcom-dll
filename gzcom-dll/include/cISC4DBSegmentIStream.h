#pragma once
#include "cIGZIStream.h"

class cGZPersistResourceKey;
class cIGZSerializable;
class cIGZVariant;
class cISC4DBSegment;

static const uint32_t GZIID_cISC4DBSegmentIStream = 0x4999a8f5;

class cISC4DBSegmentIStream : public cIGZIStream
{
	public:
		virtual bool Open(cISC4DBSegment* pSegment, cGZPersistResourceKey const& sKey, bool bUnknown) = 0;
		virtual bool Close(void) = 0;

		virtual bool IsOpen(void) = 0;
		
		virtual int32_t GetRecord(void) = 0;
		virtual int32_t GetSegment(void) = 0;
		
		virtual bool ReadGZSerializable(cIGZSerializable** ppSegmentOut) = 0;
		virtual bool ReadResKey(cGZPersistResourceKey& sKeyOut) = 0;
		virtual bool ReadVariant(cIGZVariant& sVariantOut) = 0;
};