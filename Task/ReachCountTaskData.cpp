#pragma once
#include "stdafx.h"

#include "ReachCountTaskData.h"

ReachCountTaskData::ReachCountTaskData() :CTaskData(TASK_TYPE_REACH_COUNT)
{


}

ReachCountTaskData::~ReachCountTaskData()
{

}


bool ReachCountTaskData::hasFinished()
{
    bool ret = false;

    auto conf = static_cast<ReachCountTaskConfiger*>(this->configer.get());
    if (nullptr == conf)
    {
        //配置文件出错, 严重问题
        return false;
    }

    if (this->curCount >= conf->getReachCount()){
        ret = true;
    }
    return ret;

}

void ReachCountTaskData::addProgress(int32_t count)
{
    if (this->curCount > count){
        return;
    }

    this->curCount = count;
    
}

void ReachCountTaskData::reset()
{
    this->curCount = 0;

}