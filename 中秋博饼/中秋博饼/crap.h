/*********************************


BY ������

��Ϸ���ƣ����ﲩ��
ʱ�䣺2017/9/27

res:ͼƬ  115*115


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
HWND hOut;//���ھ��
char win[6][20];
char winget[40];//���ս���


void LastDraw();
void rest();
void draw();
void keych();
int wuzi();//����
int jingshi();//��ʿ
void judge();
int bangyan();//����
int  Same();
void Init();














//void setmenu()
//{
//	outtextxy(125, 200, "���ý���");
//	/*printf("(�����ɰ��س�������һ����)");*/
//	outtextxy(125, 240, "����������߸�����");
//	scanf("%d", &n);
//	char ch[20];
//	sprintf(ch, "%s", n + '0');
//	outtextxy(125, 260, ch);
//	//printf("\n�����������������");
//
//
//	//char ch[20];
//	//for (int i = 0; i < n; i++)
//	//{
//	//	sprintf(ch, "��%dλ�����ߣ�", i + 1);
//	//	printf(ch);
//	//	scanf("%s", &player[i].name);
//	//}
//
//	while (!kbhit())
//	{
//		outtextxy(150, 480, "�����������");
//	}
//
//}


