#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100
void menu();
void thucThi();
void nhapMTV(int a[][MAX], int& n);
void taoMTV(int a[][MAX], int& n);
void xuatMTV(int a[][MAX], int n);
int ktPhanTuCucTri(int a[][MAX], int n, int d, int c);
void xuatCucTri(int a[][MAX], int n);
void sx1CotTang(int a[][MAX], int n, int c);
void sx1CotGiam(int a[][MAX], int n, int c);
void sxCotLeTangChanGiam(int a[][MAX], int n);
void sx1DuongCheoSSCheoChinhTang(int a[][MAX], int n, int k);
void sxDuongCheoSSCheoChinhTang(int a[][MAX], int n);
int soLanXuatHienx(int a[][MAX], int n, int x);
int kt1CotGiam(int a[][MAX], int n, int c);
int ktCotGiam(int a[][MAX], int n);
void chiSoDongToanChan(int a[][MAX], int n);
void xuatDuongSSCheoChinh(int a[][MAX], int n);
int demSoLanXuatHien(int a[][MAX], int n, int x);
int soXuatHienNhieuNhat(int a[][MAX], int n);
void tachChuSo(int n, int b[]);
void cacChuSoXuatHienNhieuNhat(int a[][MAX], int n);
void xuatDuongSSCheoPhu(int a[][MAX], int n);
void hoanVi(int& a, int& b);
void doiCot(int a[][MAX], int n, int c1, int c2);
void main()
{
	thucThi();
}
void thucThi()
{
	int a[MAX][MAX];
	int n, cn;
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
			printf("\nPhan tu trong ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		case 2:
		{
			printf("\nPhan tu trong ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		case 3:
		{
			printf("\nCac phan tu cuc tri trong ma tran:\n");
			xuatCucTri(a, n);
			break;
		}
		case 4:
		{
			sxCotLeTangChanGiam(a, n);
			printf("\nMa tran sau khi sap xep:\n");
			xuatMTV(a, n);
			break;
		}
		case 5:
		{
			sxDuongCheoSSCheoChinhTang(a, n);
			printf("\nMa tran sau khi sap xep:\n");
			xuatMTV(a, n);
			break;
		}
		case 6:
		{
			if (ktCotGiam(a, n) == 1)
				printf("\nMa tran giam dan theo tung cot");
			else
				printf("\nMa tran khong giam dan theo tung cot");
			break;
		}
		case 7:
		{
			chiSoDongToanChan(a, n);
			break;
		}
		case 8:
		{
			printf("\nCac duong cheo song song voi cheo chinh:\n");
			xuatDuongSSCheoChinh(a, n);
			break;
		}
		case 9:
		{
			printf("\nGia tri xuat hien nhieu nhat trong ma tran: %d", soXuatHienNhieuNhat(a, n));
			break;
		}
		case 10:
		{
			cacChuSoXuatHienNhieuNhat(a, n);
			break;
		}
		case 11:
		{
			printf("\nCac duong cheo song song voi cheo phu:\n");
			xuatDuongSSCheoPhu(a, n);
			break;
		}
		case 12:
		{
			int c1, c2;
			do
			{
				printf("\nNhap hai cot can hoan vi: ");
				scanf("%d %d", &c1, &c2);
			} while (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n);
			doiCot(a, n, c1, c2);
			printf("\nPhan tu trong ma tran:\n");
			xuatMTV(a, n);
			break;
		}
		default:
			break;
		}
	} while (1);
}
void menu()
{
	printf("\nMENU");
	printf("\n0. Thoat");
	printf("\n1. Tao mang hai chieu");
	printf("\n2. Xuat mang hai chieu");
	printf("\n3. Xuat cac phan tu cuc tri cua ma tran");
	printf("\n4. Sap xep ma tran sao cho: cac cot co chi so le thi tang dan, con cac cot co chi so chan thi giam dan");
	printf("\n5. Sap xep cho cac duong cheo song song voi duong cheo chinh va ca duong cheo chinh tang dan");
	printf("\n6. Kiem tra cac gia tri trong ma tran co giam dan theo tung cot khong");
	printf("\n7. Liet ke chi so cac dong chua toan gia tri chan");
	printf("\n8. Xuat cac duong cheo song song voi duong cheo chinh");
	printf("\n9. Tim gia tri xuat hien nhieu nhat trong ma tran");
	printf("\n10. Tim cac chu so xuat hien nhieu nhat trong ma tran");
	printf("\n11. Xuat cac duong cheo song song duong cheo phu");
	printf("\n12. Hoan vi hai cot i va j trong ma tran");
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
			a[i][j] = rand() % 101 - 50;
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
		printf("\n\n");
	}
}
int ktPhanTuCucTri(int a[][MAX], int n, int d, int c)
{
	int CucDai = 1, CucTieu = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (d + i >= 0 && c + j >= 0 && d + i < n && c + j < n && !(i == 0 && j == 0))
			{
				if (a[d][c] <= a[d + i][c + j])
				{
					CucDai = 0;
				}
				if (a[d][c] >= a[d + i][c + j])
				{
					CucTieu = 0;
				}
				if (CucDai == 0 && CucTieu == 0)
					return 0;
			}
		}
	}
	return 1;
}
void xuatCucTri(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPhanTuCucTri(a, n, i, j) == 1)
				printf("%5d", a[i][j]);
			else
				printf("     ");
		}
		printf("\n\n");
	}
}
void sx1CotTang(int a[][MAX], int n, int c)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][c] > a[j][c])
				hoanVi(a[i][c], a[j][c]);
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
				hoanVi(a[i][c], a[j][c]);
		}
	}
}
void sxCotLeTangChanGiam(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			sx1CotGiam(a, n, i);
		else
			sx1CotTang(a, n, i);
	}
}
void sx1DuongCheoSSCheoChinhTang(int a[][MAX], int n, int k)
{
	if (k >= 0)
	{
		for (int i = 0; i + k < n - 1; i++)
		{
			for (int j = i + 1; j + k < n; j++)
			{
				if (a[k + i][i] > a[k + j][j])
					hoanVi(a[k + i][i], a[k + j][j]);
			}
		}
	}
	else
	{
		k = -k;
		for (int i = 0; i + k < n - 1; i++)
		{
			for (int j = i + 1; j + k < n; j++)
			{
				if (a[i][k + i] > a[j][k + j])
					hoanVi(a[i][k + i], a[j][k + j]);
			}
		}
	}
}
void sxDuongCheoSSCheoChinhTang(int a[][MAX], int n)
{
	for (int i = 2-n; i < n-1; i++)
	{
		sx1DuongCheoSSCheoChinhTang(a, n, i);
	}
}
int soLanXuatHienx(int a[][MAX], int n, int x)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == x)
				d++;
		}
	}
	return d;
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
void chiSoDongToanChan(int a[][MAX], int n)
{
	int kt, d = 0;
	for (int i = 0; i < n; i++)
	{
		kt = 1;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				kt = 0;
				break;
			}
		}
		if (kt == 1)
		{
			if (d == 0)
				printf("\nChi so cac dong chua toan gia tri chan: ");
			printf("%5d", i);
			d++;
		}			
	}
	if (d == 0)
		printf("\nKhong co dong nao chua toan gia tri chan");
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
		printf("\n\n");
	}
}
int demSoLanXuatHien(int a[][MAX], int n, int x)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == x)
				d++;
		}
	}
	return d;
}
int soXuatHienNhieuNhat(int a[][MAX], int n)
{
	int max = demSoLanXuatHien(a, n, a[0][0]);
	int gt = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (demSoLanXuatHien(a, n, a[i][j]) > max)
			{
				max = demSoLanXuatHien(a, n, a[i][j]);
				gt = a[i][j];
			}
		}
	}
	return gt;
}
void tachChuSo(int n, int b[])
{
	int chuSo;
	n = abs(n);
	do
	{
		chuSo = n % 10;
		b[chuSo]++;
		n /= 10;
	} while (n > 0);
}
void cacChuSoXuatHienNhieuNhat(int a[][MAX], int n)
{
	int b[10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tachChuSo(a[i][j], b);
		}
	}
	int chuSoXuatHienNhieuNhat = 0;
	for (int i = 0; i < 10; i++)
	{
		if (b[chuSoXuatHienNhieuNhat] < b[i])
		{
			chuSoXuatHienNhieuNhat = i;
		}
	}
	printf("\nCac chu so xuat hien nhieu nhat: ");
	for (int i = 0; i < 10; i++)
	{
		if (b[chuSoXuatHienNhieuNhat] == b[i])
		{
			printf("%5d", i);
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
		printf("\n\n");
	}
}
void hoanVi(int& a, int& b)
{
	int t = a; a = b; b = t;
}
void doiCot(int a[][MAX], int n, int c1, int c2)
{
	for (int i = 0; i < n; i++)
	{
		hoanVi(a[i][c1], a[i][c2]);
	}
}