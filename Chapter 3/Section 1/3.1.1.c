#include<stdio.h>
#include<stdlib.h>

int fabonacci(int n)
{
    int a = 1;
    int b = 1;
    int temp;

    n--;
    while(n--)
    {
        temp = a + b;
        b = a;
        a = temp;
    }
    return a;
}

int main()
{
    int n;
    int deal;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &deal);
        printf("%d\n", fabonacci(deal - 1));
    }
    return 0;
}