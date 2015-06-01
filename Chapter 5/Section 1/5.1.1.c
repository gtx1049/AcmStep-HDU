#include<stdio.h>
#include<memory.h>
int father[2001];
int po[2001];

int findFather(int x)
{
    if(x == father[x])
    {
        return x;
    }
    else
    {
        father[x] = findFather(father[x]);
        return father[x];
    }
}

void unionset(int x, int y)
{
    int fx, fy;

    fx = findFather(x);
    fy = findFather(y);

    if(fx != fy)
    {
        father[fy] = fx;
    }
}

int main()
{
    int s;
    int i, j;
    int x, y;
    int flag;
    int bugnum, interact;

    scanf("%d", &s);
    for(i = 0; i < s; i++)
    {
        flag = 1;

        scanf("%d %d", &bugnum, &interact);
        for(j = 0; j <= bugnum; j++)
        {
            father[j] = j;
        }
        memset(po, 0, sizeof(po));

        for(j = 0; j < interact; j++)
        {
            scanf("%d %d", &x, &y);

            if(flag)
            {
                x = findFather(x);
                y = findFather(y);

                if(x == y)
                {
                    flag = 0;
                }

                if(po[x] == 0)
                {
                    po[x] = y;
                }
                else
                {
                    unionset(po[x], y);
                }

                if(po[y] == 0)
                {
                    po[y] = x;
                }
                else
                {
                    unionset(po[y], x);
                }
            }

        }

        if(flag)
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", i + 1);
        }
        else
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n\n", i + 1);
        }
    }

    return 0;
}