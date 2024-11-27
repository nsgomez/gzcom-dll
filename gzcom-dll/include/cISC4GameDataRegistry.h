#pragma once
#include "cIGZUnknown.h"

class cIGZCommandParameterSet;
class cIGZMessageTarget2;
class cIGZString;
class cIGZVariant;
class cISC4GameDataRegistryNotificationTarget;

static const uint32_t GZCLSID_cISC4GameDataRegistry = 0xebe0e860;
static const uint32_t GZIID_cISC4GameDataRegistry = 0xe898ed03;

/**
 * @brief Used to register functions that can be called from LUA code. These functions
 * are registered in the sc4game LUA table, and grouped by a category/child node.
 * For example: sc4game.automata.get_source_building_count
 */
class cISC4GameDataRegistry : public cIGZUnknown
{
public:
	/**
	 * @brief An opaque type that represents a registry entry.
	 */
	class cEntry;

	enum eEntryFlags : int32_t
	{
		EntryFlagNone = 0,
		EntryFlagCallFunction = 1
	};

	enum eNotificationType : uint32_t
	{
		NotificationTypeShutdown = 1,
		NotificationTypeRemoveEntry = 2,
		NotificationTypeAddEntry = 3,
	};

	typedef bool(*AddChildEntryCallback1)(void* pContext, cIGZVariant& variant, bool set, cISC4GameDataRegistry* registry);
	typedef bool(*AddChildEntryCallback2)(void* pContext, cIGZCommandParameterSet* input, cIGZCommandParameterSet* output, cISC4GameDataRegistry* registry);

	/**
	 * @brief Adds a child node, which are used to group the callback methods.
	 * An example of a child node is the 'aura' part of sc4game.aura.end_strike.
	 * @param key A unique key that identifies node, usually the implementing class.
	 * @param name The name of the child node.
	 * @param parentNode The parent node. This will normally be the root node, see GetRootNodeEntry.
	 * @param flags Unused, should be eEntryFlags::EntryFlagNone.
	 * @param pContext Unused, should be null.
	 * @return The child node.
	 */
	virtual cEntry* AddChildEntry(cIGZUnknown* key, const char* name, cEntry* parentNode, eEntryFlags flags = EntryFlagNone, void* pContext = nullptr) = 0;

	/**
	 * @brief Adds a function that the LUA code can call.
	 * @param key A unique key that identifies the callback method, usually its memory address.
	 * @param name The function name.
	 * @param pCallback The callback that is executed when the LUA code calls the method.
	 * @param parentNode The parent node.
	 * @param flags Unknown. SC4 normally uses eEntryFlags::EntryFlagNone.
	 * @param pContext The context that is passed to the callback.
	 * @return The child node.
	 */
	virtual cEntry* AddChildEntry(void* key, const char* name, AddChildEntryCallback1 pCallback, cEntry* parentNode, eEntryFlags flags, void* pContext) = 0;

	/**
	 * @brief Adds a function that the LUA code can call.
	 * @param key A unique key that identifies the callback method, usually its memory address.
	 * @param name The function name.
	 * @param pCallback The callback that is executed when the LUA code calls the method.
	 * @param parentNode The parent node.
	 * @param flags Unknown. SC4 normally uses eEntryFlags::EntryFlagNone.
	 * @param pContext The context that is passed to the callback.
	 * @return The child node.
	 */
	virtual cEntry* AddChildEntry(void* key, const char* name, AddChildEntryCallback2 pCallback, cEntry* parentNode, eEntryFlags flags, void* pContext) = 0;

	virtual bool RemoveChildEntry(cIGZUnknown* key) = 0;
	virtual bool RemoveChildEntry(void* key) = 0;

	virtual cEntry* GetEntryID(cIGZUnknown* key) const = 0;
	virtual cEntry* GetEntryID(void* key) const = 0;

	virtual cEntry* GetNode(cEntry* entry) const = 0;
	virtual void* GetValue(cEntry* entry) const = 0;

	virtual bool IsValidEntry(cEntry* entry) const = 0;
	virtual bool IsNodeEntry(cEntry* entry) const = 0;

	virtual cIGZString* GetEntryName(cEntry* entry) const = 0;

	virtual bool DoValueExchange(cEntry* entry, cIGZVariant& variant, bool set) = 0;
	virtual bool DoValueCall(cEntry* entry, cIGZCommandParameterSet* input, cIGZCommandParameterSet* output) = 0;

	virtual bool SetEntryContext(cEntry* entry, void* pContext) = 0;
	virtual void* GetEntryContext(cEntry* entry) const = 0;

	virtual bool CheckEntryFlags(cEntry* entry, eEntryFlags flags) const = 0;
	virtual cEntry* GetParentNodeEntry(cEntry* entry) const = 0;
	virtual cEntry* GetRootNodeEntry() const = 0;

	typedef bool(*VisitEntryCallback)(cEntry*, void*);

	virtual bool VisitBreadthFirst(cEntry* entry, VisitEntryCallback pCallback, void* pContext) = 0;
	virtual bool VisitImmediateChildren(cEntry* entry, VisitEntryCallback pCallback, void* pContext) = 0;

	virtual bool AddNotificationTarget(cISC4GameDataRegistryNotificationTarget* pTarget) = 0;
	virtual bool AddNotificationTarget(cIGZMessageTarget2* pTarget) = 0;

	virtual bool RemoveNotificationTarget(cISC4GameDataRegistryNotificationTarget* pTarget) = 0;
	virtual bool RemoveNotificationTarget(cIGZMessageTarget2* pTarget) = 0;

	virtual void DebugDumpRecursive(cEntry* entry) = 0;
};