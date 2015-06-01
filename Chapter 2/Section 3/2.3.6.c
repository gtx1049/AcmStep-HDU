#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
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