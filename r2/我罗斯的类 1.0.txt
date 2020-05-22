#include <iostream>
#include <windows.h>
#include<string>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#define x1 0
#define y1 0
#define x2 48
#define y2 0
using namespace std;

int block0[19][4][4] = {{ { 0,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },
{ 0,0,0,0 } },{ { 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } },
{ { 0,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 } },
{ { 0,0,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } },
{ { 2,0,0,0 },{ 0,0,0,0 },{ 0,1,0,0 },{ 1,1,1,0 } },
{ { 2,0,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,1,0,0 } },
{ { 3,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 1,0,0,0 } },
{ { 3,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } },
{ { 3,0,0,0 },{ 0,0,0,0 },{ 0,0,1,0 },{ 1,1,1,0 } },
{ { 3,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 } },
{ { 4,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,0,1,0 } },
{ { 4,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 1,1,0,0 } },
{ { 4,0,0,0 },{ 0,0,0,0 },{ 1,0,0,0 },{ 1,1,1,0 } },
{ { 4,0,0,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 } },
{ { 5,0,0,0 },{ 0,0,0,0 },{ 0,1,1,0 },{ 1,1,0,0 } },
{ { 5,0,0,0 },{ 1,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } },
{ { 6,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 0,1,1,0 } },
{ { 6,0,0,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 } },
{ { 7,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 1,1,0,0 } }};

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

void initialWindow(HANDLE hOut);//初始界面 
void SetPos(HANDLE hOut,int x, int y);//移动光标






class Block
{
	private:
		int feature[4][4];
	public:
		
		
};
class Player
{
	private:
		int x,y,num,score,newblock[4][4],nextblock[4][4];
		Block block;
	public:
		Player(int n,const int x0,int y0)
		{
			num=n;
			x=x0;
			y=y0;
			score=0;
		}
		void randBlock(HANDLE hOut);
		void printBlock(HANDLE hOut, int block[4][4]);//打印 
		void PrintScreen();//打印窗口
};


int main()
{
	initialWindow(hOut);
//	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Player player1(1,x1,y1),player2(2,x2,y2);
	player1.PrintScreen();
	player2.PrintScreen();
	player1.randBlock(hOut);
	player2.randBlock(hOut);
	while(1)
	{
		
	}
	return 0;
}



void Player::randBlock(HANDLE hOut)
{
   // clearBlock(hOut, block, 5, 15);
	int m,i;
	m=rand()%19;
	for (i = 0; i < 4; i++)
	{
        for (int j = 0; j < 4; j++)
        {
            nextblock[i][j] = block0[m][i][j];
        }
    }
    printBlock(hOut, nextblock);
}

void Player::PrintScreen()//打印窗口
{
	SetPos(hOut, x+8, y+23);
	cout<<"Player"<<num;
	SetPos(hOut, x, y);
    for (int i = 0; i < 20; i++)
    {
    	SetPos(hOut, x, y+i);
        cout << "■                    ■                    ■" << endl;
    } 
	SetPos(hOut, x+0, y+20);
    cout << "■■■■■■■■■■■■";
    SetPos(hOut, x+24, y);
    cout << "☆☆☆☆☆☆☆☆☆☆";
	SetPos(hOut, x+24, y+20);
    cout << "☆☆☆☆☆☆☆☆☆☆■";
    SetPos(hOut, x+26, y+1);
    cout << "分    数：      ";
    
    SetPos(hOut, x+26, y+4);
    cout << "下一方块：";
} 






void initialWindow(HANDLE hOut)
{
    SetConsoleTitle("俄罗斯方块");
    COORD size = { 100, 30 };
    SetConsoleScreenBufferSize(hOut, size);
    SMALL_RECT rc = { 0, 0, 99, 30 };
    SetConsoleWindowInfo(hOut, true, &rc);
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(hOut, &cursor_info);
}
void SetPos(HANDLE hOut,int x, int y)//移动光标
{
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}



void Player::printBlock(HANDLE hOut, int block[4][4])
{
    switch (block[0][0])
    {
    case 0: 
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
        break;
    case 2:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 3: 
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 4:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 5:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 6:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 7:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        break;
    default:
        break;
    }
    for (int i = 0; i < 4; ++i)
    {
       if (i+x+5>= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {

                    SetPos(hOut, 2*(x/2+15+j), y+5+i);
                    cout << "■";
                }
            }
        }
    }
}