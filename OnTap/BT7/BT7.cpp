#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
typedef struct PhanSo
{
	int tu;
	int mau;
}PS;
void doiDauPS(PS& x)
{
	if (x.mau < 0)
	{
		x.tu *= -1;
		x.mau *= -1;
	}
}
int timUSCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a == 0 || b == 0)
		return 1;
	while (a != b)
	{
		if (a >= b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
void rutGonPS(PS& x)
{
	int usclc = timUSCLN(x.tu, x.mau);
	x.tu /= usclc;
	x.mau /= usclc;
}
double tinhGiaTriPS(PS x)
{
	return (double)x.tu / x.mau;
}
void taoMangPS(PS a[],int &n)
{
	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", &n);
	} while (n < 1);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		do
		{
			a[i].tu = rand() % 199 - 99;
		} while (a[i].tu == 0);
		do
		{
			a[i].mau = rand() % 99 + 1;
		} while (a[i].mau == 0 || a[i].mau % 2 == 0);
		rutGonPS(a[i]);
	}
}
void xuatMangPS(PS a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d/%-5d", a[i].tu, a[i].mau);
	}
}
int psMauMax(PS a[], int n)
{
	int vtmax = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[vtmax].mau < a[i].mau)
			vtmax = i;
	}
	return vtmax;
}
void xoaPT(PS a[], int &n, int vt)
{
	for (int i = vt; i < n-1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void xoaPTTuBang1(PS a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].tu == 1)
			xoaPT(a, n, i);
	}
}
void swap(PS& a, PS& b)
{
	PS t = a;
	a = b;
	b = t;
}
void interchangeSort_TangDan(PS*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tinhGiaTriPS(a[i]) > tinhGiaTriPS(a[j]))
				swap(a[i], a[j]);
		}
	}
}
void interchangeSort_GiamDan(PS*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tinhGiaTriPS(a[i]) < tinhGiaTriPS(a[j]))
				swap(a[i], a[j]);
		}
	}
}
void selectionSort_TangDan(PS* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tinhGiaTriPS(a[j]) < tinhGiaTriPS(*(a + vtm)))
				vtm = j;
			swap(a[i], *(a + vtm));
		}
	}
}
void selectionSort_GiamDan(PS* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tinhGiaTriPS(a[j]) > tinhGiaTriPS(*(a + vtm)))
				vtm = j;
			swap(a[i], *(a + vtm));
		}
	}
}
void quickSort_TangDan(PS* a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	PS x = a[mid];
	do
	{
		while (tinhGiaTriPS(a[i]) < tinhGiaTriPS(x))
			i++;
		while (tinhGiaTriPS(a[j]) > tinhGiaTriPS(x))
			j--;
		if (i < j)
			swap(a[i], a[j]);
		i++;
		j--;
	} while (i < j);
	if (left < j)
		quickSort_TangDan(a, left, j);
	if (right > i)
		quickSort_TangDan(a, i, right);
}
void quickSort_GiamDan(PS* a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	PS x = a[mid];
	do
	{
		while (tinhGiaTriPS(a[i]) > tinhGiaTriPS(x))
			i++;
		while (tinhGiaTriPS(a[j]) < tinhGiaTriPS(x))
			j--;
		if (i < j)
			swap(a[i], a[j]);
		i++;
		j--;
	} while (i < j);
	if (left < j)
		quickSort_GiamDan(a, left, j);
	if (right > i)
		quickSort_GiamDan(a, i, right);
}
int demPTBeHon1(PS a[], int n)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (tinhGiaTriPS(a[i]) < 1)
			d++;
	}
	return d;
}
PS tongPS(PS x, PS y)
{
	PS z;
	z.tu = x.tu * y.mau + y.tu * x.mau;
	z.mau = x.mau * y.mau;
	doiDauPS(z);
	rutGonPS(z);
	return z;
}
PS tichPS(PS x, PS y)
{
	PS z;
	z.tu = x.tu * y.tu;
	z.mau = x.mau * y.mau;
	doiDauPS(z);
	rutGonPS(z);
	return z;
}
PS tongMang(PS a[], int n)
{
	PS t = a[0];
	for (int i = 1; i < n; i++)
	{
		t = tongPS(t, a[i]);
	}
	return t;
}
PS tichMang(PS a[], int n)
{
	PS t = a[0];
	for (int i = 1; i < n; i++)
	{
		t = tichPS(t, a[i]);
	}
	return t;
}
void themPT(PS* a, int& n, PS x, int vt)
{
	for (int i = n; i > vt; i--)
	{
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
int vtCucDai(PS a[], int n)
{
	printf("\nCac phan tu cuc tieu: ");
	if (tinhGiaTriPS(a[0]) > tinhGiaTriPS(a[1]))
		return 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (tinhGiaTriPS(a[i - 1]) < tinhGiaTriPS(a[i]) && tinhGiaTriPS(a[i]) > tinhGiaTriPS(a[i + 1]))
			return i;
	}
	if (tinhGiaTriPS(a[n - 1]) > tinhGiaTriPS(a[n - 2]))
		return n - 1;
}
void themXTruocCucDai(PS a[], int n, PS x)
{
	themPT(a, n, x, vtCucDai(a, n));
}
void xoaCucDai(PS a[], int n)
{
	printf("\nCac phan tu cuc tieu: ");
	if (tinhGiaTriPS(a[0]) < tinhGiaTriPS(a[1]))
		xoaPT(a, n, 0);
	for (int i = 1; i < n - 1; i++)
	{
		if (tinhGiaTriPS(a[i - 1]) > tinhGiaTriPS(a[i]) && tinhGiaTriPS(a[i]) < tinhGiaTriPS(a[i + 1]))
			xoaPT(a, n, i);
	}
	if (tinhGiaTriPS(a[n - 1]) < tinhGiaTriPS(a[n - 2]))
		xoaPT(a, n, n - 1);
}
void main()
{
	PS a[MAX];
	int n;
	taoMangPS(a, n);
	printf("\nNoi dung mang: ");
	xuatMangPS(a, n);
	getch();
}