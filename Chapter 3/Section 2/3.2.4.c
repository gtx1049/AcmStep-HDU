#include<stdio.h>
#include<stdlib.h>

//Input
//Input contains data for a bunch of mice, one mouse per line, terminated by end of file.
//The data for a particular mouse will consist of a pair of integers: the first representing
//its size in grams and the second representing its speed in centimeters per second. Both integers
// are between 1 and 10000. The data in each test case will contain information for at most 1000 mice.
//Two mice may have the same weight, the same speed, or even the same weight and speed.
//
//
//Output
//
//Your program should output a sequence of lines of data; the first line should contain a number n;
//the remaining n lines should each contain a single positive integer (each one representing a mouse).
//If these n integers are m[1], m[2],..., m[n] then it must be the case that W[m[1]] < W[m[2]] < ... < W[m[n]]
//and S[m[1]] > S[m[2]] > ... > S[m[n]] In order for the answer to be correct, n should be as large
//as possible.All inequalities are strict: weights must be strictly increasing, and speeds must be strictly
//decreasing. There may be many correct outputs for a given input, your program only needs to find one.

//两个属性只是个迷惑而已，其实就是在递减的M序列中找一个最大的递增S序列

typedef struct mouse
{
    int weight;
    int speed;
    int index;
}MOUSE;

int compare(const void* m1, const void* m2)
{
    if(((MOUSE*)m1)->weight == ((MOUSE*)m2)->weight)
    {
        return ((MOUSE*)m2)->speed - ((MOUSE*)m1)->speed;
    }
    return ((MOUSE*)m1)->weight - ((MOUSE*)m2)->weight;
}

int main()
{
    MOUSE mice[1000];
    int c[1000];
    int index[1000];
    int w;
    int s;
    int count = 0;
    int i;
    int j;

    int maxtemp;
    int maxc;

    while(scanf("%d %d", &w, &s) != EOF)
    {
        mice[count].weight = w;
        mice[count].speed = s;
        mice[count].index = count;
        count++;
    }

    qsort(mice, count, sizeof(MOUSE), compare);

    c[0] = 1;
    maxtemp = 1;
    index[0] = 0;

    for(i = 1; i < count; i++)
    {
        c[i] = 1;
        for(j = 0; j < i; j++)
        {
            if(c[j] + 1 > c[i] && mice[i].speed < mice[j].speed && mice[i].weight > mice[j].weight)
            {
                c[i] = c[j] + 1;
                index[i] = j;
            }
        }
        if(c[i] > maxtemp)
        {
            maxtemp = c[i];
            maxc = i;
        }
    }

    for(i = 0, j = maxtemp - 1; i < maxtemp; i++, j--)
    {
        c[j] = maxc;
        maxc = index[maxc];
    }

    printf("%d\n", maxtemp);
    for(i = 0; i < maxtemp; i++)
    {
        printf("%d\n", mice[c[i]].index + 1);
    }

    return 0;
}