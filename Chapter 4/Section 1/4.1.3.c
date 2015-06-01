#include<stdio.h>
#include<stdlib.h>
#include<math.h>
const double pi = 3.14159265358979323846;
double r[10001];

int judge(double one, int F, int N)
{
    int i;
    int count = 0;

    for(i = 0; i < N; i++)
    {
        count += (int)(r[i] / one);
    }
    if(count < F)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n;
    int N;
    int F;
    int i;
    double sum;
    double begin;
    double end;

    scanf("%d", &n);
    while(n--)
    {
        sum = 0;
        scanf("%d %d", &N, &F);
        F++;
        for(i = 0; i < N; i++)
        {
            scanf("%lf", &r[i]);
            r[i] = r[i] * r[i] * pi;
            sum += r[i];
        }
        begin = 0;
        end = sum / F;

        while(end - begin > 1e-7)
        {
            if(judge((begin + end) / 2, F, N))
            {
                begin = (begin + end) / 2;
            }
            else
            {
                end = (begin + end) / 2;
            }
        }
        printf("%.4lf\n", (begin + end) / 2);
    }
    return 0;
}