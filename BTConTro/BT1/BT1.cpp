#include "stdio.h"
#include "conio.h"
void main()
{
	int a, b, *pa, *pb;
	printf("\nNhap a b: ");
	scanf("%d %d", &a, &b);
	pa = &a;
	pb = &b;
	printf("\na = %d, b = %d", *pa, *pb);
	getch();
}