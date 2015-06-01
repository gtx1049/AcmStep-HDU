#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int main()
{
    int remain[1001];
    int dish[1001];
    int n;
    int i;
    int left;
    int j;
    int flag;
    int maxdish;

    while(scanf("%d", &n) != EOF && n)
    {
        maxdish = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &dish[i]);
            if(dish[i] > maxdish)
            {
                maxdish = dish[i];
                flag = i;
            }
        }
        scanf("%d", &left);

        if(left < 5)
        {
            printf("%d\n", left);
            continue;
        }

        memset(remain, 0, sizeof(remain));

        for(i = 1; i <= n; i++)
        {
            if(flag != i)
            {
                for(j = left - 5; j >= dish[i]; j--)
                {
                    if(remain[j] < remain[j - dish[i]] + dish[i])
                    {
                        remain[j] = remain[j - dish[i]] + dish[i];
                    }
                }
            }
        }

        printf("%d\n", left - remain[left - 5] - maxdish);
    }
    return 0;
}