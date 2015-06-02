#include<stdio.h>
#include<stdlib.h>

//Input
//首先给出一个正整数C，表示有C组测试数据
//接下来的C行，每行包含一个整数n (n<=20)，表示要走n步。
//
//
//Output
//请编程输出走n步的不同方案总数；
//每组的输出占一行。

//可以从上一次的结果拓展两个方向 × 2，再加上上上次做的拓展
//所以 f(n) = 2f(n - 1) + f(n - 2)

int num[21];
void create()
{
    int i;

    num[1] = 3;
    num[2] = 7;

    for(i = 3; i < 21; i++)
    {
        num[i] = num[i - 1] * 2 + num[i - 2];
    }
}

int main()
{
    int n;
    int i;

    create();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &i);
        printf("%d\n", num[i]);
    }
    return 0;
}