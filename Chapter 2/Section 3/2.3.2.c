#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const double log2pi = 0.3990899342;
const double loge   = 0.4342944819;

int getret(int n)
{
    return (int)(log2pi + (double)(0.5 + n) * log10((double)n) - n * loge + 1);
}

int main()
{
    int n;
    int num;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &num);
        printf("%d\n", getret(num));
    }

    return 0;
}