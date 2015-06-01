#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAX 1005
typedef struct Point
{
    int currentn;
    int currentm;
    int step;
    char op[MAX];
}POINT;

POINT queue[MAX];
int count;
int front;
int rear;

void addQueue(POINT p)
{
    queue[rear] = p;
    rear = (rear + 1) % MAX;
    count++;
}

POINT outQueue()
{
    POINT temp = queue[front];
    count--;
    front = (front + 1) % MAX;
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
    if(count)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
char oper[5] = {"+-*%"};
int mark[MAX];
int main()
{
    int N, M, K;
    POINT begin;
    POINT pre;
    POINT next;
    int target;
    POINT out;
    int i;

    while(scanf("%d %d %d", &N, &K, &M) != EOF)
    {
        if(N == 0 && M == 0 && K == 0)
        {
            break;
        }

        out.step = 0;
        target = (N + 1 + 1000 * K) % K;
        clearQueue();
        begin.currentn = (N + 1000 * K) % K;
        begin.currentm = (N + 1000 * M) % M;
        begin.step = 0;
        memset(mark, 0, sizeof(mark));
        mark[begin.currentn] = 1;
        addQueue(begin);

        while(!isEmpty())
        {
            pre = outQueue();
            if(target == pre.currentn)
            {
                out = pre;
                break;
            }

            for(i = 0; i < 4; i++)
            {
                next = pre;
                switch(i)
                {
                    case 0:
                        next.currentn = (next.currentn + M + 1000 * K) % K;
                        break;
                    case 1:
                        next.currentn = (next.currentn - M + 1000 * K) % K;
                        next.currentm = (next.currentm - M + 1000 * M) % M;
                        break;
                    case 2:
                        next.currentn = (next.currentn * M + 1000 * K) % K;
                        next.currentm = 0;
                        break;
                    case 3:
                        next.currentn = (next.currentm + 1000 * K) % K;
                        break;
                }
                if(!mark[next.currentn])
                {
                    mark[next.currentn] = 1;
                    next.step++;
                    next.op[next.step] = oper[i];
                    addQueue(next);
                }
            }
        }
        printf("%d\n", out.step);
        if(out.step)
        {
            for(i = 1; i <= out.step; i++)
            {
                printf("%c", out.op[i]);
            }
            printf("\n");
        }
    }
    return 0;
}