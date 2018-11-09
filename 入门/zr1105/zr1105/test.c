#include <stdio.h>
void Swap(int *x, int *y){
	int tmp = *x;
	 *x = *y;
	 *y = tmp;
}
int main(){
	int a=10;
	int b=20;
	Swap(&a, &b);
	//int *x = &a;
	//int *y = &b;
	//int tmp = *x;
	//*x = *y;
	//*y = tmp;
	printf("a=%d,b=%d\n",a, b);
	system("pause");
	return 0;
}