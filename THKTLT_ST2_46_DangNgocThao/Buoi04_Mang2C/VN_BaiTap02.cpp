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
	printf("\n2. Sap xep duong chep phu tang dan");
	printf("\n3. Sap xep duong chep phu giam dan");
	printf("\n4. Sap xep cac dong co chi so le thi tang dan con cac dong co chi so chan thi giam dan");
	printf("\n5. Sap xep cac cot co chi so le thi giam dan con cac cot co chi so chan thi tang dan");
	printf("\n6. Sap xep duong cheo chinh va cac duong cheo song song voi duong cheo chinh tang dan");
	printf("\n7. Sap xep ca phan tu chan nam o cac dong dau mang, cac phan tu le nam o cac dong cuoi mang");
	printf("\n8. kiem tra ma tran co doi xung qua duong cheo chinh");
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
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void sxCheoPhuTang(int a[][MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][n - 1 - i] > a[j][n - 1 - j])
				swap(a[i][n - 1 - i], a[j][n - 1 - j]);
		}
	}
}
void sxCheoPhuGiam(int a[][MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][n - 1 - i] < a[j][n - 1 - j])
				swap(a[i][n - 1 - i], a[j][n - 1 - j]);
		}
	}
}
void sx1DongTang(int a[][MAX], int n, int d)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[d][i] > a[d][j])
				swap(a[d][i], a[d][j]);
		}
	}
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
void sx1CotGiam(int a[][MAX], int n, int c)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][c] < a[j][c])
				swap(a[i][c], a[j][c]);
		}
	}
}
void sxDongLeTangChanGiam(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			sx1DongGiam(a, n, i);
		else
			sx1DongTang(a, n, i);
	}
}
void sxCotLeGiamChanTang(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			sx1CotTang(a, n, i);
		else
			sx1CotGiam(a, n, i);
	}
}
void sx1DuongSSCheoChinhTang(int a[][MAX], int n, int d, int c)
{
	for (int i = d, j = c; i < n - 1 && j < n - 1; i++, j++)
	{
		for (int k = i + 1, l = j + 1; k < n && l < n; k++, l++)
		{
			if (a[i][j] > a[k][l])
				swap(a[i][j], a[k][l]);
		}
	}
}
void sxCacDuongSSCheoChinhTang(int a[][MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		sx1DuongSSCheoChinhTang(a, n, 0, i);
		sx1DuongSSCheoChinhTang(a, n, i, 0);
	}
}
void sxChanDauLeCuoi(int a[][MAX], int n)
{
	for (int i = 0; i < n * n - 1; i++)
	{
		for (int j = i + 1; j < n * n; j++)
		{
			if (a[i / n][i % n] % 2 != 0 && a[j / n][j % n] % 2 == 0)
				swap(a[i / n][i % n], a[j / n][j % n]);
		}
	}
}
int ktDoixung(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][j] != a[j][i])
				return 0;
		}
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
		case 2:
		{
			sxCheoPhuTang(a, n);
			printf("\nNoi dung ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		case 3:
		{
			sxCheoPhuGiam(a, n);
			printf("\nNoi dung ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		case 4:
		{
			sxDongLeTangChanGiam(a, n);
			printf("\nNoi dung ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		case 5:
		{
			sxCotLeGiamChanTang(a, n);
			printf("\nNoi dung ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		case 6:
		{
			sxCacDuongSSCheoChinhTang(a, n);
			printf("\nNoi dung ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		case 7:
		{
			sxChanDauLeCuoi(a, n);
			printf("\nNoi dung ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		case 8:
		{
			int kq = ktDoixung(a, n);
			if (kq == 1)
				printf("\nMa tran doi xung qua duong cheo chinh");
			else
				printf("\nMa tran khong doi xung qua duong cheo chinh");
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}
