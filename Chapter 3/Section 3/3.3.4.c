#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
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