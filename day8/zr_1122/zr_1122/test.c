#include<stdio.h>
#include<stdlib.h>
int Printf_num(int num){
	int i = 0;
	printf("奇数序列:\n");
	for (i = 30; i >= 0; i -= 2){
		if ((num >> i) & 0x1){
			printf(" 1 ");
		}else{
			printf(" 0 ");
		}
	}
	printf("\n");
	printf("偶数序列:\n");
	for (i = 31; i >= 1; i -= 2){
		if ((num >> i) & 0x1){
			printf(" 1 ");
		}
		else{
			printf(" 0 ");
		}
	}
}

int main(){
	int num =- 8;
	printf("%d\n", Printf_num(num));
	system("pause");
	return 0;
}