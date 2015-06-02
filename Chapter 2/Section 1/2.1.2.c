#include<stdio.h>
#include<math.h>

//Input
//There are a lot of cases. In each case, there is an integer N representing the number of integers to find. Each integer won’t exceed 32-bit signed integer, and each of them won’t be less than 2.
//
//
//Output
//
//For each case, print the number of prime numbers you have found out.
//求素数的暴力算法

int isPrime(int num)
{
    int i;
    int k;

    k = sqrt(num);
    if(num == 1)
    {
        return 0;
    }
    if(num == 2)
    {
        return 1;
    }
    if(num % 2 == 0 && num != 2)
    {
        return 0;
    }
    else
    {
        for(i = 3; i <= k; i += 2)
        {
            if(num % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    int n;
    int i;
    int num;
    int count;

    while(scanf("%d", &n) != EOF)
    {
        count = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if(isPrime(num) == 1)
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}