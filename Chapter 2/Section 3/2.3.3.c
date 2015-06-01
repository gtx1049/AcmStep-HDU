#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

char ret[1001];
char* bigIntfour(int n)
{
    int num1array[2005] = {0};
    int num2array[2005] = {0};
    int num3array[2005] = {0};
    int num4array[2005] = {0};
    int temparray[2005] = {0};
    int i;
    int j;
    int advance = 0;

    int* num1 = num1array;
    int* num2 = num2array;
    int* num3 = num3array;
    int* num4 = num4array;
    int* temp = temparray;
    int* trans;


    if(n <= 4)
    {
        return "1";
    }

    num1array[0] = 1;
    num2array[0] = 1;
    num3array[0] = 1;
    num4array[0] = 1;

    for(j = 0; j < n - 4; j++)
    {
        for(i = 0; i < 2005; i++)
        {
            advance = num1[i] + num2[i] + num3[i] + num4[i] + advance;
            temp[i] = advance % 10;
            advance /= 10;
        }
        trans = num4;
        num4 = num3;
        num3 = num2;
        num2 = num1;
        num1 = temp;
        temp = trans;
        memset(temp, 0, sizeof(int) * 2005);
    }

    for(i = 2004; num1[i] == 0; i--);
    for(j = 0; i >= 0; j++, i--)
    {
        ret[j] = num1[i] + '0';
    }
    ret[j] = '\0';
    return ret;
}

int main()
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        printf("%s\n", bigIntfour(n));
    }

    return 0;
}