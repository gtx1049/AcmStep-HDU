#include<stdio.h>
#include<stdlib.h>

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