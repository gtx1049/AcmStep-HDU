#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct Node
{
    int x;
    int y;
}NODE;

NODE queue[40000];
int qcount;
int font;
int tail;

void addQueue(NODE node)
{
    queue[tail] = node;
    tail = (tail + 1) % 40000;
    qcount++;
}

NODE outQueue()
{
    NODE ret;
    ret = queue[font];
    qcount--;
    font = (font + 1) % 40000;
    return ret;
}

void clearQueue()
{
    qcount = 0;
    font = 0;
    tail = 0;
}

int isQueueempty()
{
    if(qcount == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int main()
{
    char map[200][200];
    int mark[200][200];
    int N;
    int M;
    int i;
    int j;
    int xoffset[4] = {-1, 1, 0, 0};
    int yoffset[4] = {0, 0, -1, 1};
    NODE begin;
    NODE end;
    NODE temp;
    NODE temp2;

    while(scanf("%d %d", &N, &M) != EOF)
    {
        memset(mark, 999999, sizeof(map));
        getchar();
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                scanf("%c", &map[i][j]);
                if(map[i][j] == 'a')
                {
                    begin.x = i;
                    begin.y = j;
                }
                if(map[i][j] == 'r')
                {
                    end.x = i;
                    end.y = j;
                }
            }
            getchar();
        }
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                mark[i][j] = 999999;
            }
        }
        mark[begin.x][begin.y] = 0;
        clearQueue();
        addQueue(begin);
        while(!isQueueempty())
        {
            temp = outQueue();

            for(i = 0; i < 4; i++)
            {
                temp2.x = temp.x + xoffset[i];
                temp2.y = temp.y + yoffset[i];
                if(temp2.x < N && temp2.x >= 0 &&
                    temp2.y < M && temp2.y >= 0 &&
                    map[temp2.x][temp2.y] != '#')
                {
                    if(map[temp2.x][temp2.y] == 'x')
                    {
                        if(mark[temp2.x][temp2.y] > mark[temp.x][temp.y] + 2)
                        {
                            mark[temp2.x][temp2.y] = mark[temp.x][temp.y] + 2;
                            addQueue(temp2);
                        }

                    }
                    else
                    {
                        if(mark[temp2.x][temp2.y] > mark[temp.x][temp.y] + 1)
                        {
                            mark[temp2.x][temp2.y] = mark[temp.x][temp.y] + 1;
                            addQueue(temp2);
                        }
                    }
                }
            }
        }
        if(mark[end.x][end.y] == 999999)
        {
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        }
        else
        {
            printf("%d\n", mark[end.x][end.y]);
        }
    }

    return 0;
}