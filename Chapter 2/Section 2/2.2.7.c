#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
int table[20] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2};
int countdigital(char* n)
{
    int len;
    int mod;
    int i;
    int left;
    int j;

    len = strlen(n);
    if(len > 1)
    {
        mod = (n[len - 1]) - '0' + (n[len - 2] - '0') * 10;
    }
    if(len == 1)
    {
        mod = (n[len - 1]) - '0';
    }
    if(len == 0)
    {
        return 1;
    }
    left = 0;
    for(i = 0; i < len; i++)
    {
        left = left * 10 + (n[i] - '0');
        n[i] = (left / 5) + '0';
        if(n[i] == 0 + '0' && i == 0)
        {
            for(j = 0; j < len; j++)
            {
                n[j] = n[j + 1];
            }
            i--;
            len--;
        }

        left = left % 5;
    }

    return countdigital(n) * table[mod % 20] % 10;
}

int main()
{
    char n[1000];

    while(scanf("%s", n) != EOF)
    {
        printf("%d\n",countdigital(n));
    }

    return 0;
}