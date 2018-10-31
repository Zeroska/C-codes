#include <stdio.h>
#include <conio.h>

//reverse an array 

void reverseArray(int testArray[])
{
	int a = sizeof(testArray);
	int arrayValue = ((sizeof(testArray)) / (sizeof(testArray[0])));
	printf("%d\n",a);
	int b = sizeof(testArray[0]);
	printf("%d [0]\n", b);
	printf("arrayValue: %d\n",arrayValue);
	for (int i  = 0; i < 5/2; i++)
	{
		int temp = testArray[i];
		testArray[i] = testArray[5 - i - 1];
		testArray[5 - i - 1] = temp;
	}
}

int main()
{
	int array[5] = { 1,1,2,3,4 };
	reverseArray(array);
	for (int i = 0; i < 5; i++)
	{
		printf("%4d", *(array+i));
	}
	_getch();
}