#include<stdio.h>
#include<stdlib.h>
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