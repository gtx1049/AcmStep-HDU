#include<stdio.h>
#include<stdlib.h>

//Input
//输入数据首先包括一个整数C,表示测试实例的个数，每个测试实例的第一行是一个整数N(1 <= N <= 100)，表示数塔的高度，接下来用N行数字表示数塔，其中第i行有个i个整数，且所有的整数均在区间[0,99]内。
//
//
//Output
//对于每个测试实例，输出可能得到的最大和，每个实例的输出占一行。

//非常基础的DP，C[i][j] = max{c[i - 1][j - 1], c[i][j]} + t[i][j]
//有一个技巧就是应该倒着走，最后顶点处就是需要的数字

int main()
{
    int tower[100][100];
    int c[100][100];
    int n;
    int i;
    int height;
    int j;
    int q;
    int max;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &height);
        for(j = 0; j < height; j++)
        {
            for(q = 0; q < j + 1; q++)
            {
                scanf("%d", &tower[j][q]);
            }
        }

        c[0][0] = tower[0][0];
        max = c[0][0];
        for(j = 1; j < height; j++)
        {
            for(q = 0; q < j + 1; q++)
            {
                if(q == 0)
                {
                    c[j][q] = c[j - 1][q] + tower[j][q];
                }
                else if(q == j)
                {
                    c[j][q] = c[j - 1][q - 1] + tower[j][q];
                }
                else
                {
                    c[j][q] = c[j - 1][q - 1] > c[j - 1][q] ? c[j - 1][q - 1] + tower[j][q] : c[j - 1][q] + tower[j][q];
                }
                if(c[j][q] > max)
                {
                    max = c[j][q];
                }
            }
        }
        printf("%d\n", max);
    }

    return 0;
}