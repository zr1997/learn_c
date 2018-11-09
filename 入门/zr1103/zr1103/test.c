#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(){
	char password[10] = { 0 };
	int i = 0;
	for (i = 0; i < 3; ++i){
		printf("please input your password:");
		scanf("%s", &password);
		if (strcmp(password, "12345") == 0){
			printf("succeed!\n");
			break;
		}
	}
	if (i == 3){
		printf("login failed\n");
	}
	//double arr[] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	//int to_find = 2;
	//int mid = 0;
	//int left = 0;
	//int right = (sizeof(arr) / sizeof(arr[0])) - 1;
	//while (left <= right){
	//	mid = (left + right) / 2;
	//	if (to_find > arr[mid]){
	//		left = mid + 1;
	//	}
	//	else if (to_find < arr[mid]){
	//		right = mid - 1;
	//	}
	//	else{
	//		break;
	//	}
	//}
	//if (left<=right){
	//	printf("%d\n", mid);
	//}
	//else{
	//	printf("-1\n");
	//}
	system("pause");
	return(0);
}