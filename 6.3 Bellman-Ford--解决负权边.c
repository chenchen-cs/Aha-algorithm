#define  _CRT_SECURE_NO_WARNINGS  
//	时间：2021.11.14  22点08分
//	算法：Bellman-Ford
//	目的：解决负权边得问题
#include<stdio.h>
int main()
{
	int dis[10], bak[10], i, k, n, m, u[10], v[10], w[10], check, flag;
	int inf = 99999999;//用inf存储一个我们认为得正无穷值
	//读入n和m，n表示顶点个数，m表示边的个数
	scanf("%d %d", &n, &m);

	//读入边
	for (i = 1; i <= m; i++)
		scanf("%d %d %d", &u[i], &v[i], &w[i]);

	//初始化dis数组，这里是1号顶点到其余各个顶点得初始路程
	for (i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;

	//Bellman-Ford算法核心语句
	for (k = 1; k <= n - 1; k++)
	{
		//将dis数组备份到bak数组中
		for (i = 1; i <= n; i++) bak[i] = dis[i];
		//进行一轮松弛
		for (i = 1; i <= m; i++)
			if (dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
		//松弛完毕后检测dis是否有更新
		check = 0;
		for (i = 1; i <= n; i++) if (bak[i] != dis[i]) { check = 1; break; }
		if (check == 0) break;//如果dis数组没有更新，提前退出循环结束算法
	}
	//检测负权回路
	flag = 0;
	for (i = 1; i <= m; i++)
		if (dis[v[i]] > dis[u[i]] + w[i]) flag = 1;

	if (flag == 1) printf("此图含有负权回路");
	else
	{
		//输出最终的结果
		for (i = 1; i <= n; i++)
			printf("%d ", dis[i]);
	}
	getchar(); getchar();
	return 0;
}