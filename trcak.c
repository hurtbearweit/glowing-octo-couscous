#include"public.h"
#include"track.h"
#include"pass.h"
/************************************************************************
FUNCTION:Track
DESCRIPTION:�鿴�˿ͳ˿͹켣
INPUT:�洢�˿ͳ˿ͼ�¼�Ľṹ��R
RETURN:��
************************************************************************/
int Track(struct Record R)
{
	int tag; //��ǵ�ǰ�˳���¼���ܽ����
	
	clrmous(MouseX, MouseY);
	delay(100);
    save_bk_mou(MouseX, MouseY);
    cleardevice();
	Draw_Track();
	tag=Record_Tag(R.number,R.contact);
	Track_Show(tag,R);
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 500 && MouseX < 605 && MouseY> 447 && MouseY < 467)
		{
			
			if (mouse_press(500, 447, 605, 467) == 2)//����˳�δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(500, 447, 605, 467) == 1)//����˳����
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				return;
				//�л����˿͵�¼����
			}
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/************************************************************************
FUNCTION:Draw_Track
DESCRIPTION:���Ʋ鿴�˿ͳ˿͹켣����
INPUT:��
RETURN:��
************************************************************************/
int Draw_Track()
{
	int hl = WHITE;   //�߿���ɫ
	int co = YELLOW;  //���������ɫ
	int hz = RED;  //������ɫ

	map();
    cover(471,0,639,479,LIGHTGRAY);
	setcolor(BLACK);
	circle(512, 60, 12);
	circle(557, 60, 12);
	circle(602, 60, 12);
	setcolor(BLACK);
	setlinestyle(0,0,3);
	line (492, 60, 620, 60);
	setcolor(LIGHTBLUE);
	setlinestyle(0,0,3);
	line (471,0,471,479);
	line (476,0,476,479);
	puthz(482, 15, "���γ˳��켣", 24, 25, CYAN);
	draw_exit(505, 450, LIGHTGRAY, BLUE, 6, GREEN);
	puthz(494, 49 + 40, "���Σ�", 16, 18, hz);
	cover(555, 48 + 40, 555 + 56, 48 + 21 + 40, co);//*********�ڿ�����ʾ����
	highlight(555, 48 + 40, 555 + 56, 48 + 21 + 40, hl);

	puthz(494, 74 + 51, "����վ", 16, 18, hz);
	cover(555, 73 + 51, 555 + 56, 73 + 21 + 51, co);//*********�ڿ�����ʾ����վ
	highlight(555, 73 + 51, 555 + 56, 73 + 21 + 51, hl);
	
	puthz(494, 100 + 62, "����վ", 16, 18, hz);
	cover(555, 99 + 62, 555 + 56, 99 + 21 + 62, co);//*********�ڿ�����ʾ����վ
	highlight(555, 99 + 62, 555 + 56, 99 + 21 + 62, hl);

	puthz(494, 69 + 135, "���᣺", 16, 18, hz);
	cover(555, 65 + 135, 555 + 56, 65 + 21 + 135, co);//*********�ڿ�����ʾ����
	highlight(555, 65 + 135, 555 + 56, 65 + 21 + 135, hl);
	
	puthz(494, 100 + 135, "��λ��", 16, 18, hz);
	cover(555, 99 + 135, 555 + 56, 99 + 21 + 135, co);//*********�ڿ�����ʾ��λ
	highlight(555, 99 + 135, 555 + 56, 99 + 21 + 135, hl);

	puthz(494, 121 + 148, "�˳����ڣ�", 16, 18, hz);
	cover(487, 150 + 148, 620, 150 + 21 + 148, co);//*********�ڿ�����ʾ�˳�����
	highlight(487, 150 + 148, 620, 150 + 21 + 148, hl);

	puthz(494, 187 + 145, "���������", 16, 18, hz);
	cover(487, 215 + 145, 620, 215 + 21 + 145, co);//*********�ڿ�����ʾ�Ƿ��ܽ�
	highlight(487, 215 + 145, 620, 215 + 21 + 145, hl);
	
	 
}

/************************************************************************
FUNCTION:Track_Show
DESCRIPTION:��ʾ�˿͹켣
INPUT:�˿�״̬tag,�洢�˳���¼�Ľṹ��R
RETURN:��
************************************************************************/
int Track_Show(int tag,struct Record R)
{
	int hl = WHITE;   //�߿���ɫ
	int co = YELLOW;  //���������ɫ
	int hz = RED;  //������ɫ
	int ori_time = 0; //��¼�ϳ�վ�ϳ�վ�ڸ��г�վ���е�λ��
	int i; // for��丨������
	int size; //��¼��ǰ�˳���¼����վ������
	int arr[10]={0};
	char str1[30] = ".\\TEXT\\TRAIN\\";
	char str2[10] = ".dat";
	char origin[5];
	char terminal[5];
	FILE* fp;
	STATION* s;
	strcat(str1, R.train_number);
	strcat(str1, str2);
	i=0;
	size=0;
	City_Search(R.origin,origin); //��ȡ���վ��
	City_Search(R.terminal,terminal); //��ȡ�յ�վ��
	
	setcolor(MAGENTA);  //ͼ��ע�� 
	circle(23, 17, 8);
	circle(23, 17, 11);
	puthz(38,10,"Ϊ��ʼվ",16,17,BLACK); 
	setcolor(LIGHTRED);
	circle(23, 52, 8);
	circle(23, 52, 11);
	puthz(38,44,"Ϊ����վ",16,17,BLACK); 
	setcolor(LIGHTBLUE);
	circle(23, 87, 8);
	circle(23, 87, 11);
	puthz(38,79,"Ϊ�յ�վ",16,17,BLACK); 
    
	if(tag==0)
	{
		puthz(494, 218 + 145, "��ǰ���ܽ�֪ͨ", 16, 18, GREEN);
	}
	else if(tag==1)
	{
		puthz(494, 218 + 145, "���ڽӴ��Ŀ���", 16, 18,LIGHTRED);
	}
	else
	{
		puthz(494, 218 + 145, "����Ϊȷ��˿�", 16, 18,LIGHTRED);
	}
	setcolor(LIGHTRED);
	settextjustify(0, 2);
	settextstyle(1, 0, 2);
	if(strlen(R.train_number)==3)
	{
		outtextxy(565, 45 + 40, R.train_number); //����
	}
	else
	{
		outtextxy(572, 45 + 40, R.train_number);
	}
	puthz(566, 76 + 51, origin, 16, 22, hz); //����վ
	puthz(566, 102 + 62, terminal, 16, 22, hz); //����վ
    setcolor(LIGHTRED);
	settextjustify(0, 2);
	settextstyle(1, 0, 2);
	outtextxy(580, 60 + 135+2, R.carriage); //����
	outtextxy(572, 97 + 135, R.sit); //����
	settextjustify(0, 2); //������
	settextstyle(1, 0, 2);
	setcolor(LIGHTRED);
	outtextxy(500,148 + 148, "2021");
	outtextxy(554,148 + 148, ".");
	outtextxy(560, 148 + 148, R.month);
	outtextxy(581,148 + 148, ".");
	outtextxy(587, 148 + 148, R.day);
	
	
	
	if ((fp = fopen(str1, "rb+")) == NULL) {
		printf("\nError on open this file!");
		return 0;
	}
	while (!feof(fp))
	{
		if ((s= (STATION*)malloc(sizeof(STATION))) == NULL)
		{
			printf("Memory is over!\n");
			return 0;
		}
		fscanf(fp,"%d",&s->off);
		fgetc(fp);
		if(s->off==-1) //offͣ�˴���
		{
			break;
		}
		fscanf(fp,"%d",&s->time); //timeվ�����
		fgetc(fp);
		fscanf(fp,"%d",&s->number); //numberվ�����
		fgetc(fp);
		fscanf(fp,"%s",s->name);
		fgetc(fp);
		fscanf(fp,"%d",&s->stop);
		getc(fp);
		fscanf(fp,"%s",s->hour);
		fgetc(fp);
		fscanf(fp,"%s",s->minute);
		fgetc(fp);
		if (s->number == R.origin)  //���ϳ�վ��ʱ�̱��վ���Ӧ��ʱ 
		{
			ori_time = s->time;   //��¼�ϳ�վ��˳�� 
			arr[0]=s->number;   //��¼�ϳ�վ��վ�����Ϊ��һվ��
			size++;
		}
		if ((s->time)>ori_time&&ori_time!=0)
		{
			i++;
			arr[i]=s->number;
			size++;
		}
		//�ϳ���ʼ�������д�վ����� 
		if (s->number==R.terminal)  //���³�վ��ʱ�̱��վ���Ӧ��ʱ 
		{
			break;
		}
		if(s!=NULL)
		{
			free(s);
			s=NULL;
		}
	}
	if(s!=NULL)
	{
		free(s);
		s=NULL;
	}
	if (fclose(fp) != 0)                                             //�ر��ļ�
	{
		printf("\nError on close train.dat!");
		delay(3000);
		exit(1);
	}
	
	i = 0;  //��ʼվ
	setcolor(MAGENTA);
	if(arr[i]==1||arr[i]==4||arr[i]==6||arr[i]==12||arr[i]==14)
	{
        circle(findx(arr[i]), findy(arr[i]), 12);
        circle(findx(arr[i]), findy(arr[i]), 15);
	}
	else
	{
		circle(findx(arr[i]), findy(arr[i]), 8);
        circle(findx(arr[i]), findy(arr[i]), 11);
	}
    delay(400);
    i = size-1;  //����վ
	setcolor(LIGHTBLUE);
    if(arr[i]==1||arr[i]==4||arr[i]==6||arr[i]==12||arr[i]==14)
	{
        circle(findx(arr[i]), findy(arr[i]), 12);
        circle(findx(arr[i]), findy(arr[i]), 15);
	}
	else
	{
		circle(findx(arr[i]), findy(arr[i]), 8);
        circle(findx(arr[i]), findy(arr[i]), 11);
	}
    delay(1200);
    for (i = 1; i < size-1; i++)  //�м�վ
    {
        setcolor(LIGHTRED);
		if(arr[i]==1||arr[i]==4||arr[i]==6||arr[i]==12||arr[i]==14)
		{
		    circle(findx(arr[i]), findy(arr[i]), 12);
            circle(findx(arr[i]), findy(arr[i]), 15);
	        delay(500);
		}
		else
		{
		    circle(findx(arr[i]), findy(arr[i]), 8);
            circle(findx(arr[i]), findy(arr[i]), 11);
	        delay(500);
		}
    }
	for (i = 0; i <size-1; i++)
	{
		Light_Bet_Sta(arr[i], arr[i + 1],tag); 
		delay(250);
	}
	
}

int Light_Bet_Sta(int a, int b, int statement)
{
	int x1, x2, y1, y2;
	x1 = findx(a);
	x2 = findx(b);
	y1 = findy(a);
	y2 = findy(b);
	if (statement == 0)
	{
		setcolor(CYAN);
		setlinestyle(0, 0, 3);
		line(x1 + 1, y1, x2 + 1, y2);
		setlinestyle(0, 0, 3);
		line(x1 - 1, y1, x2 - 1, y2);
	}
	if (statement == 1||statement==2)
	{
		setcolor(LIGHTRED);
		setlinestyle(0, 0, 3);
		line(x1 + 1, y1, x2 + 1, y2);
		setlinestyle(0, 0, 3);
		line(x1 - 1, y1, x2 - 1, y2);
	}
}
