#include "stdafx.h"

#include "Task.h"

class TService
{
public:
    TService();
    ~TService();

public:
    CTask* addTask();
    void updateProgress(CTask*);
    void finishTask(CTask*);
    void getAward(CTask*);

private:
    map<int32_t, CTask*> m_taskMap;//所有task配置信息存储


};