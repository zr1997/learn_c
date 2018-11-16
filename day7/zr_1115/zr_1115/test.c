#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROM 10
#define MAX_COL 10
#define DEFAULT_MINE_COUNT 10

int Menu(){
	printf("================\n");
	printf("1:开始游戏\n");
	printf("0:退出游戏\n");
	printf("================\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Init(char show_map[MAX_ROM + 2][MAX_COL + 2],
	char mine_map[MAX_ROM+2][MAX_COL+2]){
	for (int row = 0; row < MAX_ROM + 2; ++row){
		for (int col = 0; col < MAX_COL + 2; ++col){
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROM + 2; ++row){
		for (int col = 0; col < MAX_COL + 2; ++col){
			mine_map[row][col] = '*';
		}
	}
	//随机制造n个雷,放于雷阵中
	int mine_count = DEFAULT_MINE_COUNT;
	while (mine_count > 0){
		int row = rand() % 10 + 1;
		int col = rand() % 10 + 1;
		if (mine_map[row][col] == '1'){
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}
void DisplayMap(char map[MAX_ROM + 2][MAX_COL + 2]){
	//打印第一行纵坐标
	printf("   ");
	for (int i = 1; i <= MAX_COL; ++i){
		printf("%d ", i);
	}
	printf("\n");
	//打印上边框
	for (int i = 1; i <= MAX_COL; ++i){
		printf("----");
	}
	printf("\n");
	//按行打印具体地图
	for (int row = 1; row <= MAX_ROM; ++row){
		printf("%02d| ", row);
		for (int col = 1; col <= MAX_COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void UpdataShowMap(char show_map[MAX_ROM + 2][MAX_COL + 2],
	char mine_map[MAX_ROM + 2][MAX_COL + 2], int row, int col){
	int mine_cnt = (mine_map[row - 1][col - 1] - '0')
		+ (mine_map[row - 1][col] - '0')
		+ (mine_map[row - 1][col + 1] - '0')
		+ (mine_map[row][col - 1] - '0')
		+ (mine_map[row][col + 1] - '0')
		+ (mine_map[row + 1][col + 1] - '0')
		+ (mine_map[row + 1][col] - '0')
		+ (mine_map[row + 1][col - 1] - '0');
	show_map[row][col] = '0' + mine_cnt;
}
void Game(){
	//进行游戏
	//使用两个二维数组表示地图
	char show_map[MAX_ROM + 2][MAX_COL + 2];
	//第一个是玩家看到的地图
	//1.没有被掀开,用'*'表示
	//2.掀开用数字表示周围有几个雷
	char mine_map[MAX_ROM + 2][MAX_COL + 2];
	//第二个是雷阵
	//1.是地雷,用'1'表示
	//2.不是地雷,用'0'表示
	int blank_cnt = 0;
	Init(show_map, mine_map);
	DisplayMap(show_map);
	while (1){
		//玩家输入坐标并判定坐标是否合法
		int row, col;
		printf(""); 
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > MAX_ROM || col <= 0 || col > MAX_COL){
			printf("输入不合法,请重新输入!\n");
			continue;
		}
		//判断玩家是否踩雷,踩雷则游戏结束
		if (mine_map[row][col] == '1'){
			printf("游戏结束");
			DisplayMap(mine_map);
			break;
		}
		//没踩雷判定是否 所有格子被掀开则玩家胜利
		++blank_cnt;
		if (blank_cnt == MAX_ROM*MAX_COL - DEFAULT_MINE_COUNT){
			printf("恭喜!\n");
			DisplayMap(mine_map);
			break;
		}
		//没有全部掀开则统计该位置周围有几个雷,将数字更新到地图上
		UpdataShowMap(show_map,mine_map,row,col);
		DisplayMap(show_map);
	}
}
void Start(){
	//游戏的入口函数
	while (1){
		int choice = Menu();
		if (choice == 0){
			//退出
			break; 
		}
		Game();
	}
}

int main(){
	Start();
	system("pause");
	return 0;
}