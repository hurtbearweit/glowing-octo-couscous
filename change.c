#include"public.h"
#include"change.h"
/************************************************************************
FUNCTION:Change
DESCRIPTION:完成乘客密码修改
INPUT:界面跳转控制变量page
RETURN:无
************************************************************************/
void Change(int* page)
{
    int pos1=0;                                             //判断输入框1输入情况
	int pos2=0;                                             //判断输入框2输入情况
	int pos3=0;                                             //判断输入框3输入情况
	int pos4=0;                                             //判断输入框4输入情况
	int flag=0;                                             //标记输入框点亮情况，以防重复点亮
	int jun1=0;                                             //判断账号输入结果
	int jun2=0;                                             //判断密码输入结果
	int jun3=0;                                             //判断确认密码输入结果
	int jun4=0;                                             //判断身份证号输入结果
	char A[15]={'\0'};                                      //账号，6-12位
	char I[25]={'\0'};                                      //身份证，18位
	char II[25]={'\0'};                                     //用户账号对应的身份证号
	char P[20]={'\0'};                                      //设置新密码，6-12位
	char RP[20] ={'\0'};                                    //确认密码，6-12位
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Change();                                          //画修改密码界面
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);                   //画鼠标
		if(MouseX>95&&MouseX<545&& MouseY>85&& MouseY<110)  //鼠标进入输入框1的范围
		{
			if(mouse_press(95,85,545,110)==2)               //未点击输入框1
			{
				MouseS=2;                                   //改鼠标为光标形态
				if(flag==0&&pos1==0)                  
				{
					Change_Lighten(95,85,545,110,1);        //点亮输入框1
					flag=1;                                 //标记输入框1已点亮
				}
				continue;
			}

			else if(mouse_press(95,85,545,110) ==1)         //点击输入框1
			{
				MouseS =0;
				Change_Lighten(95,85,545,110,1);
				A[0]='\0';                                  //清空之前的输入
				setfillstyle(1,DARKGRAY);
		        bar(550,90,640,106);
				Input_Vis(A,95,85,12,LIGHTGRAY);            //可视输入
				jun1=C_Account_Jundge(A,II);                //判断账号的注册情况
				if(strlen(A)!= 0)                           //判断是否完成输入
					pos1=1;                                 //完成输入则进行标记
				else
					pos1=0;
				continue;
			}
		}
		if(MouseX>95&& MouseX<545&& MouseY>145&& MouseY< 170)
		{
			if(mouse_press(95,145,545,170)==2)     
			{
				MouseS=2;
				if(flag==0&&pos2==0)
				{
					Change_Lighten(95,145,545,170,2);
					flag=2;
				}
				continue;
			}

			else if(mouse_press(95,145,545,170)==1)     
			{
			    Change_Lighten(95,145,545,170,2);
				MouseS=0;
				P[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,150,640,166);
				Input_Invis(P,95,145,16,LIGHTGRAY);
				jun2=C_Password_Jundge(P);               //判断密码长度是否符合要求
				if(strlen(P)!=0)
					pos2=1;
				else
					pos2=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>205&& MouseY<230)
		{
			if(mouse_press(95,205,545,230) == 2)    
			{
				MouseS=2;
				if(flag==0&&pos3==0)
				{
					Change_Lighten(95,205,545,230,3);
					flag=3;
				}
				continue;
			}

			else if(mouse_press(95,205,545,230)==1)      
			{
				Change_Lighten(95,205,545,230,3);
				MouseS = 0;
				RP[0] ='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,210,640,226);
				Input_Invis(RP,95,205,16,LIGHTGRAY);         //不可视输入
				jun3=C_Password_Same(P,RP);
				if(strlen(RP)!=0)
					pos3=1;
				else
					pos3=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>260&& MouseY<290)
		{
			if(mouse_press(95,265,545,290)==2)      
			{
				MouseS=2;
				if(flag==0&&pos4==0)
				{
					Change_Lighten(95,265,545,290,4);
					flag=4;
				}
				continue;
			}

			else if(mouse_press(95,265,545,290)==1)
			{
				Change_Lighten(95,265,545,290,4);
				MouseS=0;
				I[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				Input_Vis(I,95,265,18,LIGHTGRAY);
				jun4=C_ID_Jundge(I,II);                      //判断身份证是否与账号匹配
				if(strlen(I)!=0)
					pos4=1;
				else 
					pos4=0;
				continue;
			}
		}
		if(MouseX>143&&MouseX<237&&MouseY>370&& MouseY<400)
		{
			if(mouse_press(143,370,237,400)==2)                
			{
				if(flag==0)
				{
					MouseS=1;
					Change_Lighten(143,370,237,400,5);
					flag=5;
				}
				continue;
			}

			else if(mouse_press(143,370,237,400)==1)
			{
				MouseS=0;                        //重置鼠标
				A[0] = '\0';
				I[0] = '\0';
				P[0] = '\0';
				RP[0] = '\0';
				flag=0;                          //重置数据
				pos1 = 0;
				pos2 = 0;
				pos3 = 0;
				pos4 = 0;
				return;
			}
		}

		if(MouseX >273&& MouseX<367&& MouseY>370&& MouseY<400)
		{
			if(mouse_press(273,370,367,400) == 2)					
			{
				if (flag==0)
				{
					MouseS=1;
					Change_Lighten(273,370,367,400,6);
					flag=6;
				}
				continue;
			}

			else if(mouse_press(273,370,367,400)==1)
			{
				MouseS=0;
			if (Change_Com(jun1,jun2,jun3,jun4,A,P))     //完成密码的修改
				{
		            *page=1;
					break;
				}
				else
				{
					return;
				}
			}
		}

		if (MouseX>403&&MouseX<497&&MouseY>370&&MouseY<400)
		{
			if (mouse_press(403, 370, 497, 400) == 2)				
			{
				if (flag==0)
				{
					MouseS=1;
					Change_Lighten(403,370,497,400,7);
					flag=7;
				}
				continue;
			}

		else if(mouse_press(403, 370, 497, 400) == 1)
			{
				MouseS=0;
				*page=1;
				break; 
			}
		}

		if(flag!=0)                                 //根据点亮情况，对输入框进行还原
		{
			MouseS=0;
			if(pos1==0)
			{
				Change_Darken(1);
			}
			if (pos2==0)
			{
				Change_Darken(2);
			}
			if (pos3==0)
			{
				Change_Darken(3);
			}
			if (pos4==0)
			{
				Change_Darken(4);
			}
			if (flag==5||flag ==6||flag ==7)
			{
				Change_Darken(flag);
			}
			flag=0;
		}
		if(MouseS!=0)                               //还原鼠标
		{                 
			MouseS=0;
		}
	}
}

/************************************************************************
FUNCTION:Draw_Change
DESCRIPTION:绘制修改密码界面
INPUT:无
RETURN:无
************************************************************************/
int Draw_Change()
{
    cleardevice();
	setbkcolor(DARKGRAY);                        //设置背景颜色
	
	puthz(255,25,"修改密码",32,32,WHITE);
	puthz(254,24,"修改密码",32,32,RED);
	puthz(175,320,"勿将身份信息透露给他人",24,24,BROWN);
	puthz(95,60,"请输入账号",16,16,CYAN);        //画输入提示
	puthz(95,120,"请输入新密码",16,16,CYAN);
    puthz(95,180,"请确认密码",16,16,CYAN);
    puthz(95,240,"请输入身份证号码",16,16,CYAN);
	
	setviewport(0,0,640,480,1);                  //画小人和身份证
	setfillstyle(1,YELLOW);
	setcolor(YELLOW);
	circle(50,95,30);
	floodfill(50,95,YELLOW);

    setfillstyle(1,BLUE);
	setcolor(BLUE);
	circle(50,275,30);
	floodfill(50,275,BLUE);
	
	setfillstyle(1,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	circle(50,85,10);
	floodfill(50,85,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	line(50,95,34,115);
	line(34,115,66,115);
	line(66,115,50,95);
	floodfill(50,105,LIGHTGRAY);
	
	setfillstyle(1, WHITE);
	setcolor(WHITE);
	rectangle(30,265,70,285);
	floodfill(35,275, WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(45,268,55,271);
	bar(45,273,65,276);
	bar(45,278,65,281);
	
	setfillstyle(1,WHITE);                     
	bar(95,85,545,110);                          //画输入框
    bar(95,145,545,170);
	bar(95,205,545,230);
	bar(95,265,545,290);

	setfillstyle(1,GREEN);
	bar(143, 370, 237, 400);
	puthz(161,373,"重置",24,34,WHITE);           //画操作框
    setfillstyle(1,RED);
	bar(273, 370, 367, 400);
	puthz(291,373,"完成",24,34,WHITE);
    setfillstyle(1,BLUE);
	bar(403, 370, 497, 400);
	puthz(421,373,"返回",24,34,WHITE);
}

/************************************************************************
FUNCTION:Change_Lighten
DESCRIPTION:修改密码界面按钮点亮
INPUT:点亮控制变量flag
RETURN:无
************************************************************************/
int Change_Lighten(int x1,int y1,int x2,int y2,int flag)//点亮操作框
{
	clrmous(MouseX,MouseY);
	delay(10);

	if(flag==5)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,CYAN);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(161,373,"重置",24,34,LIGHTCYAN);
	}
	else if(flag== 6)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,RED);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(291,373,"完成",24,34,LIGHTRED);
	}
	else if(flag==7)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,BLUE);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(421,373,"返回",24,34,LIGHTBLUE);
	}
	else                                       //点亮输入框
	{
		setcolor(MAGENTA);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,LIGHTGRAY);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
	}
}

/************************************************************************
FUNCTION:Change_Darken
DESCRIPTION:卫健委管理员界面按钮恢复
INPUT:恢复控制变量pos
RETURN:无
************************************************************************/
int Change_Darken(int pos)//根据点亮情况，对操作框进行还原
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	switch (pos)
	{
	case 1:                                    //还原输入框
		bar(95,85,545,110);
		break;
	case 2:
		bar(95,145,545,170);
		break;
	case 3:
		bar(95,205,545,230);
		break;
	case 4:
		bar(95,265,545,290);
		break;
	case 5:
		setfillstyle(1,GREEN);
		bar(143,370,237,400);
		puthz(161,373,"重置",24,34,WHITE);
		break;
	case 6:
		setfillstyle(1,RED);
		bar(273,370,367,400);
		puthz(291,373,"完成",24,34,WHITE);
		break;
	case 7:
		setfillstyle(1,BLUE);
		bar(403,370,497,400);
		puthz(421,373,"返回",24,34,WHITE);
		break;
	}
}

/************************************************************************
FUNCTION:C_Account_Jundge
DESCRIPTION:判断输入的账号正确
INPUT:输入的账号A
RETURN:判断结果
************************************************************************/
int C_Account_Jundge(char* A,char* II)
{
	int l;
	int i;
	FILE* fp;
	USER*u=NULL;
	if((fp = fopen(".\\TEXT\\UserData.dat","rb+"))==NULL)//打开存储用户信息的文件
	{
		printf("\nError on close UserData.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                      //文件指针定位到开头
	l=ftell(fp)/sizeof(USER);                                //计算文件中用户个数
	for(i=0;i<l;i++)                                           //变量所有用户
	{
		if((u=(USER*)malloc(sizeof(USER)))==NULL)              //分配空间
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(USER),SEEK_SET);                     //文件指针移动到第i个用户
		fread(u,sizeof(USER),1,fp);                            //读取第i个用户的信息
		if(strcmp(u->account,A)==0)                            //如果与当前用户的账号匹配
		{
			setfillstyle(1,DARKGRAY);
		    bar(550,90,640,106);
		    puthz(550,90,"账号存在",16,16,RED);
			strcpy(II,u->ID);                                  //记录当前用户的身份证号
			if(u != NULL)                                      //释放内存
			{
				free(u);
				u = NULL;
			}
			if(fclose(fp)!= 0)                                 //关闭文件
			{
				printf("\nError on close UserData.dat!");
				delay(3000);
				exit(1);
			}
			return 1;      
	    }
    }
	if(i==l)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,90,640,106);
		puthz(550,90,"账号不存在",16,16,RED);
	    if(u!=NULL)
		{
			free(u);
			u = NULL;
		}
		if(fclose(fp)!= 0)
		{
			printf("\nError on close UserData.dat!");
			delay(3000);
			exit(1);
		}
		return 0;
	}
}


/************************************************************************
FUNCTION:C_ID_Jundge
DESCRIPTION:判断输入的账号和身份证号是否匹配
INPUT:输入的账号对应的身份证号II，输入的身份证号I
RETURN:判断结果
************************************************************************/
int C_ID_Jundge(char* I,char* II)                    //判断身份证是否与输入的账号匹配
{
	if(strcmp(I,II)==0&&strlen(I)==18)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,270,640,286);
		puthz(550,270,"身份证匹配",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,270,640,286);
		puthz(550,270,"身份证无效",16,16,RED);
		return 0;
	}
}

/************************************************************************
FUNCTION:C_Password_Jundge
DESCRIPTION:判断密码长度是否符合要求
INPUT:输入的密码P
RETURN:判断结果
************************************************************************/
int C_Password_Jundge(char *P)                      //判断密码长度是否符合要求
{
	if(strlen(P)>=6)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,150,640,166);
		puthz(550,150,"通过",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,150,640,166);
		puthz(550,150,"密码过短",16,16,RED);
		return 0;
	}
}	

/************************************************************************
FUNCTION:C_Password_Same
DESCRIPTION:判断两次输入的密码是否一致
INPUT:输入的密码P，确认密码RP
RETURN:判断结果
************************************************************************/
int C_Password_Same(char *P,char *RP)              //判断两次输入的密码是否一致
{
	if(strcmp(P,RP)==0)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,226);
		puthz(550,210,"密码一致",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,226);
		puthz(550,210,"密码不一致",16,16,RED);
		return 0;
	}
}

/************************************************************************
FUNCTION:Change_Com
DESCRIPTION:完成密码的修改
INPUT:判断结果jun1,jun2,jun3,jun4,输入的账号和密码
RETURN:判断结果
************************************************************************/
int Change_Com(int jun1,int jun2,int jun3,int jun4,char* A,char* P)
{
	int l;
	int i;
	FILE* fp;
	USER* u=NULL;
	if(jun1==1&&jun2==1&&jun3==1&&jun4==1)                               //输入的内容均符合要求
	{
	    if ((fp=fopen(".\\TEXT\\UserData.dat","rb+"))==NULL)
	    {
		    printf("\nError on open file UserData.dat!");
		    delay(3000);
		    exit(1);
	    }
	    fseek(fp,0,SEEK_END);                                            //文件指针定位到最后一位
	    l=ftell(fp)/sizeof(USER);                                      //计算用户个数
	    for(i=0;i<l;i++)
	    {
		    if((u=(USER*)malloc(sizeof(USER)))==NULL)
		    {
			    printf("\nMemory not enough!");
			    delay(3000);
			    exit(1);
		    }
		    fseek(fp,i*sizeof(USER),SEEK_SET);                           //文件指针移动到第i个用户
		    fread(u,sizeof(USER),1,fp);                                  //将第i个用户的信息信息读入u
		    if (strcmp(A,u->account)==0)                                 //在文件中找到与输入账号匹配的用户
		    {
				strcpy(u->password,P);                                   //修改读到该用户信息中的密码为新密码
				fseek(fp,i*sizeof(USER),SEEK_SET);                       //文件指针定位到该用户
				fwrite(u,sizeof(USER),1,fp);                             //用该用户修改后的信息覆盖掉之前的信息
				if(u!=NULL)                                              //释放内存
				{
					free(u);
					u=NULL;
				}
				if(fclose(fp)!=0)                                        //关闭文件
				{
					printf("\nError on close UserData.dat!");
					exit(1);
				}
				setfillstyle(SOLID_FILL, WHITE);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                setfillstyle(SOLID_FILL, WHITE);
		        puthz(274,220,"保存注册",24,24,RED);
		        stablack(282,270,3);
		        stablack(282,270,3);
		        delay(500);
		        stablack(320,270,3);
		        delay(500);
		        stablack(358,270,3);
		        delay(500);
		        setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                setfillstyle(SOLID_FILL, WHITE);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                setfillstyle(SOLID_FILL, WHITE);
		        puthz(274,230,"修改成功",24,24,RED);
		        delay(3000);
				return 1;
			}
			if(u!=NULL)                                              //释放内存
			{
				free(u);
				u=NULL;
			}
		}
		if(u!=NULL)
	    {
		    free(u);
		    u=NULL;
	    }
	    if(fclose(fp)!= 0)
	    {
		    printf("\nError on close UserData.dat!");
		    exit(1);
	    }
	}
	 //未满足修改密码的所有条件
	setfillstyle(SOLID_FILL, WHITE);
    bar(200,180,440,300);
    rectangle(200,180,440,300);
    setfillstyle(SOLID_FILL, WHITE);
	puthz(274,220,"正在保存",24,24,RED);
	stablack(282,270,3);
	stablack(282,270,3);
	delay(500);
	stablack(320,270,3);
	delay(500);
	stablack(358,270,3);
	delay(500);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    setfillstyle(SOLID_FILL, WHITE);
    bar(200,180,440,300);
    rectangle(200,180,440,300);
    setfillstyle(SOLID_FILL, WHITE);
	puthz(274,230,"修改失败",24,24,RED);
	delay(3000);
	return 0;
}