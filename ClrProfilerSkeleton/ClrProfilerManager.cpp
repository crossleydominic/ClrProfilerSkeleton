#include <windows.h>
#include "stdafx.h"
#include "ClrProfilerManager.h"

//Initialize static member variable
ClrProfilerManager* ClrProfilerManager::m_instance = NULL;

ClrProfilerManager::ClrProfilerManager()
{
	m_profiler = NULL;
}

ClrProfilerManager::~ClrProfilerManager()
{
	if(m_instance != NULL)
	{
		delete m_instance;
	}
}

ClrProfilerManager* ClrProfilerManager::GetInstance()
{
	if(m_instance == NULL)
	{
		m_instance = new ClrProfilerManager();	
	}

	return m_instance;
}

ClrProfilerImpl* ClrProfilerManager::GetProfiler()
{
	return m_profiler;
}
 
void ClrProfilerManager::SetProfiler(ClrProfilerImpl* profiler)
{
	if(profiler != NULL)
	{
		m_profiler = profiler;
	}
}