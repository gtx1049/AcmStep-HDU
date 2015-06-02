#include<stdio.h>
#include<stdlib.h>

//Input
//输入数据由多行组成，每行包含一个整数n,表示该测试实例的长方形方格的规格是2×n (0<n<=50)。
//
//
//Output
//对于每个测试实例，请输出铺放方案的总数，每个实例的输出占一行。

//同样菲伯纳锲问题，骨牌n可以从 骨牌(n - 1) 的方法数得到，只需添加1块骨牌，也可以从(n - 2)得到，添加也只有一种

long long fabonacci(int n)
{
    long long a = 1;
    long long b = 1;
    long long temp;

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

    while(scanf("%d", &n) != EOF)
    {
        printf("%I64d\n", fabonacci(n));
    }
    return 0;
}