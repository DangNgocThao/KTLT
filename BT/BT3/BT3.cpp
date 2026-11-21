#include "stdio.h"
#include "conio.h"
#include "string.h"
struct NhanVien
{
	char hoten[50];
	int ngays, thangs, nams;
	char gioitinh[5];
};
void nhapThongTin(NhanVien a[], int& n);
void xuatThongTinNghiHuu(NhanVien a[], int n);
void main()
{
	NhanVien a[50];
	int n;
	nhapThongTin(a, n);
	xuatThongTinNghiHuu(a, n);
	getch();
}
void nhapThongTin(NhanVien a[], int& n)
{
	printf("\nNhap so nhan vien: ");
	scanf("%d", &n);
	getc(stdin);
	for (int i = 0; i < n; i++)
	{
		printf("\nThong tin nhan vien thu %d", i + 1);
		printf("\nTen: ");
		gets_s(a[i].hoten, 50);
		printf("\nNgay sinh: ");
		scanf("%d/%d/%d", &a[i].ngays, &a[i].thangs, &a[i].nams);
		getc(stdin);
		printf("\nGioi tinh: ");
		gets_s(a[i].gioitinh, 5);
	}
}
void xuatThongTinNghiHuu(NhanVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nThong tin nhan vien thu %d", i + 1);
		printf("\nTen: %s", a[i].hoten);
		if (stricmp(a[i].gioitinh, "nu") == 0)
			printf("\nThoi gian nghi huu: %d/%d", a[i].thangs, a[i].nams + 60);
		else
			if (stricmp(a[i].gioitinh, "nam") == 0)
				printf("\nThoi gian nghi huu: %d/%d", a[i].thangs, a[i].nams + 62);
			else
				printf("\nNhap sai!");
	}
}