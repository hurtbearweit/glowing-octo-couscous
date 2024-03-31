#include"public.h"
/***************
NAME：list_1
FUNCTION:列表第一页
***************/
void list_1(int *page)
{   
    int pos1=0;
	int pos2=0;
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	draw_list();
	list_output(1) ;   
	delay(500);
	while(1)
	{
		 newmouse(&MouseX,&MouseY,&press);
		 if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)   //在返回键上
		 {  
	      if(mouse_press(50,425,140,460)==2)
    		{   			 
    				List_Lighten(50,425,140,460,1);
                   	MouseS=1;				
                    pos1=1;					
				    continue;
			}
			else if(mouse_press(50,425,140,460)==1)
			{
				List_Lighten(50,425,140,460,1);				   
                    pos1=1;	
				MouseS=0;
				clrmous(MouseX, MouseY);
				 delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=4;
				break;
			}
		 }
		 if(MouseX>490&&MouseX<580&&MouseY>425&&MouseY<460)   
		 {  
	      if(mouse_press(490,425,580,460)==2)
    		{
    				List_Lighten(490,425,580,460,2);
					MouseS=1;                
                    pos2=1;					
				    continue;
			}
			else if(mouse_press(490,425,580,460)==1)
			{
				List_Lighten(490,425,580,460,2);				     
                    pos2=1;	
				MouseS=0;
				clrmous(MouseX, MouseY);
				 delay(100);
				 save_bk_mou(MouseX, MouseY);
				*page=92;
				break;
			}
		 }		 		 
			 if(pos1!=0)
			 {
				 List_Dark(1);
				 pos1=0;
			 }
			 
			  if(pos2!=0)
			 {
				 List_Dark(2);
				 pos1=0;
				 
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
void list_2(int *page)
{
	int tag=0;
    int pos1=0;
	int pos2=0;
	Draw_list_2();
	list_output(2) ;   
	delay(500);
	while(1)
	{
		 newmouse(&MouseX,&MouseY,&press);
		 if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)   //在返回键上
		 {  
	      if(mouse_press(50,425,140,460)==2)
    		{   			 
    				List_Lighten(50,425,140,460,1);
                   	MouseS=1;				
					tag=1;
                    pos1=1;					
				    continue;
			}
			else if(mouse_press(50,425,140,460)==1)
			{
				List_Lighten(50,425,140,460,1);
				    tag=1;
                    pos1=1;	
				MouseS=0;
				clrmous(MouseX, MouseY);
				 delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=4;
				break;
			}
		 }
		 if(MouseX>490&&MouseX<580&&MouseY>425&&MouseY<460)   
		 {  
	      if(mouse_press(490,425,580,460)==2)
    		{
    				List_Lighten(490,425,580,460,3);
					MouseS=1;
                    tag=1;
                    pos2=1;					
				    continue;
			}
			else if(mouse_press(490,425,580,460)==1)
			{
				List_Lighten(490,425,580,460,3);
				     tag=1;
                    pos2=1;	
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
			 if(pos1!=0)
			 {
				 List_Dark(1);
				 pos1=0;
			 }
			 if(pos2!=0)
			 {
				 List_Dark(3);
				 pos1=0;
				 
			 }
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
void draw_list()
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
void  List_Lighten(int x1,int y1,int x2,int y2,int flag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	if(flag==1)
	{
		setcolor(RED);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,CYAN);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(70,430,"返回",24,24,LIGHTCYAN);
	}
	else if(flag== 2)
	{
		setcolor(RED);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,RED);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(500,430,"下一页",24,24,LIGHTCYAN);
	}
	else if(flag== 3)
	{
		setcolor(RED);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,RED);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(500,430,"上一页",24,24,LIGHTCYAN);
	}
	
	
}
/**************************
NAME：List_Dark
FUNCTION：按钮还原
**************************/
void List_Dark(int pos)
{
	
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, GREEN);
	switch(pos)
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
	}			   
}
/*****************************
NAME:list_output
FUNCTION:文本信息输出
*****************************/
void list_output(int temp)                                  
{ 
	switch(temp)
  {  case 1:
	puthz(45,20,"项目名称",24,24,RED);
	puthz(195,20,"所在区域",24,24,RED);
	puthz(345,20,"项目特点",24,24,RED);
	puthz(495,20,"推荐指数",24,24,RED);
	
	puthz(45,70,"木翼双龙",24,24,BLUE);
	puthz(195,70,"欢乐江城",24,24,BLUE);
	puthz(345,70,"恢弘刺激",24,24,BLUE);
	puthz(525,70,"五星",24,24,BLUE);
	
	puthz(45,120,"极速飞车",24,24,BLUE);
	puthz(195,120,"极速世界",24,24,BLUE);
	puthz(345,120,"急速失重",24,24,BLUE);
	puthz(525,120,"六星",24,24,BLUE);
	
	puthz(45,170,"完美风暴",24,24,BLUE);
	puthz(210,170,"飓风湾",24,24,BLUE);
	puthz(345,170,"翻转失重",24,24,BLUE);
	puthz(525,170,"五星",24,24,BLUE);
	
	puthz(60,220,"摩天塔",24,24,BLUE);
	puthz(210,220,"渔光岛",24,24,BLUE);
	puthz(345,220,"至高观光",24,24,BLUE);
	puthz(525,220,"四星",24,24,BLUE);
	
	puthz(45,270,"天地双雄",24,24,BLUE);
	puthz(195,270,"欢乐时光",24,24,BLUE);
	puthz(345,270,"骤升骤降",24,24,BLUE);
	puthz(525,270,"五星",24,24,BLUE);
	
	puthz(45,320,"莲花栈道",24,24,BLUE);
	puthz(195,320,"羽落天堂",24,24,BLUE);
	puthz(345,320,"自然美好",24,24,BLUE);
	puthz(525,320,"三星",24,24,BLUE);
	
	puthz(45,370,"音乐飞船",24,24,BLUE);
	puthz(195,370,"欢乐海洋",24,24,BLUE);
	puthz(345,370,"动感旋转",24,24,BLUE);
	puthz(525,370,"四星",24,24,BLUE);
	break;
	
	case 2:
	puthz(45,20,"项目名称",24,24,RED);
	puthz(195,20,"所在区域",24,24,RED);
	puthz(345,20,"项目特点",24,24,RED);
	puthz(495,20,"推荐指数",24,24,RED);
	
	puthz(30,70,"疯狂溜达车",24,24,BLUE);
	puthz(195,70,"卡通工厂",24,24,BLUE);
	puthz(335,70,"至尊合家欢",24,24,BLUE);
	puthz(525,70,"四星",24,24,BLUE);
	
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
void Draw_list_2()
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
