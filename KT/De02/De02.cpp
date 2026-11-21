#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "time.h"
#include "string.h"
int vtPTChanDau(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) % 2 == 0)
			return i;
	}
	return -1;
}
void themPT(int*& a, int& n, int x, int vt)
{
	for (int i = n; i > vt; i--)
	{
		*(a + i) = *(a + i - 1);
	}
	*(a + vt) = x;
	n++;
}
void themPTtruocPTChanDau(int*& a, int& n, int x)
{
	int vtchan = vtPTChanDau(a, n);
	if (vtchan == -1)
		themPT(a, n, x, n - 1);
	else
		themPT(a, n, x, vtchan);
}

int ktChuSoToanLe(int n) 
{
	int t;
	do 
	{
		t = n % 10;
		n /= 10;
		if (t % 2 == 0)
			return 0;
	} while (n > 0);
	return 1;
}
void xuatSoCoChuSoToanLe(int a[][100], int n)
{
	printf("\nCac phan tu ma tung chu so cua no la le: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktChuSoToanLe(a[i][j]) == 1)
				printf("%5d", a[i][j]);
		}
	}
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void sx1DongGiam(int a[][100], int n, int d)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[d][i] < a[d][j])
				swap(a[d][i], a[d][j]);
		}
	}
}
void sxDongGiam(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		sx1DongGiam(a, n, i);
	}
}

struct SinhVien
{
	char masv[11];
	char hoten[31];
	int nam;
	char malop[6];
};
int demSinhVienDHTH(SinhVien a[], int n)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (strstr(a[i].malop, "DHTH") != NULL)
			d++;
	}
	return d;
}
void xuatTTSVhoTran(SinhVien a[], int n)
{
	char t[5];
	for (int i = 0; i < n; i++)
	{
		strncpy(t, a[i].hoten, 4);
		t[4] = '\0';
		if (stricmp(t, "Tran") == NULL)
		{
			printf("\nThong tin sinh vien thu %d", i + 1);
			printf("\nMSSV: %s", a[i].masv);
			printf("\nHo ten: %s", a[i].hoten);
			printf("\nNam sinh: %d", a[i].nam);
			printf("\nMa lop: %s", a[i].malop);
		}
	}
}

int tinhx(int n)
{
	if (n == 0)
		return 1;
	else
		return tinhx(n - 1) + 3 * tinhy(n - 1);
}
int tinhy(int n)
{
	if (n == 0)
		return 1;
	else
		return 3 * tinhx(n - 1) + 2 * tinhy(n - 1);
}
float tinhSnDeQuy(int n)
{
	if (n == 3)
		return 1 / 6;
	else
		return tinhSnDeQuy(n - 1) + 1.0 / ((n - 2) * (n - 1) * n);
}
float tinhSn(int n)
{
	float t = 0;
	for (int i = 3; i <= n; i++)
	{
		t += 1.0 / ((i - 2) * (i - 1) * i);
	}
	return t;
}