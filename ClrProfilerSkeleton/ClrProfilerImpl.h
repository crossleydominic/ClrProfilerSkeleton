#ifndef INC_CLRPROFILERIMPL_H
#define INC_CLRPROFILERIMPL_H

#include "ClrProfiler_h.h"

//===========================================================
//	Implementation of the Profiler
//===========================================================
class ClrProfilerImpl : public IClrProfiler
{
public:
	ClrProfilerImpl();

	//IUnknown Implementation
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	virtual ULONG __stdcall AddRef() ;
	virtual ULONG __stdcall Release() ;

	//We're not really interested in implementing any of the 
	//ICorProfilerCallback functions at the mo so just provide
	//default inline implementation.

	//ICorProfilerCallback Implementation
	HRESULT __stdcall Initialize(IUnknown *pICorProfilerInfoUnk);
    HRESULT __stdcall Shutdown(){
		return S_OK;	
	};
   	HRESULT __stdcall AppDomainCreationStarted(AppDomainID appDomainID){
		return S_OK;	
	};
	HRESULT __stdcall AppDomainCreationFinished(AppDomainID appDomainID, HRESULT hrStatus){
		return S_OK;	
	};
    HRESULT __stdcall AppDomainShutdownStarted(AppDomainID appDomainID){
		return S_OK;	
	};
	HRESULT __stdcall AppDomainShutdownFinished(AppDomainID appDomainID, HRESULT hrStatus){
		return S_OK;	
	};
   	HRESULT __stdcall AssemblyLoadStarted(AssemblyID assemblyID){
		return S_OK;	
	};
	HRESULT __stdcall AssemblyLoadFinished(AssemblyID assemblyID, HRESULT hrStatus){
		return S_OK;	
	};
    HRESULT __stdcall AssemblyUnloadStarted(AssemblyID assemblyID){
		return S_OK;	
	};
	HRESULT __stdcall AssemblyUnloadFinished(AssemblyID assemblyID, HRESULT hrStatus){
		return S_OK;	
	};
   	HRESULT __stdcall ModuleLoadStarted(ModuleID moduleID){
		return S_OK;	
	};
	HRESULT __stdcall ModuleLoadFinished(ModuleID moduleID, HRESULT hrStatus){
		return S_OK;	
	};
    HRESULT __stdcall ModuleUnloadStarted(ModuleID moduleID){
		return S_OK;	
	};
	HRESULT __stdcall ModuleUnloadFinished(ModuleID moduleID, HRESULT hrStatus){
		return S_OK;	
	};
	HRESULT __stdcall ModuleAttachedToAssembly(ModuleID moduleID, AssemblyID assemblyID){
		return S_OK;	
	};
    HRESULT __stdcall ClassLoadStarted(ClassID classID){
		return S_OK;	
	};
    HRESULT __stdcall ClassLoadFinished(ClassID classID, HRESULT hrStatus){
		return S_OK;	
	};
 	HRESULT __stdcall ClassUnloadStarted(ClassID classID){
		return S_OK;	
	};
	HRESULT __stdcall ClassUnloadFinished(ClassID classID, HRESULT hrStatus){
		return S_OK;	
	};
	HRESULT __stdcall FunctionUnloadStarted(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall JITCompilationStarted(FunctionID functionID, BOOL fIsSafeToBlock){
		return S_OK;	
	};
    HRESULT __stdcall JITCompilationFinished(FunctionID functionID, HRESULT hrStatus, BOOL fIsSafeToBlock){
		return S_OK;	
	};
    HRESULT __stdcall JITCachedFunctionSearchStarted(FunctionID functionID, BOOL *pbUseCachedFunction){
		return S_OK;	
	};
	HRESULT __stdcall JITCachedFunctionSearchFinished(FunctionID functionID, COR_PRF_JIT_CACHE result){
		return S_OK;	
	};
    HRESULT __stdcall JITFunctionPitched(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall JITInlining(FunctionID callerID, FunctionID calleeID, BOOL *pfShouldInline){
		return S_OK;	
	};
    HRESULT __stdcall ThreadCreated(ThreadID threadID){
		return S_OK;	
	};
    HRESULT __stdcall ThreadDestroyed(ThreadID threadID){
		return S_OK;	
	};
    HRESULT __stdcall ThreadAssignedToOSThread(ThreadID managedThreadID, DWORD osThreadID){
		return S_OK;	
	};
    HRESULT __stdcall RemotingClientInvocationStarted(){
		return S_OK;	
	};
    HRESULT __stdcall RemotingClientSendingMessage(GUID *pCookie, BOOL fIsAsync){
		return S_OK;	
	};
    HRESULT __stdcall RemotingClientReceivingReply(GUID *pCookie, BOOL fIsAsync){
		return S_OK;	
	};
    HRESULT __stdcall RemotingClientInvocationFinished(){
		return S_OK;	
	};
    HRESULT __stdcall RemotingServerReceivingMessage(GUID *pCookie, BOOL fIsAsync){
		return S_OK;	
	};
    HRESULT __stdcall RemotingServerInvocationStarted(){
		return S_OK;	
	};
    HRESULT __stdcall RemotingServerInvocationReturned(){
		return S_OK;	
	};
    HRESULT __stdcall RemotingServerSendingReply(GUID *pCookie, BOOL fIsAsync){
		return S_OK;	
	};
	HRESULT __stdcall UnmanagedToManagedTransition(FunctionID functionID, COR_PRF_TRANSITION_REASON reason){
		return S_OK;	
	};
    HRESULT __stdcall ManagedToUnmanagedTransition(FunctionID functionID, COR_PRF_TRANSITION_REASON reason){
		return S_OK;	
	};
    HRESULT __stdcall RuntimeSuspendStarted(COR_PRF_SUSPEND_REASON suspendReason){
		return S_OK;	
	};
    HRESULT __stdcall RuntimeSuspendFinished(){
		return S_OK;	
	};
    HRESULT __stdcall RuntimeSuspendAborted(){
		return S_OK;	
	};
    HRESULT __stdcall RuntimeResumeStarted(){
		return S_OK;	
	};
    HRESULT __stdcall RuntimeResumeFinished(){
		return S_OK;	
	};
    HRESULT __stdcall RuntimeThreadSuspended(ThreadID threadid){
		return S_OK;	
	};
    HRESULT __stdcall RuntimeThreadResumed(ThreadID threadid){
		return S_OK;	
	};
    HRESULT __stdcall MovedReferences(ULONG cmovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[]){
		return S_OK;	
	};
    HRESULT __stdcall ObjectAllocated(ObjectID objectID, ClassID classID){
		return S_OK;	
	};
    HRESULT __stdcall ObjectsAllocatedByClass(ULONG classCount, ClassID classIDs[], ULONG objects[]){
		return S_OK;	
	};
    HRESULT __stdcall ObjectReferences(ObjectID objectID, ClassID classID, ULONG cObjectRefs, ObjectID objectRefIDs[]){
		return S_OK;	
	};
    HRESULT __stdcall RootReferences(ULONG cRootRefs, ObjectID rootRefIDs[]){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionThrown(ObjectID thrownObjectID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionSearchFunctionEnter(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionSearchFunctionLeave(){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionSearchFilterEnter(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionSearchFilterLeave(){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionSearchCatcherFound(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionCLRCatcherFound(){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionCLRCatcherExecute(){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionOSHandlerEnter(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionOSHandlerLeave(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionUnwindFunctionEnter(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionUnwindFunctionLeave(){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionUnwindFinallyEnter(FunctionID functionID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionUnwindFinallyLeave(){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionCatcherEnter(FunctionID functionID, ObjectID objectID){
		return S_OK;	
	};
    HRESULT __stdcall ExceptionCatcherLeave(){
		return S_OK;	
	};
    HRESULT __stdcall COMClassicVTableCreated(ClassID wrappedClassID, REFGUID implementedIID, void *pVTable, ULONG cSlots){
		return S_OK;	
	};
    HRESULT __stdcall COMClassicVTableDestroyed(ClassID wrappedClassID, REFGUID implementedIID, void *pVTable){
		return S_OK;	
	};

	//ICorProfilerCallback2 Implementation
	HRESULT __stdcall ThreadNameChanged(ThreadID threadId, ULONG cchName, WCHAR name[]){
		return S_OK;	
	};
	HRESULT __stdcall GarbageCollectionStarted(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason){
		return S_OK;	
	};
    HRESULT __stdcall SurvivingReferences(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[]){
		return S_OK;	
	};
    HRESULT __stdcall GarbageCollectionFinished(){
		return S_OK;	
	};
    HRESULT __stdcall FinalizeableObjectQueued(DWORD finalizerFlags, ObjectID objectID){
		return S_OK;	
	};
    HRESULT __stdcall RootReferences2(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[]){
		return S_OK;	
	};
    HRESULT __stdcall HandleCreated(GCHandleID handleId, ObjectID initialObjectId){
		return S_OK;	
	};
    HRESULT __stdcall HandleDestroyed(GCHandleID handleId){
		return S_OK;	
	};

	void FunctionEnter2Impl(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_INFO *retvalRange);
	void FunctionLeave2Impl(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo, COR_PRF_FUNCTION_ARGUMENT_RANGE *argInfo);
	void FunctionTailcall2Impl(FunctionID functionID, UINT_PTR clientData, COR_PRF_FRAME_INFO frameInfo);


private:
	//Reference count
	long m_cRef;

	//Destructor is private so that heap allocation
	//(as opposed to stack based allocation)
	//is the only way of creating an instance of this
	//class.
	~ClrProfilerImpl();

	void FormatFunctionName(LPWSTR className, LPWSTR functionName, LPWSTR formattedBuffer, long bufferSize);

	//Stores references to the Profiling APIs interfaces.
	//We need references to both because they let us query
	//for different things.
	ICorProfilerInfo* m_profilerInfo;
	ICorProfilerInfo2* m_profilerInfo2;

	long m_stackSize;
};

#endif INC_CLRPROFILERIMPL_H