#include<stdio.h>

//Input
//输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数.
//
//
//Output
//对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。
//求最小公约数的算法

int gcd(int a, int b)
{
    int temp;
    if(a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int a;
    int b;
    int c;

    while(scanf("%d %d", &a, &b) != EOF)
    {
        c = gcd(a, b);
        printf("%d\n", a * b / c);
    }
    return 0;
}