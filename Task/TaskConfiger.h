#pragma once
#include "stdafx.h"

#include "stdint.h"

#include <memory>



enum TASK_TYPE //任务类型
{
    TASK_TYPE_REACH_COUNT = 0x100,  //某次数值达到某个点
    TASK_TYPE_ACCUMULATE = 0x101,       //累计达到某点
    TASK_TYPE_SERIAL_TOTAL = 0x102,     //不中断的累计, 中断后清零
    TASK_TYPE_CARD_TYPE = 0x103,        //拥有某些卡牌或者达成某些条件 //和 card_name 对应
    TASK_TYPE_HAVE_CARD = 0x104,        //拥有某些卡牌或者达成某些条件 //和 hand_card 对应

};

class CTaskConfiger
{
public:
    CTaskConfiger(TASK_TYPE tp):type(tp){ }
    virtual ~CTaskConfiger();
    virtual void loadConfig();
    TASK_TYPE getType(){ return type; }

public:
    CTaskConfiger(const CTaskConfiger& /*rsh*/) = delete; //配置信息禁止拷贝构造
    CTaskConfiger& operator=(const CTaskConfiger& /*rsh*/) = delete; //禁止拷贝赋值


private:
    TASK_TYPE type;//任务类型 //1 每日任务, 2 每周任务, 3 成就任务
    int32_t group; //所属组别 
    int32_t idx;   //在组内的索引 //任务所需条件数量和idx正相关
    int32_t id;    //任务id     //任务的唯一id 
    int32_t preTaskID; //前置任务 //当前任务的前置任务id 
    int32_t nextTaskID; //后置任务 //当前任务完成后会开启哪个任务 
    //int64_t expireSec;  //多少秒过期, 0表示不过期  //这个写在具体的任务里面吧
};

using CTaskConfigerPtr = std::shared_ptr<CTaskConfiger>;
