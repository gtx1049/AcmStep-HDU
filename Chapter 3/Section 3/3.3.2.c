#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int marbles[6];
int bag[120001];

void zeroOne(int onevolume, int maxvolume, int value)
{
    int i;
    for(i = maxvolume; i >= onevolume; i--)
    {
        bag[i] = bag[i] > bag[i - onevolume] + value ? bag[i] : bag[i - onevolume] + value;
    }
}

void completePack(int onevolume, int maxvolume, int value)
{
    int i;
    for(i = onevolume; i <= maxvolume; i++)
    {
        bag[i] = bag[i] > bag[i - onevolume] + value ? bag[i] : bag[i - onevolume] + value;
    }
}

void multiPack(int onevolume, int maxvolume, int value, int amount)
{
    int i;
    if(onevolume * amount >= maxvolume)
    {
        completePack(onevolume, maxvolume, value);
    }
    else
    {
        for(i = 1; i < amount;)
        {
            zeroOne(i * onevolume, maxvolume, i * value);
            amount -= i;
            i *= 2;
        }
        zeroOne(amount * onevolume, maxvolume, amount * value);
    }
}

int main()
{
    int i;
    int flag;
    int totalv;
    int no = 1;

    while(1)
    {
        totalv = 0;
        flag = 1;
        memset(bag, 0, sizeof(bag));
        for(i = 0; i < 6; i++)
        {
            scanf("%d", &marbles[i]);
            if(marbles[i] != 0)
            {
                flag = 0;
                totalv += (i + 1) * marbles[i];
            }
        }
        if(flag)
        {
           break;
        }
        else
        {
            if(totalv % 2 == 0)
            {
                totalv /= 2;
                for(i = 0; i < 6; i++)
                {
                    multiPack(i + 1, totalv, i + 1, marbles[i]);
                }
                if(bag[totalv] == totalv)
                {
                    printf("Collection #%d:\n", no);
                    printf("Can be divided.\n\n");
                }
                else
                {
                    printf("Collection #%d:\n", no);
                    printf("Can't be divided.\n\n");
                }
            }
            else
            {
                printf("Collection #%d:\n", no);
                printf("Can't be divided.\n\n");
            }
        }
        no++;

    }
    return 0;
}