#define  _CRT_SECURE_NO_WARNINGS  
/*	算法：深度优先搜索(DFS)
	时间：2021.10.28
	目的：找出小哼解救小哈的最短路径
*/
#include<stdio.h>
int n, m, p, q, min = 99999999;
int a[51][51], book[51][51];
void dfs(int x, int y, int step)
{
	int next[4][2] = {
		{0,1},//向右走
		{1,0},//向下走
		{0,-1},//向左走
		{-1,0}//向上走
	};
	int tx, ty, k;
	//判断是否到达小哈的位置
	if (x == p && y == q)
	{
		//更新最小值
		if (step < min)
			min = step;
		return;//请注意这里的返回很重要
	}

	//枚举4种走法
	for (k = 0; k <= 3; k++)
	{
		//计算下一个点坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if (tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//判断该点是否为障碍物或者已经在路径里
		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//标记这个点已经被走过
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;//尝试结束，取消这个点的标记
		}
	}
	return;

}
int main()
{
	int i, j, startx, starty;
	//读入n和m，n为行m为列
	scanf("%d %d", &n, &m);
	//读入迷宫
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	//读入起点和终点坐标
	scanf("%d %d %d %d", &startx, &starty, &p, &q);

	//从起点开始搜索
	book[startx][startx] = 1;//标记起点已经在路径中，防止后面重复走
	//第一个参数是起点的x坐标，第二个参数是起点的y坐标，第三个参数是初始步数为0
	dfs(startx, starty, 0);

	//输出最短步数
	printf("%d", min);
	getchar(); getchar();
}