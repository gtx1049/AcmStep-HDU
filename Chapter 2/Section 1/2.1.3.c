#include<stdio.h>

#define LONG __int64
typedef struct Planet
{
    LONG circle;
    LONG days;
}planet;


LONG gcdAB(LONG a, LONG b)
{
    long long temp;
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
    planet a;
    planet b;
    planet result;

    LONG divide;
    int n;
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%I64d/%I64d %I64d/%I64d", &a.circle, &a.days, &b.circle, &b.days);

        result.circle = a.circle * b.circle;
        result.days = gcdAB(a.circle * b.days, b.circle * a.days);

        divide = gcdAB(result.circle, result.days);

        if(result.days == divide)
        {
            printf("%I64d\n", result.circle / divide);
        }
        else
        {
            printf("%I64d/%I64d\n", result.circle / divide, result.days / divide);
        }
    }
    return 0;
}