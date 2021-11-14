#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*	算法：队列
	时间：2021.10.18
	目的：数组实现队列操作
*/
struct queue
{
	int data[100];//队列的主体，用来储存内容
	int head;//队首
	int tail;//队尾
};
int main()
{
	struct queue q;
	int i;
	//初始化队列
	q.head = 1;//队列头从0或者1开始都可以
	q.tail = 1;
	for (int i = 1; i <= 9; i++)
	{
		//依次向队列里插9个数
		scanf("%d", &q.data[q.tail]);
		q.tail++;
	}
	while (q.head < q.tail)//当队列不为空的时候执行循环
	{
		//打印队首并将队首出队
		printf("%d ", q.data[q.head]);
		q.head++;

		//先将新队首的数添加到队尾
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		//再将队首出队
		q.head++;
	}
	system("pause");
	return 0;
}