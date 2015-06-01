#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int pat[100001][11];
int c[100001][11];

int pat[100001][11];

int main()
{
    int n;
    int i;
    int time;
    int maxtime;
    int position;
    int j;
    int onemax;

    while(scanf("%d", &n) && n)
    {
        memset(pat, 0, sizeof(pat));
        maxtime = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &position, &time);
            pat[time][position]++;
            if(time > maxtime)
            {
                maxtime = time;
            }
        }

        for(i = maxtime - 1; i >= 0; i--)
        {
            for(j = 0; j < 11; j++)
            {
                if(j == 0)
                {
                    pat[i][j] = pat[i + 1][0] > pat[i + 1][1] ? pat[i + 1][0] + pat[i][j] : pat[i + 1][1] + pat[i][j];
                }
                else if(j == 10)
                {
                    pat[i][j] = pat[i + 1][9] > pat[i + 1][10] ? pat[i + 1][9] + pat[i][j] : pat[i + 1][10] + pat[i][j];
                }
                else
                {
                    onemax = pat[i + 1][j - 1];
                    if(pat[i + 1][j] > onemax)
                    {
                        onemax = pat[i + 1][j];
                    }
                    if(pat[i + 1][j + 1] > onemax)
                    {
                        onemax = pat[i + 1][j + 1];
                    }
                    pat[i][j] = onemax + pat[i][j];
                }
            }
        }
        printf("%d\n", pat[0][5]);
    }
    return 0;
}