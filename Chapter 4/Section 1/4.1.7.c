#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//The input consists of several testcases. The first line of each testcase contains
// two integer numbers N and K, separated by a space. N (1 ≤ N ≤ 10000) is the number
//of cables in the stock, and K (1 ≤ K ≤ 10000) is the number of requested pieces.
//The first line is followed by N lines with one number per line, that specify the
//length of each cable in the stock in meters. All cables are at least 1 centimeter
//and at most 100 kilometers in length. All lengths in the input are written with
//a centimeter precision, with exactly two digits after a decimal point.
//The input is ended by line containing two 0's.
//
//
//Output
//For each testcase write to the output the maximal length (in meters) of the pieces
//that Cable Master may cut from the cables in the stock to get the requested number
//of pieces. The number must be written with a centimeter precision, with exactly
// two digits after a decimal point.
//If it is not possible to cut the requested number of pieces each one being at
//least one centimeter long, then the output must contain the single number "0.00" (without quotes).

//同分饼一题

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