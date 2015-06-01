#include<stdio.h>
#include<stdlib.h>
int num[21];
void create()
{
    int i;

    num[1] = 3;
    num[2] = 7;

    for(i = 3; i < 21; i++)
    {
        num[i] = num[i - 1] * 2 + num[i - 2];
    }
}

int main()
{
    int n;
    int i;

    create();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &i);
        printf("%d\n", num[i]);
    }
    return 0;
}