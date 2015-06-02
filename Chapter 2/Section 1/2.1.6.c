#include<stdio.h>
#include<math.h>
#include<memory.h>

//Input
//第一行是测试数据的组数CN（Case number，1<CN<10000），接着有CN行正整数N（1<n<32768），表示会员人数。
//
//
//Output
//对于每一个N，输出一行新朋友的人数，这样共有CN行输出。
//欧拉函数(n)表示小于n的数中与n互素的数的个数
//欧拉函数(x) = x(1-1/p1)(1-1/p2)(1-1/p3)…(1-1/pn) p1到pn为x的素因数
//需要筛选法的重要公式(x) = (x = p1 ^ q1 * p2 ^ q2 … pn ^ qn) = (p1 - 1)p1^(q1 - 1)*...
//即遇到能整除的数时，先乘以其因数减一，再逐渐乘可以乘除的次数的因数，原数会逐渐减小。

int euler(int x)
{
    int ret = 1;
    int i = 2;

    if(x == 1)
    {
        return 0;
    }

    for(i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            x /= i;
            ret *= i - 1;

            while(x % i == 0)
            {
                x /= i;
                ret *= i;
            }
        }
    }
    if(x > 1)
    {
        ret *= x - 1;
    }

    return ret;
}

int main()
{
    int n;
    int i = 0;
    int number;
    int count;

    scanf("%d", &n);
    for(; i < n; i++)
    {
        scanf("%d", &number);

        count = euler(number);

        printf("%d\n", count);
    }

    return 0;
}