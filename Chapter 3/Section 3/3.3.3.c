#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整
//数n和m(1<=n<=100, 1<=m<=100),分别表示经费的金额和大米的种类，然后是m行数据，
//每行包含3个数p，h和c(1<=p<=20,1<=h<=200,1<=c<=20)，分别表示每袋的价格、每袋的
//重量以及对应种类大米的袋数。
//
//
//Output
//对于每组测试数据，请输出能够购买大米的最多重量，你可以假设经费买不光所有的
//大米，并且经费你可以不用完。每个实例的输出占一行。

//多重背包，同上。

int money[101];
void zeroonePack(int price, int maxout, int weight)
{
    int i;
    for(i = maxout; i >= price; i--)
    {
        money[i] = money[i] > money[i - price] + weight ? money[i] : money[i - price] + weight;
    }
}

void completePack(int price, int maxout, int weight)
{
    int i;
    for(i = price; i <= maxout; i++)
    {
        money[i] = money[i] > money[i - price] + weight ? money[i] : money[i - price] + weight;
    }
}

void multiPack(int price, int maxout, int weight, int amount)
{
    int i;
    if(price * amount >= maxout)
    {
        completePack(price, maxout, weight);
    }
    else
    {
        for(i = 1; i < amount;)
        {
            zeroonePack(i * price, maxout, i * weight);
            amount -= i;
            i *= 2;
        }
        zeroonePack(amount * price, maxout, amount * weight);
    }
}

int main()
{
    int C;
    int n;
    int m;
    int p[101];
    int h[101];
    int c[101];
    int i;

    scanf("%d", &C);
    while(C--)
    {
        scanf("%d %d", &n, &m);
        for(i = 1; i <= m; i++)
        {
            scanf("%d", &p[i]);
            scanf("%d", &h[i]);
            scanf("%d", &c[i]);
        }
        memset(money, 0, sizeof(money));
        for(i = 1; i <= m; i++)
        {
            multiPack(p[i], n, h[i], c[i]);
        }
        printf("%d\n", money[n]);
    }
    return 0;
}