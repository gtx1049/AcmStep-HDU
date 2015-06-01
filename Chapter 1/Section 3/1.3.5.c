#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

//Input
//输入包含多个测试实例，每个实例的第一行是两个整数v和n(v,n<100)，分别表示口袋的容量和宝贝的种类，接着的n行每行包含2个整数pi和mi(0<pi,mi<10)，分别表示某种宝贝的单价和对应的体积，v为0的时候结束输入。
//
//
//Output
//对于每个测试实例，请输出XHD最多能取回多少价值的宝贝，每个实例的输出占一行。

typedef struct Treasure
{
   int value;
   int sum;
}treasure;

int compare(const void* trea1, const void* trea2)
{
   return ((treasure*)trea2)->value - ((treasure*)trea1)->value;
}

int main()
{
   int capacity;
   int n;
   int i;
   int get;
   treasure trea[101];

   while(scanf("%d", &capacity) && capacity != 0)
   {
       scanf("%d", &n);
       for(i = 0; i < n; i++)
       {
           scanf("%d %d", &trea[i].value, &trea[i].sum);
       }

       qsort(trea, n, sizeof(treasure), compare);

       get = 0;
       for(i = 0; i < n; i++)
       {
           if(capacity > trea[i].sum)
           {
               get += trea[i].value * trea[i].sum;
               capacity -= trea[i].sum;
           }
           else
           {
               get += trea[i].value * capacity;
               break;
           }
       }
       printf("%d\n", get);
   }
   return 0;
}