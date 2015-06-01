#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

//Input
//输入包含多组测试数据，每组数据占3行，首先一行是一个整数n(n<100)，表示每方上场队员的人数，接着的二行每行包含n个整数，分别依次表示中日两方人员的能力值，n为0的时候结束输入。
//
//
//Output
//对于每个测试实例，请输出比赛的结果，结果的格式如样例所示（数字和vs之间有且仅有一个空格），其中，HDU的比分在前。
//每个实例的输出占一行。

int compare(const void* num1, const void* num2)
{
   return *((int*)num1) - *((int*)num2);
}

int main()
{
   int china[100];
   int janpan[100];
   int chinascore;
   int janpanscore;
   int n;
   int i;

   while(scanf("%d", &n) && n != 0)
   {
       for(i = 0; i < n; i++)
       {
           scanf("%d", &china[i]);
       }
       for(i = 0; i < n; i++)
       {
           scanf("%d", &janpan[i]);
       }
       qsort(china, n, sizeof(int), compare);
       qsort(janpan, n, sizeof(int), compare);
       chinascore = 0;
       janpanscore = 0;
       for(i = 0; i < n; i++)
       {
           if(china[i] > janpan[i])
           {
               chinascore += 2;
           }
           else if(china[i] < janpan[i])
           {
               janpanscore += 2;
           }
           else if(china[i] == janpan[i])
           {
               chinascore++;
               janpanscore++;
           }
       }
       printf("%d vs %d\n", chinascore, janpanscore);
   }
   return 0;
}