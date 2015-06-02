#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//The input file will contain one or more test cases.
//Each test case consists of one line containing two
//squares separated by one space. A square is a string
// consisting of a letter (a-h) representing the column
//  and a digit (1-8) representing the row on the chessboard.
//
//Output
//For each test case, print one line saying "To get
//from xx to yy takes n knight moves.".

//搜到就break，第一回广搜到的肯定是线路最短的.

typedef struct point
{
    int x;
    int y;
}POINT;

POINT queues[64];
int count;
int front;
int rear;

void addQueues(POINT p)
{
    count++;
    queues[rear] = p;
    rear = (rear + 1) % 64;
}

POINT outQueues()
{
    POINT temp;
    temp = queues[front];
    count--;
    front = (front + 1) % 64;
    return temp;
}

void clearQueue()
{
    count = 0;
    front = 0;
    rear = 0;
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

int map[8][8];
int main()
{
    POINT begin;
    POINT end;
    POINT pre, next;
    char in[4];
    int i, j;
    int offsetx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int offsety[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    while(scanf("%c%c %c%c", &in[0], &in[1], &in[2], &in[3]) != EOF)
    {
        getchar();
        begin.x = in[0] - 'a';
        begin.y = in[1] - '1';
        end.x = in[2] - 'a';
        end.y = in[3] - '1';

        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                map[i][j] = 99999;
            }
        }
        map[begin.x][begin.y] = 0;
        clearQueue();
        addQueues(begin);
        while(!isEmpty())
        {
            pre = outQueues();
            for(i = 0; i < 8; i++)
            {
                next.x = pre.x + offsetx[i];
                next.y = pre.y + offsety[i];

                if(next.x >= 0 && next.x < 8 &&
                   next.y >= 0 && next.y < 8 &&
                   map[next.x][next.y] > map[pre.x][pre.y] + 1)
                {
                    map[next.x][next.y] = map[pre.x][pre.y] + 1;
                    addQueues(next);
                }
            }
        }
        printf("To get from %c%c to %c%c takes %d knight moves.\n",
                begin.x + 'a', begin.y + '1', end.x + 'a', end.y + '1', map[end.x][end.y]);
    }
    return 0;
}