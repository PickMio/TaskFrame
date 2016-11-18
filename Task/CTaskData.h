#include "stdafx.h"
#include "TaskConfiger.h"

class CTaskData
{
public:
    CTaskData(TASK_TYPE tp) :type(tp){ resetProgress(); };
    ~CTaskData();

    virtual void addProgress();
    virtual void resetProgress();
private:
    TASK_TYPE type;



};