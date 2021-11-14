#define  _CRT_SECURE_NO_WARNINGS  
//	算法：DFS
//	时间：2021.10.29
#include<stdio.h>
int a[51][51];
int book[51][51], n, m, sum;
void dfs(int x, int y)
{
	//定义一个方向数组
	int next[4][2] = {
		{0,1},//向右走
		{1,0},//向下走
		{0,-1},//向左走
		{-1,0}//向上走
	};
	int k, tx, ty;

	//枚举4个方向
	for (k = 0; k <= 3; k++)
	{
		//计算下一步坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if (tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//判断是否是陆地
		if (a[tx][ty] > 0 && book[tx][ty] == 0)
		{
			sum++;
			book[tx][ty] = 1;//标记这个点已走过
			dfs(tx, ty);//开始尝试下一个点
		}
	}
	return;
}
int main()
{
	int i, j, startx, starty;
	scanf("%d %d %d %d", &n, &m, &startx, &starty);
	//读入地图
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	book[startx][starty] = 1;
	sum = 1;
	//从降落的位置开始
	dfs(startx, starty);
	//最后输出岛屿的大小
	printf("%d\n", sum);
	getchar(); getchar();
	return 0;
}