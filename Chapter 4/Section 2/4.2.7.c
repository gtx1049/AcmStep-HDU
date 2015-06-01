typedef struct statu
{
    int bottle;
    int cup1;
    int cup2;
}STATUS;

#define MAX 100
STATUS queue[MAX];
int front;
int rear;
int count;

void addQueue(STATUS s)
{
    queue[rear] = s;
    count++;
    rear = (rear + 1) % MAX;
}

STATUS outQueue()
{
    STATUS temp = queue[front];
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

int mark[101][101][101];
int main()
{
    int S;
    int N;
    int M;
    STATUS begin;
    STATUS pre;
    STATUS next;
    STATUS result;

    while(scanf("%d %d %d", &S, &N, &M))
    {
        if(S == 0 && N == 0 && M == 0)
        {
            break;
        }

        if(S % 2 != 0)
        {
            printf("NO\n");
            continue;
        }

        begin.bottle = S;
        begin.cup1 = 0;
        begin.cup2 = 0;

        memset(mark, 0, sizeof(mark));
        mark[begin.bottle][begin.cup1][begin.cup2] = 1;
        clearQueue();
        addQueue(begin);
        while(!isEmpty())
        {
            pre = outQueue();
            if(pre.cup1 == S / 2 && pre.cup2 == S / 2)
            {
                result.bottle = pre.bottle;
                result.cup1 = pre.cup1;
                result.cup2 = pre.cup2;
                break;
            }
            if(pre.bottle == S / 2 && pre.cup1 == S / 2)
            {
                result.bottle = pre.bottle;
                result.cup1 = pre.cup1;
                result.cup2 = pre.cup2;
                break;
            }
            if(pre.bottle == S / 2 && pre.cup2 == S / 2)
            {
                result.bottle = pre.bottle;
                result.cup1 = pre.cup1;
                result.cup2 = pre.cup2;
                break;
            }
            if(pre.bottle - (N - pre.cup1) >= 0 && pre.bottle != 0 && pre.cup1 != N)
            {
                next.bottle = pre.bottle - (N - pre.cup1);
                next.cup1 = N;
                next.cup2 = pre.cup2;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            else if((N - pre.cup1) - pre.bottle > 0 && pre.bottle != 0 && pre.cup1 != N)
            {
                next.bottle = 0;
                next.cup1 = pre.cup1 + pre.bottle;
                next.cup2 = pre.cup2;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            if(pre.bottle - (M - pre.cup2) >= 0 && pre.bottle != 0 && pre.cup2 != M)
            {
                next.bottle = pre.bottle - (M - pre.cup2);
                next.cup2 = M;
                next.cup1 = pre.cup1;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            else if((M - pre.cup2) - pre.bottle > 0 && pre.bottle != 0 && pre.cup2 != M)
            {
                next.bottle = 0;
                next.cup2 = pre.cup2 + pre.bottle;
                next.cup1 = pre.cup1;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            if(pre.cup1 - (M - pre.cup2) >= 0 && pre.cup1 != 0 && pre.cup2 != M)
            {
                next.cup1 = pre.cup1 - (M - pre.cup2);
                next.cup2 = M;
                next.bottle = pre.bottle;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            else if((M - pre.cup2) - pre.cup1 > 0 && pre.cup1 != 0 && pre.cup2 != M)
            {
                next.cup1 = 0;
                next.cup2 = pre.cup2 + pre.cup1;
                next.bottle = pre.bottle;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            if(pre.cup2 - (N - pre.cup1) >= 0 && pre.cup2 != 0 && pre.cup1 != N)
            {
                next.cup2 = pre.cup2 - (N - pre.cup1);
                next.cup1 = N;
                next.bottle = pre.bottle;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            else if((N - pre.cup1) - pre.cup2 > 0 && pre.cup2 != 0 && pre.cup1 != N)
            {
                next.cup2 = 0;
                next.cup1 = pre.cup2 + pre.cup1;
                next.bottle = pre.bottle;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            if(pre.cup1 != 0 && pre.bottle != S)
            {
                next.bottle = pre.cup1 + pre.bottle;
                next.cup1 = 0;
                next.cup2 = pre.cup2;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
            if(pre.cup2 != 0 && pre.bottle != S)
            {
                next.bottle = pre.cup2 + pre.bottle;
                next.cup2 = 0;
                next.cup1 = pre.cup1;
                if(mark[next.bottle][next.cup1][next.cup2] == 0)
                {
                    mark[next.bottle][next.cup1][next.cup2] = mark[pre.bottle][pre.cup1][pre.cup2] + 1;
                    addQueue(next);
                }
            }
        }
        if(mark[result.bottle][result.cup1][result.cup2] == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("%d\n", mark[result.bottle][result.cup1][result.cup2] - 1);
        }
    }
    return 0;
}