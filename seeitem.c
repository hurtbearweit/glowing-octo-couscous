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
	setbkcolor(WHITE);     //���� 
	
	setfillstyle(1,BLUE);
	bar(0,0,640,60);
	bar(0,440,640,480);
	puthz(240,14,"�人���ֹ�",32,32,LIGHTGRAY);
	
	setfillstyle(1,WHITE);
	setcolor(BLACK);
	setlinestyle(0,0,1);
	bar(60,100,240,200);
	rectangle(60,100,240,200);
	puthz(78,138,"�鿴������Ŀ",24,24,BLACK);
	
	bar(60,260,240,360);
	rectangle(60,260,240,360);
	puthz(102,298,"������Ʊ",24,24,BLACK);
	
	bar(400,100,580,200);
	rectangle(400,100,580,200);
	puthz(442,126,"������Ŀ",24,24,BLACK);
	puthz(442,150,"����ԤԼ",24,24,BLACK);
	
	bar(400,260,580,360);
	rectangle(400,260,580,360);
	puthz(442,298,"·���Ƽ�",24,24,BLACK);
}


int Light_Seeitem()
{
	clrmous(MouseX,MouseY);
	delay(10);
	
	
	
}

int Dark_Seeitem()
{
	
	
	
	
}
