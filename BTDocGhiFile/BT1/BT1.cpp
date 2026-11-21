#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
void menu();
void nhapM1C(int a[], int& n);
void xuatM1C(int a[], int n);
void ghiFile(int a[], int n);
void docFile(int a[], int& n);
void main()
{
	int a[50], n, c;
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
			ghiFile(a, n);
			break;
		}
		case 4:
		{
			docFile(a,n);
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
	printf("\n3. Ghi file");
	printf("\n4. Doc file");
}
void nhapM1C(int a[], int& n)
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
void ghiFile(int a[], int n)
{
	FILE* f;
	f = fopen("input.txt", "wt");
	fprintf(f, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d\n", a[i]);
	}
	fclose(f);
}
void docFile(int a[], int& n)
{
	FILE* f;
	f = fopen("input.txt", "rt");
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d\n", &a[i]);
	}
	fclose(f);
}