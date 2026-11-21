#include "stdio.h"
#include "conio.h"
void nhapSoNguyen(int &x)
{
	printf("\nNhap so nguyen: ");
	scanf("%d", &x);
}
float tinhThuong2SoNguyen(int x, int y)
{
	try
	{
		float thuong;
		if (y == 0)
			throw 101;
		else
		{
			thuong = (float)x / y;
			return thuong;
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
	int a, b;
	nhapSoNguyen(a);
	nhapSoNguyen(b);
	float th = tinhThuong2SoNguyen(a, b);
	if (th != 0)
		printf("\n%d / %d = %.2f", a, b, th);
	getch();
}