#include <windows.h>

#include "cor.h"
#include "ClrProfiler_i.c"
#include "ClrProfilerImpl.h"
#include "ClrProfilerClassFactory.h"
#include <iostream>
#include <fstream>
#include "ClrProfilerManager.h"
#include "stdafx.h"
#include "Globals.h"

ClrProfilerImpl::ClrProfilerImpl() 
{
	m_cRef = 1;
	m_profilerInfo = NULL;
	m_profilerInfo2 = NULL;
	m_stackSize = 0;
}

ClrProfilerImpl::~ClrProfilerImpl()
{
	//release interfaces.
	if(m_profilerInfo != NULL)
	{
		m_profilerInfo->Release();
	}

	if(m_profilerInfo2 != NULL)
	{	
		m_profilerInfo2->Release();
	}
}
ULONG ClrProfilerImpl::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}
ULONG ClrProfilerImpl::Release()
{
	LONG res = InterlockedDecrement(&m_cRef);

	if (res == 0){
		//We only allow heap allocation of this class
		//so its always ok to call delete.
		delete this;
	}
	return res;
}

//Boilerplate QI
HRESULT ClrProfilerImpl::QueryInterface( REFIID riid, void **ppInterface )
{
	if(riid == IID_IUnknown)
	{
		*ppInterface = static_cast<ICorProfilerCallback*>(this);
	}
	else if(riid == IID_ICorProfilerCallback)
	{
		*ppInterface = static_cast<ICorProfilerCallback*>(this);
	}
	else if(riid == IID_ICorProfilerCallback2)
	{
		*ppInterface = static_cast<ICorProfilerCallback2*>(this);
	}
	else if(riid == IID_IClrProfiler)
	{
		*ppInterface = static_cast<IClrProfiler*>(this);
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

void ClrProfilerImpl::FunctionEnter2Impl(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_INFO *retvalRange)
{
	//WriteLogOutput(L"Function entered");

	m_stackSize++;

	IMetaDataImport* pIMetaDataImport = 0;
	HRESULT hr = S_OK;
	mdToken funcToken = 0;
	WCHAR szFunction[2048];
	WCHAR szClass[2048];
	WCHAR formatedFunctionName[2048];

	// get the token for the function which we will use to get its name
	hr = m_profilerInfo2->GetTokenAndMetaDataFromFunction(functionID, IID_IMetaDataImport, (LPUNKNOWN *) &pIMetaDataImport, &funcToken);
	if(SUCCEEDED(hr))
	{
		mdTypeDef classTypeDef;
		ULONG cchFunction;
		ULONG cchClass;

		// retrieve the function properties based on the token
		hr = pIMetaDataImport->GetMethodProps(funcToken, &classTypeDef, szFunction, 2048, &cchFunction, 0, 0, 0, 0, 0);
		if (SUCCEEDED(hr))
		{

			// get the function name
			hr = pIMetaDataImport->GetTypeDefProps(classTypeDef, szClass, 2048, &cchClass, 0, 0);
			if (SUCCEEDED(hr))
			{
				// create the fully qualified name
				//WriteLogOutput(szClass);
				//WriteLogOutput(szFunction);
				if(_wcsnicmp(L"NamespaceNameHere", szClass, 10) == 0)
				{
					FormatFunctionName(szClass, szFunction, formatedFunctionName, 2048);
				}

				//_snwprintf_s(wszMethod,cMethod,cMethod,L"%s.%s",szClass,szFunction);
			}
		}
		// release our reference to the metadata
		pIMetaDataImport->Release();
	}

}

void ClrProfilerImpl::FormatFunctionName(LPWSTR className, LPWSTR functionName, LPWSTR formattedBuffer, long bufferLength)
{
	wcscpy_s(formattedBuffer, bufferLength, L"");

	for(int i = 0; i < m_stackSize; i++)
	{
		wcscat_s(formattedBuffer, bufferLength, L"  ");
	}

	wcscat_s(formattedBuffer, bufferLength, className);
	wcscat_s(formattedBuffer, bufferLength, functionName);
}

void ClrProfilerImpl::FunctionLeave2Impl(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_RANGE *argInfo)
{
	m_stackSize--;
}
void ClrProfilerImpl::FunctionTailcall2Impl(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo)
{
	m_stackSize--;
}

//====================================================
// End of ClrProfilerImpl Class Level function handlers
//====================================================

HRESULT __stdcall ClrProfilerImpl::Initialize(IUnknown *pICorProfilerInfoUnk)
{
	ClrProfilerManager::GetInstance()->SetProfiler(this);

	//Try and get ICorProfilerInfo(2) interfaces.	
	pICorProfilerInfoUnk->QueryInterface(IID_ICorProfilerInfo, (void**)&m_profilerInfo);
	pICorProfilerInfoUnk->QueryInterface(IID_ICorProfilerInfo2, (void**)&m_profilerInfo2);

	//We MUST be able to get pointers to both interfaces.
	if(m_profilerInfo == NULL && m_profilerInfo2 == NULL)
	{
		//Indicate failure so our profiler get unloaded.
		return S_FALSE;
	}

	//We're only interested in function enter/leave right now.
	m_profilerInfo2->SetEventMask(COR_PRF_MONITOR_ENTERLEAVE | COR_PRF_ENABLE_STACK_SNAPSHOT);

	//Set the function hooks. 
	//Cast to the expected function prototype.
	m_profilerInfo2->SetEnterLeaveFunctionHooks2((FunctionEnter2*)&EnterNaked2,
												(FunctionLeave2*)&LeaveNaked2,
												(FunctionTailcall2*)&TailcallNaked2);

	return S_OK;	
};