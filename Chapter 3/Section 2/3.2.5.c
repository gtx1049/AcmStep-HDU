#include<stdio.h>
#include<stdlib.h>

//Input
//The input file will contain one or more test cases. The first line of each test case contains an integer n,
//representing the number of different blocks in the following data set. The maximum value for n is 30.
//Each of the next n lines contains three integers representing the values xi, yi and zi.
//Input is terminated by a value of zero (0) for n.
//
//
//Output
//For each test case, print one line containing the case number
//(they are numbered sequentially starting from 1) and the height of the
// tallest possible tower in the format "Case case: maximum height = height".

//一种方块只有3种形态，首先列出这些形态并排序，再找出最大子序列即可

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