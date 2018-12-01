#include<stdio.h>
#include<stdlib.h>
int main(){
	int find = 0;
	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; ++i){
		find ^= arr[i];
	}
	printf("%d\n", find);
	system("pause");
	return 0;
}