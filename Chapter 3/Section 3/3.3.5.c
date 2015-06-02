#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//多组数据。对于每组数据：
//第一行为正整数n，表示菜的数量。n<=1000。
//第二行包括n个正整数，表示每种菜的价格。价格不超过50。
//第三行包括一个正整数m，表示卡上的余额。m<=1000。
//
//n=0表示数据结束。
//
//
//Output
//对于每组输入,输出一行,包含一个整数，表示卡上可能的最小余额。

//此题重在分析，就是最贵的要留在最后买，也就是剩5块钱的时候买
//那就是求剩5块钱可以买到最多价值的东西，再加上最贵物品。

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