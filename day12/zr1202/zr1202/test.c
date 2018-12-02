#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void re_string(char* arr, int len){
	int left = 0;
	int right = len - 1;
	while (left <= right){
		char mid;
		mid = arr[right];
		arr[right] = arr[left];
		arr[left] = mid;
		right--;
		left++;
	}
}
//i ma a tneduts
void re_word(char* arr, int len){
	int right = 0;
	int left = 0;
	for (right = 0; right <= len; right++){
		if (arr[right] == ' ' || arr[right] == '\0'){
			int r = right - 1;
			int l = left;
			while (l <= r){
				char mid;
				mid = arr[r];
				arr[r] = arr[l];
				arr[l] = mid;
				r--;
				l++;
			}
			left = right + 1;
		}
	}
}
int main(){
	char arr[50] = "student a am i";
	int len = strlen(arr);
	re_string(arr, len);
	re_word(arr, len);
	printf("%s\n", arr);
	system("pause");
	return 0;
}