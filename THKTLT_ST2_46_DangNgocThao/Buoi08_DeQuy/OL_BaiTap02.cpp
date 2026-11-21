#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void nhapSoNguyenDuong(int &x);
void taoMang1C_SoNguyen_TrongDoanXY(int * &a, int &n, int x, int y);
void xuatMang1C_SoNguyen(int *a, int n);
int tinhTongChan(int *a, int n);
int tinhTongChan_DQ(int *a, int n);
void interchangeSort(int * &a, int n);
int binarySearch(int *a, int n, int x);
int binarySearch_DQ(int *a, int n, int x, int left, int right);
int timMaxChan(int *a, int n);
int timMaxChan_DQ(int *a, int n);
int tinhTongLe(int* a, int n);
int tinhTongLe_DQ(int* a, int n);
void xuatViTriLe(int* a, int n);
void xuatViTriLe_DQ(int *a, int n);
void showMenu();
void process();
void main()
{
	process();
	getch();
}
void showMenu()
{
	printf("\nMenu");
	printf("\n0. Thoat");
	printf("\n1. Tao mang 1 chieu so nguyen");
	printf("\n2. Xuat mang 1 chieu so nguyen");
	printf("\n3. Tinh tong chan cua mang 1 chieu so nguyen");
	printf("\n4. Tim kiem X tren mang 1 chieu so nguyen");
	printf("\n5. Tim Max chan tren mang 1 chieu so nguyen");
	printf("\n6. Tinh tong le cua mang 1 chieu so nguyen");
	printf("\n7. Xuat cac so o vi tri le");
}
void process()
{
	int *a = new int;
	int n, x, vt;
	int cn;
	double kq;

	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 1:
		{
			taoMang1C_SoNguyen_TrongDoanXY(a, n, 0, 99);
			printf("\nNoi dung cua mang la: ");
			xuatMang1C_SoNguyen(a, n);
			break;
		}
		case 2:
		{
			printf("\nNoi dung cua mang la: ");
			xuatMang1C_SoNguyen(a, n);
			break;
		}
		case 3:
		{
			printf("Tinh tong chan (Khong de quy) la: %d", tinhTongChan(a, n));
			printf("\nTinh tong chan (De quy) la: %d", tinhTongChan_DQ(a, n));
			break;
		}
		case 4:
		{
			printf("Nhap gia tri muon tim: ");
			scanf("%d", &x);
			interchangeSort(a, n);
			printf("\nNoi dung cua mang sau khi sap xep tang dan la: ");
			xuatMang1C_SoNguyen(a, n);

			vt = binarySearch(a, n, x);
			if (vt == -1)
				printf("\nKhong tim thay %d trong mang (Khong de quy).", x);
			else
				printf("\nTim thay %d tai vi tri %d trong mang (Khong de quy).", x, vt);

			vt = binarySearch_DQ(a, n, x, 0, n - 1);
			if (vt == -1)
				printf("\nKhong tim thay %d trong mang (De quy).", x);
			else
				printf("\nTim thay %d tai vi tri %d trong mang (De quy).", x, vt);
			break;
		}
		case 5:
		{
			vt = timMaxChan(a, n);
			if (vt == -1)
				printf("\nMang khong co phan tu chan nao (Khong de quy).");
			else
				printf("\nGia tri chan lon nhat (Khong de quy) la: %d", vt);

			vt = timMaxChan_DQ(a, n);
			if (vt == -1)
				printf("\nMang khong co phan tu chan nao (De quy).");
			else
				printf("\nGia tri chan lon nhat (De quy) la: %d", vt);
			break;
		}
		case 6:
		{
			printf("Tinh tong le (Khong de quy) la: %d", tinhTongLe(a, n));
			printf("\nTinh tong le (De quy) la: %d", tinhTongLe_DQ(a, n));
			break;
		}
		case 7:
		{
			printf("\nCac so o vi tri le (khong de quy): ");
			xuatViTriLe(a, n);
			printf("\nCac so o vi tri le (de quy): ");
			xuatViTriLe_DQ(a, n);
		}
		default:
			break;
		}
	} while (cn != 0);
}
void nhapSoNguyenDuong(int &x)
{
	do
	{
		printf("Ban hay nhap mot so nguyen bat ky: ");
		scanf("%d", &x);
	} while (x <= 0);
}
void taoMang1C_SoNguyen_TrongDoanXY(int * &a, int &n, int x, int y)
{
	nhapSoNguyenDuong(n);
	a = (int*)malloc(n * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = (rand() % (y - x + 1)) + x;
	}
}
void xuatMang1C_SoNguyen(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", *(a + i));
	}
}
int tinhTongChan(int *a, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			t += a[i];
	}
	return t;
}
int tinhTongChan_DQ(int *a, int n)
{
	if (n == 1)
	{
		if (a[0] % 2 == 0)
			return a[0];
		else
			return 0;
	}
	int t = tinhTongChan_DQ(a, n - 1);
	if (a[n - 1] % 2 == 0)
		t += a[n - 1];
	return t;
}
void sawp(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}
void interchangeSort(int * &a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) >  *(a + j))
				sawp(*(a + i), *(a + j));
		}
	}
}
int binarySearch(int *a, int n, int x)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x == a[mid])
			return mid;
		else if (x < a[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int binarySearch_DQ(int *a, int n, int x, int left, int right)
{
	if (left > right)
		return -1;
	int mid = (left + right) / 2;
	if (x == a[mid])
		return mid;
	if (x < a[mid])
		return binarySearch_DQ(a, n, x, left, mid - 1);
	else
		return binarySearch_DQ(a, n, x, mid + 1, right);
}
int timMaxChan(int *a, int n)
{
	int max = -1;
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			max = a[i];
			break;
		}
	}
	for (int j = i + 1; j < n; j++)
	{
		if (a[j] % 2 == 0 && max < a[j])
			max = a[j];
	}
	return max;
}
int timMaxChan_DQ(int *a, int n)
{
	if (n == 1)
	{
		if (a[0] % 2 == 0)
			return a[0];
		else
			return -1;
	}
	int max = timMaxChan_DQ(a, n - 1);
	if (a[n - 1] % 2 == 0 && max < a[n - 1])
		max = a[n - 1];
	return max;
}
int tinhTongLe(int* a, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
			t += a[i];
	}
	return t;
}
int tinhTongLe_DQ(int* a, int n)
{
	if (n == 1)
	{
		if (a[0] % 2 != 0)
			return a[0];
		else
			return 0;
	}
	int t = tinhTongLe_DQ(a, n - 1);
	if (a[n - 1] % 2 != 0)
		t += a[n - 1];
	return t;
}
void xuatViTriLe(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			printf("%5d", a[i]);
	}
}
void xuatViTriLe_DQ(int *a, int n)
{
	if (n > 0)
	{
		xuatViTriLe_DQ(a, n - 1);
		if ((n - 1) % 2 != 0)
			printf("%5d", a[n - 1]);
	}
}