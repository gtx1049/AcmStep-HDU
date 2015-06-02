#include<stdio.h>
#include<stdlib.h>

//Input
//输入数据的第一行是一个整数C,表示测试实例的个数，然后是C 行数据，每行包含一个整数n(0<n<=10000),表示折线的数量。
//
//
//Output
//对于每个测试实例，请输出平面的最大分割数，每个实例的输出占一行。

//首先考虑只有1条直线时，其对应为 1-2，2-4，3-7，4-11……可以得出 F(n) = F(n - 1) + n
//如果换成一次增加两条直线则找出的关系应为F(n + 1) = F(n) + n + 1 = F(n - 1) + 2n + 1
//此时 n = 3, n = 5... 此时需要连续i, 则 (n + 1) / 2 = i, (n - 1) / 2 = i - 1
//得到 F(i) = F(i - 1) + 4i - 1
//因为此题为折线，每次增加时，与正常情况相比，少了两个面
//所以 F(i) = F(i - 1) + 4i - 3

long long num[10000];
void create()
{
    int i;
    num[1] = 2;

    for(i = 2; i < 10001; i++)
    {
        num[i] = num[i - 1] + 4 * i - 3;
    }
}

int main()
{
    int n;
    int index;

    create();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &index);
        printf("%I64d\n", num[index]);
    }
    return 0;
}