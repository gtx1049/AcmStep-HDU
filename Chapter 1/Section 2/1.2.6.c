#include<stdio.h>

//HDU1328

//Input
//The input starts with the integer n on a line by itself - this is the number of strings to follow. The following n lines each contain one string of at most 50 upper-case letters.
//
//
//Output
//For each string in the input, first output the number of the string, as shown in the sample output. The print the string start is derived from the input string by replacing every time by the following letter in the alphabet, and replacing 'Z' by 'A'.
//
//Print a blank line after each test case.
//注意吃掉换行符

int main()
{
	int count;
	int i = 0;
	int j;
	char code[50];

	scanf("%d", &count);
	getchar();

	for(; i < count; i++)
	{
		gets(code);
		for(j = 0; code[j] != '\0'; j++)
		{
			if(code[j] != 90)
			{
				code[j] += 1; 
			}
			else
			{
				code[j] = 65;
			}
		}
		printf("String #%d\n", i + 1);
		printf("%s\n\n", code);
	}
}