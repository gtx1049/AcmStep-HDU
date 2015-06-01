#include<stdio.h>
int main()
{
    int X[11] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
    int n;
    while(scanf("%d", &n) != EOF && n)
    {
        printf("%d\n", X[n]);
    }
    return;
}