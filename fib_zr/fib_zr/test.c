#include<stdio.h>
int Fib(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}
int main(){
	printf("%d\n", Fib(4));
	system("pause");
	return 0;
}