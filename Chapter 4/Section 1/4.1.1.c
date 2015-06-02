#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//The first line of the input contains an integer T(1<=T<=100) which means the number
// of test cases. Then T lines follow, each line has a real number Y (fabs(Y) <= 1e10);
//
//
//Output
//For each test case, you should just output one real number(accurate up to 4
//decimal places),which is the solution of the equation,or “No solution!”,if there
//is no solution for the equation between 0 and 100.

//二分法解方程问题，每次取二分处与结果比较

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