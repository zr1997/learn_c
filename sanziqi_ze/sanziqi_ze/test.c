#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
char g_board[ROW][COL];
void Init(){
	srand((unsigned int)time(0));
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			g_board[row][col] = ' ';
		}
	}
}
void Printf(){
	for (int row = 0; row < ROW; ++row){
		printf("| %c | %c | %c |\n",g_board[row][0],g_board[row][1],
			g_board[row][2]);
		printf(" ---|---|--- \n");
	}
}
void PlayerMove(){
	printf("���������\n");
	while (1){
		printf("�������������(row) (col)\n");
		int row, col;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			printf("���������Ƿ������������룺\n");
			continue;
		}
		if (g_board[row][col] != ' '){
			printf("��λ�������ӣ����������룺\n");
            continue;
		}
		    g_board[row][col] = 'X';
			break;
	}
}
void ComputerMove(){
	printf("���������\n");
	while (1){
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_board[row][col] != ' '){
			continue;
		}
		g_board[row][col] = 'O';
		break;
	}
}
char CheckWinner(){
	for (int row = 0; row < ROW; ++row){	//�ȼ����
		if (g_board[row][0] == g_board[row][1] &&
			g_board[row][0] == g_board[row][2] &&
			g_board[row][0] != ' '){
			return g_board[row][0];
		}
	}
	for (int col = 0; col < COL; ++col){	//�ټ����
		if (g_board[0][col] == g_board[1][col] &&
			g_board[0][col] == g_board[2][col] &&
			g_board[0][col] != ' '){
			return g_board[0][col];
		}
	}
	//�ټ������б��
	if (g_board[0][0] == g_board[1][1] &&
		g_board[0][0] == g_board[2][2] &&
		g_board[0][0] != ' '){
		return g_board[0][0];
	}
	if (g_board[0][2] == g_board[1][1] &&
		g_board[0][2] == g_board[2][0] &&
		g_board[0][2] != ' '){
		return g_board[0][2];
	}
	//������Ƿ�Ϊƽ��
	if (is_full()){
		return 'Q';
	}
	return ' ';
}
int is_full(){
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			if (g_board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
int main(){	
	Init();//��ʼ������Ϊ�� ��
	char winner;
	while (1){
		ComputerMove();
		Printf();
		//�������Ӽ���Ƿ������Ϸ
	    //��ҵ���Ϊ��x�����Ե���Ϊ��o��
		//winner == ��x��ʱ���ʤ��winner == ��o��ʱ����ʤ
		//winner == �� ��ʱʤ��δ�֣�winner == ��q����ƽ��
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
		PlayerMove();//������Ӽ���Ƿ������Ϸ
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
	}
	Printf();
	if (winner == 'X'){
		printf("���ʤ\n");
	}else if (winner == 'O'){
		printf("����ʤ\n");
	}else if(winner == 'Q'){
		printf("ƽ��\n");
	}
	system("pause");
	return 0;
}