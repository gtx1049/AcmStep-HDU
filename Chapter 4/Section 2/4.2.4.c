#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int queue[200];
int front;
int rear;
int count;
void addQueue(int level)
{
    queue[rear] = level;
    rear = (rear + 1) % 200;
    count++;
}
int outQueue()
{
    int temp;
    temp = queue[front];
    count--;
    front = (front + 1) % 200;
    return temp;
}
void clearQueue()
{
    front = 0;
    rear = 0;
    count = 0;
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

int mark[200];
int K[200];
int main()
{
    int N;
    int A;
    int B;
    int i;
    int pre, next;

    while(scanf("%d", &N) && N)
    {
        scanf("%d %d", &A, &B);
        for(i = 0; i < N; i++)
        {
            scanf("%d", &K[i]);
        }
        for(i = 0; i < N; i++)
        {
            mark[i] = 99999;
        }
        clearQueue();
        addQueue(A - 1);
        mark[A - 1] = 0;
        while(!isEmpty())
        {
            pre = outQueue();
            next = pre + K[pre];
            if(next < N && mark[next] > mark[pre] + 1)
            {
                mark[next] = mark[pre] + 1;
                addQueue(next);
            }
            next = pre - K[pre];
            if(next >= 0 && mark[next] > mark[pre] + 1)
            {
                mark[next] = mark[pre] + 1;
                addQueue(next);
            }
        }
        if(mark[B - 1] != 99999)
        {
            printf("%d\n", mark[B - 1]);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}