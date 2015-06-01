#include<stdio.h>
#include<stdlib.h>
long long num[10000];
void create()
{
    int i;
    num[1] = 2;

    for(i = 2; i < 10001; i++)
    {
        num[i] = num[i - 1] + 4 * i - 3;
    }
}

int main()
{
    int n;
    int index;

    create();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &index);
        printf("%I64d\n", num[index]);
    }
    return 0;
}