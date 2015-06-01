#include<stdio.h>

//HDU2719

//Input
//The input consists of one or more strings, each 1–79 characters long and on a line by itself, followed by a line containing only "#" that signals the end of the input. The character "#" is used only as an end-of-input marker and will not appear anywhere else in the input. A string may contain spaces, but not at the beginning or end of the string, and there will never be two or more consecutive spaces.
//
//
//Output
//For each input string, replace every occurrence of a reserved character in the table above by its percent-encoding, exactly as shown, and output the resulting string on a line by itself. Note that the percent-encoding for an asterisk is %2a (with a lowercase "a") rather than %2A (with an uppercase "A").
//向字符串中格式化输出数据
int main()
{
	char line[79];
	char output[79];
	char character;
	int i;
	int j;

	while(gets(line) && line[0] != '#')
	{
		for(i = 0, j = 0; line[i] != '\0'; i++)
		{
			if(line[i] >= 32 && line[i] <= 42 
			   && line[i] != 34 && line[i] != 35
			   && line[i] != 38 && line[i] != 39)
			{
				sprintf(output + j, "%%%x", line[i]);
				j = j + 3;
			}
			else
			{
				sprintf(output + j, "%c", line[i]);
				j++;
			}
		}
		printf("%s\n", output);
	}
}