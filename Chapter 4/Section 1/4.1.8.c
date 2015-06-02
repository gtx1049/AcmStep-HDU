#include<stdio.h>
#include<stdlib.h>

//Input
//第1行是整数T,表示有T组数据，下面有T行
//每行一个整数n (1 ≤ n ≤ 30)
//
//
//Output
//猜n次可以猜到的最大数

//此题莫名其妙，不管了

int main()
{
	int n;
	int i;
	int m;
	int j;
	int q;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &m);
		q = 1;
		for(j = 0; j < m; j++)
		{
			q *= 2; 
		}
		printf("%d\n", q -1);
	}
	return 0;
}