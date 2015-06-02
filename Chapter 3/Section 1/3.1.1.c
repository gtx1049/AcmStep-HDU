#include<stdio.h>
#include<stdlib.h>

//Input
//输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
//
//
//Output
//对于每个测试实例，请输出不同走法的数量

//上楼梯数是菲伯纳锲数列，因为到达n层有两种方法，从 n - 1 层来或从 n - 2 层来
//那么 f(n) = f(n - 1) + f(n - 2)
//不要用递归做法，会超时

int fabonacci(int n)
{
    int a = 1;
    int b = 1;
    int temp;

    n--;
    while(n--)
    {
        temp = a + b;
        b = a;
        a = temp;
    }
    return a;
}

int main()
{
    int n;
    int deal;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &deal);
        printf("%d\n", fabonacci(deal - 1));
    }
    return 0;
}