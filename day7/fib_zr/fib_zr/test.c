#include<stdio.h>
#include<stdlib.h>
int Fib(int n){
	int i, j, sum;
	for (i = 1, j = 1, n = 3; n < 11; n++){
		sum = i + j;
		i = j;
		j = sum;
	}
	return j;
}
int main(){
	printf("%d\n", Fib(10));
	system("pause");
	return 0;
}