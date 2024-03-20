#ifndef _data_h_
#define _data_h_

typedef struct Passenger { //乘客信息
	int number; //乘客代号
	char name[10]; //乘客姓名
	char ID[20]; //乘客身份证号
	char telephone[15]; //乘客电话号码
	char sex[5]; //乘客性别
	char age[5]; //乘客年龄
}PASSENGER;

typedef struct State{ //乘客涉疫情况
	int number; //乘客代号
	int patient; //确诊情况，0为未确诊，1为无症状，2为有症状
	int contact; //密接情况，0为正常，1为密切接触者
	int deal; //密接处理情况，0为未处理，1为已处理
	int find; //密接联络情况，0为未联络，1为已联络
}STATE;
 
typedef struct Administrator{ //管理员信息
	char unit; //管理员所属单位，1为检测机构，2为卫健委，3为铁路
	char account[9]; //管理员账号 
	char password[9]; //管理员密码 
}ADMINISTRATOR;            

typedef struct User{ //用户信息
    int number; //用户乘客代号
    char ID[20]; //用户身份证号
	char account[15]; //用户账号
	char password[15]; //用户密码
}USER;

typedef struct Record{ //乘车记录
	int contact; //乘车记录代号
	int number; //乘客代号
	int origin; //起始站代号
	int terminal; //终点站代号
	char month[3]; //乘车月
	char day[3]; //乘车日
	char train_number[5]; //车次
	char carriage[3]; //车厢
    char sit[3]; //车座
	struct Record* front; //指向上一个节点的指针
	struct Record* next; //指向下一个节点的指针
}RECORD; 

typedef struct P_record{ //乘车记录扩充版
    int count; //记录当前一共存储了多少次乘车记录
	int r_number; //乘车记录代号
	int number; //乘客代号
	int origin; //起始站代号
	int terminal; //终点站代号
	char name[7]; //乘客姓名
	char telephone[15]; //乘客电话号码
	char age[3]; //乘客年龄
	char sex[3]; //乘客性别
	char month[3]; //乘车月
	char day[3]; //乘车日
	char train_number[5]; //车次
	char carriage[3]; //车厢
    char sit[3]; //车座
	struct P_record* front; //指向上一个节点的指针
	struct P_record* next; //指向下一个节点的指针
}P_RECORD; 

typedef struct R_state{
	int number; //乘车记录代号
	int contact; //乘车记录密接情况，0为正常，1为密接
}R_STATE;

typedef struct Station{ //列车站点信息
	int off; //站点停运代号
	int state; //站点停运情况
	int time; //站点位置
	int number; //站点代号
    int stop; //列车在该站是否停靠，是为1，否为0，起点站为2，终点站为3  
    char name[5]; //站点名 
    char hour[3]; //到站时
    char minute[3]; //到站分
	struct Station* front; //指向上一个节点的指针
    struct Station* next; //指向下一个节点的结构指针
}STATION; 

typedef struct Train{ //列车信息
	int origin; //列车起始站
	int terminal; //列车终点站
	char number[5]; //列车车次
	char month[3]; //列车月
	char day[3]; //列车日
	char carriage[3]; //列车车厢
    char sit[3]; //列车车座
	struct Train* front; //指向上一个节点的指针
	struct Train* next; //指向下一个节点的结构指针
}TRAIN;

typedef struct Off{ //站点停运情况
	int number; //站点代号
	int off; //站点停运情况，0为未停运，1为已停运
}OFF;

typedef struct City{ //城市信息
	int number; //城市代号
	char patient[4]; //患者人数
	int risk; //风险级别，1为低风险，2为中风险，3为高风险 
}CITY;


typedef struct Patient{ //确诊乘客信息
    int patient; //乘客确诊类型，1为无症状，2为有症状
	int number; //乘客代号
	int count; //确诊乘客中的序号
	char name[10]; //乘客姓名
	char ID[20]; //乘客身份证号
	char telephone[15]; //乘客电话号码
	char sex[5]; //乘客性别
	char age[5];//乘客年龄
	struct Patient* front; //指向上一个节点的指针           
	struct Patient* next; //指向下一个节点的指针
}PATIENT;

typedef struct Contact{ //密切接触者乘客信息
    int r_number; //乘车记录代号
	int number; //乘客代号
	int count; //乘客在密切接触者中的序号
	char train_number[5]; //同乘车次
	char carriage[3];
	char sit[3];
	char name[10]; //乘客姓名
	char ID[20]; //乘客身份证号
	char telephone[15]; //乘客电话号码
	char sex[5]; //乘客性别
	char age[5]; //乘客年龄
}CONTACT;

#endif   