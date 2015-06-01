#include<stdio.h>
#include<stdlib.h>

//Input
//输入数据包含多个测试实例，每个测试实例的第一行只有一个整数n(n<=100)，表示你喜欢看的节目的总数，然后是n行数据，每行包括两个数据Ti_s,Ti_e (1<=i<=n)，分别表示第i个节目的开始和结束时间，为了简化问题，每个时间都用一个正整数表示。n=0表示输入结束，不做处理。
 
//Output
//对于每个测试实例，输出能完整看到的电视节目的个数，每个测试实例的输出占一行。

typedef struct PROGRAM
{
	int begintime;
	int endtime;
}Program;

int compare(const void* program1, const void* program2)
{
	return ((Program*)program1)->endtime - ((Program*)program2)->endtime;
}

int main()
{
	int n;
	int i;
	int count;
	Program pro[100];
	int end;

	while(scanf("%d", &n) && n != 0)
	{
		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &pro[i].begintime, &pro[i].endtime);
		}
		count = 0;
		qsort(pro, n, sizeof(Program), compare);

		end = pro[0].begintime;
		for(i=0;i<n;i++)
		{  
			if(pro[i].begintime>=end)
			{  
				count++;  
				end=pro[i].endtime;  
			}  
		}  
		printf("%d\n", count);
	}
}