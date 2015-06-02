#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//The first line of the input file contains a single integer t (1 ≤ t ≤ 10), the number of test cases, followed by input data for each test case:
//The first line is: N(N <= 100),M(M<=N),L(L <= 1000)
//N: the number of DVD that DuoDuo want buy.
//M: the number of DVD that the shop can sale.
//L: the longest time that her grandfather allowed to watch.
//The second line to N+1 line, each line contain two numbers. The first number is the time of the ith DVD, and the second number is the value of ith DVD that DuoDuo rated.
//
//
//Output
//Contain one number. (It is less then 2^31.)
//The total value that DuoDuo can get tonight.
//If DuoDuo can’t watch all of the movies that her uncle had bought for her, please output 0.

//二维背包，只需再加一维数组，此题的关键问题在于初始化
//因为M要求是“必须填满的”即每一层的数据必须由上一层得到
//那么一开始整个数组为-1，只有第0层可以叠加
//只有上次元素不为-1，才可以继续叠加

int movie[101][1001];
int main()
{
    int casecount;
    int N;
    int M;
    int L;
    int i;
    int onetime;
    int onevalue;
    int l;
    int v;

    scanf("%d", &casecount);
    while(casecount--)
    {
        scanf("%d %d %d", &N, &M, &L);
        memset(movie, -1, sizeof(movie));
        memset(movie, 0, sizeof(int) * 101);
        for(i = 0; i < N; i++)
        {
            scanf("%d %d", &onetime, &onevalue);

            for(v = M; v >= 1; v--)
            {
                for(l = L; l >= onetime; l--)
                {
                    if(movie[v - 1][l - onetime] != -1)
                    {
                        movie[v][l] = movie[v][l] > movie[v - 1][l - onetime] + onevalue ?
                                      movie[v][l] : movie[v - 1][l - onetime] + onevalue;
                    }
                }
            }
        }
        if(movie[M][L] == -1)
        {
            movie[M][L] = 0;
        }
        printf("%d\n", movie[M][L]);
    }
    return 0;
}