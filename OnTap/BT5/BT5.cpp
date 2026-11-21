#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#define MAX 100
void menu()
{
	printf("\nMENU");
	printf("\n0. Thoat");
	printf("\n1. Nhap mang mot chieu");
	printf("\n2. Xuat mang mot chieu");
}
void nhapM1C(int a[], int& n)
{
	do
	{
		printf("\nNhap n: ");
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
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[i]);
	}
}
void giaTriChan(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			printf("%5d", a[i]);
	}
}
int ktSoNguyenTo(int x)
{
	int d = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0)
			d++;
	}
	if (d == 2)
		return 1;
	else
		return 0;
}
int vtSNTMax(int a[], int n)
{
	int vtsnt = -1;
	for (int i = 0; i < n; i++)
	{
		if (ktSoNguyenTo(a[i]) == 1)
		{
			vtsnt = i;
			break;
		}
	}
	if (vtsnt == -1)
		return 0;
	int vtmax = vtsnt;
	for (int i = vtsnt; i < n; i++)
	{
		if (ktSoNguyenTo(a[i]) == 1 && a[i] > a[vtmax])
			vtmax = i;
	}
	return vtmax;
}
int TongChanVTLe(int a[], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0 && a[i] % 2 == 0)
			t += a[i];
	}
	return t;
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void sapChanTangLeKhongDoi(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
int ktMangTang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
			return 0;
	}
	return 1;
}
int KiemTraCapSoCong(int a[], int n, int& d)
{
	d = a[1] - a[0];
	for (int i = 2; i < n - 1; i++)
	{
		if ((a[i + 1] - a[i]) != d)
		{
			return 0;
		}
	}
	return 1;
}
int vtLeMax(int a[], int n)
{
	int vtle = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			vtle = i;
			break;
		}
	}
	if (vtle == -1)
		return 0;
	int vtmax = vtle;
	for (int i = vtle; i < n; i++)
	{
		if (a[i] % 2 != 0 && a[i] > a[vtmax])
			vtmax = i;
	}
	return vtmax;
}
int vtSoChiaHetCho3Min(int a[], int n)
{
	int vt = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 3 == 0)
		{
			vt = i;
			break;
		}
	}
	if (vt == -1)
		return 0;
	int vtmin = vt;
	for (int i = vt; i < n; i++)
	{
		if (a[i] % 3 == 0 && a[i] < a[vtmin])
			vtmin = i;
	}
	return vtmin;
}
void timMaxChuoiCon(int a[], int n)
{
	int dodai = 1;
	int max = 1;
	int dau = 0;
	int cuoi = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] < a[i + 1])
		{
			dodai++;
			if (dodai > max)
			{
				max = dodai;
				dau = i + 2 - dodai;
				cuoi = i + 2;
			}
		}
		else
			dodai = 1;
	}
	for (int i = dau; i < cuoi; i++)
		printf("%5d", a[i]);
}
void sapBeHon10TangConLaiKhongDoi(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < 10 && a[j] <10 && a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
int linearSearch(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return i;
	}
	return -1;
}
int binarySearch(int* a, int n, int x)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		else
			if (a[mid] < x)
				left = mid + 1;
			else
				right = mid - 1;
	}
	return -1;
}
void interchangeSort(int*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
void selectionSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[vtm])
				vtm = j;
			swap(a[i], a[vtm]);
		}
	}
}
void quickSort(int* a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	int x = a[mid];
	do
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i < j)
			swap(a[i], a[j]);
		i++;
		j--;
	} while (i < j);
	if (left < j)
		quickSort(a, left, j);
	if (right > i)
		quickSort(a, i, right);
}
void main()
{
	int a[MAX];
	int n, cn;
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
			nhapM1C(a, n);
			break;
		}
		case 2:
		{
			printf("\nPhan tu trong mang:");
			xuatM1C(a, n);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}