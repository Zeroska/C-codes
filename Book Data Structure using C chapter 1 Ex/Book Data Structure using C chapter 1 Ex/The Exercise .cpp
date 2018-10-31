#include <stdio.h>
#include <conio.h>
#include <string.h>

//Write a program to read 10 integers. Display these numbers
//by printing three numbers in a line separated by commas

void read10Integer(int a[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("Please Enter your %d numbers: ",i + 1);
		scanf_s("%d", &a[i]);
	}
}

void printOut10Integer(int a[])
{
	printf("Here are your 10 numbers: \n");
	for (int i = 0; i < 10; i++)
	{
		if (i <= 2)
		{
			printf(" %d,", a[i]);
		}
		else if (i <= 5)
		{
			if (i == 3)
			{
				printf("\n");
			}
			printf(" %d,", a[i]);
		}
		else if (i <= 8)
		{
			if (i == 6)
			{
				printf("\n");
			}
			printf(" %d,", a[i]);
		}
		else if (i <= 10)
		{
			if (i == 9)
			{
				printf("\n");
			}
			printf(" %d,", a[i]);
		}
	}
}

/*Write a program to print the count of even numbers between 1 - 200, also print their sum*/
int countEvenNumbers(int totalNumber)
{
	int evenCount = 0;
	for (int i = 1; i <= totalNumber; i += 2)
	{
		evenCount += 1;
	}
	return evenCount;
}

void askTheTotalNumber()
{
	printf("What are the total number: ");
}

/*Write a program to count the number of vowels in a text*/
int countNumberOfVowelInAText(char text[])
{
	int wordCount = 0;
 	int lenght = strlen(text); // the lenght of a text
	for (int i = 0; i <= lenght - 1; i++)// looping throught the text except the /0 
	{
		if (text[i] == 'a' || text[i] == 'o' || text[i] == 'u' || text[i] == 'i' || text[i] == 'e')//if the text has vowel add to total count +1.
		{
			wordCount += 1;
		}
	}
	return wordCount;
}

void askTheString()
{
	printf("Enter your text here and we will count the vowel for ya: ");
}
/*Write a program to read the address of a user display the result by breaking it in multiples line*/
void askTheUserAddress()
{
	printf("Please enter your address: ");
}
void 
int main()
{
	int a[100];
	int number;
	char text[500];
	askTheString();
	gets_s(text);
	askTheTotalNumber();
	scanf_s("%d",&number);
	printf("The total even number of %d is %d\n\n", number, countEvenNumbers(number));
	printf("The vowel counted are: %d\n", countNumberOfVowelInAText(text));
	read10Integer(a);
	printOut10Integer(a);
	_getch();
}