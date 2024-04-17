#include"public.h"

void Special_Book(int *page,int *num)
{
	int tag=0;
    int pos=0;
    int mark=0;
    
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Special_Book();
	delay(500);
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if(MouseX>170&&MouseX<620&&MouseY>50&&MouseY<100)
		{
			if(mouse_press(170,50,470,100)==2)
			{
				MouseS=1;
				if(mark==0)
				{
					mark=1;
					Light_Go(1);
				}
				continue;
			}
			else if(mouse_press(170,50,470,100)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				*page=631;
				break;
			}
			//在前往键上 
			else if(mouse_press(470,50,620,100)==2)
			{
				MouseS=1;
				if(pos!=11)
				{
					if(tag==0)
					{
						tag=11;
						Light_Special_Book(470,50,620,100,11);
					}
				}
				continue;
			}
			else if(mouse_press(470,50,620,100)==1)
			{
				pos=11;
				Draw_Special_Book(pos);
				MouseS=0;
				Input_Data_Special_Book(num,pos);	
				continue;
			}
			//在预约键上 
		}
		//项目1 
		if(MouseX>470&&MouseX<620&&MouseY>100&&MouseY<150)
		{
			if(mouse_press(170,100,470,150)==2)
			{
				MouseS=1;
				if(mark==0)
				{
					mark=2;
					Light_Go(2);
				}
				continue;
			}
			else if(mouse_press(170,100,470,150)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				*page=632;
				break;
			}
			else if(mouse_press(470,100,620,150)==2)
			{
				MouseS=1;
				if(pos!=12)
				{
					if(tag==0)
					{
						tag=12;
						Light_Special_Book(470,100,620,150,12);
					}
				}
				continue;
			}
			else if(mouse_press(470,100,620,150)==1)
			{
				pos=12;
				Draw_Reserve(pos);
				MouseS=0;
				Input_Data_Special_Book(num,pos);
				continue;
			}
		}
		//项目2 
		if(MouseX>470&&MouseX<620&&MouseY>150&&MouseY<200)
		{
			if(mouse_press(170,150,470,200)==2)
			{
				MouseS=1;
				if(mark==0)
				{
					mark=3;
					Light_Go(3);
				}
				continue;
			}
			else if(mouse_press(170,150,470,200)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				*page=633;
				break;
			}
			else if(mouse_press(470,150,620,200)==2)
			{
				MouseS=1;
				if(pos!=13)
				{
					if(tag==0)
					{
						tag=13;
						Light_Special_Book(470,150,620,200,13);
					}
				}
				continue;
			}
			else if(mouse_press(470,150,620,200)==1)
			{
				pos=13;
				Draw_Reserve(pos);
				MouseS=0;
				Input_Data_Special_Book(num,pos); 
				continue;
			}
		}
		//项目3 
		if(MouseX>470&&MouseX<620&&MouseY>200&&MouseY<250)
		{
			if(mouse_press(170,200,470,250)==2)
			{
				MouseS=1;
				if(mark==0)
				{
					mark=4;
					Light_Go(4);
				}
				continue;
			}
			else if(mouse_press(170,200,470,250)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				*page=634;
				break;
			}
			else if(mouse_press(470,200,620,250)==2)
			{
				MouseS=1;
				if(pos!=14)
				{
					if(tag==0)
					{
						tag=14;
						Light_Special_Book(470,200,620,250,14);
					}
				}
				continue;
			}
			else if(mouse_press(470,200,620,250)==1)
			{
				pos=14;
				Draw_Reserve(pos);
				MouseS=0;
				Input_Data_Special_Book(num,pos);	
				continue;
			}
		}
		//项目4 
		if(MouseX>470&&MouseX<620&&MouseY>250&&MouseY<300)
		{
			if(mouse_press(170,250,470,300)==2)
			{
				MouseS=1;
				if(mark==0)
				{
					mark=5;
					Light_Go(5);
				}
				continue;
			}
			else if(mouse_press(170,250,470,300)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				*page=635;
				break;
			}
			if(mouse_press(470,250,620,300)==2)
			{
				MouseS=1;
				if(pos!=15)
				{
					if(tag==0)
					{
						tag=15;
						Light_Special_Book(470,250,620,300,15);
					}
				}
				continue;
			}
			else if(mouse_press(470,250,620,300)==1)
			{
				pos=15;
				Draw_Reserve(pos);
				MouseS=0;
				Input_Data_Special_Book(num,pos);
				continue;	
			}
		}
		//项目5
		if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)//在返回键上
		{  
	        if(mouse_press(50,425,140,460)==2)
    		{ 
			    MouseS=1;	  			 
    			if(tag==0)
				{
					tag=1;
					Light_Special_Book(50,425,140,460,1);	
				}				
				continue;
			}
			else if(mouse_press(50,425,140,460)==1)
			{
				Light_Special_Book(50,425,140,460,1);				   
				MouseS=0;
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=6;
				break;
			}
		}
	/*	if(mark!=0)
		{
			Dark_Go(mark);
			mark=0;	
		}		 		 
	*/	if(pos==0)
		{
			if(tag!=0)
			{
				R_List_Dark(tag);
				tag=0;
			}
		}	 
		if(MouseS!=0)
		{
			MouseS=0;
		}   
	}
}

void Draw_Special_Book()
{
	cleardevice();
	bkcolor();
	sgraph(20,10,620,50);
	puthz(45,18,"项目名称",24,24,RED);
	puthz(272,18,"详细介绍",24,24,RED);
	puthz(495,18,"预约状况",24,24,RED);
	
	sgraph(20,50,620,100);
	puthz(45,68,"餐饮预约",24,24,BLUE);
	puthz(293,68,"前往",24,24,BLUE);
	puthz(525,68,"预约",24,24,BLUE);
	
	sgraph(20,100,620,150); 
	puthz(45,118,"特殊表演",24,24,BLUE);
	puthz(293,118,"前往",24,24,BLUE);
	puthz(525,118,"预约",24,24,BLUE);
	
	sgraph(20,150,620,200); 
	puthz(45,168,"会员导览",24,24,BLUE);
	puthz(293,168,"前往",24,24,BLUE);
	puthz(525,168,"预约",24,24,BLUE);
	
	sgraph(20,200,620,250); 
	settextstyle(1,0,3);
	setcolor(BLUE);
	outtextxy(60,214,"VR"); 
	puthz(93,218,"体验",24,24,BLUE);
	puthz(293,218,"前往",24,24,BLUE);
	puthz(525,218,"预约",24,24,BLUE);
	
	sgraph(20,250,620,300); 
	puthz(33,268,"特色过山车",24,24,BLUE);
	puthz(293,268,"前往",24,24,BLUE);
	puthz(525,268,"预约",24,24,BLUE);
	
	cover(50,425,140,460,GREEN);
	puthz(70,430,"返回",24,24,WHITE);
	
	bar(490,425,590,460);
	puthz(492,430,"我的预约",24,24,WHITE);	
}

void  Light_Special_Book(int x1,int y1,int x2,int y2,int tag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	if(tag==1)
	{
		setcolor(RED);
	    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	    setfillstyle(1,CYAN);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(70,430,"返回",24,24,LIGHTCYAN);
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
}

void Dark_Special_Book(int tag)
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
	    case 11:
	    	cover(471,51,619,99,WHITE);
	    	highlight(471,51,619,99,RED);
			puthz(525,70,"预约",24,24,BLUE);
			break;
	    case 12:
	    	cover(471,101,619,149,WHITE);
	    	highlight(471,101,619,149,RED);
			puthz(525,120,"预约",24,24,BLUE);
			break;
		case 13:
			cover(471,151,619,199,WHITE);
			highlight(471,151,619,199,RED);
			puthz(525,170,"预约",24,24,BLUE);
			break;
		case 14:
			cover(471,201,619,249,WHITE);
			highlight(471,201,619,249,RED);
			puthz(525,220,"预约",24,24,BLUE);
			break;
		case 15:
			cover(471,251,619,299,WHITE);
			highlight(471,251,619,299,RED);
			puthz(525,270,"预约",24,24,BLUE);
			break;	
	}			   
}

void Light_Go(int mark)
{
	clrmous(MouseX,MouseY);
	delay(10);
	if(mark==1)
	{
		cover(x1+1,y1+1,x2-1,y2-1,LIGHTGRAY);
		puthz(525,70,"预约",24,24,RED);	
	}
	else if(tag==2)
	{
		setcolor(RED);
		setlinestyle(0,0,3);
		rectangle(60,260,240,360);
		setfillstyle(1,LIGHTGRAY);
		bar(60,260,240,360);
		puthz(102,298,"在线门票",24,24,LIGHTRED);	
	}
	else if(tag==3)
	{
		setcolor(RED);
		setlinestyle(0,0,3);
		rectangle(400,100,580,200);
		setfillstyle(1,LIGHTGRAY);
		bar(400,100,580,200);
		puthz(442,126,"特殊服务",24,24,LIGHTRED);
		puthz(442,150,"在线预约",24,24,LIGHTRED);	
	}
	else if(tag==4)
	{
		setcolor(RED);
		setlinestyle(0,0,3);
		rectangle(400,260,580,360);
		setfillstyle(1,LIGHTGRAY);
		bar(400,260,580,360);
		puthz(442,298,"路线推荐",24,24,LIGHTRED);	
	}
	else if(tag==5)
	{
		setfillstyle(1,LIGHTGRAY);
		bar(560,380,620,420);
		puthz(562,388,"返回",24,32,LIGHTRED);
	}
}

void Input_Data_Special_Book(int *num,int pos)				//将预约的项目读入该用户的文件中 
{  
	int l;
	int i;
	FILE *fp;
	USER *n;
	if((fp=fopen(".\\TEXT\\USER.dat","rb+"))==NULL)
	{
		printf("\nErroe on open file USER.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);
	l=ftell(fp)/sizeof(USER);
	for(i=0;i<l;i++)
	{
		if((n=(USER*)malloc(sizeof(USER)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(USER),SEEK_SET);
		fread(n,sizeof(USER),1,fp);
		if(*num==n->num)
		{
			n->special[pos-11]=1;
			fseek(fp,i*sizeof(USER),SEEK_SET);
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
