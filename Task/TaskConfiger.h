#include "stdafx.h"

#include "stdint.h"



enum TASK_TYPE //任务类型
{
    TASK_TYPE_REACH_COUNT = 1,  //某次数值达到某个点
    TASK_TYPE_ACCUMULATE,       //累计达到某点
    TASK_TYPE_SERIAL_TOTAL,     //不中断的累计, 中断后清零
    TASK_TYPE_HAVE_CARD,        //拥有某些卡牌或者达成某些条件

};

class CTaskConfiger
{
public:
    CTaskConfiger(TASK_TYPE tp):type(tp){ };
    virtual ~CTaskConfiger();
    virtual void loadConfig();
    TASK_TYPE getType(){ return type; };

public:
    CTaskConfiger(const CTaskConfiger& /*rsh*/) = delete; //配置信息禁止拷贝构造
    CTaskConfiger& operator=(const CTaskConfiger& /*rsh*/) = delete; //禁止拷贝赋值


private:
    TASK_TYPE type;//任务类型
    int32_t group; //所属组别
    int32_t idx;   //在组内的索引
};