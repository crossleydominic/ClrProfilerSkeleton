#include <windows.h>

#include "cor.h"
#include "ClrProfiler_i.c"
#include "ClrProfilerImpl.h"
#include "ClrProfilerClassFactory.h"
#include <iostream>
#include <fstream>
#include "stdafx.h"

//========================
// Constructor/Desctructor
//========================
ClrProfilerClassFactory::ClrProfilerClassFactory() 
{
	m_cRef = 1;
}

ClrProfilerClassFactory::~ClrProfilerClassFactory()
{
}

//========================
// IUnknown implementation
//========================
ULONG ClrProfilerClassFactory::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}
ULONG ClrProfilerClassFactory::Release()
{
	LONG res = InterlockedDecrement(&m_cRef);

	if (res == 0){
		//We only allow heap allocation of this class
		//so its always ok to call delete.
		delete this;
	}
	return res;
}

HRESULT ClrProfilerClassFactory::QueryInterface( REFIID riid, void **ppInterface )
{

	if(riid == IID_IUnknown)
	{
		*ppInterface = static_cast<IClassFactory*>(this);
	}
	else if(riid == IID_IClassFactory)
	{
		*ppInterface = static_cast<IClassFactory*>(this);
	}
	else if(riid == IID_IClrProfiler)
	{
		*ppInterface = static_cast<IClrProfilerClassFactory*>(this);
	}
	else
	{
		//Unussoprted interface requested
		*ppInterface = 0;
		return E_NOTIMPL;
	}

	// if we reach this point, *ppv is non-null
	// and must be AddRef'ed
	reinterpret_cast<IUnknown*>(*ppInterface)->AddRef();
	return S_OK;
}
//============================
// End IUnknown implementation
//============================

//==============================
// IClass Factory Implementation
//==============================

HRESULT __stdcall ClrProfilerClassFactory::CreateInstance(IUnknown* pUnknownOuter,
                                           const IID& iid,
                                           void** ppv) 
{

	// We don't support Com Aggregation here.
	if (pUnknownOuter != NULL)
	{
		return CLASS_E_NOAGGREGATION ;
	}

	// Create Profiler object
	ClrProfilerImpl* profiler = new ClrProfilerImpl();
	if (profiler == NULL)
	{
		return E_OUTOFMEMORY ;
	}

	// Get the requested interface (Should be ICorProfillerCallback(2)).
	HRESULT hr = profiler->QueryInterface(iid, ppv) ;

	// Release the IUnknown pointer.
	// (If QueryInterface failed, component will delete itself.)
	profiler->Release();
	return hr ;
}
//=====================================
// End of IClass Factory Implementation
//=====================================