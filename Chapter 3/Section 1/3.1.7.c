#include<stdio.h>
#include<stdlib.h>
long long num[51];
void create()
{
    int i;
    num[1] = 3;
    num[2] = 6;
    num[3] = 6;

    for(i = 4; i < 51; i++)
    {
        num[i] = 2 * num[i - 2] + num[i - 1];
    }
}

int main()
{
    int n;

    create();
    while(scanf("%d", &n) != EOF)
    {
        printf("%I64d\n", num[n]);
    }
    return 0;
}