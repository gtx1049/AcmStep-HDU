#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

//Input
//The input file contains several test cases. Each test case is made up of two integer numbers: m and n. It is terminated by m = n = 0. Otherwise, m, n <=100.
//
//
//Output
//For each test case, first print the test number (counting from 1) in one line, then output the number of different ways in another line.

//卡特林数的拓展形式：m个人进栈，n个人出栈（相当于m个1，n个0排列，从左向右数1的个数大于0的个数）
//其通式为 C(m + n, m) - C(m + n, m + 1) 或 C(m + n, m) - C(m + n, n - 1)
//即所有方式减去不合法方式，不合法方式与 n + 1个出栈，m - 1个入栈是等价的
//此题还需乘以全排列数量

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

void getRet(char* ret, int n, int m)
{
    int i;

    for(i = m + n; i > 1; i--)
    {
        bigMuti(ret, i);
    }
    bigMuti(ret, m + 1 - n);
    bigDivide(ret, m + 1);
}

int main()
{
    int m;
    int n;
    char ret[1000];
    int i = 1;

    while(scanf("%d %d", &n, &m))
    {
        if(n == 0 && m == 0)
        {
            break;
        }
        if(m > n)
        {
            printf("Test #%d:\n", i);
            printf("0\n");
        }
        else
        {
            ret[0] = '1';
            ret[1] = '\0';
            getRet(ret, m ,n);
            printf("Test #%d:\n", i);
            printf("%s\n", ret);
        }
        i++;
    }
    return 0;
}