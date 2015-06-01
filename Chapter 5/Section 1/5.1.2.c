#include<stdio.h>
int father[100001];
int appear[100001];
int flag;

int findFather(int x)
{
    if(x == father[x])
    {
        return x;
    }
    else
    {
        return father[x] = findFather(father[x]);
    }
}

void unionset(int x, int y)
{
    x = findFather(x);
    y = findFather(y);
    if(x == y)
    {
        flag = 1;
    }
    else
    {
        father[y] = x;
    }
}

void init()
{
    int i;
    for(i = 0; i < 100001; i++)
    {
        father[i] = i;
        appear[i] = 0;
    }
}

int main()
{
    int a, b;
    int j;

    while(scanf("%d %d", &a, &b))
    {
        flag = 0;

        init();

        if(a == -1 && b == -1)
        {
            break;
        }
        if(a == 0 && b == 0)
        {
            printf("Yes\n");
            continue;
        }
        appear[a] = 1;
        appear[b] = 1;
        unionset(a, b);
        while(scanf("%d %d", &a, &b))
        {
            if(a == 0 && b== 0)
            {
                break;
            }
            if(!flag)
            {
                appear[a] = 1;
                appear[b] = 1;
                unionset(a, b);
            }
        }
        if(flag)
        {
            printf("No\n");
        }
        else
        {
            for(j = 0; j < 100001; j++)
            {
                if(appear[j] && father[j] == j)
                {
                    flag++;
                }
            }
            if(flag == 1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}