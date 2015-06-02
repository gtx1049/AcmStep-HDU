#include<stdio.h>
#include<stdlib.h>

//Problem Description
//A subsequence of a given sequence is the given sequence with some elements
//(possible none) left out. Given a sequence X = <x1, x2, ..., xm> another
//sequence Z = <z1, z2, ..., zk> is a subsequence of X if there exists a
//strictly increasing sequence <i1, i2, ..., ik> of indices of X such that
//for all j = 1,2,...,k, xij = zj. For example, Z = <a, b, f, c> is a subsequence
//of X = <a, b, c, f, b, c> with index sequence <1, 2, 4, 6>. Given two sequences X
//and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
//The program input is from a text file. Each data set in the file contains two strings representing
//the given sequences. The sequences are separated by any number of white spaces. The input data are
// correct. For each set of data the program prints on the standard output the length of the maximum
// -length common subsequence from the beginning of a separate line.

//动态规划经典问题，最大公共子序列问题，资料很多，推荐公开课算法导论上的讲解
//用一个表(备忘录)来记录曾经计算过值
//状态转移方程为 c[i][j] = c[i - 1][j - 1] + 1(if s1[i] == s2[j]) 值相同，原来公共子序列值+1
//当s1[i]与s2[j]不等时，c[i][j] 为 c[i - 1][j],c[i][j - 1]中较大的

int main()
{
    char s1[500];
    char s2[500];
    int table[500][500] = {{0}};
    int len1;
    int len2;
    int i;
    int j;

    while(scanf("%s %s", s1, s2) != EOF)
    {
        len1 = strlen(s1);
        len2 = strlen(s2);

        for(i = 1; i <= len1; i++)
        {
            for(j = 1; j <= len2; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    table[i][j] = table[i - 1][j - 1] + 1;
                }
                else
                {
                    table[i][j] = table[i - 1][j] > table[i][j - 1] ? table[i - 1][j] : table[i][j - 1];
                }
            }
        }
        printf("%d\n", table[len1][len2]);
    }

    return 0;
}