#define _CRT_SECURE_NO_WARNINGS 1

//测试三子棋游戏

#include"game.h"  //引用自己的头文件用双引号

//游戏算法实现
void game()
{
	char ret = 0;  //用于判断输赢函数的返回值
	//数组 存放落子信息
	char board[ROW][COL] = { 0 };  //创建落子的数组 全为空格
	//0为不可打印字符 char类型
	//初始化棋盘 棋盘空白处为空格
	InitBoard(board, ROW, COL);  //初始化棋盘函数
	//期望显示棋盘的样子
	//   |   |   
	//---|---|---
	//   |   |   
	//---|---|---
	//   |   |   
	DisplayBoard(board,ROW, COL);  //打印棋盘函数
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);

		//判断输赢
		ret=IsWin(board,ROW,COL);


		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断输赢
		ret = IsWin(board,ROW,COL);  //返回判断输赢的函数
		if (ret != 'C')  //游戏继续，继续循环  C
		{
			break;    //跳出循环
		}
	}
	if (ret == '*') 
	{
		printf("玩家赢\n");  //玩家赢 *
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");  //电脑赢 #
	}
	else
	{
		printf("平局\n");    //平局 其他字符
	}
}

void menu()  //游戏初始界面
{
	printf("*******************************\n");
	printf("******1.play    0.exit*********\n");
	printf("*******************************\n");
}
void test()   //测试
{
	int input = 0;  //玩家输入的变量
	srand((unsigned int)time(NULL));  // 随机数的生成器
	do
	{
		menu(); //初始游戏界面
		printf("请选择：>");
		scanf("%d", &input); //玩家输入是否进行游戏 0，1
		switch (input)   //判断玩家输入的数据来确定是否进行游戏 switch选择函数
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择\n");
			break;
		}
	} while (input);  //多次进行游戏游戏，循环
}
int main()
{
	test();
	return 0;
}