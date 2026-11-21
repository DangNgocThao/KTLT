#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#define MAX 100
void menu()
{
	printf("\nMENU");
	printf("\n0. Thoat");
	printf("\n1. Tao va xuat ma tran vuong a chua cac phan tu ngau nhien");
}
void nhapMTV(int a[][MAX], int& n)
{
	do
	{
		printf("\nNhap cap cua ma tran: ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("\na[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}
void taoMTV(int a[][MAX], int& n)
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
void xuatMTV(int a[][MAX], int n)
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
int tongCC(int a[][MAX], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t += a[i][i];
	}
	return t;
}
int tongCP(int a[][MAX], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t += a[i][n - 1 - i];
	}
	return t;
}
int tongTGT(int a[][MAX], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			t += a[i][j];
	}
	return t;
}
int tongTGD(int a[][MAX], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			t += a[i][j];
	}
	return t;
}
void xuatDuongSSCheoChinh(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && (i != 0 || j != n - 1) && (i != n - 1 || j != 0))
				printf("%5d", a[i][j]);
			else
				printf("     ");
		}
	}
}
void xuatDuongSSCheoPhu(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j != n - 1 && (i != 0 || j != 0) && (i != n - 1 || j != n - 1))
				printf("%5d", a[i][j]);
			else
				printf("     ");
		}
	}
}
int ktPTCucDai(int a[][MAX], int n, int d, int c)
{
	int cucDai = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (d + i >= 0 && c + j >= 0 && d + i < n && c + j < n && !(i == 0 && j == 0))
			{
				if (a[d][c] <= a[d + i][c + j])
				{
					cucDai = 0;
				}
				if (cucDai == 0)
					return 0;
			}
		}
	}
	return 1;
}
int ktPTCucTieu(int a[][MAX], int n, int d, int c)
{
	int cucTieu = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (d + i >= 0 && c + j >= 0 && d + i < n && c + j < n && !(i == 0 && j == 0))
			{
				if (a[d][c] >= a[d + i][c + j])
				{
					cucTieu = 0;
				}
				if (cucTieu == 0)
					return 0;
			}
		}
	}
	return 1;
}
int ktPTHoangHau(int a[][MAX], int n, int d, int c)
{
	int x = a[d][c];
	for (int i = 0; i < n; i++)
	{
		if (a[d][i] > x)
		{
			return 0;
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (a[j][c] > x)
		{
			return 0;
		}
	}
	int d1 = d + 1;
	int c1 = c + 1;
	while (c1 + 1 < n && d1 < n)
	{
		if (a[c1][d1] > x)
			return 0;
		c1++;
		d1++;
	}
	d1 = d - 1;
	c1 = c - 1;
	while (c1 - 1 >= 0 && d1 >= 0)
	{
		if (a[c1][d1] > x)
			return 0;
		c1--;
		d1--;
	}
	d1 = d + 1;
	c1 = c - 1;
	while (c1 - 1 >= 0 && d1 < n)
	{
		if (a[c1][d1] > x)
			return 0;
		c1--;
		d1++;
	}
	d1 = d - 1;
	c1 = c + 1;
	while (c1 + 1 < n && d1 >= 0)
	{
		if (a[c1][d1] > x)
			return 0;
		c1++;
		d1--;
	}
	return 1;
}
int maxDongk(int a[][MAX], int n, int k)
{
	int max = a[k][0];
	for (int i = 0; i < n; i++)
	{
		if (a[k][i] > max)
			max = a[k][i];
	}
	return max;
}
int minDongk(int a[][MAX], int n, int k)
{
	int min = a[k][0];
	for (int i = 0; i < n; i++)
	{
		if (a[k][i] < min)
			min = a[k][i];
	}
	return min;
}
int maxCotk(int a[][MAX], int n, int k)
{
	int max = a[0][k];
	for (int i = 0; i < n; i++)
	{
		if (a[i][k] > max)
			max = a[i][k];
	}
	return max;
}
int minCotk(int a[][MAX], int n, int k)
{
	int min = a[0][k];
	for (int i = 0; i < n; i++)
	{
		if (a[i][k] < min)
			min = a[i][k];
	}
	return min;
}
int ktPTYenNgua(int a[][MAX], int n, int d, int c)
{
	if ((maxDongk(a, d, n) == a[d][c] && minCotk(a, n, c) == a[d][c]) || (minDongk(a, d, n) == a[d][c] && maxCotk(a, n, c) == a[d][c]))
		return 1;
	else
		return 0;
}
void xuatCucDai(int a[][MAX], int n)
{
	printf("\nCac phan tu cuc dai trong ma tran: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTCucDai(a, n, i, j) == 1)
				printf("%5d", a[i][j]);
		}
	}
}
void xuatCucTieu(int a[][MAX], int n)
{
	printf("\nCac phan tu cuc tieu trong ma tran: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTCucTieu(a, n, i, j) == 1)
				printf("%5d", a[i][j]);
		}
	}
}
void xuatHoangHau(int a[][MAX], int n)
{
	printf("\nCac phan tu hoang hau trong ma tran: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTHoangHau(a, n, i, j) == 1)
				printf("%5d", a[i][j]);
		}
	}
}
void xuatYenNgua(int a[][MAX], int n)
{
	printf("\nCac phan tu yen ngua trong ma tran: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTYenNgua(a, n, i, j) == 1)
				printf("%5d", a[i][j]);
		}
	}
}
int cucDaiMax(int a[][MAX], int n)
{
	int vtd = -1, vtc = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTCucDai(a,n,i,j) == 1)
			{
				vtd = i;
				vtc = j;
				break;
			}
		}
	}
	if (vtd == -1)
		return 0;
	int max = a[vtd][vtc];
	for (int i = vtd; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTCucDai(a, n, i, j) == 1 && a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
int cucTieuMax(int a[][MAX], int n)
{
	int vtd = -1, vtc = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTCucTieu(a, n, i, j) == 1)
			{
				vtd = i;
				vtc = j;
				break;
			}
		}
	}
	if (vtd == -1)
		return 0;
	int max = a[vtd][vtc];
	for (int i = vtd; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTCucTieu(a, n, i, j) == 1 && a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
int hoangHauMax(int a[][MAX], int n)
{
	int vtd = -1, vtc = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTHoangHau(a, n, i, j) == 1)
			{
				vtd = i;
				vtc = j;
				break;
			}
		}
	}
	if (vtd == -1)
		return 0;
	int max = a[vtd][vtc];
	for (int i = vtd; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTHoangHau(a, n, i, j) == 1 && a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
int yenNguaMax(int a[][MAX], int n)
{
	int vtd = -1, vtc = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTYenNgua(a, n, i, j) == 1)
			{
				vtd = i;
				vtc = j;
				break;
			}
		}
	}
	if (vtd == -1)
		return 0;
	int max = a[vtd][vtc];
	for (int i = vtd; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTYenNgua(a, n, i, j) == 1 && a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
int tongMinDongMaxCot(int a[][MAX], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t += minDongk(a, n, i);
		t += maxCotk(a, n, i);
	}
	return t;
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void sxZicZac(int a[][MAX], int n)
{
	for (int i = 0; i < n * n - 1; i++)
	{
		for (int j = i + 1; j < n * n; j++)
		{
			if (a[i / n][i % n] > a[j / n][j % n])
				swap(a[i / n][i % n], a[j / n][j % n]);
		}
	}
}
int kt1CotTang(int a[][MAX], int n, int c)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i][c] >= a[i + 1][c])
			return 0;
	}
	return 1;
}
int kt1DongTang(int a[][MAX], int n, int d)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[d][i] >= a[d][i + 1])
			return 0;
	}
	return 1;
}
int ktZicZacTang(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (kt1CotTang(a, m, j) == 0 || kt1DongTang(a, i, n) == 0)
				return 0;
		}
	}
	return 1;
}
void sx1DongGiam(int a[][MAX], int n, int d)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[d][i] < a[d][j])
				swap(a[d][i], a[d][j]);
		}
	}
}
void sx1CotTang(int a[][MAX], int n, int c)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][c] > a[j][c])
				swap(a[i][c], a[j][c]);
		}
	}
}
void sxCotTang(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		sx1CotTang(a, n, i);
	}
}
void sxDongGiam(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		sx1DongGiam(a, n, i);
	}
}
void sxCheoChinhTang(int a[][MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][i] > a[j][j])
				swap(a[i][i], a[j][j]);
		}
	}
}
void xuatBien(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
				printf("%5d", a[i][j]);
			else
				printf("     ");
		}
		printf("\n");
	}
}
int ktCheoChinhTang(int a[][MAX], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (a[i][i] > a[i + 1][i + 1])
			return 0;
	}
	return 1;
}
int kt1CotGiam(int a[][MAX], int n, int c)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i][c] <= a[i + 1][c])
			return 0;
	}
	return 1;
}
int ktCotGiam(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (kt1CotGiam(a, n, i) == 0)
			return 0;
	}
	return 1;
}
void main()
{
	int a[MAX][MAX];
	int m, n, cn;
	do
	{
		menu();
		printf("\nChon chuc nang: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 0:
		{
			exit(1);
		}
		case 1:
		{
			taoMTV(a, n);
			printf("\nNoi dung ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}
