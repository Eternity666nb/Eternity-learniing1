#pragma once
//�������̵Ĵ�С
//�漰�к��п�����
#define ROW 3
#define COL 3

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//������Ҫ�ӷֺ�

void InitBoard(char board[ROW][COL], int row, int col);//�������̳�ʼ������

void DisplayBoard(char board[ROW][COL], int row, int col);//������ӡ���̺���

void game();//������Ϸ���庯��

void PlayerMove(char board[ROW][COL], int row, int col);//����������庯��

void ComputerMove(char board[ROW][COL], int row, int col);//�����������庯��


//������Ӯ����
//���Ӯ '*'
//����Ӯ '#'
//ƽ��   'Q'
//����   'C'

char IsWin(char board[ROW][COL], int row, int col);

//�ж��Ƿ�ƽ��
int IsFull(char board[ROW][COL], int row, int col);

