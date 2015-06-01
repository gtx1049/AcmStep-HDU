#include<stdio.h>
#include<math.h>
#include<memory.h>
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