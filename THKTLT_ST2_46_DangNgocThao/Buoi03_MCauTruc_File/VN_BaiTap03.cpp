#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct KhachHang
{
	char ho[8], hoLot[20], ten[8];
	char sdt[12];
	int veNguoiLon, veTreEm;
	char tenPhim[30];
	char phong[8];
	char xuat[2];
	int tien;
}KH;
void docDSKH(const char fName[], KH dskh[], int& n)
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
		fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%d#%d#%[^#]%*c%[^#]%*c%[^#]%*c\n", &dskh[i].ho, &dskh[i].hoLot, &dskh[i].ten, &dskh[i].sdt, &dskh[i].veNguoiLon, &dskh[i].veTreEm, &dskh[i].tenPhim, &dskh[i].phong, &dskh[i].xuat);
		dskh[i].tien = dskh[i].veNguoiLon * 40000 + dskh[i].veTreEm * 20000;
	}
	fclose(fi);
}
void xuatDSKH(KH dskh[], int n)
{
	printf("%-5s%-40s%-15s%-15s%-15s%-20s%-10s%-10s%s\n", "STT", "HO VA TEN KHACH HANG", "SO DIEN THOAI", "VE NGUOI LON", "VE TRE EM", "TEN PHIM", "PHONG", "XUAT", "TIEN");
	for (int i = 0; i < n; i++)
	{
		printf("%-5d", i + 1);
		printf("%-10s%-20s%-10s", dskh[i].ho, dskh[i].hoLot, dskh[i].ten);
		printf("%-20s", dskh[i].sdt);
		printf("%-15d", dskh[i].veNguoiLon);
		printf("%-10d", dskh[i].veTreEm);
		printf("%-20s", dskh[i].tenPhim);
		printf("%-10s", dskh[i].phong);
		printf("%-10s", dskh[i].xuat);
		printf("%d\n", dskh[i].tien);
	}
}
int tongDoanhThuRap(KH dskh[], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t += dskh[i].tien;
	}
	return t;
}
int tongDoanhThuPhim(KH dskh[], int n, KH x)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (stricmp(dskh[i].tenPhim, x.tenPhim) == NULL)
			t += dskh[i].tien;
	}
	return t;
}
int vtDauTenPhim(KH dskh[], int n, KH x)
{
	for (int i = 0; i < n; i++)
	{
		if (stricmp(dskh[i].tenPhim, x.tenPhim) == NULL)
			return i;
	}
}
void xuatDoanhThuPhim(KH dskh[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == vtDauTenPhim(dskh, n, dskh[i]))
			printf("\nTong doanh thu phim %s: %d", dskh[i].tenPhim, tongDoanhThuPhim(dskh, n, dskh[i]));
	}
}
void xuatTTPhongChieu(KH dskh[], int n, char x[], char y[])
{
	printf("%-5s%-40s%-15s%-15s%-15s%-20s%-10s%-10s%s\n", "STT", "HO VA TEN KHACH HANG", "SO DIEN THOAI", "VE NGUOI LON", "VE TRE EM", "TEN PHIM", "PHONG", "XUAT", "TIEN");
	for (int i = 0; i < n; i++)
	{
		if (stricmp(x, dskh[i].phong) == NULL && stricmp(y, dskh[i].xuat) == NULL)
		{
			printf("%-5d", i + 1);
			printf("%-10s%-20s%-10s", dskh[i].ho, dskh[i].hoLot, dskh[i].ten);
			printf("%-20s", dskh[i].sdt);
			printf("%-15d", dskh[i].veNguoiLon);
			printf("%-10d", dskh[i].veTreEm);
			printf("%-20s", dskh[i].tenPhim);
			printf("%-10s", dskh[i].phong);
			printf("%-10s", dskh[i].xuat);
			printf("%d\n", dskh[i].tien);
		}
	}
}
void swap(KH& x, KH& y)
{
	KH t = x;
	x = y;
	y = t;
}
void interchangeSort_TienTang(KH dskh[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dskh[i].tien > dskh[j].tien)
				swap(dskh[i], dskh[j]);
		}
	}
}
void selectionSort_TienTang(KH dskh[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (dskh[j].tien < dskh[vtm].tien)
				vtm = j;
			swap(dskh[i], dskh[vtm]);
		}
	}
}
void quickSort_TienTang(KH dskh[], int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	KH x = dskh[mid];
	do
	{
		while (dskh[i].tien < x.tien)
			i++;
		while (dskh[j].tien > x.tien)
			j--;
		if (i < j)
			swap(dskh[i], dskh[j]);
		i++;
		j--;
	} while (i < j);
	if (left < j)
		quickSort_TienTang(dskh, left, j);
	if (right > i)
		quickSort_TienTang(dskh, i, right);
}
void sxTangTheoHoTen(KH dskh[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			char ci[40], cj[40], kt[2] = " ";
			strcpy(ci, dskh[i].ho); strcat(ci, kt); strcat(ci, dskh[i].hoLot); strcat(ci, kt); strcat(ci, dskh[i].ten);
			strcpy(cj, dskh[j].ho); strcat(cj, kt); strcat(cj, dskh[j].hoLot); strcat(cj, kt); strcat(cj, dskh[j].ten);
			if (stricmp(ci, cj) > 0)
				swap(dskh[i], dskh[j]);
		}
	}
}
int binarySearch(KH dskh[], int n, char x[])
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		char c[40], kt[2] = " ";
		strcpy(c, dskh[mid].ho); strcat(c, kt); strcat(c, dskh[mid].hoLot); strcat(c, kt); strcat(c, dskh[mid].ten);
		if (stricmp(c, x) == NULL)
			return mid;
		else
			if (stricmp(c, x) < 0)
				left = mid + 1;
			else
				right = mid - 1;
	}
	return -1;
}
void xuatKHTheoTen(KH dskh[], int n, char x[])
{
	int vt = binarySearch(dskh, n, x);
	if (vt == -1)
		printf("\nKhong co ten khach hang dat ve");
	else
	{
		printf("%-5s%-40s%-15s%-15s%-15s%-20s%-10s%-10s%s\n", "STT", "HO VA TEN KHACH HANG", "SO DIEN THOAI", "VE NGUOI LON", "VE TRE EM", "TEN PHIM", "PHONG", "XUAT", "TIEN");
		printf("%-5d", vt + 1);
		printf("%-10s%-20s%-10s", dskh[vt].ho, dskh[vt].hoLot, dskh[vt].ten);
		printf("%-20s", dskh[vt].sdt);
		printf("%-15d", dskh[vt].veNguoiLon);
		printf("%-10d", dskh[vt].veTreEm);
		printf("%-20s", dskh[vt].tenPhim);
		printf("%-10s", dskh[vt].phong);
		printf("%-10s", dskh[vt].xuat);
		printf("%d\n", dskh[vt].tien);
	}
}
void menu()
{
	printf("\nMenu");
	printf("\n1. Doc danh sach khach hang tu file");
	printf("\n2. Xuat danh sach khach hang");
	printf("\n3. Tinh va xuat tong doanh thu cua rap phim");
	printf("\n4. Tinh tong doanh thu tung phim");
	printf("\n5. Xuat thong tin khach hang dat ve cua phong chieu x va xuat chieu y");
	printf("\n6. Sap xep danh sach khach hang theo tien tang bang Interchange Sort");
	printf("\n7. Sap xep danh sach khach hang theo tien tang bang Selection Sort");
	printf("\n8. Sap xep danh sach khach hang theo tien tang bang Quick Sort");
	printf("\n9. Sap xep danh sach tang theo ho ten");
	printf("\n10. Tim khach hang theo ho ten bang Binary Search");
}
void process()
{
	KH dskh[100];
	int n;
	int cn;
	do
	{
		menu();
		printf("\nBan hay chon mot chuc nang bat ky: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 1:
		{
			docDSKH("input.txt", dskh, n);
			break;
		}
		case 2:
		{
			xuatDSKH(dskh, n);
			break;
		}
		case 3:
		{
			printf("\nTong doanh thu cua rap: %d", tongDoanhThuRap(dskh, n));
			break;
		}
		case 4:
		{
			xuatDoanhThuPhim(dskh, n);
			break;
		}
		case 5:
		{
			char x[8], y[2];
			printf("\nNhap phong: ");
			getc(stdin);
			gets_s(x);
			printf("\nNhap xuat: ");
			gets_s(y);
			xuatTTPhongChieu(dskh, n, x, y);
			break;
		}
		case 6:
		{
			interchangeSort_TienTang(dskh, n);
			xuatDSKH(dskh, n);
			break;
		}
		case 7:
		{
			selectionSort_TienTang(dskh, n);
			xuatDSKH(dskh, n);
			break;
		}
		case 8:
		{
			quickSort_TienTang(dskh, 0, n - 1);
			xuatDSKH(dskh, n);
			break;
		}
		case 9:
		{
			sxTangTheoHoTen(dskh, n);
			xuatDSKH(dskh, n);
			break;
		}
		case 10:
		{
			char c[40];
			printf("\nNhap ho ten khach hang: ");
			getc(stdin);
			gets_s(c);
			xuatKHTheoTen(dskh, n, c);
			break;
		}
		default:
			break;
		}
	} while (cn != 0);
}
void main()
{
	process();
	getch();
}