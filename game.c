#define _CRT_SECURE_NO_WARNINGS 1
//��Ϸ�㷨ʵ�ֱ���

#include"game.h"//����ͷ�ļ�����Ҫ�ӷֺ�

void InitBoard(char board[ROW][COL], int row, int col)//��ʼ������
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

void DisplayBoard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{

		for (j = 0; j < col; j++)
		{//1.��ӡһ�е�����
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ���
		if (i < row - 1)  //��һ�еķָ���
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

//������庯��
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������壺>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>\n");
		scanf("%d%d", &x, &y);
		//�ж�x,y�ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж��Ƿ����ظ�
			if (board[x - 1][y - 1] == ' ')  //x,y��һ��ʼ��������Ϊ��,�������Ӧ
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
	while (1)
	{
		x = rand() % row;  //�������rand
		y = rand() % col;
		//�ж������Ƿ�ռ��
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
}
//�ж�ƽ�ֺ���
//����1��������
//����0������δ��
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
				return 0; //δ��
			}
		}
	}
	return 1;  //��
}

//�ж���Ӯ����
//������������б��
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;

	//�жϺ���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}

	//�ж�����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//�ж�б��
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1]!= ' ')
		{
			return board[1][1]; 
		}
		else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		{
			return board[1][1];
		}

	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))  //ͨ������ֵ���ж��Ƿ�ƽ��
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}