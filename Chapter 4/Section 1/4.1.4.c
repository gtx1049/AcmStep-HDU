#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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