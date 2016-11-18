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

public:
    bool addTask(int32_t id);
    void updateProgress(int32_t tid, int32_t count); //��������
    void finishTask(int32_t tid);
    void getAward(int32_t tid);

private:
    map<int32_t, shared_ptr<CTask>> processingTasks; //���ڴ��������
    map<int32_t, shared_ptr<CTask>> finishedTasks;   //�Ѿ���ɵ�����
    
    list<shared_ptr<CTask>> avaliableTasks;  //�ɽ��ܵ������б�



};