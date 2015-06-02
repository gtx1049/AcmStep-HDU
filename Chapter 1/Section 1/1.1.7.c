#include<stdio.h>

//Input
//The input will consist of a series of pairs of integers a and b, separated by a space, one pair of integers per line. 
//
//
//Output
//For each pair of input integers a and b you should output the sum of a and b, and followed by a blank line. 

int main()
{
	int a;
	int b;
	while(scanf("%d %d",&a, &b) != EOF)
	{
		printf("%d\n\n", a + b);
	}
	return 0;
}