#include<stdio.h>

//HDU2095

//The input file will consist of several cases. 
//Each case will be presented by an integer n (1<=n<1000000, and n is odd) at first. Following that, n positive integers will be given in a line, all integers will smaller than 2^31. These numbers indicate the card numbers of the presents.n = 0 ends the input.

//使用异或操作来解决奇数出现次数问题
//异或操作满足交换律
//偶数个相同数异或，得到的结果是0
//0与一个数异或后还是这个数
int main()
{
	int n;
	int i;
	int number;
	int unique;

	while(scanf("%d", &n) && n != 0)
	{
		unique = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &number);
			unique ^= number;
		}
		printf("%d\n", unique);
	}

	return 0;
}