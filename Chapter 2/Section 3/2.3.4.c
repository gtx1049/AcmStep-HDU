#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

//Input
//The input will contain a number 1 <= i <= 100 per line representing the number of elements of the set.
//
//
//Output
//You have to print a line in the output for each entry with the answer to the previous question.

//二叉树组合个数与节点的关系构成卡特兰数
//其一种通项公式为 『h(n)=C(2n,n)/(n+1) (n=1,2,3,...)』
//因为数值过大，需要大数乘除法

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
}

int main()
{
    char muti[1000];
    int n;

    while(scanf("%d", &n) != EOF)
    {
        muti[0] = '1';
        muti[1] = '\0';
        getRet(muti, n);
        printf("%s\n", muti);
    }

    return 0;
}