#pragma once
#include "stdafx.h"
#include <time.h>
#include <memory>

#include "TaskConfiger.h"


class CTaskData
{
public:
    CTaskData(TASK_TYPE tp);
    virtual ~CTaskData();

public:
    virtual void addProgress(int32_t count) = 0;
    virtual void reset() = 0;

    virtual bool hasFinished() = 0;


protected:
    std::shared_ptr<CTaskConfiger> configer;

private:
    TASK_TYPE type;
    int32_t    id;        //任务id 
    int64_t   takeTimeStamp;  //接任务的时间戳

    //time 这个函数是根据系统的字节长来判断的


};
