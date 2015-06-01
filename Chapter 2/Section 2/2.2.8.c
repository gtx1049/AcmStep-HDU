#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
int getret(int n)
{
    int i = 1;
    int ret = 1;

    if(n == 0)
    {
        return 1;
    }
    if(n > 41)
    {
        return 0;
    }
    for(i = 1; i <= n; i++)
    {
        ret = i * ret % 2009;
    }
    return ret;
}

int main()
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        printf("%d\n", getret(n));
    }
    return 0;
}