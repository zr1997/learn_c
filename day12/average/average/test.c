#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Average(int i ,int j){
	return (i&j) + ((i^j) >> 1);
}
int main(){
	int i = 0;
	int j = 0;
	printf("请输入两个数: \n");
	scanf("%d %d", &i, &j);
	printf("%d\n",	Average(i, j));
	system("pause");
	return 0;
}