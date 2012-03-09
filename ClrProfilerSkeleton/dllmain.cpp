#include "targetver.h"
#include "stdafx.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <windows.h>

#include "cor.h"
#include "corprof.h"
#include "atlbase.h"
#include "ClrProfiler_i.c"
#include "ClrProfilerImpl.h"
#include "ClrProfilerClassFactory.h"
#include <iostream>
#include <fstream>

using namespace std;

//==========================================================
//----------------------------------------------------------
//
//	DLL ENTRY POINT
//
//----------------------------------------------------------
//==========================================================
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
//==========================================================
//----------------------------------------------------------
//
//	END OF DLL ENTRY POINT
//
//----------------------------------------------------------
//==========================================================

//==========================================================
//----------------------------------------------------------
//
//	EXPORTED DLL FUNCTIONS
//
//----------------------------------------------------------
//==========================================================
STDAPI DllCanUnloadNow(void)
{
    return S_OK;
}


STDAPI DllUnregisterServer()
{    
    /*char szID[128];         // the class ID to unregister.
    char szCLSID[128];      // CLSID\\szID.
    OLECHAR szWID[128];     // helper for the class ID to unregister.
    char rcProgID[128];    // szProgIDPrefix.szClassProgID
    char rcIndProgID[128]; // rcProgID.iVersion


    // format the prog ID values.
    sprintf_s( rcProgID,128, "%s.%s", g_szProgIDPrefix, PROFILER_GUID );
    sprintf_s( rcIndProgID,128, "%s.%d", rcProgID, 1 );

	memset (szCLSID, 0, sizeof(szCLSID));
    UnregisterClassBase( CLSID_PROFILER, rcProgID, rcIndProgID, szCLSID, ARRAY_SIZE(szCLSID) );
    DeleteKey( szCLSID, "InprocServer32" );

    StringFromGUID2(CLSID_PROFILER, szWID, ARRAY_SIZE( szWID ) );
    WideCharToMultiByte(CP_ACP, 0, szWID, -1, szID, sizeof(szID), NULL,NULL);

    DeleteKey( "CLSID", szCLSID );*/

    return S_OK;   
}

//================================================================
STDAPI DllRegisterServer()
{    
    HRESULT hr = S_OK;
    /*char  szModule[_MAX_PATH];  

    DllUnregisterServer();
    GetModuleFileNameA( g_hInst, szModule, ARRAY_SIZE(szModule) );

    char rcCLSID[MAX_LENGTH];           // CLSID\\szID.
    char rcProgID[MAX_LENGTH];          // szProgIDPrefix.szClassProgID
    char rcIndProgID[MAX_LENGTH];       // rcProgID.iVersion
    char rcInproc[MAX_LENGTH + 2];      // CLSID\\InprocServer32


    // format the prog ID values.
    sprintf_s( rcIndProgID,MAX_LENGTH, "%s.%s", g_szProgIDPrefix, PROFILER_GUID ) ;
    sprintf_s( rcProgID,MAX_LENGTH, "%s.%d", rcIndProgID, 1 );

    // do the initial portion.
    hr =  RegisterClassBase( CLSID_PROFILER, 
                            "Profiler", rcProgID, rcIndProgID, rcCLSID,
							ARRAY_SIZE (rcCLSID));

    if ( SUCCEEDED( hr ) )
    {
        // set the server path.
        SetKeyAndValue( rcCLSID, "InprocServer32", szModule );

        // add the threading model information.
        sprintf_s( rcInproc,MAX_LENGTH+2, "%s\\%s", rcCLSID, "InprocServer32" );
        SetRegValue( rcInproc, "ThreadingModel", "Both" );
    }   
    else
        DllUnregisterServer();*/
    
    return hr;    
}

//================================================================
STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, LPVOID FAR *ppv )                  
{    
	// Can we create this component?
	if (rclsid != CLSID_ClrProfiler)
	{
		return CLASS_E_CLASSNOTAVAILABLE ;
	}

	//Create class factory
	ClrProfilerClassFactory* classFactory = new ClrProfilerClassFactory();

	if (classFactory == NULL)
	{
		return E_OUTOFMEMORY ;
	}

	// Get requested interface.
	HRESULT hr = classFactory->QueryInterface(riid, ppv) ;
	classFactory->Release() ;

	return hr ;  
}