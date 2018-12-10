#include<stdio.h>
int search(int arr[3][3], int key, int ROW, int COL)
{
	int row = 0;//右上角下标
	int col = COL - 1;
	//从第一行最后一列开始查找
	while ((row < ROW) && (col >= 0))
		//利用杨氏矩阵特性，让k每次与右上角的数比较，行向下逼近，列向左逼近，
		//直到查找到左下角的数，如果还不相等，直接返回0；说明没找到
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
	ret = search(arr, key, 3, 3);//封装一个函数，利用函数的返回值来判定是否找到
	if (1 == ret)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	system("pause");
	return 0;
}