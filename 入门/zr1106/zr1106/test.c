#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Isleap(int i){
	if (i % 100 != 0){
		if (i % 4 == 0){
			return 1;
		}
		printf("\n");
		return 0;
	}
	if (i % 400 == 0){
		return 1;
	}
	return 0;
}
int main(){
	int ret = 0;
	int year = 0;
	printf("input a number:");
	scanf("%d", &year);
	ret = Isleap(year);
	if (ret == 1){
		printf("it is a leap year");
	}
	else{
		printf("it is not a leap year");
	}
	system("pause");
	return 0;
}