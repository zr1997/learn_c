#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Mul(int m){
	for (int line = 1; line <= m; ++line){
		for (int column = 1; column <= line; ++column){
			int ret = line * column;
			printf("%d*%d=%2d\t", line, column, m);
		}
		printf("\n");
	}
}
int main(){
	int num = 0;
	printf("input a number:");
	scanf("%d",&num);
	Mul(num);
	system("pause");
	return 0;
}
