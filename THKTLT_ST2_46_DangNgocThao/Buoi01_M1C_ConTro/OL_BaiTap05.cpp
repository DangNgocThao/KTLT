#include "stdio.h"
#include "conio.h"
void nhapSoNguyen(int &x)
{
	printf("\nNhap so nguyen: ");
	scanf("%d", &x);
}
float tinh3SoNguyen(int a, int b, int c)
{
	try
	{
		float t;
		if (a - b == 0)
			throw 101;
		else
		{
			t = (float)c / (a - b);
			return t;
		}
	}
	catch (int ErrorCode)
	{
		if (ErrorCode == 101)
		{
			printf("\nLoi %d: Chia cho 0", ErrorCode);
			return 0;
		}
	}
}
void main()
{
	int a, b, c;
	nhapSoNguyen(a);
	nhapSoNguyen(b);
	nhapSoNguyen(c);
	float t = tinh3SoNguyen(a, b, c);
	if (t != 0)
		printf("\n%d / (%d - %d) = %.2f", c, a, b, t);
	getch();
}