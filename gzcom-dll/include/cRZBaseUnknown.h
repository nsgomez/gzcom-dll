#pragma once
#include "cIGZUnknown.h"

/**
 * @brief A base class for types that implement cIGZUnknown and delete
 * themselves when their reference count drops to zero.
 */
class cRZBaseUnknown : public cIGZUnknown
{
public:
	virtual ~cRZBaseUnknown();

	/**
	* @brief Casts the object to the interface specified by riid. Override
	* this method to respond to queries for any additional interfaces that
	* you implement.
	* @param riid The GUID for the interface type to cast to.
	* @param ppvObj A pointer to a void pointer to store the result in.
	* @return Whether the object could be successfully cast or not.
	*/
	virtual bool QueryInterface(uint32_t riid, void** ppvObj);

	/**
	* @brief Adds a reference to this object.
	* @return The new reference count for this object.
	*/
	uint32_t AddRef();

	/**
	 * @brief Removes a reference to this object. When the reference
	 * count drops to zero the object will delete itself.
	* @return The new reference count for this object.
	 */
	uint32_t Release();

protected:
	cRZBaseUnknown();
	uint32_t refCount;
};
