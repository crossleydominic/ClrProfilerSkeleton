#ifndef INC_CLRPROFILERCLASSFACTORY_H
#define INC_CLRPROFILERCLASSFACTORY_H

#include "ClrProfiler_h.h"

//===========================================================
//	Class factory used by COM to create an instance of 
//	our profiler
//===========================================================
class ClrProfilerClassFactory : public IClrProfilerClassFactory{
public:
	// IUnknown Implementation
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) ;         
	virtual ULONG   __stdcall AddRef() ;
	virtual ULONG   __stdcall Release() ;

	// IClassFactory Implementation
	virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter,
	                                         const IID& iid,
	                                         void** ppv) ;

	//We don't need to implement this as we're only 
	//ever going to be invoked as an in-proc server.
	virtual HRESULT __stdcall LockServer(BOOL bLock){
		return S_OK;
	}; 

	// Constructor
	ClrProfilerClassFactory();

private:
	//Reference counter
	long m_cRef ;

	//Private destructor, heap allocation only
	~ClrProfilerClassFactory();
};

#endif INC_CLRPROFILERCLASSFACTORY_H