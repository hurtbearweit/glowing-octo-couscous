#include"public.h"
#include"IMAGE.h"
#include"hotad.h"

void Hotad(int *page)
{
	int tag;
	cleardevice();
    Draw_Hotad();
    
    while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if(MouseX>10&&MouseX<120&&MouseY>20&&MouseY<40)
		{
			if(mouse_press(10,20,120,40)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					tag=1;
					Light_Hotad(1); 
				}
				continue;
			}
			else if(mouse_press(10,20,120,40)==1)
    		{
    			Light_Hotad(1);
    			MouseS=0;
    			tline(315,370,170,365,YELLOW);
    			delay(300);
    			tline(170,365,160,195,YELLOW);
    			delay(300);
    			tline(160,195,330,155,YELLOW);
    			delay(300);
    			tline(330,155,390,75,YELLOW);
    			delay(300);
    			continue;
    		}
		}
		//路线1 
		if(MouseX>10&&MouseX<120&&MouseY>50&&MouseY<70)
    	{
    		if(mouse_press(10,50,120,70)==2)
    		{
    			MouseS=1;
    			if(tag==0)
				{
					tag=2;
					Light_Hotad(2); 
				}
    			continue;
			}
			else if(mouse_press(10,50,120,70)==1);
			{
				Light_Hotad(2); 
				MouseS=0;
				tline(315,370,380,430,BLUE);
    			delay(300);
    			tline(380,430,445,385,BLUE);
    			delay(300);
    			tline(445,385,465,325,BLUE);
    			delay(300);
    			tline(465,325,520,225,BLUE);
    			delay(300);
    			continue;
			}
		}
		//路线2 
		if(MouseX>10&&MouseX<120&&MouseY>80&&MouseY<100)
    	{
    		if(mouse_press(10,80,120,100)==2)
    		{
    			MouseS=1;
    			if(tag==0)
				{
					tag=3;
					Light_Hotad(3); 
				}
    			continue;
			}
			else if(mouse_press(10,80,120,100)==1);
			{
				Light_Hotad(3);
				MouseS=0;
				tline(315,370,520,225,BLACK);
    			delay(200);
    			tline(520,225,340,155,BLACK);
    			delay(200);
    			tline(340,155,155,200,BLACK);
    			delay(200);
    			continue;
			}
		}
		//路线三 
		if(MouseX>548&&MouseX<613&&MouseY>429&&MouseY<463)//如果在返回键上
		{
	        if(mouse_press(548,429,613,463)==2)
    		{	
				MouseS=1;
    			if(tag==0)
				{
					tag=4;
					Light_Hotad(4); 
				}
    			continue;  				  							
			}
			else if(mouse_press(548,429,613,463)==1)
			{
				Light_Hotad(4);
				MouseS=0;
				*page=7;
				break;
			}
		 }
		if(tag!=0)
		{
			Draw_Hotad();
			Dark_Hotad(tag);
			tag=0;
		}
		if(MouseS!=0)
		{
			MouseS=0;
		}
	} 
}


void Draw_Hotad()
{
	bmp_convert("C:\\CODE\\PICTURE\\hlg.bmp","C:\\CODE\\PICTURE\\hlg.dbm");
    show_dbm(0,0,"C:\\CODE\\PICTURE\\hlg.dbm");
	
	cover(0,0,130,110,LIGHTGREEN);
	setcolor(RED);
	settextjustify(0,2);
	settextstyle(1,0,2);
	
	cover(10,20,120,40,LIGHTGRAY);
	puthz(14,22,"路线",16,18,RED);
	outtextxy(50,20,"1");
	highlight(10,20,120,40,WHITE);
	setcolor(YELLOW);
	setlinestyle(0,0,3);
	line(90,30,115,30);
	
	cover(10,50,120,70,LIGHTGRAY);
	puthz(14,52,"路线",16,18,RED);
	highlight(10,50,120,70,WHITE);
	setcolor(BLUE);
	setlinestyle(0,0,3);
	line(90,60,115,60);
	
	cover(10,80,120,100,LIGHTGRAY);
	puthz(14,82,"路线",16,18,RED);
	highlight(10,80,120,100,WHITE);
	setcolor(CYAN);
	setlinestyle(0,0,3);
	line(90,90,115,90);	
}

void Light_Hotad(int tag)
{
	switch(tag)
	{
	  	case 1:
	  		highlight(10,20,120,40,YELLOW);
	  		break;
	  	case 2:
	  		highlight(10,50,120,70,YELLOW);
	  		break;
	  	case 3:
		  	highlight(10,80,120,100,YELLOW);
		  	break;
		case 4:
			highlight(548,429,613,463,YELLOW);
			break;
	}
}

void Dark_Hotad(int tag)
{
	switch(tag)
	{
	  	case 1:
	  		highlight(10,20,120,40,WHITE);
	  		break;
	  	case 2:
	  		highlight(10,50,120,70,WHITE);
	  		break;
	  	case 3:
		  	highlight(10,80,120,100,WHITE);
		  	break;
		case 4:
			highlight(548,429,613,463,WHITE);
			break;
	}
}
