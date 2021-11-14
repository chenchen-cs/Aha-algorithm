#define  _CRT_SECURE_NO_WARNINGS  
//	时间：2021.10.30
//  目的：用广度优先搜索遍历图(无向）
#include<stdio.h>
int main()
{
	int i, j, n, m, a, b, cur, book[101] = { 0 }, e[101][101];
	int que[10001], head, tail;
	scanf("%d %d", &n, &m);
	//初始化二维矩阵
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = 99999999;//假设99999999为无穷大

	//读入顶点之间的边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;//因为这里是无向图
	}
	//队列初始化
	head = 1;
	tail = 1;

	//从1号顶点出发，将1号顶点加入队列
	que[tail] = 1;
	tail++;
	book[1] = 1;//标记1号顶点已访问

	//当队列不为空的时候循环
	while (head < tail)
	{
		cur = que[head];//当前正在访问的顶点编号
		for (i = 1; i <= n; i++)//从1-n依次尝试
		{
			//判断从顶点cur到顶点i是否有边，并判断顶点i是否已经访问过
			if (e[cur][i] == 1 && book[i] == 0)
			{
				//如果从顶点cur到顶点i有边，并且顶点i没有被访问过，则将顶点i入队
				que[tail] = i;
				tail++;
				book[i] = 1;//标记顶点i已访问
			}
			//如果tail大于n，则表明所有顶点都已经被访问过了
			if (tail > n)
				break;
		}
		head++;//注意这个地方，千万不要忘记当一个顶点扩展结束后，head++，然后才能继续向下扩展
	}
	for (i = 1; i < tail; i++)
		printf("%d ", que[i]);
	getchar(); getchar();
	return 0;
}