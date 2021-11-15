#define  _CRT_SECURE_NO_WARNINGS  
//	算法：并查集
//	时间：2021.11.15 19点30分
//  目的：找出一共多少个犯罪团伙，其实就是找出多少个“祖宗”
#include<stdio.h>
int f[1000] = { 0 }, n, m, k, sum = 0;
//这里初始化，非常的重要，数组里面存的是自己数组下标的编号就好了
void init()
{
	int i;
	for (i = 1; i <= n; i++)
		f[i] = i;
}
//这是找爹的递归函数，不停地去找爹，直到找到祖宗为止，其实就是去找犯罪团伙的最高领导人
//“擒贼先擒王”原则
int getf(int v)
{
	if (f[v] == v)
		return v;
	else
	{
		//这里是路径压缩，每次在函数返回的时候，顺带把路上遇到的人的“BOSS”
		//改为最后找到的祖宗编号，也就是犯罪团伙的最高领导人编号。这样可以提高
		//今后找到犯罪团伙的最高领导人（其实是数的祖先）的速度
		f[v] = getf(f[v]);
		return f[v];
	}
}
//这里是合并两集合的函数
void merge(int v, int u)
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)//判断两个结点是否在一个集合中，即是否为一个祖先
	{
		f[t2] = t1;
		//靠左原则，左边变成右边的BOSS，即把右边的集合，作为左边集合的子集合
		//经过路径压缩以后，将f[u]的根的值也赋值为v的祖先f[t1]
	}
}

int main()
{
	int i, x, y;
	scanf("%d %d", &n, &m);
	//初始化是必须的
	init();
	for (i = 1; i <= m; i++)
	{
		//开始合并犯罪团伙
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	//最后扫描有多少个独立的犯罪团伙
	for (i = 1; i <= n; i++)
	{
		if (f[i] == i)
			sum++;
	}
	printf("%d\n", sum);
	return 0;
}