#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
void menu()
{
	printf("\n0. Thoat");
	printf("\n1. Nhap mang a");
	printf("\n2. Nhap mang b");
	printf("\n3. Tinh va xuat ket qua cac phep chia cua phan tu mang a cho phan tu mang b");
}
void nhapMang1C(int * &a, int &n)
{
	printf("\nNhap so phan tu: ");
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("\na[%d] = ", i); 
		scanf("%d", &*(a + i));
	}
}
void mangaChiaMangb(int* a, int n, int* b, int m)
{
	printf("\nKet qua cac phan tu mang a chia cho cac phan tu mang b: ");
	if (n > m)
	{
		for (int i = 0; i < m; i++)
		{
			if (b[i] == 0)
				printf("%d\t", a[i]);
			else
				printf("%.2f\t", (float)a[i] / b[i]);
		}
		for (int i = m; i < n; i++)
		{
			printf("%d\t", a[i]);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (b[i] == 0)
				printf("%d\t", a[i]);
			else
				printf("%.2f\t", (float)a[i] / b[i]);
		}
		for (int i = n; i < m; i++)
		{
			printf("%d\t", b[i]);
		}
	}
}
void main()
{
	int n, m, cn;
	int* a = new int, * b = new int;
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
			nhapMang1C(a, n);
			break;
		}
		case 2:
		{
			nhapMang1C(b, m);
			break;
		}
		case 3:
		{
			mangaChiaMangb(a, n, b, m);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}