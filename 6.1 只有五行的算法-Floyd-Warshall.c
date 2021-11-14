#define  _CRT_SECURE_NO_WARNINGS  
//	算法：Floyd-Warshall
//	时间：2021.11.3 22点41分
//  目的：求解多源路最短路径问题（任意两个点之间的最短路径）
#include<stdio.h>
int main()
{
	int e[10][10], k, i, j, n, m, t1, t2, t3;
	int inf = 99999999;//用inf(infinity的缩写)存储一个我们认为的正无穷值
	//读入n和m,n表示顶点个数，m表示边的条数
	scanf("%d %d", &n, &m);

	//初始化
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;

	//读入边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3;
	}

	//Floyd-Warshall算法核心语句
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
	//输出最终的结果
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%10d", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}