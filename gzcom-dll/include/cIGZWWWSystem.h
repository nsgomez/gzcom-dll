/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWWWSystem.h
 *
 * Copyright (C) 2026 Casper Van Gheluwe
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "cIGZUnknown.h"

class cIGZMessageTarget2;
class cIGZWWWSystemURLHandler;
class cRZCookieManager;
class cRZHTTPClient;
class cRZURL;
class NetworkFileCache;
class SC4String;

static const uint32_t GZIID_cIGZWWWSystem = 0x449b1912;

/**
 * @brief The framework service that downloads documents over HTTP and FTP.
 *
 * Each load request gets a job ID. The result is posted to a cIGZMessageTarget2,
 * either the one passed to LoadDocument or the default notification target.
 * The game's HTTP client, FTP client, network file cache and cookie manager are
 * concrete classes without an SDK definition, so they are only declared here.
 */
class cIGZWWWSystem : public cIGZUnknown
{
public:
	// Where a downloaded document is kept. The value names are not known.
	// Passing 4 lets the system pick one from the URL's file extension,
	// which gives 1 for a few known extensions and 3 for everything else.
	enum RAMDataPreference : int32_t {};

	// A pending download. Its layout holds the game's own std::string, so it is opaque.
	struct Job;

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual bool PostInit() = 0;

	// The target receives load notifications when LoadDocument gets a null target.
	// The system holds a reference to it.
	virtual void SetDefaultNotificationTarget(cIGZMessageTarget2* pTarget) = 0;
	virtual cIGZMessageTarget2* GetDefaultNotificationTarget() = 0;

	// Used when LoadDocument gets null custom data.
	virtual void SetDefaultCustomData(void* pData) = 0;
	virtual void* GetDefaultCustomData() = 0;

	virtual bool GetCacheDirectory(SC4String& directoryOut) = 0;
	virtual bool SetCacheDirectory(SC4String const& directory) = 0;

	virtual void SetCookieUsage(bool useCookies) = 0;
	virtual bool GetCookieUsage() = 0;
	virtual void SetCacheUsage(bool useCache) = 0;
	virtual bool GetCacheUsage() = 0;

	// Starts loading a document. Returns the new job ID, or 0 if the request failed.
	// The string overload parses the URL and calls the cRZURL overload.
	virtual uint32_t LoadDocument(SC4String const& url, cIGZMessageTarget2* pTarget, RAMDataPreference ramDataPreference, void* pCustomData, bool bUnknown) = 0;
	virtual uint32_t LoadDocument(cRZURL& url, cIGZMessageTarget2* pTarget, RAMDataPreference ramDataPreference, void* pCustomData, bool bUnknown) = 0;

	// Returns 2 while the job is still queued or loading and 0 otherwise.
	virtual uint32_t GetDocumentLoadStatus(uint32_t jobID) = 0;
	// Returns nullptr if no pending job has that ID.
	virtual Job* GetJob(uint32_t jobID) = 0;
	// These return 0 when the job does not exist or uses the other protocol.
	virtual uint32_t HTTPClientJobIDFromWWWSystemJobID(uint32_t jobID) = 0;
	virtual uint32_t FTPClientJobIDFromWWWSystemJobID(uint32_t jobID) = 0;

	virtual bool CancelDocumentLoadRequest(uint32_t jobID) = 0;
	// Returns the number of requests that were cancelled.
	virtual uint32_t CancelAllDocumentLoadRequests() = 0;

	virtual bool IsVisitedURL(SC4String const& url) = 0;

	virtual bool AddURLHandler(cIGZWWWSystemURLHandler* pHandler) = 0;
	virtual void RemoveURLHandler(cIGZWWWSystemURLHandler* pHandler) = 0;
	virtual void RemoveAllURLHandlers() = 0;

	virtual cRZHTTPClient* GetHTTPClient() = 0;
	// The game's FTP client class has no known name, so this is untyped.
	virtual void* GetFTPClient() = 0;
	virtual NetworkFileCache* GetNetworkFileCache() = 0;
	virtual cRZCookieManager* GetCookieManager() = 0;
};
