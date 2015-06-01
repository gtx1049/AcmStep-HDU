#include<stdio.h>

//HDU1094

//Input
//Input contains multiple test cases, and one case one line. Each case starts with an integer N, and then N integers follow in the same line. 
//
//
//Output
//For each test case you should output the sum of N integers in one line, and with one line of output for each line in input. 

int main()
{
	int sum;
	int n;
	int temp;
	
	while(scanf("%d", &n) != EOF)
	{
		sum  = 0;
		while(n)
		{
			scanf("%d", &temp);
			sum += temp;
			n--;
		}
		printf("%d\n", sum);
	}
}