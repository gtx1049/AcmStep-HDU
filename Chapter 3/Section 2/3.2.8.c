#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//输入数据首先是一个整数C，表示测试数据的组数。
//每组测试数据的第一行是两个整数n,m，分别表示行数和列数(1<=n<=20,10<=m<=1000)；
//接着是n行数据，每行包含m个整数，表示n行m列的格子对应的幸运值K ( |k|<100 )。
//
//
//Output
//请对应每组测试数据输出一个整数，表示yifenfei可以得到的最大幸运值。

//其实挺简单的一道题，关键注意负数，如果全为负数的时候，返回max时，跟max为0比较就行不通了，所以一定要把max置成其中一值

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