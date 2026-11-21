#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
int tinhA(int n)
{
	if (n == 1)
		return 1;
	else
	{
		int s = 0;
		for (int i = 1; i < n; i++)
		{
			s += tinhA(i);
		}
		return n * s;
	}
}
int tinhx(int n)
{
	if (n == 1 || n == 0)
		return n == 0 ? 1 : 2;
	else
	{
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			s += (n - i) * tinhx(i);
		}
		return s;
	}
}
void main()
{
	int n;
	do
	{
		printf("\nNhap thu hang can tinh: ");
		scanf("%d", &n);
	} while (n < 1);
	printf("\nAn = %d", tinhA(n));
	printf("\nXn = %d", tinhx(n));
	getch();
}