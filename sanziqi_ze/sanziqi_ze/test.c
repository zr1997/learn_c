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
	printf("请玩家落子\n");
	while (1){
		printf("请玩家输入坐标(row) (col)\n");
		int row, col;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			printf("输入的坐标非法，请重新输入：\n");
			continue;
		}
		if (g_board[row][col] != ' '){
			printf("该位置已有子，请重新输入：\n");
            continue;
		}
		    g_board[row][col] = 'X';
			break;
	}
}
void ComputerMove(){
	printf("请电脑落子\n");
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
	for (int row = 0; row < ROW; ++row){	//先检查行
		if (g_board[row][0] == g_board[row][1] &&
			g_board[row][0] == g_board[row][2] &&
			g_board[row][0] != ' '){
			return g_board[row][0];
		}
	}
	for (int col = 0; col < COL; ++col){	//再检查列
		if (g_board[0][col] == g_board[1][col] &&
			g_board[0][col] == g_board[2][col] &&
			g_board[0][col] != ' '){
			return g_board[0][col];
		}
	}
	//再检查两条斜线
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
	//最后检查是否为平局
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
	Init();//初始化棋盘为‘ ’
	char winner;
	while (1){
		ComputerMove();
		Printf();
		//电脑落子检查是否结束游戏
	    //玩家的子为‘x’电脑的子为‘o’
		//winner == ‘x’时玩家胜；winner == ‘o’时电脑胜
		//winner == ‘ ’时胜负未分；winner == ‘q’是平局
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
		PlayerMove();//玩家落子检查是否结束游戏
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
	}
	Printf();
	if (winner == 'X'){
		printf("玩家胜\n");
	}else if (winner == 'O'){
		printf("电脑胜\n");
	}else if(winner == 'Q'){
		printf("平局\n");
	}
	system("pause");
	return 0;
}