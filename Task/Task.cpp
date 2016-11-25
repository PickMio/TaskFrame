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
    m_ID = 0;

}

void CTask::setTaskData(shared_ptr<CTaskData> tdata)
{
    this->status = TASK_PROGRESS_ACCEPT;
    this->data = tdata;
    this->status = TASK_PROGRESS_PROCESSING;

}

//��ѯ�����Ƿ���ɲ��ı�����״̬ 
bool CTask::hasFinished()
{
    bool ret = false;
    if (TASK_PROGRESS_PROCESSING != this->status && 
        TASK_PROGRESS_FINISHED != this->status){
        //����״̬���� 
        return ret;
    }

    if (TASK_PROGRESS_FINISHED == this->status){
        ret = true;
        return ret;
    }

    if (nullptr == this->data.get())
    {
        // �������
        return ret;
    }

    ret = this->data.get()->hasFinished();

    return ret;

}

void CTask::addProgress(int32_t count)
{
    if ( TASK_PROGRESS_PROCESSING != this->status ){
        //����״̬����
        return; 
    }
    auto tdata = data.get();
    if ( nullptr == tdata ) {
        //�������, ��ǰ��������û�� 
    }
    tdata->addProgress( count );

    if ( this->hasFinished() ){
        this->status = TASK_PROGRESS_FINISHED;
    }
}

int32_t CTask::getTaskID()
{
    return m_ID;

}

