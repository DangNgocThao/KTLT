#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
int tinhx(int n);
int tinhy(int n);
void main()
{
	int n;
	do
	{
		printf("\nNhap thu hang can tinh: ");
		scanf("%d", &n);
	} while (n < 1);
	printf("\nXn = %d", tinhx(n));
	printf("\nYn = %d", tinhy(n));
	getch();
}
int tinhx(int n)
{
	if (n == 0)
		return 1;
	else
		return tinhx(n - 1) + tinhy(n - 1);
}
int tinhy(int n)
{
	if (n == 0)
		return 0;
	else
		return 3 * tinhx(n - 1) + 2 * tinhy(n - 1);
}