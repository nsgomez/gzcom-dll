#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZPersistResource;
class cIGZPersistResourceKeyList;
class cIGZPersistResourceKeyFilter;
class cIGZPersistResourceFactory;
class cIGZPersistDBRecord;
class cIGZPersistDBSegment;
class cIGZPersistCacheStrategy;

class cIGZPersistResourceManager : public cIGZUnknown
{
public:

	virtual bool GetResource(cGZPersistResourceKey const& resKey, uint32_t riid, void** ppvObj, uint32_t unknown1, cIGZUnknown* unknown2) = 0;
	virtual bool GetPrivateResource(cGZPersistResourceKey const& resKey, uint32_t riid, void** ppvObj, uint32_t unknown1, cIGZUnknown* unknown2) = 0;
	virtual bool GetNewResource(cGZPersistResourceKey const& resKey, uint32_t riid, void** ppvObj, uint32_t unknown1, cIGZUnknown* unknown2) = 0;
	virtual bool GetNewResource(uint32_t unknown1, uint32_t unknown2, void** unknown3, uint32_t unknown4, cIGZUnknown* unknown5) = 0;

	virtual bool RegisterResource(cGZPersistResourceKey const& key, cIGZPersistResource& resource) = 0;
	virtual bool RegisterResource(cIGZPersistResource* resource) = 0;
	virtual bool UnregisterResource(cGZPersistResourceKey const& key) = 0;
	virtual bool HasRegisteredResource(cGZPersistResourceKey const& key) = 0;

	virtual bool Save(cGZPersistResourceKey const& key, cIGZPersistDBSegment* dbSegment) = 0;
	virtual bool Save(cIGZPersistResourceKeyList* list, cIGZPersistDBSegment* dbSegment) = 0;
	virtual bool SaveResource(cIGZPersistResource* resource, cGZPersistResourceKey const& key, cIGZPersistDBSegment* dbSegment) = 0;

	virtual bool TestForKey(cGZPersistResourceKey const& key) = 0;
	virtual uint32_t GetResourceList(cIGZPersistResourceKeyList** ppResourceList, cIGZPersistResourceKeyFilter* filter) = 0;
	virtual uint32_t GetResourceListForType(cIGZPersistResourceKeyList** ppResourceList, uint32_t unknown1) = 0;
	virtual uint32_t GetAvailableResourceList(cIGZPersistResourceKeyList** ppResourceList, cIGZPersistResourceKeyFilter* filter) = 0;
	virtual uint32_t GetAvailableResourceListForType(cIGZPersistResourceKeyList** ppResourceList, uint32_t unknown1) = 0;

	virtual bool RegisterObjectFactory(uint32_t unknown1, uint32_t unknown2, cIGZPersistResourceFactory* factory) = 0;
	virtual bool UnregisterObjectFactory(cIGZPersistResourceFactory* factory) = 0;
	virtual bool FindObjectFactory(cIGZPersistResource* unknown1, cIGZPersistResourceFactory** unknown2) = 0;
	virtual bool FindObjectFactory(cIGZPersistResourceFactory** unknown2) = 0;
	virtual bool FindObjectFactory(uint32_t unknown1, cIGZPersistResourceFactory** ppFactory) = 0;
	virtual uint32_t GetFactoryCount() = 0;
	virtual cIGZPersistResourceFactory* GetFactoryByIndex(uint32_t index) = 0;

	virtual bool RegisterDBSegment(cIGZPersistDBSegment& segment) = 0;
	virtual bool RegisterDBSegmentFront(cIGZPersistDBSegment& segment) = 0;
	virtual bool RegisterDBSegmentBack(cIGZPersistDBSegment& segment) = 0;
	virtual bool UnregisterDBSegment(cIGZPersistDBSegment& segment) = 0;
	virtual bool TestDBSegment(cIGZPersistDBSegment& segment) = 0;
	virtual bool FindDBSegment(cGZPersistResourceKey const& key, cIGZPersistDBSegment** ppSegment) = 0;
	virtual bool FindDBSegment(uint32_t unknown1, cIGZPersistDBSegment** ppSegment) = 0;
	virtual uint32_t GetSegmentCount() = 0;
	virtual cIGZPersistDBSegment* GetSegmentByIndex(uint32_t unknown1) = 0;

	typedef bool(*EnumerateDBSegmentsCallback)(cIGZPersistDBSegment*, void*);

	virtual uint32_t EnumerateDBSegments(cIGZPersistDBSegment** unknown1, uint32_t* unknown2) = 0;
	virtual bool EnumerateDBSegments(EnumerateDBSegmentsCallback* pCallback, cIGZPersistDBSegment* unknown2) = 0;

	virtual bool OpenDBRecord(cGZPersistResourceKey const& key, cIGZPersistDBRecord** unknown2, bool unknown3) = 0;
	virtual bool CloseDBRecord(cGZPersistResourceKey const& key, cIGZPersistDBRecord** unknown2) = 0;
	virtual bool AddCacheStrategy(cIGZPersistCacheStrategy* cacheStrategy) = 0;
	virtual bool RemoveCacheStrategy(cIGZPersistCacheStrategy* cacheStrategy) = 0;

	virtual bool IsGarbageCollectionActive() = 0;
	virtual void SetGarbageCollectionActive(bool value) = 0;
	virtual void ForceGarbageCollection() = 0;
};
