#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>

//Input
//The input will consist of a series of pairs of integers i and j, one pair of integers per line. All integers will be less than 1,000,000 and greater than 0.
//You should process all pairs of integers and for each pair determine the maximum cycle length over all integers between and including i and j.
//You can assume that no opperation overflows a 32-bit integer.
//
//
//Output
//For each pair of input integers i and j you should output i, j, and the maximum cycle length for integers between and including i and j. These three numbers should be separated by at least one space with all three numbers on one line and with one line of output for each line of input. The integers i and j must appear in the output in the same order in which they appeared in the input and should be followed by the maximum cycle length (on the same line).

//莫名其妙的一道题，用这种低效的算法不会超时，而且输入会存在i j顺序颠倒的情况

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