#include<stdio.h>
int search(int arr[3][3], int key, int ROW, int COL)
{
	int row = 0;//���Ͻ��±�
	int col = COL - 1;
	//�ӵ�һ�����һ�п�ʼ����
	while ((row < ROW) && (col >= 0))
		//�������Ͼ������ԣ���kÿ�������Ͻǵ����Ƚϣ������±ƽ���������ƽ���
		//ֱ�����ҵ����½ǵ��������������ȣ�ֱ�ӷ���0��˵��û�ҵ�
	{
		if (key > arr[row][col])
		{
			row++;
		}
		else if (key == arr[row][col])
		{
			return 1;
		}
		else
		{
			col--;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 20;
	int ret = 0;
	ret = search(arr, key, 3, 3);//��װһ�����������ú����ķ���ֵ���ж��Ƿ��ҵ�
	if (1 == ret)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}
	system("pause");
	return 0;
}