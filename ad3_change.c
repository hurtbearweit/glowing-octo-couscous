#include"public.h"
#include"3.h"
#include"3_change.h"
#include"3_off.h"

/************************************************************************
FUNCTION:Ad3_Change
DESCRIPTION:��·����Ա�鿴�г���Ϣ
INPUT:������ת���Ʊ���page
RETURN:��
************************************************************************/
void Ad3_Change(int* page)//��·����Ա������
{
	int flag=0; //��ǵ������
	int pos1=0; //��ǳ�����������
	int jun=0; //�����ʽ�ж�
	char N[5]={"\0"}; //������ĳ�
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Ad3_Change();
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>320&&MouseX<424&& MouseY>154&& MouseY<179)//���������
		{
			if(mouse_press(320,154,424,179)==2)               
			{
				MouseS=2;				
				if(flag==0&&pos1==0)
				{
					Ad3_Lighten(8);
					flag=8;
				}
				continue;
			}
			else if(mouse_press(320,154,424,179)==1)        
			{
				MouseS=0;    
				Ad3_Lighten(8);
				N[0]='\0';                                   //���֮ǰ������
				Input_Vis(N,320,154,4,LIGHTGRAY);            //��������
				if(strlen(N)!=0)                             //�ж��Ƿ��������
					pos1=1;                                  //�����������б��
				else
					pos1=0;
				continue;
			}
	    }
		if(MouseX>183&&MouseX<183+295&& MouseY>390&& MouseY<390+37)//��ѯ
		{
			if(mouse_press(183, 390, 183 + 295, 390 + 37)==2)               
			{
				MouseS=1;                                   //�����Ϊ�����̬
				if(flag==0)                  
				{
		            Ad3_Lighten(7);
					flag=7;                                
				}
				continue;
			}
			else if(mouse_press(183, 390, 183 + 295, 390 + 37)==1)        
			{
				MouseS=0;
				Ad3_Lighten(7);   
                if(Ad3_Change_Jundge(N))
                {
					MouseS=0;
					setlinestyle(SOLID_LINE,0,NORM_WIDTH); //��ʾ��ѯ��ʾ
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, WHITE);
		            puthz(274,220,"���ڲ�ѯ",24,24,RED);
		            stablack(282,270,3);
					stablack(282,270,3);
					delay(500);
					stablack(320,270,3);
					delay(500);
					stablack(358,270,3);
					delay(500);
					Ad3_Off(N); //�����г�ʱ�̱��޸Ľ���
					break;
				}
				else //��ʾ��ʽ�����޷���ɲ�ѯ
				{
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, WHITE);
		            puthz(274,220,"���ڲ�ѯ",24,24,RED);
					stablack(282,270,3);
					stablack(282,270,3);
					delay(500);
					stablack(320,270,3);
					delay(500);
					stablack(358,270,3);
					delay(500);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, WHITE);
		            puthz(274,230,"��ʽ����",24,24,RED);
		            delay(3000);
					return;
				}
				continue;
			}
	    }		
		if(MouseX>274&&MouseX<379&&MouseY>352&&MouseY<372)//����
		{
			if(mouse_press(274,252,379,372)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(274,252,379,372)==1)
			{
				MouseS=0;
				flag=0;
				pos1=0;
				N[0]='\0';
				Draw_Ad3_Change();
				delay(200);
				continue;
			}
		}
		if(MouseX>55&&MouseX<160&&MouseY>437&&MouseY<457)//�˳�
		{
			if(mouse_press(55,437,160,457)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(55,437,160,457)==1)
			{
				MouseS=0;
				*page=8;
				break;
			}
		}
        if(flag!=0)
		{
			MouseS=0;
            if(flag==7)
			{
               Ad3_Darken(7);
			}
			if(flag==8&&pos1==0)
			{
               Ad3_Darken(8);
			}
            flag=0;			
	    }
		if(MouseS!=0)                               //��ԭ���
		{                 
			MouseS=0;
		}
	}
}

/************************************************************************
FUNCTION:Draw_Ad3_Change
DESCRIPTION:������·����Ա�鿴�г���Ϣ����
INPUT:��
RETURN:��
************************************************************************/
int Draw_Ad3_Change()
{
	
	int offset = 15;
	int i,color,x,y,k;
	int x1=80;
	int y1=240;
	int x2=639-x1;
	int a=22;
	int b=7;
    
	cleardevice();
	cover(0, 0, 639, 479, WHITE);
	highlight(0, 0, 639, 479, LIGHTGREEN);//background
	cover(118, 10, 118 + 405, 10 + 32, BLUE);
	highlight(118, 10, 118 + 405, 10 + 32, CYAN);
	puthz(168, 14, "��ӭ�����������ʱ��ģʽ", 24, 24 + 2, WHITE);//title

	cover(605, 180, 639, 479, LIGHTGRAY);
	highlight(605, 180, 639, 479, GREEN);
	triangle(585, 180, 639, 180, 639, 80, GREEN);
	trianglefill(585 + 2, 180 - 2, 639 - 2, 180 - 2, 639 - 2, 80 + 2, GREEN);
	cover(0, 0, 36, 300, LIGHTGRAY);
	highlight(0, 0, 36, 300, GREEN);
	triangle(0, 400, 0, 300, 50, 300, GREEN);
	trianglefill(0 + 2, 400 - 2, 0 + 2, 300 - 2, 50 + 2, 300 - 2, GREEN);//decoration of bk

	search_choose_words_bk(70 + 60, 99, 22, LIGHTGRAY, LIGHTCYAN);
	puthz(71 + 60, 100.75, "�������������Ϣ���Ա�ϵͳ���Ҷ�Ӧ�г���", 16, 18, MAGENTA);
	search_choose_words_bk(113, 150 + 8, 7, LIGHTGRAY, LIGHTCYAN);
	puthz(114, 159.75, "�������г�����", 16, 17, MAGENTA);
	setcolor(DARKGRAY);                                   //������ʾ����Ϊ��ɫ
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtextxy(300,154,"G");
	search_choose_enter_24bk(69 + 250+3, 155, 4, DARKGRAY, LIGHTCYAN);//********�г����������
	
	cover(183, 390, 183 + 295, 390 + 37, YELLOW);
	highlight(183, 390, 183 + 295, 390 + 37, CYAN);	
	puthz(255 + 10, 392, "��ѯ����", 32, 32, RED);
	draw_exit(60, 440, WHITE, RED, BLUE, CYAN);
	draw_refresh(279, 355, WHITE, DARKGRAY, LIGHTGREEN, LIGHTGREEN);
	
	k=230;
	setcolor(BLACK);
	setlinestyle(1, 0, 3);
	line(x1, k, x1 + 280, k);
	puthz(x1+1, k - 20, "����ǰ�г�ͣ��վʾ����", 16, 17,BROWN);
	delay(100);
	setcolor(BLACK);
	k+=70;
	for (i=0;i<(x2-x1)/a;i++)
	{
		if (i%2==0)
		{
			
			cover(x1+i*a,y1,(i+1)*a+x1,y1+b,LIGHTBLUE);
			delay(30);
		}
		if (i%2)
		{
		    cover(x1+i*a,y1,(i+1)*a+x1,y1+b,LIGHTGRAY);
			delay(30);
			
		}
		if (i%5==0)
			{
			   stalightred(x1+i*a+a/2,y1+b/2,8);
			}
	} 
	y1+=70;
	delay(200);
	setlinestyle(1, 0, 3);
	line(x1, k, x1 + 280, k);
	puthz(x1+1, k - 20, "�������г�ͣ��վʾ����", 16, 17,BROWN);
	delay(100);
	 for (i=0;i<(x2-x1)/a;i++)
	{
		if (i%2==0)
		{
			
			cover(x1+i*a,y1,(i+1)*a+x1,y1+b,LIGHTBLUE);
			delay(20);
		}
		if (i%2)
		{
		    cover(x1+i*a,y1,(i+1)*a+x1,y1+b,LIGHTGRAY);
			delay(20);
			
		}
		if (i%10==0)
			{
			   stalightred(x1+i*a+a/2,y1+b/2,8);
			}
	}
}

/************************************************************************
FUNCTION:Ad3_Change_Jundge
DESCRIPTION:�жϹ���Ա���������Ƿ����Ҫ��
INPUT:����ĳ��Σ��꣬�£���
RETURN:��
************************************************************************/
int Ad3_Change_Jundge(char* N) //�ж�����ĳ��Ρ��ꡢ�¡��ո�ʽ�Ƿ����Ҫ��
{
	int len1,len2,len3,len4;
	int flag=1;
	int i;
	len1=strlen(N);

	if(len1==0)
	{
		flag=0;
	}
	for(i=0;i<len1;i++)
	{
		if(!(N[i]>='0'&&N[i]<='9'))
		{
			flag=0;
			break;
		}
	}
	if(flag==1) //�����жϽ��
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
