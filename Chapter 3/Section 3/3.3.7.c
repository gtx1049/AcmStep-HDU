#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
double dp[10001];
double probability[10001];
int money[10001];
int main()
{
    int n;
    int m;
    int i;
    int j;

    while(scanf("%d %d", &n, &m) && (m || n))
    {
        for(i = 1; i <= m; i++)
        {
            scanf("%d %lf", &money[i], &probability[i]);
        }

        for(i = 0; i <= n; i++)
        {
            dp[i] = 1.0;
        }
        for(i = 1; i <= m; i++)
        {
            for(j = n; j >= money[i]; j--)
            {
                if((1 - probability[i]) * dp[j - money[i]] < dp[j])
                {
                    dp[j] = (1 - probability[i]) * dp[j - money[i]];
                }
            }
        }
        printf("%.1lf%%\n", (1.0 - dp[n]) * 100.0);
    }
    return 0;
}