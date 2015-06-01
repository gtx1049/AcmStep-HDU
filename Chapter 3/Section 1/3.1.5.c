#include<stdio.h>
#include<stdlib.h>
int num[30];
void create()
{
    int i;
    num[1] = 1;
    num[2] = 3;

    for(i = 3; i < 31; i++)
    {
        num[i] = 2 * num[i - 2] + num[i - 1];
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