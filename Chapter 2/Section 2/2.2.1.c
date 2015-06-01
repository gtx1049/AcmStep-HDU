#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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