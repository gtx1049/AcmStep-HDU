#include<stdio.h>
#include<stdlib.h>
long long fabonacci(int n)
{
    long long a = 1;
    long long b = 1;
    long long temp;

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

    while(scanf("%d", &n) != EOF)
    {
        printf("%I64d\n", fabonacci(n));
    }
    return 0;
}