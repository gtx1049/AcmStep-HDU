#include<stdio.h>
#include<memory.h>
int father[100001];
int appear[100001];
int in[100001];
int flag;
int secflag;

int findFather(int x)
{
    while(x != father[x])
    {
        x = father[x];
    }
    return x;
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
    }
    memset(appear, 0, sizeof(appear));
    memset(in, 0, sizeof(in));
}

int main()
{
    int a, b;
    int j;
    int num = 1;

    while(scanf("%d %d", &a, &b))
    {
        flag = 0;
        secflag = 0;
        init();

        if(a < 0 && b < 0)
        {
            break;
        }
        if(a == 0 && b == 0)
        {
            printf("Case %d is a tree.\n", num);
            continue;
        }
        appear[a] = 1;
        appear[b] = 1;
        unionset(a, b);
        in[b]++;
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
                in[b]++;
            }
        }
        if(flag)
        {
            printf("Case %d is not a tree.\n", num);
        }
        else
        {
            for(j = 0; j < 100001; j++)
            {
                if(appear[j])
                {
                    if(father[j] == j)
                    {
                        flag++;
                    }
                    if(in[j] > 1)
                    {
                        secflag = 1;
                    }

                }
            }
            if(flag == 1 && !secflag)
            {
                printf("Case %d is a tree.\n", num);
            }
            else
            {
                printf("Case %d is not a tree.\n", num);
            }
        }

        num++;
    }

    return 0;
}