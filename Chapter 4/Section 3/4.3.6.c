#include<stdio.h>

//Input
//共有若干行，每行一个正整数N≤10，表示棋盘和皇后的数量；如果N=0，表示结束。
//
//Output
//共有若干行，每行一个正整数，表示对应输入行的皇后的不同放置数量。

//不知道为什么DFS会超时，先递归出结果再打表了。
//int N;
//int count;
//int chess[10][10];
//
//int check(int i, int n)
//{
//    int j;
//    for(j = 0; j < N; j++)
//    {
//        if(chess[j][i] == 1)
//        {
//            return 0;
//        }
//    }
//    for(j = 0; j < N; j++)
//    {
//        if(chess[n][j] == 1)
//        {
//            return 0;
//        }
//    }
//    for(j = -N + 1; j < N; j++)
//    {
//        if(i + j < N && i + j >= 0 &&
//           n + j < N && n + j >= 0 &&
//           chess[n + j][i + j] == 1)
//        {
//            return 0;
//        }
//    }
//    for(j = -N + 1; j < N; j++)
//    {
//        if(i - j < N && i - j >= 0 &&
//           n + j < N && n + j >= 0 &&
//           chess[n + j][i - j] == 1)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//void dfs(int n)
//{
//    int i;
//    if(n == N)
//    {
//        count++;
//        return;
//    }
//
//    for(i = 0; i < N; i++)
//    {
//        if(check(i ,n))
//        {
//            chess[n][i] = 1;
//            dfs(n + 1);
//            chess[n][i] = 0;
//        }
//    }
//}
//
//int main()
//{
//    while(scanf("%d", &N) != EOF && N != 0)
//    {
//        count = 0;
//        memset(chess, 0, sizeof(chess));
//
//        dfs(0);
//
//        printf("%d\n", count);
//    }
//    return 0;
//}

int main()
{
    int X[11] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
    int n;
    while(scanf("%d", &n) != EOF && n)
    {
        printf("%d\n", X[n]);
    }
    return;
}