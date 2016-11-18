#include "stdafx.h"
#include "TaskConfiger.h"
class ReachCountTaskConfiger 
    : public CTaskConfiger
{
public:
    ReachCountTaskConfiger() : CTaskConfiger(TASK_TYPE_REACH_COUNT){}
    ~ReachCountTaskConfiger() override;
public:
    void loadConfig() override;


};