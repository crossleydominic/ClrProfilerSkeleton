#include <windows.h>

#include "cor.h"
#include "ClrProfiler_i.c"
#include "ClrProfilerManager.h"
#include "stdafx.h"

void __declspec( naked ) EnterNaked2(FunctionID funcId, 
                                     UINT_PTR clientData, 
                                     COR_PRF_FRAME_INFO frameInfo, 
                                     COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo)
{

  __asm
  {
    PUSH EBP
    MOV EBP, ESP

    PUSH EAX
    PUSH ECX
    PUSH EDX

  }

  ClrProfilerManager::GetInstance()->GetProfiler()->FunctionEnter2Impl (funcId, clientData, frameInfo, argumentInfo);

  __asm
  {
    POP  EDX
    POP  ECX
    POP  EAX

    MOV ESP, EBP
    POP EBP

    RET 10H
  }
  
} // EnterNaked

void __declspec( naked ) LeaveNaked2(FunctionID funcId, 
                                     UINT_PTR clientData, 
                                     COR_PRF_FRAME_INFO frameInfo, 
                                     COR_PRF_FUNCTION_ARGUMENT_RANGE *retvalRange)
{
 __asm
  {
    PUSH EBP
    MOV EBP, ESP

    PUSH EAX
    PUSH ECX
    PUSH EDX
  }

  ClrProfilerManager::GetInstance()->GetProfiler()->FunctionLeave2Impl(funcId, clientData, frameInfo, retvalRange);

  __asm
  {
    POP  EDX
    POP  ECX
    POP  EAX

    MOV ESP, EBP
    POP EBP

    RET 10H
  }
} // LeaveNaked


void __declspec( naked ) TailcallNaked2(FunctionID funcId, 
                                        UINT_PTR clientData, 
                                        COR_PRF_FRAME_INFO frameInfo)
{
    __asm
    {
        push eax
        push ecx
        push edx
	}

	ClrProfilerManager::GetInstance()->GetProfiler()->FunctionTailcall2Impl(funcId, clientData, frameInfo);

	__asm
	{
        pop edx
        pop ecx
        pop eax
        ret 10H
    }
} // TailcallNaked

