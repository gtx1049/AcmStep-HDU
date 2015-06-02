#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>

//Input
//包含多组数据，首先输入T,表示有T组数据.每组数据4行，第1行N是盘子的数目N<=64.
//后3行如下
//m a1 a2 ...am
//p b1 b2 ...bp
//q c1 c2 ...cq
//N=m+p+q,0<=m<=N,0<=p<=N,0<=q<=N,
//
//
//Output
//对于每组数据，判断它是否是在正确的移动中产生的系列.正确输出true，否则false

//汉诺塔是一个递归过程：
//首先 将 n - 1 个碟子从 A 移动到 B， 然后将第 n 个碟子从 A 移动到 C，最后将n - 1个碟子移动到C
//递归过程不要考虑细节，其最低操作是移动一个盘子的时候
//做验证时，这样的情况是不能发生的：n不可能落在 B (相对位置), 所有的 n - x 都不能出现在 媒介柱
//其流程如下：判断最大的n是否正确（A是原住，B是媒介柱，C是目标柱），如果 n = 0, 退出必然正确，现在看n所处位置：
//n在B柱，则序列错误退出。若n在A柱，n - 1必在A柱，则 n - 1的目标柱在B柱（为使n可过），媒介柱为C柱
//n在C柱，则以达成目标，n - 1目前在B柱，目标柱为C柱，媒介柱为A柱
//判断n - 1的情况是否正确
//仅仅是判断每一次的盘子的位置×（检验过程中不会变动），肯定是目前检验相对最大的

int isright;

void judge(int n, int* A, int* B, int* C)
{
    if(n == 0)
    {
        isright = 1;
        return;
    }
    if(B[0] == n)
    {
        isright = 0;
        return;
    }
    if(A[0] == n)
    {
        A++;
        judge(n - 1, A, C, B);
    }
    else if(C[0] == n)
    {
        C++;
        judge(n - 1, B, A, C);
    }
}

int main()
{
    int T;
    int n;
    int a;
    int b;
    int c;
    int A[64];
    int B[64];
    int C[64];
    int i;

    scanf("%d", &T);
    while(T--)
    {
        memset(A, 0, sizeof(int) * 64);
        memset(B, 0, sizeof(int) * 64);
        memset(C, 0, sizeof(int) * 64);
        isright = 1;

        scanf("%d", &n);
        scanf("%d", &a);
        for(i = 0; i < a; i++)
        {
            scanf("%d", &A[i]);
        }
        scanf("%d", &b);
        for(i = 0; i < b; i++)
        {
            scanf("%d", &B[i]);
        }
        scanf("%d", &c);
        for(i = 0; i < c; i++)
        {
            scanf("%d", &C[i]);
        }
        judge(n, A, B, C);
        if(isright)
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}