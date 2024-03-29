#include"public.h"
#include"track.h"
#include"pass.h"
/************************************************************************
FUNCTION:Track
DESCRIPTION:查看乘客乘客轨迹
INPUT:存储乘客乘客记录的结构体R
RETURN:无
************************************************************************/
int Track(struct Record R)
{
	int tag; //标记当前乘车记录的密接情况
	
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
			
			if (mouse_press(500, 447, 605, 467) == 2)//点击退出未点击
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(500, 447, 605, 467) == 1)//点击退出点击
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				return;
				//切换到乘客登录界面
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
DESCRIPTION:绘制查看乘客乘客轨迹界面
INPUT:无
RETURN:无
************************************************************************/
int Draw_Track()
{
	int hl = WHITE;   //边框颜色
	int co = YELLOW;  //矩形填充颜色
	int hz = RED;  //汉字颜色

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
	puthz(482, 15, "本次乘车轨迹", 24, 25, CYAN);
	draw_exit(505, 450, LIGHTGRAY, BLUE, 6, GREEN);
	puthz(494, 49 + 40, "车次：", 16, 18, hz);
	cover(555, 48 + 40, 555 + 56, 48 + 21 + 40, co);//*********在框中显示车次
	highlight(555, 48 + 40, 555 + 56, 48 + 21 + 40, hl);

	puthz(494, 74 + 51, "出发站", 16, 18, hz);
	cover(555, 73 + 51, 555 + 56, 73 + 21 + 51, co);//*********在框中显示出发站
	highlight(555, 73 + 51, 555 + 56, 73 + 21 + 51, hl);
	
	puthz(494, 100 + 62, "到达站", 16, 18, hz);
	cover(555, 99 + 62, 555 + 56, 99 + 21 + 62, co);//*********在框中显示到达站
	highlight(555, 99 + 62, 555 + 56, 99 + 21 + 62, hl);

	puthz(494, 69 + 135, "车厢：", 16, 18, hz);
	cover(555, 65 + 135, 555 + 56, 65 + 21 + 135, co);//*********在框中显示车厢
	highlight(555, 65 + 135, 555 + 56, 65 + 21 + 135, hl);
	
	puthz(494, 100 + 135, "座位：", 16, 18, hz);
	cover(555, 99 + 135, 555 + 56, 99 + 21 + 135, co);//*********在框中显示座位
	highlight(555, 99 + 135, 555 + 56, 99 + 21 + 135, hl);

	puthz(494, 121 + 148, "乘车日期：", 16, 18, hz);
	cover(487, 150 + 148, 620, 150 + 21 + 148, co);//*********在框中显示乘车日期
	highlight(487, 150 + 148, 620, 150 + 21 + 148, hl);

	puthz(494, 187 + 145, "涉疫情况：", 16, 18, hz);
	cover(487, 215 + 145, 620, 215 + 21 + 145, co);//*********在框中显示是否密接
	highlight(487, 215 + 145, 620, 215 + 21 + 145, hl);
	
	 
}

/************************************************************************
FUNCTION:Track_Show
DESCRIPTION:显示乘客轨迹
INPUT:乘客状态tag,存储乘车记录的结构体R
RETURN:无
************************************************************************/
int Track_Show(int tag,struct Record R)
{
	int hl = WHITE;   //边框颜色
	int co = YELLOW;  //矩形填充颜色
	int hz = RED;  //汉字颜色
	int ori_time = 0; //记录上车站上车站在该列车站点中的位置
	int i; // for语句辅助参数
	int size; //记录当前乘车记录所经站点总数
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
	City_Search(R.origin,origin); //获取起点站名
	City_Search(R.terminal,terminal); //获取终点站名
	
	setcolor(MAGENTA);  //图例注释 
	circle(23, 17, 8);
	circle(23, 17, 11);
	puthz(38,10,"为起始站",16,17,BLACK); 
	setcolor(LIGHTRED);
	circle(23, 52, 8);
	circle(23, 52, 11);
	puthz(38,44,"为经过站",16,17,BLACK); 
	setcolor(LIGHTBLUE);
	circle(23, 87, 8);
	circle(23, 87, 11);
	puthz(38,79,"为终点站",16,17,BLACK); 
    
	if(tag==0)
	{
		puthz(494, 218 + 145, "当前无密接通知", 16, 18, GREEN);
	}
	else if(tag==1)
	{
		puthz(494, 218 + 145, "存在接触的可能", 16, 18,LIGHTRED);
	}
	else
	{
		puthz(494, 218 + 145, "本人为确诊乘客", 16, 18,LIGHTRED);
	}
	setcolor(LIGHTRED);
	settextjustify(0, 2);
	settextstyle(1, 0, 2);
	if(strlen(R.train_number)==3)
	{
		outtextxy(565, 45 + 40, R.train_number); //车次
	}
	else
	{
		outtextxy(572, 45 + 40, R.train_number);
	}
	puthz(566, 76 + 51, origin, 16, 22, hz); //出发站
	puthz(566, 102 + 62, terminal, 16, 22, hz); //到达站
    setcolor(LIGHTRED);
	settextjustify(0, 2);
	settextstyle(1, 0, 2);
	outtextxy(580, 60 + 135+2, R.carriage); //车厢
	outtextxy(572, 97 + 135, R.sit); //车座
	settextjustify(0, 2); //年月日
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
		if(s->off==-1) //off停运代号
		{
			break;
		}
		fscanf(fp,"%d",&s->time); //time站点次序
		fgetc(fp);
		fscanf(fp,"%d",&s->number); //number站点代号
		fgetc(fp);
		fscanf(fp,"%s",s->name);
		fgetc(fp);
		fscanf(fp,"%d",&s->stop);
		getc(fp);
		fscanf(fp,"%s",s->hour);
		fgetc(fp);
		fscanf(fp,"%s",s->minute);
		fgetc(fp);
		if (s->number == R.origin)  //当上车站与时刻表的站点对应上时 
		{
			ori_time = s->time;   //记录上车站的顺序 
			arr[0]=s->number;   //记录上车站的站点序号为第一站点
			size++;
		}
		if ((s->time)>ori_time&&ori_time!=0)
		{
			i++;
			arr[i]=s->number;
			size++;
		}
		//上车后开始在数组中存站点代号 
		if (s->number==R.terminal)  //当下车站与时刻表的站点对应上时 
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
	if (fclose(fp) != 0)                                             //关闭文件
	{
		printf("\nError on close train.dat!");
		delay(3000);
		exit(1);
	}
	
	i = 0;  //初始站
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
    i = size-1;  //到达站
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
    for (i = 1; i < size-1; i++)  //中间站
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
