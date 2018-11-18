#include<stdio.h>
#include<stdlib.h>

int main(){   //0表示不是凶手,1表示是凶手
	int a = 0, b = 0, c = 0, d = 0;
	int FD;//因为c和d的供词出现对立
	int i;
	for (i = 1; i <= 4; ++i){
		if (i == 1){//a说假话
			a = 1; c = 1; FD = 1; d = 0;
		}
		if (i == 2){//b说假话
			a = 0; c = 0; FD = 1; d = 0;
		}
		if (i == 3){//c说假话
			a = 0; c = 1; FD = 0; d = 0;
		}
		if (i == 4){//d说假话
			a = 0; c = 1; FD = 1; d = 0;
		}
		//只有一人为凶手,当和为1时凶手出现
		//因cd供词推出的都是d是不是凶手,FD==d是为了排除d是d不是的情况
		if (a + b + c + d + FD == 1 && FD == d){
			printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
		}
	}
	system("pause");
	return 0;
}