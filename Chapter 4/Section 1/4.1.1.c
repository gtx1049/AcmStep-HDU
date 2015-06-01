#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double getFun(double x)
{
    return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}

int main()
{
    double begin;
    double end;
    double result;
    double x;
    int n;

    scanf("%d", &n);
    while(n--)
    {
        x = 32767;
        begin = 0;
        end = 100;
        scanf("%lf", &result);
        if(result < getFun(0) || result > getFun(100))
        {
            printf("No solution!\n");
        }
        else
        {

            while(end - begin > 0.000001)
            {
                x = getFun((begin + end) / 2);
                if(x > result)
                {
                    end = (begin + end) / 2;
                }
                else
                {
                    begin = (begin + end) / 2;
                }
            }
            printf("%.4lf\n", (begin + end) / 2);
        }
    }
    return 0;
}