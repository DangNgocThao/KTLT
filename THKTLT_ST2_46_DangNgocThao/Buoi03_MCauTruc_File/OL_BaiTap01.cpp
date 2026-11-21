#include<conio.h>
#include<stdio.h>
#include<string.h>
#define fileName_In "input_SV_1.txt"
#define fileName_Out "output_SV_1.txt"
#define fileName_In_DSSV "input_DSSV.txt"
#define fileName_Out_DSSV1 "output_DSSV_1.txt"
#define fileName_Out_DSSV2 "output_DSSV_2.txt"
#define fileName_Out_DSSV3 "output_DSSV_3.txt"
typedef struct SinhVien
{
	char mssv[11];
	char ho[8], hoLot[20], ten[8];
	double diemTB;
}SV;
void xuatTTSV(SV x)
{
	printf("%-15s%-10s%-20s%-10s%5.2lf\n", x.mssv, x.ho, x.hoLot, x.ten, x.diemTB);
}
void docTTSV(FILE *fi, SV &x)
{
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%lf\n", &x.mssv, &x.ho, &x.hoLot, &x.ten, &x.diemTB);
}
void ghiTTSV(FILE *fo, SV x)
{
	fprintf(fo, "%-15s%-10s%-20s%-10s%5.2lf\n", x.mssv, x.ho, x.hoLot, x.ten, x.diemTB);
}
void xuatDSSV(SV ds[], int &n)
{
	printf("%-5s%-15s%-40s%-10s\n", "STT", "MSSV", "HO VA TEN SINH VIEN", "DIEM TB");
	for (int i = 0; i < n; i++)
	{
		printf("%-5d", i + 1);
		xuatTTSV(ds[i]);
	}
}
void docDSSV(const char fName[], SV ds[], int &n)
{
	FILE *fi = fopen(fName, "rt");
	if (fi == NULL)
	{
		printf("Loi mo file de doc du lieu!");
		getch();
		return;
	}
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		SV x;
		docTTSV(fi, x);
		ds[i] = x;
	}
	fclose(fi);
}
void ghiDSSV(const char fName[], SV ds[], int n)
{
	FILE *fo = fopen(fName, "w+");
	if (fo == NULL)
	{
		printf("Loi mo file de ghi du lieu!");
		getch();
		return;
	}
	fprintf(fo, "%-5s%-15s%-40s%-10s\n", "STT", "MSSV", "HO VA TEN SINH VIEN", "DIEM TB");
	for (int i = 0; i < n; i++)
	{
		fprintf(fo, "%-5d", i + 1);
		SV x = ds[i];
		ghiTTSV(fo, x);
	}
	fclose(fo);
}
void hoanVi(SV &x, SV &y)
{
	SV temp = x;
	x = y;
	y = temp;
}
void sxTangTheoTen(SV ds[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stricmp(ds[i].ten, ds[j].ten) > 0)
				hoanVi(ds[i], ds[j]);
		}
	}
}
void sxGiamTheoDiemTB(SV ds[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ds[i].diemTB < ds[j].diemTB)
				hoanVi(ds[i], ds[j]);
		}
	}
}
//void menu()
//{
//	printf("\n***********************************************");
//	printf("\n*                    MENU                     *");
//	printf("\n***********************************************");
//	printf("\n* 0. Thoat                                    *");
//	printf("\n* 1. Doc danh sach sinh vien                  *");
//	printf("\n* 2. Sap xep tang theo ten                    *");
//	printf("\n* 3. Sap xep giam theo diem                   *");
//	printf("\n***********************************************");
//}
//void process()
//{
//	SV dssv[10];
//	int n;
//	int cn;
//	do
//	{
//		menu();
//		printf("\nBan hay chon mot chuc nang bat ky: ");
//		scanf("%d", &cn);
//		switch (cn)
//		{
//		case 1:
//		{
//			docDSSV(fileName_In_DSSV, dssv, n);
//			printf("DANH SACH SINH VIEN\n");
//			xuatDSSV(dssv, n);
//			ghiDSSV(fileName_Out_DSSV1, dssv, n);
//			break;
//		}
//		case 2:
//		{
//			sxTangTheoTen(dssv, n);
//			printf("DANH SACH SINH VIEN SAU KHI SAP XEP TANG DAN THEO TEN\n");
//			xuatDSSV(dssv, n);
//			ghiDSSV(fileName_Out_DSSV2, dssv, n);
//			break;
//		}
//		case 3:
//		{
//			sxGiamTheoDiemTB(dssv, n);
//			printf("DANH SACH SINH VIEN SAU KHI SAP XEP GIAM DAN THEO DIEM TB\n");
//			xuatDSSV(dssv, n);
//			ghiDSSV(fileName_Out_DSSV3, dssv, n);
//			break;
//		}
//		default:
//			break;
//		}
//	} while (cn != 0);
//}
//void main()
//{
//	process();
//	getch();
//}