#include"public.h"
#include"login.h"
#include"welcome.h"

void Login(int *page,int *num)
{
	int pos1=0;
	int pos2=0;
	int tag=0;
	char a[15]; 
	char p[15];
	/*int  *num=NULL;*/
	clrmous(MouseX,MouseY);
    delay(100);
    save_bk_mou(MouseX,MouseY);
    Draw_Login(); 
    /*num=(int *)malloc(sizeof(int));*/
    while(1)
    {
    	newmouse(&MouseX,&MouseY,&press);
    	//“∆÷¡’À∫≈ 
    	if(MouseX>170&&MouseX<545&&MouseY>210&&MouseY<235)
    	{
    		if(mouse_press(170,210,545,235)==2)
    		{
    			MouseS=2;
    			if(tag==0&&pos1==0)
    			{
    				Light_Login(1);
    				tag=1;
    				pos1=0;
				}
				continue;
			}
			else if(mouse_press(170,210,545,235)==1)
			{
				Light_Login(1);
				MouseS=0;
				a[0]='\0';
				Input_Vis(a,170,210,12,LIGHTGRAY);
				if(strlen(a)!=0)
				{
					pos1=1;
				}
				else 
				{
					pos1=0;
				}
				continue;
			}
		}
		//“∆÷¡√‹¬Î 
		if(MouseX>170&&MouseX<545&&MouseY>245&&MouseY<270)
		{
			if(mouse_press(170,245,545,270)==2)
			{
				MouseS=2;
				if(tag==0&&pos2==0)
				{
					Light_Login(2);
					tag=2;
				}
				continue;
			}
			else if(mouse_press(170,245,545,270)==1)
			{
				Light_Login(2);
				MouseS=0;
				p[0]='\0';
				Input_Vis(p,170,245,12,LIGHTGRAY);
				if(strlen(p)!=0)
				{
					pos2=2;
				}
				else 
				{
					pos2=0;
				}
				continue;
			}
		}
		//“∆÷¡µ«¬º 
		if(MouseX>260&&MouseX<380&&MouseY>290&&MouseY<325)
		{
			if(mouse_press(260,290,380,325)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					Light_Login(3);
					tag=3;
				}
				continue;
			}
			
			else if(mouse_press(260,290,380,325)==1)
			{
				Light_Login(3);
				MouseS=0;
				if(Judge_Login(a,p,num))
				{
					setlinestyle(0,0,1);
                    setfillstyle(1, WHITE);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(1, WHITE);
		            puthz(274,220,"’˝‘⁄µ«¬º",24,24,RED);
					stablack(282,270,3);
					stablack(282,270,3);
					delay(500);
					stablack(320,270,3);
					delay(500);
					stablack(358,270,3);
					delay(500);
					setlinestyle(0,0,1);
                    setfillstyle(1,WHITE);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(1, WHITE);
		            puthz(274,230,"µ«¬º≥…π¶",24,24,RED);
		            delay(3000);
					*page=3;                                       //Ã¯◊™÷¡”√ªßπ¶ƒ‹ΩÁ√Ê
					break;
				}
				else
				{
					setfillstyle(1,DARKGRAY);
					bar(270,225,370,255);
					puthz(272,227,"µ«¬º ß∞‹£°",24,24,RED);
					delay(3000);
					return;
				}
				continue;	
			}
		}
		//“∆÷¡◊¢≤· 
		if(MouseX>136&&MouseX<200&&MouseY>340&&MouseY<365)
		{
			if(mouse_press(136,340,200,365)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					Light_Login(4);
					tag=4;
				}
				continue;
			}
			else if(mouse_press(136,340,200,365)==1)
			{
				Light_Login(4);
				MouseS=0;
				*page=1;
				break;
			}
		}
		//“∆÷¡Õ¸º«√‹¬Î 
		if(MouseX>264&&MouseX<376&&MouseY>340&&MouseY<365)
		{
			if(mouse_press(264,340,376,365)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					Light_Login(5);
					tag=5;
				}
				continue;
			}
			else if(mouse_press(264,340,376,365)==1)
			{
				Light_Login(5);
				MouseS=0;
				*page=2;
				break;
			}
		}
		//“∆÷¡ÕÀ≥ˆ 
		if(MouseX>440&&MouseX<504&&MouseY>340&&MouseY<365)
		{
			if(mouse_press(440,340,504,365)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					Light_Login(6);
					tag=6;
				}
				continue;
			}
			else if(mouse_press(440,340,504,365)==1)
			{
				Light_Login(6);
				MouseS=0;
				Bye();
				exit(1);
				break;
			}
		}
		//”ŒøÕµ«¬º
		if (MouseX>460&&MouseX<540&&MouseY>297&&MouseY<317)
		{
			if(mouse_press(460,297,540,317)==2)
			{
				MouseS=1;
				if(tag==0)
				{
					Light_Login(7);
					tag=7;
				}
				continue;
			}
			else if(mouse_press(460,297,540,317)==1)
			{
				Light_Login(7);
				MouseS=0;
				*page=4;
				break;
			}
		}
		if(tag!=0)
		{
			if(pos1==0)
			{
				Dark_Login(1);
			}
			if(pos2==0)
			{
				Dark_Login(2);
			}
			if(tag==3||tag==4||tag==5||tag==6||tag==7)
			{
				Dark_Login(tag);
			}
			tag=0;
		}
		if(MouseS!=0)
		{
			MouseS=0;
		}
	}
}

void  Draw_Login()
{
	cleardevice();
	setbkcolor(8);     //±≥æ∞ 
	
	setfillstyle(1,BLUE);
	bar(0,0,640,60);
	bar(0,440,640,480);
	puthz(240,14,"Œ‰∫∫ª∂¿÷π»",32,32,LIGHTGRAY);
	
	puthz(95,203,"’À∫≈",32,32,CYAN);
	puthz(95,245,"√‹¬Î",32,32,CYAN);
	
	setfillstyle(1,WHITE);
	bar(170,210,545,235);
	bar(170,245,545,270);
	
	setfillstyle(1, RED);
    bar(260,290,380,325);
    puthz(291,295,"µ«¬º",24,34,WHITE);

    setfillstyle(1,WHITE);
    bar(136,340,200,365);
    puthz(148,344,"◊¢≤·",16,24,LIGHTBLUE);
    setlinestyle(0,0,1);
    setcolor(LIGHTBLUE);
    rectangle(136,340,200,365);
    
    bar(264,340,376,365);
    puthz(276,344,"Õ¸º«√‹¬Î",16,24,LIGHTBLUE);
    rectangle(264,340,376,365);
    
    bar(440,340,504,365);
    puthz(452,344,"ÕÀ≥ˆ",16,24,LIGHTBLUE);
    rectangle(440,340,504,365);
    
    setfillstyle(1,RED);
	bar(460,297,540,317);
	puthz(468,299,"”ŒøÕµ«¬º",16,16,WHITE);
} 

void Light_Login(int tag)
{
	clrmous(MouseX,MouseY);
	delay(10);
	
	if(tag==1)
	{
		setcolor(MAGENTA);       // Û±Í“∆÷¡’À∫≈¿∏ 
		setfillstyle(1,LIGHTGRAY);
		setlinestyle(0,0,1);
		bar(170,210,545,235);
		rectangle(170,210,545,235);
	}
	else if(tag==2)
	{
		setcolor(MAGENTA);       // Û±Í“∆÷¡√‹¬Î¿∏ 
		setfillstyle(1,LIGHTGRAY);
		setlinestyle(0,0,1);
		bar(170,245,545,270);
		rectangle(170,245,545,270);
	}
	else if(tag==3)
	{
		setfillstyle(1,LIGHTRED);      
		bar(260,290,380,325);
		puthz(291,295,"µ«¬º",24,34,WHITE);
	}
	else if(tag==4)
	{
		setlinestyle(0,0,1);
		setfillstyle(1,WHITE);            
		bar(136,340,200,365);
        puthz(148,344,"◊¢≤·",16,24,CYAN);
        setcolor(CYAN);
        setlinestyle(0,0,1);
        rectangle(136,340,200,365);	
	}
	else if(tag==5)
	{
        setlinestyle(0,0,1);
		setfillstyle(1,WHITE);
		bar(264,340,376,365);
    	puthz(276,344,"Õ¸º«√‹¬Î",16,24,CYAN);
    	setcolor(CYAN);
        setlinestyle(0,0,1);
    	rectangle(264,340,376,365); 
	}
	else if(tag==6)
	{
    	setlinestyle(0,0,1);
    	setfillstyle(1,WHITE);
    	bar(440,340,504,365);
        puthz(452,344,"ÕÀ≥ˆ",16,24,CYAN);
        setcolor(CYAN);
        setlinestyle(0,0,1);
        rectangle(440,340,504,365);		    
	}
	else if(tag==7)
	{
		setfillstyle(1,LIGHTRED);      
		bar(460,297,540,317);
		puthz(468,299,"”ŒøÕµ«¬º",16,16,WHITE);
	}
}

void Dark_Login(int pos)                            
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
    switch (pos)
	{
	case 1:
		bar(170,210,545,235);
		break;
	case 2:
		bar(170,245,545,270);
		break;
	case 3:
		setfillstyle(1, RED);
	    bar(260,290,380,325);
        puthz(291,295,"µ«¬º",24,34,WHITE);
		break;
	case 4:
		setlinestyle(0,0,1);
	    setfillstyle(1,WHITE);
	    bar(136,340,200,365);
        puthz(148,344,"◊¢≤·",16,24,LIGHTBLUE);
	    setlinestyle(0,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(136,340,200,365);
	    break;
	case 5:
		setlinestyle(0,0,1);
	    setfillstyle(1,WHITE);
		bar(264,340,376,365);
        puthz(276,344,"Õ¸º«√‹¬Î",16,24,LIGHTBLUE);
		setlinestyle(0,0,2);
	    setcolor(LIGHTBLUE);                                  //Õ¸º«√‹¬ÎøÚ
	    rectangle(264,340,376,365);
	case 6:
	    setlinestyle(0,0,1);
	    setfillstyle(1,WHITE);
		bar(440,340,504,365);
        puthz(452,344,"ÕÀ≥ˆ",16,24,LIGHTBLUE);
		setlinestyle(0,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(440,340,504,365);
		break;
	case 7:
		setfillstyle(1, RED);
	    bar(460,297,540,317);
		puthz(468,299,"”ŒøÕµ«¬º",16,16,WHITE);
		break;
	}
}

int Judge_Login(char *a,char *p,int *n)
{
	int l;
	int i;
	FILE *fp;
	USER *temp=NULL;
	if((fp=fopen(".\\TEXT\\USER.dat","rb+"))==NULL)
	{
		printf("\nError on open file UESR.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);
	l=ftell(fp)/sizeof(USER);
	for(i=0;i<l;i++)
	{
		if((temp=(USER*)malloc(sizeof(USER)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(USER),SEEK_SET);
		fread(temp,sizeof(USER),1,fp);
		if(strcmp(a,temp->account)==0)
		{         
			if(strcmp(p,temp->password)!=0)
			{
				puthz(550,250,"√‹¬Î¥ÌŒÛ",16,16,RED);
				break;
			}
			else if(strcmp(p,temp->password)==0)
			{   *n=temp->num;
				puthz(550,250,"√‹¬Î’˝»∑",16,16,RED);
				if(temp!=NULL)
				{
					free(temp);
					temp=NULL;
				} 
				if(fclose(fp)!=0)
				{
					printf("\nError on close UESR.dat!");
					delay(3000);
					exit(1);
				}
				return 1;
			}
		}
	}
	if(i==l)
	{
		puthz(550,215,"’À∫≈Œ¥◊¢≤·",16,16,RED);
	}
	
	if(temp!=NULL)
	{
		free(temp);
		temp=NULL;
	} 
	if(fclose(fp)!=0)
	{
		printf("\nError on close UESR.dat!");
		delay(3000);
		exit(1);
	}
	return 0;
}




