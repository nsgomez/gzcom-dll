/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISCExemplarCache.h
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

class cIGZUnknownList;
class cISCExemplarCacheQueryDef;
class cISCResExemplar;
class cISCResExemplarCohort;

static const uint32_t GZIID_cISCExemplarCache = 0xa52ea0c8;

class cISCExemplarCache : public cIGZUnknown
{
public:
	// When notify is true, the retained queries are refreshed and a change
	// message is sent after the cache is updated.
	virtual bool AddExemplar(cISCResExemplar* exemplar, bool notify) = 0;
	virtual bool RemoveExemplar(cISCResExemplar* exemplar, bool notify) = 0;
	virtual bool AddCohort(cISCResExemplarCohort* cohort) = 0;
	virtual bool RemoveCohort(cISCResExemplarCohort* cohort, bool notify) = 0;

	// Runs a one-off query and hands back a new list of matching exemplars.
	virtual bool PerformQuery(cISCExemplarCacheQueryDef* queryDef, cIGZUnknownList** results) = 0;

	// Retained queries are keyed by the ID of their query definition. The
	// cache keeps their results, which can be rerun and fetched by that ID.
	virtual bool RegisterRetainedQuery(cISCExemplarCacheQueryDef* queryDef) = 0;
	virtual bool UnregisterRetainedQuery(uint32_t queryId) = 0;
	virtual bool PerformRetainedQuery(uint32_t queryId) = 0;
	virtual bool GetRetainedQueryResult(uint32_t queryId, cIGZUnknownList** results) = 0;
};
