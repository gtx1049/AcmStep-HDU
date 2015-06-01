#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

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