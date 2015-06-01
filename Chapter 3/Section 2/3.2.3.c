#include<stdio.h>
#include<stdlib.h>
int main()
{
    int array[1000];
    int count;
    int i;
    int j;
    int c[1000];
    int max;
    int save;
    int tempmax;

    while(scanf("%d", &count) != EOF && count)
    {
        for(i = 0; i < count; i++)
        {
            scanf("%d", &array[i]);
        }
        max = 0;
        save = 0;
        
        c[0] = array[0];
        for(i = 1; i < count; i++)
        {
            tempmax = 0;
            for(j = 0; j < i; j++)
            {
                if(c[j] > tempmax && array[i] > array[j])
                {
                    tempmax = c[j];
                    save = j;
                }
            }
            if(array[i] > array[save])
            {
                c[i] = c[save] + array[i];
            }
            else
            {
                c[i] = array[i];
            }
        }
        for(i = 0; i < count; i++)
        {
            if(c[i] > max)
            {
                max = c[i];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}