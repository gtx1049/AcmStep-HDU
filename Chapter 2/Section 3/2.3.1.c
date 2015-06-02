#include <stdio.h>
#include <stdlib.h>

//Sample Input
//2
//1 2
//112233445566778899 998877665544332211
//
//
//Sample Output
//Case 1:
//1 + 2 = 3
//
//Case 2:
//112233445566778899 + 998877665544332211 = 1111111111111111110

//之前在TJOJ写的，略麻烦，但是很规整

char* addTwoInt(char* num1, char* num2)
{
	char* result;
	char* longerchar;

	int num1lenth = 0;
    int num2lenth = 0;
    int smalllenth;
	int bigerlenth;

	int topnum1;
	int topnum2;

	int toplonger;

	int bittemp;
	int flag = 0;
	int zeroflag = 1;

	int i = 0;
	int j;

	for(; *(num1 + num1lenth) != '\0'; num1lenth++);
	for(; *(num2 + num2lenth) != '\0'; num2lenth++);

	if(num1lenth <= num2lenth)
	{
		smalllenth = num1lenth;
		bigerlenth = num2lenth;
	}
	else
	{
		smalllenth = num2lenth;
		bigerlenth = num1lenth;
	}

	result = (char*)calloc(bigerlenth + 2, sizeof(char));
	for(; i < bigerlenth + 1; i++)
	{
		*(result + i) = '0';
	}
	*(result + i) = '\0';
	j = bigerlenth;

	topnum1 = num1lenth - 1;
	topnum2 = num2lenth - 1;


	for(i = 0; i < smalllenth; i++, j--)
	{
		bittemp = (*(num1 + topnum1) - '0') + (*(num2 + topnum2) - '0');
		if(flag == 1)
		{
			bittemp += 1;
			flag = 0;
		}
		if(bittemp >= 10)
		{
			bittemp -= 10;
			flag = 1;
		}
		result[j] = bittemp + '0';
		topnum1--;
		topnum2--;
	}
	toplonger = topnum1 == -1 ? topnum2 : topnum1;
	longerchar = toplonger == topnum1 ? num1 : num2;

	for(;toplonger != -1; toplonger--, j--)
	{
		bittemp = *(longerchar + toplonger) - '0';
		if(flag == 1)
		{
			bittemp += 1;
			flag = 0;
		}
		if(bittemp >= 10)
		{
			bittemp -= 10;
			flag = 1;
		}
		result[j] = bittemp + '0';
	}
	if(flag == 1)
	{
		result[j] = '1';
	}

	for(i = 0; i < bigerlenth + 1; i++)
	{
		if(result[i] != '0')
		{
			zeroflag = 0;
			break;
		}
	}
	if(zeroflag == 1)
	{
		return "0";
	}
	else
	{
		return result + i;
	}
}

int main()
{
    int i;
    int n;
    char a[1001];
    char b[1001];
    char* result;

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%s", a);
        scanf("%s", b);

        result = addTwoInt(a, b);
        printf("Case %d:\n", i);
        printf("%s + %s = %s\n", a, b, result);
        if(i < n)
        {
            printf("\n");
        }
    }
    return 0;
}