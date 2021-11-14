#define  _CRT_SECURE_NO_WARNINGS  
/*	算法：枚举
	时间：2021.10.27
	目的：理解枚举的思想
*/
#include<stdio.h>
int fun(int x)
{
	int num = 0;//用来计数的变量，一定要初始化
	int f[10] = { 6,2,5,5,4,5,6,3,7,6 };//用一个数组来记录0-9每个数字需要用多少根火柴棍
	while (x / 10 != 0)
	{
		//获得x的末尾数字并将此数所需要用到的火柴棍棍数累加到num中
		num += f[x % 10];
		x = x / 10;//去掉x的末尾数字，例如x的值为123现在x的值为12
	}
	//最后加上此时x所需用到的火柴棍的根数（此时x一定是一位数）
	num += f[x];
	return num;//返回需要火柴棍的总棍数
}
int main()
{
	int a, b, c, m, i, sum = 0;//sum是用来计数的，因此一定要初始化为0
	scanf("%d", &m);
	//开始枚举a和b
	for (a = 0; a <= 1111; a++)
	{
		for (b = 0; b <= 1111; b++)
		{
			c = a + b;//计算出c
			//fun是我们自己写的子函数，用来计算一个数所需要用火柴棍的总数
			//当a使用的火柴棍根数+b使用的火柴棍的根数+c使用的火柴棍的根数之和恰好等于
			//m-4时，则成功的找出了一组解
			if (fun(a) + fun(b) + fun(c) == m - 4)
			{
				printf("%d+%d=%d\n", a, b, c);
				sum++;
			}
		}
	}
	printf("一共可以拼出%d个不同的等式", sum);
	getchar(); getchar();
	return 0;
}