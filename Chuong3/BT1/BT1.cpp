#include <stdio.h>
#include <conio.h>
#include <math.h>
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
	printf("\n9. Tinh s5");
	printf("\n10. Tinh s5 de quy");
	printf("\n11. Tinh s6");
	printf("\n12. Tinh s6 de quy");
	printf("\n13. Tinh s7");
	printf("\n14. Tinh s7 de quy");
	printf("\n15. Tinh s8");
	printf("\n16. Tinh s8 de quy");
	printf("\n17. Tinh s9");
	printf("\n18. Tinh s9 de quy");
	printf("\n19. Tinh s10");
	printf("\n20. Tinh s10 de quy");
}
int tinhS1(int n)
{
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + i;
	}
	return t;
}
int tinhS1_DeQuy(int n)
{
	if (n == 1)
		return 1;
	else
		return tinhS1_DeQuy(n - 1) + n;
}
float tinhS2(int n)
{
	float t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = sqrt(2 + t);
	}
	return t;
}
float tinhS2_DeQuy(int n)
{
	if (n == 1)
		return sqrt(2);
	else
		return sqrt(2 + tinhS2_DeQuy(n - 1));

}
float tinhS3(int n)
{
	float t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + (float)i / (i + 1);
	}
	return t;
}
float tinhS3_DeQuy(int n)
{
	if (n == 1)
		return 1.0 / 2;
	else
		return tinhS3_DeQuy(n - 1) + (float)n / (n + 1);
}
float tinhS4(int n)
{
	float t = 0;
	for (int i = 0; i <= n; i++)
	{
		t = t + 1.0 / (2 * i + 1);
	}
	return t;
}
float tinhS4_DeQuy(int n)
{
	if (n == 0)
		return 1;
	else
		return tinhS4_DeQuy(n - 1) + 1.0 / (2 * n + 1);
}
int tinhS5(int n)
{
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + i * (i + 1);
	}
	return t;
}
int tinhS5_DeQuy(int n)
{
	if (n == 1)
		return 2;
	else
		return tinhS5_DeQuy(n - 1) + n * (n + 1);
}
float tinhS6(int n)
{
	float t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + 1.0 / (i * (i + 1) * (i + 2));
	}
	return t;
}
float tinhS6_DeQuy(int n)
{
	if (n == 1)
		return 1.0 / 6;
	else
		return tinhS6_DeQuy(n - 1) + 1.0 / (n * (n + 1) * (n + 2));
}
int tinhS7(int n)
{
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + i * i;
	}
	return t;
}
int tinhS7_DeQuy(int n)
{
	if (n == 1)
		return 1;
	else
		return tinhS7_DeQuy(n - 1) + n * n;
}
int tinhS8(int n)
{
	int t = 0, s = 0;
	for (int i = 1; i <= n; i++)
	{
		s = s + i;
		t = t + s;
	}
	return t;
}
int tinhS8_DeQuy(int n)
{
	if (n == 1)
		return 1;
	else
		return tinhS8_DeQuy(n - 1) + tinhS1(n);
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
float tinhS9(int n)
{
	float t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + pow(-1, double(i)) * ((2 * i - 1) + (2 * i)) / giaiThua(2 * i);
	}
	return t;
}
float tinhS9_DeQuy(int n)
{
	if (n == 1)
		return -3.0 / 2;
	else
		return tinhS9_DeQuy(n - 1) + pow(-1, double(n)) * ((2 * n - 1) + (2 * n)) / giaiThua(2 * n);
}
float tinhS10(int n)
{
	float t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + (i * giaiThua(i + 1)) / ((i + 1) + sqrt(i + 2));
	}
	return t;
}
float tinhS10_DeQuy(int n)
{
	if (n == 1)
		return 4 - 2 * sqrt(3);
	else
		return tinhS10_DeQuy(n - 1) + (n * giaiThua(n + 1)) / ((n + 1) + sqrt(n + 2));
}
void main()
{
	int n, cn;
	do
	{
		menu();
		printf("\nChon chuc nang: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 1:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS1 = %d", tinhS1(n));
			break;
		}
		case 2:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS1 = %d", tinhS1_DeQuy(n));
			break;
		}
		case 3:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS2 = %.2f", tinhS2(n));
			break;
		}
		case 4:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS2 = %.2f", tinhS2_DeQuy(n));
			break;
		}
		case 5:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS3 = %.2f", tinhS3(n));
			break;
		}
		case 6:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS3 = %.2f", tinhS3_DeQuy(n));
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
		case 9:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS5 = %d", tinhS5(n));
			break;
		}
		case 10:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS5 = %d", tinhS5_DeQuy(n));
			break;
		}
		case 11:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS6 = %.2f", tinhS6(n));
			break;
		}
		case 12:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS6 = %.2f", tinhS6_DeQuy(n));
			break;
		}
		case 13:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS7 = %d", tinhS7(n));
			break;
		}
		case 14:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS7 = %d", tinhS7_DeQuy(n));
			break;
		}
		case 15:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS8 = %d", tinhS8(n));
			break;
		}
		case 16:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS8 = %d", tinhS8_DeQuy(n));
			break;
		}
		case 17:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS9 = %.2f", tinhS9(n));
			break;
		}
		case 18:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS9 = %.2f", tinhS9_DeQuy(n));
			break;
		}
		case 19:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS10 = %.2f", tinhS10(n));
			break;
		}
		case 20:
		{
			printf("\nNhap n can tinh: ");
			scanf("%d", &n);
			printf("\nS10 = %.2f", tinhS10_DeQuy(n));
			break;
		}
		default:
			break;
		}
	} while (cn!=0);
	getch();
}