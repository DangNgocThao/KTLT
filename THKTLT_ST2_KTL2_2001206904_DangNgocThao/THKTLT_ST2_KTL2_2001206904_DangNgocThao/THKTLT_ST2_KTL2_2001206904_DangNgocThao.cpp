/***********************************/
/* Họ và tên: Đặng Ngọc Thảo       */
/* Mã số SV : 2001206904           */
/* Lớp: 11DHTH15                   */
/* Thứ: 2                          */
/* Tiết: 456                       */
/* Bài tập Buổi 10: Kiểm tra Lần 2 */
/***********************************/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
struct Sach
{
	char ma[11];
	char ten[31];
	float dongia;
	int nam;
};
void taoMang1C_SoNguyen_TrongDoanXY(int*& a, int& n, int x, int y);
void xuatMang1C_DQ(int* a, int n);
int ktChucLonHonDonVi(int n);
void xuatPTChucLonHonDonVi_DQ(int a[], int n);
int tongChuSo_DQ(int n);
int tongPTCoTongChuSoLaChan_DQ(int* a, int n);
int tinhTongN(int n);
double tinhSn(int x, int n);
double tinhSn_DQ(int x, int n);
int demChuSo(int n);
int demChuSo_DQ(int n);
int tinhXn_DQ(int n);
void docDSSach(const char fName[], Sach ds[], int& n);
void xuatTTSach(Sach ds);
void xuatDSSach(Sach ds[], int n);
int timTheoMa(Sach ds[], int n, char x[]);
void xuatTTSachTimDuoc(Sach ds[], int n, int vt);
void showMenu();
void process();
void main()
{
	process();
	getch();
}
void taoMang1C_SoNguyen_TrongDoanXY(int*& a, int& n, int x, int y)
{
	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", &n);
	} while (n <= 0);
	a = (int*)malloc(n * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = (rand() % (y - x + 1)) + x;
	}
}
void xuatMang1C_DQ(int* a, int n)
{
	if (n > 0)
	{
		xuatMang1C_DQ(a, n - 1);
		printf("%5d", a[n - 1]);
	}
}
int ktChucLonHonDonVi(int n)
{
	if (n / 10 % 10 > n % 10)
		return 1;
	else
		return 0;
}
void xuatPTChucLonHonDonVi_DQ(int a[], int n)
{
	if (n > 0)
	{
		xuatPTChucLonHonDonVi_DQ(a, n - 1);
		if (ktChucLonHonDonVi(a[n - 1]) == 1)
			printf("%5d", a[n - 1]);
	}
}
int tongChuSo_DQ(int n)
{
	if (n < 10)	return n;
	return n % 10 + tongChuSo_DQ(n / 10);
}
int tongPTCoTongChuSoLaChan_DQ(int* a, int n)
{
	if (n == 1)
	{
		if (tongChuSo_DQ(a[0]) % 2 == 0)
			return a[0];
		else
			return 0;
	}
	int t = tongPTCoTongChuSoLaChan_DQ(a, n - 1);
	if (tongChuSo_DQ(a[n - 1]) % 2 == 0)
		t += a[n - 1];
	return t;
}
int tinhTongN(int n)
{
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = t + i;
	}
	return t;
}
double tinhSn(int x, int n)
{
	double t = 0;
	for (int i = 1; i <= n; i++)
	{
		t += pow(x, i) / tinhTongN(i);
	}
	return t;
}
double tinhSn_DQ(int x, int n)
{
	if (n == 1) return x;
	return pow(x, n) / tinhTongN(n) + tinhSn_DQ(x, n - 1);
}
int demChuSo(int n)
{
	int d = 0;
	while (n > 0)
	{
		d++;
		n /= 10;
	}
	return d;
}
int demChuSo_DQ(int n)
{
	if (n < 10)
		return 1;
	else
		return 1 + demChuSo_DQ(n / 10);
}
int tinhXn_DQ(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	else
	{
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			s += (n - i) * tinhXn_DQ(i);
		}
		return s;
	}
}
void docDSSach(const char fName[], Sach ds[], int& n)
{
	FILE* fi = fopen(fName, "rt");
	if (fi == NULL)
	{
		printf("Loi mo file de doc du lieu!");
		getch();
		return;
	}
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fi, "%[^#]%*c%[^#]%*c%f#%d\n", &ds[i].ma, &ds[i].ten, &ds[i].dongia, &ds[i].nam);
	}
	fclose(fi);
}
void xuatTTSach(Sach ds)
{
	printf("%-15s%-20s%-15.3f%-15d%\n", ds.ma, ds.ten, ds.dongia, ds.nam);
}
void xuatDSSach(Sach ds[], int n)
{
	printf("%-5s%-15s%-20s%-15s%-15s%\n", "STT", "MA SACH", "TEN SACH", "DON GIA", "NAM SAN XUAT");
	for (int i = 0; i < n; i++)
	{
		printf("%-5d", i + 1);
		xuatTTSach(ds[i]);
	}
}
int timTheoMa(Sach ds[], int n, char x[])
{
	for (int i = 0; i < n; i++)
	{
		if (stricmp(ds[i].ma, x) == NULL)
			return i;
	}
	return -1;
}
void xuatTTSachTimDuoc(Sach ds[], int n, int vt)
{
	printf("%-5s%-15s%-20s%-15s%-15s%\n", "STT", "MA SACH", "TEN SACH", "DON GIA", "NAM SAN XUAT");
	printf("%-5d", vt + 1);
	xuatTTSach(ds[vt]);
}
void showMenu()
{
	printf("\nMenu");
	printf("\n0. Thoat");
	printf("\n1. Tao mang 1 chieu so nguyen");
	printf("\n2. Xuat mang 1 chieu so nguyen");
	printf("\n3. Xuat cac phan tu co chu so hang chuc lon hon chu so hang don vi");
	printf("\n4. Tinh tong cac phan tu co tong tat ca cac chu so la mot so chan");
	printf("\n5. Tinh Sn");
	printf("\n6. Dem so luong chu so cua mot so nguyen duong n");
	printf("\n7. Tinh Xn");
	printf("\n8. Doc thong tin sach tu file");
	printf("\n9. xuat thong tin sach");
	printf("\n10. Tim va cho biet thong tin cua mot cuon sach co ma so x");
}
void process()
{
	int* a = new int;
	int n;
	Sach ds[100];
	int cn;
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 1:
		{
			taoMang1C_SoNguyen_TrongDoanXY(a, n, 0, 500);
			printf("\nNoi dung cua mang la: ");
			xuatMang1C_DQ(a, n);
			break;
		}
		case 2:
		{
			printf("\nNoi dung cua mang la: ");
			xuatMang1C_DQ(a, n);
			break;
		}
		case 3:
		{
			printf("\nCac phan tu co chu so hang chuc lon hon chu so hang don vi: ");
			xuatPTChucLonHonDonVi_DQ(a, n);
			break;
		}
		case 4:
		{
			printf("\nTong cac phan tu co tong tat ca cac chu so la mot so chan: %d", tongPTCoTongChuSoLaChan_DQ(a, n));
			break;
		}
		case 5:
		{
			int x, N;
			printf("\nNhap x: ");
			scanf("%d", &x);
			do
			{
				printf("\nNhap thu hang can tinh: ");
				scanf("%d", &N);
			} while (N < 1);
			printf("\nSn (khong de quy) = %.3lf", tinhSn(x, N));
			printf("\nSn (de quy) = %.3lf", tinhSn_DQ(x, N));
			break;
		}
		case 6:
		{
			int N;
			do
			{
				printf("\nNhap so phan tu: ");
				scanf("%d", &N);
			} while (N <= 0);
			printf("\nSo chu so cua %d (khong de quy) la: %d", N, demChuSo(N));
			printf("\nSo chu so cua %d (de quy) la: %d", N, demChuSo_DQ(N));
			break;
		}
		case 7:
		{
			int N;
			do
			{
				printf("\nNhap thu hang can tinh: ");
				scanf("%d", &N);
			} while (N < 0);
			printf("\nXn = %d", tinhXn_DQ(N));
			break;
		}
		case 8:
		{
			docDSSach("dsSach.txt", ds, n);
			xuatDSSach(ds, n);
			break;
		}
		case 9:
		{
			xuatDSSach(ds, n);
			break;
		}
		case 10:
		{
			int kq;
			char x[11];
			printf("\nNhap ma can tim: ");
			getc(stdin);
			gets_s(x);
			kq = timTheoMa(ds, n, x);
			if (kq == -1)
				printf("\nKhong tim thay sach co ma do");
			else
				xuatTTSachTimDuoc(ds, n, kq);
			break;
		}
		default:
			break;
		}
	} while (cn != 0);
}