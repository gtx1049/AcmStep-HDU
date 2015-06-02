#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Input
//Input consists of several lines of integer numbers. The first line contains an integer n, which is the number of cases to be tested, followed by n lines, one integer 1 ≤ n ≤ 107 on each line.
//
//
//Output
//The output contains the number of digits in the factorial of the integers appearing in the input.

//利用阶乘的近似公式n！ = (根号2 * pi * n) * n^n * e^-n
//两边求对数，左侧用科学计数法表示 xx * 10的n次方，则得到结果的小数部分为xx，整数部分为n，若取得位数只需n+1
//所以结果为 0.5 * log2pi + (1 + 2 * n) / 2 * logn - nloge 去整数部分+1

const double log2pi = 0.3990899342;
const double loge   = 0.4342944819;

int getret(int n)
{
    return (int)(log2pi + (double)(0.5 + n) * log10((double)n) - n * loge + 1);
}

int main()
{
    int n;
    int num;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &num);
        printf("%d\n", getret(num));
    }

    return 0;
}