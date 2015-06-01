#include<stdio.h>
#include<stdlib.h>
typedef struct box
{
    int x;
    int y;
    int z;
    int s;
}BOX;

int compare(const void* num1, const void* num2)
{
    return ((BOX*)num2)->s - ((BOX*)num1)->s;
}

int main()
{
    int n;
    BOX boxs[90];
    int i;
    int height[90];
    int casenum = 1;
    int j;
    int max;

    while(scanf("%d", &n) != EOF && n)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d", &boxs[i * 3].x, &boxs[i * 3].y, &boxs[i * 3].z);
            boxs[i * 3].s = boxs[i * 3].x * boxs[i * 3].y;
            boxs[i * 3 + 1].x = boxs[i * 3].y;
            boxs[i * 3 + 1].y = boxs[i * 3].z;
            boxs[i * 3 + 1].z = boxs[i * 3].x;
            boxs[i * 3 + 1].s = boxs[i * 3].y * boxs[i * 3].z;
            boxs[i * 3 + 2].x = boxs[i * 3].x;
            boxs[i * 3 + 2].y = boxs[i * 3].z;
            boxs[i * 3 + 2].z = boxs[i * 3].y;
            boxs[i * 3 + 2].s = boxs[i * 3].x * boxs[i * 3].z;
        }

        qsort(boxs, n * 3, sizeof(BOX), compare);
        max = 0;
        height[0] = boxs[0].z;
        for(i = 1; i < n * 3; i++)
        {
            height[i] = boxs[i].z;
            for(j = 0; j < i; j++)
            {
                if(((boxs[i].x < boxs[j].x && boxs[i].y < boxs[j].y) ||
                    (boxs[i].x < boxs[j].y && boxs[i].y < boxs[j].x)) &&
                     height[j] + boxs[i].z > height[i])
                {
                    height[i] = height[j] + boxs[i].z;
                }
            }
            if(height[i] > max)
            {
                max = height[i];
            }
        }
        printf("Case %d: maximum height = %d\n", casenum, max);
        casenum++;
    }
    return 0;
}