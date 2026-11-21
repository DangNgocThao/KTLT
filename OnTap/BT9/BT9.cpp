#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
int tongMang(int a[], int n)
{
	if (n == 1)
		return a[0];
	else
		return a[n - 1] + tongMang(a, n - 1);
}
int tichMang(int a[], int n)
{
	if (n == 1)
		return a[0];
	else
		return a[n - 1] * tichMang(a, n - 1);
}
int timMin(int a[], int n)
{
	if (n == 1)
		return a[0];
	if (timMin(a, n - 1) < a[n - 1])
		return timMin(a, n - 1);
	else
		return a[n - 1];
}
int demDuong(int a[], int n)
{
	if (n == 1)
		return a[0] > 0 ? 1 : 0;
	else
		return a[n - 1] > 0 ? 1 + demDuong(a, n - 1) : demDuong(a, n - 1);
}
int tongLe(int a[], int n)
{
	if (n == 1)
		return a[0] % 2 != 0 ? a[0] : 0;
	else
		return a[n - 1] % 2 != 0 ? a[n - 1] + tongLe(a, n - 1) : 0;
}
int timMax(int a[], int n)
{
	if (n == 1)
		return a[0];
	if (timMax(a, n - 1) > a[n - 1])
		return timMax(a, n - 1);
	else
		return a[n - 1];
}
int tinhf7(int n)
{
	if (n == 1 || n == 0)
		return 2;
	else
		return 2 * tinhf7(n - 1) * tinhf7(n - 2);
}
int tinhf8(int n)
{
	if (n == 1 || n == 0)
		return n == 0 ? 1 : 2;
	else
		return 2 * tinhf8(n - 1) + 4 * tinhf8(n - 2);
}
int tinhf9(int n)
{
	if (n == 1 || n == 0)
		return n == 0 ? 4 : 2;
	else
		return tinhf9(n - 1) + 3 * tinhf9(n - 2);
}
int tinhf10(int n)
{
	if (n == 0)
		return 1;
	else
		return 2 * tinhf10(n / 2);
}
int tinhf11(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return tinhf11(n - 1) + tinhf11(n - 2);
}
int tinhf12(int n)
{
	if (n == 0)
		return 4;
	else
		return 2 * n * tinhf12(n - 1);
}
int giaiThua(int n)
{
	int t = 1;
	for (int i = 1; i <= n; i++)
	{
		t = t * i;
	}
	return t;
}
float tinhS13(int n)
{
	if (n == 1)
		return 4 - 2 * sqrt(3);
	else
		return tinhS13(n - 1) + (n * giaiThua(n + 1)) / ((n + 1) + sqrt(n + 2));
}
float tinhS14(int n)
{
	if (n == 1)
		return (1 + sqrt(3)) / (2 + sqrt(6));
	else
		return tinhS14(n - 1) + (n + sqrt(n + n + 1)) / ((n + 1) + sqrt(giaiThua(n + 2)));
}
void main()
{

	getch();
}