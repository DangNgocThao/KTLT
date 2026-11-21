#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct SanPham
{
	char ma[6];
	char ten[11];
	double dongia;
	int solg;
}SP;
void docDSSP(SP dssp[], int &n,const char fNAME[])
{
	FILE* fi = fopen(fNAME, "rt");
	if (fi == NULL)
	{
		printf("Loi mo file de doc du lieu!");
		getch();
		return;
	}
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fi, "%[^#]%*c%[^#]%*c%lf#%d\n", &dssp[i].ma, &dssp[i].ten, &dssp[i].dongia, &dssp[i].solg);
	}
	fclose(fi);
}
void xuatDSSP(SP dssp[], int n)
{
	printf("%-10s%-15s%-15s%-15s\n", "MA SP", "TEN SP", "DON GIA", "SO LUONG");
	for (int i = 0; i < n; i++)
	{
		printf("%-10s%-15s%-15.2lf%-15d\n", dssp[i].ma, dssp[i].ten, dssp[i].dongia, dssp[i].solg);
	}
}
void swap(SP& a, SP& b)
{
	SP t = a;
	a = b;
	b = t;
}
void sxDonGiaTang(SP dssp[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dssp[i].dongia > dssp[j].dongia)
				swap(dssp[i], dssp[j]);
		}
	}
}
void sxMaTang(SP dssp[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stricmp(dssp[i].ma, dssp[j].ma) > 0)
				swap(dssp[i], dssp[j]);
		}
	}
}
int binarySearch(SP dssp[], int n, char x[])
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (stricmp(dssp[mid].ma, x) == NULL)
			return mid;
		else
			if (stricmp(dssp[mid].ma, x) < 0)
				left = mid + 1;
			else
				right = mid - 1;
	}
	return -1;
}
void xuatSPTheoMa(SP dssp[], int n, char x[])
{
	int vt = binarySearch(dssp, n, x);
	if (vt == -1)
		printf("\nKhong co ma san pham trong danh sach");
	else
	{
		printf("%-10s%-15s%-15s%-15s\n", "MA SP", "TEN SP", "DON GIA", "SO LUONG");
		printf("%-10s%-15s%-15.2lf%-15d\n", dssp[vt].ma, dssp[vt].ten, dssp[vt].dongia, dssp[vt].solg);
	}
}
void main()
{
	SP dssp[10];
	int n;
	docDSSP(dssp, n, "input.txt");
	xuatDSSP(dssp, n);
	sxDonGiaTang(dssp, n);
	printf("\nDanh sach sau khi sap xep don gia tang dan:\n");
	xuatDSSP(dssp, n);
	sxMaTang(dssp, n);
	printf("\nDanh sach sau khi sap xep ma tang dan:\n");
	xuatDSSP(dssp, n);
	char x[6];
	printf("\nNhap ma can tim: ");
	gets_s(x);
	xuatSPTheoMa(dssp, n, x);
	getch();
}
