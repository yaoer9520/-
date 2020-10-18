#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
IMAGE jie;
int x,y,f=0,z,h=1,i=0;
char z1;
void hui1()
{
	setbkmode(0);
	settextcolor(RGB(255,0,0));
	settextstyle(48,0,_T("黑体"));
	outtextxy(0,0,_T("开始游戏"));
}
void hui2()
{
	setfillcolor(RGB(0,100,100));
	fillrectangle(0,0,200,48);
	hui1();
}
void hui3()
{
	setfillcolor(RGB(255,255,255));
	fillrectangle(0,0,200,48);
	hui1();
}
void chu()
{
	if(f==0)
	{
		x=0,y=rand()%700;
		z=rand()%26+97;
		f=1;
	}
}
void main()
{
	MOUSEMSG m;
	initgraph(800,600);
	srand(time(NULL));
	loadimage(&jie,_T("界面.jpg"),800,600);
	putimage(0,0,&jie);
	hui1();
	while(1)
	{
		if(MouseHit)
		{
			m=GetMouseMsg();
		}
		printf("%d,%d\n",m.x,m.y);
		if(m.x<=200&&m.x>=0&&m.y>=0&&m.y<=48)
		{
			hui2();
		}
		else
		{
			hui3();
		}
		if(m.x<=200&&m.x>=0&&m.y>=0&&m.y<=48&&m.uMsg==WM_LBUTTONDOWN)
		{
			break;
		}
	}
	cleardevice();
	settextcolor(RGB(0,255,0));
	settextstyle(48,0,_T("宋体"));
	while(1)
	{
		chu();
		outtextxy(y,x,z);
		x+=h;
		Sleep(10);
		cleardevice();
		if(kbhit())
		{
			z1=getch();
			if(z1==z)
			{
				cleardevice();
				f=0;
				i++;
			}
			if(i==2)
			{
				h++;
				i=0;
			}
		}
	}
}