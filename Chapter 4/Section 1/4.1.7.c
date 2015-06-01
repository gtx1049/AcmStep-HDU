#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double cable[10000];

int check(double one, int N, int K)
{
    int count = 0;
    int i;
    for(i = 0; i < N; i++)
    {
        count += (int)(cable[i] / one);
    }
    if(count >= K)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N;
    int K;
    int i;
    double sum;
    double begin;
    double end;

    while(scanf("%d %d", &N, &K) != EOF)
    {
        sum = 0;
        if(N == 0 && K == 0)
        {
            break;
        }
        for(i = 0; i < N; i++)
        {
            scanf("%lf", &cable[i]);
            sum += cable[i];
        }
        begin = 0;
        end = sum / K;
        while(end - begin > 1e-7)
        {
            if(check((begin + end) / 2, N, K))
            {
                begin = (begin + end) / 2;
            }
            else
            {
                end = (begin + end) / 2;
            }
        }
        if((begin + end) / 2 < 1)
        {
            printf("0.00\n");
        }
        else
        {
            printf("%.2lf\n", (begin + end) / 2);
        }
    }
    return 0;
}