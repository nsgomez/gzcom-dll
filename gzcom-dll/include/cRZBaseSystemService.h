#pragma once
#include "cIGZSystemService.h"

/**
 * @brief A base class that handles the boilerplate for
 * implementing a GZCOM system service.
 */
class cRZBaseSystemService : public cIGZSystemService
{
public:
	bool QueryInterface(uint32_t riid, void** ppvObj) override;

	uint32_t AddRef() override;

	uint32_t Release() override;

	uint32_t GetServiceID() override;

	cIGZSystemService* SetServiceID(uint32_t id) override;

	int32_t GetServicePriority() override;

	bool IsServiceRunning() override;

	cIGZSystemService* SetServiceRunning(bool running) override;

	bool OnTick(uint32_t unknown1) override;

	bool OnIdle(uint32_t unknown1) override;

	int32_t GetServiceTickPriority() override;

protected:
	cRZBaseSystemService(uint32_t serviceID, int32_t servicePriority);

	uint32_t refCount;
	uint32_t serviceID;
	int32_t servicePriority;
	int32_t serviceTickPriority;
	bool serviceRunning;
};
