#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int t, n;
int x[12];
int result[12];
int flag;

void dfs(int position, int sum, int count)
{
    int i;
    int last;

    if(sum > t)
    {
        return;
    }
    if(sum == t)
    {
        flag = 1;
        for(i = 0; i < count - 1; i++)
        {
            printf("%d+", result[i]);
        }
        printf("%d\n", result[i]);
    }

    last = -1;
    for(i = position; i < n; i++)
    {
        if(last != x[i])
        {
            result[count] = x[i];
            last = x[i];
            dfs(i + 1, sum + x[i], count + 1);
        }
    }
}

int main()
{
    int i;
    while(scanf("%d %d", &t, &n))
    {
        if(t == 0 && n == 0)
        {
            break;
        }
        flag = 0;

        for(i = 0; i < n; i++)
        {
            scanf("%d", &x[i]);
        }

        printf("Sums of %d:\n", t);

        dfs(0, 0, 0);

        if(!flag)
        {
            printf("NONE\n");
        }
    }
    return 0;
}