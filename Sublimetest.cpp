#include <stdio.h>
#include <conio.h>

//Still on the recursion thing.
//prototype
int solvedBT1(int)
int solvedBT2(int)
int solvedBT3(int)
int solvedBT4(int)
float solvedBT5(int)
float solvedBT6(int)
float solvedBT7(int)
int main()
{
	int n;
	printf("Please enter your n number: ");
	scanf_s("%d",&n);

}
int solvedBT1(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return solvedBT1(n/10) + 1;
	}
}

int solvedBT2(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n*solvedBT2(n - 1);
	}
}

int solvedBT3(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return solvedBT3(n-1) + n;
	}
}
int solvedBT4(int n )
{
	if (n == 1)
	{
		return 1/2.0;
	}
	else 
	{
		return solvedBT4(n -1) + n*n;
	}
}
float solvedBT5(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return solvedBT5(n - 1) + 1/(float)n;
	}
}
float solvedBT6(int n)
{
	if (n == 1)
	{
		return 1/2.0;
	}
	else
	{
		return solvedBT6(n -1) + 1/2(float)n;
	}
}
float solvedBT7(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return solvedBT7(n - 1) + 1/(2*(float)n + 1); 

	}
}
