#pragma once
#include "cIGZUnknown.h"

class cIGZLua5;

typedef struct lua_State lua_State;
typedef int32_t(*lua_CFunction)(lua_State*);

static const uint32_t GZIID_cIGZLua5Thread = 0xEB2810F1;

class cIGZLua5Thread : public cIGZUnknown
{
public:
	enum LuaType : int32_t
	{
		LuaTypeNone = -1,
		LuaTypeNil = 0,
		LuaTypeBoolean = 1,
		LuaTypeLightUserData = 2,
		LuaTypeNumber = 3,
		LuaTypeString = 4,
		LuaTypeTable = 5,
		LuaTypeFunction = 6,
		LuaTypeUserData = 7,
		LuaTypeThread = 8
	};

	virtual cIGZLua5* GetLua() = 0;

	virtual lua_State* GetContext() = 0;
	virtual void* GetUserContext() const = 0;
	virtual void SetUserContext(void*) = 0;

	virtual bool OnCreate(cIGZLua5*, lua_State*, int32_t) = 0;
	virtual bool OnDestroy() = 0;

	virtual int32_t Pause(int32_t) = 0;
	virtual int32_t GetID() = 0;
	virtual bool IsValid() = 0;
	virtual bool Destroy() = 0;
	virtual int32_t Status() = 0;

	virtual int32_t GetTop() = 0;
	virtual void SetTop(int32_t) = 0;

	virtual void PushValue(int32_t) = 0;
	virtual void Remove(int32_t) = 0;
	virtual void Insert(int32_t) = 0;
	virtual void Pop(int32_t) = 0;
	virtual void Replace(int32_t) = 0;
	virtual void Move(lua_State*, int32_t) = 0;
	virtual bool GrowStack(int32_t) = 0;

	virtual LuaType Type(int32_t) = 0;
	virtual const char* TypeName(int32_t) = 0;

	virtual bool IsNumber(int32_t) = 0;
	virtual bool IsString(int32_t) = 0;
	virtual bool IsCFunction(int32_t) = 0;
	virtual bool IsFunction(int32_t) = 0;
	virtual bool IsTable(int32_t) = 0;
	virtual bool IsUserData(int32_t) = 0;
	virtual bool IsLightUserData(int32_t) = 0;
	virtual bool IsBoolean(int32_t) = 0;
	virtual bool IsNil(int32_t) = 0;
	virtual bool IsNone(int32_t) = 0;
	virtual bool IsNoneOrNil(int32_t) = 0;

	virtual bool Equal(int32_t, int32_t) = 0;
	virtual bool RawEqual(int32_t, int32_t) = 0;
	virtual bool LessThan(int32_t, int32_t) = 0;

	virtual uint32_t ToUint32(int32_t) = 0;
	virtual int32_t ToSint32(int32_t) = 0;
	virtual double ToNumber(int32_t) = 0;
	virtual bool ToBoolean(int32_t) = 0;
	virtual const char* ToString(int32_t) = 0;
	virtual size_t Strlen(int32_t) = 0;
	virtual lua_CFunction ToCFunction(int32_t) = 0;
	virtual void* ToUserData(int32_t) = 0;
	virtual cIGZLua5Thread* ToThread(int32_t) = 0;

	virtual void PushNil() = 0;
	virtual void PushNumber(double) = 0;
	virtual void PushLString(char const*, int32_t) = 0;
	virtual void PushString(char const*) = 0;
	virtual void PushCClosure(lua_CFunction*, int32_t) = 0;
	virtual void PushBoolean(bool) = 0;
	virtual void PushLightUserData(void*) = 0;
	virtual void PushNewUserData(int32_t) = 0;
	virtual void PushNewTable() = 0;

	virtual void GetTable(int32_t) = 0;
	virtual void RawGet(int32_t) = 0;
	virtual void RawGetI(int32_t, int32_t) = 0;
	virtual void GetFunctionEnvironment(int32_t) = 0;

	virtual int32_t GetMetaTable(int32_t) = 0;
	virtual void GetRegistryTable() = 0;
	virtual void GetGlobalTable() = 0;

	virtual void SetTable(int32_t) = 0;
	virtual void RawSet(int32_t) = 0;
	virtual void RawSetI(int32_t, int32_t) = 0;
	virtual int32_t SetFunctionEnvironment(int32_t) = 0;
	virtual int32_t SetMetaTable(int32_t) = 0;

	virtual void Call(int32_t, int32_t) = 0;
	virtual void CallProtected(int32_t, int32_t, int32_t, bool) = 0;

	virtual void DoFile(char const*) = 0;
	virtual void DoString(char const*) = 0;
	virtual void DoBuffer(char const*, int32_t, char const*) = 0;
	virtual void Load(char const* (*)(lua_State*, void*, uint32_t*), void*, char const*) = 0;
	virtual int32_t LoadFile(char const*) = 0;
	virtual int32_t LoadStringA(char const*) = 0;
	virtual int32_t LoadBuffer(char const*, int32_t, char const*) = 0;

	virtual void Error(char const*) = 0;
	virtual void Next(int32_t) = 0;
	virtual void Concat(int32_t) = 0;

	virtual void Register(lua_CFunction, char const*) = 0;
	virtual int32_t GetUpValueIndex(int32_t) = 0;

	virtual int32_t Ref() = 0;
	virtual void GetRef(int32_t) = 0;
	virtual void Unref(int32_t) = 0;

	virtual void SetGlobal(char const*) = 0;
	virtual void GetGlobal(char const*) = 0;

	virtual int32_t Tag(int32_t) = 0;
	virtual void GetTagMethod(int32_t, char const*) = 0;
	virtual void SetTagMethod(int32_t, char const*) = 0;
	virtual int32_t NewTag() = 0;
	virtual void SetTag(int32_t) = 0;
	virtual int32_t CopyTagMethods(int32_t, int32_t) = 0;
	virtual void CloneTag(int32_t) = 0;

	virtual void PushUserTag(void*, int32_t) = 0;
	virtual void* ToUserTag(int32_t) = 0;
};