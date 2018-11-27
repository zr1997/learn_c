#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value){
	unsigned int ret = 0;
	int i = 0;
	for (i = 0; i < 32; ++i){
		ret = ret << 1;
		ret = ret | (value >> i) & 1;
	}
	return ret;
}
int main(){
	int num = 25;
	printf("%u\n", reverse_bit(num));
	system("pause");
	return 0;
}