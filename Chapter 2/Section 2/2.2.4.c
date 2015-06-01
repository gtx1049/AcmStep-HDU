#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
int gcd(int m, int n)
{
    int temp;
    if(m < n)
    {
        temp = n;
        n = m;
        m = temp;
    }
    if(n == 0)
    {
        return m;
    }
    return gcd(n, m % n);
}

int main()
{
    int P;
    int m;
    int n;

    scanf("%d", &P);
    while(P--)
    {
        scanf("%d", &m);
        scanf("%d", &n);
        if(gcd(m, n) == 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}