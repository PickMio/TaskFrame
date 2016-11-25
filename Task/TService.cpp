#include "stdafx.h"

#include "TService.h"

TService::TService()
{}

TService::~TService()
{}
bool TService::addTask(CTaskPtr t)
{
    if (getProcessingTask(t.get()->getTaskID())){
        //当前任务在任务列表
        return false;
    }
    processingTasks.push_back(t);

    return true;
}

void TService::updateProgress(int32_t tid, int32_t count)
{
    auto task = this->getProcessingTask(tid);
    if (nullptr == task){
        //没找到当前的任务!!! 严重错误
        return;
    }
    auto taskptr = task.get();
    if (nullptr == taskptr)
    {
        return;
    }
    if (taskptr->hasFinished()){
        //任务已经完成了
        return;
    }
    taskptr->addProgress(count);
}


void TService::getAward(int32_t tid)
{


}

CTaskPtr TService::getProcessingTask(int32_t id)
{
    for (auto it = processingTasks.begin(); it != processingTasks.end(); ++it){
        if (it->get()->getTaskID() == id){
            return (*it);
        }
    }
    return nullptr;

}