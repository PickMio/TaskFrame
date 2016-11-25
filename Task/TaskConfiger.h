#pragma once
#include "stdafx.h"

#include "stdint.h"

#include <memory>



enum TASK_TYPE //��������
{
    TASK_TYPE_REACH_COUNT = 0x100,  //ĳ����ֵ�ﵽĳ����
    TASK_TYPE_ACCUMULATE = 0x101,       //�ۼƴﵽĳ��
    TASK_TYPE_SERIAL_TOTAL = 0x102,     //���жϵ��ۼ�, �жϺ�����
    TASK_TYPE_CARD_TYPE = 0x103,        //ӵ��ĳЩ���ƻ��ߴ��ĳЩ���� //�� card_name ��Ӧ
    TASK_TYPE_HAVE_CARD = 0x104,        //ӵ��ĳЩ���ƻ��ߴ��ĳЩ���� //�� hand_card ��Ӧ

};

class CTaskConfiger
{
public:
    CTaskConfiger(TASK_TYPE tp):type(tp){ }
    virtual ~CTaskConfiger();
    virtual void loadConfig();
    TASK_TYPE getType(){ return type; }

public:
    CTaskConfiger(const CTaskConfiger& /*rsh*/) = delete; //������Ϣ��ֹ��������
    CTaskConfiger& operator=(const CTaskConfiger& /*rsh*/) = delete; //��ֹ������ֵ


private:
    TASK_TYPE type;//�������� //1 ÿ������, 2 ÿ������, 3 �ɾ�����
    int32_t group; //������� 
    int32_t idx;   //�����ڵ����� //������������������idx�����
    int32_t id;    //����id     //�����Ψһid 
    int32_t preTaskID; //ǰ������ //��ǰ�����ǰ������id 
    int32_t nextTaskID; //�������� //��ǰ������ɺ�Ὺ���ĸ����� 
    //int64_t expireSec;  //���������, 0��ʾ������  //���д�ھ�������������
};

using CTaskConfigerPtr = std::shared_ptr<CTaskConfiger>;
