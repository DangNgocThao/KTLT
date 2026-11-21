#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAXSIZE 100
void nhapSoNguyen(int &x)
{
		printf("\nNhap so nguyen: ");
		scanf("%d", &x);
}
void nhapMang1C_SoNguyen_ConTro(int * &a, int &n)
{
	nhapSoNguyen(n);
	a = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("\na[%d] = ", i); 
		scanf("%d", &*(a + i));
	}
}
void taoMang1C_SoNguyen_ConTro(int * &a, int &n)
{
	nhapSoNguyen(n);
	a = (int *)malloc(n*sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = rand() % 199 - 99;
	}
}
void xuatMang1C_SoNguyen_ConTro(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d", *(a + i));
	}
}
void main()
{
	int n;
	int *a = new int;
	taoMang1C_SoNguyen_ConTro(a, n);
	printf("\nNoi dung cua mang la: ");
	xuatMang1C_SoNguyen_ConTro(a, n);
	getch();
}