#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
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