#include <stdio.h>
#include <conio.h>

//Dem so luong chu so nguyen duong.

unsigned int count_the_number_of_N(unsigned int n)
{
	if (n == 0) /*ieu kien dung, cho toi khi n chia toi don vi cuoi cung thi dung, vi hang don vi Ex : 1/10 = 0*/
	{
		return 0; // cung chua biet vi sao nen return 0 or return 1 no idea.
	}
	else
	{
		return 1 + count_the_number_of_N(n / 10); /*neu chia duoc thi +1 vao lan dem, cho toi khi khong chia duoc thi
												  ta so chu so trong so nguyen n do.*/
	}
}

int main()
{
	unsigned int n;
	printf("Please enter your number: ");
	scanf_s("%d",&n);
	printf("the lengh of your number is : %d", count_the_number_of_N(n));
	_getch();
}

