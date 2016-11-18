#pragma once
#include "stdafx.h"

#include <list>
#include "Task.h"
#include "TaskConfiger.h"

using namespace std;
class TService
{
public:
    TService();
    ~TService();

public:
    bool addTask(int32_t id);
    void updateProgress(int32_t tid, int32_t count); //更新数量
    void finishTask(int32_t tid);
    void getAward(int32_t tid);

private:
    map<int32_t, shared_ptr<CTask>> processingTasks; //正在处理的任务
    map<int32_t, shared_ptr<CTask>> finishedTasks;   //已经完成的任务
    
    list<shared_ptr<CTask>> avaliableTasks;  //可接受的任务列表



};