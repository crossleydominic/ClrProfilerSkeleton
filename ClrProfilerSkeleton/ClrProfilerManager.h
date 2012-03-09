#ifndef INC_CLRPROFILERMANAGER_H
#define INC_CLRPROFILERMANAGER_H

#include "cor.h"
#include "ClrProfilerImpl.h"

class ClrProfilerManager
{
public:

	static ClrProfilerManager* GetInstance();

	ClrProfilerImpl* GetProfiler();
	void SetProfiler(ClrProfilerImpl*);

	~ClrProfilerManager();

private: 
	ClrProfilerManager();

	static ClrProfilerManager* m_instance;

	ClrProfilerImpl* m_profiler;
};

#endif INC_CLRPROFILERMANAGER_H