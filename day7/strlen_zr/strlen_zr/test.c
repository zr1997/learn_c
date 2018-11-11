#include<stdio.h>

int Strlen(char* string){
	int count = 0;
	if (*string != '\0'){
		++string;
		count = Strlen(string) + 1;
	}else{
		return count;
	}
}

int strlen(char* string){
	int count = 0;
	while (1){
		if (*string != '\0'){
			++string;
			++count;
		}
		else{
			break;
		}
	}
	return count;
}
int main(){
	char* str= "abcdefg";
	printf("%d\n", Strlen(str));
	printf("%d\n", strlen(str));
	system("pause");
	return 0;
}