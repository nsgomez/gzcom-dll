#pragma once
#include "cIGZUnknown.h"

class cIGZIStream;
class cIGZMessage2;
class cIGZOStream;
class cISC4Lot;
class cISC4Occupant;
class cS3DBoundingBox;
class cS3DTransform;
class SC4DrawContext;

class cISC4ConstructionOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;
		virtual bool SetLot(cISC4Lot*) = 0;

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool Write(cIGZOStream&) = 0;
		virtual bool Read(cIGZIStream&) = 0;
		virtual uint32_t GetGZCLSID(void) = 0;

		virtual bool GetPosition(float*) = 0;
		virtual void SetPosition(float const*) = 0;

		virtual bool GetBoundingBox(float*, float*) = 0;

		virtual cIGZUnknown* GetOwner(void) = 0;
		virtual void SetOwner(cIGZUnknown*) = 0;
		
		virtual bool GetBounds(cS3DBoundingBox&) = 0;
		virtual bool GetWorldBounds(cS3DBoundingBox&) = 0;

		virtual bool GetTransform(cS3DTransform&) = 0;
		virtual bool SetTransform(cS3DTransform const&) = 0;

		virtual bool GetSortValue(uint32_t&) = 0;

		virtual bool Draw(SC4DrawContext*, bool) = 0;
		virtual bool DoMessage(cIGZMessage2*) = 0;
};
