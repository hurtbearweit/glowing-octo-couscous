#include"public.h"
#include"seeitem.h"

void Seeitem()
{
	clrmous(MouseX,MouseY);
    delay(100);
    save_bk_mou(MouseX,MouseY);
    Draw_Seeitem();
	
	
	
	
}


int Draw_Seeitem()
{
	cleardevice();
	setbkcolor(WHITE);     //背景 
	
	setfillstyle(1,BLUE);
	bar(0,0,640,60);
	bar(0,440,640,480);
	puthz(240,14,"武汉欢乐谷",32,32,LIGHTGRAY);
	
	setfillstyle(1,WHITE);
	setcolor(BLACK);
	setlinestyle(0,0,1);
	bar(60,100,240,200);
	rectangle(60,100,240,200);
	puthz(78,138,"查看游乐项目",24,24,BLACK);
	
	bar(60,260,240,360);
	rectangle(60,260,240,360);
	puthz(102,298,"在线门票",24,24,BLACK);
	
	bar(400,100,580,200);
	rectangle(400,100,580,200);
	puthz(442,126,"特殊项目",24,24,BLACK);
	puthz(442,150,"在线预约",24,24,BLACK);
	
	bar(400,260,580,360);
	rectangle(400,260,580,360);
	puthz(442,298,"路线推荐",24,24,BLACK);
}


int Light_Seeitem()
{
	clrmous(MouseX,MouseY);
	delay(10);
	
	
	
}

int Dark_Seeitem()
{
	
	
	
	
}
