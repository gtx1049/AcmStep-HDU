#include<stdio.h>
#include<stdlib.h>

//Input
//输入有若干组数据，每组数据的第一行有两个正整数n,m(0<=n<=10000,0<=m<=10000)
//后面的m行，每行都有两个数据ai(整型),bi(实型)分别表示第i个学校的申请费用和可能拿到offer的概率。
//输入的最后有两个0。
//
//
//Output
//每组数据都对应一个输出，表示Speakless可能得到至少一份offer的最大概率。用百分数表示，精确到小数点后一位。

//概率计算

double dp[10001];
double probability[10001];
int money[10001];
int main()
{
    int n;
    int m;
    int i;
    int j;

    while(scanf("%d %d", &n, &m))
    {
        if(n == 0 && m == 0)
        {
            break;
        }
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