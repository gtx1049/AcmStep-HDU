#include<stdio.h>

//HDU1091

//Input
//Input contains multiple test cases. Each test case contains a pair of integers a and b, one pair of integers per line. A test case containing 0 0 terminates the input and this test case is not to be processed.
//
//
//Output
//For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input. 

int main()
{
	int a;
	int b;
	while(scanf("%d %d",&a, &b) && !(a ==0 && b == 0))
	{
		printf("%d\n", a + b);
	}
	return 0;
}
