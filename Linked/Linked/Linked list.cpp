#include <stdio.h>
#include <conio.h>
#define MAX_LETTER_IN_NAME 80

typedef struct STUDENT
{
	char name[MAX_LETTER_IN_NAME];
	int ID;
	float mathPoint;
	float englishPoint;
	float physicsPoint;
	float averagePoint;
}STUDENT;


typedef struct NODE
{
	STUDENT info;
	NODE* next;
}NODE;


typedef struct
{
	NODE* head;
}LIST;


		//PROTOTYPE
void initialize(LIST &list);
bool isListEmpty(LIST list);
NODE* createNode(STUDENT student);
NODE* insertLast(LIST &list, STUDENT student,NODE* q);
NODE* insertHead(LIST &list, STUDENT student);
void askforStudentInformation(STUDENT &student, LIST &list, int numberOfStudent);
void askforHowManyStudent();
int countNodeHasCreated(LIST list);
void displayTheNode(LIST list);
int findMaxInList(LIST list, int numberOfStudent);
int findMinInList(LIST list, int numberOfStudent);
float findTheAveragePoint(LIST list, int numberOfStudent);
void printALine();
void askTheUserInsertLast(LIST &list, STUDENT &student);

//--------------------------------MAIN----------------------------------	
int main()
{
	int numberOfStudent;
	LIST list;
	NODE* Node = new NODE;
	STUDENT studentInformation;
	initialize(list);
	askforHowManyStudent();
	scanf_s("%d", &numberOfStudent);
	askforStudentInformation(studentInformation, list , numberOfStudent);
	printALine();
	int counted = countNodeHasCreated(list);
	bool ans = isListEmpty(list);
	float theAveragePoint = findTheAveragePoint(list, numberOfStudent);
	printf("List isn't empty right?(false = empty)  %s\n", ans? "true": "false");
	printf("There are %d Nodes.\n", counted);	
	displayTheNode(list);
	int max = findMaxInList(list, numberOfStudent);
	int min = findMinInList(list, numberOfStudent);
	printf("Max English point is: %d",max);
	printf("Min English point is %d", min);
	printf("\n");
	askTheUserInsertLast(list, studentInformation);
	int counted2 = countNodeHasCreated(list);
	printf("There are %d Nodes\n\n", counted2);
	displayTheNode(list);
	_getch();
}
//-------------------------------MAIN------------------------------------


//-------------------------------FUNCTION--------------------------------
//Initialize
void initialize(LIST &list)
{
	list.head = NULL; /*Contructor for the list*/
}


//Checck whether the list is empty or not
bool isListEmpty(LIST list)
{
	if (list.head == NULL)
	{
		return false;
	}
	return true;
}


//Create a Node without link 
NODE* createNode(STUDENT student)
{
	NODE* p = new NODE; /**/
	if (p != NULL)
	{
		p->info = student;/**/
		p->next = NULL;
	}
	return p;
}


//Add a node to the head of the list
NODE* insertHead(LIST &list, STUDENT student)
{
	NODE* p = createNode(student);	
	if (p != NULL)
	{
		p->next = list.head;

		list.head = p;
	}
	return p;
}


//Add a node to the last of the list
NODE* insertLast(LIST &list, STUDENT student,NODE* q)
{
	NODE* p = createNode(student);
	if (list.head == NULL) // If the list is empty, insert head
	{
		insertHead(list, student);
	}
	else
	{
		q = list.head; //Temp to hold the value
		while (q->next != NULL) //Go to the end of the list
		{
			q = q->next; 
		}
		q->next = p; //link the node together
	}
	return p;
}


NODE* insertAfter(LIST &list, STUDENT student,NODE* q)
{
	NODE* p = createNode(student);
	if (p != NULL)
	{
		p->next = q->next;
		q->next = p;
	}
	return p;
}


//Ask for the total number of student
void askforHowManyStudent()
{
	printf("How many student you want to enter: ");
}


//Count the node created by the function
int countNodeHasCreated(LIST list) /*if the count == numberOfStudent then it's fine else PANIC */
{
	int count = 0;
	NODE* p = list.head;
	while (p != NULL)
	{
		count += 1;
		p = p->next;
	}
	return count;
}


//Print all the Node
void displayTheNode(LIST list)
{
	NODE* p = list.head;
	while (p != NULL)
	{
		printf("Student name: %s\n", p->info.name);
		printf("ID: %d\n", p->info.ID);
		printf("- Math point: %.2f\n", p->info.mathPoint);
		printf("- English point: %.2f\n", p->info.englishPoint);
		printf("- Physics point: %.2f\n", p->info.physicsPoint);
		printf("- Average point: %.2f\n",p->info.averagePoint);
		printf("\n");
		p = p->next;
	}
}


//Ask for student information and create a NODE and added it into a list.
void askforStudentInformation(STUDENT &student , LIST &list, int numberOfStudent)
{
	for (int i = 1; i <= numberOfStudent; i++)
	{
		printf("Your number [%d] student\n", i);
		printf("Please enter student ID: ");
		scanf_s("%d", &student.ID);
		while (getchar() != '\n');
		printf("Please enter student name: ");
		gets_s(student.name);
		printf("- Math point: ");
		scanf_s("%f", &student.mathPoint);
		printf("- English point: ");
		scanf_s("%f", &student.englishPoint);
		printf("- Physics point: ");
		scanf_s("%f", &student.physicsPoint);
		printf("\n");
		createNode(student);
		insertHead(list ,student);
	}
}


//Find Max in List --- DO IT AGAIN --- WRONG...
int findMaxInList(LIST list,int numberOfStudent)
{
	int maxPoint = 0;
	NODE* p = list.head;
	if (p != NULL)
	{
		for (int i = 0; i < numberOfStudent; i++)
		{
			if (p->info.englishPoint > maxPoint) //If the	
			{
				maxPoint = p->info.englishPoint;
			}
			p->info.englishPoint = p->next->info.englishPoint;
		}
	}
	return maxPoint;
}


int findMinInList(LIST list, int numberOfStudent)
{
	int minPoint = 0;
	NODE* p = list.head;
	if (p != NULL)
	{
		for (int i = 0; i < numberOfStudent; i++)
		{
			if (p->info.englishPoint < minPoint)
			{
				minPoint = p->info.englishPoint;
			}
			p->info.englishPoint = p->next->info.englishPoint;
		}
	}
	return minPoint;
}


float findTheAveragePoint(LIST list, int numberOfStudent)
{
	NODE* p = list.head;
	if (p != NULL)
	{
		for(int i =0;i <numberOfStudent; i++)
		{
			p->info.averagePoint = (p->info.englishPoint + p->info.mathPoint + p->info.physicsPoint)/3;
			p->info.averagePoint = p->next->info.averagePoint;
		}
		
	}
	return p->info.averagePoint;
}


void printALine()
{
	printf("\n------------------------------------------------\n");
}


void askTheUserInsertLast(LIST &list, STUDENT &student)
{
	printf("Insert to the last of the list\n");
	printf("Please input your data\n\n");
	printALine();
	printf("Please enter student ID: ");
	scanf_s("%d", &student.ID);
	while (getchar() != '\n');
	printf("Please enter student name: ");
	gets_s(student.name);
	printf("- Math point: ");
	scanf_s("%f", &student.mathPoint);
	printf("- English point: ");
	scanf_s("%f", &student.englishPoint);
	printf("- Physics point: ");
	scanf_s("%f", &student.physicsPoint);
	printf("\n");
	NODE* node = createNode(student);
	insertLast(list, student, node);
}
//-----------------------------------FUNCTION------------------------------