#pragma once
#include "CTaskData.h"
#include "ReachCountTaskConfiger.h"

class ReachCountTaskData
    : public CTaskData
{
public:
    ReachCountTaskData();
    ~ReachCountTaskData();

public:
    bool hasFinished();
    void addProgress(int32_t count);
    void reset();

    
private:
    int32_t curCount;  //当前达到的最大数量
    


};