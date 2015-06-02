#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>

//Input
//The first line of the input contains an integer T (T ≤ 200), indicating the number of test cases. Then T cases follow. Each case contains a line with two numbers N and K. (1 < N ≤ 20, 1 ≤ K < N)
//
//
//Output
//Output one line for each case, indicating the corresponding possibility. Four digits after decimal point are preserved by rounding.

//首先介绍一下环的概念，即一个首尾相连的数列，对于此题来说，若房间的钥匙号构成环则需要破门
//例如 2->1->2 意思为在2房间拿到1的钥匙后，在1房间发现了2，以此类推，这样，这一题就是说，破门两次，即有两个环存在
//问题变成 m 个数组合成 n 个环，有几个环即表示需要破坏几次门，在这些情况中，需要去掉 1 形成自环的情况。
//引入 第一类stirling数，记为S (m , k), 既把 m 分成 k 个环的组合情况。
//去掉 1 形成自环的情况 即 剩下的 m - 1 个数形成 k - 1个环即 S(m - 1, k - 1)
//stirling递推公式： S(m, k) = (m - 1)S(m - 1, k) + S(m - 1, k - 1) [S(m, m) = 1, S(m, 0) = 0]

//此题有一个优化方向，即打表，且斯特林数表可以用一个20 × 20的数组来进行实现而无需递归。

long long stirling(int m, int n)
{
    if(m == n)
    {
        return 1;
    }
    if(n == 0)
    {
        return 0;
    }

    return (m - 1) * stirling(m - 1, n) + stirling(m - 1, n - 1);
}

int main()
{
    int n;
    int m;
    int k;
    long long up;
    long long down;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &m);
        scanf("%d", &k);

        down = 1;
        up = 0;

        while(k != 0)
        {
            up += stirling(m, k) - stirling(m - 1, k - 1);
            k--;
        }
        while(m != 0)
        {
            down *= m;
            m--;
        }

        printf("%.4f\n", 1.0 * up / down);
    }
    return 0;
}