#include<stdio.h>
#include<math.h>
#include<memory.h>
int main()
{
    int n;
    int count;
    int i;
    double temp;
    int x;

    scanf("%d", &count);
    for(i = 0; i < count; i++)
    {
        scanf("%d", &n);
        temp = n * log10((double)n);
        x = (int)pow(10, temp - (long long)temp);
        printf("%d\n", x);
    }
    return 0;
}