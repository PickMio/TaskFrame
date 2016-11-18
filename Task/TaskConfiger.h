#include "stdafx.h"

#include "stdint.h"



enum TASK_TYPE //��������
{
    TASK_TYPE_REACH_COUNT = 1,  //ĳ����ֵ�ﵽĳ����
    TASK_TYPE_ACCUMULATE,       //�ۼƴﵽĳ��
    TASK_TYPE_SERIAL_TOTAL,     //���жϵ��ۼ�, �жϺ�����
    TASK_TYPE_HAVE_CARD,        //ӵ��ĳЩ���ƻ��ߴ��ĳЩ����

};

class CTaskConfiger
{
public:
    CTaskConfiger(TASK_TYPE tp):type(tp){ };
    virtual ~CTaskConfiger();
    virtual void loadConfig();
    TASK_TYPE getType(){ return type; };

public:
    CTaskConfiger(const CTaskConfiger& /*rsh*/) = delete; //������Ϣ��ֹ��������
    CTaskConfiger& operator=(const CTaskConfiger& /*rsh*/) = delete; //��ֹ������ֵ


private:
    TASK_TYPE type;//��������
    int32_t group; //�������
    int32_t idx;   //�����ڵ�����
};