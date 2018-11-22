#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value){
	int count = 0;
	for (int i = 0; i < 32; ++i){
		if (value & (1<<i)){
			++count;
		}
	}
	return count;
}
int main(){
	int num = 15;

	printf("%d\n", count_one_bits(num));
	system("pause");
	return 0;
}