#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>

//Input
//Input to the program is a series of nonnegative integers, each on its own line with no other letters, digits or spaces. For each integer N, you should read the value and compute the last nonzero digit of N!.
//
//
//Output
//For each integer input, the program should print exactly one line of output containing the single last non-zero digit of N!.

//求一个阶乘的尾数，最重要的就是去掉0，当因数里有2，5时可以造成结果有0
//思考1，去掉所有的尾数2和5的数，对于10以内的数，得到0，1，3，4，6，7，8，9对于大于10的数如果去掉
//2，5，这多去掉了一个6（12）3（15）...2的存在过多，不易于处理，每10组中2的个数没有规律，难以处理
//思考2，提取所有的5，5是造成尾数有0的关键，提取5之后，相当于原阶乘除以5，为去掉尾数0，还需除以2
//去掉多少个5就得除掉多少个2，例如19！= 『（0，1，2，3，4，1，6，7，8，9）（1，11，12，13，14，1，16，17，18，19）』（1，2，3）
//注意 1 ！ = 0 ！是等价的。由此可见上式形成了一个新的阶乘，递归初步形成。『xxx』内部分尾数为6，6×6永远是6（10个1组的情况）
//下一步的目标是求『xxx』内尾数为多少，如果其个数不为10的整数倍
//首先考察『（0，1，2，3，4，1，6，7，8，9）』的尾数对应为『（1，1，2，6，4，4，4，8，4，6）』下一组为『6，6，2，6，4，4，4，8，4，6』不断循环
//对于大于5的数，需要除以2，而且有几个5需要除几个2，即 某表中尾数 /2^(N / 5)。参照下表：
//      『1，1，2，6，4，4，4，8，4，6』
//0 - 9 『1，1，2，6，4，2，2，4，2，8』前5除1，后5除2
//10-19 『4，4，8，4，6，8，8，6，8，2』前5除4，后5除8（注意只取尾数，且尾数一定为偶数）
//20-29 『6，6，2，6，4，2，2，4，2，8』前5除16，后5除32（注意只看尾数，则只需看6，2）
//30-39 『4，4，8，4，6，8，8，6，8，2』前5除64，后5除128
//          …………………………………………………………
//可见除数每4次一次循环（只看尾数），而还有一点为除以1等价于除以6，乘以1等价于乘以6，则知当n大于10时，表内数据以20为单位循环
//最后得到公式 f(n) = [f(n / 5) × 表[n % 20]] % 10, f(0) = 1
//增加证明，使用1，1开头的20数循环，因为×1与×6等价，当第一次超界21时，等于1×f(4)等价于6×f(4)，n = 5时同样

//此题数据非常大，达到了10的1000次方，所以需要大数除法和一些技巧
//对20取余只需最后两位

int table[20] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2};
int countdigital(char* n)
{
    int len;
    int mod;
    int i;
    int left;
    int j;

    len = strlen(n);
    if(len > 1)
    {
        mod = (n[len - 1]) - '0' + (n[len - 2] - '0') * 10;
    }
    if(len == 1)
    {
        mod = (n[len - 1]) - '0';
    }
    if(len == 0)
    {
        return 1;
    }
    left = 0;
    for(i = 0; i < len; i++)
    {
        left = left * 10 + (n[i] - '0');
        n[i] = (left / 5) + '0';
        if(n[i] == 0 + '0' && i == 0)
        {
            for(j = 0; j < len; j++)
            {
                n[j] = n[j + 1];
            }
            i--;
            len--;
        }

        left = left % 5;
    }

    return countdigital(n) * table[mod % 20] % 10;
}

int main()
{
    char n[1000];

    while(scanf("%s", n) != EOF)
    {
        printf("%d\n",countdigital(n));
    }

    return 0;
}