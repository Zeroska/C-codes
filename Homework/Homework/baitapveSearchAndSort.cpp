#include <stdio.h>
#include <conio.h>
#define MAX 255

typedef struct Student {
	int idNumber;
	char lastName[50];
	char firstName[50];
}Student;


void welcomeTheUser()
{
	printf("							THE STUDENT NOTEBOOK.\n");
	printf("						/ / / / / / / / / \n");
	printf("				------------Written by Khuong.----------\n");
	printf("						/ / / / / / / / /\n\n ");
}


void showInstruction()
{
	printf("Choose from 1 to 5 to use this note book:\n");
	printf("1.Enter student information.\n");
	printf("2.Create a file name input.txt which has student information in it.\n");
	printf("3.Display the student informaion on console.\n");
	printf("4.Use Linear Search to find the target student.\n");
	printf("5.Use InterChange Sort (Aplabetical Order).\n");
	printf("Press 0 to exit.\n\n");
	printf("\tYour choice:");
}


void askHowManyStudent()
{
	printf("\nHow many student you want to enter: ");
}


void enterStudentInformation(Student array[] , int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		printf("Please enter your %d student ID: ", i + 1);
		scanf_s("%d", &array[i].idNumber);
		while (getchar() != '\n');

		printf("Enter your [%d] student first name: ", i + 1);
		gets_s(array[i].firstName);

		printf("Enter your [%d} student last name: ", i + 1);
		gets_s(array[i].lastName);

	}
}


void InputToFile(Student array[], int numberOfStudents)
{

	FILE *inputFile = fopen("input.txt", "w");
	if (inputFile == NULL)
	{
		printf("Oh sorry Error!");
	}
	printf("\tHad created a File names input.txt.\n");
	for (int i = 0; i < numberOfStudents; i++)
	{
		fprintf(inputFile, "Student no.%d\n", i + 1);
		fprintf(inputFile, "ID : %d\n", array[i].idNumber);
		fprintf(inputFile, "First name: %s\n", array[i].firstName);
		fprintf(inputFile, "Last name: %s\n\n", array[i].lastName);
	}
	fclose(inputFile);
}


void readFile()
{
	FILE *File = fopen("input.txt", "r");
	char buffer[1000];
	if (File == NULL)
	{
		printf("Error!!!");
	}
	while (fgets(buffer, 10000, File) != NULL)
	{
		printf("%s",buffer);
	}
	fclose(File);
}


int linearSearch(Student array[], int n, int idStudent)
{
	for (int i = 0; i < n; i++)
	{
		if (idStudent == array[i].idNumber)
		{
			return i + 1;
		}
	}
	return NULL;
}


void swap(Student &a, Student &b)
{
	Student temp;
	temp = a;
	a = b;
	b = temp;

}


void interchangeSort(Student array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i].firstName < array[j].firstName)
			{
				swap(array[i] ,array[j]);
			}
		}
	}
}


void askForSpecificStudent()
{
	printf("Please enter student ID: ");
}


void exitboard()
{
	printf("My watch has ended, program exit.!!\n");
}


void showHowManyStudent(int numberOfStudent)
{
	printf("\n\tYou had %d student's informations.\n ", numberOfStudent);
}

void outputSorted()
{
	printf("The content has been sorted.\n\n");
}

int main()
{
	
	Student array[MAX];
	int choice;
	int numberOfStudents;
	int studentIDs;

	welcomeTheUser();
	
	while (int loop = true)
	{
		showInstruction();
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0:
			exitboard();
			loop = false;
			break;

		case 1:
			//Ask 
			askHowManyStudent();
			scanf_s("%d", &numberOfStudents);
			enterStudentInformation(array, numberOfStudents);
			break;

		case 2:
			//Create a file name input.txt which has information
			InputToFile(array, numberOfStudents);
			break;

		case 3:
			//display the content in file
			readFile();
			break;

		case 4:
		{
			//Ask for student ID
			askForSpecificStudent();
			scanf_s("%d", &studentIDs);
			int searchForStudent = linearSearch(array, numberOfStudents, studentIDs);
			printf("Found one at %d with ID %d.", searchForStudent, studentIDs);
			break;
		}
		default:
			interchangeSort(array, numberOfStudents);
			outputSorted();
			break;
		}
		showHowManyStudent(numberOfStudents);
	}
	_getch();
}	