#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct point
{
    int x;
    int y;
}POINT;
POINT points[100];
int matrix[10][10];
int blank;
int flag;
const int test = 9;

int judge(int target, int index)
{
    int i, j;
    int x, y;
    x = points[index].x;
    y = points[index].y;
    for(j = 0; j < test; j++)
    {
        if(target == matrix[x][j] || target == matrix[j][y])
        {
            return 0;
        }
    }
    x = points[index].x / 3 * 3;
    y = points[index].y / 3 * 3;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(matrix[x + i][y + j] == target)
            {
                return 0;
            }
        }
    }

    return 1;
}

void dfs(int index)
{
    int i;

    if(blank == index)
    {
        flag = 1;
        return;
    }

    if(!flag)
    {
        for(i = 1; i <= test; i++)
        {
            if(judge(i, index))
            {
                matrix[points[index].x][points[index].y] = i;
                dfs(index + 1);
                if(!flag)
                {
                    matrix[points[index].x][points[index].y] = -1;
                }
                else
                {
                    return;
                }
            }
        }
    }


}

int main()
{
    int i;
    int j;
    char enter;
    char temp;
    int ci = 0;

    memset(matrix, 0, sizeof(matrix));
    while(1)
    {
        blank = 0;
        flag = 0;

        for(i = 0; i < test; i++)
        {
            for(j = 0; j < test; j++)
            {
                scanf("%c", &temp);
                getchar();
                if(temp - '0' > 0 && temp - '0' < 10)
                {
                    matrix[i][j] = temp - '0';
                }
                else
                {
                    matrix[i][j] = -1;
                    points[blank].x = i;
                    points[blank].y = j;
                    blank++;
                }
            }
        }

        dfs(0);
        ci++;
        if(ci != 1)
        {
            printf("\n");
        }
        for(i = 0; i < test; i++)
        {
            for(j = 0; j < test - 1; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("%d", matrix[i][j]);
            printf("\n");
        }

        if(scanf("%c", &enter) == -1)
        {
            break;
        }
    }
    return 0;
}