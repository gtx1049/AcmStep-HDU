#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//The input will contain one or more test cases, one per line. Each test
// case contains t, the total, followed by n, the number of integers in
//  the list, followed by n integers x1,...,xn. If n=0 it signals the end
//of the input; otherwise, t will be a positive integer less than 1000, n
//will be an integer between 1 and 12(inclusive), and x1,...,xn will be
//positive integers less than 100. All numbers will be separated by exactly
//one space. The numbers in each list appear in nonincreasing order, and
//there may be repetitions.
//
//
//Output
//For each test case, first output a line containing 'Sums of', the total,
// and a colon. Then output each sum, one per line; if there are no sums, output
// the line 'NONE'. The numbers within each sum must appear in nonincreasing order.
// A number may be repeated in the sum as many times as it was repeated in the
// original list. The sums themselves must be sorted in decreasing order based on
//  the numbers appearing in the sum. In other words, the sums must be sorted by
//  their first number; sums with the same first number must be sorted by their
//  second number; sums with the same first two numbers must be sorted by their
//  third number; and so on. Within each test case, all sums must be distince; the
//  same sum connot appear twice.

//有空再考虑一下，有两个不同，一个是找到了会继续执行，第二个是last的运用

int t, n;
int x[12];
int result[12];
int flag;

void dfs(int position, int sum, int count)
{
    int i;
    int last;

    if(sum > t)
    {
        return;
    }
    if(sum == t)
    {
        flag = 1;
        for(i = 0; i < count - 1; i++)
        {
            printf("%d+", result[i]);
        }
        printf("%d\n", result[i]);
    }

    last = -1;
    for(i = position; i < n; i++)
    {
        if(last != x[i])
        {
            result[count] = x[i];
            last = x[i];
            dfs(i + 1, sum + x[i], count + 1);
        }
    }
}

int main()
{
    int i;
    while(scanf("%d %d", &t, &n))
    {
        if(t == 0 && n == 0)
        {
            break;
        }
        flag = 0;

        for(i = 0; i < n; i++)
        {
            scanf("%d", &x[i]);
        }

        printf("Sums of %d:\n", t);

        dfs(0, 0, 0);

        if(!flag)
        {
            printf("NONE\n");
        }
    }
    return 0;
}