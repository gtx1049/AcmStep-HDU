#include<stdio.h>
#include<stdlib.h>

//Input
//输入数据首先包含一个正整数C，表示包含C组测试用例，然后是C行数据，每行包含一个正整数n(1<=n<=30)，表示教室的长度。
//
//
//Output
//对于每组测试数据，请输出铺设地砖的方案数目，每个输出占一行。

//同第一题，对于n - 2的情况，可以填2种与n-1不同，所以 f(n) = 2f(n - 2) + f(n - 1)

int num[30];
void create()
{
    int i;
    num[1] = 1;
    num[2] = 3;

    for(i = 3; i < 31; i++)
    {
        num[i] = 2 * num[i - 2] + num[i - 1];
    }
}

int main()
{
    int n;
    int i;

    create();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &i);
        printf("%d\n", num[i]);
    }
    return 0;
}