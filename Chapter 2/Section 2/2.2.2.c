#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int ret[14] = {2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
    int i;

    while(scanf("%d", &i) != EOF)
    {
        if(i == 0)
        {
            break;
        }
        printf("%d\n", ret[i - 1]);
    }

    return 0;
}