#pragma once
#include <map>
#include <vector>
#include <stdint.h>
#include <memory>
using namespace std;

#include "TaskConfiger.h"
#include "CTaskData.h"
enum TASK_PROGRESS
{
    TASK_PROGRESS_NONE = 0,    //����û����
    TASK_PROGRESS_ACCEPT,      //����ս���
    TASK_PROGRESS_PROCESSING,     //��������
    TASK_PROGRESS_FINISHED,    //�����Ѿ����, ��ô�콱
    TASK_PROGRESS_END,         //�Ѿ��콱, �����ս�
    TASK_PROGRESS_REJECTED,   //�����Ѿ��ܾ�
};

//��ҪΪCTask ����һ��������, ��������ʼ��һЩ����
class CTask
{
public:
    CTask();
    ~CTask();

//�����ж�
public:
    bool hasFinished();
    void setTaskData(CTaskDataPtr tdata);
    void addProgress(int32_t count);
    int32_t getTaskID();

private:
    int32_t  m_ID;//����ID
    CTaskDataPtr data;  //������� 
    TASK_PROGRESS status;

};

using CTaskPtr = shared_ptr<CTask>;