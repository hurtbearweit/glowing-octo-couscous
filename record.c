#include"public.h"
#include"pass.h"
#include"track.h"
#include"record.h"

/************************************************************************
FUNCTION:Record
DESCRIPTION:查看乘客乘车记录
INPUT:界面跳转控制变量page，乘客代号identity
RETURN:无
************************************************************************/
void Record(int* page,int identity)
{
	int i; //标记当前所读乘车记录
	int amount; //记录乘车记录总数
	int flag=0; //标记点亮情况
	int tag=0; //标记乘客状态，0为正常，1为密接，2为确诊
	RECORD R[6]; //记录乘客乘车记录的链表表头
	
	clrmous(MouseX, MouseY);
	delay(100);
    save_bk_mou(MouseX, MouseY);
    cleardevice();
	Draw_Record();
	amount=Record_Get(identity,R);
	i=0;
	Show_Record(R[i]);
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 81 && MouseX < 183 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(81, 358, 183, 419) == 2)//查看上一条未点击
			{
				MouseS = 1;
				if (flag==0)//防止被重复标亮
				{
					Pass_Lighten(2);
					flag= 2;
				}
				continue;
			}
			else if (mouse_press(81, 358, 183, 419) == 1)//查看上一条框点击
			{
				MouseS = 0;
				Pass_Lighten(2);
				if(i==0)
				{
					setfillstyle(1, WHITE);
		            bar(81.72, 358.75, 81.72 + 101, 358.75 + 60.5);
		            highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
		            puthz(102,380, "暂无更多",16,16,RED);
		            delay(3000);
				}
				else
				{
					i--;
					Show_Record(R[i]);
				}
				delay(100);
				continue;
			}
		}
		if (MouseX > 226 && MouseX < 413 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(226, 358, 413, 419) == 2)   //显示轨迹未点击
			{
				MouseS = 1;
				if (flag==0)//防止被重复标亮
				{
					Pass_Lighten(3);
					flag=3;
				}
				continue;
			}
			else if (mouse_press(226, 358, 413, 419) == 1)//显示轨迹点击
			{
				MouseS = 0;
				Pass_Lighten(3);
				Track(R[i]);
				clrmous(MouseX, MouseY);
	            delay(100);
                save_bk_mou(MouseX, MouseY);
                cleardevice();
	            Draw_Record();
	            Show_Record(R[i]);
				continue;
			}
		}
		if (MouseX > 459 && MouseX < 561 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(459, 358, 561, 419) == 2)//下一条未点击
			{
				MouseS = 1;
				if (flag==0)//防止被重复标亮
				{
					Pass_Lighten(4);
					flag=4;
				}
				continue;
			}
			else if (mouse_press(459, 358, 561, 419) == 1)//下一条点击
			{
				MouseS = 0;
				Pass_Lighten(4);
				if(i==amount-1)
				{
					setfillstyle(1, WHITE);
		            bar(459.75, 358.75, 459.75 + 101, 358.75 + 60.5);
		            highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
		            puthz(480, 380, "暂无更多", 16, 16, RED);
		            delay(3000);
				}
				else
				{
					i++;
					Show_Record(R[i]);
				}
				delay(100);
			}
		}
		//465,14,570,34
		if (MouseX > 465 && MouseX < 570 && MouseY> 14 && MouseY < 34)
		{
			if (mouse_press(465, 14, 570, 34) == 2)//点击退出未点击
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(465, 14, 570, 34) == 1)//点击退出点击
			{
				MouseS=0;
				*page=5;
				break;
				//切换到乘客登录界面
			}
		}
		if (flag!=0)
		{
			MouseS = 0;
			if (flag== 2)
			{
				Pass_Darken(2);
			}
			if (flag== 3)
			{
				Pass_Darken(3);
			}
			if (flag == 4)
			{
				Pass_Darken(4);
			}
			flag=0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/************************************************************************
FUNCTION:Record_Get
DESCRIPTION:获取乘客乘车记录
INPUT:乘客代号n,存储乘客乘车记录的结构体数组
RETURN:无
************************************************************************/
int Record_Get(int n,struct Record* R)
{
	int flag=0;
	FILE* fp;
	int i=0;
	int amount=0;
	RECORD* r; //临时存储乘车记录
	
	if ((fp = fopen(".\\TEXT\\record.dat", "rb+")) == NULL) //打开文件
	{
		printf("\nError on open record.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_SET);
	while(!feof(fp))
	{
		if((r=(RECORD*)malloc(sizeof(RECORD)))==NULL) //分配空间             
	    {
		    printf("\nMemory not enough!");
            delay(3000);
			exit(1);
	    } 
		fscanf(fp,"%d",&r->contact); //读一次乘车记录
		if(r->contact==-1)
		{
			break;
		}
		getc(fp);
		fscanf(fp,"%d",&r->number);
		getc(fp);
		fscanf(fp,"%s",r->month);
		getc(fp);
		fscanf(fp,"%s",r->day);
		getc(fp);
		fscanf(fp,"%s",r->train_number);
		fgetc(fp);
		fscanf(fp,"%s",r->carriage);
		fgetc(fp);
		fscanf(fp,"%s",r->sit);
		fgetc(fp);
		fscanf(fp,"%d",&r->origin);
		fgetc(fp);
		fscanf(fp,"%d",&r->terminal);
		fgetc(fp);
		if(n==r->number) //读到当前乘客的乘车记录
		{
			flag==1; //标记已经找到当前乘客乘车记录
			R->contact=r->contact;
			R->number=r->number;
			strcpy(R->month,r->month);
			strcpy(R->day,r->day);
			strcpy(R->train_number,r->train_number);
			strcpy(R->carriage,r->carriage);
			strcpy(R->sit,r->sit);
			R->origin=r->origin;
			R->terminal=r->terminal;
			amount++;
			R++;
		}
        if(r!=NULL)
		{
			free(r);
			r=NULL;
	    }
		if(n!=r->number&&flag==1)
		{
			break;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close record.dat!");
		delay(3000);
		exit(1);
	}
	return amount;
}

/************************************************************************
FUNCTION:Draw_Record
DESCRIPTION:绘制查看乘客乘车记录界面
INPUT:无
RETURN:无
************************************************************************/
int Draw_Record()
{
	int i; //for语句辅助参数	
	int a = 2;
	int mainhzcolor = BLUE;
	int framecolor = CYAN;
	int fillcolor = LIGHTGRAY;
	int buttoncolor = LIGHTRED;
	int textstyle = 3;
	
	cleardevice();
    cover(0, 0, 639, 479, WHITE);
	puthz(242.38, 13.25, "本次乘车记录", 24, 25.5, mainhzcolor);
	stared(29, 12, 10);
	stayellow(29, 46, 10);
	stagreen(29, 80.5, 10);
	stared(589.5, 12, 10);
	stayellow(589.5, 46, 10);
	stagreen(589.5, 80.5, 10);
	cover(229.5, 100.5, 229.5 + 148, 100.5 + 10, fillcolor);
	highlight(229.5, 100.5, 229.5 + 148, 100.5 + 10, BLACK);
	draw_exit(470, 17, WHITE, BLUE, GREEN, LIGHTGREEN);
	Fill_Triangle(376.5, 89.66, 376.5, 89.66 + 34, 376.5 + 31, 89.66 + 17, LIGHTGRAY);
	triangle(376.5, 89.66, 376.5, 89.66 + 34, 376.5 + 31, 89.66 + 17, BLACK);
	cover(79.5, 67.5, 79.5 + 139, 67.5 + 63, fillcolor);
	highlight(79.5, 67.5, 79.5 + 139, 67.5 + 63, YELLOW);
	cover(419.5, 67.5, 419.5 + 139, 67.5 + 63, fillcolor);
	highlight(419.5, 67.5, 419.5 + 139, 67.5 + 63, YELLOW);
	setcolor(mainhzcolor);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 4);
	DOThighlight(90.5, 139.5, 90.5 + 118, 139.5 + 36, framecolor);
	setcolor(mainhzcolor);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	outtextxy(134.76, 142, " : ");
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	DOThighlight(435.5, 139.5, 435.5 + 118, 139.5 + 36, framecolor);
	setcolor(mainhzcolor);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	outtextxy(481.26, 142, " : ");
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	/*date*/
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	setcolor(mainhzcolor);
	puthz(139, 211, "年", 24, 24, mainhzcolor);
	puthz(202, 211, "月", 24, 24, mainhzcolor);
	puthz(260, 211, "日", 24, 24, mainhzcolor);
	/*Seat*/
	cover(455.88, 205.88, 455.88 + 31.25, 205.88 + 31.25, fillcolor);
	cover(538.5, 205.88, 538.5 + 31.25, 205.88 + 31.25, fillcolor);
	setcolor(LIGHTCYAN);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	rectangle(455.88, 205.88, 455.88 + 31.25, 205.88 + 31.25);
	rectangle(538.5, 205.88, 538.5 + 31.25, 205.88 + 31.25);
	puthz(461, 210, "车", 24, 24, mainhzcolor);
	puthz(542, 210, "座", 24, 24, mainhzcolor);
	setcolor(mainhzcolor);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
	puthz(96, 377, "上一条", 24, 24.5, buttoncolor);
	highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
	puthz(247, 376.75, "查看乘车轨迹", 24, 24.5, buttoncolor);
	highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
	puthz(475.88, 377, "下一条", 24, 24.5, buttoncolor);
}

/************************************************************************
FUNCTION:Draw_Remind
DESCRIPTION:绘制乘车记录界面提醒
INPUT:乘客状态tag
RETURN:无
************************************************************************/
int Draw_Remind(int tag)
{
	int i; //for语句辅助参数	
	int a = 2;
	int mainhzcolor = BLUE;
	int framecolor = CYAN;
	int fillcolor = LIGHTGRAY;
	int buttoncolor = LIGHTRED;
	int textstyle = 3;
	if (tag==0)
	{
		DOThighlight(181.5, 252.5, 181.5 + 274, 252.5 + 74, LIGHTGREEN);
		puthz(252.38, 263.21, "暂无异常", 32, 34, LIGHTGREEN);
		puthz(186.5, 300.13, "本次乘车未接触确诊乘客", 24, 24, mainhzcolor);
		cover(624.5, 157.5, 639, 157.5 + 144, LIGHTGREEN);
		highlight(624.5, 157.5, 639, 157.5 + 144, GREEN);
		cover(0, 157.5, 14.5, 157.5 + 144, LIGHTGREEN);
		highlight(0, 157.5, 14.5, 157.5 + 144, GREEN);
		cover(0, 438.88, 639, 479, framecolor);
		puthz(132.66, 446.13, "出行请做好个人防护，祝您旅途愉快", 24, 25.5, mainhzcolor);
	}
	else if(tag==1)
	{
		DOThighlight(181.5, 252.5, 181.5 + 274, 252.5 + 74, RED);
		puthz(252.38, 263.21, "出现异常", 32, 34, RED);
		puthz(186.5, 300.13, "本次乘车已接触确诊乘客", 24, 24, mainhzcolor);
		cover(624.5, 157.5, 639, 157.5 + 144, MAGENTA);
		highlight(624.5, 157.5, 639, 157.5 + 144, RED);
		cover(0, 157.5, 14.5, 157.5 + 144, MAGENTA);
		highlight(0, 157.5, 14.5, 157.5 + 144, RED);
		cover(0, 438.88, 639, 479, framecolor);
		puthz(132.66, 446.13, "请随时与卫健委保持联系，谢谢您！", 24, 25.5, mainhzcolor);
	}
	else
	{
		DOThighlight(181.5, 252.5, 181.5 + 274, 252.5 + 74, RED);
		puthz(252.38, 263.21, "出现异常", 32, 34, RED);
		puthz(186.5+24, 300.13, "已被确诊为新冠肺炎", 24, 24, mainhzcolor);
		cover(624.5, 157.5, 639, 157.5 + 144, MAGENTA);
		highlight(624.5, 157.5, 639, 157.5 + 144, RED);
		cover(0, 157.5, 14.5, 157.5 + 144, MAGENTA);
		highlight(0, 157.5, 14.5, 157.5 + 144, RED);
		cover(0, 438.88, 639, 479, framecolor);
		puthz(132.66, 446.13, "请随时与卫健委保持联系，谢谢您！", 24, 25.5, mainhzcolor);
	}
}

/************************************************************************
FUNCTION:Record_Tag
DESCRIPTION:获取乘客状态
INPUT:乘车记录代号代号n
RETURN:乘客状态flag
************************************************************************/
int Record_Tag(int pn,int rn)
{
	int l;
	int i;
	int flag=0; //记录乘客情况
	FILE* fp;
	STATE* ss=NULL;
	R_STATE* s=NULL;
	if ((fp=fopen(".\\TEXT\\r_state.dat","rb+"))==NULL)
	{
		printf("\nError on open file r_state.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                            //文件指针定位到最后一位
	l=ftell(fp)/sizeof(R_STATE);                                      
	for(i=0;i<l;i++)
	{
		if((s=(R_STATE*)malloc(sizeof(R_STATE)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
		    exit(1);
		}
		fseek(fp,i*sizeof(R_STATE),SEEK_SET);                           
		fread(s,sizeof(R_STATE),1,fp);                                 
		if(rn==s->number) //在文件中查询到对应乘客                                  
		{
			if(s->contact==1) //该次乘车记录被标记为密接
			{
				flag=1;
            }
			else //乘客处于正常状态
			{
				flag=0;
			}		
			if(s!=NULL)                                              //释放内存
			{
				free(s);
				s=NULL;
			}
			break;
		}
		if(s!=NULL)                                              //释放内存
		{
			free(s);
			s=NULL;
		}
	}
	if(fclose(fp)!=0)
	{
		printf("\nError on close r_state.dat!");
		delay(3000);
		exit(1);
	}
	if ((fp=fopen(".\\TEXT\\state.dat","rb+"))==NULL)
	{
		printf("\nError on open file state.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                            //文件指针定位到最后一位
	l=ftell(fp)/sizeof(STATE);                                      
	for(i=0;i<l;i++)
	{
		if((ss=(STATE*)malloc(sizeof(STATE)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
		    exit(1);
		}
		fseek(fp,i*sizeof(STATE),SEEK_SET);                           
		fread(ss,sizeof(STATE),1,fp);                                 
		if(pn==ss->number) //从文件中获取该乘客的相关信息                                
		{			
		    if(ss->patient!=0)
			{
				flag=2;
			    if(ss!=NULL)                                              //释放内存
		        {
			        free(ss);
			        ss=NULL;
		        }
			    break;
			}
		}
		if(ss!=NULL)                                              //释放内存
		{
			free(ss);
			ss=NULL;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
	return flag;
}

/************************************************************************
FUNCTION:Show_Record
DESCRIPTION:显示乘车记录
INPUT:存储乘车记录的机构体r
RETURN:无
************************************************************************/
int Show_Record(struct Record r)
{
	int mainhzcolor = BLUE;
	int framecolor = CYAN;
	int fillcolor = LIGHTGRAY;
	int buttoncolor = LIGHTRED;
	int textstyle = 3;
	int tag; //用于当前乘车记录的密接情况
	char hour1[3]={"\0"} ;//记录出发时
	char hour2[3]={"\0"} ;//记录到达时
	char min1[3]={"\0"} ;//记录出发分
	char min2[3]={"\0"} ;//记录到达分
	FILE* fp;
	char str1[40] = ".\\TEXT\\TRAIN\\";
	char str2[10] = ".dat";
	STATION* t;
	strcat(str1, r.train_number);  //赋值
	strcat(str1, str2);
	if ((fp = fopen(str1, "rb+")) == NULL) 
	{
		printf("\nError on open file train.dat!");
		delay(3000);
		exit(1);
	}
	while (!feof(fp))
	{
		if ((t=(STATION*)malloc(sizeof(STATION))) == NULL)
		{
			printf("Memory is over!\n");
			return 0;
		}
		fscanf(fp,"%d",&t->off);
		fgetc(fp);
		if(t->off==-1)
		{
			break;
		}
		fscanf(fp,"%d",&t->time);
		fgetc(fp);
		fscanf(fp,"%d",&t->number);
		fgetc(fp);
		fscanf(fp,"%s",t->name);
		fgetc(fp);
		fscanf(fp,"%d",&t->stop);
		getc(fp);
		fscanf(fp,"%s",t->hour);
		fgetc(fp);
		fscanf(fp,"%s",t->minute);
		fgetc(fp);
		if(t->number==r.origin)
		{
			strcpy(hour1,t->hour);
			strcpy(min1,t->minute);
		}
		else if(t->number==r.terminal)
		{
			strcpy(hour2,t->hour);
			strcpy(min2,t->minute);
		}
		if(t!=NULL)
		{
			free(t);
			t=NULL;
		}
	}
	if(fclose(fp)!=0)
	{
		printf("\nError on close train.dat!");
		delay(3000);
		exit(1);
	}
	
	setfillstyle(1,WHITE); //遮盖之前显示的信息
	bar(227,206,255,240);
	bar(179,206,200,240);
	bar(435,205,450,240);
	bar(500,205,530,240);
	bar(180, 250, 180 + 278, 252.5 + 76);
	bar(280,64,330,97);
	bar(435.5, 139.5, 435.5 + 118, 139.5 + 36);
	bar(90.5, 139.5, 90.5 + 118, 139.5 + 36);
	
	cover(79.5, 67.5, 79.5 + 139, 67.5 + 63, fillcolor); //遮盖之前显示的信息
	highlight(79.5, 67.5, 79.5 + 139, 67.5 + 63, YELLOW);
	cover(419.5, 67.5, 419.5 + 139, 67.5 + 63, fillcolor);
	highlight(419.5, 67.5, 419.5 + 139, 67.5 + 63, YELLOW);
	
	tag=Record_Tag(r.number,r.contact);
	Draw_Remind(tag);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	setcolor(BLACK);
	Pass_City_Show(101, 75, r.origin, 48, 51, mainhzcolor);
	Pass_City_Show(442.5, 75, r.terminal, 48, 51, mainhzcolor);
	if(strlen(r.train_number)==2)
	{
		outtextxy(295, 65, r.train_number);
	}
	else
	{
		outtextxy(284, 65, r.train_number);
	}
	outtextxy(71, 206, "2021");
	outtextxy(179, 206, r.month);
	outtextxy(227, 206, r.day);
	outtextxy(435, 205, r.carriage);
	outtextxy(500, 205, r.sit);
	outtextxy(106.76, 142, hour1);
	outtextxy(165.16, 142, min1);
	outtextxy(449.26, 142, hour2);
	outtextxy(512.26, 142, hour2);
	outtextxy(134.76, 140, " : ");
	outtextxy(481.26, 140, " : ");
}