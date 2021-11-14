#define  _CRT_SECURE_NO_WARNINGS  
//	算法：BFS
//	时间：2021.10.29

#include<stdio.h>
struct node
{
	int x;//横坐标
	int y;//纵坐标
};
int main()
{
	struct node que[2501];
	int head, tail;
	int a[51][51];
	int book[51][51] = { 0 };
	int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;
	//定义一个方向数组
	int next[4][2] = {
		{0,1},//向右走
		{1,0},//向下走
		{0,-1},//向左走
		{-1,0}//向上走
	};
	//读入n行m列以及小哼降落的坐标
	scanf("%d %d %d %d", &n, &m, &startx, &starty);

	//读入地图
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	//队列初始化
	head = 1;
	tail = 1;
	//往队列插入降落的起始坐标
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;

	//当队列不为空的时候循环
	while (head < tail)
	{
		//枚举4个方向
		for (k = 0; k <= 3; k++)
		{
			//计算下一步的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//判断是否越界
			if (tx<1 || tx>n || ty<1 || ty>m)
				continue;
			//判断是否是陆地或者曾经是否走过
			if (a[tx][ty] > 0 && book[tx][ty] == 0)
			{
				sum++;
				//每个点只入队一次，所以需要标记这个点已经走过
				book[tx][ty] = 1;
				//将新扩展的点加入队列
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;//注意这地方千万不能忘记
		//当一个点扩展结束后，head++才能继续往下扩展
	}
	//最后输出岛屿的大小
	printf("%d\n", sum);
	getchar(); getchar();
}