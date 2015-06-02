#include<stdio.h>
#include<stdlib.h>

//Input
//Input contains multiple test cases. Each test case is described in a line as follow:
//N value_1 value_2 …value_N
//It is guarantied that N is not more than 1000 and all value_i are in the range of 32-int.
//A test case starting with 0 terminates the input and this test case is not to be processed.
//
//
//Output
//For each case, print the maximum according to rules, and one line one case.

//c[i]为以i为结尾的数字的和，他等于c[0] 到 c[i - 1]中最大的值同时又满足a[i]大于这个最大值时的a[j],加上a[i]
//如果全不成立，他就等于a[i]

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