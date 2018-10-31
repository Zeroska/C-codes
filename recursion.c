#include <stdio.h>
#include <conio.h>

int printTheFirst50Numbers(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		printf("%d",n)
		return printTheFirst50Numbers(n-1) + n;
	}
}


int main()
{
	int n = 50;
	printf("Print the first 50 Numbers")
	int The50Numbers = printTheFirst50Numbers(n);
}