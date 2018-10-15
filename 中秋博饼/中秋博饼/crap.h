/*********************************


BY 伏海旭

游戏名称：中秋博饼
时间：2017/9/27

res:图片  115*115


********************************/

#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define N 6
#define WIDTH 690
#define HEIGHT 750
#define IMAGESIZE 230



IMAGE img[N + 1];
int craps[2][3] = { 0 };
int n;
HWND hOut;//窗口句柄
char win[6][20];
char winget[40];//最终奖项


void LastDraw();
void rest();
void draw();
void keych();
int wuzi();//五子
int jingshi();//进士
void judge();
int bangyan();//榜眼
int  Same();
void Init();














//void setmenu()
//{
//	outtextxy(125, 200, "设置界面");
//	/*printf("(输入后可按回车进行下一输入)");*/
//	outtextxy(125, 240, "请输入参赛者个数：");
//	scanf("%d", &n);
//	char ch[20];
//	sprintf(ch, "%s", n + '0');
//	outtextxy(125, 260, ch);
//	//printf("\n请输入参赛者姓名：");
//
//
//	//char ch[20];
//	//for (int i = 0; i < n; i++)
//	//{
//	//	sprintf(ch, "第%d位参赛者：", i + 1);
//	//	printf(ch);
//	//	scanf("%s", &player[i].name);
//	//}
//
//	while (!kbhit())
//	{
//		outtextxy(150, 480, "按任意键继续");
//	}
//
//}


