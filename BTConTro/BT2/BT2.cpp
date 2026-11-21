#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
void menu();
void nhapM1C(int a[], int& n);
void xuatM1C(int a[], int n);
void maxM1C(int a[], int n);
void minM1C(int a[], int n);
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
			maxM1C(a, n);
			break;
		}
		case 4:
		{
			minM1C(a, n);
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
	printf("\n1. Nhap noi dung cua mang");
	printf("\n2. Xuat noi dung cua mang");
	printf("\n3. Tim max");
	printf("\n4. Tim min");
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
		printf("%d\t", a[i]);
}
void maxM1C(int a[], int n)
{
	int *max = a;
	for (int i = 0; i < n; i++)
		if (*max < *(max + i))
			*max = *(max + i);
	printf("\nMax = %d, dia chi Max: %X", *max, max);
}
void minM1C(int a[], int n)
{
	int *min = a;
	for (int i = 0; i < n; i++)
		if (*min > *(min + i))
			*min = *(min + i);
	printf("\nMin = %d, dia chi Min: %X", *min, min);
}