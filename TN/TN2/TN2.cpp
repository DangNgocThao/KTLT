#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void taoMTVuong(int a[][MAX], int &n)
{
	do
	{
		printf("\nNhap cap cua ma tran: ");
		scanf("%d", &n);
	} while (n <= 0);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 199 - 99;
		}
	}
}
void xuatMTVuong(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void sx1DongChanTang(int a[][MAX], int n, int d)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[d][i] > a[d][j] && a[d][i] % 2 == 0 & a[d][j] % 2 == 0)
				swap(a[d][i], a[d][j]);
		}
	}
}
void sxDongChanTang(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		sx1DongChanTang(a, n, i);
	}
}
void sxDuongCheoPhuGiam(int a[][MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[vtm][n - 1 - vtm] < a[j][n - 1 - j])
				vtm = j;
			swap(a[i][n - 1 - i], a[vtm][n - 1 - vtm]);
		}
	}
}
void main()
{
	int a[MAX][MAX], n;
	taoMTVuong(a, n);
	printf("\nNoi dung ma tran:\n");
	xuatMTVuong(a, n);
	sxDongChanTang(a, n);
	printf("\nNoi dung ma tran dong sap xep chan tang\n");
	xuatMTVuong(a, n);
	sxDuongCheoPhuGiam(a, n);
	printf("\nNoi dung ma tran sap xep duong cheo phu giam\n");
	xuatMTVuong(a, n);
	getch();
}