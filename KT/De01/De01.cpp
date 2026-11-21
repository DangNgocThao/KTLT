/*
Ho ten:Dang Ngoc Thao
Ma SV:2001206904
*/
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "time.h"
//Cau 1
int vtPTLeCuoi(int* a, int n)
{
	int vtle = -1;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) % 2 != 0)
			vtle = i;
	}
	return vtle;
}
void xoaPT(int*& a, int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		*(a + i) = *(a + i + 1);
	}
	n--;
}
void xoaPTsauPTLeCuoi(int*& a, int& n)
{
	int vtle = vtPTLeCuoi(a, n);
	if (vtle == -1)
		xoaPT(a, n, n - 1);
	else
		xoaPT(a, n, vtle + 1);
}
//Cau 2
int tongPTBoiCua3CotChan(int a[][100], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 3 == 0 && j % 2 == 0)
				t += a[i][j];
		}
	}
	return t;
}
int kt1DongGiam(int a[][100], int n, int d)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[d][i] <= a[d][i + 1])
			return 0;
	}
	return 1;
}
void xuatDong(int a[][100], int n, int d)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[d][i]);
	}
	printf("\n");
}
void xuatDongGiam(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (kt1DongGiam(a, n, i) == 1)
			xuatDong(a, n, i);
	}
}
//Cau 3
struct ThiSinh
{
	char sbd[11];
	char hoten[51];
	int nam;
	char que[41];
	float diemlt, diemth;
};
int ktDauRot(ThiSinh a[], int i)
{
	if (a[i].diemlt >= 5 && a[i].diemth >= 5 && a[i].diemlt + a[i].diemth > 12)
		return 1;
	else
		return 0;
}
void xuatDauRot(ThiSinh a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ktDauRot(a, i) == 1)
			printf("\nThi sinh %d dau", i + 1);
		else
			printf("\nThi sinh %d rot", i + 1);
	}
}
int demDau(ThiSinh a[], int n)
{
	int d;
	for (int i = 0; i < n; i++)
	{
		if (ktDauRot(a, i) == 1)
			d++;
	}
	return d;
}
int demRot(ThiSinh a[], int n)
{
	int d;
	for (int i = 0; i < n; i++)
	{
		if (ktDauRot(a, i) == 0)
			d++;
	}
	return d;
}
//Cau 4
int csc(int a, int r, int n)
{
	if (n == 1)
		return a;
	else
		return csc(a, r, n - 1) + r;
}
void xuatday20CSC(int a, int r)
{
	printf("\nDay CSC 20 so: ");
	for (int i = 1; i <= 20; i++)
	{
		printf("%5d", csc(a, r, i));
	}
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
float tinhSnDeQuy(int n)
{
	if (n == 1)
		return -1.0;
	else
		return tinhSnDeQuy(n - 1) + pow(-1, float(n)) * (((2 * n - 1) * 2 * n) / giaiThua(2 * n));
}
float tinhSn(int n)
{
	float t = 0;
	for (int i = 1; i <= n; i++)
	{
		t += pow(-1, float(i)) * (((2 * i - 1) * 2 * i) / giaiThua(2 * i));
	}
	return t;
}