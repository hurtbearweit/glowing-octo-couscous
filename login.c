#include"public.h"
#include"login.h"
#include"welcome.h"

void Login(int *page)
{
	int pos1=0;
	int pos2=0;
	int tag=0;
	char account[15]; 
	char password[15];
	
	clrmous(MouseX,MouseY);
    delay(100);
    save_bk_mou(MouseX,MouseY);
    Draw_Login(); 
    
    while(1)
    {
    	newmouse(&MouseX,&MouseY,&press);
    	//ÒÆÖÁÕËºÅ 
    	if(MouseX>170&&MouseX<545&&MouseY>203&&MouseY<235);
    	{
    		pos1=0;
    		if(mouse_press(170,203,545,235)==2)
    		{
    			MouseS=2;
    			if(tag==0&&pos1==0)
    			{
    				Light_Login(1);
    				tag=1;
				}
				continue;
			}
			else if(mouse_press(170,203,545,235)==1)
			{
				Light_Login(1);
				MouseS=0;
				account[0]='\0';
				continue;
			}
		}
		//ÒÆÖÁÃÜÂë 
		if(MouseX>170&&MouseX<545&&MouseY>245&&MouseY<277)
		{
			pos2=0;
			if(mouse_press(170,245,545,277)==2)
			{
				MouseS=2;
				if(tag==0&&pos2==0)
				{
					Light_Login(2);
					tag=2;
				}
				continue;
			}
			else if(mouse_press(170,245,545,277)==1)
			{
				Light_Login(2);
				MouseS=0;
				password[0]='\0';
				continue;
			}
		}
		//ÒÆÖÁµÇÂ¼ 
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
				continue;
			}
		}
		//ÒÆÖÁ×¢²á 
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
				*page=3;
				break;
			}
		}
		//ÒÆÖÁÐÞ¸ÄÃÜÂë 
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
		//ÒÆÖÁÍË³ö 
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
				break;
			}
		}
		if(tag!=0)
		{
			MouseS=0;
			if(pos1=0)
			{
				Dark_Login(1);
			}
			if(pos2=0)
			{
				Dark_Login(2);
			}
			if(tag==3||tag==4||tag==5||tag==6)
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

int  Draw_Login()
{
	cleardevice();
	setbkcolor(8);     //±³¾° 
	
	setfillstyle(1,BLUE);
	bar(0,0,640,60);
	bar(0,440,640,480);
	puthz(240,14,"Îäºº»¶ÀÖ¹È",32,32,LIGHTGRAY);
	
	puthz(95,203,"ÕËºÅ",32,32,CYAN);
	puthz(95,245,"ÃÜÂë",32,32,CYAN);
	
	setfillstyle(1,WHITE);
	bar(170,203,545,235);
	bar(170,245,545,277);
	
	setfillstyle(1, RED);
    bar(260,290,380,325);
    puthz(291,295,"µÇÂ¼",24,34,WHITE);
    
    setfillstyle(1,WHITE);
    bar(136,340,200,365);
    puthz(148,344,"×¢²á",16,24,LIGHTBLUE);
    setlinestyle(0,0,1);
    setcolor(LIGHTBLUE);
    rectangle(136,340,200,365);
    
    bar(264,340,376,365);
    puthz(276,344,"ÐÞ¸ÄÃÜÂë",16,24,LIGHTBLUE);
    rectangle(264,340,376,365);
    
    bar(440,340,504,365);
    puthz(452,344,"ÍË³ö",16,24,LIGHTBLUE);
    rectangle(440,340,504,365);
} 

int Light_Login(int tag)
{
	clrmous(MouseX,MouseY);
	delay(10);
	
	if(tag==1)
	{
		setcolor(MAGENTA);       //Êó±êÒÆÖÁÕËºÅÀ¸ 
		setfillstyle(1,LIGHTGRAY);
		setlinestyle(0,0,1);
		bar(170,203,545,235);
		rectangle(170,203,545,235);
	}
	else if(tag==2)
	{
		setcolor(MAGENTA);       //Êó±êÒÆÖÁÃÜÂëÀ¸ 
		setfillstyle(1,LIGHTGRAY);
		setlinestyle(0,0,1);
		bar(170,245,545,277);
		rectangle(170,245,545,277);
	}
	else if(tag==3)
	{
		setcolor(WHITE);
		setlinestyle(0,0,1);
		setfillstyle(1,LIGHTRED);      
		bar(260,290,380,325);
		puthz(291,295,"µÇÂ¼",24,34,WHITE);
	}
	else if(tag==4)
	{
			setlinestyle(0,0,1);
			setfillstyle(1,WHITE);            
			bar(136,340,200,365);
            puthz(148,344,"×¢²á",16,24,CYAN);
            setcolor(CYAN);
            setlinestyle(0,0,1);
            rectangle(136,340,200,365);	
	}
	else if(tag==5)
	{
        	setlinestyle(0,0,1);
		    setfillstyle(1,WHITE);
		    bar(264,340,376,365);
    		puthz(276,344,"ÐÞ¸ÄÃÜÂë",16,24,CYAN);
    		setcolor(CYAN);
            setlinestyle(0,0,1);
    		rectangle(264,340,376,365); 
	}
	else if(tag==6)
	{
    		setlinestyle(0,0,1);
    		setfillstyle(1,WHITE);
    		bar(440,340,504,365);
            puthz(452,344,"ÍË³ö",16,24,CYAN);
            setcolor(CYAN);
            setlinestyle(0,0,1);
            rectangle(440,340,504,365);		    
	}
}

int Dark_Login(int pos)                            
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
    switch (pos)
	{
	case 1:
		bar(170,203,545,235);
		break;
	case 2:
		bar(170,245,545,277);
		break;
	case 3:
		setfillstyle(1, RED);
	    bar(260,290,380,325);
        puthz(291,295,"µÇÂ¼",24,34,WHITE);
		break;
	case 4:
		setlinestyle(0,0,1);
	    setfillstyle(1,WHITE);
	    bar(136,340,200,365);
        puthz(148,344,"×¢²á",16,24,LIGHTBLUE);
	    setlinestyle(0,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(136,340,200,365);
	    break;
	case 5:
		setlinestyle(0,0,1);
	    setfillstyle(1,WHITE);
		bar(264,340,376,365);
        puthz(276,344,"ÐÞ¸ÄÃÜÂë",16,24,LIGHTBLUE);
		setlinestyle(0,0,2);
	    setcolor(LIGHTBLUE);//ÐÞ¸ÄÃÜÂë¿ò
	    rectangle(264,340,376,365);
	case 6:
	    setlinestyle(0,0,1);
	    setfillstyle(1,WHITE);
		bar(440,340,504,365);
        puthz(452,344,"ÍË³ö",16,24,LIGHTBLUE);
		setlinestyle(0,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(440,340,504,365);
		break;
	}
}





