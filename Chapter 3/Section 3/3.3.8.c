#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct invice
{
    double A;
    double B;
    double C;
    int sum;
}INVICE;

int dp[3000010];

int main()
{
    INVICE invices[31];
    double Q;
    int N;
    int m;
    int i;
    int j;
    char type;
    double money;
    int index;
    int flag;

    while(scanf("%lf %d", &Q, &N) && N)
    {
        index = 0;
        for(j = 0; j < N; j++)
        {
            flag = 1;
            invices[index].A = 0;
            invices[index].B = 0;
            invices[index].C = 0;
            invices[index].sum = 0;
            scanf("%d", &m);
            for(i = 0; i < m; i++)
            {
                getchar();
                scanf("%c:%lf", &type, &money);
                if(type == 'A')
                {
                    invices[index].A += money;
                }
                else if(type == 'B')
                {
                    invices[index].B += money;
                }
                else if(type == 'C')
                {
                    invices[index].C += money;
                }
                else
                {
                    flag = 0;
                }
            }
            if(invices[index].A > 600 || invices[index].B > 600 || invices[index].C > 600)
            {
                flag = 0;
            }
            if(flag)
            {
                invices[index].sum = (int)((invices[index].A + invices[index].B + invices[index].C) * 100);
                if(invices[index].sum <= 100000)
                {
                    index++;
                }
            }

        }
        memset(dp, 0, sizeof(dp));
        for(i = 0; i < index; i++)
        {
            for(j = (int)(Q * 100); j >= invices[i].sum; j--)
            {
                dp[j] = dp[j] > dp[j - invices[i].sum] + invices[i].sum
                    ? dp[j] : dp[j - invices[i].sum] + invices[i].sum;
            }
        }
        printf("%.2lf\n", (double)(dp[(int)(Q * 100)] / 100.0));
    }
    return 0;
}