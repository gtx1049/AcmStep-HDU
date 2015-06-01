#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
char oil[100][100];
int mark[100][100];
int count;
int m;
int n;
int xoffset[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int yoffset[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void dfs(int x, int y)
{
    int i;
    int nextx;
    int nexty;
    if(oil[x][y] == '@' && mark[x][y] != 1)
    {
        mark[x][y] = 1;
        for(i = 0; i < 8; i++)
        {
            nextx = x + xoffset[i];
            nexty = y + yoffset[i];
            if(nextx >= 0 && nexty >= 0 && nextx < m && nexty < n)
            {
                dfs(nextx, nexty);
            }
        }
    }
    else
    {
        return;
    }
}

int main()
{
    int i;
    int j;

    while(scanf("%d %d", &m, &n) != EOF && m && n)
    {
        getchar();
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%c", &oil[i][j]);
            }
            getchar();
        }
        count = 0;
        memset(mark, 0, sizeof(mark));
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(oil[i][j] == '@' && mark[i][j] != 1)
                {
                    dfs(i, j);
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}