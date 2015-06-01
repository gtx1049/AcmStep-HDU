#include<stdio.h>
#include<memory.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct segment
{
    float x1;
    float y1;
    float x2;
    float y2;
}SEGMENT;

SEGMENT segments[1001];
int father[1001];

int findFather(int x)
{
    if(x == father[x])
    {
        return x;
    }
    else
    {
        return father[x] = findFather(father[x]);
    }
}

void unionset(int x, int y)
{
    x = findFather(x);
    y = findFather(y);
    if(x != y)
    {
        father[y] = x;
    }
}

int crossProduct(int i, int j)
{
    float x1, x2, x3, y1, y2, y3;
    x1 = segments[i].x1 - segments[j].x1;
    y1 = segments[i].y1 - segments[j].y1;
    x2 = segments[j].x2 - segments[j].x1;
    y2 = segments[j].y2 - segments[j].y1;
    x3 = segments[i].x2 - segments[j].x1;
    y3 = segments[i].y2 - segments[j].y1;
    return (x1 * y2 - x2 * y1) * (x2 * y3 - x3 * y2) >= 0;
}

int recIntersect(int i, int j)
{
    return MAX(segments[i].x2, segments[i].x1) >= MIN(segments[j].x2, segments[j].x1) &&
           MAX(segments[i].y2, segments[i].y1) >= MIN(segments[j].y2, segments[j].y1);
}

int judge(int j, int i)
{
    return recIntersect(i, j) && recIntersect(j, i) &&
           crossProduct(i, j) && crossProduct(j, i);
}

void init()
{
    int i;
    for(i = 0; i < 1001; i++)
    {
        father[i] = i;
    }
}

int main()
{
    int t, i, q, j, current, coun;
    int n;
    int p, target, result;
    char cmd;

    scanf("%d", &t);
    for(coun = 0; coun < t; coun++)
    {
        init();
        scanf("%d", &n);
        getchar();
        current = 0;
        for(p = 0; p < n; p++)
        {
            scanf("%c", &cmd);
            if(cmd == 'P')
            {
                scanf("%f %f %f %f", &segments[current].x1, &segments[current].y1,
                                     &segments[current].x2, &segments[current].y2);
                for(j = 0; j < current; j++)
                {
                    if(judge(j, current))
                    {
                        unionset(j, current);
                    }
                }
                getchar();
                current++;
            }
            else if(cmd == 'Q')
            {
                result = 0;
                scanf("%d", &q);
                target = findFather(q - 1);
                for(i = 0; i < current; i++)
                {
                    if(target == findFather((i)))
                    {
                        result++;
                    }
                }
                getchar();
                printf("%d\n", result);
            }
        }
        if(coun != t - 1)
        {
            printf("\n");
        }

    }

    return 0;
}