//HDU1093

//Input
//Input contains an integer N in the first line, and then N lines follow. Each line starts with a integer M, and then M integers follow in the same line. 
//
//
//Output
//For each group of input integers you should output their sum in one line, and with one line of output for each line in input. 

int main()
{
	int sum;
	int count;
	int n;
	int temp;
	int i = 0;

	scanf("%d", &count);
	for(; i < count; i++)
	{
		scanf("%d", &n);
		sum  = 0;
		while(n)
		{
			scanf("%d", &temp);
			sum += temp;
			n--;
		}
		printf("%d\n", sum);
	}
}