#include<stdio.h>
#include<stdlib.h>
int re_num(int* arr,unsigned int size){
	if (arr == NULL || size == 0){
		return;
	}
	int i = 0;
	int *p_begin = arr;
	int *p_end = arr + size - 1;
	while (p_begin < p_end){
		while (p_begin < p_end && (*p_begin & 0x1) == 1){
			p_begin++;
		}
		while (p_begin < p_end && (*p_end & 0x1) == 0){
			p_end--;
		}
		if (p_begin < p_end){
			int tmp = *p_begin;
			*p_begin = *p_end;
			*p_end = tmp;
		}

	}
	for (i = 0; i < size; i++){
		printf("%d\t", arr[i]);
	}
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	re_num(arr,size);
	printf("\n");
	system("pause");
	return 0;
}