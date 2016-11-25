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

    //�����ˢ��, ��ʱ�������ݿ⴦��, ��ǰ������ɺ��ȥ���ݿ��ȡһ������.
    //�����ֵ�ǰ�����Ѿ���ʱʱ, �����¼�������.
    //Ҫ��ʱˢ����������, ��������ǰҪˢ��һ������
    //������Ϣˢ�»����ڷ��������а�...
    //ÿ�����½��Ȼ��߱��ʲô��Ҫ�ж����Ƿ���Ҫˢ����������

public:
    bool addTask(CTaskPtr t);
    void updateProgress(int32_t tid, int32_t count); //��������
    void getAward(int32_t tid);
    CTaskPtr getProcessingTask(int32_t id);
private:
    list<CTaskPtr> processingTasks; //���ڴ��������
    map<int32_t, CTaskPtr> finishedTasks;   //�Ѿ���ɵ�����
    
    list<CTaskPtr> avaliableTasks;  //�ɽ��ܵ������б�

};