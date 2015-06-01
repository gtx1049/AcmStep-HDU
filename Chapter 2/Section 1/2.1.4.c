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
    int p;
    int q;

    while(scanf("%d %d", &p, &q) != EOF)
    {
        printf("%d\n", p + q - gcd(p, q));
    }
    return 0;
}