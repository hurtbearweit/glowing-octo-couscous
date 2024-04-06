#include"public.h"

void R_List_1(int *page,int *num)
{
    int tag=0;
    int pos=0;
    
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	R_Draw_List();
	R_List_Output(1);
	delay(500);
	
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>470&&MouseX<620&&MouseY>50&&MouseY<100)
		{
			if(mouse_press(470,50,620,100)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=11;
					R_List_Lighten(470,50,620,100,11);
				}
				continue;
			}
			else if(mouse_press(470,50,620,100)==1)
			{
				pos=11;
				tag=0;
				Draw_Reserve(pos);
				MouseS=0;
				R_Input_Data(num,pos);	
			}
		}
		//项目1 
		if(MouseX>470&&MouseX<620&&MouseY>100&&MouseY<150)
		{
			if(mouse_press(470,100,620,150)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=12;
					R_List_Lighten(470,100,620,150,12);
				}
				continue;
			}
			else if(mouse_press(470,100,620,150)==1)
			{
				pos==12;
				tag=0;
				Draw_Reserve(pos);
				MouseS=0;
				R_Input_Data(num,pos);	
			}
		}
		//项目2 
		if(MouseX>470&&MouseX<620&&MouseY>150&&MouseY<200)
		{
			if(mouse_press(470,150,620,200)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=13;
					R_List_Lighten(470,150,620,200,13);
				}
				continue;
			}
			else if(mouse_press(470,150,620,200)==1)
			{
				pos==13;
				tag=0;
				Draw_Reserve(pos);
				MouseS=0;
				R_Input_Data(num,pos); 
			}
		}
		//项目3 
		if(MouseX>470&&MouseX<620&&MouseY>200&&MouseY<250)
		{
			if(mouse_press(470,200,620,250)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=14;
					R_List_Lighten(470,200,620,250,14);
				}
				continue;
			}
			else if(mouse_press(470,200,620,250)==1)
			{
				pos==14;
				tag=0;
				Draw_Reserve(pos);
				MouseS=0;
				R_Input_Data(num,pos);	
			}
		}
		//项目4 
		if(MouseX>470&&MouseX<620&&MouseY>250&&MouseY<300)
		{
			if(mouse_press(470,250,620,300)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=15;
					R_List_Lighten(470,250,620,300,15);
				}
				continue;
			}
			else if(mouse_press(470,250,620,300)==1)
			{
				pos==15;
				tag=0;
				Draw_Reserve(pos);
				MouseS=0;
				R_Input_Data(num,pos);	
			}
		}
		//项目5 
		if(MouseX>470&&MouseX<620&&MouseY>300&&MouseY<350)
		{
			if(mouse_press(470,300,620,350)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=16;
					R_List_Lighten(470,300,620,350,16);
				}
				continue;
			}
			else if(mouse_press(470,300,620,350)==1)
			{
				pos==16;
				tag=0;
				Draw_Reserve(pos);
				MouseS=0;
				R_Input_Data(num,pos);	
			}
		}
		//项目6 
		if(MouseX>470&&MouseX<620&&MouseY>350&&MouseY<400)
		{
			if(mouse_press(470,350,620,400)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=17;
					R_List_Lighten(470,350,620,400,17);
				}
				continue;
			}
			else if(mouse_press(470,350,620,400)==1)
			{
				pos==17;
				tag=0;
				Draw_Reserve(pos);
				MouseS=0;
				R_Input_Data(num,pos);	
			}
		}
		//项目7  
		if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)//在返回键上
		{  
	        if(mouse_press(50,425,140,460)==2)
    		{ 
			    MouseS=1;	  			 
    			if(tag==0)
				{
					tag=1;
					R_List_Lighten(50,425,140,460,1);	
				}				
				continue;
			}
			else if(mouse_press(50,425,140,460)==1)
			{
				R_List_Lighten(50,425,140,460,1);				   
				MouseS=0;
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=3;
				break;
			}
		}
		if(MouseX>490&&MouseX<580&&MouseY>425&&MouseY<460)   //跳转至下一页 
		{  
	        if(mouse_press(490,425,580,460)==2)
    		{
    			MouseS=1;
    			if(tag==0)
				{
					tag=2;
					R_List_Lighten(490,425,580,460,2);
				}				
				continue;
			}
			else if(mouse_press(490,425,580,460)==1)
			{
				R_List_Lighten(490,425,580,460,2);		
				MouseS=0;
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=62;
				break;
			}
		}		 		 
		if(tag!=0)
		{
			R_List_Dark(tag);
			tag=0;
		}	 
		if(MouseS!=0)
		{
			MouseS=0;
		}   
	}
}
/***************
NAME：list_1
FUNCTION:列表第二页
***************/
void R_List_2(int *page,int *num)
{
	int tag=0;
	int pos=0;
	
	R_Draw_List_2();
	R_List_Output(2) ;   
	delay(500);
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>470&&MouseX<620&&MouseY>100&&MouseY<150)
		{
			if(mouse_press(470,100,620,150)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=21;
					R_List_Lighten(470,50,620,100,21);
				}
				continue;
			}
			else if(mouse_press(470,100,620,150)==1)
			{
				pos==21;
				tag=0;
				R_List_Lighten(470,50,620,100,21);
				MouseS=0;
				R_Input_Data(num,pos-20);
				Draw_Reserve(pos);
			}
		}
		if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)   //在返回键上
		{  
	        if(mouse_press(50,425,140,460)==2)
    		{   			 
                MouseS=1;				
				if(tag==0)
				{
					tag=1;
				    R_List_Lighten(50,425,140,460,1);
				}
				continue;
			}
			else if(mouse_press(50,425,140,460)==1)
			{
				R_List_Lighten(50,425,140,460,1);
				tag=1;
				MouseS=0;
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=3;
				break;
			}
		}
		if(MouseX>490&&MouseX<580&&MouseY>425&&MouseY<460)   
		{  
	        if(mouse_press(490,425,580,460)==2)
    		{
    			R_List_Lighten(490,425,580,460,3);
				MouseS=1;
                tag=2;				
				continue;
			}
			else if(mouse_press(490,425,580,460)==1)
			{
				R_List_Lighten(490,425,580,460,3);
				tag=2;
				MouseS=0;
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=91;
				break;
			}
		}
		 
		if(tag!=0)
		{
			R_List_Dark(tag); 
			tag=0;	 		 
		}
		if(MouseS!=0)
	    {
		    MouseS=0;
	    }
	}
}
/*******************
NAME：draw_list
FUNCTION:绘制第一页
*******************/
void R_Draw_List()
{
	cleardevice();
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(RED);
	line(20,10,620,10);
	line(20,50,620,50);
	line(20,100,620,100);
	line(20,150,620,150);
	line(20,200,620,200);
	line(20,250,620,250);
	line(20,300,620,300);
	line(20,350,620,350);
	line(20,400,620,400);
	line(20,10,20,400);
	line(620,10,620,400);
	line(170,10,170,400);
	line(320,10,320,400);
	line(470,10,470,400);
	
	setfillstyle(1,GREEN);
	bar(50,425,140,460);
	puthz(70,430,"返回",24,24,WHITE);
	bar(490,425,580,460);
	puthz(500,430,"下一页",24,24,WHITE);
	
	puthz(220,430,"第",24,24,RED);
	outtextxy(250,430,"1");
	puthz(260,430,"页",24,24,RED);
	outtextxy(290,430,"/");
	puthz(300,430,"共",24,24,RED);
	outtextxy(330,430,"2");
	puthz(350,430,"页",24,24,RED);
}
/************************
NAME:List_Lighten
FUNCTION:按钮点亮
************************/
void  R_List_Lighten(int x1,int y1,int x2,int y2,int tag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	if(tag==1)
	{
		setcolor(RED);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,CYAN);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(70,430,"返回",24,24,LIGHTCYAN);
	}
	else if(tag==2)
	{
		setcolor(RED);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,RED);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(500,430,"下一页",24,24,LIGHTCYAN);
	}
	else if(tag==3)
	{
		setcolor(RED);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,RED);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(500,430,"上一页",24,24,LIGHTCYAN);
	}
	else if(tag==11)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,70,"预约",24,24,RED);	
	}
	else if(tag==12)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,120,"预约",24,24,RED);	
	}
	else if(tag==13)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,170,"预约",24,24,RED);	
	}
	else if(tag==14)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,220,"预约",24,24,RED);	
	}
	else if(tag==15)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,270,"预约",24,24,RED);	
	}
	else if(tag==16)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,320,"预约",24,24,RED);	
	}
	else if(tag==17)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,370,"预约",24,24,RED);	
	}
	else if(tag==21)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,70,"预约",24,24,RED);	
	}
}
/**************************
NAME：List_Dark
FUNCTION：按钮还原
**************************/
void R_List_Dark(int tag)
{
	
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, GREEN);
	switch(tag)
	{  
	    case 1:
		    bar(50,425,140,460);
	        puthz(70,430,"返回",24,24,WHITE);
	        break;
		case 2:
		    bar(490,425,580,460);
	        puthz(500,430,"下一页",24,24,WHITE);
	        break;
		case 3:
		    bar(490,425,580,460);
	        puthz(500,430,"上一页",24,24,WHITE);
	        break;
	    case 11:
	    	cover(471,51,619,99,WHITE);
			puthz(525,70,"预约",24,24,BLUE);
			break;
	    case 12:
	    	cover(471,101,619,149,WHITE);
			puthz(525,120,"预约",24,24,BLUE);
			break;
		case 13:
			cover(471,151,619,199,WHITE);
			puthz(525,170,"预约",24,24,BLUE);
			break;
		case 14:
			cover(471,201,619,249,WHITE);
			puthz(525,220,"预约",24,24,BLUE);
			break;
		case 15:
			cover(471,251,619,299,WHITE);
			puthz(525,270,"预约",24,24,BLUE);
			break;
		case 16:
			cover(471,301,619,349,WHITE);
			puthz(525,320,"预约",24,24,BLUE);
			break;
		case 17:
			cover(471,351,619,399,WHITE);
			puthz(525,370,"预约",24,24,BLUE);
			break;	
		case 21:
	    	cover(471,51,619,99,WHITE);
			puthz(525,70,"预约",24,24,BLUE);
			break;		
	}			   
}
/*****************************
NAME:list_output
FUNCTION:文本信息输出
*****************************/
void R_List_Output(int temp)                                  
{
	switch(temp)
	{
		case 1:
			puthz(45,20,"项目名称",24,24,RED);
	        puthz(195,20,"所在区域",24,24,RED);
			puthz(345,20,"项目特点",24,24,RED);
			puthz(495,20,"预约状况",24,24,RED);
	
			puthz(45,70,"木翼双龙",24,24,BLUE);
			puthz(195,70,"欢乐江城",24,24,BLUE);
			puthz(345,70,"恢弘刺激",24,24,BLUE);
			puthz(525,70,"预约",24,24,BLUE);
	
			puthz(45,120,"极速飞车",24,24,BLUE);
			puthz(195,120,"极速世界",24,24,BLUE);
			puthz(345,120,"急速失重",24,24,BLUE);
			puthz(525,120,"预约",24,24,BLUE);
	
			puthz(45,170,"完美风暴",24,24,BLUE);
			puthz(210,170,"飓风湾",24,24,BLUE);
			puthz(345,170,"翻转失重",24,24,BLUE);
			puthz(525,170,"预约",24,24,BLUE);
	
			puthz(60,220,"摩天塔",24,24,BLUE);
			puthz(210,220,"渔光岛",24,24,BLUE);
			puthz(345,220,"至高观光",24,24,BLUE);
			puthz(525,220,"预约",24,24,BLUE);
			
			puthz(45,270,"天地双雄",24,24,BLUE);
			puthz(195,270,"欢乐时光",24,24,BLUE);
			puthz(345,270,"骤升骤降",24,24,BLUE);
			puthz(525,270,"预约",24,24,BLUE);
	
			puthz(45,320,"莲花栈道",24,24,BLUE);
			puthz(195,320,"羽落天堂",24,24,BLUE);
			puthz(345,320,"自然美好",24,24,BLUE);
			puthz(525,320,"预约",24,24,BLUE);
	
			puthz(45,370,"音乐飞船",24,24,BLUE);
			puthz(195,370,"欢乐海洋",24,24,BLUE);
			puthz(345,370,"动感旋转",24,24,BLUE);
			puthz(525,370,"预约",24,24,BLUE);
			break;
		case 2:
			puthz(45,20,"项目名称",24,24,RED);
			puthz(195,20,"所在区域",24,24,RED);
			puthz(345,20,"项目特点",24,24,RED);
			puthz(495,20,"预约状态",24,24,RED);
	
			puthz(30,70,"疯狂溜达车",24,24,BLUE);
			puthz(195,70,"卡通工厂",24,24,BLUE);
			puthz(335,70,"至尊合家欢",24,24,BLUE);
			puthz(525,70,"预约",24,24,BLUE);
	
			setcolor(RED);
			puthz(50,120,"以上所有内容均来自欢乐谷官网",24,24,RED);
			outtextxy(395,120,",");
			puthz(405,120,"若想得知有关游乐项",24,24,RED);
			puthz(50,170,"目的详细信息可以前往地图查看",24,24,RED);
			outtextxy(395,170,",");
			puthz(405,170,"欢乐谷感谢您的光顾",24,24,RED);
			outtextxy(630,170,"!");
			break;			
	}
}
/*********************************
NAME:Draw_list_2
FUNCTION:绘制第二页
*********************************/
void R_Draw_List_2()
{  
    cleardevice();
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(RED);
	line(20,10,620,10);
	line(20,50,620,50);
	line(20,100,620,100);
	line(20,10,20,100);
	line(620,10,620,100);
	line(170,10,170,100);
	line(320,10,320,100);
	line(470,10,470,100);
	
	setfillstyle(1,GREEN);
	bar(50,425,140,460);
	puthz(70,430,"返回",24,24,WHITE);
	bar(490,425,580,460);
	puthz(500,430,"上一页",24,24,WHITE);
	
	puthz(220,430,"第",24,24,RED);
	outtextxy(250,430,"2");
	puthz(260,430,"页",24,24,RED);
	outtextxy(290,430,"/");
	puthz(300,430,"共",24,24,RED);
	outtextxy(330,430,"2");
	puthz(350,430,"页",24,24,RED);	
}

void R_Input_Data(int *num,int pos)				//将预约的项目读入该用户的文件中 
{
	int l;
	int i;
	FILE *fp;
	ITEM *n;
	if((fp=fopen(".\\TEXT\\IT.dat","rb+"))==NULL)
	{
		printf("\nErroe on open file IT.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);
	l=ftell(fp)/sizeof(ITEM);
	for(i=0;i<l;i++)
	{
		if((n=(ITEM*)malloc(sizeof(ITEM)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(ITEM),SEEK_SET);
		fread(n,sizeof(ITEM),1,fp);
		if(*num==n->num)
		{
			if(pos>10&&pos<20)
			{
				n->it[pos-11]=1;
			}
			else 
			{
				n->it[7]=1;
			}
			fseek(fp,i*sizeof(ITEM),SEEK_SET);
			fwrite(n,sizeof(USER),1,fp);
		}
	}
	if(n!=NULL)
	{
		free(n);
		n=NULL;
	}
	if((fclose(fp))!=0)
	{
		printf("\nErroe on close USER.dat!");
		delay(3000);
		exit(1);
	}
}

void Draw_Reserve(int pos)
{
	switch(pos)
	{
		case 11:
			cover(471,51,619,99,LIGHTGREEN);
			puthz(509,70,"已预约",24,24,BLUE);
			break;
		case 12:
			cover(471,101,619,149,LIGHTGREEN);
			puthz(509,120,"已预约",24,24,BLUE);
			break;
		case 13:
			cover(471,151,619,199,LIGHTGREEN);
			puthz(509,170,"已预约",24,24,BLUE);
			break;
		case 14:
			cover(471,201,619,249,LIGHTGREEN);
			puthz(509,220,"已预约",24,24,BLUE);
			break;
		case 15:
			cover(471,251,619,299,LIGHTGREEN);
			puthz(509,270,"已预约",24,24,BLUE);
			break;
		case 16:
			cover(471,301,619,349,LIGHTGREEN);
			puthz(509,320,"已预约",24,24,BLUE);
			break;
		case 17:
			cover(471,351,619,399,LIGHTGREEN);
			puthz(509,370,"已预约",24,24,BLUE);
			break;
		case 18:
			cover(471,51,619,99,LIGHTGREEN);
			puthz(509,70,"已预约",24,24,BLUE);
			break;
	}
}







