#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s1[500];
    char s2[500];
    int table[500][500] = {{0}};
    int len1;
    int len2;
    int i;
    int j;

    while(scanf("%s %s", s1, s2) != EOF)
    {
        len1 = strlen(s1);
        len2 = strlen(s2);

        for(i = 1; i <= len1; i++)
        {
            for(j = 1; j <= len2; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    table[i][j] = table[i - 1][j - 1] + 1;
                }
                else
                {
                    table[i][j] = table[i - 1][j] > table[i][j - 1] ? table[i - 1][j] : table[i][j - 1];
                }
            }
        }
        printf("%d\n", table[len1][len2]);
    }

    return 0;
}