#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//输入数据的第一行是一个正整数K,表明测试数据的数量.每组测试数据的
//第一行是四个正整数A,B,C和T(1<=A,B,C<=50,1<=T<=1000),它们分别代表
//城堡的大小和魔王回来的时间.然后是A块输入数据(先是第0块,然后是第1块
//,第2块......),每块输入数据有B行,每行有C个正整数,代表迷宫的布局,其
//中0代表路,1代表墙.(如果对输入描述不清楚,可以参考Sample Input中的
//迷宫描述,它表示的就是上图中的迷宫)
//特别注意:本题的测试数据非常大,请使用scanf输入,我不能保证使用cin能
//不超时.在本OJ上请使用Visual C++提交.
//
//Output
//对于每组测试数据,如果Ignatius能够在魔王回来前离开城堡,那么请输出他最少需要多少分钟,否则输出-1.

//三维广度搜索，只需注意方向。

#define QUL 125000
typedef struct Node
{
    int x;
    int y;
    int z;
}NODE;

NODE queue[QUL];
int qcount;
int font;
int tail;

void addQueue(NODE node)
{
    queue[tail] = node;
    tail = (tail + 1) % QUL;
    qcount++;
}

NODE outQueue()
{
    NODE ret;
    ret = queue[font];
    qcount--;
    font = (font + 1) % QUL;
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

int map[50][50][50];
int mark[50][50][50];
int main()
{
    int K;
    int A, B, C, T;
    int i, j, k;
    NODE begin;
    NODE pre, next;
    int xoffset[6] = {-1, 0, 0, 1, 0, 0};
    int yoffset[6] = {0, -1, 0, 0, 1, 0};
    int zoffset[6] = {0, 0, -1, 0, 0, 1};

    begin.x = 0;
    begin.y = 0;
    begin.z = 0;
    scanf("%d", &K);
    while(K--)
    {
        scanf("%d %d %d %d", &A, &B, &C, &T);
        for(i = 0; i < A; i++)
        {
            for(j = 0; j < B; j++)
            {
                for(k = 0; k < C; k++)
                {
                    scanf("%d", &map[i][j][k]);
                }
            }
        }
        if(map[A-1][B-1][C-1]==1)
        {
            printf("-1\n");
            continue;
        }
        memset(mark, -1, sizeof(mark));
        mark[0][0][0] = 0;
        clearQueue();
        addQueue(begin);
        while(!isQueueempty())
        {
            pre = outQueue();
            for(i = 0; i < 6; i++)
            {
                next.x = pre.x + xoffset[i];
                next.y = pre.y + yoffset[i];
                next.z = pre.z + zoffset[i];
                if(next.x < A && next.x >= 0 &&
                   next.y < B && next.y >= 0 &&
                   next.z < C && next.z >= 0 &&
                   map[next.x][next.y][next.z] != 1 &&
                   mark[next.x][next.y][next.z] == -1)
                {
                    mark[next.x][next.y][next.z] = mark[pre.x][pre.y][pre.z] + 1;
                    addQueue(next);
                }
            }
        }
        if(mark[A - 1][B - 1][C - 1] <= T)
        {
            printf("%d\n", mark[A - 1][B - 1][C - 1]);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}