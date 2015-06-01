#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct POINT
{
    int x;
    int y;
}Point;

#define MAX 40000

Point queue[MAX];
int count;
int front;
int rear;
void addQueue(Point t)
{
    queue[rear] = t;
    count++;
    rear = (rear + 1) % MAX;
}
Point outQueue()
{
    Point temp = queue[front];
    count--;
    front = (front + 1) % MAX;
    return temp;
}
void clearQueue()
{
    count = 0;
    rear = 0;
    front = 0;
}
int isEmpty()
{
    if(count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char map[200][200];
int markA[200][200];
int markB[200][200];
int offsetx[4] = {-1, 0, 0, 1};
int offsety[4] = {0, -1, 1, 0};
int main()
{
    int n;
    int m;
    int i, j;
    Point xbegin, ybegin;
    Point pre, next;
    int minimal;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        getchar();
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                scanf("%c", &map[i][j]);
                if(map[i][j] == 'Y')
                {
                    xbegin.x = i;
                    xbegin.y = j;
                }
                else if(map[i][j] == 'M')
                {
                    ybegin.x = i;
                    ybegin.y = j;
                }
            }
            getchar();
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                markA[i][j] = MAX;
            }
        }
        markA[xbegin.x][xbegin.y] = 0;
        clearQueue();
        addQueue(xbegin);
        while(!isEmpty())
        {
            pre = outQueue();
            for(i = 0; i < 4; i++)
            {
                next.x = pre.x + offsetx[i];
                next.y = pre.y + offsety[i];
                if(next.x >= 0 && next.x < n &&
                   next.y >= 0 && next.y < m &&
                   map[next.x][next.y] != '#')
                {
                    if(markA[next.x][next.y] > markA[pre.x][pre.y] + 1)
                    {
                        markA[next.x][next.y] = markA[pre.x][pre.y] + 1;
                        addQueue(next);
                    }
                }
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                markB[i][j] = MAX;
            }
        }
        markB[ybegin.x][ybegin.y] = 0;
        clearQueue();
        addQueue(ybegin);
        while(!isEmpty())
        {
            pre = outQueue();
            for(i = 0; i < 4; i++)
            {
                next.x = pre.x + offsetx[i];
                next.y = pre.y + offsety[i];
                if(next.x >= 0 && next.x < n &&
                   next.y >= 0 && next.y < m &&
                   map[next.x][next.y] != '#')
                {
                    if(markB[next.x][next.y] > markB[pre.x][pre.y] + 1)
                    {
                        markB[next.x][next.y] = markB[pre.x][pre.y] + 1;
                        addQueue(next);
                    }
                }
            }
        }
        minimal = MAX;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(map[i][j] == '@')
                {
                    if(markA[i][j] + markB[i][j] < minimal)
                    {
                        minimal = markA[i][j] + markB[i][j];
                    }
                }
            }
        }
        printf("%d\n", minimal * 11);
    }
    return 0;
}