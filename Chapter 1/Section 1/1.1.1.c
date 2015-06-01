#include<stdio.h>

//HDU1089

//Input
//The input will consist of a series of pairs of integers a and b, separated by a space, one pair of integers per line. 
//
//
//Output
//For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input. 

int main()
{
	int a;
	int b;
	while(scanf("%d %d",&a, &b) != EOF)
	{
		printf("%d\n", a + b);
	}
	return 0;
}
