#include<stdio.h>
#include<stdlib.h>

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