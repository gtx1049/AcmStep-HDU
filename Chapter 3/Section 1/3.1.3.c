#include<stdio.h>
#include<stdlib.h>
long long num[55];
void create()
{
    int i;

    num[0] = 1;
    num[1] = 1;
    num[2] = 2;

    for(i = 3; i < 56; i++)
    {
        num[i] = num[i - 1] + num[i - 3];
    }
}

int main()
{
    int n;
    create();

    while(scanf("%d", &n) != EOF && n != 0)
    {
        printf("%I64d\n", num[n]);
    }

    return 0;
}