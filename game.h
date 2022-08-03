#pragma once
//定义棋盘的大小
//涉及行和列可引用
#define ROW 3
#define COL 3

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//声明需要加分号

void InitBoard(char board[ROW][COL], int row, int col);//声明棋盘初始化函数

void DisplayBoard(char board[ROW][COL], int row, int col);//声明打印棋盘函数

void game();//声明游戏主体函数

void PlayerMove(char board[ROW][COL], int row, int col);//声明玩家下棋函数

void ComputerMove(char board[ROW][COL], int row, int col);//声明电脑下棋函数


//声明输赢函数
//玩家赢 '*'
//电脑赢 '#'
//平局   'Q'
//继续   'C'

char IsWin(char board[ROW][COL], int row, int col);

//判断是否平局
int IsFull(char board[ROW][COL], int row, int col);

