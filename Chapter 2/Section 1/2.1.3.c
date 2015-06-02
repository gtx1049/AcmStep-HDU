#include<stdio.h>

//Input
//输入数据的第一行为一个正整数T, 表示测试数据的组数. 然后是T组测试数据. 每组测试数据包含两组正整数，用空格隔开。每组包含两个正整数，表示转n圈需要的天数(26501/6335，表示转26501圈要6335天)，用\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'隔开。
//
//
//Output
//对于每组测试数据, 输出它们的相遇周期，如果相遇周期是整数则用整数表示，否则用最简分数表示。
//这是一道很肤浅的题，行星的相遇周期并不是他们周期的最小公倍数，而是由公式1/T1 - 1/T2 = 1/P得到的
//求分数的最小公倍数，分母先通分, 分子为通分后两个分子的最小公倍数
//无语了，HDOJ不可使用lld输出
//做了一些简化，约分掉不用的数

#define LONG __int64
typedef struct Planet
{
    LONG circle;
    LONG days;
}planet;


LONG gcdAB(LONG a, LONG b)
{
    long long temp;
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
    planet a;
    planet b;
    planet result;

    LONG divide;
    int n;
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%I64d/%I64d %I64d/%I64d", &a.circle, &a.days, &b.circle, &b.days);

        result.circle = a.circle * b.circle;
        result.days = gcdAB(a.circle * b.days, b.circle * a.days);

        divide = gcdAB(result.circle, result.days);

        if(result.days == divide)
        {
            printf("%I64d\n", result.circle / divide);
        }
        else
        {
            printf("%I64d/%I64d\n", result.circle / divide, result.days / divide);
        }
    }
    return 0;
}