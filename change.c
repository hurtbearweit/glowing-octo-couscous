#include"public.h"
#include"change.h"
/************************************************************************
FUNCTION:Change
DESCRIPTION:��ɳ˿������޸�
INPUT:������ת���Ʊ���page
RETURN:��
************************************************************************/
void Change(int* page)
{
    int pos1=0;                                             //�ж������1�������
	int pos2=0;                                             //�ж������2�������
	int pos3=0;                                             //�ж������3�������
	int pos4=0;                                             //�ж������4�������
	int flag=0;                                             //�����������������Է��ظ�����
	int jun1=0;                                             //�ж��˺�������
	int jun2=0;                                             //�ж�����������
	int jun3=0;                                             //�ж�ȷ������������
	int jun4=0;                                             //�ж����֤��������
	char A[15]={'\0'};                                      //�˺ţ�6-12λ
	char I[25]={'\0'};                                      //���֤��18λ
	char II[25]={'\0'};                                     //�û��˺Ŷ�Ӧ�����֤��
	char P[20]={'\0'};                                      //���������룬6-12λ
	char RP[20] ={'\0'};                                    //ȷ�����룬6-12λ
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Change();                                          //���޸��������
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);                   //�����
		if(MouseX>95&&MouseX<545&& MouseY>85&& MouseY<110)  //�����������1�ķ�Χ
		{
			if(mouse_press(95,85,545,110)==2)               //δ��������1
			{
				MouseS=2;                                   //�����Ϊ�����̬
				if(flag==0&&pos1==0)                  
				{
					Change_Lighten(95,85,545,110,1);        //���������1
					flag=1;                                 //��������1�ѵ���
				}
				continue;
			}

			else if(mouse_press(95,85,545,110) ==1)         //��������1
			{
				MouseS =0;
				Change_Lighten(95,85,545,110,1);
				A[0]='\0';                                  //���֮ǰ������
				setfillstyle(1,DARKGRAY);
		        bar(550,90,640,106);
				Input_Vis(A,95,85,12,LIGHTGRAY);            //��������
				jun1=C_Account_Jundge(A,II);                //�ж��˺ŵ�ע�����
				if(strlen(A)!= 0)                           //�ж��Ƿ��������
					pos1=1;                                 //�����������б��
				else
					pos1=0;
				continue;
			}
		}
		if(MouseX>95&& MouseX<545&& MouseY>145&& MouseY< 170)
		{
			if(mouse_press(95,145,545,170)==2)     
			{
				MouseS=2;
				if(flag==0&&pos2==0)
				{
					Change_Lighten(95,145,545,170,2);
					flag=2;
				}
				continue;
			}

			else if(mouse_press(95,145,545,170)==1)     
			{
			    Change_Lighten(95,145,545,170,2);
				MouseS=0;
				P[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,150,640,166);
				Input_Invis(P,95,145,16,LIGHTGRAY);
				jun2=C_Password_Jundge(P);               //�ж����볤���Ƿ����Ҫ��
				if(strlen(P)!=0)
					pos2=1;
				else
					pos2=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>205&& MouseY<230)
		{
			if(mouse_press(95,205,545,230) == 2)    
			{
				MouseS=2;
				if(flag==0&&pos3==0)
				{
					Change_Lighten(95,205,545,230,3);
					flag=3;
				}
				continue;
			}

			else if(mouse_press(95,205,545,230)==1)      
			{
				Change_Lighten(95,205,545,230,3);
				MouseS = 0;
				RP[0] ='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,210,640,226);
				Input_Invis(RP,95,205,16,LIGHTGRAY);         //����������
				jun3=C_Password_Same(P,RP);
				if(strlen(RP)!=0)
					pos3=1;
				else
					pos3=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>260&& MouseY<290)
		{
			if(mouse_press(95,265,545,290)==2)      
			{
				MouseS=2;
				if(flag==0&&pos4==0)
				{
					Change_Lighten(95,265,545,290,4);
					flag=4;
				}
				continue;
			}

			else if(mouse_press(95,265,545,290)==1)
			{
				Change_Lighten(95,265,545,290,4);
				MouseS=0;
				I[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				Input_Vis(I,95,265,18,LIGHTGRAY);
				jun4=C_ID_Jundge(I,II);                      //�ж����֤�Ƿ����˺�ƥ��
				if(strlen(I)!=0)
					pos4=1;
				else 
					pos4=0;
				continue;
			}
		}
		if(MouseX>143&&MouseX<237&&MouseY>370&& MouseY<400)
		{
			if(mouse_press(143,370,237,400)==2)                
			{
				if(flag==0)
				{
					MouseS=1;
					Change_Lighten(143,370,237,400,5);
					flag=5;
				}
				continue;
			}

			else if(mouse_press(143,370,237,400)==1)
			{
				MouseS=0;                        //�������
				A[0] = '\0';
				I[0] = '\0';
				P[0] = '\0';
				RP[0] = '\0';
				flag=0;                          //��������
				pos1 = 0;
				pos2 = 0;
				pos3 = 0;
				pos4 = 0;
				return;
			}
		}

		if(MouseX >273&& MouseX<367&& MouseY>370&& MouseY<400)
		{
			if(mouse_press(273,370,367,400) == 2)					
			{
				if (flag==0)
				{
					MouseS=1;
					Change_Lighten(273,370,367,400,6);
					flag=6;
				}
				continue;
			}

			else if(mouse_press(273,370,367,400)==1)
			{
				MouseS=0;
			if (Change_Com(jun1,jun2,jun3,jun4,A,P))     //���������޸�
				{
		            *page=1;
					break;
				}
				else
				{
					return;
				}
			}
		}

		if (MouseX>403&&MouseX<497&&MouseY>370&&MouseY<400)
		{
			if (mouse_press(403, 370, 497, 400) == 2)				
			{
				if (flag==0)
				{
					MouseS=1;
					Change_Lighten(403,370,497,400,7);
					flag=7;
				}
				continue;
			}

		else if(mouse_press(403, 370, 497, 400) == 1)
			{
				MouseS=0;
				*page=1;
				break; 
			}
		}

		if(flag!=0)                                 //���ݵ�����������������л�ԭ
		{
			MouseS=0;
			if(pos1==0)
			{
				Change_Darken(1);
			}
			if (pos2==0)
			{
				Change_Darken(2);
			}
			if (pos3==0)
			{
				Change_Darken(3);
			}
			if (pos4==0)
			{
				Change_Darken(4);
			}
			if (flag==5||flag ==6||flag ==7)
			{
				Change_Darken(flag);
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
FUNCTION:Draw_Change
DESCRIPTION:�����޸��������
INPUT:��
RETURN:��
************************************************************************/
int Draw_Change()
{
    cleardevice();
	setbkcolor(DARKGRAY);                        //���ñ�����ɫ
	
	puthz(255,25,"�޸�����",32,32,WHITE);
	puthz(254,24,"�޸�����",32,32,RED);
	puthz(175,320,"�������Ϣ͸¶������",24,24,BROWN);
	puthz(95,60,"�������˺�",16,16,CYAN);        //��������ʾ
	puthz(95,120,"������������",16,16,CYAN);
    puthz(95,180,"��ȷ������",16,16,CYAN);
    puthz(95,240,"���������֤����",16,16,CYAN);
	
	setviewport(0,0,640,480,1);                  //��С�˺����֤
	setfillstyle(1,YELLOW);
	setcolor(YELLOW);
	circle(50,95,30);
	floodfill(50,95,YELLOW);

    setfillstyle(1,BLUE);
	setcolor(BLUE);
	circle(50,275,30);
	floodfill(50,275,BLUE);
	
	setfillstyle(1,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	circle(50,85,10);
	floodfill(50,85,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	line(50,95,34,115);
	line(34,115,66,115);
	line(66,115,50,95);
	floodfill(50,105,LIGHTGRAY);
	
	setfillstyle(1, WHITE);
	setcolor(WHITE);
	rectangle(30,265,70,285);
	floodfill(35,275, WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(45,268,55,271);
	bar(45,273,65,276);
	bar(45,278,65,281);
	
	setfillstyle(1,WHITE);                     
	bar(95,85,545,110);                          //�������
    bar(95,145,545,170);
	bar(95,205,545,230);
	bar(95,265,545,290);

	setfillstyle(1,GREEN);
	bar(143, 370, 237, 400);
	puthz(161,373,"����",24,34,WHITE);           //��������
    setfillstyle(1,RED);
	bar(273, 370, 367, 400);
	puthz(291,373,"���",24,34,WHITE);
    setfillstyle(1,BLUE);
	bar(403, 370, 497, 400);
	puthz(421,373,"����",24,34,WHITE);
}

/************************************************************************
FUNCTION:Change_Lighten
DESCRIPTION:�޸�������水ť����
INPUT:�������Ʊ���flag
RETURN:��
************************************************************************/
int Change_Lighten(int x1,int y1,int x2,int y2,int flag)//����������
{
	clrmous(MouseX,MouseY);
	delay(10);

	if(flag==5)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,CYAN);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(161,373,"����",24,34,LIGHTCYAN);
	}
	else if(flag== 6)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,RED);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(291,373,"���",24,34,LIGHTRED);
	}
	else if(flag==7)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,BLUE);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(421,373,"����",24,34,LIGHTBLUE);
	}
	else                                       //���������
	{
		setcolor(MAGENTA);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,LIGHTGRAY);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
	}
}

/************************************************************************
FUNCTION:Change_Darken
DESCRIPTION:����ί����Ա���水ť�ָ�
INPUT:�ָ����Ʊ���pos
RETURN:��
************************************************************************/
int Change_Darken(int pos)//���ݵ���������Բ�������л�ԭ
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	switch (pos)
	{
	case 1:                                    //��ԭ�����
		bar(95,85,545,110);
		break;
	case 2:
		bar(95,145,545,170);
		break;
	case 3:
		bar(95,205,545,230);
		break;
	case 4:
		bar(95,265,545,290);
		break;
	case 5:
		setfillstyle(1,GREEN);
		bar(143,370,237,400);
		puthz(161,373,"����",24,34,WHITE);
		break;
	case 6:
		setfillstyle(1,RED);
		bar(273,370,367,400);
		puthz(291,373,"���",24,34,WHITE);
		break;
	case 7:
		setfillstyle(1,BLUE);
		bar(403,370,497,400);
		puthz(421,373,"����",24,34,WHITE);
		break;
	}
}

/************************************************************************
FUNCTION:C_Account_Jundge
DESCRIPTION:�ж�������˺���ȷ
INPUT:������˺�A
RETURN:�жϽ��
************************************************************************/
int C_Account_Jundge(char* A,char* II)
{
	int l;
	int i;
	FILE* fp;
	USER*u=NULL;
	if((fp = fopen(".\\TEXT\\UserData.dat","rb+"))==NULL)//�򿪴洢�û���Ϣ���ļ�
	{
		printf("\nError on close UserData.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                      //�ļ�ָ�붨λ����ͷ
	l=ftell(fp)/sizeof(USER);                                //�����ļ����û�����
	for(i=0;i<l;i++)                                           //���������û�
	{
		if((u=(USER*)malloc(sizeof(USER)))==NULL)              //����ռ�
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(USER),SEEK_SET);                     //�ļ�ָ���ƶ�����i���û�
		fread(u,sizeof(USER),1,fp);                            //��ȡ��i���û�����Ϣ
		if(strcmp(u->account,A)==0)                            //����뵱ǰ�û����˺�ƥ��
		{
			setfillstyle(1,DARKGRAY);
		    bar(550,90,640,106);
		    puthz(550,90,"�˺Ŵ���",16,16,RED);
			strcpy(II,u->ID);                                  //��¼��ǰ�û������֤��
			if(u != NULL)                                      //�ͷ��ڴ�
			{
				free(u);
				u = NULL;
			}
			if(fclose(fp)!= 0)                                 //�ر��ļ�
			{
				printf("\nError on close UserData.dat!");
				delay(3000);
				exit(1);
			}
			return 1;      
	    }
    }
	if(i==l)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,90,640,106);
		puthz(550,90,"�˺Ų�����",16,16,RED);
	    if(u!=NULL)
		{
			free(u);
			u = NULL;
		}
		if(fclose(fp)!= 0)
		{
			printf("\nError on close UserData.dat!");
			delay(3000);
			exit(1);
		}
		return 0;
	}
}


/************************************************************************
FUNCTION:C_ID_Jundge
DESCRIPTION:�ж�������˺ź����֤���Ƿ�ƥ��
INPUT:������˺Ŷ�Ӧ�����֤��II����������֤��I
RETURN:�жϽ��
************************************************************************/
int C_ID_Jundge(char* I,char* II)                    //�ж����֤�Ƿ���������˺�ƥ��
{
	if(strcmp(I,II)==0&&strlen(I)==18)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,270,640,286);
		puthz(550,270,"���֤ƥ��",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,270,640,286);
		puthz(550,270,"���֤��Ч",16,16,RED);
		return 0;
	}
}

/************************************************************************
FUNCTION:C_Password_Jundge
DESCRIPTION:�ж����볤���Ƿ����Ҫ��
INPUT:���������P
RETURN:�жϽ��
************************************************************************/
int C_Password_Jundge(char *P)                      //�ж����볤���Ƿ����Ҫ��
{
	if(strlen(P)>=6)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,150,640,166);
		puthz(550,150,"ͨ��",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,150,640,166);
		puthz(550,150,"�������",16,16,RED);
		return 0;
	}
}	

/************************************************************************
FUNCTION:C_Password_Same
DESCRIPTION:�ж���������������Ƿ�һ��
INPUT:���������P��ȷ������RP
RETURN:�жϽ��
************************************************************************/
int C_Password_Same(char *P,char *RP)              //�ж���������������Ƿ�һ��
{
	if(strcmp(P,RP)==0)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,226);
		puthz(550,210,"����һ��",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,226);
		puthz(550,210,"���벻һ��",16,16,RED);
		return 0;
	}
}

/************************************************************************
FUNCTION:Change_Com
DESCRIPTION:���������޸�
INPUT:�жϽ��jun1,jun2,jun3,jun4,������˺ź�����
RETURN:�жϽ��
************************************************************************/
int Change_Com(int jun1,int jun2,int jun3,int jun4,char* A,char* P)
{
	int l;
	int i;
	FILE* fp;
	USER* u=NULL;
	if(jun1==1&&jun2==1&&jun3==1&&jun4==1)                               //��������ݾ�����Ҫ��
	{
	    if ((fp=fopen(".\\TEXT\\UserData.dat","rb+"))==NULL)
	    {
		    printf("\nError on open file UserData.dat!");
		    delay(3000);
		    exit(1);
	    }
	    fseek(fp,0,SEEK_END);                                            //�ļ�ָ�붨λ�����һλ
	    l=ftell(fp)/sizeof(USER);                                      //�����û�����
	    for(i=0;i<l;i++)
	    {
		    if((u=(USER*)malloc(sizeof(USER)))==NULL)
		    {
			    printf("\nMemory not enough!");
			    delay(3000);
			    exit(1);
		    }
		    fseek(fp,i*sizeof(USER),SEEK_SET);                           //�ļ�ָ���ƶ�����i���û�
		    fread(u,sizeof(USER),1,fp);                                  //����i���û�����Ϣ��Ϣ����u
		    if (strcmp(A,u->account)==0)                                 //���ļ����ҵ��������˺�ƥ����û�
		    {
				strcpy(u->password,P);                                   //�޸Ķ������û���Ϣ�е�����Ϊ������
				fseek(fp,i*sizeof(USER),SEEK_SET);                       //�ļ�ָ�붨λ�����û�
				fwrite(u,sizeof(USER),1,fp);                             //�ø��û��޸ĺ����Ϣ���ǵ�֮ǰ����Ϣ
				if(u!=NULL)                                              //�ͷ��ڴ�
				{
					free(u);
					u=NULL;
				}
				if(fclose(fp)!=0)                                        //�ر��ļ�
				{
					printf("\nError on close UserData.dat!");
					exit(1);
				}
				setfillstyle(SOLID_FILL, WHITE);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                setfillstyle(SOLID_FILL, WHITE);
		        puthz(274,220,"����ע��",24,24,RED);
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
		        puthz(274,230,"�޸ĳɹ�",24,24,RED);
		        delay(3000);
				return 1;
			}
			if(u!=NULL)                                              //�ͷ��ڴ�
			{
				free(u);
				u=NULL;
			}
		}
		if(u!=NULL)
	    {
		    free(u);
		    u=NULL;
	    }
	    if(fclose(fp)!= 0)
	    {
		    printf("\nError on close UserData.dat!");
		    exit(1);
	    }
	}
	 //δ�����޸��������������
	setfillstyle(SOLID_FILL, WHITE);
    bar(200,180,440,300);
    rectangle(200,180,440,300);
    setfillstyle(SOLID_FILL, WHITE);
	puthz(274,220,"���ڱ���",24,24,RED);
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
	puthz(274,230,"�޸�ʧ��",24,24,RED);
	delay(3000);
	return 0;
}