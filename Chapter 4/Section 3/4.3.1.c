#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//The input consists of multiple test cases. The first line
// of each test case contains three integers N, M, and T
// (1 < N, M < 7; 0 < T < 50), which denote the sizes of
// the maze and the time at which the door will open,
// respectively. The next N lines give the maze layout,
// with each line containing M characters. A character is one of the following:
//\\\\\\\'X\\\\\\\': a block of wall, which the doggie cannot enter;
//\\\\\\\'S\\\\\\\': the start point of the doggie;
//\\\\\\\'D\\\\\\\': the Door; or
//\\\\\\\'.\\\\\\\': an empty block.
//The input is terminated with three 0\\\\\\\'s. This test case is not to be processed.
//
//
//Output
//For each test case, print in one line \\\\\\\"YES\\\\\\\" if the
// doggie can survive, or \\\\\\\"NO\\\\\\\" otherwise.

//必须在T时刻到，所以使用深度优先搜索，先标记再标记回的搜索，加一层
//根据奇数偶数剪枝
//奇偶剪枝：
//是数据结构的搜索中，剪枝的一种特殊小技巧。
//现假设起点为(sx,sy)，终点为（ex,ey），给定t步恰好走到终点，
//　
//s
//|
//|
//|
//+ — — — e
//
//如图所示（“|”竖走，“—”横走，“+”转弯），易证abs(ex-sx)+abs(ey-sy)为此问题类中任意情况下，起点到终点的最短步数，记做step，此处step1=8；
//　　
//s	— —	—
// 	— —	+
//|	+
//|
//+	— —	— e
//
//如图，为一般情况下非最短路径的任意走法举例，step2=14；
//step2-step1=6，偏移路径为6，偶数（易证）；
//故，若t-[abs(ex-sx)+abs(ey-sy)]结果为非偶数（奇数），则无法在t步恰好到达；
//返回，false；
//反之亦反。
//总结，走最近路的时候想支开下，但是还得折回，就是多了偶数步

typedef struct Point
{
    int x;
    int y;
}POINT;

int abs(int x)
{
    return x > 0 ? x : -x;
}

int mark[7][7];
char map[7][7];
int N, M, T;
int success;
int offsetx[4] = {0, 0, -1, 1};
int offsety[4] = {-1, 1, 0, 0};
POINT end;
void dfs(POINT p, int time)
{
    int i;
    POINT next;

    if(time > T)
    {
        return;
    }
    if(map[p.x][p.y] == 'D' && time == T)
    {
        success = 1;
        return;
    }
    if((T - time - (abs(end.x - p.x) + abs(end.y - p.y))) & 1)
    {
        return;
    }

    for(i = 0; i < 4; i++)
    {
        next.x = p.x + offsetx[i];
        next.y = p.y + offsety[i];
        if(next.x >= 0 && next.x < N &&
           next.y >= 0 && next.y < M &&
           map[next.x][next.y] != 'X' &&
           mark[next.x][next.y] == 0 &&
           !success)
        {
            mark[next.x][next.y] = 1;
            dfs(next, time + 1);
            mark[next.x][next.y] = 0;
        }
    }
}

int main()
{

    int i, j;
    POINT begin;

    while(scanf("%d %d %d", &N, &M, &T) != EOF)
    {
        if(N == 0 && M == 0 && T == 0)
        {
            break;
        }
        getchar();
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                scanf("%c", &map[i][j]);
                if(map[i][j] == 'S')
                {
                    begin.x = i;
                    begin.y = j;
                }
                if(map[i][j] == 'D')
                {
                    end.x = i;
                    end.y = j;
                }
            }
            getchar();
        }
        success = 0;
        memset(mark, 0, sizeof(mark));
        mark[begin.x][begin.y] = 1;
        dfs(begin, 0);

        if(success)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}