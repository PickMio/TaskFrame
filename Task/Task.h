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
    TASK_PROGRESS_PROCESS,     //��������
    TASK_PROGRESS_FINISHED,    //�����Ѿ����, ��ô�콱
    TASK_PROGRESS_END,         //�Ѿ��콱, �����ս�
    TASK_PROGRESS_REJECTED,   //�����Ѿ��ܾ�
};

class CTask
{
public:
    CTask();
    ~CTask();

//�����ж�
public:
    bool canTake();
    bool isFinish();
    bool canGetAward();
    void setTaskData(shared_ptr<CTaskData> tdata);

private:
    int32_t  m_ID;//����ID
    shared_ptr<CTaskData> data;  //������� 

};