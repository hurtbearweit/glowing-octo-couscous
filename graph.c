#include"public.h"
#include"graph.h"
//不适用与垂直的矩形************ss*
void cover(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color)//画有颜色的矩形框
{
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	bar(lefttop_x, lefttop_y, rightbottom_x, rightbottom_y);
}


void highlight(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color)//画眼颜色矩形边框
{
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(color);
	rectangle(lefttop_x, lefttop_y, rightbottom_x, rightbottom_y);
}


void DOThighlight(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color)
{
	setcolor(color);
	setlinestyle(1, 0, 3);
	rectangle(lefttop_x, lefttop_y, rightbottom_x, rightbottom_y);
}
//画填充了黑色的圆圈
void stablack(int x, int y, int r)
{
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	pieslice(x, y, 0, 360, r);
	setcolor(BLACK);
	line(x, y, x + r, y);
}

//画填充了橘红色的圆圈
void stalightred(int x, int y, int r)
{
	setcolor(LIGHTRED);
	setfillstyle(1, LIGHTRED);
	pieslice(x, y, 0, 360, r);
	setcolor(LIGHTRED);
	line(x, y, x + r, y);
}

//画填充了绿色的圆圈
void stagreen(int x, int y, int r)
{
	setcolor(LIGHTGREEN);
	setfillstyle(1, LIGHTGREEN);
	pieslice(x, y, 0, 360, r);
	setcolor(LIGHTGREEN);
	line(x, y, x + r, y);
}

//画填充了青色的圆圈
void stacyan(int x, int y, int r)
{
	setcolor(CYAN);
	setfillstyle(1, CYAN);
	pieslice(x, y, 0, 360, r);
	setcolor(CYAN);
	line(x, y, x + r, y);
}

//画填充了黄色的圆圈
void stayellow(int x, int y, int r)
{
	setcolor(YELLOW);
	setfillstyle(1, YELLOW);
	pieslice(x, y, 0, 360, r);
	setcolor(YELLOW);
	line(x, y, x + r, y);
}


//画填充了红色的圆圈
void stared(int x, int y, int r)
{
	setcolor(RED);
	setfillstyle(1, RED);
	pieslice(x, y, 0, 360, r);
	setcolor(RED);
	line(x, y, x + r, y);
}



//画站点之间的宽为x像素的连线
void linebetweensta(int x1, int y1, int x2, int y2)
{
	/*int m,n;
	m = (x1 + x2) / 2;
	n = (y1 + y2) / 2;
	if (x1 == x2)
	{
		setcolor(BLACK);
		setlinestyle(0,0,3);
		line(x1, y1, x1, y2);
	}*/
	//if (x1 == x2)
	//{
	setcolor(BLACK);
	setcolor(BLACK);
	setlinestyle(0, 0, 3);
	line(x1 + 1, y1, x2 + 1, y2);
	setlinestyle(0, 0, 3);
	line(x1 - 1, y1, x2 - 1, y2);
	//}
	/*if (y1 == y2)
		cover(x1, y1 + 4, x2, y1 - 4, BLACK);
	else
	{m
		line(x1 - 4, y1, x2 - 4, y2);
		line(x1 + 4, y1, x2 + 4, y2);
		line(x1 - 4, y1, x1 + 4, y1);
		line(x2 - 4, y2, x2 + 4, y2);
		floodfill(,n,BLACK);
	}*/
}

//画一个圆环
void ring(int x, int y, int r2, int r1, int color, int bk, int style)
{
	int i;
	int w = 2;
	if (style == 2)
	{
		setcolor(bk);
		setfillstyle(1, color);
		pieslice(x, y, 0, 360, r2);
		setcolor(color);
		line(x, y, x + r2-2, y);
		setfillstyle(1, bk);
		pieslice(x, y, 0, 360, r1);
		setcolor(bk);
		line(x, y, x + r1-2, y);
		setfillstyle(1, color);
		if((color != GREEN)&&(r1 > 45))
		{
			setcolor(color);
			for(i = r2-w;i<=(r2+w);i++)
			{
				setcolor(color);
				setlinestyle(0,0,3);
				circle(x , y, i);
			}
		}
	}
	if (style == 1)
	{
		setfillstyle(1, bk);
		setcolor(color);
		circle(x, y, r2);
		floodfill(x, y, color);
		circle(x, y, r1);
		floodfill(x, y, bk);
	}

}

//画一个宽度为r的方框
void frame(int x1, int y1, int x2, int y2, int r, int color, int bk)
{
	cover(x1, y1, x2, y2, color);
	cover(x1 + r, y1 + r, x2 - r, y2 - r, bk);
}

//画一个三角形(未填充颜色)
void triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
	setcolor(color);
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
}

//画填充颜色的三角形
void trianglefill(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
	int n, m;
	setcolor(color);
	n = (x1 + x2 + x3) / 3;
	m = (y1 + y2 + y3) / 3;
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
	floodfill(n, m, color);

}

//画一个退出系统的标志
void draw_exit(int x, int y, int bk, int hzcolor, int fmcolor, int tr)
{
	int a;
	int b;
	int m, n;
	highlight(x - 5, y - 3, x + 100, y + 17, fmcolor);
	puthz(x, y, "点击退出", 16, 18, hzcolor);
	a = 18 * 4 + x + 2;
	b = y;
	frame(a, b, a + 12, b + 16, 4, fmcolor, bk);
	cover(a + 6, b + 6, a + 15, b + 10, tr);
	m = a + 15;
	n = b + 8;
	triangle(m, b, m, b + 16, m + 7, n, tr);
}

//画出底图
void map()
{
	FILE* fp;
	CITY* c;
	int i; 
	
	cleardevice();
	setbkcolor(BLACK);
	putbmp(0, 0, ".\\PICTURE\\MAP.bmp");

	puthz(230 + 17, 15, "北京", 16, 21, BLACK);
	linebetweensta(232.5, 26, 294.5, 55.5);

	puthz(294.5 + 15, 52, "天津", 16, 21, BLACK);

	puthz(294.5 + 15, 125.5 - 7, "济南", 16, 21, BLACK);
	linebetweensta(294.5, 55.5, 294.5, 125.5);

	puthz(294.5 + 15, 173.5 - 7, "徐州", 16, 21, BLACK);
	linebetweensta(294.5, 125.5, 294.5, 173.5);

	puthz(326 + 25, 215, "南京", 16, 21, BLACK);
	linebetweensta(294.5, 173.5, 329.5, 228.5);
	//替换 428.5
	puthz(428.5 - 10, 274 + 15, "上海", 16, 21, BLACK);
	linebetweensta(329.5, 228.5, 428.5, 273.5);
	//jingguang
	linebetweensta(232.5, 26, 197, 111.5);

	puthz(149, 102, "太原", 16, 21, BLACK);
	linebetweensta(197, 111.5, 197, 173.5);

	puthz(151, 190, "郑州", 16, 21, BLACK);
	linebetweensta(197, 173.5, 197, 273.5);

	puthz(150, 263, "武汉", 16, 21, BLACK);
	linebetweensta(197, 273.5, 197, 340.5);

	puthz(149, 363, "长沙", 16, 21, BLACK);
	linebetweensta(197, 340.5, 197, 416.5);

	puthz(197 + 15, 416.5 - 7, "广州", 16, 21, BLACK);
	linebetweensta(197, 416.5, 197, 441.5);

	puthz(197 + 15, 441.5 - 7, "深圳", 16, 21, BLACK);
	//hucheng*
	linebetweensta(294.5, 173.5, 197, 173.5);

	puthz(44, 167, "西安", 16, 21, BLACK);
	linebetweensta(93.5, 173.5, 197, 173.5);

	puthz(34, 269, "成都", 16, 21, BLACK);
	linebetweensta(93.5, 173.5, 19.5, 273.5);
	//hukun

	puthz(345, 310, "杭州", 16, 21, BLACK);
	linebetweensta(428.5, 273.5, 356.5, 296.5);

	puthz(270, 360, "南昌", 16, 21, BLACK);
	linebetweensta(356.5, 296.5, 282, 340.5);
	linebetweensta(282, 340.5, 197, 340.5);

	puthz(44 - 3+35, 290+20, "贵阳", 16, 21, BLACK);
	linebetweensta(197, 340.5, 93.5, 340.5);

	puthz(40, 410, "昆明", 16, 21, BLACK);
	linebetweensta(93.5, 340.5, 19.5, 416.5);
	
	stagreen(360,400,10);
	puthz(380,392,"低风险",16,16,BLACK);
	stayellow(360,430,10);
	puthz(380,422,"中风险",16,16,BLACK);
	stared(360,460,10);
	puthz(380,452,"高风险",16,16,BLACK);
	
	if((fp=fopen(".\\TEXT\\city.dat","rb+"))==NULL)     //打开存储用户信息的文件
	{
		printf("\nError on open city.dat!");
		delay(3000);
		exit(1);;
	}
	for(i=0;i<18;i++)
	{
		if((c=(CITY*)malloc(sizeof(CITY)))==NULL)
		{
			printf("\nMemory not enough!");
			return 0;
		}
		fseek(fp,i*sizeof(CITY),SEEK_SET);                           
		fread(c,sizeof(CITY),1,fp);    		
		switch(c->number)
		{
			case 1: //北京
			    if(c->risk==1)
				{
					stagreen(232.5, 26, 11); //北京
				}
				else if(c->risk==2)
				{
					stayellow(232.5, 26, 11);
				}
				else if(c->risk==3)
				{
					stared(232.5, 26, 11);
				}
				break;
			case 2: //天津
			    if(c->risk==1)
				{
					stagreen(294.5, 55.5, 7); //天津
				}
				else if(c->risk==2)
				{
					stayellow(294.5, 55.5, 7);
				}
				else if(c->risk==3)
				{
					stared(294.5, 55.5, 7);
				}
				break;
			case 3: //济南
			    if(c->risk==1)
				{
					stagreen(294.5, 125.5, 7); //济南
				}
				else if(c->risk==2)
				{
					stayellow(294.5, 125.5, 7);
				}
				else if(c->risk==3)
				{
					stared(294.5, 125.5, 7);
				}
				break;
			case 4: //徐州
			    if(c->risk==1)
				{
					stagreen(294.5, 173.5, 11); //徐州
				}
				else if(c->risk==2)
				{
					stayellow(294.5, 173.5, 11);
				}
				else if(c->risk==3)
				{
					stared(294.5, 173.5, 11);
				}
				break;
			case 5: //南京
			    if(c->risk==1)
				{
					stagreen(329.5, 228.5, 7); //南京
				}
				else if(c->risk==2)
				{
					stayellow(329.5, 228.5, 7);
				}
				else if(c->risk==3)
				{
					stared(329.5, 228.5, 7);
				}
				break;
			case 6: //上海
			    if(c->risk==1)
				{
					stagreen(428.5, 273.5, 11); //上海
				}
				else if(c->risk==2)
				{
					stayellow(428.5, 273.5, 11);
				}
				else if(c->risk==3)
				{
					stared(428.5, 273.5, 11);
				}
				break;
			case 7: //西安
			    if(c->risk==1)
				{
					stagreen(93.5, 173.5, 7); //西安
				}
				else if(c->risk==2)
				{
					stayellow(93.5, 173.5, 7);
				}
				else if(c->risk==3)
				{
					stared(93.5, 173.5, 7);
				}
				break;
			case 8: //成都
			    if(c->risk==1)
				{
					stagreen(19.5, 273.5, 7); //成都
				}
				else if(c->risk==2)
				{
					stayellow(19.5, 273.5, 7);
				}
				else if(c->risk==3)
				{
					stared(19.5, 273.5, 7);
				}
				break;
			case 9: //杭州
			    if(c->risk==1)
				{
					stagreen(356.5, 296.5, 7); //杭州
				}
				else if(c->risk==2)
				{
					stayellow(356.5, 296.5, 7);
				}
				else if(c->risk==3)
				{
					stared(356.5, 296.5, 7);
				}
				break;
			case 10: //贵阳
			    if(c->risk==1)
				{
					stagreen(93.5, 340.5, 7); //贵阳
				}
				else if(c->risk==2)
				{
					stayellow(93.5, 340.5, 7);
				}
				else if(c->risk==3)
				{
					stared(93.5, 340.5, 7);
				}
				break;
			case 11: //太原
			    if(c->risk==1)
				{
					stagreen(197, 111.5, 7); //太原
				}
				else if(c->risk==2)
				{
					stayellow(197, 111.5, 7);
				}
				else if(c->risk==3)
				{
					stared(197, 111.5, 7);
				}
				break;
			case 12: //郑州
			    if(c->risk==1)
				{
					stagreen(197, 173.5, 11); //郑州
				}
				else if(c->risk==2)
				{
					stayellow(197, 173.5, 11);
				}
				else if(c->risk==3)
				{
					stared(197, 173.5, 11);
				}
				break;
			case 13: //武汉
			    if(c->risk==1)
				{
					stagreen(197, 273.5, 7); //武汉
				}
				else if(c->risk==2)
				{
					stayellow(197, 273.5, 7);
				}
				else if(c->risk==3)
				{
					stared(197, 273.5, 7);
				}
				break;
			case 14: //长沙
			    if(c->risk==1)
				{
					stagreen(197, 340.5, 11); //长沙
				}
				else if(c->risk==2)
				{
					stayellow(197, 340.5, 11);
				}
				else if(c->risk==3)
				{
					stared(197, 340.5, 11);
				}
				break;
			case 15: //广州
			    if(c->risk==1)
				{
					stagreen(197, 416.5, 7); //广州
				}
				else if(c->risk==2)
				{
					stayellow(197, 416.5, 7);
				}
				else if(c->risk==3)
				{
					stared(197, 416.5, 7);
				}
				break;
			case 16: //深圳
			    if(c->risk==1)
				{
					stagreen(197, 441.5, 7); //深圳
				}
				else if(c->risk==2)
				{
					stayellow(197, 441.5, 7);
				}
				else if(c->risk==3)
				{
					stared(197, 441.5, 7);
				}
				break;
			case 17: //南昌
			    if(c->risk==1)
				{
					stagreen(282, 340.5, 7); //南昌
				}
				else if(c->risk==2)
				{
					stayellow(282, 340.5, 7);
				}
				else if(c->risk==3)
				{
					stared(282, 340.5, 7);
				}
				break;
			case 18: //昆明
			    if(c->risk==1)
				{
					stagreen(19.5, 416.5, 7); //昆明
				}
				else if(c->risk==2)
				{
					stayellow(19.5, 416.5, 7);
				}
				else if(c->risk==3)
				{
					stared(19.5, 416.5, 7);
				}
				break;    
		}
		if(c!=NULL)                                              //释放内存
		{
			free(c);
			c=NULL;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close city.dat!");
		delay(3000);
		exit(1);
	}
}

//画一个重新载入的标志
void draw_refresh(int x, int y, int bk, int hzcolor, int fmcolor, int tr)
{
	int a, b, r;
	highlight(x - 5, y - 3, x + 100, y + 17, fmcolor);
	puthz(x, y, "重新载入", 16, 18, hzcolor);
	a = 18 * 4 + x + 2;
	b = y + 1;
	r=8;
	ring(a + r, b + r, r, r - 2, tr, bk, 2);
	cover(a + r, b + r - 2, a + 2 * r, b + r + 5, bk);
	triangle(a + 1.3 * r, b + 0.3 * r, a + 2.1 * r, b + 0.3 * r, a + 1.7 * r, b + r, tr);
    
}

//画当天的日期
void draw_date(int x, int y, int linecolor,int wordcolor)
{
	int a, b;
	char Y[5];
	char M[3];
	char D[3];
	struct tm* ptr;
	time_t lt;
	setcolor(linecolor);
	setlinestyle(1, 0, 3);
	line(x, y-10, x+190, y-10);
	a = 2 + x;
	b = y - 40;
	lt = time(NULL);
	ptr = localtime(&lt);
	sprintf(Y, "%d", ptr->tm_year + 1900);
	sprintf(M, "%d", ptr->tm_mon + 1);
	sprintf(D, "%d", ptr->tm_mday);
	//乘车日期
	setcolor(linecolor);
	setlinestyle(1, 0, 3);
	//line(400, 26.5, 400 + 270, 26.5);
	puthz(a, b-15, "今天是：", 16, 17, wordcolor);
	//年填在(a+68,b,a+68+64,b+16)
	settextstyle(1, 0, 1);
	settextjustify(LEFT_TEXT, 0);
	outtextxy(a+15 , b+18, Y);
	puthz(a  + 64, b+5, "年", 16, 17, wordcolor);
	settextstyle(1, 0, 1);
	settextjustify(LEFT_TEXT, 0);
	outtextxy(a  + 64 + 23, b + 18, M);
	//月填在(a+68 + 64+17,b,a+68 + 64+17+28,b+16)
	puthz(a  + 64 + 17 + 17, b +5, "月", 16, 17, wordcolor);
	//日填在(a  + 64 + 17 + 28+17,b,a  + 64 + 17 + 28+17+28,b+16)
	settextstyle(1, 0, 1);
	settextjustify(LEFT_TEXT, 0);
	if(strlen(D)==2)
	{
	    outtextxy(a  + 64 + 17 + 28 + 6, b + 18, D);
	}
	else 
	{
		outtextxy(a  + 64 + 17 + 28 + 12, b + 18, D);
	}
	puthz(a  + 64 + 17 + 28 + 26, b+5 , "日", 16, 17, wordcolor);
}

//行高20选项文字框
//输出坐标为(x-2,y-2,x-2 + n * 17 + 4,y+18)的矩形区域
void search_choose_words_bk(int x, int y, int n, int h, int b)
{
	int length, x2, y2, x1, y1;
	length = n * 17 + 4;
	x1 = x - 2;
	y1 = y - 2;
	x2 = x1 + length;
	y2 = y + 18;
	cover(x1, y1, x2, y2, b);
	highlight(x1, y1, x2, y2, h);
}

//行高25选项文字框
//输出坐标为(x-2,y-1,x-2 + n * 25 + 4,y+24)的矩形区域
void search_choose_words_24bk(int x, int y, int n, int h, int b)
{
	int length, x2, y2, x1, y1;
	length = n * 25 + 4;
	x1 = x - 2;
	y1 = y - 1;
	x2 = x1 + length;
	y2 = y + 18 + 6;
	cover(x1, y1, x2, y2, b);
	highlight(x1, y1, x2, y2, h);
}

//行高20选项输入框
//输出坐标为(x-2,y-2,x-2 + n * 17 + 4,y+18)的矩形区域
void search_choose_enter_bk(int x, int y, int n, int b, int h)
{
	int length, x2, y2, x1, y1;
	length = n * 17 + 4;
	x1 = x - 2;
	y1 = y - 2;
	x2 = x1 + length;
	y2 = y + 23;
	cover(x1, y1, x2, y2, b);
	highlight(x1, y1, x2, y2, h);
}

//行高25选项输入框
//输出坐标为(x-2,y-1,x-2 + n * 25 + 4,y+24)的矩形区域
void search_choose_enter_24bk(int x, int y, int n, int b, int h)
{
	int length, x2, y2, x1, y1;
	length = n * 25 + 4;
	x1 = x - 2;
	y1 = y - 1;
	x2 = x1 + length;
	y2 = y + 24;
	cover(x1, y1, x2, y2, b);
	highlight(x1, y1, x2+1, y2+1, h);
}
//城市管理的城市名字
void citynow(int i)
{
	int x = 480;
	int y = 20;
	int color = LIGHTMAGENTA;
	if (i == 1)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：北京市", 24, 25, color);
	}
	if (i == 2)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：天津市", 24, 25, color);
	}
	if (i == 3)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：济南市", 24, 25, color);
	}
	if (i == 4)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：徐州市", 24, 25, color);
	}
	if (i == 5)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：南京市", 24, 25, color);
	}
	if (i == 6)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：上海市", 24, 25, color);
	}
	if (i == 7)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：西安市", 24, 25, color);
	}
	if (i == 8)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：成都市", 24, 25, color);
	}
	if (i == 9)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：杭州市", 24, 25, color);
	}
	if (i == 10)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：贵阳市", 24, 25, color);
	}
	if (i == 11)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：太原市", 24, 25, color);
	}
	if (i == 12)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：郑州市", 24, 25, color);
	}
	if (i == 13)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：武汉市", 24, 25, color);
	}
	if (i == 14)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：长沙市", 24, 25, color);
	}
	if (i == 15)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：广州市", 24, 25, color);
	}
	if (i == 16)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：深圳市", 24, 25, color);
	}
	if (i == 17)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：南昌市", 24, 25, color);
	}
	if (i == 18)
	{
		DOThighlight(x, y, x + 150, y + 25, color);
		puthz(x + 4, y + 2, "当前：昆明市", 24, 25, color);
	}
}

void Fill_Triangle(int  ax, int ay, int bx, int by, int cx, int cy,int color)
{
	int x,y,y1,i,j;
	int  k=cy-ay;
	y=ay;
	y1 = by;
	for (x = ax + 1; x < cx; x++)
	{
		for (i=0;i<k;i++)
		{
			putpixel(x, y+i, color);
			putpixel(x, y1-i, color);
			if (y+i>=cy)
               break;			
		}
		if (x%2==0)
		{
		    y++;
     		y1--;
		}
	}
}
