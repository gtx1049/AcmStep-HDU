#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int mat[20][1000];

int check(int row, int column)
{
    int max = 0;
    int i;

    if(row == 0 && column == 0)
    {
        return 0;
    }
    if(row == 0)
    {
        max = mat[0][column - 1];
    }
    else if(column == 0)
    {
        max = mat[row - 1][0];
    }
    else
    {
        max = mat[row - 1][column] > mat[row][column - 1] ? mat[row - 1][column] : mat[row][column - 1];
    }

    for(i = 1; i < column + 1; i++)
    {
        if((column + 1) % i == 0)
        {
            if(mat[row][i - 1] > max)
            {
                max = mat[row][i - 1];
            }
        }
    }
    return max;
}

int main()
{
    int c;
    int i;
    int p;
    int q;
    int n;
    int m;

    scanf("%d", &c);
    for(i = 0; i < c; i++)
    {
        scanf("%d %d", &n, &m);
        memset(mat, 0, sizeof(mat));
        for(p = 0; p < n; p++)
        {
            for(q = 0; q < m; q++)
            {
                scanf("%d", &mat[p][q]);
            }
        }

        for(p = 0; p < n; p++)
        {
            for(q = 0; q < m; q++)
            {
                mat[p][q] = check(p, q) + mat[p][q];
            }
        }
        printf("%d\n", mat[n - 1][m - 1]);
    }
    return 0;
}