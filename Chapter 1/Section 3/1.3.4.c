#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

//Input
//输入包含多组测试用例，每组输入数据只有一行数字（数字之间没有空格），这行数字的长度不大于1000。
//
//输入数据保证：分割得到的非负整数不会大于100000000；输入数据不可能全由‘5’组成。
//
//
//Output
//对于每个测试用例，输出分割得到的整数排序的结果，相邻的两个整数之间用一个空格分开，每组输出占一行。
//注意处理连续5的情况，以及末尾不是5的情况
int compare(const void* num1, const void* num2)
{
   return *(long long*)num1 > *(long long*)num2 ? 1 : -1;
}

int main()
{
   char line[1000];
   unsigned long long number[100];
   int i;
   int j;
   char* begin;

   while(gets(line) != NULL)
   {
       j = 0;
       begin = line;
       for(i = 0; line[i] != '\0'; i++)
       {
           if(line[i] == '5')
           {
               line[i] = '\0';
               if(strlen(begin) != 0)
               {
                   number[j] = atoll(begin);
                   j++;
               }
               begin = line + i + 1;
           }
       }
       if(strlen(begin) != 0)
       {
           number[j] = atoll(begin);
           j++;
       }
       qsort(number, j, sizeof(long long), compare);

       for(i = 0; i < j; i++)
       {
           if(i != j - 1)
           {
               printf("%llu ", number[i]);
           }
           else
           {
               printf("%llu\n", number[i]);
           }
       }
   }
   return 0;
}
