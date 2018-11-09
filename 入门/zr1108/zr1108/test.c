#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(){
	char word = 0;
	printf("input a word:\n");
	while (1){
		scanf("%c", &word);
		if (word >= 65 && word <= 90){
			word += 32;
			printf("%c\n", word);
		}
		else if (word >= 97 && word <= 122){
			word -= 32;
			printf("%c\n", word);
		}
	}
	system("pause");
	return 0;
}