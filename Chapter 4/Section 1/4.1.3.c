#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//One line with a positive integer: the number of test cases. Then for each test case:
//---One line with two integers N and F with 1 <= N, F <= 10 000: the number of pies and
//the number of friends.
//---One line with N integers ri with 1 <= ri <= 10 000: the radii of the pies.
//
//
//Output
//For each test case, output one line with the largest possible volume V such that me and
//my friends can all get a pie piece of size V. The answer should be given as a floating
// point number with an absolute error of at most 10^(-3).

//关键在于最后值不是算出来的，而是搜索/检验出来的
//不满足检验时，中点成末点的原因：中点都不能满足，那么肯定更小，若现今中点能满足，则肯定更大一些

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