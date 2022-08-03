#define _CRT_SECURE_NO_WARNINGS 1

//������������Ϸ

#include"game.h"  //�����Լ���ͷ�ļ���˫����

//��Ϸ�㷨ʵ��
void game()
{
	char ret = 0;  //�����ж���Ӯ�����ķ���ֵ
	//���� ���������Ϣ
	char board[ROW][COL] = { 0 };  //�������ӵ����� ȫΪ�ո�
	//0Ϊ���ɴ�ӡ�ַ� char����
	//��ʼ������ ���̿հ״�Ϊ�ո�
	InitBoard(board, ROW, COL);  //��ʼ�����̺���
	//������ʾ���̵�����
	//   |   |   
	//---|---|---
	//   |   |   
	//---|---|---
	//   |   |   
	DisplayBoard(board,ROW, COL);  //��ӡ���̺���
	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);

		//�ж���Ӯ
		ret=IsWin(board,ROW,COL);


		if (ret != 'C')
		{
			break;
		}

		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�ж���Ӯ
		ret = IsWin(board,ROW,COL);  //�����ж���Ӯ�ĺ���
		if (ret != 'C')  //��Ϸ����������ѭ��  C
		{
			break;    //����ѭ��
		}
	}
	if (ret == '*') 
	{
		printf("���Ӯ\n");  //���Ӯ *
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");  //����Ӯ #
	}
	else
	{
		printf("ƽ��\n");    //ƽ�� �����ַ�
	}
}

void menu()  //��Ϸ��ʼ����
{
	printf("*******************************\n");
	printf("******1.play    0.exit*********\n");
	printf("*******************************\n");
}
void test()   //����
{
	int input = 0;  //�������ı���
	srand((unsigned int)time(NULL));  // �������������
	do
	{
		menu(); //��ʼ��Ϸ����
		printf("��ѡ��>");
		scanf("%d", &input); //��������Ƿ������Ϸ 0��1
		switch (input)   //�ж���������������ȷ���Ƿ������Ϸ switchѡ����
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
			break;
		}
	} while (input);  //��ν�����Ϸ��Ϸ��ѭ��
}
int main()
{
	test();
	return 0;
}