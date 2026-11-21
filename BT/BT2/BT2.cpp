#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#define MAX 1000
void menu();
void nhapM1C(int a[], int &n);
void xuatM1C(int a[], int n);
void them1PhanTu(int a[], int& n, int x, int vt);
void xoa1PhanTu(int a[], int& n, int vt);
void main()
{
	int c, n, a[MAX];
	do
	{
		menu();
		printf("\nHay chon mot chuc nang cua chuong trinh: ");
		scanf("%d", &c);
		switch (c)
		{
			case 0:
			{
				exit(1);
				break;
			}
			case 1:
			{
				nhapM1C(a, n);
				break;
			}
			case 2:
			{
				xuatM1C(a, n);
				break;
			}
			case 3:
			{
				int x, vt;
				printf("\nNhap gia tri can them: ");
				scanf("%d", &x);
				printf("\nVi tri can them: ");
				scanf("%d", &vt);
				them1PhanTu(a, n, x, vt);
				xuatM1C(a, n);
				break;
			}
			case 4:
			{
				int vt;
				printf("\nVi tri can xoa: ");
				scanf("%d", &vt);
				xoa1PhanTu(a, n, vt);
				xuatM1C(a, n);
				break;
			}
		}
	} while (1);
	getch();
}
void menu()
{
	printf("\nMENU");
	printf("\n0. Thoat");
	printf("\n1. Khoi tao mang");
	printf("\n2. Xuat noi dung cua mang");
	printf("\n3. Them mot phan tu vao mang");
	printf("\n4. Xoa mot phan tu vao mang");
}
void nhapM1C(int a[], int &n)
{
	do
	{
		printf("\nNhap so phan tu trong mang: ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		printf("\na[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void xuatM1C(int a[], int n)
{
	printf("\nNoi dung trong mang: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}
void them1PhanTu(int a[], int& n, int x, int vt)
{
	try
	{
		if (vt<0 || vt>n)
			throw 100;
		else
		{
			for (int i = n; i > vt; i--)
			{
				a[i] = a[i - 1];
			}
			a[vt] = x;
			n++;
		}
	}
	catch (int num)
	{
		printf("\nVi tri them vao khong phu hop");
	}
}
void xoa1PhanTu(int a[], int& n, int vt)
{
	try
	{
		if (vt<0 || vt>=n)
			throw 100;
		else
		{
			for (int i = vt; i < n - 1; i++)
			{
				a[i] = a[i + 1];
			}
			n--;
		}
	}
	catch (int num)
	{
		printf("\nVi tri xoa khong phu hop");
	}
}