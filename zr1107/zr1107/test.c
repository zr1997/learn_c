#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int init(int arr[],int len){
	int i = 0;
	int num = 0;
	printf("init numbers,please input five numbers:\n");
	for (i = 0; i < len; ++i){
		scanf("%d", &num);
		arr[i] = num;
	}
}
void empty(int arr[],int len){
	int i = 0;
	printf("empty:\n");
	for (i = 0; i < len; ++i){
		arr[i] = 0;
	}
}
void reverse(int arr[],int len){
	int i = 0;
	int arr2[5];
	printf("reverse:\n");
	for (i = 0; i < len; ++i){
		arr2[i] = arr[i];
	}
	for (i = 0; i < len; ++i){
		arr[i] = arr2[len - 1 - i];
	}
}
int main(){
	int arr[5] = {0};
	int len = sizeof(arr) / sizeof(arr[0]);
	init(arr,len);
	reverse(arr, len);
	for (int i = 0; i < len; ++i){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	empty(arr,len);
	for (int i = 0; i < len; ++i){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
