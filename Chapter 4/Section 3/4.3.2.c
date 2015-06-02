#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//n (0 < n < 20).
//
//Output
//The output format is shown as sample below. Each row
//represents a series of circle numbers in the ring
//beginning from 1 clockwisely and anticlockwisely.
//The order of numbers must satisfy the above requirements.
// Print solutions in lexicographical order.
//You are to write a program that completes above process.
//Print a blank line after each case.

//深度搜索，到达状态输出即可，中间状态需判断以达到剪枝目的

int N;
int order[21];
int mark[21];
int prime[11] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int test(int x)
{
    int i;
    for(i = 0; i < 11; i++)
    {
        if(x == prime[i])
        {
            return 1;
        }
    }
    return 0;
}

void dfs(int n)
{
    int i;

    if(n == N && test(order[n] + order[1]))
    {
        for(i = 1; i < N; i++)
        {
            printf("%d ", order[i]);
        }
        printf("%d\n", order[i]);
    }
    else
    {
        for(i = 1; i <= N; i++)
        {
            if(!mark[i] && test(i + order[n]))
            {
                mark[i] = 1;
                order[n + 1] = i;
                dfs(n + 1);
                mark[i] = 0;
            }
        }
    }
}

int main()
{
    int i = 1;

    while(scanf("%d", &N) != EOF)
    {
        printf("Case %d:\n", i);
        order[1] = 1;
        memset(mark, 0, sizeof(0));
        mark[1] = 1;
        dfs(1);
        printf("\n");
        i++;
    }
    return 0;
}