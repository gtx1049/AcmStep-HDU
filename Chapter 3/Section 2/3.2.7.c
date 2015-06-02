#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//输入数据有多组。每组数据的第一行为以正整数n(0<n<100000)，表示有n个馅饼掉在这条小径上。在结下来的n行中，每行有两个整数x,T(0<T<100000),表示在第T秒有一个馅饼掉在x点上。同一秒钟在同一点上可能掉下多个馅饼。n=0时输入结束。
//
//
//Output
//每一组输入数据对应一行输出。输出一个整数m，表示gameboy最多可能接到m个馅饼。
//提示：本题的输入数据量比较大，建议用scanf读入，用cin可能会超时。

//这是一个变形的数塔问题，将时间看成行，位置看成列，可以走的数变成了3个。
//应用技巧，倒着走，最后求出发点即可
//如果正着走，需要求最初0秒5点的状态才行。
//跟原始数塔不一样的是，列数是固定的。

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