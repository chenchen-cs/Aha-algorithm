#define  _CRT_SECURE_NO_WARNINGS  
//	时间：2021.10.30
//  目的：用深度优先搜索遍历图（无向）
#include<stdio.h>
int book[101], sum, n, e[101][101];
//这里的图是用一个二维数组e来存储，二维数组中第i行第j列表示的就是顶点i到'
//顶点j是否有边，1表示有边，无穷表示没有边。这里我们将自己到自己（即i等于j)
//设为0.我们将这种存储图的方法称为图的邻接矩阵存储法。
void dfs(int cur)//cur是当前所在的顶点编号
{
	int i;
	printf("%d ", cur);
	sum++;//每访问一个顶点，sum就加1
	if (sum == n)   return;//所有的顶点都已经访问过则直接退出
	for (i = 1; i <= n; i++)//从1号顶点到n号顶点依次尝试，看哪些顶点与当前顶点cur有边相连
	{
		//判断当前顶点cur到顶点i是否有边，并判断顶点i是否已访问过
		if (e[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			dfs(i);
		}
	}
	return;
}
int main()
{
	int i, j, m, a, b;
	scanf("%d %d", &n, &m);
	//初始化二维矩阵
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = 99999999;//我们这里假设99999999为正无穷
	
	//读入顶点之间的边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;//这里是无向图，所以需要将e[b][a]也赋为1
	}

	//从1号城市出发
	book[1] = 1;//标记1号顶点已访问
	dfs(1);//从1号顶点开始遍历
	getchar(); getchar();
}