#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<stdlib.h>

//Input
//第一行是一个整数N，表示有多少组数据。
//每组数据只有一个纯小数，也就是整数部分为0。小数的位数不超过9位，循环部分用()括起来。
//
//
//Output
//对每一个对应的小数化成最简分数后输出，占一行。
//求循环小数的方法：（小数所有部分 - 不循环部分） / 10的所有位次方 - 10的不循环部分位次方
//注意，pow函数会存在误差。

int gcd(int m, int n)
{
    if(n == 0)
    {
        return m;
    }
    else
    {
        return gcd(n, m % n);
    }
}

int mi(int n)
{
    int i;
    int ret = 1;
    for(i = 0; i < n; i++)
    {
        ret *= 10;
    }
    return ret;
}

int main()
{
    int count;
    int i;
    int j;
    char floatnum[15];
    char allpart[15];
    char circlepart[15];
    int digitalamount;
    int circle;
    int iscircle;
    int up;
    int down;
    int simple;

    scanf("%d", &count);
    for(i = 0; i < count; i++)
    {
        iscircle = 0;
        digitalamount = 0;
        circle = 0;
        scanf("%s", floatnum);
        for(j = 2; floatnum[j] != '\0'; j++)
        {
            if(floatnum[j] == '(' || floatnum[j] == ')')
            {
                iscircle = 1;
                continue;
            }
            if(iscircle != 1)
            {
                circlepart[circle] = floatnum[j];
                circle++;
            }
            allpart[digitalamount] = floatnum[j];
            digitalamount++;
        }
        allpart[digitalamount] = '\0';
        circlepart[circle] = '\0';

        if(iscircle == 1)
        {
            up = atoi(allpart) - atoi(circlepart);
            down = mi(digitalamount) - mi(circle);
            simple = gcd(down, up);
            printf("%d/%d\n", up / simple, down / simple);
        }
        else
        {
            up = atoi(allpart);
            down = mi(digitalamount);
            simple = gcd(down, up);
            printf("%d/%d\n", up / simple, down / simple);
        }
    }

    return 0;
}