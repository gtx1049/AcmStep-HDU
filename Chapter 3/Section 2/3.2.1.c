#include<stdio.h>
#include<stdlib.h>

//Input
//The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines
// follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are
//between -1000 and 1000).
//
//
//Output
//For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case.
//The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence,
//the end position of the sub-sequence. If there are more than one result, output the first one.
//Output a blank line between two cases.

//动态规划第一道题，最大子段和问题
//规划思想：c[i]代表以a[i]为结尾的子段和
//状态方程：c[i] = c[i - 1] + a[i](当c[i] 大 于 0时)，当c[i]小于0时，c[i] = a[i] 注意，是以c[i]结尾，以其结尾必然a[i]保留
//选出最大的c[i]即可

//对于子问题最优剪贴证明，目前不深究，详见算法导论

int deal[100000];
int main()
{
    int count;
    int arrays;
    int i;
    int j;
    int c = 0;
    int max = 0;
    int begin;
    int end;
    int temp;

    scanf("%d", &count);
    for(i = 1; i <= count; i++)
    {
        scanf("%d", &arrays);
        for(j = 0; j < arrays; j++)
        {
            scanf("%d", &deal[j]);
        }

        temp = 0;
        begin = 0;
        end = 0;
        c = deal[0];
        max = deal[0];

        for(j = 1; j < arrays; j++)
        {
            if(c >= 0)
            {
                c += deal[j];
            }
            else
            {
                c = deal[j];
                temp = j;
            }
            if(c > max)
            {
                max = c;
                begin = temp;
                end = j;
            }
        }
        printf("Case %d:\n%d %d %d\n", i, max, begin + 1, end + 1);
        if(i != count)
        {
            printf("\n");
        }
    }
    return 0;
}