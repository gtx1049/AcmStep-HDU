#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Input
//Each line in the input describes one collection of marbles to be divided. The lines consist
//of six non-negative integers n1, n2, ..., n6, where ni is the number of marbles of value i.
//So, the example from above would be described by the input-line ``1 0 1 2 0 0''. The maximum
//total number of marbles will be 20000. The last line of the input file will be
// ``0 0 0 0 0 0''; do not process this line.
//
//
//Output
//For each colletcion, output ``Collection #k:'', where k is the number of the test case,
// and then either ``Can be divided.'' or ``Can't be divided.''. Output a blank line after
//  each test case.

//多重背包问题，有其固定算法
//首先，看看总量是否超过背包容量，若超过，按照完全背包问题处理
//对于完全背包，相对与01背包只需改变遍历顺序即从 0 到 V（因为其变化相对于同层）
//若不超过背包容量，则对每个元素进行01背包
//期间可以优化，将此种物品看成 2^k 进行01背包决定

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