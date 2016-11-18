#include <map>
#include <vector>
#include <stdint.h>
#include <memory>
using namespace std;

#include "TaskConfiger.h"
#include "CTaskData.h"

enum TASK_PROGRESS
{
    TASK_PROGRESS_NONE = 0,    //任务还没接收
    TASK_PROGRESS_ACCEPT,      //任务刚接收
    TASK_PROGRESS_PROCESS,     //任务处理中
    TASK_PROGRESS_FINISHED,    //任务已经完成, 还么领奖
    TASK_PROGRESS_END,         //已经领奖, 任务终结
    TASK_PROGRESS_REJECTED,   //任务已经拒绝
};

class CTask
{
public:
    CTask();
    ~CTask();

//条件判断
public:
    bool canTake();
    bool isFinish();
    bool canGetAward();
    void setTaskData(shared_ptr<CTaskData> tdata);

private:
    int32_t  m_ID;//任务ID
    shared_ptr<CTaskData> data;  //任务进度 

};