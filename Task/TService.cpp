#include "stdafx.h"

#include "TService.h"

bool TService::addTask(int32_t id)
{

    return false;
}

void TService::updateProgress(int32_t tid, int32_t count)
{
    auto tpair = processingTasks.find(tid);
    if (tpair == processingTasks.end()){
        //û�ҵ���ǰ������!!! ���ش���
        return;
    }
}

void TService::finishTask(int32_t tid)
{

}


void TService::getAward(int32_t tid)
{


}