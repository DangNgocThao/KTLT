#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"
void menu()
{
	printf("\n0. Thoat");
	printf("\n1. Nhap mang 1 chieu");
	printf("\n2. Xuat mang 1 chieu");
	printf("\n3. Xuat cac so cuc tieu trong mang");
	printf("\n4. Xoa phan tu tai vi tri k");
	printf("\n5. Them phan tu x tai vi tri k");
	printf("\n6. Chuyen so chan len dau mang, so le xuong cuoi mang");
	printf("\n7. Kiem tra mang co chua chan le xen ke khong");
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
void taoMang1C(int * &a, int &n)
{
	printf("\nNhap so phan tu: ");
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = rand() % 199 - 99;
	}
}
void xuatMang1C(int* a, int n)
{
	printf("\nNoi dung mang: ");
	for (int i = 0; i < n; i++)
	{
		printf("%4d", *(a + i));
	}
}
void xuatCucTieu(int* a, int n)
{
	printf("\nCac phan tu cuc tieu: ");
	if (*a < *(a + 1))
		printf("%5d", *a);
	for (int i = 1; i < n - 1; i++)
	{
		if (*(a + i - 1) > *(a + i) && *(a + i) < *(a + i + 1))
			printf("%5d", *(a + i));
	}
	if (*(a + n - 1) < *(a + n - 2))
		printf("%5d", *(a + n - 1));
}
void xoa1PT(int* a, int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		*(a + i) = *(a + i + 1);
	}
	n--;
}
void them1PT(int* a, int& n, int x, int vt)
{
	for (int i = n; i > vt; i--)
	{
		*(a + i) = *(a + i - 1);
	}
	*(a + vt) = x;
	n++;
}
void hoanVi(int& a, int& b)
{
	int t = a; 
	a = b; 
	b = t;
}
void xepChanLe(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (*(a + i) % 2 != 0 && *(a + j) % 2 == 0)
				hoanVi(*(a + i), *(a + j));
		}
	}
}
int ktChanLeXenKe(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if ((*(a + i) % 2 == 0 && *(a + i + 1) % 2 == 0) || (*(a + i) % 2 != 0 && *(a + i + 1) % 2 != 0))
			return 0;
	}
	return 1;
}
void main()
{
	int n, cn;
	int *a = new int;
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
			xuatMang1C(a, n);
			break;
		}
		case 3:
		{
			xuatCucTieu(a, n);
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
			xoa1PT(a, n, vt);
			break;
		}
		case 5:
		{
			int vt, x;
			printf("\nNhap so can them vao: ");
			scanf("%d", &x);
			do
			{
				printf("\nNhap vi tri them vao: ");
				scanf("%d", &vt);
			} while (vt < 0 || vt > n);
			them1PT(a, n, x, vt);
			break;
		}
		case 6:
		{
			xepChanLe(a, n);
			break;
		}
		case 7:
		{
			if (ktChanLeXenKe(a, n) == 1)
				printf("\nMang chua chan le xen ke");
			else
				printf("\nMang khong chua chan le xen ke");
		}
		default:
			break;
		}
	} while (1);
	getch();
}