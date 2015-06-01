#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

//Input
//The input consist of several test cases. Each case begins with the student number of Jackson, an integer between 10000000 and 99999999. Following the student number are several lines, each containing a student number between 10000000 and 99999999 and a mark between 0 and 100. A line with a student number and mark of 0 terminates each test case. There are no more than 1000 students in the class, and each has a unique student number.
//
//
//Output
//For each test case, output a line giving Jackson’s rank in the class.

typedef struct Grade
{
    int studennum;
    int grade;
}grade;

int compare(const void* grade1, const void* grade2)
{
    return ((grade*)grade2)->grade - ((grade*)grade1)->grade;
}

int main()
{
    int jasonnum;
    grade gra[1000];
    int i;
    int j;
    int rank;

    while(scanf("%d", &jasonnum) != EOF)
    {
        i = 0;
        while(scanf("%d %d", &gra[i].studennum, &gra[i].grade))
        {
            if(gra[i].studennum == 0 && gra[i].grade == 0)
            {
                break;
            }
            i++;
        }

        qsort(gra, i, sizeof(grade), compare);

        rank = 1;
        for(j = 0; j < i; j++)
        {
            if(j > 0 && (gra[j - 1].grade > gra[j].grade))
            {
                rank = j + 1;
            }
            if(jasonnum == gra[j].studennum)
            {
                break;
            }
        }
        printf("%d\n", rank);
    }

    return 0;
}
