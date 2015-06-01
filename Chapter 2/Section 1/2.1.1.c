#include<stdio.h>

int gcd(int a, int b)
{
    int temp;
    if(a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int a;
    int b;
    int c;

    while(scanf("%d %d", &a, &b) != EOF)
    {
        c = gcd(a, b);
        printf("%d\n", a * b / c);
    }
    return 0;
}