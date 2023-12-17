#include "cRZBaseVariant.h"
#include <cstdint>
#include <string>

static const uint32_t GZIID_cRZBaseVariant = 0x48122352;

cRZBaseVariant::cRZBaseVariant()
	: type(cIGZVariant::Type::Empty),
	  count(0),
	  numericTypes(),
	  voidPtr(nullptr),
	  gzUnknown(nullptr),
	  refCount(0)
{
}

cRZBaseVariant::cRZBaseVariant(int32_t value)
	: type(cIGZVariant::Type::Sint32),
	  count(0),
	  numericTypes(value),
	  voidPtr(nullptr),
	  gzUnknown(nullptr),
	  refCount(0)
{
}

cRZBaseVariant::cRZBaseVariant(uint32_t value)
	: type(cIGZVariant::Type::Uint32),
	  count(0),
	  numericTypes(value),
	  voidPtr(nullptr),
	  gzUnknown(nullptr),
	  refCount(0)
{
}

cRZBaseVariant::cRZBaseVariant(float value)
	: type(cIGZVariant::Type::Float32),
	  count(0),
	  numericTypes(value),
	  voidPtr(nullptr),
	  gzUnknown(nullptr),
	  refCount(0)
{
}

cRZBaseVariant::cRZBaseVariant(const cIGZVariant& other)
	: type(static_cast<cIGZVariant::Type>(other.GetType())),
	  count(other.GetCount()),
	  numericTypes(),
	  voidPtr(nullptr),
	  gzUnknown(nullptr),
	  refCount(0)
{
	CopyDataFrom(other);
}

cRZBaseVariant::cRZBaseVariant(const cIGZVariant* other)
	: type(cIGZVariant::Type::Empty),
	  count(0),
	  numericTypes(),
	  voidPtr(nullptr),
	  gzUnknown(nullptr),
	  refCount(0)
{
	if (other)
	{
		CopyDataFrom(*other);
	}
}


cRZBaseVariant::cRZBaseVariant(const cRZBaseVariant& other)
	: type(other.type),
	  count(other.count),
	  numericTypes(),
	  voidPtr(nullptr),
	  gzUnknown(nullptr),
	  refCount(0)
{
	CopyDataFrom(other);
}

cRZBaseVariant::cRZBaseVariant(cRZBaseVariant&& other) noexcept
	: type(other.type),
	  count(other.count),
	  numericTypes(std::move(other.numericTypes)),
	  voidPtr(other.voidPtr),
	  gzUnknown(other.gzUnknown),
	  refCount(other.refCount)
{
	other.type = cIGZVariant::Type::Empty;
	other.count = 0;
	other.voidPtr = nullptr;
	other.gzUnknown = nullptr;
	other.refCount = 0;
}

cRZBaseVariant::~cRZBaseVariant()
{
	Clear();
}

cRZBaseVariant& cRZBaseVariant::operator=(const cRZBaseVariant& other)
{
	if (this == &other)
	{
		return *this;
	}

	CopyFrom(other);

	return *this;
}

cRZBaseVariant& cRZBaseVariant::operator=(cRZBaseVariant&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	type = other.type;
	count = other.count;
	numericTypes = std::move(other.numericTypes);
	voidPtr = other.voidPtr;
	gzUnknown = other.gzUnknown;
	refCount = other.refCount;

	other.type = cIGZVariant::Type::Empty;
	other.count = 0;
	other.voidPtr = nullptr;
	other.gzUnknown = nullptr;
	other.refCount = 0;

	return *this;
}

bool cRZBaseVariant::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cRZBaseVariant)
	{
		AddRef();
		*ppvObj = this;

		return true;
	}
	else if (riid == GZIID_cIGZVariant)
	{
		AddRef();
		*ppvObj = static_cast<cIGZVariant*>(this);

		return true;
	}
	else if (riid == GZIID_cIGZUnknown)
	{
		AddRef();
		*ppvObj = static_cast<cIGZUnknown*>(this);

		return true;
	}

	return false;
}

uint32_t cRZBaseVariant::AddRef()
{
	return ++refCount;
}

uint32_t cRZBaseVariant::Release()
{
	if (refCount > 0)
	{
		--refCount;
	}

	return refCount;
}

uint16_t cRZBaseVariant::GetType() const
{
	return static_cast<uint16_t>(type);
}

uint32_t cRZBaseVariant::GetCount() const
{
	return count;
}

bool cRZBaseVariant::Erase()
{
	Clear();
	return true;
}

bool cRZBaseVariant::CopyFrom(cIGZVariant const& value)
{
	if (type != cIGZVariant::Type::Empty)
	{
		Clear();
	}

	CopyDataFrom(value);

	return true;
}

bool cRZBaseVariant::CreateCopy(cIGZVariant** value) const
{
	*value = new cRZBaseVariant(*this);

	return true;
}

bool cRZBaseVariant::CanGetVal() const
{
	return type != cIGZVariant::Type::Empty;
}

bool cRZBaseVariant::GetValBool(bool& value) const
{
	if (type == cIGZVariant::Type::Bool)
	{
		value = std::get<bool>(numericTypes);
		return true;
	}

	return false;
}

bool cRZBaseVariant::GetValBool() const
{
	return type == cIGZVariant::Type::Bool ? std::get<bool>(numericTypes) : false;
}

void cRZBaseVariant::SetValBool(bool value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValUint8(uint8_t& value) const
{
	if (type == cIGZVariant::Type::Uint8)
	{
		value = std::get<uint8_t>(numericTypes);
		return true;
	}

	return false;
}

uint8_t cRZBaseVariant::GetValUint8() const
{
	return type == cIGZVariant::Type::Uint8 ? std::get<uint8_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValUint8(uint8_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValSint8(int8_t& value) const
{
	if (type == cIGZVariant::Type::Sint8)
	{
		value = std::get<int8_t>(numericTypes);
		return true;
	}

	return false;
}

int8_t cRZBaseVariant::GetValSint8() const
{
	return type == cIGZVariant::Type::Sint8 ? std::get<int8_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValSint8(int8_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValUint16(uint16_t& value) const
{
	if (type == cIGZVariant::Type::Uint16)
	{
		value = std::get<uint16_t>(numericTypes);
		return true;
	}

	return false;
}

uint16_t cRZBaseVariant::GetValUint16() const
{
	return type == cIGZVariant::Type::Uint16 ? std::get<uint16_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValUint16(uint16_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValSint16(int16_t& value) const
{
	if (type == cIGZVariant::Type::Sint16)
	{
		value = std::get<int16_t>(numericTypes);
		return true;
	}

	return false;
}

int16_t cRZBaseVariant::GetValSint16() const
{
	return type == cIGZVariant::Type::Sint16 ? std::get<int16_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValSint16(int16_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValUint32(uint32_t& value) const
{
	if (type == cIGZVariant::Type::Uint32)
	{
		value = std::get<uint32_t>(numericTypes);
		return true;
	}

	return false;
}

uint32_t cRZBaseVariant::GetValUint32() const
{
	return type == cIGZVariant::Type::Uint32 ? std::get<uint32_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValUint32(uint32_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValSint32(int32_t& value) const
{
	if (type == cIGZVariant::Type::Sint16)
	{
		value = std::get<int32_t>(numericTypes);
		return true;
	}

	return false;
}

int32_t cRZBaseVariant::GetValSint32() const
{
	return type == cIGZVariant::Type::Sint32 ? std::get<int32_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValSint32(int32_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValUint64(uint64_t& value) const
{
	if (type == cIGZVariant::Type::Uint64)
	{
		value = std::get<uint64_t>(numericTypes);
		return true;
	}

	return false;
}

uint64_t cRZBaseVariant::GetValUint64() const
{
	return type == cIGZVariant::Type::Uint64 ? std::get<uint64_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValUint64(uint64_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValSint64(int64_t& value) const
{
	if (type == cIGZVariant::Type::Sint64)
	{
		value = std::get<int64_t>(numericTypes);
		return true;
	}

	return false;
}

int64_t cRZBaseVariant::GetValSint64() const
{
	return type == cIGZVariant::Type::Sint64 ? std::get<int64_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValSint64(int64_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValFloat32(float& value) const
{
	if (type == cIGZVariant::Type::Float32)
	{
		value = std::get<float>(numericTypes);
		return true;
	}

	return false;
}

float cRZBaseVariant::GetValFloat32() const
{
	return type == cIGZVariant::Type::Float32 ? std::get<float>(numericTypes) : 0;
}

void cRZBaseVariant::SetValFloat32(float value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValFloat64(double& value) const
{
	if (type == cIGZVariant::Type::Float64)
	{
		value = std::get<double>(numericTypes);
		return true;
	}

	return false;
}

double cRZBaseVariant::GetValFloat64() const
{
	return type == cIGZVariant::Type::Float64 ? std::get<double>(numericTypes) : 0;
}

void cRZBaseVariant::SetValFloat64(double value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValChar(char& value) const
{
	if (type == cIGZVariant::Type::Char)
	{
		value = std::get<char>(numericTypes);
		return true;
	}

	return false;
}

char cRZBaseVariant::GetValChar() const
{
	return type == cIGZVariant::Type::Char ? std::get<char>(numericTypes) : 0;
}

void cRZBaseVariant::SetValChar(char value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValRZUnicodeChar(uint16_t& value) const
{
	if (type == cIGZVariant::Type::RZUnicodeChar)
	{
		value = std::get<uint16_t>(numericTypes);
		return true;
	}

	return false;
}

uint16_t cRZBaseVariant::GetValRZUnicodeChar() const
{
	return type == cIGZVariant::Type::RZUnicodeChar ? std::get<uint16_t>(numericTypes) : 0;
}

void cRZBaseVariant::SetValRZUnicodeChar(uint16_t value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValRZChar(char& value) const
{
	if (type == cIGZVariant::Type::RZChar)
	{
		value = std::get<char>(numericTypes);
		return true;
	}

	return false;
}

char cRZBaseVariant::GetValRZChar() const
{
	return type == cIGZVariant::Type::RZChar ? std::get<char>(numericTypes) : 0;
}

void cRZBaseVariant::SetValRZChar(char value)
{
	SetValue(value);
}

bool cRZBaseVariant::GetValVoidPtr(void** value) const
{
	if (type == cIGZVariant::Type::VoidPtr)
	{
		*value = voidPtr;
		return true;
	}

	return false;
}

void* cRZBaseVariant::GetValVoidPtr() const
{
	return voidPtr;
}

void cRZBaseVariant::SetValVoidPtr(void* value)
{
	SetValue(value);
}

bool cRZBaseVariant::CreateValString(cIGZString** value) const
{
	return false;
}

void cRZBaseVariant::GetValString(cIGZString* value) const
{
}

void cRZBaseVariant::SetValString(cIGZString* value)
{
}

bool cRZBaseVariant::GetValVoid(void* value, uint32_t& length) const
{
	return false;
}

void cRZBaseVariant::SetValVoid(void* value, uint32_t length)
{
}

bool cRZBaseVariant::GetValUnknown(cIGZUnknown** outValue)
{
	if (type == cIGZVariant::Type::GZUnknown)
	{
		if (gzUnknown)
		{
			gzUnknown->AddRef();
		}
		*outValue = gzUnknown;
		return true;
	}

	return false;
}

cIGZUnknown* cRZBaseVariant::GetValUnknown()
{
	if (gzUnknown)
	{
		gzUnknown->AddRef();
	}
	return gzUnknown;
}

void cRZBaseVariant::SetValUnknown(cIGZUnknown* value)
{
	SetValue(value);
}

bool cRZBaseVariant::AsBool()
{
	return type == cIGZVariant::Type::Bool ? std::get<bool>(numericTypes) : false;
}

bool cRZBaseVariant::AsBool() const
{
	return type == cIGZVariant::Type::Bool ? std::get<bool>(numericTypes) : false;
}

uint8_t cRZBaseVariant::AsUint8()
{
	return type == cIGZVariant::Type::Uint8 ? std::get<uint8_t>(numericTypes) : 0;
}

uint8_t cRZBaseVariant::AsUint8() const
{
	return type == cIGZVariant::Type::Uint8 ? std::get<uint8_t>(numericTypes) : 0;
}

int8_t cRZBaseVariant::AsSint8()
{
	return type == cIGZVariant::Type::Sint8 ? std::get<int8_t>(numericTypes) : 0;
}

int8_t cRZBaseVariant::AsSint8() const
{
	return type == cIGZVariant::Type::Sint8 ? std::get<int8_t>(numericTypes) : 0;
}

uint16_t cRZBaseVariant::AsUint16()
{
	return type == cIGZVariant::Type::Uint16 ? std::get<uint16_t>(numericTypes) : 0;
}

uint16_t cRZBaseVariant::AsUint16() const
{
	return type == cIGZVariant::Type::Uint16 ? std::get<uint16_t>(numericTypes) : 0;
}

int16_t cRZBaseVariant::AsSint16()
{
	return type == cIGZVariant::Type::Sint16 ? std::get<int16_t>(numericTypes) : 0;
}

int16_t cRZBaseVariant::AsSint16() const
{
	return type == cIGZVariant::Type::Sint16 ? std::get<int16_t>(numericTypes) : 0;
}

uint32_t cRZBaseVariant::AsUint32()
{
	return type == cIGZVariant::Type::Uint32 ? std::get<uint32_t>(numericTypes) : 0;
}

uint32_t cRZBaseVariant::AsUint32() const
{
	return type == cIGZVariant::Type::Uint32 ? std::get<uint32_t>(numericTypes) : 0;
}

int32_t cRZBaseVariant::AsSint32()
{
	return type == cIGZVariant::Type::Sint32 ? std::get<int32_t>(numericTypes) : 0;
}

int32_t cRZBaseVariant::AsSint32() const
{
	return type == cIGZVariant::Type::Sint32 ? std::get<int32_t>(numericTypes) : 0;
}

uint64_t cRZBaseVariant::AsUint64()
{
	return type == cIGZVariant::Type::Uint64 ? std::get<uint64_t>(numericTypes) : 0;
}

uint64_t cRZBaseVariant::AsUint64() const
{
	return type == cIGZVariant::Type::Uint64 ? std::get<uint64_t>(numericTypes) : 0;
}

int64_t cRZBaseVariant::AsSint64()
{
	return type == cIGZVariant::Type::Sint64 ? std::get<int64_t>(numericTypes) : 0;
}

int64_t cRZBaseVariant::AsSint64() const
{
	return type == cIGZVariant::Type::Sint64 ? std::get<int64_t>(numericTypes) : 0;
}

float cRZBaseVariant::AsFloat32()
{
	return type == cIGZVariant::Type::Float32 ? std::get<float>(numericTypes) : 0;
}

float cRZBaseVariant::AsFloat32() const
{
	return type == cIGZVariant::Type::Float32 ? std::get<float>(numericTypes) : 0;
}

double cRZBaseVariant::AsFloat64()
{
	return type == cIGZVariant::Type::Float64 ? std::get<double>(numericTypes) : 0;
}

double cRZBaseVariant::AsFloat64() const
{
	return type == cIGZVariant::Type::Float64 ? std::get<double>(numericTypes) : 0;
}

char cRZBaseVariant::AsChar()
{
	return type == cIGZVariant::Type::Char ? std::get<char>(numericTypes) : 0;
}

char cRZBaseVariant::AsChar() const
{
	return type == cIGZVariant::Type::Char ? std::get<char>(numericTypes) : 0;
}

uint16_t cRZBaseVariant::AsRZUnicodeChar()
{
	return type == cIGZVariant::Type::RZUnicodeChar ? std::get<uint16_t>(numericTypes) : 0;
}

uint16_t cRZBaseVariant::AsRZUnicodeChar() const
{
	return type == cIGZVariant::Type::RZUnicodeChar ? std::get<uint16_t>(numericTypes) : 0;
}

char cRZBaseVariant::AsRZChar()
{
	return type == cIGZVariant::Type::RZChar ? std::get<char>(numericTypes) : 0;
}

char cRZBaseVariant::AsRZChar() const
{
	return type == cIGZVariant::Type::RZChar ? std::get<char>(numericTypes) : 0;
}

void** cRZBaseVariant::AsVoidPtr()
{
	return reinterpret_cast<void**>(voidPtr);
}

void** cRZBaseVariant::AsVoidPtr() const
{
	return reinterpret_cast<void**>(voidPtr);
}

bool* cRZBaseVariant::RefBool() const
{
	return static_cast<bool*>(voidPtr);
}

void cRZBaseVariant::RefBool(bool* value, uint32_t length)
{
	if (type == cIGZVariant::Type::BoolArray && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(bool));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::BoolArray;
		count = length;

		const size_t dataLength = static_cast<size_t>(length) * sizeof(bool);

		if (value && length > 0)
		{
			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

uint8_t* cRZBaseVariant::RefUint8() const
{
	return static_cast<uint8_t*>(voidPtr);
}

void cRZBaseVariant::RefUint8(uint8_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Uint8Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(uint8_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Uint8Array;
		count = length;

		const size_t dataLength = static_cast<size_t>(length) * sizeof(uint8_t);

		if (value && length > 0)
		{
			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

int8_t* cRZBaseVariant::RefSint8() const
{
	return static_cast<int8_t*>(voidPtr);
}

void cRZBaseVariant::RefSint8(int8_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Sint8Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(int8_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Sint8Array;
		count = length;

		const size_t dataLength = static_cast<size_t>(length) * sizeof(int8_t);

		if (value && length > 0)
		{
			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

uint16_t* cRZBaseVariant::RefUint16() const
{
	return static_cast<uint16_t*>(voidPtr);
}

void cRZBaseVariant::RefUint16(uint16_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Uint16Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(uint16_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Uint16Array;
		count = length;

		const size_t dataLength = static_cast<size_t>(length) * sizeof(uint16_t);

		if (value && length > 0)
		{
			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

int16_t* cRZBaseVariant::RefSint16() const
{
	return static_cast<int16_t*>(voidPtr);
}

void cRZBaseVariant::RefSint16(int16_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Sint16Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(int16_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Sint16Array;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(int16_t);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

uint32_t* cRZBaseVariant::RefUint32() const
{
	return static_cast<uint32_t*>(voidPtr);
}

void cRZBaseVariant::RefUint32(uint32_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Uint32Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(uint32_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Uint32Array;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(uint32_t);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

int32_t* cRZBaseVariant::RefSint32() const
{
	return static_cast<int32_t*>(voidPtr);
}

void cRZBaseVariant::RefSint32(int32_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Sint32Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(int32_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Sint32Array;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(int32_t);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

uint64_t* cRZBaseVariant::RefUint64() const
{
	return static_cast<uint64_t*>(voidPtr);
}

void cRZBaseVariant::RefUint64(uint64_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Uint64Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(uint64_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Uint64Array;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(uint64_t);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

int64_t* cRZBaseVariant::RefSint64() const
{
	return static_cast<int64_t*>(voidPtr);
}

void cRZBaseVariant::RefSint64(int64_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Sint64Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(int64_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Sint64Array;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(int64_t);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

float* cRZBaseVariant::RefFloat32() const
{
	return static_cast<float*>(voidPtr);
}

void cRZBaseVariant::RefFloat32(float* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Float32Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(float));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Float32Array;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(float);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

double* cRZBaseVariant::RefFloat64() const
{
	return static_cast<double*>(voidPtr);
}

void cRZBaseVariant::RefFloat64(double* value, uint32_t length)
{
	if (type == cIGZVariant::Type::Float64Array && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(double));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::Float64Array;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(double);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

char* cRZBaseVariant::RefChar() const
{
	return static_cast<char*>(voidPtr);
}

void cRZBaseVariant::RefChar(char* value, uint32_t length)
{
	if (type == cIGZVariant::Type::CharArray && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(char));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::CharArray;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(char);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

uint16_t* cRZBaseVariant::RefRZUnicodeChar() const
{
	return static_cast<uint16_t*>(voidPtr);
}

void cRZBaseVariant::RefRZUnicodeChar(uint16_t* value, uint32_t length)
{
	if (type == cIGZVariant::Type::RZUnicodeCharArray && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(uint16_t));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::RZUnicodeCharArray;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(uint16_t);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

char* cRZBaseVariant::RefRZChar() const
{
	return static_cast<char*>(voidPtr);
}

void cRZBaseVariant::RefRZChar(char* value, uint32_t length)
{
	if (type == cIGZVariant::Type::RZCharArray && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(char));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::RZCharArray;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(char);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

void** cRZBaseVariant::RefVoidPtr() const
{
	return reinterpret_cast<void**>(voidPtr);
}

void cRZBaseVariant::RefVoidPtr(void** value, uint32_t length)
{
	if (type == cIGZVariant::Type::VoidPtrArray && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length * sizeof(void*));
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::VoidPtrArray;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length) * sizeof(void*);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

void* cRZBaseVariant::RefVoid() const
{
	return voidPtr;
}

void cRZBaseVariant::RefVoid(void* value, uint32_t length)
{
	if (type == cIGZVariant::Type::VoidArray && count == length && value && voidPtr)
	{
		memcpy(voidPtr, value, length);
	}
	else
	{
		Clear();

		type = cIGZVariant::Type::VoidArray;
		count = length;

		if (value && length > 0)
		{
			const size_t dataLength = static_cast<size_t>(length);

			voidPtr = operator new[](dataLength);
			memcpy(voidPtr, value, dataLength);
		}
	}
}

cIGZUnknown* cRZBaseVariant::RefIGZUnknown() const
{
	return gzUnknown;
}

void cRZBaseVariant::RefIGZUnknown(cIGZUnknown** value)
{
	*value = gzUnknown;
}

void cRZBaseVariant::RefIGZUnknown(cIGZUnknown* value)
{
	SetType(cIGZVariant::Type::GZUnknown);

	if (value)
	{
		value->AddRef();
	}

	gzUnknown = value;
}

void cRZBaseVariant::Clear()
{
	if (IsArrayType())
	{
		if (voidPtr)
		{
			operator delete[](voidPtr);
			voidPtr = nullptr;
		}
	}
	else
	{
		if (gzUnknown)
		{
			gzUnknown->Release();
		}
		gzUnknown = nullptr;
		voidPtr = nullptr;
	}

	count = 0;
	type = cIGZVariant::Type::Empty;
}

void cRZBaseVariant::CopyDataFrom(cIGZVariant const& other)
{
	switch (static_cast<cIGZVariant::Type>(other.GetType()))
	{
	case cIGZVariant::Type::Empty:
		break;
	case cIGZVariant::Type::Bool:
		SetValBool(other.GetValBool());
		break;
	case cIGZVariant::Type::Uint8:
		SetValUint8(other.GetValUint8());
		break;
	case cIGZVariant::Type::Sint8:
		SetValSint8(other.GetValSint8());
		break;
	case cIGZVariant::Type::Uint16:
		SetValUint16(other.GetValUint16());
		break;
	case cIGZVariant::Type::Sint16:
		SetValSint16(other.GetValSint16());
		break;
	case cIGZVariant::Type::Uint32:
		SetValUint32(other.GetValUint32());
		break;
	case cIGZVariant::Type::Sint32:
		SetValSint32(other.GetValSint32());
		break;
	case cIGZVariant::Type::Uint64:
		SetValUint64(other.GetValUint64());
		break;
	case cIGZVariant::Type::Sint64:
		SetValSint64(other.GetValSint64());
		break;
	case cIGZVariant::Type::Float32:
		SetValFloat32(other.GetValFloat32());
		break;
	case cIGZVariant::Type::Float64:
		SetValFloat64(other.GetValFloat64());
		break;
	case cIGZVariant::Type::Char:
		SetValChar(other.GetValChar());
		break;
	case cIGZVariant::Type::RZUnicodeChar:
		SetValRZUnicodeChar(other.GetValRZUnicodeChar());
		break;
	case cIGZVariant::Type::RZChar:
		SetValRZChar(other.GetValRZChar());
		break;
	case cIGZVariant::Type::VoidPtr:
		SetValVoidPtr(other.GetValVoidPtr());
		break;
	case cIGZVariant::Type::GZUnknown:
		SetValUnknown(other.RefIGZUnknown());
		break;
	case cIGZVariant::Type::VoidArray:
		RefVoid(other.RefVoid(), other.GetCount());
		break;
	case cIGZVariant::Type::BoolArray:
		RefBool(other.RefBool(), other.GetCount());
		break;
	case cIGZVariant::Type::Uint8Array:
		RefUint8(other.RefUint8(), other.GetCount());
		break;
	case cIGZVariant::Type::Sint8Array:
		RefSint8(other.RefSint8(), other.GetCount());
		break;
	case cIGZVariant::Type::Uint16Array:
		RefUint16(other.RefUint16(), other.GetCount());
		break;
	case cIGZVariant::Type::Sint16Array:
		RefSint16(other.RefSint16(), other.GetCount());
		break;
	case cIGZVariant::Type::Uint32Array:
		RefUint32(other.RefUint32(), other.GetCount());
		break;
	case cIGZVariant::Type::Sint32Array:
		RefSint32(other.RefSint32(), other.GetCount());
		break;
	case cIGZVariant::Type::Uint64Array:
		RefUint64(other.RefUint64(), other.GetCount());
		break;
	case cIGZVariant::Type::Sint64Array:
		RefSint64(other.RefSint64(), other.GetCount());
		break;
	case cIGZVariant::Type::Float32Array:
		RefFloat32(other.RefFloat32(), other.GetCount());
		break;
	case cIGZVariant::Type::Float64Array:
		RefFloat64(other.RefFloat64(), other.GetCount());
		break;
	case cRZBaseVariant::cIGZVariant::Type::CharArray:
		RefChar(other.RefChar(), other.GetCount());
		break;
	case cRZBaseVariant::cIGZVariant::Type::RZUnicodeCharArray:
		RefRZUnicodeChar(other.RefRZUnicodeChar(), other.GetCount());
		break;
	case cRZBaseVariant::cIGZVariant::Type::RZCharArray:
		RefRZChar(other.RefRZChar(), other.GetCount());
		break;
	case cRZBaseVariant::cIGZVariant::Type::VoidPtrArray:
		RefVoidPtr(other.RefVoidPtr(), other.GetCount());
		break;
	}
}

bool cRZBaseVariant::IsArrayType() const
{
	return (static_cast<uint16_t>(type) & 0x8000) != 0;
}

void cRZBaseVariant::SetType(cIGZVariant::Type newType)
{
	if (type != newType)
	{
		if (type != cIGZVariant::Type::Empty)
		{
			Clear();
		}
		type = newType;
	}
}

void cRZBaseVariant::SetValue(bool value)
{
	SetType(cIGZVariant::Type::Bool);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(uint8_t value)
{
	SetType(cIGZVariant::Type::Uint8);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(int8_t value)
{
	SetType(cIGZVariant::Type::Sint8);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(uint16_t value)
{
	SetType(cIGZVariant::Type::Uint16);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(int16_t value)
{
	SetType(cIGZVariant::Type::Sint16);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(uint32_t value)
{
	SetType(cIGZVariant::Type::Uint32);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(int32_t value)
{
	SetType(cIGZVariant::Type::Sint32);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(uint64_t value)
{
	SetType(cIGZVariant::Type::Uint64);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(int64_t value)
{
	SetType(cIGZVariant::Type::Sint64);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(float value)
{
	SetType(cIGZVariant::Type::Float32);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(double value)
{
	SetType(cIGZVariant::Type::Float64);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(char value)
{
	SetType(cIGZVariant::Type::Char);
	numericTypes = value;
}

void cRZBaseVariant::SetValueRZUnicode(uint16_t value)
{
	SetType(cIGZVariant::Type::RZUnicodeChar);
	numericTypes = value;
}

void cRZBaseVariant::SetValueRZChar(char value)
{
	SetType(cIGZVariant::Type::RZChar);
	numericTypes = value;
}

void cRZBaseVariant::SetValue(void* value)
{
	SetType(cIGZVariant::Type::VoidPtr);
	voidPtr = value;
}

void cRZBaseVariant::SetValue(cIGZUnknown* value)
{
	SetType(cIGZVariant::Type::GZUnknown);

	if (gzUnknown != value)
	{
		if (value)
		{
			value->AddRef();
		}

		if (gzUnknown)
		{
			gzUnknown->Release();
		}

		gzUnknown = value;
	}
}
