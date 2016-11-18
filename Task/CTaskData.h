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
    int32_t    id;        //����id 
    int64_t   takeTimeStamp;  //�������ʱ���

    //time ��������Ǹ���ϵͳ���ֽڳ����жϵ�


};
