#include"public.h"
#include"pass.h"
/************************************************************************
FUNCTION:Pass
DESCRIPTION:ʵ�ֳ˿͹���
INPUT:������ת���Ʊ���page���˿ʹ���identity
RETURN:��
************************************************************************/
void Pass(int *page,int identity)
{
	int flag=0; //��ǵ������
	int tag; //��ǳ˿�״̬��1Ϊ������2Ϊ�ܽӣ�3Ϊȷ��
	clrmous(MouseX, MouseY);
	delay(100);
    save_bk_mou(MouseX, MouseY);
	tag=Pass_Tag(identity);
	Draw_Pass(tag);
	Pass_Name(identity);
	Pass_City_Get(identity);

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 492 && MouseX < 619 && MouseY> 80 && MouseY < 105)
		{
			if (mouse_press(492,80,619,105) == 2)//�鿴�˳���¼δ���
			{
				MouseS = 1;
				if (flag== 0)//��ֹ���ظ�����
				{
		            Pass_Lighten(1);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(492, 80, 619, 105) == 1)//�鿴�˳���¼����
			{
				MouseS = 0;
				Pass_Lighten(1);
				*page=51;
				break;
			}
		}
		if (MouseX > 500 && MouseX < 605 && MouseY> 447 && MouseY < 467)
		{
			if (mouse_press(500, 447, 605, 467) == 2)//����˳�δ���
			{
				MouseS=1;
				continue;
			}
			else if (mouse_press(500, 447, 605, 467) == 1)//����˳����
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				*page =1;
				break;
				//�л����˿͵�¼����
			}
		}

        if (flag!= 0)
		{
			MouseS = 0;
			if (flag== 1)
			{
				Pass_Darken(1);
			}
				flag= 0;                    //��λnum
			}
			if (MouseS != 0)
			{
				MouseS = 0;
			}
		}
		
}

/************************************************************************
FUNCTION:Draw_Pass
DESCRIPTION:���Ƴ˿͹��ܽ���
INPUT:�˿͵�ǰ״̬i
RETURN:��
************************************************************************/
void Draw_Pass(int i)
{
	cleardevice();
	if (i == 1)
	{
		cover(0, 0, 470, 479, WHITE);
		map();
		cover(471, 0, 639, 479, LIGHTGRAY);
		highlight(471, 0, 639, 479, GREEN);
		ring(555, 263, 60, 50, GREEN, LIGHTGRAY, 2);
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, LIGHTGREEN);
		highlight(472, 0, 639, 479, LIGHTGREEN);//�������
		puthz(485, 337, "���ڹ�ȥ����ȥ��", 16, 17, BLACK);
		setcolor(BLACK);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
		outtextxy(622,330,":");
		
		//******************* һ�д����� ����Ÿ�Ϊֹ��һ�����ں� 
		/*��ɫ��ͷ*/
		setcolor(GREEN);
		line(546, 300, 565, 300);
		line(546, 250, 546, 300);
		line(565, 250, 565, 300);//����
		line(520, 272, 532, 272);
		line(579, 272, 591, 272);//����ˮƽ��
		line(532, 272, 546, 250);
		line(579, 272, 565, 250);//�ڲ�б��
		line(520, 272, 555.5, 220);
		line(591, 272, 555.5, 220);
		floodfill(555.5, 270, GREEN);
		//�鿴�˳���¼
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTRED);
		//�����쳣
		cover(492, 129 + 15, 619, 159 + 15, WHITE);
		highlight(492, 129 + 15, 619, 159 + 15, GREEN);
		puthz(492 + 10, 129 + 3 + 15, "�����쳣", 24, 28, GREEN);
		//�˳�ϵͳ
		draw_exit(505, 450, LIGHTGRAY,BROWN,BLACK,GREEN);
		draw_date(15, 70, BLACK, DARKGRAY);
		setcolor(LIGHTBLUE);
		setlinestyle(0, 0, 3);
		circle(30,90,12);
		puthz(50,84,";������",16,16,BLACK);
	}
	if (i == 2)
	{
		cover(0, 0, 470, 479, WHITE);
		map();
		cover(471, 0, 639, 479, LIGHTGRAY);
		highlight(471, 0, 639, 479, GREEN);
		ring(555, 263, 60, 50, YELLOW, LIGHTGRAY, 2);
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, YELLOW);
		highlight(472, 0, 639, 479, YELLOW);//�������
		puthz(485, 337, "���ڹ�ȥ����ȥ��", 16, 17, BLACK);
		setcolor(BLACK);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
		outtextxy(622,330,":");
		/*��ɫ̾��*/
		cover(547, 227, 547 + 15, 227 + 50, YELLOW);
		stayellow(547 + 7.5, 227 + 50 + 15, 10);
		//�鿴�˳���¼
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTRED);
		//�����쳣
		cover(492, 129 + 15, 619, 159 + 15, WHITE);
		highlight(492, 129 + 15, 619, 159 + 15, YELLOW);
		puthz(492 + 10, 129 + 3 + 15, "�й��ܽ�", 24, 28, LIGHTMAGENTA);
		//�˳�ϵͳ
		draw_exit(505, 450, LIGHTGRAY,BROWN,BLACK,GREEN);
		draw_date(15, 70, BLACK, DARKGRAY);
		setcolor(LIGHTBLUE);
		setlinestyle(0, 0, 3);
		circle(30,90,12);
		puthz(50,84,";������",16,16,BLACK);
	}
	if (i == 3)
	{
		cover(0, 0, 470, 479, WHITE);
		map();
		cover(471, 0, 639, 479, LIGHTGRAY);
		highlight(471, 0, 639, 479, GREEN);
		ring(555, 263, 63, 50, RED, LIGHTGRAY, 2);
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, RED);
		highlight(472, 0, 639, 479, RED);//�������
		puthz(485, 337, "���ڹ�ȥ����ȥ��", 16, 17, BLACK);
		setcolor(BLACK);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
		outtextxy(622,330,":");
		/*̾��*/
		cover(547, 227, 547 + 15, 227 + 50, RED);
		stared(547 + 7.5, 227 + 50 + 15, 10);
		//�鿴�˳���¼
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTRED);
		//�����쳣
		cover(492, 129 + 15, 619, 159 + 15, WHITE);
		highlight(492, 129 + 15, 619, 159 + 15, RED);
		puthz(492 + 10, 129 + 3 + 15, "��Ҫ����", 24, 28, LIGHTMAGENTA);
		//�˳�ϵͳ
		draw_exit(505, 450, LIGHTGRAY,BROWN,BLACK,GREEN);
		draw_date(15, 70, BLACK, DARKGRAY);
		setcolor(LIGHTBLUE);
		setlinestyle(0, 0, 3);
		circle(30,90,12);
		puthz(50,84,";������",16,16,BLACK);
	}
}

/************************************************************************
FUNCTION:Pass_Lighten
DESCRIPTION:�˿ͽ��水ť����
INPUT:�������Ʊ���flag
RETURN:��
************************************************************************/
int Pass_Lighten(int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	switch (flag)
	{
	case 1:
		setfillstyle(1, WHITE);
		setcolor(CYAN);
		bar(492, 80, 619, 105);
		highlight(492, 80, 619, 105,LIGHTMAGENTA);
		puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTMAGENTA);
		break;
	case 2:
		setfillstyle(1, LIGHTGRAY);
		bar(81.72, 358.75, 81.72 + 101, 358.75 + 60.5);
		puthz(96, 377, "��һ��", 24, 24.5, WHITE);
		break;
	case 3:
		setfillstyle(1, LIGHTGRAY);
		bar(226, 358.75, 226 + 187, 358.75 + 60.5);
		puthz(247, 376.75, "�鿴�˳��켣", 24, 24.5, WHITE);
		break;
	case 4:
		setfillstyle(1, LIGHTGRAY);
		bar(459.75, 358.75, 459.75 + 101, 358.75 + 60.5);
		puthz(475.88, 377, "��һ��", 24, 24.5, WHITE);
		break;
	}
}

/************************************************************************
FUNCTION:Pass_Darken
DESCRIPTION:�˿ͽ��水ť�ָ�
INPUT:�ָ����Ʊ���flag
RETURN:��
************************************************************************/
int Pass_Darken(int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	switch (flag)
	{
	case 1:
		setfillstyle(1, WHITE);
		setcolor(LIGHTBLUE);
		bar(492, 80, 619, 105);
		highlight(492, 80, 619, 105,LIGHTRED);
		puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTRED);
		break;
	case 2:
		setfillstyle(1, WHITE);
		bar(81.72, 358.75, 81.72 + 101, 358.75 + 60.5);
		highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
		puthz(96, 377, "��һ��", 24, 24.5, LIGHTRED);
		break;
	case 3:
		setfillstyle(1, WHITE);
		bar(226, 358.75, 226 + 187, 358.75 + 60.5);
		highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
		puthz(247, 376.75, "�鿴�˳��켣", 24, 24.5, LIGHTRED);
		break;
	case 4:
		setfillstyle(1, WHITE);
		bar(459.75, 358.75, 459.75 + 101, 358.75 + 60.5);
		highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
		puthz(475.88, 377, "��һ��", 24, 24.5, LIGHTRED);
		break;
	}
}

/************************************************************************
FUNCTION:Pass_Tag
DESCRIPTION:��ȡ�˿�״̬
INPUT:�˿ʹ���n
RETURN:�˿�״̬flag
************************************************************************/
int Pass_Tag(int n) //���ڻ�ȡ�˿�״̬���Ի��Ʋ�ͬ�Ľ���
{
	int l;
	int i;
	int flag=0; //��¼�˿����
	FILE* fp;
	STATE* s=NULL;
	if ((fp=fopen(".\\TEXT\\state.dat","rb+"))==NULL)
	{
		printf("\nError on open file state.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                            //�ļ�ָ�붨λ�����һλ
	l=ftell(fp)/sizeof(STATE);                                      
	for(i=0;i<l;i++)
	{
		if((s=(STATE*)malloc(sizeof(STATE)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
		    exit(1);
		}
		fseek(fp,i*sizeof(STATE),SEEK_SET);                           
		fread(s,sizeof(STATE),1,fp);                                 
		if(n==s->number) //���ļ��в�ѯ����Ӧ�˿�                                  
		{
			if(s->contact==1) //�˿ͱ����Ϊ���нӴ���
			{
				flag=2;
            }
			else if(s->patient!=0) //�˿ͱ����Ϊȷ�ﻼ��
			{
				flag=3;
			}
			else //�˿ʹ�������״̬
			{
				flag=1;
			}		
			if(s!=NULL)                                              //�ͷ��ڴ�
			{
				free(s);
				s=NULL;
			}
			break;
		}
		if(s!=NULL)                                              //�ͷ��ڴ�
		{
			free(s);
			s=NULL;
		}
	}
	if(fclose(fp)!=0)
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
	return flag;
}

/************************************************************************
FUNCTION:Pass_Name
DESCRIPTION:��ʾ�˿�����
INPUT:�˿ʹ���a
RETURN:��
************************************************************************/
int Pass_Name(int a) //��ʾ�˿�����
{
	int flag = 0;
	int n = 0;
	FILE* fp;
	PASSENGER* p;
	if ((fp = fopen(".\\TEXT\\pass.dat", "rb+")) == NULL) //�򿪴洢�û���Ϣ���ļ�
	{
		printf("\nError on open file pass.dat!");
		delay(3000);
		exit(1);
	}
	while (!feof(fp))
	{
		if ((p = (PASSENGER*)malloc(sizeof(PASSENGER))) == NULL)     //����ռ�
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fscanf(fp, "%d", &p->number);
		fgetc(fp);
		fscanf(fp, "%s", p->name);
		fgetc(fp);
		fgets(p->telephone, 12, fp);
		fgetc(fp);
		fgets(p->ID, 19, fp);
		fgetc(fp);
		fgets(p->age, 3, fp);
		fgetc(fp);
		fgets(p->sex, 3, fp);
		fgetc(fp);

		if (p->number == a)
		{
			puthz(502, 30, "���ã�", 16, 17, LIGHTBLUE);
			puthz(497+ 17 * 3 + 2, 30, p->name, 16, 17, LIGHTBLUE);
			puthz(497 + 17 * 6 + 2, 30, "��", 16, 17, LIGHTBLUE);
			if (p != NULL)                                      //�ͷ��ڴ�
			{
				free(p);
				p = NULL;
			}
			break;
		}
		if (p != NULL)                                      //�ͷ��ڴ�
		{
			free(p);
			p = NULL;
		}
	}
	if (p != NULL)                                      //�ͷ��ڴ�
	{
		free(p);
		p = NULL;
	}
	if (fclose(fp) != 0)                                             //�ر��ļ�
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
	return 0;
}

double findx(int x) //���ݳ��д��ţ���ȡ�����ڵ�ͼ�ϵ�x����
{
	double a;
	switch (x)
	{
	case 1:
		a = 232.5;
		break;
	case 2:
		a = 294.5;
		break;
	case 3:
		a = 294.5;
		break;
	case 4:
		a = 294.5;
		break;
	case 5:
		a = 329.5;
		break;
	case 6:
		a = 428.5;
		break;
	case 7:
		a = 93.5;
		break;
	case 8:
		a = 19.5;
		break;
	case 9:
		a = 356.5;
		break;
	case 10:
		a = 93.5;
		break;
	case 11:
		a = 197;
		break;
	case 12:
		a = 197;
		break;
	case 13:
		a = 197;
		break;
	case 14:
		a = 197;
		break;
	case 15:
		a = 197;
		break;
	case 16:
		a = 197;
		break;
	case 17:
		a = 282;
		break;
	case 18:
		a = 19.5;
		break;
	}
	return a;
}

double findy(int x) //���ݳ��д��ţ���ȡ�����ڵ�ͼ�ϵ�y����
{
	double a;
	switch (x)
	{
	case 1:
		a = 26;
		break;
	case 2:
		a = 55.5;
		break;
	case 3:
		a = 125.5;
		break;
	case 4:
		a = 173.5;
		break;
	case 5:
		a = 228.5;
		break;
	case 6:
		a = 273.5;
		break;
	case 7:
		a = 173.5;
		break;
	case 8:
		a = 273.5;
		break;
	case 9:
		a = 296.5;
		break;
	case 10:
		a = 340.5;
		break;
	case 11:
		a = 111.5;
		break;
	case 12:
		a = 173.5;
		break;
	case 13:
		a = 273.5;
		break;
	case 14:
		a = 340.5;
		break;
	case 15:
		a = 416.5;
		break;
	case 16:
		a = 441.5;
		break;
	case 17:
		a = 340.5;
		break;
	case 18:
		a = 416.5;
		break;
	}
	return a;
}

/************************************************************************
FUNCTION:Pass_City_Show
DESCRIPTION:��ʾ�˿͵����ĳ���
INPUT:��������x,y��������ɫhz
RETURN:��
************************************************************************/
int Pass_City_Show(int x, int y, int s, int hz, int space, int mainhzcolor) //��ʾ�˿͵����ĳ���
{
	if (s == 1)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
	if (s == 2)
	{
		puthz(x, y, "���", hz, space, mainhzcolor);
	}
	if (s == 3)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
	if (s == 4)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
	if (s == 5)
	{
		puthz(x, y, "�Ͼ�", hz, space, mainhzcolor);
	}
	if (s == 6)
	{
		puthz(x, y, "�Ϻ�", hz, space, mainhzcolor);
	}
	if (s == 7)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
	if (s == 8)
	{
		puthz(x, y, "�ɶ�", hz, space, mainhzcolor);
	}
	if (s == 9)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
	if (s == 10)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
	if (s == 11)
	{
		puthz(x, y, "̫ԭ", hz, space, mainhzcolor);
	}
	if (s == 12)
	{
		puthz(x, y, "֣��", hz, space, mainhzcolor);
	}
	if (s == 13)
	{
		puthz(x, y, "�人", hz, space, mainhzcolor);
	}
	if (s == 14)
	{
		puthz(x, y, "��ɳ", hz, space, mainhzcolor);
	}
	if (s == 15)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
	if (s == 16)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
	if (s == 17)
	{
		puthz(x, y, "�ϲ�", hz, space, mainhzcolor);
	}
	if (s == 18)
	{
		puthz(x, y, "����", hz, space, mainhzcolor);
	}
}

/************************************************************************
FUNCTION:Pass_City_Get
DESCRIPTION:��ȡ�˿͵������е���Ϣ
INPUT:�˿ʹ���passengera
RETURN:��
************************************************************************/
int Pass_City_Get(int passengera) //��ȡ�˿�ȥ���ĳ�����Ϣ
{
	double x, y; //Ŀ����еĶ�Ӧ����
	int i = 0; //for��丨������
	int j, temp;
	int *idep;    //
	int *iarr;
	int a = passengera; //��ǰ�˿ʹ���
	int n = 0;
	int count = 0;
	int *showcity;
	int leftupx = 485;
	int leftupy = 364;
	int kuan = 38;
	int gao = 22;
	int size;
	int flag=0; // ���ڱ���Ѿ���ѯ����ǰ�˿�
	FILE* fp;
	RECORD* r = NULL;
	idep = (int*)malloc(6 * sizeof(int));
	iarr = (int*)malloc(6 * sizeof(int));
	showcity = (int*)malloc(12 * sizeof(int));
	if ((fp = fopen(".\\TEXT\\record.dat", "rb+")) == NULL) 
	{
		printf("\nError on open file record.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_SET);
	while (!feof(fp))
	{
		if ((r = (RECORD*)malloc(sizeof(RECORD))) == NULL)                      //����ռ�
		{
			printf("\nMemory not enough!");
			return 0;
		}
		fscanf(fp, "%d", &r->contact);
		
		if (r->contact == -1)
		{
			break;
		}
		fgetc(fp);
		fscanf(fp, "%d", &r->number);
		fgetc(fp);
		fscanf(fp, "%s", r->month);
		fgetc(fp);
		fscanf(fp, "%s", r->day);
		fgetc(fp);
		fscanf(fp, "%s", r->train_number);
		fgetc(fp);
		fscanf(fp, "%s", r->carriage);
		fgetc(fp);
		fscanf(fp, "%s", r->sit);
		fgetc(fp);
		fscanf(fp, "%d", &r->origin);
		fgetc(fp);
		fscanf(fp, "%d", &r->terminal);
		fgetc(fp);

		if (r->number==a)    //***** �ҵ�ָ���˿� !!!!ע��������û�б����� û�еĻ�Ҫ���³�ʼ�� 
		{
			idep[i] = r->origin;
			showcity[count] = r->origin;
			count++;
			iarr[i] = r->terminal;
			showcity[count] = r->terminal;
			count++;
			i++;
			n++;
			flag=1;
		}
		else if(flag==1) //�ó˿͵ĳ˳���¼�Ѿ���ȡ��ϣ�����ѭ��
		{
			flag=0;
			if (r != NULL)
		    {
			    free(r);
			    r = NULL;
		    }
			break;
		}
		if (r != NULL)
		{
			free(r);
			r = NULL;
		}
	}
	if (r != NULL)
		{
			free(r);
			r = NULL;
		}
	if (fclose(fp) != 0)
	{
		printf("\nError on close record.dat!");
		delay(3000);
		exit(1);
	}
	//����ȥ��վ����ȷ�� 
	for (i = 0; i < count; i++)		//ѭ���ж�������ÿһ����
	{
		for (j = i + 1; j < count; j++)	//�ж�a[i]��ߵ����Ƿ��a[i]���
		{
			if (showcity[i] == showcity[j])
			{
				for (temp = j; temp < count; temp++)
					showcity[temp] = showcity[temp + 1];	//��a[j]�����Ԫ��ȫ��ǰ��һ��λ��
				j--;	//a[j+1]ȡ��a[j]λ�ã�Ϊʹ�´δ�a[j+1]��ʼ����,j��һ(Ϊʹj���ֲ���)
				count--;	//���鳤�ȼ�һ
			}
		}
	}
	size = count-1;
	while (count < 12)
	{
		showcity[count] = 0;
		count++;
	}
	for (count = 0; showcity[count] != 0; count++)
	{
		if (showcity[count])
		{
			x = findx(showcity[count]) - 12.0;
			y = findy(showcity[count]) - 3.0;
			setcolor(LIGHTBLUE);
			setlinestyle(0, 0, 3);
			if(showcity[count]==1||showcity[count]==4||showcity[count]==6||showcity[count]==12||showcity[count]==14)
			{
			    circle(findx(showcity[count]), findy(showcity[count]), 14);
			    circle(findx(showcity[count]), findy(showcity[count]), 16);
			}
			else
			{
				circle(findx(showcity[count]), findy(showcity[count]), 10);
			    circle(findx(showcity[count]), findy(showcity[count]), 12);
			}
			// drawStar(x,y,LIGHTRED,LIGHTRED,LIGHTRED);
		}  //showcity�Ѿ��ѵ�һ����ĵص���ʾ���� 
	}
	if (showcity!=NULL)
	{
		for (count = 0; (showcity[count] != 0) && (count < 9); count++)
	{

		if (count % 3 || count == 0)
		{
			Pass_City_Show(leftupx, leftupy, showcity[count], 16, 17, BLUE);
			leftupx = leftupx + kuan;
			if (count != size)
			{
                 puthz(leftupx, leftupy, "��", 16, 17, BLUE);
			}
			leftupx = leftupx + 10;
		}
		if((!(count%3))&& (count != 0))
		{
			leftupx = 485;
			leftupy = leftupy + gao;
			Pass_City_Show(leftupx, leftupy, showcity[count], 16, 17, BLUE);
			leftupx = leftupx + kuan;
			if (count != size)
			{
				puthz(leftupx-2,leftupy, "��", 16, 17, BLUE);
			}
			leftupx = leftupx + 10;
		}
	}
	if (size>=9)
	{
		leftupx = 485;
		leftupy = leftupy + gao;
		puthz(leftupx+30+17, leftupy, "�ȳ���", 16, 17, BLUE);
	}
	if (idep != NULL)
		free(idep);
	if (iarr != NULL)
		free(iarr);
	if (showcity != NULL)
		free(showcity);	
	}
	return 0;
}