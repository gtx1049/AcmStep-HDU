#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

//Input
//The first line contains a single integer T(1≤T≤10),the number of test cases. Each test case is a single line containing 8 integers 0~8,the numbers in circle A~H.0 indicates an empty circle.

 

//Output
//For each test case ,print the case number and the solution in the same format as the input . if there is no solution ,print “No answer”.If there more than one solution,print “Not unique”.

int map[8][8] = {{0, 1, 1, 1, 0, 0, 0, 0},
                 {1, 0, 1, 0, 1, 1, 0, 0},
                 {1, 1, 0, 1, 1, 1, 1, 0},
                 {1, 0, 1, 0, 0, 1, 1, 0},
                 {0, 1, 1, 0, 0, 1, 0, 1},
                 {0, 1, 1, 1, 1, 0, 1, 1},
                 {0, 0, 1, 1, 0, 1, 0, 1},
                 {0, 0, 0, 0, 1, 1, 1, 0}};

int output[8];
int fillnum[8];
int fill[8];
int flag;

void dfs(int n)
{
    int i;
    int j;
    int q;
    int num;
    int innerflag;
    int retflag = 1;

    for(i = 0; i < 8; i++)
    {
        if(fillnum[i] == 0)
        {
            retflag = 0;
        }
    }

    if(retflag)
    {
        if(flag == 0)
        {
            for(i = 0; i < 8; i++)
            {
                output[i] = fill[i];
            }
            flag = 1;
        }
        else if(flag == 1)
        {
            flag = 2;
        }
        return;
    }

    for(i = n; i < 8; i++)
    {
        if(fill[i] == 0)
        {
            break;
        }
    }

    for(j = 0; j < 8; j++)
    {
        innerflag = 0;
        if(fillnum[j] == 0)
        {
            num = j + 1;
            for(q = 0; q < 8; q++)
            {
                if(map[i][q] == 1)
                {
                    if(fill[q] != 0 && (fill[q] == num + 1 || fill[q] == num - 1))
                    {
                        innerflag = 1;
                    }
                }
            }
            if(!innerflag)
            {
                fill[i] = num;
                fillnum[j] = 1;
                dfs(i + 1);
                fill[i] = 0;
                fillnum[j] = 0;
            }
        }
    }
}

int main()
{
    int T;
    int i;
    int num;
    int thecase = 1;

    scanf("%d", &T);

    while(T--)
    {
        memset(fillnum, 0, sizeof(fillnum));

        for(i = 0; i < 8; i++)
        {
            scanf("%d", &num);
            fill[i] = num;
            fillnum[num - 1] = 1;
        }
        flag = 0;
        dfs(0);

        if(flag == 0)
        {
            printf("Case %d: No answer\n", thecase);
        }
        else if(flag == 1)
        {
            printf("Case %d:", thecase);
            for(i = 0; i < 8; i++)
            {
                printf(" %d", output[i]);
            }
            printf("\n");
        }
        else if(flag == 2)
        {
            printf("Case %d: Not unique\n", thecase);
        }

        thecase++;
    }
    return 0;
}