#include "stdafx.h"
#include "Unknown.h"

cIGZUnknown::cIGZUnknown()
	: mnRefCount( 0 )           { DebugMessageBox( "cIGZUnknown spawn" ); /* Empty */ }
cIGZUnknown::~cIGZUnknown()     { DebugMessageBox( "cIGZUnknown destroy"  ); /* Empty */ }

uint32_t cIGZUnknown::AddRef()  { DebugMessageBox( "cIGZUnknown::AddRef" ); return ++mnRefCount; }
uint32_t cIGZUnknown::Release() { DebugMessageBox( "cIGZUnknown::Release" ); return RemoveRef(); }
uint32_t cIGZUnknown::RemoveRef()
{
	DebugMessageBox( "cIGZUnknown::RemoveRef" );
	if( mnRefCount > 0 )
		--mnRefCount;

	return mnRefCount;
}

uint32_t cIGZUnknown::RefCount() { DebugMessageBox( "cIGZUnknown::RefCount" ); return mnRefCount; }

bool cIGZUnknown::QueryInterface( DWORD riid, void** ppvObj )
{
	DebugMessageBox( "cIGZUnknown::QueryInterface" );
	switch( riid )
	{
		// need to get back to this
		case 0x8675309:
		default:
			break;
	}

	char buf[64];
	sprintf_s( buf, 64, "QueryInterface -- %i", riid );
	DebugMessageBox( buf );

	return false;
}