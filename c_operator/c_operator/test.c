#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value){
	int count = 0;
	while (value){
		if (value % 2 == 1 || value % 2 == (-1)){
			++count;
		}
		value /= 2;
	}
	return count;
}
int main(){
	int num = 15;

	printf("%d\n", count_one_bits(num));
	system("pause");
	return 0;
}