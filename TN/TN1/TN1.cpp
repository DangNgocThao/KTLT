#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void taoM1C(double* &a, int &n)
{
	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", &n);
	} while (n <= 0);
	a = (double *)malloc(n * sizeof(double));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = rand() * 199.0 / RAND_MAX - 99;
	}
}
void xuatM1C(double* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5.2lf	", *(a + i));
	}
}
void xuatDiaChi(double* a, int n)
{
	printf("\nDia chi lan luot cua cac phan tu: ");
	for (int i = 0; i < n; i++)
	{
		printf("%10X", a + i);
	}
}
double chanMin(double* a, int n)
{
	int vtc = -1;
	for (int i = 0; i < n; i++)
	{
		if ((int)*(a + i) % 2 == 0)
		{
			vtc = i;
			break;
		}
	}
	if (vtc == -1)
		return -1;
	double min = *(a + vtc);
	for (int i = vtc; i < n; i++)
	{
		if (*(a + i) < min && (int)*(a + i) % 2 == 0)
			min = *(a + i);
	}
	return min;
}
void main()
{
	double* a = new double;
	int n;
	taoM1C(a, n);
	printf("\nCac phan tu trong mang: ");
	xuatM1C(a, n);
	xuatDiaChi(a, n);
	double kq = chanMin(a, n);
	if (kq == -1)
		printf("\nKhong co so chan trong mang");
	else
		printf("\nSo chan nho nhat trong mang: %.2lf", kq);
	getch();
}