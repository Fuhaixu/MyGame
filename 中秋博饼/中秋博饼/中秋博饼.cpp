#include"crap.h"



int main()
{
	mciSendString("open ./res/��������.wma alias bgm", 0, 0, 0);
	mciSendString("play bgm repeat", 0, 0, 0);
	Init();
	draw();
	while(1)
	{
		keych();
	}
	return 0;
}

void Init()
{

	initgraph(WIDTH, HEIGHT);//��  ��
	setbkcolor(WHITE);
	cleardevice();
	loadimage(&img[0], "res\\0.jpg", IMAGESIZE, IMAGESIZE);
	loadimage(&img[1], "res\\1.jpg", IMAGESIZE, IMAGESIZE);
	loadimage(&img[2], "res\\2.jpg", IMAGESIZE, IMAGESIZE);
	loadimage(&img[3], "res\\3.jpg", IMAGESIZE, IMAGESIZE);
	loadimage(&img[4], "res\\4.jpg", IMAGESIZE, IMAGESIZE);
	loadimage(&img[5], "res\\5.jpg", IMAGESIZE, IMAGESIZE);
	loadimage(&img[6], "res\\6.jpg", IMAGESIZE, IMAGESIZE);


	//setmenu();
	settextcolor(BLACK);
	settextstyle(25, 9,"΢���ź�");
	outtextxy(WIDTH*0.35, 180, "�ո�������ӣ�R����ԭ��Ϸ");
	outtextxy(WIDTH*0.35, 210, "S��һ��������");
	outtextxy(WIDTH*0.35, 240, "ESC���˳���Ϸ");
	outtextxy(WIDTH*0.35, 300, "ף��ҿ�ѧ���֣����ӣ�");
	//outtextxy(WIDTH*0.35, 260, "");


	// ʵ����˸��"�����������"
	int c = 255;
	while (!kbhit())
	{
		settextcolor(RGB( c,0, 0));
		outtextxy(WIDTH*0.4, 140, "���ﲩ��");
		outtextxy(WIDTH*0.35, 380, "�������������Ϸ����");
		c -= 8;
		if (c < 0) c = 255;
		Sleep(20);
	}


}


void draw()
{
	cleardevice();
	int i, j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
			switch (craps[i][j])
		{
			case 0:
				putimage(IMAGESIZE * j, IMAGESIZE * i, &img[0]);
				break;
			case 1:
				putimage(IMAGESIZE * j, IMAGESIZE * i, &img[1]);
				break;
			case 2:
				putimage(IMAGESIZE * j, IMAGESIZE * i, &img[2]);
				break;
			case 3:
				putimage(IMAGESIZE * j, IMAGESIZE * i, &img[3]);
				break;
			case 4:
				putimage(IMAGESIZE * j, IMAGESIZE * i, &img[4]);
				break;
			case 5:
				putimage(IMAGESIZE * j, IMAGESIZE * i, &img[5]);
				break;
			case 6:
				putimage(IMAGESIZE * j, IMAGESIZE * i, &img[6]);
				break;
		}
		printf("\n");
	}
	setcolor(BLACK);
	rectangle(8, IMAGESIZE * 2 + 10, WIDTH*0.36, HEIGHT -10);
	rectangle(WIDTH*0.37, IMAGESIZE * 2 + 10, WIDTH*0.66, HEIGHT - 10);
	rectangle(WIDTH*0.67, IMAGESIZE * 2 + 10, WIDTH - 8, HEIGHT - 10);
	settextstyle(20, 0, "�ź�");

	outtextxy(WIDTH*0.4, IMAGESIZE * 2 + 20, "������");
	for (i = 0; i <6; i++)
		outtextxy(WIDTH*0.4, IMAGESIZE * 2 + 180 - i * 20, win[i]);

	outtextxy(WIDTH*0.7, IMAGESIZE * 2 +20, "����˵��");
	outtextxy(WIDTH*0.7, IMAGESIZE*2+100, "�ո��������");
	outtextxy(WIDTH*0.7, IMAGESIZE * 2 + 130, "(��6�γ����ս��)");
	outtextxy(WIDTH*0.7, IMAGESIZE*2+160, "R��������Ϸ");
	outtextxy(WIDTH*0.7, IMAGESIZE*2+190, "S��һ��������");
	outtextxy(WIDTH*0.7, IMAGESIZE * 2 + 220, "ESC�˳���Ϸ");

	Sleep(100);
}

void LastDraw()
{
	int i,j;

	for (i = 0; i<2;i++)
	for (j = 0; j<3; j++)
	{
		if (!craps[i][j])
			return;
	}

	outtextxy(13, IMAGESIZE * 2 + 20, "���ս���");

	for (i = 5; i>-1;i--)
	{
		if (strlen(win[i]))
		{
			if (i == 2&&strlen(win[0]))
			{
				strcpy(winget, win[i]);
				strcat(winget, " + ");
				if (strlen(win[1]))
					strcat(winget, win[1]);
				else strcat(winget, win[0]);
				break;
			}
			strcpy(winget, win[i]);
			break;
		}
	}

	if (i == -1)strcpy(winget, "��");

	outtextxy(13, IMAGESIZE * 2 + 100, winget);
	outtextxy(13, IMAGESIZE * 2 + 180, "����ȡ��Ľ�Ʒ");

}


void game()
{
	int x;
	int i, j, flag = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (craps[i][j] == 0)
			{
				draw();
				LastDraw();
				srand((unsigned)time(NULL));
				x = (rand()) % 6 + 1;
				craps[i][j] = x;
				judge();
				flag = 1;
				break;
			}
		}
		if (flag)break;
	}
	Sleep(200);
	draw();
	LastDraw();
	Sleep(100);

	
}


//void game()
//{
//	int x;
//	int i, j, flag = 0;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			draw();
//
//			if (craps[i][j] == 0&&(i*j<1))
//			{
//				craps[i][j] = 3;
//				judge();
//				flag = 1;
//				break;
//			}
//			if (craps[i][j] == 0 && (i*j >= 1))
//			{
//				craps[i][j] = 4;
//				judge();
//				flag = 1;
//				break;
//			}
//
//		}
//		if (flag)break;
//	}
//	Sleep(200);
//	draw();
//	Sleep(200);
//}


//�������룬��Ϸ����
void keych()
{
	char ch;
	ch = getch();
	switch (ch)
	{
	case VK_ESCAPE:
		hOut = GetForegroundWindow();
		if (IDYES == MessageBox(hOut, "����ȷ���˳���Ϸ��", "�˳�����", MB_YESNO))
			exit(1);
		break;
	case VK_SPACE:
		game();
		break;
	case 's':
	case 'S':
	{
		int count=0,i,j;
		for (i = 0; i < 2;i++)
		for (j = 0; j < 3;j++)
		if (craps[i][j])count++;
		for (int i = 0; i < 6-count; i++)
		game();
	}
		break;
	case 'r':
	case 'R':
		rest();
	default:
		break;
	}
}


//������жϿ�����ж�
void judge()
{

	int i, j, k = 0;
	int si = 0;
	int one = 0;


	int a[6];
	for (i = 0; i<2; i++)
	for (j = 0; j<3; j++)
	{
		a[k++] = craps[i][j];
	}


	for (k = 0; k<6; k++)
	{
		if (a[k] == 1)one++;

		if (a[k] == 4)
		{
			si += 1;
			continue;
		}
	}

	char ch[20];

	if (wuzi())
	{
		sprintf(ch, "״Ԫ���ӵǿ� %d", wuzi());
		strcpy(win[5], ch);

	}

	if (Same() != -1 && Same() != 7 && Same() != 0)
	{
		sprintf(ch, "״Ԫ���ӵǿ� %d", Same());
		strcpy(win[5], ch);
	}



	switch (si)
	{
	case 1:
		strcpy(win[0], "���һ��");
		break;
	case 2:
		strcpy(win[1], "���˶���");
		break;
	case 3:
		strcpy(win[3], "̽������");
		break;
	case 4:
		if (win[5] == 0)
			strcpy(win[5], "״Ԫ");
		if (one == 2)strcpy(win[5], "״Ԫ���");
		break;
	case 5:
		strcpy(win[5], "״Ԫ����");
		break;
	case 6:
		strcpy(win[5], "״Ԫ���ݺ�");
		break;
	}


	if (Same() == -1)strcpy(win[4], "���۶���");

	if (Same() == 7)strcpy(win[2], "��ʿ�Ľ�");




}


int  Same()
{
	int same = 0, t, g;
	t = craps[0][0];
	int i, j;
	for (i = 0; i < 2; i++)
	for (j = 0; j < 3; j++)
	{
		if (craps[i][j] == t)same++;
	}

	if (same == 5)
	{
		return t;//���ӵǿ�
	}
	if (same >=4|| jingshi())return 7;//�Ľ�ʿ
	if (bangyan())return -1;//���ۣ����ã�


	return 0;

}


//�����ʿ�����
int jingshi()
{
	int i, j, t, g;
	int same = 0;
	t = craps[0][1];
	g = 0;
	if (t == 0)return 0;

	for (i = 0; i < 2; i++)
	for (j = 0; j < 3; j++)
	{
		if (i == 0 && j == 0)continue;
		if (craps[i][j] == t)same++;
		if (craps[i][j])g++;
	}

	if (same == 4 )return 1;

	t = craps[0][2];
	same = 0;

	if (t == 0)return 0;
	for (i = 0; i < 2; i++)
	for (j = 0; j < 3; j++)
	{
		if ((i == 0 && j == 0) || (i == 0 && j == 1))continue;
		if (craps[i][j] == t)same++;
	}

	if (same == 4)return 1;

	return 0;

}


//������۵����
int bangyan()
{
	int a[6];
	int i, j, k, t;

	k = 0;
	for (i = 0; i < 2; i++)
	for (j = 0; j < 3; j++)
	{
		a[k++] = craps[i][j];
	}


	for (i = 0; i < 6; i++)
	for (j = 5; j>i; j--)
	{
		if (a[i]>a[j])
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	int n = 0;
	for (i = 0; i < 6; i++)
	{
		if (a[i] == i + 1)n++;
	}

	if (n == 6)return 1;
	return 0;


}


//�������ӷ�ǵ����
int wuzi()
{
	int same = 0, t, g;
	t = craps[0][1];
	g = 0;
	int i, j;
	for (i = 0; i < 2; i++)
	for (j = 0; j < 3; j++)
	{
		if (craps[i][j] == t)same++;
		if (craps[i][j])g++;
	}

	if (same == 5)
	{
		return t;//���ӵǿ�
	}

	return 0;
}


//������Ϸ
void rest()
{
	int i, j;

	for (i = 0; i < 2; i++)
	for (j = 0; j < 3; j++)
	{
		craps[i][j] = 0;
	}

	for (i = 0; i < 6; i++)
	{
		memset(win[i], 0, 20);
	}

	draw();

}