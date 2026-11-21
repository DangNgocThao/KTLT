#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
typedef struct SanPham
{
	char ma[6], ten[21], nsx[31], loai[21];
	int solg;
	float dongia;
}SP;
void xuatTT1SP(SP a)
{
	printf("\nMa san pham: %s", a.ma);
	printf("\nTen san pham: %s", a.ten);
	printf("\nSo luong trong kho: %d", a.solg);
	printf("\nDon gia: %.3f", a.dongia);
	printf("\nNha san xuat: %s", a.nsx);
	printf("\nLoai san pham: %s", a.loai);
}
void xuatTTSP(SP a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nThong tin sap pham %d", i + 1);
		xuatTT1SP(a[i]);
	}
}
void xuatTTSPLaneige(SP a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (stricmp(a[i].nsx, "Laneige") == NULL)
		{
			printf("\nThong tin sap pham %d", i + 1);
			xuatTT1SP(a[i]);
		}
	}
}
int tongSPKem(SP a[], int n)
{
	char t[4];
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		strncpy(t, a[i].ten, 3);
		if (stricmp(t, "Kem") == NULL)
			c += a[i].solg;
	}
	return c;
}
int vtmaxDonGia(SP a[], int n)
{
	int vtm = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[vtm].dongia < a[i].dongia)
			a[vtm].dongia = a[i].dongia;
	}
	return vtm;
}
void xuatMaxDonGia(SP a[], int n)
{
	xuatTT1SP(a[vtmaxDonGia(a, n)]);
}
void swap(SP a, SP b)
{
	SP t = a;
	a = b;
	b = t;
}
void sxMaTang(SP a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stricmp(a[i].ma, a[j].ma) > 0)
				swap(a[i], a[j]);
		}
	}
}
void xoaPT(SP a[], int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void xoaSP0SoLuong(SP a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].solg == 0)
			xoaPT(a, n, i);
	}
}
int DemSoSPSenka(SP a[], int n)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (stricmp(a[i].nsx, "Senka") == NULL)
			d++;
	}
	return d;
}