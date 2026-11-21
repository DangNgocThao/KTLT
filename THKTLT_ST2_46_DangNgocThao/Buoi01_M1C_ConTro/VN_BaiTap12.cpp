#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
struct PhanSo
{
	float n, m;
};
void menu()
{
	printf("\n0. Thoat");
	printf("\n1. Nhap cac phan tu cua mang");
	printf("\n2. Xuat cac phan tu cua mang");
	printf("\n3. Tim phan so lon nhat/nho nhat");
	printf("\n4. Xoa phan tu tai vi tri k");
	printf("\n5. Them phan tu x tai vi tri k");
}
void nhapMangPS(PhanSo*& a, int& n)
{
	printf("\nNhap so phan tu: ");
	scanf("%d", &n);
	a = (PhanSo*)malloc(n * sizeof(PhanSo));
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("\na[%d] = ", i);
			scanf("%f/%f", &a[i].n, &a[i].m);
		} while (a[i].m == 0);
	}
}
void xuatMangPS(PhanSo* a, int n)
{
	printf("\nNoi dung mang: ");
	for (int i = 0; i < n; i++)
	{
		printf("%.0f/%.0f\t", a[i].n, a[i].m);
	}
}
void psMaxMin(PhanSo* a, int n)
{
	PhanSo max = *a, min = *a;
	for (int i = 1; i < n; i++)
	{
		if (max.n / max.m < a[i].n / a[i].m)
			max = a[i];
		if (min.n / min.m > a[i].n / a[i].m)
			min = a[i];
	}
	printf("\nPhan so lon nhat: %.0f/%.0f, phan so nho nhat: %.0f/%.0f", max.n, max.m, min.n, min.m);
}
void xoa1PS(PhanSo* a, int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void them1PS(PhanSo* a, int& n, PhanSo x, int vt)
{
	for (int i = n; i > vt; i--)
	{
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
void main()
{
	int n, cn;
	PhanSo* a = new PhanSo;
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
			nhapMangPS(a, n);
			break;
		}
		case 2:
		{
			xuatMangPS(a, n);
			break;
		}
		case 3:
		{
			psMaxMin(a, n);
			break;
		}
		case 4:
		{
			int vt;
			do
			{
				printf("\nNhap vi tri can xoa: ");
				scanf("%d", &vt);
			} while (vt < 0 || vt >= n);
			xoa1PS(a, n, vt);
			break;
		}
		case 5:
		{
			int vt;
			PhanSo x;
			do
			{
				printf("\nNhap phan so can them vao: ");
				scanf("%f/%f", &x.n, &x.m);
			} while (x.m == 0);
			do
			{
				printf("\nNhap vi tri them vao: ");
				scanf("%d", &vt);
			} while (vt < 0 || vt > n);
			them1PS(a, n, x, vt);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}