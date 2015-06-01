#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

//Input
//输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整数n和m（0<n<=1000,0<m<=1000）,分别表示经费的金额和大米的种类，然后是m行数据，每行包含2个整数p和h(1<=p<=25,1<=h<=100)，分别表示单价和对应大米的重量。
//
//
//Output
//对于每组测试数据，请输出能够购买大米的最多重量（你可以假设经费买不光所有的大米）。
//每个实例的输出占一行，保留2位小数。

typedef struct Rice
{
   double value;
   double weight;
}rice;

int compare(const void* rice1, const void* rice2)
{
   return ((rice*)rice1)->value - ((rice*)rice2)->value;
}

int main()
{
   int num;
   int i;
   int j;
   rice ri[1001];
   int types;
   double money;
   double get;

   scanf("%d", &num);

   for(i = 0; i < num; i++)
   {
       scanf("%lf %d", &money, &types);

       get = 0;
       for(j = 0; j < types; j++)
       {
           scanf("%lf %lf", &ri[j].value, &ri[j].weight);
       }

       qsort(ri, types, sizeof(rice), compare);

       for(j = 0; j < types; j++)
       {
           if(money / ri[j].value > ri[j].weight)
           {
               get += ri[j].weight;
               money -= ri[j].value * ri[j].weight;
           }
           else
           {
               get += money / ri[j].value;
               break;
           }
       }
       printf("%.2lf\n", get);
   }
   return 0;
}