#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROM 10
#define MAX_COL 10
#define DEFAULT_MINE_COUNT 10

int Menu(){
	printf("================\n");
	printf("1:��ʼ��Ϸ\n");
	printf("0:�˳���Ϸ\n");
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
	//�������n����,����������
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
	//��ӡ��һ��������
	printf("   ");
	for (int i = 1; i <= MAX_COL; ++i){
		printf("%d ", i);
	}
	printf("\n");
	//��ӡ�ϱ߿�
	for (int i = 1; i <= MAX_COL; ++i){
		printf("----");
	}
	printf("\n");
	//���д�ӡ�����ͼ
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
	//������Ϸ
	//ʹ��������ά�����ʾ��ͼ
	char show_map[MAX_ROM + 2][MAX_COL + 2];
	//��һ������ҿ����ĵ�ͼ
	//1.û�б��ƿ�,��'*'��ʾ
	//2.�ƿ������ֱ�ʾ��Χ�м�����
	char mine_map[MAX_ROM + 2][MAX_COL + 2];
	//�ڶ���������
	//1.�ǵ���,��'1'��ʾ
	//2.���ǵ���,��'0'��ʾ
	int blank_cnt = 0;
	Init(show_map, mine_map);
	DisplayMap(show_map);
	while (1){
		//����������겢�ж������Ƿ�Ϸ�
		int row, col;
		printf(""); 
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > MAX_ROM || col <= 0 || col > MAX_COL){
			printf("���벻�Ϸ�,����������!\n");
			continue;
		}
		//�ж�����Ƿ����,��������Ϸ����
		if (mine_map[row][col] == '1'){
			printf("��Ϸ����");
			DisplayMap(mine_map);
			break;
		}
		//û�����ж��Ƿ� ���и��ӱ��ƿ������ʤ��
		++blank_cnt;
		if (blank_cnt == MAX_ROM*MAX_COL - DEFAULT_MINE_COUNT){
			printf("��ϲ!\n");
			DisplayMap(mine_map);
			break;
		}
		//û��ȫ���ƿ���ͳ�Ƹ�λ����Χ�м�����,�����ָ��µ���ͼ��
		UpdataShowMap(show_map,mine_map,row,col);
		DisplayMap(show_map);
	}
}
void Start(){
	//��Ϸ����ں���
	while (1){
		int choice = Menu();
		if (choice == 0){
			//�˳�
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