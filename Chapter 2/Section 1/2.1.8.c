#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<stdlib.h>
int gcd(int m, int n)
{
    if(n == 0)
    {
        return m;
    }
    else
    {
        return gcd(n, m % n);
    }
}

int mi(int n)
{
    int i;
    int ret = 1;
    for(i = 0; i < n; i++)
    {
        ret *= 10;
    }
    return ret;
}

int main()
{
    int count;
    int i;
    int j;
    char floatnum[15];
    char allpart[15];
    char circlepart[15];
    int digitalamount;
    int circle;
    int iscircle;
    int up;
    int down;
    int simple;

    scanf("%d", &count);
    for(i = 0; i < count; i++)
    {
        iscircle = 0;
        digitalamount = 0;
        circle = 0;
        scanf("%s", floatnum);
        for(j = 2; floatnum[j] != '\0'; j++)
        {
            if(floatnum[j] == '(' || floatnum[j] == ')')
            {
                iscircle = 1;
                continue;
            }
            if(iscircle != 1)
            {
                circlepart[circle] = floatnum[j];
                circle++;
            }
            allpart[digitalamount] = floatnum[j];
            digitalamount++;
        }
        allpart[digitalamount] = '\0';
        circlepart[circle] = '\0';

        if(iscircle == 1)
        {
            up = atoi(allpart) - atoi(circlepart);
            down = mi(digitalamount) - mi(circle);
            simple = gcd(down, up);
            printf("%d/%d\n", up / simple, down / simple);
        }
        else
        {
            up = atoi(allpart);
            down = mi(digitalamount);
            simple = gcd(down, up);
            printf("%d/%d\n", up / simple, down / simple);
        }
    }

    return 0;
}