#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//The first line of the input contains an integer T(1<=T<=100) which means
//the number of test cases. Then T lines follow, each line has only one
// real numbers Y.(0 < Y <1e10)
//
//Output
//Just the minimum value (accurate up to 4 decimal places),when x is between 0 and 100.

//求最小值，需要用到导数的知识，同时用二分法求得导数取0的近似值

double originalFun(double x, double y)
{
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x, 2) - y * x;
}

double derFun(double x, double y)
{
    return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2) + 10 * x - y;
}

int main()
{
    double y;
    int n;
    double begin;
    double end;
    double temp;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%lf", &y);

        end = 100;
        begin = 0;

        while(end - begin > 1e-6)
        {
            temp = derFun((begin + end) / 2, y);
            if(temp > 0)
            {
                end = (begin + end) / 2;
            }
            else
            {
                begin = (begin + end) / 2;
            }
        }
        printf("%.4lf\n", originalFun((begin + end) / 2, y));
    }
    return 0;
}