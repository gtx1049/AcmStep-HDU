#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//The input file consists of separate lines containing k. The last line in the input file contains 0. You can suppose that 0 < k < 14.
//
//
//Output
//The output file will consist of separate lines containing m corresponding to k in the input file.

//joseph问题，存在幸存者的递推公式和处决者的递推公式，下标的代表意义有所不同
//首先考虑转换序列k被杀死则剩余序列为：
//k + 1, k + 2, ...  n       , 0, 1, ... k - 1 经转换：
//  0  ,   1  , ...n - k - 1 , ...       n - 1
//上下的映射关系 下排位置x, k为上一轮的位置,(x + k) % (n - 1) = 上排数字（即不变编号）
//而下排位置x为 m % (n - 1) - 1
//最后我们得出的是不变下标的递推公式：f(i) = (m % (n - 1) - 1 + f(i - 1)) % (n - 1)
//化简：f(i) = (f(i - 1) + m - 1) % (n - i) f(i)=0 可由第一次的结果推定
//此题有因最后一个被杀人必为k + 1，所以可确定m为 k + 1的t倍，或t倍+1，验证即可

//以下为打表代码
//int caculate(int m, int k)
//{
//    int i;
//    int position =  0;
//    int n = k * 2;
//
//    for(i = 0; i < k; i++)
//    {
//        position = (position + m - 1) % (n - i);
//        if(position < k)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    int i;
//    int m;
//
//    for(i = 1; i < 14; i++)
//    {
//        for(m = i + 1; ; m += i + 1)
//        {
//            if(caculate(m, i) == 1)
//            {
//                printf("%d\n", m);
//                break;
//            }
//            else if(caculate(m + 1, i) == 1)
//            {
//                printf("%d\n", m + 1);
//                break;
//            }
//        }
//    }
//    return 0;
//}

//提交代码
int main()
{
    int ret[14] = {2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
    int i;

    while(scanf("%d", &i) != EOF)
    {
        if(i == 0)
        {
            break;
        }
        printf("%d\n", ret[i - 1]);
    }

    return 0;
}