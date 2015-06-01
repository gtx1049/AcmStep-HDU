#include<stdio.h>

//HDU1720

//Input may contain multiple test cases. Each case contains A and B in one line.
//A, B are hexadecimal number.
//Input terminates by EOF.
int main()
{
	int a;
	int b;

	while(scanf("%x %x", &a, &b) != EOF)
	{
		printf("%d\n", a + b);
	}
}