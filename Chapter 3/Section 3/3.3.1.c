#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int bag[1001][1001];

typedef struct bone
{
    int value;
    int volume;
}BONE;
BONE bones[1001];

int main()
{
    int n;
    int p;
    int q;
    int i;
    int j;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &p, &q);
        for(i = 1; i <= p; i++)
        {
            scanf("%d", &bones[i].value);
        }
        for(i = 1; i <= p; i++)
        {
            scanf("%d", &bones[i].volume);
        }

        memset(bag, 0, sizeof(bag));

        for(i = 1; i <= p; i++)
        {
            for(j = 0; j <= q; j++)
            {
                if(j >= bones[i].volume)
                {
                   bag[i][j] = bag[i - 1][j] > bag[i - 1][j - bones[i].volume] + bones[i].value ? bag[i - 1][j] : bag[i - 1][j - bones[i].volume] + bones[i].value;
                }
                else
                {
                   bag[i][j] = bag[i - 1][j];
                }
            }
        }
        printf("%d\n", bag[p][q]);
    }
    return 0;
}