#include<stdio.h>
#include<stdlib.h>

//Input
//输入数据包含多个测试实例,每个测试实例占一行,由一个整数N组成，(0<n<=50)。
//
//Output
//对于每个测试实例，请输出全部的满足要求的涂法，每个实例的输出占一行。

//等于上一次首尾不同色的个数(要加只一种) + 上上次可造成的首尾同色个数 × 2
//即 f(n) = 2f(n - 2) + f(n - 1)

long long num[51];
void create()
{
    int i;
    num[1] = 3;
    num[2] = 6;
    num[3] = 6;

    for(i = 4; i < 51; i++)
    {
        num[i] = 2 * num[i - 2] + num[i - 1];
    }
}

int main()
{
    int n;

    create();
    while(scanf("%d", &n) != EOF)
    {
        printf("%I64d\n", num[n]);
    }
    return 0;
}