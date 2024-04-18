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
			//在预约键上 
		}
		//项目1 
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
		//项目2 
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
		//项目3 
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
		//项目4 
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
		//项目5
		if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)//在返回键上
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
		if(MouseX>490&&MouseX<590&&MouseY>425&&MouseY<460)//在返回键上
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

void Light_Special_Book(int x1,int y1,int x2,int y2,int tag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	 if(tag==11)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,70,"预约",24,24,RED);
	}
	else if(tag==12)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,120,"预约",24,24,RED);
	}
	else if(tag==13)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,170,"预约",24,24,RED);	
	}
	else if(tag==14)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,220,"预约",24,24,RED);	
	}
	else if(tag==15)
	{
		cover(x1+2,y1+2,x2-2,y2-2,LIGHTGRAY);
		puthz(525,270,"预约",24,24,RED);	
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
			puthz(525,70,"预约",24,24,BLUE);
			break;
	    case 12:
	    	cover(472,102,618,148,WHITE);
			puthz(525,120,"预约",24,24,BLUE);
			break;
		case 13:
			cover(472,152,618,198,WHITE);
			puthz(525,170,"预约",24,24,BLUE);
			break;
		case 14:
			cover(472,202,618,248,WHITE);
			puthz(525,220,"预约",24,24,BLUE);
			break;
		case 15:
			cover(472,252,618,298,WHITE);
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
		cover(170+2,50+2,470-2,100-2,LIGHTGRAY);
		puthz(293,68,"前往",24,24,RED);	
	}
	else if(mark==2)
	{
		cover(170+2,100+2,470-2,150-2,LIGHTGRAY);
		puthz(293,118,"前往",24,24,RED);
	}
	else if(mark==3)
	{
		cover(170+2,150+2,470-2,200-2,LIGHTGRAY);
		puthz(293,168,"前往",24,24,RED);
	}
	else if(mark==4)
	{
		cover(170+2,200+2,470-2,250-2,LIGHTGRAY);
		puthz(293,218,"前往",24,24,RED);	
	}
	else if(mark==5)
	{
		cover(170+2,250+2,470-2,300-2,LIGHTGRAY);
		puthz(293,268,"前往",24,24,RED);
	}
	else if(mark==6)
	{
		cover(50,425,140,460,CYAN);
		puthz(70,430,"返回",24,24,LIGHTRED);
	}
	else if(mark==7)
	{
		cover(490,425,590,460,CYAN);
		puthz(492,430,"我的预约",24,24,LIGHTRED);
	}
}

void Dark_Go(int mark)
{
	clrmous(MouseX,MouseY);
	delay(10);
	if(mark==1)
	{
		cover(170+2,50+2,470-2,100-2,WHITE);
		puthz(293,68,"前往",24,24,BLUE);	
	}
	else if(mark==2)
	{
		cover(170+2,100+2,470-2,150-2,WHITE);
		puthz(293,118,"前往",24,24,BLUE);
	}
	else if(mark==3)
	{
		cover(170+2,150+2,470-2,200-2,WHITE);
		puthz(293,168,"前往",24,24,BLUE);
	}
	else if(mark==4)
	{
		cover(170+2,200+2,470-2,250-2,WHITE);
		puthz(293,218,"前往",24,24,BLUE);	
	}
	else if(mark==5)
	{
		cover(170+2,250+2,470-2,300-2,WHITE);
		puthz(293,268,"前往",24,24,BLUE);
	}
	else if(mark==6)
	{
		cover(50,425,140,460,GREEN);
		puthz(70,430,"返回",24,32,WHITE);
	}
	else if(mark==7)
	{
		cover(490,425,590,460,GREEN);
		puthz(492,430,"我的预约",24,24,WHITE);
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

void Special_1(int *page)
{   
    cleardevice();
	bkcolor();     
    setcolor(RED);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	puthz(220,50,"鼠标按任意处返回至地图界面",16,16,RED);
	puthz(100,100,"特殊项目名称",24,24,RED);
	puthz(300,100,"特殊餐饮服务预约",24,24,RED);
    puthz(100,150,"开放时间",24,24,RED);	
	outtextxy(300,150,"8:00~22:30");
	puthz(100,200,"开放地点",24,24,RED);
	puthz(300,200,"欢乐时光餐饮区",24,24,RED); 
	puthz(296,250,"简介",24,24,RED);
	puthz(50,300,"可以品尝欢乐时光特色餐厅提供的美食",24,24,RED);
    outtextxy(461,300,",");
	puthz(461,300,"每晚举行欢",24,24,RED);
	puthz(50,350,"乐总动员主题晚宴",24,24,RED);
	outtextxy(245,350,",");
	puthz(255,350,"不定时推出特色美食节",24,24,RED);
	outtextxy(498,350,",");
	puthz(508,350,"丰盛的",24,24,RED);
	puthz(50,400,"美食等着您的光临",24,24,RED);
	outtextxy(245,400,",");
	puthz(255,400,"预约可享受折扣以及免排队福利",24,24,RED);
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
	puthz(220,50,"鼠标按任意处返回至地图界面",16,16,RED);
	puthz(100,100,"特殊项目名称",24,24,RED);
	puthz(300,100,"特殊表演预约",24,24,RED);
    puthz(100,150,"开放时间",24,24,RED);	
	outtextxy(300,150,"18:00~24:00");
	puthz(100,200,"开放地点",24,24,RED);
	puthz(300,200,"欢乐江城",24,24,RED);
	puthz(296,250,"简介",24,24,RED);
	puthz(98,300,"欢乐江城在每周六会举办夜晚灯光秀",24,24,RED);
	outtextxy(485,300,",");
	puthz(495,300,"每周日举",24,24,RED);
	puthz(50,350,"办动物杂技秀",24,24,RED);
	outtextxy(197,350,",");
	puthz(207,350,"该项目深受大众喜爱",24,24,RED);
	outtextxy(426,350,",");
	puthz(436,350,"获得了大众的",24,24,RED);
	puthz(50,400,"一致好评",24,24,RED);
	outtextxy(150,400,",");
	puthz(160,400,"提前预约可以预定自己心仪的座位",24,24,RED); 
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
	puthz(220,50,"鼠标按任意处返回至地图界面",16,16,RED);
	puthz(100,100,"特殊项目名称",24,24,RED);
	outtextxy(300,100,"VIP");
	puthz(335,100,"导览预约",24,24,RED);
    puthz(100,150,"预约时间",24,24,RED);	
	outtextxy(300,150,"00:00~24:00");
	puthz(100,200,"集合地点",24,24,RED);
	puthz(300,200,"梦想大道",24,24,RED);
	puthz(296,250,"简介",24,24,RED);
	puthz(98,300,"为您提供私人导游或者私人服务人员",24,24,RED);
	outtextxy(485,300,",");
	puthz(495,300,"为您提供",24,24,RED);
	puthz(50,350,"专属的游园导览",24,24,RED); 
	outtextxy(221,350,",");
	puthz(231,350,"优先通道",24,24,RED);
	outtextxy(327,350,",");
	puthz(337,350,"以及其他特的特殊服务",24,24,RED);
	puthz(50,400,"项目",24,24,RED);
	outtextxy(100,400,",");
	puthz(110,400,"此项目的服务若您不满意可以申请退款",24,24,RED); 
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
	puthz(220,50,"鼠标按任意处返回至地图界面",16,16,RED);
	puthz(100,100,"特殊项目名称",24,24,RED);
	outtextxy(300,100,"VR");
	puthz(328,100,"视觉体验",24,24,RED);
    puthz(100,150,"预约时间",24,24,RED);	
	outtextxy(300,150,"10：00~22:00");
	puthz(100,200,"项目地点",24,24,RED);
	puthz(300,200,"渔光岛",24,24,RED);
	puthz(296,250,"简介",24,24,RED);
	puthz(98,300,"虚拟过山车",24,24,RED);
	outtextxy(220,300,":");
	puthz(220,300,"感受高速旋转和急转弯带来的",24,24,RED);
	puthz(50,350,"刺激",24,24,RED); 
	outtextxy(100,350,"!");
	puthz(110,350,"虚拟主题乐园",24,24,RED);
	outtextxy(257,350,":");
	puthz(267,350,"体验探险",24,24,RED);
	outtextxy(365,350,",");
	puthz(375,350,"奇幻",24,24,RED);
	outtextxy(425,350,",");
	puthz(385,350,"科幻等主题的虚拟",24,24,RED);
	puthz(50,400,"景点和游戏以及不同的文化魅力",24,24,RED); 
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
	puthz(220,50,"鼠标按任意处返回至地图界面",16,16,RED);
	puthz(100,100,"特殊项目名称",24,24,RED);
	puthz(300,100,"特色过山车",24,24,RED);
    puthz(100,150,"预约时间",24,24,RED);	
	outtextxy(300,150,"8:00~22:00");
	puthz(100,200,"项目地点",24,24,RED);
	puthz(300,200,"极速世界",24,24,RED);
	puthz(296,250,"简介",24,24,RED);
	puthz(98,300,"融合了快速",24,24,RED);
	outtextxy(220,300,",");
	puthz(230,300,"陡峭的爬升",24,24,RED);
	outtextxy(353,300,",");
	puthz(363,300,"惊险的下坡等传统元",24,24,RED); 
	puthz(50,350,"素与音效",24,24,RED); 
	outtextxy(150,350,",");
	puthz(160,350,"灯光以及新的感官体验",24,24,RED);
	outtextxy(400,350,",");
	puthz(410,350,"特色过山车会不定",24,24,RED);
	puthz(50,400,"期的举行不同的主题特色过山车",24,24,RED); 
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
	int i;				//检索用户 
	int j;				//标记已经预约的项目 
	int m;				//打印已经预约的项目 
	int l;				//计算文件长度 
	int mark[5]={0};	//将文件里面的项目预约情况打印到数组里面 
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
		}											//打开文件，时时检索项目预约情况 
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
									//将文件里面的项目预约情况放到数组里面（如果有） 
        if(j==0)
		{
			highlight(20,50,620,100,RED);
			puthz(176,59,"您当前暂无预约项目",32,32,RED);
		}
		if(j!=0)
		{
			for(m=0;m<j;m++)            
			{
				switch(mark[m])
				{
					case 0:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"餐饮预约",24,24,BLUE);
						puthz(195,50*(m+1)+20,"",24,24,BLUE);
						puthz(357,50*(m+1)+20,"已预约",24,24,BLUE);
						puthz(525,50*(m+1)+20,"取消",24,24,BLUE);
						break;
					case 1:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"疯狂溜达车",24,24,BLUE);
						puthz(195,50*(m+1)+20,"卡通工厂",24,24,BLUE);
						puthz(357,50*(m+1)+20,"已预约",24,24,BLUE);
						puthz(525,50*(m+1)+20,"取消",24,24,BLUE);
						break;
					case 2:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"天地双雄",24,24,BLUE);							
						puthz(195,50*(m+1)+20,"欢乐时光",24,24,BLUE);
						puthz(357,50*(m+1)+20,"已预约",24,24,BLUE);
						puthz(525,50*(m+1)+20,"取消",24,24,BLUE);	
						break;				
					case 3:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"完美风暴",24,24,BLUE);
						puthz(195,50*(m+1)+20,"飓风湾",24,24,BLUE);
						puthz(357,50*(m+1)+20,"已预约",24,24,BLUE);
						puthz(525,50*(m+1)+20,"取消",24,24,BLUE);
						break;
					case 4:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"木翼双龙",24,24,BLUE);
						puthz(195,50*(m+1)+20,"欢乐江城",24,24,BLUE);
						puthz(357,50*(m+1)+20,"已预约",24,24,BLUE);
						puthz(525,50*(m+1)+20,"取消",24,24,BLUE); 
						break;
					case 5:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"摩天轮",24,24,BLUE);
						puthz(195,50*(m+1)+20,"渔光岛",24,24,BLUE);
						puthz(357,50*(m+1)+20,"已预约",24,24,BLUE);
						puthz(525,50*(m+1)+20,"取消",24,24,BLUE); 
						break;
					case 6:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"莲花栈道",24,24,BLUE);
						puthz(195,50*(m+1)+20,"羽落天堂",24,24,BLUE);
						puthz(357,50*(m+1)+20,"已预约",24,24,BLUE);
						puthz(525,50*(m+1)+20,"取消",24,24,BLUE); 
						break;
					case 7:
						graph(20,50*(m+1),620,50*(m+2));
						puthz(45,50*(m+1)+20,"极速飞车",24,24,BLUE);
						puthz(195,50*(m+1)+20,"极速世界",24,24,BLUE);
						puthz(357,50*(m+1)+20,"已预约",24,24,BLUE);
						puthz(525,50*(m+1)+20,"取消",24,24,BLUE); 
						break;
				}
			}
		}				//将文件预约情况从数组里面打印出来，转移到屏幕上 
		while(1)
		{
			newmouse(&MouseX,&MouseY,&press);
			for(m=0;m<j;m++)
			{
				if(MouseX>470&&MouseX<620&&MouseY>50*(m+1)&&MouseY<50*(m+2))   //如果一直此处而未点击 
				{  
	       			if(mouse_press(470,50*(m+1),620,50*(m+2))==2) 
    				{	
						MouseS=1;
              			highlight(470+1,50*(m+1)+1,620-1,50*(m+2)-1,LIGHTBLUE);				
						continue;
					}
					else if(mouse_press(470,50*(m+1),620,50*(m+2))==1)   //如果点击了取消预约 
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
			if(MouseX>50&&MouseX<140&&MouseY>425&&MouseY<460)//在返回键上
			{  
	       		if(mouse_press(50,425,140,460)==2)
    			{ 
				    MouseS=1;	  			 
    				setcolor(RED);
	   				setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	   				setfillstyle(1,CYAN);
	    			bar(50,425,140,460);
	    			rectangle(50,425,140,460);	
					puthz(70,430,"返回",24,24,LIGHTCYAN);				
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
			if(MouseX>490&&MouseX<580&&MouseY>425&&MouseY<460)   //跳转至下一页 
			{  
	      		if(mouse_press(490,425,580,460)==2)
    			{
    				MouseS=1;
    				setcolor(RED);
	    			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    			setfillstyle(1,RED);
	    			bar(490,425,580,460);
	    			rectangle(490,425,580,460);	
					puthz(500,430,"下一页",24,24,LIGHTCYAN);				
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
	puthz(45,20,"项目名称",24,24,RED);
	puthz(195,20,"所在区域",24,24,RED);
	puthz(345,20,"项目时间",24,24,RED);
	puthz(495,20,"取消预约",24,24,RED);
	cover(560,380,620,420,WHITE)
	highlight(560,380,620,420,BLACK);
	puthz(562,388,"返回",24,32,RED);
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
