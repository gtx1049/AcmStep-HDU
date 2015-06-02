#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//测试输入包含若干测试用例。每个测试用例的第1行包含两个正数 Q 和 N，其中 Q
//是给定的报销额度，N（<=30）是发票张数。随后是 N 行输入，每行的格式为：
//m Type_1:price_1 Type_2:price_2 ... Type_m:price_m
//其中正整数 m 是这张发票上所开物品的件数，Type_i 和 price_i 是第 i 项物品
//的种类和价值。物品种类用一个大写英文字母表示。当N为0时，全部输入结束，相应的结果不要输出。
//
//
//Output
//对每个测试用例输出1行，即可以报销的最大数额，精确到小数点后2位。

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