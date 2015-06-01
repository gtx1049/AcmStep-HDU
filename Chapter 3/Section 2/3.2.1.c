#include<stdio.h>
#include<stdlib.h>

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