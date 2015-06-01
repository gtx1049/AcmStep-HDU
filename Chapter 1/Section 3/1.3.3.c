#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

//Input
//Input contains multiple test cases. Each test case contains an integer N (1<=N<=100, the number of students) in a line first, and then N lines follow. Each line contains P (0<=P<=5 number of problems that have been solved) and T（consumed time）. You can assume that all data are different when 0<p.
//A test case starting with a negative integer terminates the input and this test case should not to be processed.
//
//
//Output
//Output the scores of N students in N lines for each case, and there is a blank line after each case.
//排序问题，注意指针，顺序还原，应用到排序
typedef struct Grade
{
   int sovled;
   unsigned int seconds;
   int id;
   int score;
}grade;

int compareSovled(const void* grade1, const void* grade2)
{
   return ((grade*)grade2)->sovled - ((grade*)grade1)->sovled;
}

int compareTime(const void* grade1, const void* grade2)
{
   return ((grade*)grade1)->seconds - ((grade*)grade2)->seconds;
}

int compareId(const void* grade1, const void* grade2)
{
   return ((grade*)grade1)->id - ((grade*)grade2)->id;
}

int main()
{
   int n;
   int i;
   int j;
   int minute;
   int hours;
   int sec;
   grade g[100];
   int scount[6];
   int offset;

   while(scanf("%d", &n) && n > 0)
   {
       memset(scount, 0, sizeof(scount));

       for(i = 0; i < n; i++)
       {
           scanf("%d %d:%d:%d", &g[i].sovled, &hours, &minute, &sec);
           g[i].seconds = hours * 3600 + minute * 60 + sec;
           g[i].id = i;
           scount[g[i].sovled]++;
       }
       qsort(g, n, sizeof(grade), compareSovled);

       offset = 0;
       for(i = 5; i >= 0; i--)
       {
           if(scount[i] == 0)
           {
               continue;
           }
           qsort(g + offset, scount[i], sizeof(grade), compareTime);
           offset += scount[i];
       }

       offset = 0;
       for(i = 5; i >= 0; i--)
       {
           for(j = 0; j < scount[i]; j++)
           {
               if(offset == n)
               {
                   break;
               }
               (*(g + offset)).score = 100 - 10 * (5 - i);
               if(i != 0 && i != 5)
               {
                   if(j < scount[i] / 2)
                   {
                       (*(g + offset)).score += 5;
                   }
               }
               offset++;
           }
       }

       qsort(g, n, sizeof(grade), compareId);

       for(i = 0; i < n; i++)
       {
           printf("%d\n", g[i].score);
       }
       printf("\n");
   }

   return 0
}