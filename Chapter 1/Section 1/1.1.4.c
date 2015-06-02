#include<stdio.h>

//Input
//Input contains multiple test cases. Each test case contains a integer N, and then N integers follow in the same line. A test case starting with 0 terminates the input and this test case is not to be processed.
//
//
//Output
//For each group of input integers you should output their sum in one line, and with one line of output for each line in input. 

int main()
{
	int sum;
	int n;
	int temp;

	while(scanf("%d", &n) && n)
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