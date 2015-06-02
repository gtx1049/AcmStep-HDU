#include<stdio.h>
#include<math.h>
#include<memory.h>

//Input
//The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
//Each test case contains a single positive integer N(1<=N<=1,000,000,000).
//
//
//Output
//For each test case, you should output the leftmost digit of N^N.

//极大数->科学计数法->取对数策略
//n^n = x * 10^i
//nlg(n) = lg(x) + i
//lg(x) = nlg(n) - i
//x = 10^(nlg(n) - i) 因为lg(x)小于1大于0，所以i是nlg(n)的整数部分

int main()
{
    int n;
    int count;
    int i;
    double temp;
    int x;

    scanf("%d", &count);
    for(i = 0; i < count; i++)
    {
        scanf("%d", &n);
        temp = n * log10((double)n);
        x = (int)pow(10, temp - (long long)temp);
        printf("%d\n", x);
    }
    return 0;
}