#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

//Input
//The input will consist of several input cases, one per line. Each input case will be specified by the number n ( 1 ≤ n ≤ 100 ) of different elements that must be used to form the trees. A number 0 will mark the end of input and is not to be processed.
//
//
//Output
//For each input case print the number of binary trees that can be built using the n elements, followed by a newline character.

//还是卡特兰数构建二叉树，加上了全排列
//大数算法总结：
//1.取长度
//2.逆序将数字放在一个int数组里
//3.重要的advance开始为0， 乘法，除法，加法
//  加法： 结果位 = advance + 同位两数，advance = 结果位 / 10，结果位 = 结果位 % 10
//  乘法： 结果位 = advance + 位 × 乘数， advance = 结果位 / 10， 结果位 = 结果位 % 10
//  除法： 结果位 = (advance × 10 + 此位)， advance = 结果位 % 10， 结果位 = 结果位 / 10

void bigMuti(char* op, int sum)
{
    int len;
    int oparray[1000] = {0};
    int i;
    int j;
    int advance = 0;

    len = strlen(op);
    for(i = len - 1, j = 0; i >= 0; i--, j++)
    {
        oparray[j] = op[i] - '0';
    }

    for(i = 0; i < 1000; i++)
    {
        oparray[i] = sum * oparray[i] + advance;
        advance = oparray[i] / 10;
        oparray[i] %= 10;
    }

    for(i = 999; oparray[i] == 0; i--);
    for(j = 0; i >=0; j++, i--)
    {
        op[j] = oparray[i] + '0';
    }
    op[j] = '\0';
}

void bigDivide(char* op, int sum)
{
    int len;
    int oparray[1000] = {0};
    int i;
    int j;
    int advance = 0;

    len = strlen(op);
    for(i = len - 1, j = 0; i >= 0; i--, j++)
    {
        oparray[j] = op[i] - '0';
    }

    for(i = 999; i >= 0; i--)
    {
        oparray[i] = advance * 10 + oparray[i];
        advance = oparray[i] % sum;
        oparray[i] /= sum;
    }

    for(i = 999; oparray[i] == 0; i--);
    for(j = 0; i >=0; j++, i--)
    {
        op[j] = oparray[i] + '0';
    }
    op[j] = '\0';
}

void getRet(char* ret, int n)
{
    int i;

    for(i = 2 * n; i > n; i--)
    {
        bigMuti(ret, i);
    }
    for(i = 2; i <= n + 1; i++)
    {
        bigDivide(ret, i);
    }
    for(i = n; i > 1; i--)
    {
        bigMuti(ret, i);
    }
}

int main()
{
    char muti[1000];
    int n;

    while(scanf("%d", &n) != EOF && n != 0)
    {
        muti[0] = '1';
        muti[1] = '\0';
        getRet(muti, n);
        printf("%s\n", muti);
    }

    return 0;
}