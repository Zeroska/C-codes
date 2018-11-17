#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

void decode1(int *xp, int *yp, int *zp)
{
	int a = *yp;
	printf("a value: %d\n", a);
	int b = *zp;
	printf("b value: %d\n", b);
	int c = *xp;
	printf("c value: %d\n", c);
	*yp = c;
	printf("*yp value: %d\n",*yp);
	*zp = a;
	printf("*zp value: %d\n",*zp);
	*xp = b;
	printf("*xp value: %d\n",*xp);
}

int main()
{
	int *xp,*yp,*zp,a = 6,b = 5, c = 9;
	xp = &a;
	yp = &b;
	zp = &c;
	decode1(xp, yp, zp);
	_getch();
}