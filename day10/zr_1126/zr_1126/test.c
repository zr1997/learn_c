#include<stdio.h>
#include<stdlib.h>
int Diff_bit(int i,int j){
	int ret = 0;
	int count = 0;
	ret = i^j;
	while (ret){
		count++;
		ret = ret&(ret - 1);
	}
	return  count;
}
int main(){
	int i = 1999;
	int j = 2299;
	printf("%d\n", Diff_bit(i, j));
	system("pause");
	return 0;
}