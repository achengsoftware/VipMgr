#ifndef TASKDATA_H
#define TASKDATA_H
#include<string>
enum MGRTYPE{
    MGR_NUMBER,
    MGR_STDFF,
    MGR_GOOGS,
    MSG_CHECK,
    MGR_CONSUMPTION
};
enum TASKTYPE{
    TASK_TYPE_ADD_MEMBER=0,//��ӻ�Ա
    TASK_TYPE_SEARCH_MEMBER,//��ѯ��Ա
    TASK_TYPE_MODIFY_MEMBER,//�༭��Ա
    TASK_TYPE_DEL_MEMBER,//ɾ����Ա

    TASK_TYPE_ADD_STAFF,//���Ա��
    TASK_TYPE_SEARCH_STAFF,//��ѯԱ��
    TASK_TYPE_MODIFY_STAFF,//�༭Ա��
    TASK_TYPE_DEL_STAFF,//ɾ��Ա��

    TASK_TYPE_ADD_WORK_TYPE,//��ӹ���
    TASK_TYPE_SEARCH_WORK_TYPE,//��ѯ����
    TASK_TYPE_MODIFY_WORK_TYPE,//�༭����
    TASK_TYPE_DEL_WORK_TYPE,//ɾ������

    TASK_TYPE_ADD_GOODS,//�����Ʒ
    TASK_TYPE_SEARCH_GOODS,//��ѯ��Ʒ
    TASK_TYPE_MODIFY_GOODS,//�༭��Ʒ
    TASK_TYPE_DEL_GOODS,//ɾ����Ʒ

    TASK_TYPE_VIP_CHECK,//��Ա����
    TASK_TYPE_NOTVIP_CHECK,//�ǻ�Ա����

    TASK_TYPE_VIP_CONSUMPTION,//��Ա���Ѳ�ѯ
    TASK_TYPE_ALL_CONSUMPTION//�������Ѳ�ѯ
};

struct taskInfo{
    TASKTYPE id;
    std::string name;
};

#endif//TASKDATA_H
