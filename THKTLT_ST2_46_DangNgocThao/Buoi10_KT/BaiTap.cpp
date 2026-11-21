#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void nhapSoNguyenDuong(int &x);
void taoMang1C_SoNguyen_TrongDoanXY(int * &a, int &n, int x, int y);
void xuatMang1C_SoNguyen(int *a, int n);
int tinhTichChan_DQ(int* a, int n);
int ktChuSo4_DQ(int n);
void xuatPTChuaSo4_DQ(int* a, int n);
double tinhSn(int n);
double tinhSn_DQ(int n);
int tinhTongChuSoChanN(int n);
int tinhTongChuSoChanN_DQ(int n);
int fibonaci(int n);
void xuatDayFibonaciMN_Le(int m, int n);
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
	printf("\n3. Tich cac so chan trong mang");
	printf("\n4. Xuat cac phan tu co chua chu so 4");
	printf("\n5. Tinh Sn");
	printf("\n6. Tong cac chu so chan cua so nguyen n");
	printf("\n7. Xuat cac so fibonaci thuoc doan [m,n]");
}
void process()
{
	int *a = new int;
	int N, x, vt, m, n;
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
			taoMang1C_SoNguyen_TrongDoanXY(a, N, 0, 99);
			printf("\nNoi dung cua mang la: ");
			xuatMang1C_SoNguyen(a, N);
			break;
		}
		case 2:
		{
			printf("\nNoi dung cua mang la: ");
			xuatMang1C_SoNguyen(a, N);
			break;
		}
		case 3:
		{
			printf("\nTich chan: %d", tinhTichChan_DQ(a, N));
			break;
		}
		case 4:
		{
			printf("\nCac phan tu co chua chu so 4: ");
			xuatPTChuaSo4_DQ(a, N);
			break;
		}
		case 5:
		{
			nhapSoNguyenDuong(n);
			printf("\nSn (khong de quy) = %.3lf", tinhSn(n));
			printf("\nSn (de quy) = %.3lf", tinhSn_DQ(n));
			break;
		}
		case 6:
		{
			nhapSoNguyenDuong(n);
			printf("\nTong cac chu so nguyen chan (khong de quy) la: %d", tinhTongChuSoChanN(n));
			printf("\nTong cac chu so nguyen chan (de quy) la: %d", tinhTongChuSoChanN_DQ(n));
			break;
		}
		case 7:
		{
			nhapSoNguyenDuong(m);
			nhapSoNguyenDuong(n);
			printf("\nXuat cac so Fibonaci le thuoc doan [%d, %d] la: ", m, n);
			xuatDayFibonaciMN_Le(m, n);
			break;
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
	a = (int *)malloc(n*sizeof(int));
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
int tinhTichChan_DQ(int* a, int n)
{
	if (n == 1)
	{
		if (a[0] % 2 == 0)
			return a[0];
		else
			return 1;
	}
	int t = tinhTichChan_DQ(a, n - 1);
	if (a[n - 1] % 2 == 0)
		t *= a[n - 1];
	return t;
}
int ktChuSo4_DQ(int n)
{
	if (n == 0) return 0;
	if (n % 10 == 4) return 1;
	return ktChuSo4_DQ(n / 10);
}
void xuatPTChuaSo4_DQ(int* a, int n)
{
	if (n > 0)
	{
		xuatPTChuaSo4_DQ(a, n - 1);
		if (ktChuSo4_DQ(a[n - 1]) == 1)
			printf("%5d", a[n - 1]);
	}
}
double tinhSn(int n)
{
	double t = 0;
	for (int i = 1; i <= n; i++)
	{
		t += i / (i * pow(i + 1, i));
	}
	return t;
}
double tinhSn_DQ(int n)
{
	if (n == 1)	return 0.5;
	return n / (n * pow(n + 1, n)) + tinhSn_DQ(n - 1);
}
int tinhTongChuSoChanN(int n)
{
	int tong = 0;
	while (n != 0)
	{
		int sodu = n % 10;
		if (sodu % 2 == 0)
			tong += sodu;
		n /= 10;
	}
	return tong;
}
int tinhTongChuSoChanN_DQ(int n)
{
	if (n == 0)
	{
		return 0;
	}
	int sodu = n % 10;
	if (sodu % 2 == 0)
		return sodu + tinhTongChuSoChanN_DQ(n / 10);
	else
		return tinhTongChuSoChanN_DQ(n / 10);
}
int fibonaci(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fibonaci(n - 1) + fibonaci(n - 2);
}
void xuatDayFibonaciMN_Le(int m, int n)
{
	int i = 1;
	while (fibonaci(i) < m)
	{
		i++;
	}
	int fi;
	while ( (fi = fibonaci(i)) <= n)
	{
		if (fi % 2 != 0)
			printf("%5d", fi);
		i++;
	}
}