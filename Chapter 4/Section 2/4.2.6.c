#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
char map[20][20];
int mark[20][20];
int offsetx[4] = {0, 0, -1, 1};
int offsety[4] = {-1, 1, 0, 0};
int count;
int W;
int H;

void dfs(int x, int y)
{
    int i;
    int nextx;
    int nexty;
    if(map[x][y] == '#' || mark[x][y] == 1)
    {
        return;
    }
    else
    {
        count++;
        mark[x][y] = 1;
        for(i = 0; i < 4; i++)
        {
            nextx = x + offsetx[i];
            nexty = y + offsety[i];
            if(nextx >= 0 && nextx < H &&
               nexty >= 0 && nexty < W)
            {
                dfs(nextx, nexty);
            }
        }
    }
}

int main()
{
    int i;
    int j;
    int beginx, beginy;

    while(scanf("%d %d", &W, &H) != EOF && W && H)
    {
        getchar();
        for(i = 0; i < H; i++)
        {
            for(j = 0; j < W; j++)
            {
                scanf("%c", &map[i][j]);
                if(map[i][j] == '@')
                {
                    beginx = i;
                    beginy = j;
                }
            }
            getchar();
        }
        memset(mark, 0, sizeof(mark));
        count = 0;
        dfs(beginx, beginy);
        printf("%d\n", count);
    }
    return 0;
}