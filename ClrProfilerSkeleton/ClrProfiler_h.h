

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Mar 09 08:08:59 2012
 */
/* Compiler settings for ClrProfiler.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ClrProfiler_h_h__
#define __ClrProfiler_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IClrProfilerClassFactory_FWD_DEFINED__
#define __IClrProfilerClassFactory_FWD_DEFINED__
typedef interface IClrProfilerClassFactory IClrProfilerClassFactory;
#endif 	/* __IClrProfilerClassFactory_FWD_DEFINED__ */


#ifndef __IClrProfiler_FWD_DEFINED__
#define __IClrProfiler_FWD_DEFINED__
typedef interface IClrProfiler IClrProfiler;
#endif 	/* __IClrProfiler_FWD_DEFINED__ */


#ifndef __ClrProfiler_FWD_DEFINED__
#define __ClrProfiler_FWD_DEFINED__

#ifdef __cplusplus
typedef class ClrProfiler ClrProfiler;
#else
typedef struct ClrProfiler ClrProfiler;
#endif /* __cplusplus */

#endif 	/* __ClrProfiler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "corprof.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IClrProfilerClassFactory_INTERFACE_DEFINED__
#define __IClrProfilerClassFactory_INTERFACE_DEFINED__

/* interface IClrProfilerClassFactory */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IClrProfilerClassFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("836B7AD4-4C6F-4587-99AA-4CB2A4F045B6")
    IClrProfilerClassFactory : public IClassFactory
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IClrProfilerClassFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClrProfilerClassFactory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClrProfilerClassFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClrProfilerClassFactory * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            IClrProfilerClassFactory * This,
            /* [unique][in] */ IUnknown *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *LockServer )( 
            IClrProfilerClassFactory * This,
            /* [in] */ BOOL fLock);
        
        END_INTERFACE
    } IClrProfilerClassFactoryVtbl;

    interface IClrProfilerClassFactory
    {
        CONST_VTBL struct IClrProfilerClassFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClrProfilerClassFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClrProfilerClassFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClrProfilerClassFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClrProfilerClassFactory_CreateInstance(This,pUnkOuter,riid,ppvObject)	\
    ( (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObject) ) 

#define IClrProfilerClassFactory_LockServer(This,fLock)	\
    ( (This)->lpVtbl -> LockServer(This,fLock) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IClrProfilerClassFactory_INTERFACE_DEFINED__ */


#ifndef __IClrProfiler_INTERFACE_DEFINED__
#define __IClrProfiler_INTERFACE_DEFINED__

/* interface IClrProfiler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IClrProfiler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37DB3D2B-0571-41d2-8CF4-E7B4D3AEE601")
    IClrProfiler : public ICorProfilerCallback2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IClrProfilerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClrProfiler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClrProfiler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IClrProfiler * This,
            /* [in] */ IUnknown *pICorProfilerInfoUnk);
        
        HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *AppDomainCreationStarted )( 
            IClrProfiler * This,
            /* [in] */ AppDomainID appDomainId);
        
        HRESULT ( STDMETHODCALLTYPE *AppDomainCreationFinished )( 
            IClrProfiler * This,
            /* [in] */ AppDomainID appDomainId,
            /* [in] */ HRESULT hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE *AppDomainShutdownStarted )( 
            IClrProfiler * This,
            /* [in] */ AppDomainID appDomainId);
        
        HRESULT ( STDMETHODCALLTYPE *AppDomainShutdownFinished )( 
            IClrProfiler * This,
            /* [in] */ AppDomainID appDomainId,
            /* [in] */ HRESULT hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE *AssemblyLoadStarted )( 
            IClrProfiler * This,
            /* [in] */ AssemblyID assemblyId);
        
        HRESULT ( STDMETHODCALLTYPE *AssemblyLoadFinished )( 
            IClrProfiler * This,
            /* [in] */ AssemblyID assemblyId,
            /* [in] */ HRESULT hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE *AssemblyUnloadStarted )( 
            IClrProfiler * This,
            /* [in] */ AssemblyID assemblyId);
        
        HRESULT ( STDMETHODCALLTYPE *AssemblyUnloadFinished )( 
            IClrProfiler * This,
            /* [in] */ AssemblyID assemblyId,
            /* [in] */ HRESULT hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE *ModuleLoadStarted )( 
            IClrProfiler * This,
            /* [in] */ ModuleID moduleId);
        
        HRESULT ( STDMETHODCALLTYPE *ModuleLoadFinished )( 
            IClrProfiler * This,
            /* [in] */ ModuleID moduleId,
            /* [in] */ HRESULT hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE *ModuleUnloadStarted )( 
            IClrProfiler * This,
            /* [in] */ ModuleID moduleId);
        
        HRESULT ( STDMETHODCALLTYPE *ModuleUnloadFinished )( 
            IClrProfiler * This,
            /* [in] */ ModuleID moduleId,
            /* [in] */ HRESULT hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE *ModuleAttachedToAssembly )( 
            IClrProfiler * This,
            /* [in] */ ModuleID moduleId,
            /* [in] */ AssemblyID AssemblyId);
        
        HRESULT ( STDMETHODCALLTYPE *ClassLoadStarted )( 
            IClrProfiler * This,
            /* [in] */ ClassID classId);
        
        HRESULT ( STDMETHODCALLTYPE *ClassLoadFinished )( 
            IClrProfiler * This,
            /* [in] */ ClassID classId,
            /* [in] */ HRESULT hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE *ClassUnloadStarted )( 
            IClrProfiler * This,
            /* [in] */ ClassID classId);
        
        HRESULT ( STDMETHODCALLTYPE *ClassUnloadFinished )( 
            IClrProfiler * This,
            /* [in] */ ClassID classId,
            /* [in] */ HRESULT hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE *FunctionUnloadStarted )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId);
        
        HRESULT ( STDMETHODCALLTYPE *JITCompilationStarted )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId,
            /* [in] */ BOOL fIsSafeToBlock);
        
        HRESULT ( STDMETHODCALLTYPE *JITCompilationFinished )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId,
            /* [in] */ HRESULT hrStatus,
            /* [in] */ BOOL fIsSafeToBlock);
        
        HRESULT ( STDMETHODCALLTYPE *JITCachedFunctionSearchStarted )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId,
            /* [out] */ BOOL *pbUseCachedFunction);
        
        HRESULT ( STDMETHODCALLTYPE *JITCachedFunctionSearchFinished )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId,
            /* [in] */ COR_PRF_JIT_CACHE result);
        
        HRESULT ( STDMETHODCALLTYPE *JITFunctionPitched )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId);
        
        HRESULT ( STDMETHODCALLTYPE *JITInlining )( 
            IClrProfiler * This,
            /* [in] */ FunctionID callerId,
            /* [in] */ FunctionID calleeId,
            /* [out] */ BOOL *pfShouldInline);
        
        HRESULT ( STDMETHODCALLTYPE *ThreadCreated )( 
            IClrProfiler * This,
            /* [in] */ ThreadID threadId);
        
        HRESULT ( STDMETHODCALLTYPE *ThreadDestroyed )( 
            IClrProfiler * This,
            /* [in] */ ThreadID threadId);
        
        HRESULT ( STDMETHODCALLTYPE *ThreadAssignedToOSThread )( 
            IClrProfiler * This,
            /* [in] */ ThreadID managedThreadId,
            /* [in] */ DWORD osThreadId);
        
        HRESULT ( STDMETHODCALLTYPE *RemotingClientInvocationStarted )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RemotingClientSendingMessage )( 
            IClrProfiler * This,
            /* [in] */ GUID *pCookie,
            /* [in] */ BOOL fIsAsync);
        
        HRESULT ( STDMETHODCALLTYPE *RemotingClientReceivingReply )( 
            IClrProfiler * This,
            /* [in] */ GUID *pCookie,
            /* [in] */ BOOL fIsAsync);
        
        HRESULT ( STDMETHODCALLTYPE *RemotingClientInvocationFinished )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RemotingServerReceivingMessage )( 
            IClrProfiler * This,
            /* [in] */ GUID *pCookie,
            /* [in] */ BOOL fIsAsync);
        
        HRESULT ( STDMETHODCALLTYPE *RemotingServerInvocationStarted )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RemotingServerInvocationReturned )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RemotingServerSendingReply )( 
            IClrProfiler * This,
            /* [in] */ GUID *pCookie,
            /* [in] */ BOOL fIsAsync);
        
        HRESULT ( STDMETHODCALLTYPE *UnmanagedToManagedTransition )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId,
            /* [in] */ COR_PRF_TRANSITION_REASON reason);
        
        HRESULT ( STDMETHODCALLTYPE *ManagedToUnmanagedTransition )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId,
            /* [in] */ COR_PRF_TRANSITION_REASON reason);
        
        HRESULT ( STDMETHODCALLTYPE *RuntimeSuspendStarted )( 
            IClrProfiler * This,
            /* [in] */ COR_PRF_SUSPEND_REASON suspendReason);
        
        HRESULT ( STDMETHODCALLTYPE *RuntimeSuspendFinished )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RuntimeSuspendAborted )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RuntimeResumeStarted )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RuntimeResumeFinished )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RuntimeThreadSuspended )( 
            IClrProfiler * This,
            /* [in] */ ThreadID threadId);
        
        HRESULT ( STDMETHODCALLTYPE *RuntimeThreadResumed )( 
            IClrProfiler * This,
            /* [in] */ ThreadID threadId);
        
        HRESULT ( STDMETHODCALLTYPE *MovedReferences )( 
            IClrProfiler * This,
            /* [in] */ ULONG cMovedObjectIDRanges,
            /* [size_is][in] */ ObjectID oldObjectIDRangeStart[  ],
            /* [size_is][in] */ ObjectID newObjectIDRangeStart[  ],
            /* [size_is][in] */ ULONG cObjectIDRangeLength[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ObjectAllocated )( 
            IClrProfiler * This,
            /* [in] */ ObjectID objectId,
            /* [in] */ ClassID classId);
        
        HRESULT ( STDMETHODCALLTYPE *ObjectsAllocatedByClass )( 
            IClrProfiler * This,
            /* [in] */ ULONG cClassCount,
            /* [size_is][in] */ ClassID classIds[  ],
            /* [size_is][in] */ ULONG cObjects[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ObjectReferences )( 
            IClrProfiler * This,
            /* [in] */ ObjectID objectId,
            /* [in] */ ClassID classId,
            /* [in] */ ULONG cObjectRefs,
            /* [size_is][in] */ ObjectID objectRefIds[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *RootReferences )( 
            IClrProfiler * This,
            /* [in] */ ULONG cRootRefs,
            /* [size_is][in] */ ObjectID rootRefIds[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionThrown )( 
            IClrProfiler * This,
            /* [in] */ ObjectID thrownObjectId);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionSearchFunctionEnter )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionSearchFunctionLeave )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionSearchFilterEnter )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionSearchFilterLeave )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionSearchCatcherFound )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionOSHandlerEnter )( 
            IClrProfiler * This,
            /* [in] */ UINT_PTR __unused);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionOSHandlerLeave )( 
            IClrProfiler * This,
            /* [in] */ UINT_PTR __unused);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionUnwindFunctionEnter )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionUnwindFunctionLeave )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionUnwindFinallyEnter )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionUnwindFinallyLeave )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionCatcherEnter )( 
            IClrProfiler * This,
            /* [in] */ FunctionID functionId,
            /* [in] */ ObjectID objectId);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionCatcherLeave )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *COMClassicVTableCreated )( 
            IClrProfiler * This,
            /* [in] */ ClassID wrappedClassId,
            /* [in] */ REFGUID implementedIID,
            /* [in] */ void *pVTable,
            /* [in] */ ULONG cSlots);
        
        HRESULT ( STDMETHODCALLTYPE *COMClassicVTableDestroyed )( 
            IClrProfiler * This,
            /* [in] */ ClassID wrappedClassId,
            /* [in] */ REFGUID implementedIID,
            /* [in] */ void *pVTable);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionCLRCatcherFound )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *ExceptionCLRCatcherExecute )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *ThreadNameChanged )( 
            IClrProfiler * This,
            /* [in] */ ThreadID threadId,
            /* [in] */ ULONG cchName,
            /* [annotation][in] */ 
            __in_ecount_opt(cchName)  WCHAR name[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GarbageCollectionStarted )( 
            IClrProfiler * This,
            /* [in] */ int cGenerations,
            /* [size_is][in] */ BOOL generationCollected[  ],
            /* [in] */ COR_PRF_GC_REASON reason);
        
        HRESULT ( STDMETHODCALLTYPE *SurvivingReferences )( 
            IClrProfiler * This,
            /* [in] */ ULONG cSurvivingObjectIDRanges,
            /* [size_is][in] */ ObjectID objectIDRangeStart[  ],
            /* [size_is][in] */ ULONG cObjectIDRangeLength[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GarbageCollectionFinished )( 
            IClrProfiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *FinalizeableObjectQueued )( 
            IClrProfiler * This,
            /* [in] */ DWORD finalizerFlags,
            /* [in] */ ObjectID objectID);
        
        HRESULT ( STDMETHODCALLTYPE *RootReferences2 )( 
            IClrProfiler * This,
            /* [in] */ ULONG cRootRefs,
            /* [size_is][in] */ ObjectID rootRefIds[  ],
            /* [size_is][in] */ COR_PRF_GC_ROOT_KIND rootKinds[  ],
            /* [size_is][in] */ COR_PRF_GC_ROOT_FLAGS rootFlags[  ],
            /* [size_is][in] */ UINT_PTR rootIds[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *HandleCreated )( 
            IClrProfiler * This,
            /* [in] */ GCHandleID handleId,
            /* [in] */ ObjectID initialObjectId);
        
        HRESULT ( STDMETHODCALLTYPE *HandleDestroyed )( 
            IClrProfiler * This,
            /* [in] */ GCHandleID handleId);
        
        END_INTERFACE
    } IClrProfilerVtbl;

    interface IClrProfiler
    {
        CONST_VTBL struct IClrProfilerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClrProfiler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClrProfiler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClrProfiler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClrProfiler_Initialize(This,pICorProfilerInfoUnk)	\
    ( (This)->lpVtbl -> Initialize(This,pICorProfilerInfoUnk) ) 

#define IClrProfiler_Shutdown(This)	\
    ( (This)->lpVtbl -> Shutdown(This) ) 

#define IClrProfiler_AppDomainCreationStarted(This,appDomainId)	\
    ( (This)->lpVtbl -> AppDomainCreationStarted(This,appDomainId) ) 

#define IClrProfiler_AppDomainCreationFinished(This,appDomainId,hrStatus)	\
    ( (This)->lpVtbl -> AppDomainCreationFinished(This,appDomainId,hrStatus) ) 

#define IClrProfiler_AppDomainShutdownStarted(This,appDomainId)	\
    ( (This)->lpVtbl -> AppDomainShutdownStarted(This,appDomainId) ) 

#define IClrProfiler_AppDomainShutdownFinished(This,appDomainId,hrStatus)	\
    ( (This)->lpVtbl -> AppDomainShutdownFinished(This,appDomainId,hrStatus) ) 

#define IClrProfiler_AssemblyLoadStarted(This,assemblyId)	\
    ( (This)->lpVtbl -> AssemblyLoadStarted(This,assemblyId) ) 

#define IClrProfiler_AssemblyLoadFinished(This,assemblyId,hrStatus)	\
    ( (This)->lpVtbl -> AssemblyLoadFinished(This,assemblyId,hrStatus) ) 

#define IClrProfiler_AssemblyUnloadStarted(This,assemblyId)	\
    ( (This)->lpVtbl -> AssemblyUnloadStarted(This,assemblyId) ) 

#define IClrProfiler_AssemblyUnloadFinished(This,assemblyId,hrStatus)	\
    ( (This)->lpVtbl -> AssemblyUnloadFinished(This,assemblyId,hrStatus) ) 

#define IClrProfiler_ModuleLoadStarted(This,moduleId)	\
    ( (This)->lpVtbl -> ModuleLoadStarted(This,moduleId) ) 

#define IClrProfiler_ModuleLoadFinished(This,moduleId,hrStatus)	\
    ( (This)->lpVtbl -> ModuleLoadFinished(This,moduleId,hrStatus) ) 

#define IClrProfiler_ModuleUnloadStarted(This,moduleId)	\
    ( (This)->lpVtbl -> ModuleUnloadStarted(This,moduleId) ) 

#define IClrProfiler_ModuleUnloadFinished(This,moduleId,hrStatus)	\
    ( (This)->lpVtbl -> ModuleUnloadFinished(This,moduleId,hrStatus) ) 

#define IClrProfiler_ModuleAttachedToAssembly(This,moduleId,AssemblyId)	\
    ( (This)->lpVtbl -> ModuleAttachedToAssembly(This,moduleId,AssemblyId) ) 

#define IClrProfiler_ClassLoadStarted(This,classId)	\
    ( (This)->lpVtbl -> ClassLoadStarted(This,classId) ) 

#define IClrProfiler_ClassLoadFinished(This,classId,hrStatus)	\
    ( (This)->lpVtbl -> ClassLoadFinished(This,classId,hrStatus) ) 

#define IClrProfiler_ClassUnloadStarted(This,classId)	\
    ( (This)->lpVtbl -> ClassUnloadStarted(This,classId) ) 

#define IClrProfiler_ClassUnloadFinished(This,classId,hrStatus)	\
    ( (This)->lpVtbl -> ClassUnloadFinished(This,classId,hrStatus) ) 

#define IClrProfiler_FunctionUnloadStarted(This,functionId)	\
    ( (This)->lpVtbl -> FunctionUnloadStarted(This,functionId) ) 

#define IClrProfiler_JITCompilationStarted(This,functionId,fIsSafeToBlock)	\
    ( (This)->lpVtbl -> JITCompilationStarted(This,functionId,fIsSafeToBlock) ) 

#define IClrProfiler_JITCompilationFinished(This,functionId,hrStatus,fIsSafeToBlock)	\
    ( (This)->lpVtbl -> JITCompilationFinished(This,functionId,hrStatus,fIsSafeToBlock) ) 

#define IClrProfiler_JITCachedFunctionSearchStarted(This,functionId,pbUseCachedFunction)	\
    ( (This)->lpVtbl -> JITCachedFunctionSearchStarted(This,functionId,pbUseCachedFunction) ) 

#define IClrProfiler_JITCachedFunctionSearchFinished(This,functionId,result)	\
    ( (This)->lpVtbl -> JITCachedFunctionSearchFinished(This,functionId,result) ) 

#define IClrProfiler_JITFunctionPitched(This,functionId)	\
    ( (This)->lpVtbl -> JITFunctionPitched(This,functionId) ) 

#define IClrProfiler_JITInlining(This,callerId,calleeId,pfShouldInline)	\
    ( (This)->lpVtbl -> JITInlining(This,callerId,calleeId,pfShouldInline) ) 

#define IClrProfiler_ThreadCreated(This,threadId)	\
    ( (This)->lpVtbl -> ThreadCreated(This,threadId) ) 

#define IClrProfiler_ThreadDestroyed(This,threadId)	\
    ( (This)->lpVtbl -> ThreadDestroyed(This,threadId) ) 

#define IClrProfiler_ThreadAssignedToOSThread(This,managedThreadId,osThreadId)	\
    ( (This)->lpVtbl -> ThreadAssignedToOSThread(This,managedThreadId,osThreadId) ) 

#define IClrProfiler_RemotingClientInvocationStarted(This)	\
    ( (This)->lpVtbl -> RemotingClientInvocationStarted(This) ) 

#define IClrProfiler_RemotingClientSendingMessage(This,pCookie,fIsAsync)	\
    ( (This)->lpVtbl -> RemotingClientSendingMessage(This,pCookie,fIsAsync) ) 

#define IClrProfiler_RemotingClientReceivingReply(This,pCookie,fIsAsync)	\
    ( (This)->lpVtbl -> RemotingClientReceivingReply(This,pCookie,fIsAsync) ) 

#define IClrProfiler_RemotingClientInvocationFinished(This)	\
    ( (This)->lpVtbl -> RemotingClientInvocationFinished(This) ) 

#define IClrProfiler_RemotingServerReceivingMessage(This,pCookie,fIsAsync)	\
    ( (This)->lpVtbl -> RemotingServerReceivingMessage(This,pCookie,fIsAsync) ) 

#define IClrProfiler_RemotingServerInvocationStarted(This)	\
    ( (This)->lpVtbl -> RemotingServerInvocationStarted(This) ) 

#define IClrProfiler_RemotingServerInvocationReturned(This)	\
    ( (This)->lpVtbl -> RemotingServerInvocationReturned(This) ) 

#define IClrProfiler_RemotingServerSendingReply(This,pCookie,fIsAsync)	\
    ( (This)->lpVtbl -> RemotingServerSendingReply(This,pCookie,fIsAsync) ) 

#define IClrProfiler_UnmanagedToManagedTransition(This,functionId,reason)	\
    ( (This)->lpVtbl -> UnmanagedToManagedTransition(This,functionId,reason) ) 

#define IClrProfiler_ManagedToUnmanagedTransition(This,functionId,reason)	\
    ( (This)->lpVtbl -> ManagedToUnmanagedTransition(This,functionId,reason) ) 

#define IClrProfiler_RuntimeSuspendStarted(This,suspendReason)	\
    ( (This)->lpVtbl -> RuntimeSuspendStarted(This,suspendReason) ) 

#define IClrProfiler_RuntimeSuspendFinished(This)	\
    ( (This)->lpVtbl -> RuntimeSuspendFinished(This) ) 

#define IClrProfiler_RuntimeSuspendAborted(This)	\
    ( (This)->lpVtbl -> RuntimeSuspendAborted(This) ) 

#define IClrProfiler_RuntimeResumeStarted(This)	\
    ( (This)->lpVtbl -> RuntimeResumeStarted(This) ) 

#define IClrProfiler_RuntimeResumeFinished(This)	\
    ( (This)->lpVtbl -> RuntimeResumeFinished(This) ) 

#define IClrProfiler_RuntimeThreadSuspended(This,threadId)	\
    ( (This)->lpVtbl -> RuntimeThreadSuspended(This,threadId) ) 

#define IClrProfiler_RuntimeThreadResumed(This,threadId)	\
    ( (This)->lpVtbl -> RuntimeThreadResumed(This,threadId) ) 

#define IClrProfiler_MovedReferences(This,cMovedObjectIDRanges,oldObjectIDRangeStart,newObjectIDRangeStart,cObjectIDRangeLength)	\
    ( (This)->lpVtbl -> MovedReferences(This,cMovedObjectIDRanges,oldObjectIDRangeStart,newObjectIDRangeStart,cObjectIDRangeLength) ) 

#define IClrProfiler_ObjectAllocated(This,objectId,classId)	\
    ( (This)->lpVtbl -> ObjectAllocated(This,objectId,classId) ) 

#define IClrProfiler_ObjectsAllocatedByClass(This,cClassCount,classIds,cObjects)	\
    ( (This)->lpVtbl -> ObjectsAllocatedByClass(This,cClassCount,classIds,cObjects) ) 

#define IClrProfiler_ObjectReferences(This,objectId,classId,cObjectRefs,objectRefIds)	\
    ( (This)->lpVtbl -> ObjectReferences(This,objectId,classId,cObjectRefs,objectRefIds) ) 

#define IClrProfiler_RootReferences(This,cRootRefs,rootRefIds)	\
    ( (This)->lpVtbl -> RootReferences(This,cRootRefs,rootRefIds) ) 

#define IClrProfiler_ExceptionThrown(This,thrownObjectId)	\
    ( (This)->lpVtbl -> ExceptionThrown(This,thrownObjectId) ) 

#define IClrProfiler_ExceptionSearchFunctionEnter(This,functionId)	\
    ( (This)->lpVtbl -> ExceptionSearchFunctionEnter(This,functionId) ) 

#define IClrProfiler_ExceptionSearchFunctionLeave(This)	\
    ( (This)->lpVtbl -> ExceptionSearchFunctionLeave(This) ) 

#define IClrProfiler_ExceptionSearchFilterEnter(This,functionId)	\
    ( (This)->lpVtbl -> ExceptionSearchFilterEnter(This,functionId) ) 

#define IClrProfiler_ExceptionSearchFilterLeave(This)	\
    ( (This)->lpVtbl -> ExceptionSearchFilterLeave(This) ) 

#define IClrProfiler_ExceptionSearchCatcherFound(This,functionId)	\
    ( (This)->lpVtbl -> ExceptionSearchCatcherFound(This,functionId) ) 

#define IClrProfiler_ExceptionOSHandlerEnter(This,__unused)	\
    ( (This)->lpVtbl -> ExceptionOSHandlerEnter(This,__unused) ) 

#define IClrProfiler_ExceptionOSHandlerLeave(This,__unused)	\
    ( (This)->lpVtbl -> ExceptionOSHandlerLeave(This,__unused) ) 

#define IClrProfiler_ExceptionUnwindFunctionEnter(This,functionId)	\
    ( (This)->lpVtbl -> ExceptionUnwindFunctionEnter(This,functionId) ) 

#define IClrProfiler_ExceptionUnwindFunctionLeave(This)	\
    ( (This)->lpVtbl -> ExceptionUnwindFunctionLeave(This) ) 

#define IClrProfiler_ExceptionUnwindFinallyEnter(This,functionId)	\
    ( (This)->lpVtbl -> ExceptionUnwindFinallyEnter(This,functionId) ) 

#define IClrProfiler_ExceptionUnwindFinallyLeave(This)	\
    ( (This)->lpVtbl -> ExceptionUnwindFinallyLeave(This) ) 

#define IClrProfiler_ExceptionCatcherEnter(This,functionId,objectId)	\
    ( (This)->lpVtbl -> ExceptionCatcherEnter(This,functionId,objectId) ) 

#define IClrProfiler_ExceptionCatcherLeave(This)	\
    ( (This)->lpVtbl -> ExceptionCatcherLeave(This) ) 

#define IClrProfiler_COMClassicVTableCreated(This,wrappedClassId,implementedIID,pVTable,cSlots)	\
    ( (This)->lpVtbl -> COMClassicVTableCreated(This,wrappedClassId,implementedIID,pVTable,cSlots) ) 

#define IClrProfiler_COMClassicVTableDestroyed(This,wrappedClassId,implementedIID,pVTable)	\
    ( (This)->lpVtbl -> COMClassicVTableDestroyed(This,wrappedClassId,implementedIID,pVTable) ) 

#define IClrProfiler_ExceptionCLRCatcherFound(This)	\
    ( (This)->lpVtbl -> ExceptionCLRCatcherFound(This) ) 

#define IClrProfiler_ExceptionCLRCatcherExecute(This)	\
    ( (This)->lpVtbl -> ExceptionCLRCatcherExecute(This) ) 


#define IClrProfiler_ThreadNameChanged(This,threadId,cchName,name)	\
    ( (This)->lpVtbl -> ThreadNameChanged(This,threadId,cchName,name) ) 

#define IClrProfiler_GarbageCollectionStarted(This,cGenerations,generationCollected,reason)	\
    ( (This)->lpVtbl -> GarbageCollectionStarted(This,cGenerations,generationCollected,reason) ) 

#define IClrProfiler_SurvivingReferences(This,cSurvivingObjectIDRanges,objectIDRangeStart,cObjectIDRangeLength)	\
    ( (This)->lpVtbl -> SurvivingReferences(This,cSurvivingObjectIDRanges,objectIDRangeStart,cObjectIDRangeLength) ) 

#define IClrProfiler_GarbageCollectionFinished(This)	\
    ( (This)->lpVtbl -> GarbageCollectionFinished(This) ) 

#define IClrProfiler_FinalizeableObjectQueued(This,finalizerFlags,objectID)	\
    ( (This)->lpVtbl -> FinalizeableObjectQueued(This,finalizerFlags,objectID) ) 

#define IClrProfiler_RootReferences2(This,cRootRefs,rootRefIds,rootKinds,rootFlags,rootIds)	\
    ( (This)->lpVtbl -> RootReferences2(This,cRootRefs,rootRefIds,rootKinds,rootFlags,rootIds) ) 

#define IClrProfiler_HandleCreated(This,handleId,initialObjectId)	\
    ( (This)->lpVtbl -> HandleCreated(This,handleId,initialObjectId) ) 

#define IClrProfiler_HandleDestroyed(This,handleId)	\
    ( (This)->lpVtbl -> HandleDestroyed(This,handleId) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IClrProfiler_INTERFACE_DEFINED__ */



#ifndef __ClrProfiler_LIBRARY_DEFINED__
#define __ClrProfiler_LIBRARY_DEFINED__

/* library ClrProfiler */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ClrProfiler;

EXTERN_C const CLSID CLSID_ClrProfiler;

#ifdef __cplusplus

class DECLSPEC_UUID("324ADC20-F1DA-411c-AE5C-449C3CDC3BCA")
ClrProfiler;
#endif
#endif /* __ClrProfiler_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


