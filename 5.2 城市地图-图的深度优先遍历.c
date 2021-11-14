#define  _CRT_SECURE_NO_WARNINGS  
//	时间：2021.11.1
//	算法：用深度优先搜索遍历图（有向）
//	目的：找出两个地点的最短路径
#include<stdio.h>
int min = 99999999, book[101], n, e[101][101];//我们这里假设99999999为正无穷

//cur是当前所在的城市编号，dis是当前已经走过的路程
void dfs(int cur, int dis)
{
	int j;
	//如果当前走过的路程已经大于之前找到的最短路，则没有必要再往下尝试了，立即返回
	if (dis > min) return;
	if (cur == n)//判断是否到达了目标城市
	{
		if (dis < min) min = dis;//更新最小值
		return;
	}
	for (j = 1; j <= n; j++)//从1号城市到n号城市依次尝试
	{
		//判断当前城市cur到城市j是否有路，并判断城市j是否在已走过的路径中
		if (e[cur][j] != 99999999 && book[j] == 0)
		{
			book[j] = 1;//标记城市j已经在路径中
			dfs(j, dis + e[cur][j]);//从城市j再出发，继续寻找目标城市
			book[j] = 0;//之前一步探索完毕之后，取消对城市j的标记
		}
	}
	return;
}
int main()
{
	int i, j, m, a, b, c;
	scanf("%d %d", &n, &m);
	//初始化二维矩阵
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else   e[i][j] = 99999999;

	//读入城市之间的道路
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		e[a][b] = c;
	}
	
	//从1号城市出发
	book[1] = 1;//标记1号城市已经在路径中
	dfs(1, 0);//1表示当前所在的城市编号，0表示当前已经走过的路程
	printf("%d", min);//打印1号城市到5号城市的最短路径

	return 0;
}