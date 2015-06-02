#include<stdio.h>
#include<stdlib.h>

//Input
//There are multiple cases in this problem and ended by the EOF. In each case, there is only one integer n means the number of children (1<=n<=1000)
//
//
//Output
//For each test case, there is only one integer means the number of queue satisfied the headmaster’s needs.

//相当于上一次加了一个男孩，再看加女孩的情况，可以等价于在n - 2的情况下加2个女孩FF，而n - 2的情况不不充足，还需要
//n - 2情况下不满足条件的序列，即末尾不可能是MF，那么 n - 4 的情况可以满足 MF的情况
//所以 F(n) = F(n - 1) + F(n - 2) + F(n - 4)

void addFun(int* ret, int* num1, int* num2, int* num3)
{
    int i;
    int advance = 0;

    for(i = 0; i < 1001; i++)
    {
        ret[i] = num1[i] + num2[i] + num3[i] + advance;
        advance = ret[i] / 10;
        ret[i] %= 10;
    }

}

int array[1001][1001];
void create()
{
    int i;
    array[1][0] = 1;
    array[2][0] = 2;
    array[3][0] = 4;
    array[4][0] = 7;

    for(i = 5; i < 1001; i++)
    {
        addFun(array[i], array[i - 1], array[i - 2], array[i - 4]);
    }
}

int main()
{
    int index;
    int i;
    int j;
    char out[1000];

    create();
    while(scanf("%d", &index) != EOF)
    {
        for(i = 1000; array[index][i] == 0; i--);
        for(j = 0; i >= 0; j++, i--)
        {
            out[j] = array[index][i] + '0';
        }
        out[j] = '\0';
        printf("%s\n", out);
    }
    return 0;
}