#pragma once
#include "cIGZUnknown.h"
#include "cIGZLua5.h"
#include "cIGZLua5Thread.h"
#include "cISC4GameDataRegistry.h"

static constexpr uint32_t GZCLSID_cISCLua = 0xEA10C4A2;
static constexpr uint32_t GZIID_cISCLua = 0xEA10C4A2;

class cISCLua : public cIGZUnknown
{
public:
	virtual bool Open(cIGZLua5::OpenFlags) = 0;
	virtual void Close() = 0;
	virtual cIGZLua5* AsIGZLua5() = 0;

	virtual int32_t GetTop() = 0;
	virtual void SetTop(int32_t) = 0;

	virtual void PushValue(int32_t) = 0;
	virtual void Remove(int32_t) = 0;
	virtual void Insert(int32_t) = 0;
	virtual void Pop(int32_t) = 0;

	virtual cIGZLua5Thread::LuaType Type(int32_t) = 0;
	virtual const char* TypeName(cIGZLua5Thread::LuaType) = 0;

	virtual bool IsNumber(int32_t) = 0;
	virtual bool IsString(int32_t) = 0;
	virtual bool IsCFunction(int32_t) = 0;

	virtual int32_t Tag(int32_t) = 0;
	virtual bool IsBoolean(int32_t) = 0;
	virtual bool Equal(int32_t, int32_t) = 0;
	virtual bool LessThan(int32_t, int32_t) = 0;

	virtual uint32_t ToUint32(int32_t) = 0;
	virtual int32_t ToSint32(int32_t) = 0;
	virtual double ToNumber(int32_t) = 0;
	virtual const char* ToString(int32_t) = 0;
	virtual size_t Strlen(int32_t) = 0;
	virtual lua_CFunction ToCFunction(int32_t) = 0;
	virtual void* ToUserData(int32_t) = 0;
	virtual int32_t ToUserTag(int32_t) = 0;
	virtual bool ToBoolean(int32_t) = 0;

	virtual void PushNil() = 0;
	virtual void PushNumber(double) = 0;
	virtual void PushLString(char const*, size_t) = 0;
	virtual void PushString(char const*) = 0;
	virtual void PushCClosure(lua_CFunction fn, int32_t nargs) = 0;
	virtual void PushUserTag(void*, int32_t) = 0;
	virtual void PushBoolean(bool) = 0;

	virtual void GetGlobal(char const*) = 0;
	virtual void GetTable(int32_t) = 0;
	virtual void RawGet(int32_t) = 0;
	virtual void RawGetI(int32_t, int32_t) = 0;
	virtual void GetGlobals() = 0;
	virtual void GetTagMethod(int32_t, char const*) = 0;
	virtual void GetRef(int32_t) = 0;

	virtual int32_t NewTable() = 0;
	virtual void SetGlobal(char const*) = 0;
	virtual void SetTable(int32_t) = 0;

	virtual void RawSet(int32_t) = 0;
	virtual void RawSetI(int32_t, int32_t) = 0;
	virtual void SetTagMethod(int32_t, char const*) = 0;
	virtual int32_t Ref(int32_t) = 0;

	virtual void CallProtected(int32_t nargs, int32_t nresults) = 0;
	virtual void RawCall(int32_t nargs, int32_t nresults) = 0;
	virtual void DoFile(char const*) = 0;
	virtual void DoString(char const*) = 0;
	virtual void DoBuffer(char const*, int32_t, char const*) = 0;

	virtual int32_t GetGCCount() = 0;
	virtual int32_t GetGCThreshold() = 0;
	virtual void SetGCThreshold(int32_t) = 0;

	virtual int32_t NewTag() = 0;
	virtual int32_t CopyTagMethods(int32_t, int32_t) = 0;
	virtual void SetTag(int32_t) = 0;

	virtual void Unref(int32_t) = 0;
	virtual int32_t Next(int32_t) = 0;
	virtual int32_t GetN(int32_t) = 0;
	virtual void Error(char const*) = 0;
	virtual void Concat(int32_t) = 0;

	virtual void* NewUserData(size_t) = 0;
	virtual void Register(lua_CFunction, char const*) = 0;
	virtual void PushUserData(void*, int32_t) = 0;
	virtual void CloneTag(int32_t) = 0;

	virtual bool IsFunction(int32_t) = 0;
	virtual bool IsTable(int32_t) = 0;
	virtual bool IsUserData(int32_t) = 0;
	virtual bool IsNil(int32_t) = 0;

	virtual uint32_t ToDataRegistryEntryID(cISC4GameDataRegistry*, int32_t) = 0;
	virtual cISC4GameDataRegistry::cEntry* ToDataRegistryNode(cISC4GameDataRegistry*, int32_t) = 0;
	virtual cISC4GameDataRegistry::cEntry* ToDataRegistryValue(cISC4GameDataRegistry*, int32_t) = 0;
};
