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
			//��ǰ������ 
			if(mouse_press(470,50,620,100)==2)
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
				Draw_Reserve(pos);
				MouseS=0;
				Input_Data_Special_Book(num,pos);	
				continue;
			}
			//��ԤԼ���� 
		}
		//��Ŀ1 
		if(MouseX>170&&MouseX<620&&MouseY>100&&MouseY<150)
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
		//��Ŀ2 
		if(MouseX>170&&MouseX<620&&MouseY>150&&MouseY<200)
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
		//��Ŀ3 
		if(MouseX>170&&MouseX<620&&MouseY>200&&MouseY<250)
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
		//��Ŀ4 
		if(MouseX>170&&MouseX<620&&MouseY>250&&MouseY<300)
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
		//��Ŀ5
		if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)//�ڷ��ؼ���
		{  
	        if(mouse_press(50,425,140,460)==2)
    		{ 
			    MouseS=1;	  			 
    			if(mark==0)
				{
					mark=6;
					Light_Go(6);	
				}				
				continue;
			}
			else if(mouse_press(50,425,140,460)==1)
			{
				Light_Go(6);				   
				MouseS=0;
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=6;
				break;
			}
		}
		if(MouseX>490&&MouseX<590&&MouseY>425&&MouseY<460)//�ڷ��ؼ���
		{  
	        if(mouse_press(490,425,590,460)==2)
    		{ 
			    MouseS=1;	  			 
    			if(mark==0)
				{
					mark=7;
					Light_Go(7);	
				}				
				continue;
			}
			else if(mouse_press(490,425,590,460)==1)
			{
				Light_Go(7);				   
				MouseS=0;
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX, MouseY);
				*page=636;
				break;
			}
		}
		if(mark!=0)
		{
			Dark_Go(mark);
			mark=0;
		}		 
		if(pos==0)
		{
			if(tag!=0)
			{
				Dark_Special_Book(tag);
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
	puthz(45,18,"��Ŀ����",24,24,RED);
	puthz(272,18,"��ϸ����",24,24,RED);
	puthz(495,18,"ԤԼ״��",24,24,RED);
	
	sgraph(20,50,620,100);
	puthz(45,68,"����ԤԼ",24,24,BLUE);
	puthz(293,68,"ǰ��",24,24,BLUE);
	puthz(525,68,"ԤԼ",24,24,BLUE);
	
	sgraph(20,100,620,150); 
	puthz(45,118,"�������",24,24,BLUE);
	puthz(293,118,"ǰ��",24,24,BLUE);
	puthz(525,118,"ԤԼ",24,24,BLUE);
	
	sgraph(20,150,620,200); 
	puthz(45,168,"��Ա����",24,24,BLUE);
	puthz(293,168,"ǰ��",24,24,BLUE);
	puthz(525,168,"ԤԼ",24,24,BLUE);
	
	sgraph(20,200,620,250); 
	settextstyle(1,0,3);
	setcolor(BLUE);
	outtextxy(60,214,"VR"); 
	puthz(93,218,"����",24,24,BLUE);
	puthz(293,218,"ǰ��",24,24,BLUE);
	puthz(525,218,"ԤԼ",24,24,BLUE);
	
	sgraph(20,250,620,300); 
	puthz(33,268,"��ɫ��ɽ��",24,24,BLUE);
	puthz(293,268,"ǰ��",24,24,BLUE);
	puthz(525,268,"ԤԼ",24,24,BLUE);
	
	cover(50,425,140,460,GREEN);
	puthz(70,430,"����",24,24,WHITE);
	
	bar(490,425,590,460);
	puthz(492,430,"�ҵ�ԤԼ",24,24,WHITE);	
}

void Light_Special_Book(int x1,int y1,int x2,int y2,int tag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	 if(tag==11)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,70,"ԤԼ",24,24,RED);
	}
	else if(tag==12)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,120,"ԤԼ",24,24,RED);
	}
	else if(tag==13)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,170,"ԤԼ",24,24,RED);	
	}
	else if(tag==14)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,220,"ԤԼ",24,24,RED);	
	}
	else if(tag==15)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,270,"ԤԼ",24,24,RED);	
	}
}

void Dark_Special_Book(int tag)
{
	
	clrmous(MouseX, MouseY);
	delay(10);
	switch(tag)
	{  
	    
	    case 11:
	    	cover(472,52,618,98,WHITE);
			puthz(525,70,"ԤԼ",24,24,BLUE);
			break;
	    case 12:
	    	cover(472,102,618,148,WHITE);
			puthz(525,120,"ԤԼ",24,24,BLUE);
			break;
		case 13:
			cover(472,152,618,198,WHITE);
			puthz(525,170,"ԤԼ",24,24,BLUE);
			break;
		case 14:
			cover(472,202,618,248,WHITE);
			puthz(525,220,"ԤԼ",24,24,BLUE);
			break;
		case 15:
			cover(472,252,618,298,WHITE);
			puthz(525,270,"ԤԼ",24,24,BLUE);
			break;	
	}			   
}
void Light_Go(int mark)
{
	clrmous(MouseX,MouseY);
	delay(10);
	if(mark==1)
	{
		cover(170+2,50+2,470-2,100-2,LIGHTGRAY);
		puthz(293,68,"ǰ��",24,24,RED);	
	}
	else if(mark==2)
	{
		cover(170+2,100+2,470-2,150-2,LIGHTGRAY);
		puthz(293,118,"ǰ��",24,24,RED);
	}
	else if(mark==3)
	{
		cover(170+2,150+2,470-2,200-2,LIGHTGRAY);
		puthz(293,168,"ǰ��",24,24,RED);
	}
	else if(mark==4)
	{
		cover(170+2,200+2,470-2,250-2,LIGHTGRAY);
		puthz(293,218,"ǰ��",24,24,RED);	
	}
	else if(mark==5)
	{
		cover(170+2,250+2,470-2,300-2,LIGHTGRAY);
		puthz(293,268,"ǰ��",24,24,RED);
	}
	else if(mark==6)
	{
		cover(50,425,140,460,CYAN);
		puthz(70,430,"����",24,24,LIGHTRED);
	}
	else if(mark==7)
	{
		cover(490,425,590,460,CYAN);
		puthz(492,430,"�ҵ�ԤԼ",24,24,LIGHTRED);
	}
}

void Dark_Go(int mark)
{
	clrmous(MouseX,MouseY);
	delay(10);
	if(mark==1)
	{
		cover(170+2,50+2,470-2,100-2,WHITE);
		puthz(293,68,"ǰ��",24,24,BLUE);	
	}
	else if(mark==2)
	{
		cover(170+2,100+2,470-2,150-2,WHITE);
		puthz(293,118,"ǰ��",24,24,BLUE);
	}
	else if(mark==3)
	{
		cover(170+2,150+2,470-2,200-2,WHITE);
		puthz(293,168,"ǰ��",24,24,BLUE);
	}
	else if(mark==4)
	{
		cover(170+2,200+2,470-2,250-2,WHITE);
		puthz(293,218,"ǰ��",24,24,BLUE);	
	}
	else if(mark==5)
	{
		cover(170+2,250+2,470-2,300-2,WHITE);
		puthz(293,268,"ǰ��",24,24,BLUE);
	}
	else if(mark==6)
	{
		cover(50,425,140,460,GREEN);
		puthz(70,430,"����",24,32,WHITE);
	}
	else if(mark==7)
	{
		cover(490,425,590,460,GREEN);
		puthz(492,430,"�ҵ�ԤԼ",24,24,WHITE);
	}
}
void Input_Data_Special_Book(int *num,int pos)				//��ԤԼ����Ŀ������û����ļ��� 
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

void Special_1(int *page)
{   
    cleardevice();
	bkcolor();     
    setcolor(RED);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	puthz(220,50,"��갴���⴦��������ͼ����",16,16,RED);
	puthz(100,100,"������Ŀ����",24,24,RED);
	puthz(300,100,"�����������ԤԼ",24,24,RED);
    puthz(100,150,"����ʱ��",24,24,RED);	
	outtextxy(300,150,"8:00~22:30");
	puthz(100,200,"���ŵص�",24,24,RED);
	puthz(300,200,"����ʱ�������",24,24,RED); 
	puthz(296,250,"���",24,24,RED);
	puthz(50,300,"����Ʒ������ʱ����ɫ�����ṩ����ʳ",24,24,RED);
    outtextxy(461,300,",");
	puthz(461,300,"ÿ����л�",24,24,RED);
	puthz(50,350,"���ܶ�Ա��������",24,24,RED);
	outtextxy(245,350,",");
	puthz(255,350,"����ʱ�Ƴ���ɫ��ʳ��",24,24,RED);
	outtextxy(498,350,",");
	puthz(508,350,"��ʢ��",24,24,RED);
	puthz(50,400,"��ʳ�������Ĺ���",24,24,RED);
	outtextxy(245,400,",");
	puthz(255,400,"ԤԼ�������ۿ��Լ����ŶӸ���",24,24,RED);
	delay(500);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,639,479)==1)
    	{   	
			clrmous(MouseX, MouseY);
	        delay(100);
			save_bk_mou(MouseX, MouseY);
	        *page=63;
            break;		    
    	}	
    }
} 

void Special_2(int *page)
{   
    cleardevice();
	bkcolor();     
    setcolor(RED);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	puthz(220,50,"��갴���⴦��������ͼ����",16,16,RED);
	puthz(100,100,"������Ŀ����",24,24,RED);
	puthz(300,100,"�������ԤԼ",24,24,RED);
    puthz(100,150,"����ʱ��",24,24,RED);	
	outtextxy(300,150,"18:00~24:00");
	puthz(100,200,"���ŵص�",24,24,RED);
	puthz(300,200,"���ֽ���",24,24,RED);
	puthz(296,250,"���",24,24,RED);
	puthz(98,300,"���ֽ�����ÿ������ٰ�ҹ��ƹ���",24,24,RED);
	outtextxy(485,300,",");
	puthz(495,300,"ÿ���վ�",24,24,RED);
	puthz(50,350,"�춯���Ӽ���",24,24,RED);
	outtextxy(197,350,",");
	puthz(207,350,"����Ŀ���ܴ���ϲ��",24,24,RED);
	outtextxy(426,350,",");
	puthz(436,350,"����˴��ڵ�",24,24,RED);
	puthz(50,400,"һ�º���",24,24,RED);
	outtextxy(150,400,",");
	puthz(160,400,"��ǰԤԼ����Ԥ���Լ����ǵ���λ",24,24,RED); 
	delay(500);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,639,479)==1)
    	{   	
			clrmous(MouseX, MouseY);
	        delay(100);
			save_bk_mou(MouseX, MouseY);
	        *page=63;
            break;		    
    	}	
    }
} 

void Special_3(int *page)
{   
    cleardevice();
	bkcolor();     
    setcolor(RED);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	puthz(220,50,"��갴���⴦��������ͼ����",16,16,RED);
	puthz(100,100,"������Ŀ����",24,24,RED);
	outtextxy(300,100,"VIP");
	puthz(335,100,"����ԤԼ",24,24,RED);
    puthz(100,150,"ԤԼʱ��",24,24,RED);	
	outtextxy(300,150,"00:00~24:00");
	puthz(100,200,"���ϵص�",24,24,RED);
	puthz(300,200,"������",24,24,RED);
	puthz(296,250,"���",24,24,RED);
	puthz(98,300,"Ϊ���ṩ˽�˵��λ���˽�˷�����Ա",24,24,RED);
	outtextxy(485,300,",");
	puthz(495,300,"Ϊ���ṩ",24,24,RED);
	puthz(50,350,"ר������԰����",24,24,RED); 
	outtextxy(221,350,",");
	puthz(231,350,"����ͨ��",24,24,RED);
	outtextxy(327,350,",");
	puthz(337,350,"�Լ������ص��������",24,24,RED);
	puthz(50,400,"��Ŀ",24,24,RED);
	outtextxy(100,400,",");
	puthz(110,400,"����Ŀ�ķ���������������������˿�",24,24,RED); 
	delay(500);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,639,479)==1)
    	{   	
			clrmous(MouseX, MouseY);
	        delay(100);
			save_bk_mou(MouseX, MouseY);
	        *page=63;
            break;		    
    	}	
    }
} 

void Special_4(int *page)
{   
    cleardevice();
	bkcolor();     
    setcolor(RED);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	puthz(220,50,"��갴���⴦��������ͼ����",16,16,RED);
	puthz(100,100,"������Ŀ����",24,24,RED);
	outtextxy(300,100,"VR");
	puthz(328,100,"�Ӿ�����",24,24,RED);
    puthz(100,150,"ԤԼʱ��",24,24,RED);	
	outtextxy(300,150,"10��00~22:00");
	puthz(100,200,"��Ŀ�ص�",24,24,RED);
	puthz(300,200,"��⵺",24,24,RED);
	puthz(296,250,"���",24,24,RED);
	puthz(98,300,"�����ɽ��",24,24,RED);
	outtextxy(220,300,":");
	puthz(220,300,"���ܸ�����ת�ͼ�ת�������",24,24,RED);
	puthz(50,350,"�̼�",24,24,RED); 
	outtextxy(100,350,"!");
	puthz(110,350,"����������԰",24,24,RED);
	outtextxy(257,350,":");
	puthz(267,350,"����̽��",24,24,RED);
	outtextxy(365,350,",");
	puthz(375,350,"���",24,24,RED);
	outtextxy(425,350,",");
	puthz(385,350,"�ƻõ����������",24,24,RED);
	puthz(50,400,"�������Ϸ�Լ���ͬ���Ļ�����",24,24,RED); 
	delay(500);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,639,479)==1)
    	{   	
			clrmous(MouseX, MouseY);
	        delay(100);
			save_bk_mou(MouseX, MouseY);
	        *page=63;
            break;		    
    	}	
    }
} 

void Special_5(int *page)
{   
    cleardevice();
	bkcolor();     
    setcolor(RED);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	puthz(220,50,"��갴���⴦��������ͼ����",16,16,RED);
	puthz(100,100,"������Ŀ����",24,24,RED);
	puthz(300,100,"��ɫ��ɽ��",24,24,RED);
    puthz(100,150,"ԤԼʱ��",24,24,RED);	
	outtextxy(300,150,"8:00~22:00");
	puthz(100,200,"��Ŀ�ص�",24,24,RED);
	puthz(300,200,"��������",24,24,RED);
	puthz(296,250,"���",24,24,RED);
	puthz(98,300,"�ں��˿���",24,24,RED);
	outtextxy(220,300,",");
	puthz(230,300,"���͵�����",24,24,RED);
	outtextxy(353,300,",");
	puthz(363,300,"���յ����µȴ�ͳԪ",24,24,RED); 
	puthz(50,350,"������Ч",24,24,RED); 
	outtextxy(150,350,",");
	puthz(160,350,"�ƹ��Լ��µĸй�����",24,24,RED);
	outtextxy(400,350,",");
	puthz(410,350,"��ɫ��ɽ���᲻��",24,24,RED);
	puthz(50,400,"�ڵľ��в�ͬ��������ɫ��ɽ��",24,24,RED); 
	delay(500);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,639,479)==1)
    	{   	
			clrmous(MouseX, MouseY);
	        delay(100);
			save_bk_mou(MouseX, MouseY);
	        *page=63;
            break;		    
    	}	
    }
} 

void My_Special_Book(&page,&num)
{
	int i;				//�����û� 
	int j;				//����Ѿ�ԤԼ����Ŀ 
	int m;				//��ӡ�Ѿ�ԤԼ����Ŀ 
	int l;				//�����ļ����� 
	int mark[5]={0};	//���ļ��������ĿԤԼ�����ӡ���������� 
	FILE *fp;
	USER us;

	clrmous(MouseX,MouseY);
	delay(1000);
	save_bk_mou(MouseX,MouseY);
	cleardevice();
	Draw_Mybook();
	
	while(1)
	{
		i=0;
		j=0; 
		m=0;
		if((fp=fopen(".\\TEXT\\USER.dat","rb+"))==NULL)
		{
			printf("\nErroe on open file USER.dat!");
			delay(3000);
			exit(1);						
		}											//���ļ���ʱʱ������ĿԤԼ��� 
		fseek(fp,0,SEEK_END);
		l=ftell(fp)/sizeof(USER);
		for(i=0;i<l;i++)
		{
			fseek(fp,i*sizeof(USER),SEEK_SET);
			fread(&us,sizeof(USER),1,fp);
			if(*num==us.number)
			{
				for(i=0,j=0;i<5;i++)
				{
					if(us.special[i]==1)
					{
						mark[j++]=i;
					}
				}			      	
			}
		}	
									//���ļ��������ĿԤԼ����ŵ��������棨����У� 
        if(j==0)
		{
			highlight(20,50,620,100,RED);
			puthz(176,59,"����ǰ����ԤԼ��Ŀ",32,32,RED);
		}
		if(j!=0)
		{
			for(m=0;m<j;m++)            
			{
				switch(mark[m])
				{
					case 0:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"����ԤԼ",24,24,BLUE);
						puthz(195,50*(m+1)+20,"",24,24,BLUE);
						puthz(357,50*(m+1)+20,"��ԤԼ",24,24,BLUE);
						puthz(525,50*(m+1)+20,"ȡ��",24,24,BLUE);
						break;
					case 1:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"�����ﳵ",24,24,BLUE);
						puthz(195,50*(m+1)+20,"��ͨ����",24,24,BLUE);
						puthz(357,50*(m+1)+20,"��ԤԼ",24,24,BLUE);
						puthz(525,50*(m+1)+20,"ȡ��",24,24,BLUE);
						break;
					case 2:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"���˫��",24,24,BLUE);							
						puthz(195,50*(m+1)+20,"����ʱ��",24,24,BLUE);
						puthz(357,50*(m+1)+20,"��ԤԼ",24,24,BLUE);
						puthz(525,50*(m+1)+20,"ȡ��",24,24,BLUE);	
						break;				
					case 3:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"�����籩",24,24,BLUE);
						puthz(195,50*(m+1)+20,"쫷���",24,24,BLUE);
						puthz(357,50*(m+1)+20,"��ԤԼ",24,24,BLUE);
						puthz(525,50*(m+1)+20,"ȡ��",24,24,BLUE);
						break;
					case 4:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"ľ��˫��",24,24,BLUE);
						puthz(195,50*(m+1)+20,"���ֽ���",24,24,BLUE);
						puthz(357,50*(m+1)+20,"��ԤԼ",24,24,BLUE);
						puthz(525,50*(m+1)+20,"ȡ��",24,24,BLUE); 
						break;
					case 5:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"Ħ����",24,24,BLUE);
						puthz(195,50*(m+1)+20,"��⵺",24,24,BLUE);
						puthz(357,50*(m+1)+20,"��ԤԼ",24,24,BLUE);
						puthz(525,50*(m+1)+20,"ȡ��",24,24,BLUE); 
						break;
					case 6:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"����ջ��",24,24,BLUE);
						puthz(195,50*(m+1)+20,"��������",24,24,BLUE);
						puthz(357,50*(m+1)+20,"��ԤԼ",24,24,BLUE);
						puthz(525,50*(m+1)+20,"ȡ��",24,24,BLUE); 
						break;
					case 7:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"���ٷɳ�",24,24,BLUE);
						puthz(195,50*(m+1)+20,"��������",24,24,BLUE);
						puthz(357,50*(m+1)+20,"��ԤԼ",24,24,BLUE);
						puthz(525,50*(m+1)+20,"ȡ��",24,24,BLUE); 
						break;
				}
			}
		}				//���ļ�ԤԼ��������������ӡ������ת�Ƶ���Ļ�� 
		while(1)
		{
			newmouse(&MouseX,&MouseY,&press);
			for(m=0;m<j;m++)
			{
				if(MouseX>470&&MouseX<620&&MouseY>50*(m+1)&&MouseY<50*(m+2))   //���һֱ�˴���δ��� 
				{  
	       			if(mouse_press(470,50*(m+1),620,50*(m+2))==2) 
    				{	
						MouseS=1;
              			highlight(470+1,50*(m+1)+1,620-1,50*(m+2)-1,LIGHTBLUE);				
						continue;
					}
					else if(mouse_press(470,50*(m+1),620,50*(m+2))==1)   //��������ȡ��ԤԼ 
					{
						M_Input_Data(num,mark[m]);	
						MouseS=0;
						clrmous(MouseX, MouseY);
						delay(100);
						save_bk_mou(MouseX, MouseY);
						goto error;
					}
				}
			}
			if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)//�ڷ��ؼ���
			{  
	       		if(mouse_press(50,425,140,460)==2)
    			{ 
				    MouseS=1;	  			 
    				setcolor(RED);
	   				setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	   				setfillstyle(1,CYAN);
	    			bar(50,425,140,460);
	    			rectangle(50,425,140,460);	
					puthz(70,430,"����",24,24,LIGHTCYAN);				
					continue;
				}
				else if(mouse_press(50,425,140,460)==1)
				{				   
					MouseS=0;
					clrmous(MouseX, MouseY);
					delay(100);
					save_bk_mou(MouseX, MouseY);
					*page=6;
					goto right;
				}
			}
			if(MouseX>490&&MouseX<580&&MouseY>425&&MouseY<460)   //��ת����һҳ 
			{  
	      		if(mouse_press(490,425,580,460)==2)
    			{
    				MouseS=1;
    				setcolor(RED);
	    			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    			setfillstyle(1,RED);
	    			bar(490,425,580,460);
	    			rectangle(490,425,580,460);	
					puthz(500,430,"��һҳ",24,24,LIGHTCYAN);				
					continue;
				}
				else if(mouse_press(490,425,580,460)==1)
				{		
					MouseS=0;
					clrmous(MouseX, MouseY);
					delay(100);
					save_bk_mou(MouseX, MouseY);
					*page=62;
					goto right;
				}
			}
		}
		error:  
		cover(19,51,621,401,LIGHTGRAY);                    
		if(fclose(fp)!=0)
		{
			printf("\nErroe on close USER.dat!");
			delay(3000);
			exit(1);
		}	
	}
	right:
	delay(100); 
}

void Draw_Mybook()
{
	cleardevice();
	bkcolor();
	graph(20,10,620,50);
	puthz(45,20,"��Ŀ����",24,24,RED);
	puthz(195,20,"��������",24,24,RED);
	puthz(345,20,"��Ŀʱ��",24,24,RED);
	puthz(495,20,"ȡ��ԤԼ",24,24,RED);
	cover(560,380,620,420,WHITE)
	highlight(560,380,620,420,BLACK);
	puthz(562,388,"����",24,32,RED);
}

void Change_Data_Special_Book(int *num,int tag)	
{
	int l;
	int i;
	FILE *fp;
	USER *n=NULL;
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
			n->special[tag]=0;
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
