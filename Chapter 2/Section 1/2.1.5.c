#include <stdio.h>
#include <memory.h>
#define MAX 1000001
int lpf[MAX];
int main()
{

    int i = 2;
    int j;
    int location = 1;
    int input;

    memset(lpf, -1, sizeof(int) * MAX);
    lpf[1] = 0;

    for(; i < MAX; i++)
    {
        if(lpf[i] == -1)
        {
            for(j = i; j < MAX; j += i)
            {
                lpf[j] = location;
            }
            location++;
        }
    }

    while(scanf("%d", &input) != EOF)
    {
        printf("%d\n", lpf[input]);
    }

    return 0;
}