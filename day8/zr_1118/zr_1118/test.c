#include<stdio.h>
#include<stdlib.h>

int main(){   //0��ʾ��������,1��ʾ������
	int a = 0, b = 0, c = 0, d = 0;
	int FD;//��Ϊc��d�Ĺ��ʳ��ֶ���
	int i;
	for (i = 1; i <= 4; ++i){
		if (i == 1){//a˵�ٻ�
			a = 1; c = 1; FD = 1; d = 0;
		}
		if (i == 2){//b˵�ٻ�
			a = 0; c = 0; FD = 1; d = 0;
		}
		if (i == 3){//c˵�ٻ�
			a = 0; c = 1; FD = 0; d = 0;
		}
		if (i == 4){//d˵�ٻ�
			a = 0; c = 1; FD = 1; d = 0;
		}
		//ֻ��һ��Ϊ����,����Ϊ1ʱ���ֳ���
		//��cd�����Ƴ��Ķ���d�ǲ�������,FD==d��Ϊ���ų�d��d���ǵ����
		if (a + b + c + d + FD == 1 && FD == d){
			printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
		}
	}
	system("pause");
	return 0;
}