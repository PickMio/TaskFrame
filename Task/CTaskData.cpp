#include "stdafx.h"
#include "CTaskData.h"

CTaskData::CTaskData(TASK_TYPE tp) : type(tp)
{
    this->takeTimeStamp = (int64_t)time(nullptr); 
}
CTaskData::~CTaskData()
{
}
