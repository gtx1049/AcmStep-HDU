#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
int judge(int n)
{
    int length = 1;

    while(n != 1)
    {
        if(n % 2 == 0)
        {
            n >>= 1;
        }
        else
        {
            n = 3 * n + 1;
        }
        length++;
    }
    return length;
}

int main()
{
    int begin;
    int end;
    int i;
    int max;
    int temp;
    int swap;

    while(scanf("%d", &begin) != EOF && scanf("%d", &end) != EOF)
    {
        swap = 0;
        if(begin > end)
        {
            max = begin;
            begin = end;
            end = max;
            swap = 1;
        }
        max = 0;
        for(i = begin; i <= end; i++)
        {
            temp = judge(i);
            if(temp > max)
            {
                max = temp;
            }
        }
        if(swap == 1)
        {
            temp = begin;
            begin = end;
            end = temp;
        }
        printf("%d %d %d\n", begin, end, max);
    }
    return 0;
}