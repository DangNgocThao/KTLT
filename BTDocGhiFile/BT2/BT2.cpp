#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
struct SV
{
	char ms[15];
	char hoten[50];
	float dtb;
};
void menu();
void nhapThongTinSV(SV a[], int& n);
void xuatThongTinSV(SV a[], int n);
void ghiFile(SV a[], int n);
void docFile(SV a[], int& n);
void main()
{
	SV a[50];
	int n, c;
	do
	{
		menu();
		printf("\nHay chon mot chuc nang cua chuong trinh: ");
		scanf("%d", &c);
		switch (c)
		{
		case 0:
		{
			exit(1);
			break;
		}
		case 1:
		{
			nhapThongTinSV(a, n);
			break;
		}
		case 2:
		{
			xuatThongTinSV(a, n);
			break;
		}
		case 3:
		{
			ghiFile(a, n);
			break;
		}
		case 4:
		{
			docFile(a, n);
			break;
		}
		}
	} while (1);
	getch();
}
void menu()
{
	printf("\nMENU");
	printf("\n0. Thoat");
	printf("\n1. Nhap thong tin sinh vien");
	printf("\n2. Xuat thong tin sinh vien");
	printf("\n3. Ghi file");
	printf("\n4. Doc file");
}
void nhapThongTinSV(SV a[], int& n)
{
	do
	{
		printf("\nNhap so sinh vien: ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		getc(stdin);
		printf("\nNhap ma so sinh vien: ");
		gets_s(a[i].ms);
		printf("\nNhap ho ten: ");
		gets_s(a[i].hoten);
		printf("\nNhap diem trung binh: ");
		scanf("%f", &a[i].dtb);
	}
}
void xuatThongTinSV(SV a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nThong tin sinh vien thu %d", i + 1);
		printf("\nMa so sinh vien: %s", a[i].ms);
		printf("\nHo ten: %s", a[i].hoten);
		printf("\nDiem trung binh: %.2f", a[i].dtb);
	}
}
void ghiFile(SV a[], int n)
{
	FILE* fb;
	fb = fopen("input.txt", "wb");
	fwrite(&n, sizeof(int), 1, fb);
	for (int i = 0; i < n; i++)
	{
		fwrite(&a[i].ms, sizeof(a[i].ms), n, fb);
		fwrite(&a[i].hoten, sizeof(a[i].hoten), n, fb);
		fwrite(&a[i].dtb, sizeof(float), n, fb);
	}
	fclose(fb);
}
void docFile(SV a[], int& n)
{
	FILE* fb;
	fb = fopen("input.txt", "rb");
	fread(&n, sizeof(int), 1, fb);
	for (int i = 0; i < n; i++)
	{
		fread(&a[i].ms, sizeof(a[i].ms), n, fb);
		fread(&a[i].hoten, sizeof(a[i].hoten), n, fb);
		fread(&a[i].dtb, sizeof(float), n, fb);
	}
	fclose(fb);
}