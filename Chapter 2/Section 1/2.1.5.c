#include <stdio.h>
#include <memory.h>

//Input
//Each line will contain one integer n(0 < n < 1000000).
//
//
//Output
//Output the LPF(n).
//
//其实就是求一个素数在素数表中的位置
//一个非常简单的方法，筛选法，所谓筛选法
//即在一个范围的数中，去掉能够除去某些素数的数，然后继续除
//在这道题中，数组记录的是此位置数的最大素因素数在素数表位置
//通过间隔选数，等同于除法，较大素数的位置会覆盖较小的
//对于一个很大的数组，放在栈中容纳不下

#define MAX 1000001
int lpf[MAX];
int main()
{

    int i = 2;
    int j;
    int location = 1;
    int input;

    memset(lpf, -1, sizeof(int) * MAX);
    lpf[1] = 0;

    for(; i < MAX; i++)
    {
        if(lpf[i] == -1)
        {
            for(j = i; j < MAX; j += i)
            {
                lpf[j] = location;
            }
            location++;
        }
    }

    while(scanf("%d", &input) != EOF)
    {
        printf("%d\n", lpf[input]);
    }

    return 0;
}