#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//The first line contain a integer T , the number of cases.
//Followed by T cases , each case three lines , the first line contain two integer N , V, (N <= 1000 , V <= 1000 )representing the number of bones and the volume of his bag. And the second line contain N integers representing the value of each bone. The third line contain N integers representing the volume of each bone.
//
//
//Output
//One integer per line representing the maximum of the total value (this number will be less than 231).

//0-1背包问题，状态方程f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]} i为第i个东西，v为当最大容量为v，w[i]为第i个的价值
//向一维转换从后向前覆盖即可，（前面的保留为上一次的）f[v]=max{f[v],f[v-c[i]]+w[i]}

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