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

    //任务的刷新, 暂时放在数据库处理, 当前任务完成后会去数据库获取一个任务.
    //当发现当前任务已经超时时, 会重新加载任务.
    //要定时刷新任务配置, 加载任务前要刷新一下配置
    //任务信息刷新还是在服务器进行吧...
    //每当更新进度或者别的什么都要判断下是否需要刷新所有任务

public:
    bool addTask(CTaskPtr t);
    void updateProgress(int32_t tid, int32_t count); //更新数量
    void getAward(int32_t tid);
    CTaskPtr getProcessingTask(int32_t id);
private:
    list<CTaskPtr> processingTasks; //正在处理的任务
    map<int32_t, CTaskPtr> finishedTasks;   //已经完成的任务
    
    list<CTaskPtr> avaliableTasks;  //可接受的任务列表

};