#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
long long stirling(int m, int n)
{
    if(m == n)
    {
        return 1;
    }
    if(n == 0)
    {
        return 0;
    }

    return (m - 1) * stirling(m - 1, n) + stirling(m - 1, n - 1);
}

int main()
{
    int n;
    int m;
    int k;
    long long up;
    long long down;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &m);
        scanf("%d", &k);

        down = 1;
        up = 0;

        while(k != 0)
        {
            up += stirling(m, k) - stirling(m - 1, k - 1);
            k--;
        }
        while(m != 0)
        {
            down *= m;
            m--;
        }

        printf("%.4f\n", 1.0 * up / down);
    }
    return 0;
}