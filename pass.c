#include"public.h"
#include"pass.h"
/************************************************************************
FUNCTION:Pass
DESCRIPTION:实现乘客功能
INPUT:界面跳转控制变量page，乘客代号identity
RETURN:无
************************************************************************/
void Pass(int *page,int identity)
{
	int flag=0; //标记点亮情况
	int tag; //标记乘客状态，1为正常，2为密接，3为确诊
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
			if (mouse_press(492,80,619,105) == 2)//查看乘车记录未点击
			{
				MouseS = 1;
				if (flag== 0)//防止被重复标亮
				{
		            Pass_Lighten(1);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(492, 80, 619, 105) == 1)//查看乘车记录框点击
			{
				MouseS = 0;
				Pass_Lighten(1);
				*page=51;
				break;
			}
		}
		if (MouseX > 500 && MouseX < 605 && MouseY> 447 && MouseY < 467)
		{
			if (mouse_press(500, 447, 605, 467) == 2)//点击退出未点击
			{
				MouseS=1;
				continue;
			}
			else if (mouse_press(500, 447, 605, 467) == 1)//点击退出点击
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				*page =1;
				break;
				//切换到乘客登录界面
			}
		}

        if (flag!= 0)
		{
			MouseS = 0;
			if (flag== 1)
			{
				Pass_Darken(1);
			}
				flag= 0;                    //复位num
			}
			if (MouseS != 0)
			{
				MouseS = 0;
			}
		}
		
}

/************************************************************************
FUNCTION:Draw_Pass
DESCRIPTION:绘制乘客功能界面
INPUT:乘客当前状态i
RETURN:无
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
		highlight(472, 0, 639, 479, LIGHTGREEN);//两个外框
		puthz(485, 337, "您在过去两周去过", 16, 17, BLACK);
		setcolor(BLACK);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
		outtextxy(622,330,":");
		
		//******************* 一行打三个 打完九个为止加一个等于号 
		/*绿色箭头*/
		setcolor(GREEN);
		line(546, 300, 565, 300);
		line(546, 250, 546, 300);
		line(565, 250, 565, 300);//矩形
		line(520, 272, 532, 272);
		line(579, 272, 591, 272);//两边水平线
		line(532, 272, 546, 250);
		line(579, 272, 565, 250);//内侧斜线
		line(520, 272, 555.5, 220);
		line(591, 272, 555.5, 220);
		floodfill(555.5, 270, GREEN);
		//查看乘车记录
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTRED);
		//暂无异常
		cover(492, 129 + 15, 619, 159 + 15, WHITE);
		highlight(492, 129 + 15, 619, 159 + 15, GREEN);
		puthz(492 + 10, 129 + 3 + 15, "暂无异常", 24, 28, GREEN);
		//退出系统
		draw_exit(505, 450, LIGHTGRAY,BROWN,BLACK,GREEN);
		draw_date(15, 70, BLACK, DARKGRAY);
		setcolor(LIGHTBLUE);
		setlinestyle(0, 0, 3);
		circle(30,90,12);
		puthz(50,84,"途经城市",16,16,BLACK);
	}
	if (i == 2)
	{
		cover(0, 0, 470, 479, WHITE);
		map();
		cover(471, 0, 639, 479, LIGHTGRAY);
		highlight(471, 0, 639, 479, GREEN);
		ring(555, 263, 60, 50, YELLOW, LIGHTGRAY, 2);
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, YELLOW);
		highlight(472, 0, 639, 479, YELLOW);//两个外框
		puthz(485, 337, "您在过去两周去过", 16, 17, BLACK);
		setcolor(BLACK);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
		outtextxy(622,330,":");
		/*黄色叹号*/
		cover(547, 227, 547 + 15, 227 + 50, YELLOW);
		stayellow(547 + 7.5, 227 + 50 + 15, 10);
		//查看乘车记录
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTRED);
		//暂无异常
		cover(492, 129 + 15, 619, 159 + 15, WHITE);
		highlight(492, 129 + 15, 619, 159 + 15, YELLOW);
		puthz(492 + 10, 129 + 3 + 15, "有过密接", 24, 28, LIGHTMAGENTA);
		//退出系统
		draw_exit(505, 450, LIGHTGRAY,BROWN,BLACK,GREEN);
		draw_date(15, 70, BLACK, DARKGRAY);
		setcolor(LIGHTBLUE);
		setlinestyle(0, 0, 3);
		circle(30,90,12);
		puthz(50,84,"途经城市",16,16,BLACK);
	}
	if (i == 3)
	{
		cover(0, 0, 470, 479, WHITE);
		map();
		cover(471, 0, 639, 479, LIGHTGRAY);
		highlight(471, 0, 639, 479, GREEN);
		ring(555, 263, 63, 50, RED, LIGHTGRAY, 2);
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, RED);
		highlight(472, 0, 639, 479, RED);//两个外框
		puthz(485, 337, "您在过去两周去过", 16, 17, BLACK);
		setcolor(BLACK);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
		outtextxy(622,330,":");
		/*叹号*/
		cover(547, 227, 547 + 15, 227 + 50, RED);
		stared(547 + 7.5, 227 + 50 + 15, 10);
		//查看乘车记录
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTRED);
		//暂无异常
		cover(492, 129 + 15, 619, 159 + 15, WHITE);
		highlight(492, 129 + 15, 619, 159 + 15, RED);
		puthz(492 + 10, 129 + 3 + 15, "不要出行", 24, 28, LIGHTMAGENTA);
		//退出系统
		draw_exit(505, 450, LIGHTGRAY,BROWN,BLACK,GREEN);
		draw_date(15, 70, BLACK, DARKGRAY);
		setcolor(LIGHTBLUE);
		setlinestyle(0, 0, 3);
		circle(30,90,12);
		puthz(50,84,"途经城市",16,16,BLACK);
	}
}

/************************************************************************
FUNCTION:Pass_Lighten
DESCRIPTION:乘客界面按钮点亮
INPUT:点亮控制变量flag
RETURN:无
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
		puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTMAGENTA);
		break;
	case 2:
		setfillstyle(1, LIGHTGRAY);
		bar(81.72, 358.75, 81.72 + 101, 358.75 + 60.5);
		puthz(96, 377, "上一条", 24, 24.5, WHITE);
		break;
	case 3:
		setfillstyle(1, LIGHTGRAY);
		bar(226, 358.75, 226 + 187, 358.75 + 60.5);
		puthz(247, 376.75, "查看乘车轨迹", 24, 24.5, WHITE);
		break;
	case 4:
		setfillstyle(1, LIGHTGRAY);
		bar(459.75, 358.75, 459.75 + 101, 358.75 + 60.5);
		puthz(475.88, 377, "下一条", 24, 24.5, WHITE);
		break;
	}
}

/************************************************************************
FUNCTION:Pass_Darken
DESCRIPTION:乘客界面按钮恢复
INPUT:恢复控制变量flag
RETURN:无
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
		puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTRED);
		break;
	case 2:
		setfillstyle(1, WHITE);
		bar(81.72, 358.75, 81.72 + 101, 358.75 + 60.5);
		highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
		puthz(96, 377, "上一条", 24, 24.5, LIGHTRED);
		break;
	case 3:
		setfillstyle(1, WHITE);
		bar(226, 358.75, 226 + 187, 358.75 + 60.5);
		highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
		puthz(247, 376.75, "查看乘车轨迹", 24, 24.5, LIGHTRED);
		break;
	case 4:
		setfillstyle(1, WHITE);
		bar(459.75, 358.75, 459.75 + 101, 358.75 + 60.5);
		highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
		puthz(475.88, 377, "下一条", 24, 24.5, LIGHTRED);
		break;
	}
}

/************************************************************************
FUNCTION:Pass_Tag
DESCRIPTION:获取乘客状态
INPUT:乘客代号n
RETURN:乘客状态flag
************************************************************************/
int Pass_Tag(int n) //用于获取乘客状态，以绘制不同的界面
{
	int l;
	int i;
	int flag=0; //记录乘客情况
	FILE* fp;
	STATE* s=NULL;
	if ((fp=fopen(".\\TEXT\\state.dat","rb+"))==NULL)
	{
		printf("\nError on open file state.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                            //文件指针定位到最后一位
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
		if(n==s->number) //在文件中查询到对应乘客                                  
		{
			if(s->contact==1) //乘客被标记为密切接触者
			{
				flag=2;
            }
			else if(s->patient!=0) //乘客被标记为确诊患者
			{
				flag=3;
			}
			else //乘客处于正常状态
			{
				flag=1;
			}		
			if(s!=NULL)                                              //释放内存
			{
				free(s);
				s=NULL;
			}
			break;
		}
		if(s!=NULL)                                              //释放内存
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
DESCRIPTION:显示乘客姓名
INPUT:乘客代号a
RETURN:无
************************************************************************/
int Pass_Name(int a) //显示乘客姓名
{
	int flag = 0;
	int n = 0;
	FILE* fp;
	PASSENGER* p;
	if ((fp = fopen(".\\TEXT\\pass.dat", "rb+")) == NULL) //打开存储用户信息的文件
	{
		printf("\nError on open file pass.dat!");
		delay(3000);
		exit(1);
	}
	while (!feof(fp))
	{
		if ((p = (PASSENGER*)malloc(sizeof(PASSENGER))) == NULL)     //分配空间
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
			puthz(502, 30, "您好，", 16, 17, LIGHTBLUE);
			puthz(497+ 17 * 3 + 2, 30, p->name, 16, 17, LIGHTBLUE);
			puthz(497 + 17 * 6 + 2, 30, "！", 16, 17, LIGHTBLUE);
			if (p != NULL)                                      //释放内存
			{
				free(p);
				p = NULL;
			}
			break;
		}
		if (p != NULL)                                      //释放内存
		{
			free(p);
			p = NULL;
		}
	}
	if (p != NULL)                                      //释放内存
	{
		free(p);
		p = NULL;
	}
	if (fclose(fp) != 0)                                             //关闭文件
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
	return 0;
}

double findx(int x) //根据城市代号，获取城市在地图上的x坐标
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

double findy(int x) //根据城市代号，获取城市在地图上的y坐标
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
DESCRIPTION:显示乘客到过的城市
INPUT:城市坐标x,y，字体颜色hz
RETURN:无
************************************************************************/
int Pass_City_Show(int x, int y, int s, int hz, int space, int mainhzcolor) //显示乘客到过的城市
{
	if (s == 1)
	{
		puthz(x, y, "北京", hz, space, mainhzcolor);
	}
	if (s == 2)
	{
		puthz(x, y, "天津", hz, space, mainhzcolor);
	}
	if (s == 3)
	{
		puthz(x, y, "济南", hz, space, mainhzcolor);
	}
	if (s == 4)
	{
		puthz(x, y, "徐州", hz, space, mainhzcolor);
	}
	if (s == 5)
	{
		puthz(x, y, "南京", hz, space, mainhzcolor);
	}
	if (s == 6)
	{
		puthz(x, y, "上海", hz, space, mainhzcolor);
	}
	if (s == 7)
	{
		puthz(x, y, "西安", hz, space, mainhzcolor);
	}
	if (s == 8)
	{
		puthz(x, y, "成都", hz, space, mainhzcolor);
	}
	if (s == 9)
	{
		puthz(x, y, "杭州", hz, space, mainhzcolor);
	}
	if (s == 10)
	{
		puthz(x, y, "贵阳", hz, space, mainhzcolor);
	}
	if (s == 11)
	{
		puthz(x, y, "太原", hz, space, mainhzcolor);
	}
	if (s == 12)
	{
		puthz(x, y, "郑州", hz, space, mainhzcolor);
	}
	if (s == 13)
	{
		puthz(x, y, "武汉", hz, space, mainhzcolor);
	}
	if (s == 14)
	{
		puthz(x, y, "长沙", hz, space, mainhzcolor);
	}
	if (s == 15)
	{
		puthz(x, y, "广州", hz, space, mainhzcolor);
	}
	if (s == 16)
	{
		puthz(x, y, "深圳", hz, space, mainhzcolor);
	}
	if (s == 17)
	{
		puthz(x, y, "南昌", hz, space, mainhzcolor);
	}
	if (s == 18)
	{
		puthz(x, y, "昆明", hz, space, mainhzcolor);
	}
}

/************************************************************************
FUNCTION:Pass_City_Get
DESCRIPTION:获取乘客到过城市的信息
INPUT:乘客代号passengera
RETURN:无
************************************************************************/
int Pass_City_Get(int passengera) //获取乘客去过的城市信息
{
	double x, y; //目标城市的对应坐标
	int i = 0; //for语句辅助参数
	int j, temp;
	int *idep;    //
	int *iarr;
	int a = passengera; //当前乘客代号
	int n = 0;
	int count = 0;
	int *showcity;
	int leftupx = 485;
	int leftupy = 364;
	int kuan = 38;
	int gao = 22;
	int size;
	int flag=0; // 用于标记已经查询到当前乘客
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
		if ((r = (RECORD*)malloc(sizeof(RECORD))) == NULL)                      //分配空间
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

		if (r->number==a)    //***** 找到指定乘客 !!!!注意数组有没有被保留 没有的话要重新初始化 
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
		else if(flag==1) //该乘客的乘车记录已经读取完毕，跳出循环
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
	//测试去过站的正确性 
	for (i = 0; i < count; i++)		//循环判断数组中每一个数
	{
		for (j = i + 1; j < count; j++)	//判断a[i]后边的数是否和a[i]相等
		{
			if (showcity[i] == showcity[j])
			{
				for (temp = j; temp < count; temp++)
					showcity[temp] = showcity[temp + 1];	//将a[j]后面的元素全往前移一个位置
				j--;	//a[j+1]取代a[j]位置，为使下次从a[j+1]开始查找,j减一(为使j保持不变)
				count--;	//数组长度减一
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
		}  //showcity已经把第一界面的地点显示完了 
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
                 puthz(leftupx, leftupy, "、", 16, 17, BLUE);
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
				puthz(leftupx-2,leftupy, "、", 16, 17, BLUE);
			}
			leftupx = leftupx + 10;
		}
	}
	if (size>=9)
	{
		leftupx = 485;
		leftupy = leftupy + gao;
		puthz(leftupx+30+17, leftupy, "等城市", 16, 17, BLUE);
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