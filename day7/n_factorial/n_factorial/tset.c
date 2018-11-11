#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Factorial(int n){
	int i = 0;
	int product = 0;
	for (i = 1; i <= n; ++i){
		return product = Factorial(n - 1)*n;
	}
}
int factorial(int n){
	int product = 1;
	for ( n; n > 0; --n){
		product *= n;
	}
	return product;
}
int main(){
	int n = 0;
	printf("input a number: \n");
	scanf("%d", &n);
	printf("%d\n", Factorial(n));
	printf("%d\n", factorial(n));
	system("pause");
	return 0;
}