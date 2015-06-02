#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//The input file contains one or more grids. Each grid begins
//with a line containing m and n, the number of rows and columns
// in the grid, separated by a single space. If m = 0 it signals
//  the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100.
//   Following this are m lines of n characters each (not counting
//the end-of-line characters). Each character corresponds to one
// plot, and is either `*', representing the absence of oil, or `@',
// representing an oil pocket.
//
//
//Output
//For each grid, output the number of distinct oil deposits. Two
//different pockets are part of the same oil deposit if they are
//adjacent horizontally, vertically, or diagonally. An oil deposit
//will not contain more than 100 pockets.

//DFS框架：
// dfs()
// if(满足条件) then xxx return
// dfs()
//本题思路，遇到@就进行深搜，将所有的邻近@标为1，再次搜索下一个
//注意m,n的顺序

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