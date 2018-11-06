#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	printf("please input a word:");
	while (1){
		char word;
	    printf("");
	    scanf("%c", &word);
		if (word >= 97 && word <= 122){
			word = word - 32;
			printf("%c\n", word);
		}
		else if (word >= 65 && word <= 90){
			word = word + 32;
			printf("%c\n", word);
		}
		else{
		}
	}
	system("pause");
	return 0;
}