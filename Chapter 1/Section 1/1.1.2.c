#include<stdio.h>

//Input
//Input contains an integer N in the first line, and then N lines follow. Each line consists of a pair of integers a and b, separated by a space, one pair of integers per line.
//
//
//Output
//For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input. 

int main()
{
	int n;
	int a;
	int b;
	int i = 0;
	scanf("%d", &n);
	for(; i < n; i++)
	{
		scanf("%d %d",&a, &b);
		printf("%d\n", a + b);
	}
	return 0;
};