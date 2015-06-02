#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//The input consists of several test cases.,Each test case contains two lines.
//The first line contains three integers N ,A,B( 1 <= N,A,B <= 200) which describe
//above,The second line consist N integers k1,k2,....kn.
//A single 0 indicate the end of the input.
//
//
//Output
//For each case of the input output a interger, the least times you have to
//press the button when you on floor A,and you want to go to floor B.If you
// can't reach floor B,printf "-1".

//广度搜索，只有两个方向，需要注意的只有求最小路径的比较（有点类似于动态规划）

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