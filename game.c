#define _CRT_SECURE_NO_WARNINGS 1
//游戏算法实现本体

#include"game.h"//引用头文件不需要加分号

void InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{

		for (j = 0; j < col; j++)
		{//1.打印一行的数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.打印分割行
		if (i < row - 1)  //少一行的分隔符
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}

//玩家下棋函数
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋：>\n");
	while (1)
	{
		printf("请输入要下的坐标:>\n");
		scanf("%d%d", &x, &y);
		//判断x,y的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断是否下重复
			if (board[x - 1][y - 1] == ' ')  //x,y从一开始，而数组为零,与数组对应
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % row;  //随机函数rand
		y = rand() % col;
		//判断坐标是否被占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
}
//判断平局函数
//返回1，棋盘满
//返回0，棋盘未满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j=0;j<col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0; //未满
			}
		}
	}
	return 1;  //满
}

//判断输赢函数
//横三，竖三，斜三
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;

	//判断横三
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}

	//判断竖三
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//判断斜三
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1]!= ' ')
		{
			return board[1][1]; 
		}
		else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		{
			return board[1][1];
		}

	//判断是否平局
	if (1 == IsFull(board, ROW, COL))  //通过返回值来判断是否平局
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}