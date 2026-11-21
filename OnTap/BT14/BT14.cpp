#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
void menu()
{
	printf("\nMenu");
	printf("\n0. Thoat");
	printf("\n1. Tinh to hop chap k cua n");
	printf("\n2. Dem so chu so cua so nguyen duong n");
	printf("\n3. Dem so chu so chan cua so nguyen duong n");
	printf("\n4. Tim uoc chung lon nhat cua 2 so nguyen duong a, b");
}
int toHop(int n, int k) 
{
    if (k == 0 || k == n)
        return 1;
    else
        return toHop(n - 1, k - 1) + toHop(n - 1, k);
}
int demChuSo(int n)
{
    if (n < 10)
        return 1;
    else
        return 1 + demChuSo(n / 10);
}
int demChuSoChan(int n)
{
    if (n < 10)
        return n % 2 == 0 ? 1 : 0;
    else
        return n % 10 % 2 == 0 ? 1 + demChuSoChan(n / 10) : demChuSoChan(n / 10);
}
int ucln(int a, int b)
{
	if (a == b)
		return a;
	else
		return a > b ? ucln(a - b, b) : ucln(a, b - a);
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
			int n, k;
			do
			{
				printf("\nNhap n: ");
				scanf("%d", &n);
				printf("\nNhap k: ");
				scanf("%d", &k);
			} while (n < k);
			printf("\nTo hop = %d", toHop(n, k));
			break;
		}
		case 2:
		{
			int n;
			do
			{
				printf("\nNhan so can dem: ");
				scanf("%d", &n);
			} while (n < 0);
			printf("\n%d co %d chu so", n, demChuSo(n));
			break;
		}
		case 3:
		{
			int n;
			do
			{
				printf("\nNhan so can dem: ");
				scanf("%d", &n);
			} while (n < 0);
			printf("\n%d co %d chu so chan", n, demChuSoChan(n));
			break;
		}
		case 4:
		{
			int a, b;
			printf("\nNhap 2 so can tim UCLN: ");
			scanf("%d %d", &a, &b);
			printf("\nUCLN(%d,%d) = %d", a, b, ucln(a, b));
			break;
		}
		default:
			break;
		}
	} while (1);
    getch();
}