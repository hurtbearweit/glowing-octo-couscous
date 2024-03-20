#ifndef _data_h_
#define _data_h_

typedef struct Passenger { //�˿���Ϣ
	int number; //�˿ʹ���
	char name[10]; //�˿�����
	char ID[20]; //�˿����֤��
	char telephone[15]; //�˿͵绰����
	char sex[5]; //�˿��Ա�
	char age[5]; //�˿�����
}PASSENGER;

typedef struct State{ //�˿��������
	int number; //�˿ʹ���
	int patient; //ȷ�������0Ϊδȷ�1Ϊ��֢״��2Ϊ��֢״
	int contact; //�ܽ������0Ϊ������1Ϊ���нӴ���
	int deal; //�ܽӴ��������0Ϊδ����1Ϊ�Ѵ���
	int find; //�ܽ����������0Ϊδ���磬1Ϊ������
}STATE;
 
typedef struct Administrator{ //����Ա��Ϣ
	char unit; //����Ա������λ��1Ϊ��������2Ϊ����ί��3Ϊ��·
	char account[9]; //����Ա�˺� 
	char password[9]; //����Ա���� 
}ADMINISTRATOR;            

typedef struct User{ //�û���Ϣ
    int number; //�û��˿ʹ���
    char ID[20]; //�û����֤��
	char account[15]; //�û��˺�
	char password[15]; //�û�����
}USER;

typedef struct Record{ //�˳���¼
	int contact; //�˳���¼����
	int number; //�˿ʹ���
	int origin; //��ʼվ����
	int terminal; //�յ�վ����
	char month[3]; //�˳���
	char day[3]; //�˳���
	char train_number[5]; //����
	char carriage[3]; //����
    char sit[3]; //����
	struct Record* front; //ָ����һ���ڵ��ָ��
	struct Record* next; //ָ����һ���ڵ��ָ��
}RECORD; 

typedef struct P_record{ //�˳���¼�����
    int count; //��¼��ǰһ���洢�˶��ٴγ˳���¼
	int r_number; //�˳���¼����
	int number; //�˿ʹ���
	int origin; //��ʼվ����
	int terminal; //�յ�վ����
	char name[7]; //�˿�����
	char telephone[15]; //�˿͵绰����
	char age[3]; //�˿�����
	char sex[3]; //�˿��Ա�
	char month[3]; //�˳���
	char day[3]; //�˳���
	char train_number[5]; //����
	char carriage[3]; //����
    char sit[3]; //����
	struct P_record* front; //ָ����һ���ڵ��ָ��
	struct P_record* next; //ָ����һ���ڵ��ָ��
}P_RECORD; 

typedef struct R_state{
	int number; //�˳���¼����
	int contact; //�˳���¼�ܽ������0Ϊ������1Ϊ�ܽ�
}R_STATE;

typedef struct Station{ //�г�վ����Ϣ
	int off; //վ��ͣ�˴���
	int state; //վ��ͣ�����
	int time; //վ��λ��
	int number; //վ�����
    int stop; //�г��ڸ�վ�Ƿ�ͣ������Ϊ1����Ϊ0�����վΪ2���յ�վΪ3  
    char name[5]; //վ���� 
    char hour[3]; //��վʱ
    char minute[3]; //��վ��
	struct Station* front; //ָ����һ���ڵ��ָ��
    struct Station* next; //ָ����һ���ڵ�Ľṹָ��
}STATION; 

typedef struct Train{ //�г���Ϣ
	int origin; //�г���ʼվ
	int terminal; //�г��յ�վ
	char number[5]; //�г�����
	char month[3]; //�г���
	char day[3]; //�г���
	char carriage[3]; //�г�����
    char sit[3]; //�г�����
	struct Train* front; //ָ����һ���ڵ��ָ��
	struct Train* next; //ָ����һ���ڵ�Ľṹָ��
}TRAIN;

typedef struct Off{ //վ��ͣ�����
	int number; //վ�����
	int off; //վ��ͣ�������0Ϊδͣ�ˣ�1Ϊ��ͣ��
}OFF;

typedef struct City{ //������Ϣ
	int number; //���д���
	char patient[4]; //��������
	int risk; //���ռ���1Ϊ�ͷ��գ�2Ϊ�з��գ�3Ϊ�߷��� 
}CITY;


typedef struct Patient{ //ȷ��˿���Ϣ
    int patient; //�˿�ȷ�����ͣ�1Ϊ��֢״��2Ϊ��֢״
	int number; //�˿ʹ���
	int count; //ȷ��˿��е����
	char name[10]; //�˿�����
	char ID[20]; //�˿����֤��
	char telephone[15]; //�˿͵绰����
	char sex[5]; //�˿��Ա�
	char age[5];//�˿�����
	struct Patient* front; //ָ����һ���ڵ��ָ��           
	struct Patient* next; //ָ����һ���ڵ��ָ��
}PATIENT;

typedef struct Contact{ //���нӴ��߳˿���Ϣ
    int r_number; //�˳���¼����
	int number; //�˿ʹ���
	int count; //�˿������нӴ����е����
	char train_number[5]; //ͬ�˳���
	char carriage[3];
	char sit[3];
	char name[10]; //�˿�����
	char ID[20]; //�˿����֤��
	char telephone[15]; //�˿͵绰����
	char sex[5]; //�˿��Ա�
	char age[5]; //�˿�����
}CONTACT;

#endif   