#include "stdio.h"
#include "conio.h"
void tinh3SoNguyen(int a, int b, int c);
void main()
{
	int a, b, c;
	printf("\nNhap 3 so nguyen can tinh: ");
	scanf("%d %d %d", &a, &b, &c);
	tinh3SoNguyen(a, b, c);
	getch();
}
void tinh3SoNguyen(int a, int b, int c)
{
	try
	{
		if (a - b == 0)
			throw 100;
		else
			printf("\n%d/(%d-%d) = %.3f", c, a, b, (float)c / (a - b));
	}
	catch (int num)
	{
		printf("\nChia cho 0");
	}
}