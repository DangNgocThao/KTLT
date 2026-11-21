#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#define MAX 100
void menu();
void nhapM1C(int a[], int& n);
void xuatM1C(int a[], int n);
void giaTriChan(int a[], int n);
void viTriAm(int a[], int n);
int giaTriMax(int a[], int n);
int duongDau(int a[], int n);
int chanCuoi(int a[], int n);
int viTriMinDau(int a[], int n);
int viTriChanDau(int a[], int n);
int ktSoHoanThien(int x);
int viTriSoHTCuoi(int a[], int n);
int duongMin(int a[], int n);
int ktSoNguyenTo(int x);
int soNTDau(int a[], int n);
int soHTDau(int a[], int n);
int amMax(int a[], int n);
int soNTMax(int a[], int n);
int viTriSoHTMin(int a[], int n);
int soLanXuatHien(int a[], int n, int x);
int chanMin(int a[], int n);
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
		case 3:
		{
			printf("\nCac gia tri chan trong mang 1 chieu: ");
			giaTriChan(a, n);
			break;
		}
		case 4:
		{
			printf("\nVi tri ma gia tri tai do la gia tri am trong mang 1 chieu: ");
			viTriAm(a, n);
			break;
		}
		case 5:
		{
			printf("\nGia tri lon nhat trong mang 1 chieu: %d", giaTriMax(a, n));
			break;
		}
		case 6:
		{
			int d = duongDau(a, n);
			if (d == -1)
				printf("\nKhong co gia tri duong trong mang");
			else
				printf("\nGia tri duong dau tien trong mang 1 chieu: %d", d);
			break;
		}
		case 7:
		{
			int c = chanCuoi(a, n);
			if (c == -1)
				printf("\nKhong co gia tri chan trong mang");
			else
				printf("\nSo chan cuoi cung trong mang 1 chieu: %d", c);
			break;
		}
		case 8:
		{
			printf("\nVi tri gia tri nho nhat dau tien trong mang 1 chieu: %d", viTriMinDau(a, n));
			break;
		}
		case 9:
		{
			int c = viTriChanDau(a, n);
			if (c == -1)
				printf("\nKhong co gia tri chan trong mang");
			else
				printf("\nVi tri cua gia tri chan dau tien trong mang mot chieu: %d", c);
			break;
		}
		case 10:
		{
			int ht = viTriSoHTCuoi(a, n);
			if (ht == -1)
				printf("\nKhong co so hoan thien trong mang");
			else
				printf("\nVi tri so hoan thien cuoi cung trong mang 1 chieu: %d", ht);
			break;
		}
		case 11:
		{
			int d = duongMin(a, n);
			if (d == -1)
				printf("\nKhong co gia tri duong trong mang");
			else
				printf("\nGia tri duong nho nhat trong mang: %d", d);
			break;
		}
		case 12:
		{
			int nt = soNTDau(a, n);
			if (nt == -1)
				printf("\nKhong co so nguyen to trong mang");
			else
				printf("\nSo nguyen to dau tien trong mang 1 chieu: %d", nt);
			break;
		}
		case 13:
		{
			int ht = soHTDau(a, n);
			if (ht == -1)
				printf("\nKhong co so hoan thien trong mang");
			else
				printf("\nSo hoan thien dau tien trong 1 chieu: %d", ht);
			break;
		}
		case 14:
		{
			int am = amMax(a, n);
			if (am == 0)
				printf("\nKhong co gia tri am trong mang");
			else
				printf("\nGia tri am lon nhat trong mang: %d", am);
			break;
		}
		case 15:
		{
			int nt = soNTMax(a, n);
			if (nt == 0)
				printf("\nKhong co so nguyen to trong mang");
			else
				printf("\nSo nguyen to lon nhat trong mang 1 chieu: %d", nt);
			break;
		}
		case 16:
		{
			int ht = viTriSoHTMin(a, n);
			if (ht == 0)
				printf("\nKhong co so hoan thien trong mang");
			else
				printf("\nVi tri so hoan thien nho nhat trong mang 1 chieu: %d", ht);
			break;
		}
		case 17:
		{
			int cmin = chanMin(a, n);
			int vtcuoi = 0;
			if (soLanXuatHien(a, n, cmin) > 1 && cmin % 2 == 0)
			{
				for (int i = 1; i < n; i++)
					if (cmin == a[i])
						vtcuoi = i;
				printf("\nVi tri phan tu chan nho nhat cuoi cung: %d", vtcuoi);
			}
			else
				if (cmin == -1)
					printf("\nKhong co gia tri chan trong mang");
				else
					printf("\nGia tri chan nho nhat trong mang 1 chieu: %d", cmin);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}
void menu()
{
	printf("\nMENU");
	printf("\n0. Thoat");
	printf("\n1. Nhap mang mot chieu");
	printf("\n2. Xuat mang mot chieu");
	printf("\n3. Liet ke cac gia tri chan trong mang so nguyen");
	printf("\n4. Liet ke cac vi tri ma gia tri tai do la gia tri am trong mang 1 chieu");
	printf("\n5. Tim gia tri lon nhat trong mang 1 chieu");
	printf("\n6. Tim gia tri duong dau tien trong mang 1 chieu");
	printf("\n7. Tim so chan cuoi cung trong mang 1 chieu");
	printf("\n8. Tim vi tri gia tri nho nhat dau tien trong mang 1 chieu");
	printf("\n9. Tim vi tri cua gia tri chan dau tien trong mang mot chieu");
	printf("\n10. Tim vi tri so hoan thien cuoi cung trong mang 1 chieu");
	printf("\n11. Tim gia tri duong nho nhat trong mang");
	printf("\n12. Tim so nguyen to dau tien trong mang 1 chieu");
	printf("\n13. Tim so hoan thien dau tien trong 1 chieu");
	printf("\n14. Tim gia tri am lon nhat trong mang");
	printf("\n15. Tim so nguyen to lon nhat trong mang 1 chieu");
	printf("\n16. Tim vi tri so hoan thien nho nhat trong mang 1 chieu");
	printf("\n17. Tim gia tri chan nho nhat trong mang 1 chieu");
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
void viTriAm(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			printf("%5d", i);
	}
}
int giaTriMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	return max;
}
int duongDau(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			return a[i];
	}
	return -1;
}
int chanCuoi(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] % 2 == 0)
			return a[i];
	}
	return -1;
}
int viTriMinDau(int a[], int n)
{
	int vtmin = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[vtmin] > a[i])
		{
			vtmin = i;
		}
	}
	return vtmin;
}
int viTriChanDau(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			return i;
	}
	return -1;
}
int ktSoHoanThien(int x)
{
	int t = 0;
	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
			t = t + i;
	}
	if (t == x)
		return 1;
	else
		return 0;
}
int viTriSoHTCuoi(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (ktSoHoanThien(a[i]) == 1)
			return i;
	}
	return -1;
}
int duongMin(int a[], int n)
{
	int vtduong = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			vtduong = i;
			break;
		}
	}
	if (vtduong == -1)
		return -1;
	int min = a[vtduong];
	for (int i = vtduong; i < n; i++)
	{
		if (a[i] > 0 && a[i] < min)
			min = a[i];
	}
	return min;
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
int soNTDau(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ktSoNguyenTo(a[i]) == 1)
			return a[i];
	}
	return -1;
}
int soHTDau(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ktSoHoanThien(a[i]) == 1)
			return a[i];
	}
	return -1;
}
int amMax(int a[], int n)
{
	int vtam = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			vtam = i;
			break;
		}
	}
	if (vtam == -1)
		return 0;
	int max = a[vtam];
	for (int i = vtam; i < n; i++)
	{
		if (a[i] < 0 && a[i] > max)
			max = a[i];
	}
	return max;
}
int soNTMax(int a[], int n)
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
	int max = a[vtsnt];
	for (int i = vtsnt; i < n; i++)
	{
		if (ktSoNguyenTo(a[i]) == 1 && a[i] > max)
			max = a[i];
	}
	return max;
}
int viTriSoHTMin(int a[], int n)
{
	int vtsht = -1;
	for (int i = 0; i < n; i++)
	{
		if (ktSoHoanThien(a[i]) == 1)
		{
			vtsht = i;
			break;
		}
	}
	if (vtsht == -1)
		return 0;
	int vtmin = vtsht;
	for (int i = vtsht; i < n; i++)
	{
		if (ktSoHoanThien(a[i]) == 1 && a[i] < a[vtmin])
		{
			vtmin = i;
		}
	}
	return vtmin;
}
int soLanXuatHien(int a[], int n, int x)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			d++;
	}
	return d;
}
int chanMin(int a[], int n)
{
	int vtchan = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			vtchan = i;
			break;
		}
	}
	if (vtchan == -1)
		return -1;
	int min = a[vtchan];
	for (int i = vtchan; i < n; i++)
	{
		if (a[i] % 2 == 0 && a[i] < min)
			min = a[i];
	}
	return min;
}