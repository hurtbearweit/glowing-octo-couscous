#include"public.h"
#include"login.h"
/************************************************************************
FUNCTION:Login
DESCRIPTION:实现登录选择功能
INPUT:界面跳转控制变量page,管理员所属机构ad
RETURN:无
************************************************************************/
void Login(int *page,int *ad)
{
    int flag=0;
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Login();
	
	while(1)
	{               
	    newmouse(&MouseX,&MouseY,&press);    
		if(MouseX>170&&MouseX<300&& MouseY>90&&MouseY<220)  
		{
			if(mouse_press(170,90,300,220)==2)              
			    {
				    MouseS=1;           
                    if(flag=0); 
                    {
                        Login_Light(1);
					    flag=1;
                    }					
				continue;
			    }
			    else if(mouse_press(170,90,300,220)==1)        
			    {
			        MouseS=0;
			        clrmous(MouseX,MouseY);
			        *page=1;//跳转至乘客登录界面
				    break;
			        }
		        }
		if(MouseX>320&&MouseX<450&& MouseY>90&&MouseY<220)  
		{
			if(mouse_press(320,90,450,220)==2)              
			{
				MouseS=1;  
                if(flag=0);
                {
                    Login_Light(2);
					flag=2;
                }									
			continue;
			}
			else if(mouse_press(320,90,450,220)==1)        
			{
				MouseS=0;
				*ad=1;
				*page=2;//跳转至检测机构管理员界面
				break;
			}
		}
		if(MouseX>170&&MouseX<300&& MouseY>240&&MouseY<370)  
		{
			if(mouse_press(170,240,300,370)==2)              
			{
				MouseS=1;  
                if(flag=0);
                {
                    Login_Light(3);
					flag=3;
                }									
				continue;
			}
			else if(mouse_press(170,240,300,370)==1)        
			{
				MouseS=0;
				*ad=2;
				*page=2;//跳转至卫健委管理员界面
				break;
			}
		}
		if(MouseX>320&&MouseX<450&& MouseY>240&& MouseY<370)  
		{
			if(mouse_press(320,240,450,370)==2)              
			{
				MouseS=1;     
                if(flag=0);
            {
                Login_Light(4);
				flag=4;
            }									
			continue;
			}
			else if(mouse_press(320,240,450,370)==1)        
			{
				MouseS=0;
				*ad=3;
				*page=2;//跳转至铁路管理员界面
				break;
			}
		}
		if(MouseX>492&&MouseX<597&&MouseY>417&&MouseY<437)
		{
			if(mouse_press(492,417,597,437)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(492,417,597,437)==1)
			{
				MouseS=0;
				Bye();
				delay(3000);
				exit(1);
				break;
			}
		}
		if(flag!=0)
		{
			Login_Darken(flag);
			flag=0;
		}
		if(MouseS!=0)
		{
		    MouseS=0;
		}
    }
}

/************************************************************************
FUNCTION:Draw_Login
DESCRIPTION:绘制登录选择界面
INPUT:无
RETURN:无
************************************************************************/
int Draw_Login()
{
	int i,color,x,y,k;
	int x1=25;
	int y1=20;
	int x2=639-x1;
	int y2=430-y1;
	int a=22;
	int b=7;
	int r=20;
    
	cleardevice();
	setbkcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    setcolor(LIGHTGRAY);	
	line(0,0,40,40);
	line(40,40,600,40);
	line(600,40,640,0);
	line(40,40,40,440);
	line(40,440,0,480);
	line(600,40,600,440);
	line(600,440,640,480);
	line(40,440,600,440);
	
    
	setfillstyle(1,BLUE);
	bar(170,90,320,240);
	puthz(213,149,"乘客",32,32,LIGHTGRAY);
	delay(200);
	
	setfillstyle(1,RED);
	bar(320,90,470,240);
	puthz(371,141,"检测",24,24,LIGHTGRAY);
	puthz(371,165,"机构",24,24,LIGHTGRAY);
	delay(200);
	
	setfillstyle(1,BROWN);
	bar(320,240,470,390);
	puthz(363,299,"铁路",32,32,LIGHTGRAY);
	delay(200);
	
	setfillstyle(1,GREEN);
	bar(170,240,320,390);
	puthz(209,303,"卫健委",24,24,LIGHTGRAY);
	delay(200);
	
	
	setfillstyle(1,MAGENTA);
	pieslice(320,240,0,360,50);
	setcolor(MAGENTA);
	line(320,240,370,240);
	puthz(302,232,"欢迎",16,20,WHITE);
	
	draw_exit(497, 420, LIGHTGREEN, WHITE, BLUE, GREEN);
	
	/*setcolor(LIGHTGRAY);
	cover(x2-50, y1, x2, y2-80, LIGHTGRAY);
	highlight(x2-50, y1, x2, y2-80, WHITE);
	triangle(585, 180, 639, 180, 639, 80, WHITE);
	trianglefill(585 + 2, 180 - 2, 639 - 2, 180 - 2, 639 - 2, 80 + 2, WHITE);*///decoration of bk
	 /*for (k=0;k<y2;k++)
	{
	    
		setlinestyle(SOLID_LINE,0,3);
		setcolor(WHITE);
		line (x-15,y+k,x+15,y+k);
		delay(3);
		k+=2;
	}*/
    for (i=0;i<(x2-x1)/a;i++)
	{
		if (i%2==0)
		{
			
			cover(x1+i*a,y1,(i+1)*a+x1,y1+b,LIGHTBLUE);
			delay(10);
		}
		if (i%2)
		{
		    cover(x1+i*a,y1,(i+1)*a+x1,y1+b,WHITE);
			delay(10);
			
		}
		if (i%8==0)
			{
			   stalightred(x1+i*a+a/2,y1+b/2,8);
			}
	} 
    
	y1-=6;
	y2+=6;
	x1+=5;
	for (i=0;i<(y2-y1)/a;i++)
	{
		if (i%2==0)
		{
			
			cover(x1,y1+i*a,x1+b,(i+1)*a+y1,BROWN);
			//if (i<(y2-y1)/a-5)
			//cover(x2,y1+i*a,x2+b,(i+1)*a+y1,BROWN);
			delay(10);
		}
		if (i%2)
		{
		    cover(x1,y1+i*a,b+x1,y1+(i+1)*a,WHITE);
			//if (i<(y2-y1)/a-5)
			//cover(x2,y1+i*a,b+x2,y1+(i+1)*a,WHITE);
			delay(10);
			
		}
		if(!(i))
			stayellow(x1+b/2,y1+i*a+a/2,12);
		if (i%5==0&&i)
		{
			stagreen(x1+b/2,y1+i*a+a/2,8);
			//stagreen(x2+b/2,y1+i*a+a/2,8);
		}
	}
	cover(b+x1-7,y1+(i+1)*a-22,b+x1+5-5,y1+(i+1)*a+5-18,BROWN);
	setcolor(BROWN);
	x1+=4;
	y1-=2;
	arc(x1+r,y2,180,270,r);
	x1+=1;y2-=1;
	arc(x1+r,y2,180,270,r);
	x1+=1;y2-=1;
	arc(x1+r,y2,180,270,r);
		x1+=1;y2-=1;
	arc(x1+r,y2,180,270,r);
	x1-=8;
	x2-=180;
	y2+=17;
	y=y2+20;
	for (i=0;i<(x2-x1)/a;i++)
	{
		if (i%2==0&&i)
		{
			
			cover(x1+i*a,y2,(i+1)*a+x1,y2+b,BROWN);
			cover(x1+i*a,y,(i+1)*a+x1,y+b,BLUE);
			delay(10);
		}
		if (i%2)
		{
		    cover(x1+i*a,y2,(i+1)*a+x1,y2+b,WHITE);
			cover(x1+i*a,y,(i+1)*a+x1,y+b,WHITE);
			delay(10);
			
		}
		if (i%4==0&&i)
		{
			   stalightred(x1+i*a+a/2,y2+b/2,8);
			   if (i%8==0&&i)
			   {
				    stacyan(x1+i*a+a/2,y2+b/2,9);
					stacyan(x1+i*a+a/2,y+b/2,9);
					cover(x1+i*a+a/2-9,y2+b/2,x1+i*a+a/2+9,y+b/2,CYAN);
			   }
		}
	} 
	y2+=12;
    Fill_Triangle(x2-10, y2-20, x2-10, y2+20, x2+30, y2, LIGHTGRAY);
    triangle(x2-10, y2-20, x2-10, y2+20, x2+30, y2, LIGHTRED);
}

/************************************************************************
FUNCTION:Login_Lighten
DESCRIPTION:登录选择界面按钮点亮
INPUT:点亮控制变量flag
RETURN:无
************************************************************************/
int Login_Light(int flag)
{
	switch(flag)
	{
		case 1:
		{
		    puthz(213,149,"乘客",32,32,WHITE);
			break;
		}
		case 2:
		{
			puthz(371,141,"检测",24,24,WHITE);
	        puthz(371,165,"机构",24,24,WHITE);
			break;
		}
		case 3:
		{
			puthz(209,303,"卫健委",24,24,WHITE);
			break;
		}
		case 4:
		{
			puthz(363,299,"铁路",32,32,WHITE);
			break;
		}
	}
}

/************************************************************************
FUNCTION:Login_Darken
DESCRIPTION:登录选择界面按钮恢复
INPUT:恢复控制变量flag
RETURN:无
************************************************************************/
int Login_Darken(int flag)
{
	switch(flag)
	{
		case 1:
		{
		    puthz(213,149,"乘客",32,32,LIGHTGRAY);
			break;
		}
		case 2:
		{
			puthz(371,141,"检测",24,24,LIGHTGRAY);
	        puthz(371,165,"机构",24,24,LIGHTGRAY);
			break;
		}
		case 3:
		{
			puthz(209,303,"卫健委",24,24,LIGHTGRAY);
			break;
		}
		case 4:
		{
			puthz(363,299,"铁路",32,32,LIGHTGRAY);
			break;
		}
	}
}
