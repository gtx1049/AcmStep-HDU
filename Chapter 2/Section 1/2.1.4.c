#include<stdio.h>

//Input
//每行有两个数p和q.
//
//
//Output
//输出最少要将蛋糕切成多少块.
//观察切割圆形蛋糕，3份需3刀，2份需2刀（上下一刀）
//即刀数（割线）代表块数
//将所有割线相加，减去重复的割线即最大公倍数
//可将蛋糕当成方形竖直切，则(q - 1) + (p - 1) - (gcd(q, p) - 1) + 1即可

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
    int p;
    int q;

    while(scanf("%d %d", &p, &q) != EOF)
    {
        printf("%d\n", p + q - gcd(p, q));
    }
    return 0;
}