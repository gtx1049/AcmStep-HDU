#include<stdio.h>
#include<stdlib.h>

//Input
//输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
//n=0表示输入数据的结束，不做处理。
//
//
//Output
//对于每个测试实例，输出在第n年的时候母牛的数量。
//每个输出占一行。

//可以得出递推公式 f(n) = f(n - 1) + f(n - 3)

long long num[55];
void create()
{
    int i;

    num[0] = 1;
    num[1] = 1;
    num[2] = 2;

    for(i = 3; i < 56; i++)
    {
        num[i] = num[i - 1] + num[i - 3];
    }
}

int main()
{
    int n;
    create();

    while(scanf("%d", &n) != EOF && n != 0)
    {
        printf("%I64d\n", num[n]);
    }

    return 0;
}