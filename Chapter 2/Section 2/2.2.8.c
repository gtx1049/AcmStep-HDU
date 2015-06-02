#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>

//Input
//Each line will contain one integer N(0 <= N<=10^9). Process to end of file.
//
//
//Output
//For each case, output N! mod 2009

//如果阶乘中出现2009的因数，则%2009之后皆为0
//2009 = 7 × 7 × 41
//公式，(a * b * c * d) % p = (((((a * b) % p) * c) %p) * d) % p
//证明3个数即可 设 m = a * b, n = c。(a * b * c) % p = (m * n) % p
//将 m * n 看成 n 个 m 相加得 ((m % p) * n) % p
//替换 (((a * b) % p) * c) % p

int getret(int n)
{
    int i = 1;
    int ret = 1;

    if(n == 0)
    {
        return 1;
    }
    if(n > 41)
    {
        return 0;
    }
    for(i = 1; i <= n; i++)
    {
        ret = i * ret % 2009;
    }
    return ret;
}

int main()
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        printf("%d\n", getret(n));
    }
    return 0;
}