//HDU1197

//Input
#include<stdio.h>

//There is no input for this problem.
//
//
//Output
//Your output is to be 2992 and all larger four-digit numbers that satisfy the requirements (in strictly increasing order), each on a separate line with no leading or trailing blanks, ending with a new-line character. There are to be no blank lines in the output. The first few lines of the output are shown below.
//进制转换问题，余数为位数，辗转相除
int main()
{
	int testnum = 1000;
	int sum10;
	int sum12;
	int sum16;
	int temp;

	for(;testnum < 10000; testnum++)
	{
		sum10 = 0;
		sum12 = 0;
		sum16 = 0;
		temp = testnum;
		while(temp != 0)
		{
			sum10 += temp % 10;
			temp /= 10; 
		}
		temp = testnum;
		while(temp != 0)
		{
			sum12 += temp % 12;
			temp /= 12;
		}
		temp = testnum;
		while(temp != 0)
		{
			sum16 += temp % 16;
			temp /= 16;
		}
		if(sum12 == sum10 && sum10 == sum16)
		{
			printf("%d\n", testnum);
		}
	}
}