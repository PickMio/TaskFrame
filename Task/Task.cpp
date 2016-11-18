// Task.cpp : �������̨Ӧ�ó������ڵ㡣
//


// ���ʵ��һ������ָ���task
#include "stdafx.h"

#include "Task.h"

CTask::~CTask()
{

}

CTask::CTask()
{
    status = TASK_PROGRESS_NONE;

}

void CTask::setTaskData(shared_ptr<CTaskData> tdata)
{
    this->data = tdata;

}

bool CTask::hasFinished()
{
    bool ret = false;
    if (TASK_PROGRESS_PROCESSING != this->status || 
        TASK_PROGRESS_FINISHED != this->status){
        //����״̬���� 
        return ret;
    }

    if (TASK_PROGRESS_FINISHED == this->status){
        ret = true;
        return ret;
    }

    if (nullptr == this->data->get())
    {
        // �������
        return ret;
    }

    ret = this->data.get()->hasFinished();
    if ( ret ){
        this->status = TASK_PROGRESS_FINISHED;
    }

    return ret;

}

void CTask::addProgress(int32_t count)
{
    auto tdata = data.get();
    if (nullptr == tdata) {
        //�������, ��ǰ��������û�� 
    }
    tdata->addProgress(count);

}


