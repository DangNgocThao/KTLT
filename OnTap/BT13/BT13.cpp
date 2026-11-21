#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
void menu()
{
	printf("\nMenu");
	printf("\n0. Thoat");
	printf("\n1. Xuat so Fibonacci thu n");
	printf("\n2. Xuat so Fibonacci lon nhat va <m");
	printf("\n3. Xuat cac so Fibonacci thuoc khoang [m,n]");
}
int fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}
int fibonacciBeHonm(int m)
{
	if (m == 1)
		return m;
	for (int i = 1; i <= m + 1; i++)
	{
		if (fibonacci(i) >= m)
			return fibonacci(i - 1);
	}
}
void fibonacciMN(int m, int n)
{
	printf("\nDay fibonacci thuoc [%d,%d]: ", m, n);
	for (int i = m; i < n; i++)
	{
		if (fibonacci(i) >= m && fibonacci(i) <= n)
			printf("%5d", fibonacci(i));
	}
}
void main()
{
	int cn;
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
			int n;
			do
			{
				printf("\nNhap n: ");
				scanf("%d", &n);
			} while (n <= 0);
			printf("\nSo Fibonacci thu %d: %d", n, fibonacci(n));
			break;
		}
		case 2:
		{
			int m;
			do
			{
				printf("\nNhap m: ");
				scanf("%d", &m);
			} while (m <= 0);
			printf("\nSo Fibonacci lon nhat va <%d: %d", m, fibonacciBeHonm(m));
			break;
		}
		case 3:
		{
			int m, n;
			do
			{
				printf("\nNhap doan m n: ");
				scanf("%d %d", &m, &n);
			} while (m > n || m <= 0);
			fibonacciMN(m, n);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}