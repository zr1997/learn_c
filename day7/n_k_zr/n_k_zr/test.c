#include<stdio.h>
int Pow(int n,int k){
	if (k == 0){
		return 0;
	}else if (k == 1){
		return n;
	}else{
		return n*Pow(n, k - 1);
	}
}
int main(){
	printf("%d", Pow(5, 5));
	system("pause");
	return 0;
}