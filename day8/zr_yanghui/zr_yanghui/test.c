#include<stdio.h>
#include<stdlib.h>
int Yanghui_triangle(int i,int j){
	if (j == 1 || j == i + 1){
		return 1;
	}
	return Yanghui_triangle(i - 1, j - 1)
		+ Yanghui_triangle(i - 1, j);
}
int main(){
	//´òÓ¡Ñî»ÔÈı½Ç
	int i, j;
	for (i = 0; i < 6; ++i){
		for (j = 1; j < i + 1; ++j){

			printf("%d\t", Yanghui_triangle(i, j));
		}
	printf("1\n");
	}
	system("pause");
	return 0;
}