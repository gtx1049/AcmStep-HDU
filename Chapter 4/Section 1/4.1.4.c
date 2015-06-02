#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//There are many cases. Every data case is described as followed: In the first line
//there are three integers L, N, M, in the second line there are L integers represent
// the sequence A, in the third line there are N integers represent the sequences B,
// in the forth line there are M integers represent the sequence C. In the fifth line
//  there is an integer S represents there are S integers X to be calculated. 1<=L, N,
//  M<=500, 1<=S<=1000. all the integers are 32-integers.
//
//Output
//For each case, firstly you have to print the case number as the form "Case d:",
//then for the S queries, you calculate if the formula can be satisfied or not. If
// satisfied, you print "YES", otherwise print "NO".

//首先列举出所有的 a+b 和，用给得的值减去 c，用此值在sum中搜索

int absum[250000];

int compare(const void* num1, const void* num2)
{
    return *((int*)num1) - *((int*)num2);
}

int check(int target, int len)
{
    int begin = 0;
    int end = len - 1;

    while(end - begin > 1)
    {
        if(absum[(begin + end) / 2] == target)
        {
            return 1;
        }
        if(absum[(begin + end) / 2] > target)
        {
            end = (begin + end) / 2;
        }
        else
        {
            begin = (begin + end) / 2;
        }
    }
    return 0;
}

int main()
{
    int L;
    int N;
    int M;
    int q;
    int i;
    int j;
    int a[500];
    int b[500];
    int c[500];
    int flag;
    int resultn;
    int result;
    int casen = 1;

    while(scanf("%d %d %d", &L, &N, &M) != EOF)
    {
        for(i = 0; i < L; i++)
        {
            scanf("%d", &a[i]);
        }
        for(i = 0; i < N; i++)
        {
            scanf("%d", &b[i]);
        }
        for(i = 0; i < M; i++)
        {
            scanf("%d", &c[i]);
        }

        q = 0;
        for(i = 0; i < L; i++)
        {
            for(j = 0; j < N; j++)
            {
                absum[q] = a[i] + b[j];
                q++;
            }
        }

        qsort(absum, q, sizeof(int), compare);

        scanf("%d", &resultn);
        printf("Case %d:\n", casen);
        for(j = 0; j < resultn; j++)
        {
            scanf("%d", &result);
            flag = 0;
            for(i = 0; i < M; i++)
            {
                if(check(result - c[i], q))
                {
                    flag = 1;
                }
            }
            if(flag)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        casen++;
    }
    return 0;
}