#include<stdio.h>
#include<math.h>
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