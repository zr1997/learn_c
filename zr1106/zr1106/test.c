#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void Swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int main(){
	int i = 10;
	int j = 20;
	Swap(&i, &j);
	printf("i=%d\n", i);
	printf("j=%d\n", j);
	system("pause");
	return 0;
}