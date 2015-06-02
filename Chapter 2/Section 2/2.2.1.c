#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//输入若干数字n(0 <= n <= 100000000)，每个数字一行。读到文件尾。
//
//
//Output
//输出f[n]的前4个数字（若不足4个数字，就全部输出）。
//菲波纳锲数列通式： 1 / 根号5 (((1 + 根号5) / 2)^n - ((1 - 根号5) / 2)^n)
//当数值过大时，采用取对方式，再利用科学计数法进行计算

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    int ret;
    double deal;
    double five;
    double cut;

    five = log10((sqrt(5) + 1) / 2);
    cut  = 0.5 * log10(5);

    while(scanf("%d", &n) != EOF)
    {
        if(n <= 20)
        {
            ret = fibonacci(n);
        }
        else
        {
            deal = n * five - cut;
            deal = deal - (int)deal;
            ret = pow(10.0, deal) * 1000;
        }
        printf("%d\n", ret);
    }
    return 0;
}