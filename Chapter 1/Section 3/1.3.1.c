#include<stdio.h>
#include<stdlib.h>

//Input
//The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
//
//
//Output
//For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
typedef struct Room
{
	double catfood;
	double javabean;
	double rate;
}room;
int compare(const void* room1, const void* room2)
{
	return ((room*)room1)->rate < ((room*)room2)->rate ? 1 : -1;
}

int main()
{
	room r[1001];
	int roomcount;
	int catfood;
	int i;
	double getjavabean;

	while(scanf("%d %d", &catfood, &roomcount) && !(catfood == -1 && roomcount == -1))
	{
		getjavabean = 0;

		for(i = 0; i < roomcount; i++)
		{
			scanf("%lf %lf", &r[i].javabean, &r[i].catfood);
			r[i].rate = r[i].javabean / r[i].catfood;
		}

		qsort(r, roomcount, sizeof(room), compare);

		for(i = 0; i < roomcount; i++)
		{
			if(catfood >= r[i].catfood)
			{
				getjavabean += r[i].javabean;
				catfood -= r[i].catfood;
			}
			else
			{
				getjavabean += (r[i].javabean / r[i].catfood) * catfood;
				break;
			}
		}
		printf("%.3lf\n", getjavabean);
	}
}