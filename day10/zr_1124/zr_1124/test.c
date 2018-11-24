#include<stdio.h>
#include<stdlib.h>
int Printf_num(int num){
	if (num != 0 ){
		printf("%d", num % 10);
		Printf_num(num / 10);
	}
}
int main(){
	int num = 1234;
	Printf_num(num);
	system("pause");
	return 0;
}