#define  _CRT_SECURE_NO_WARNINGS  
/*	算法：深度优先搜索（DFS)
	时间：2021.10.29
	目的：优化3.2炸弹人的代码
*/
#include<stdio.h>
char a[20][21];
int book[20][20], max, mx, my, n, m;
int getnum(int i, int j)
{
	int sum, x, y;
	sum = 0;//sum用来计数（可以消灭的敌人数），所以初始化为0
	//将坐标i,j复制到两个新变量x,y中，以便以后向上下左右四个方向统计可以消灭的敌人数

	//向上统计可以消灭的敌人数
	x = i; y = j;
	while (a[x][y] != '#')//判断的点不是墙，如果不是墙就继续
	{
		//如果当前的点是敌人，则进行计数
		if (a[x][y] == 'G')
			sum++;
		//x--的作用是继续向上统计
		x--;
	}

	//向下统计可以消灭的敌人数
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		//x++的作用是继续向下统计
		x++;
	}

	//向左统计可以消灭的敌人数
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		//y--的作用是继续向左统计
		y--;
	}

	//向右统计可以消灭的敌人数
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		//y++的作用是继续向上统计
		y++;
	}
	return sum;
}
void dfs(int x, int y)
{
	//定义一个用于表示走的方向的数组
	int next[4][2] = {
		{0,1},//向右走
		{1,0},//向下走
		{0,-1},//向左走
		{-1,0}//向上走
	};
	int k, sum, tx, ty;
	//计算这个点当前可以消灭的敌人总数
	sum = getnum(x, y);

	//更新max的值
	if (sum > max)
	{
		//如果当前的点统计出的所能消灭的敌人数大于max,
		//则更新max，并用mx和my记录当前点的坐标
		max = sum;
		mx = x;
		my = y;
	}
	//枚举四个方向
	for (k = 0; k <= 3; k++)
	{
		//下个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if (tx<0 || tx>n - 1 || ty<0 || ty>m - 1)
			continue;
		//判断是否围墙或者已经走过
		if (a[tx][ty] == '.' && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//标记这个点已走过
			dfs(tx, ty);//开始尝试下一个点
			//book[tx][ty]=0
//此处不用收回，与路径或者步数有关的深搜，需要收回标记，无关则不需要回收
		}
	}
	return;
}
int main()
{
	int i, startx, starty;
	//读入n和m，n表示有多少行字符，m表示每行有多少字符
	scanf("%d %d %d %d", &n, &m, &startx, &starty);

	//读入n行字符
	for (i = 0; i <= n - 1; i++)
		scanf("%s", a[i]);
	//从小人站的位置开始尝试
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;
	dfs(startx, starty);

	printf("将炸弹放置在（%d %d),最多可以下消灭%d个敌人\n", mx, my, max);
	getchar(); getchar();
	return 0;
}