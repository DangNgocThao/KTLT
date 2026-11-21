#include <stdio.h>
#include <conio.h>
#include <math.h>
float tinhS1(int n);
float tinhS1_DeQuy(int n);
int tinhS2(int n);
int tinhS2_DeQuy(int n);
int tinhS3(int n);
int tinhTongn(int n);
int tinhS3_DeQuy(int n);
int giaiThua(int n);
float tinhS4(int n);
float tinhS4_DeQuy(int n);
void menu();
void process();
void main()
{
	process();
	getch();
}
float tinhS1(int n)
{
	float t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + 1.0 / (i * (i + 1) * (i + 2));
	}
	return t;
}
float tinhS1_DeQuy(int n)
{
	if (n == 1)
		return 1.0 / 6;
	else
		return tinhS1_DeQuy(n - 1) + 1.0 / (n * (n + 1) * (n + 2));
}
int tinhS2(int n)
{
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + i * i;
	}
	return t;
}
int tinhS2_DeQuy(int n)
{
	if (n == 1)
		return 1;
	else
		return tinhS2_DeQuy(n - 1) + n * n;
}
int tinhS3(int n)
{
	int t = 0, s = 0;
	for (int i = 1; i <= n; i++)
	{
		s = s + i;
		t = t + s;
	}
	return t;
}
int tinhTongn(int n)
{
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + i;
	}
	return t;
}
int tinhS3_DeQuy(int n)
{
	if (n == 1)
		return 1;
	else
		return tinhS3_DeQuy(n - 1) + tinhTongn(n);
}
int giaiThua(int n)
{
	int t = 1;
	for (int i = 1; i <= n; i++)
	{
		t = t * i;
	}
	return t;
}
float tinhS4(int n)
{
	float t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + pow(-1, double(i)) * ((2 * i - 1) + (2 * i)) / giaiThua(2 * i);
	}
	return t;
}
float tinhS4_DeQuy(int n)
{
	if (n == 1)
		return -3.0 / 2;
	else
		return tinhS4_DeQuy(n - 1) + pow(-1, double(n)) * ((2 * n - 1) + (2 * n)) / giaiThua(2 * n);
}
void menu()
{
	printf("\nMenu");
	printf("\n0. Thoat");
	printf("\n1. Tinh s1");
	printf("\n2. Tinh s1 de quy");
	printf("\n3. Tinh s2");
	printf("\n4. Tinh s2 de quy");
	printf("\n5. Tinh s3");
	printf("\n6. Tinh s3 de quy");
	printf("\n7. Tinh s4");
	printf("\n8. Tinh s4 de quy");
}
void process()
{
	int n, cn;
	do
	{
		menu();
		printf("\nBan hay chon mot chuc nang bat ky: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 1:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS1 = %.2f", tinhS1(n));
			break;
		}
		case 2:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS1 = %.2f", tinhS1_DeQuy(n));
			break;
		}
		case 3:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS2 = %d", tinhS2(n));
			break;
		}
		case 4:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS2 = %d", tinhS2_DeQuy(n));
			break;
		}
		case 5:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS3 = %d", tinhS3(n));
			break;
		}
		case 6:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS3 = %d", tinhS3_DeQuy(n));
			break;
		}
		case 7:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS4 = %.2f", tinhS4(n));
			break;
		}
		case 8:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS4 = %.2f", tinhS4_DeQuy(n));
			break;
		}
		default:
			break;
		}
	} while (cn != 0);
}
