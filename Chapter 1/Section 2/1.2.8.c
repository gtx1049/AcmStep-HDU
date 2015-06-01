#include<stdio.h>

//HDU1219

//Input
//Each article consists of just one line, and all the letters are in lowercase. You just have to count the number of each letter, so do not pay attention to other characters. The length of article is at most 100000. Process to the end of file.
//
//Note: the problem has multi-cases, and you may use "while(gets(buf)){...}" to process to the end of file.
//
//
//Output
//For each article, you have to tell how many times each letter appears. The output format is like "X:N". 
//
//Output a blank line after each test case. More details in sample output.
int main()
{
	char line[1000001];
	int aphb[26];
	unsigned int i;

	while(gets(line) != NULL)
	{
		for(i = 0; i < 26; i++)
		{
			aphb[i] = 0;
		}
		for(i = 0; line[i] != '\0'; i++)
		{
			if(line[i] >= 97 && line[i] <= 122)
			{
				aphb[line[i] - 97]++;
			}
		}
		for(i = 0; i < 26; i++)
		{
			printf("%c:%d\n", 97 + i, aphb[i]);
		}
		printf("\n");
	}
}