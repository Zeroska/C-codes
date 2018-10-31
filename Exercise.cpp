#include <stdio.h>
#include <conio.h>

//Write a program to read 10 integers. Display these numbers
//by printing three numbers in a line separated by commas

void read10Integer(int a[])
{
	for (int i = 0; i <= 10; i++)
	{
		printf("Please Enter your %d numbers: ");
		scanf_s("%d",&a[i]);
	}
}

void printOut10Integer(int a[])
{
	for (int i = 0; i <= 10; i++)
	{
		if (a[i] <= 2)
		{
			printf(" %d,",a[i]);
		}
		else if (a[i] <= 5)
		{
			printf(" %d,",a[i]);
		}
		else if (a[i] <= 8)
		{
			printf(" %d,",a[i]);
		}
		else if (a[i] <= 10)
		{
			printf(" %d,",a[i]);
		}
	}
}

int main()
{

}