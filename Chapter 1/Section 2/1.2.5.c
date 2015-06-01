#include<stdio.h>

//HDU2399

//Input
//The input file will contain data for one or more test cases, one test case per line. On each line there will be one or more upper case letters, separated by blank spaces.
//
//
//Output
//Each line of input will result in exactly one line of output. If all upper case letters on a particular line of input came from the set {A, B, C, D, F} then the output will consist of the GPA, displayed with a precision of two decimal places. Otherwise, the message "Unknown letter grade in input" will be printed.

int main()
{
	float gpa;
	float sum;
	float count;
	int i;
	char line[50];
	int flag;
	
	while(gets(line) != NULL)
	{
		sum = 0;
		count = 0;
		flag = 0;
		for(i = 0; line[i] != '\0'; i++)
		{
			if(line[i] == 'A')
			{
				sum += 4;
				count++;
			}
			else if(line[i] == 'B')
			{
				sum += 3;
				count++;
			}
			else if(line[i] == 'C')
			{
				sum += 2;
				count++;
			}
			else if(line[i] == 'D')
			{
				sum += 1;
				count++;
			}
			else if(line[i] == 'F')
			{
				count++;
			}
			else if(line[i] == ' ')
			{
				continue;
			}
			else
			{
				printf("Unknown letter grade in input\n");
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			gpa = sum / count;
			printf("%.2f\n", gpa);
		}
	}
}