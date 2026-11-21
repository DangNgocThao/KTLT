//#include<conio.h>
//#include<stdio.h>
//#include<string.h>
//#define MAX 100
//#define fNameIn_DSThuoc "input_DSThuoc.txt"
//#define fNameOut_DSThuoc "output_DSThuoc.txt"
//typedef struct Thuoc
//{
//	char maThuoc[6];
//	char tenThuoc[21], nhaSX[21], dangThuoc[11], congDung[51];
//	double donGia;
//}th;
//void xuatTTThuoc(th x)
//{
//	printf("%-10s%-15s%-17s%-14s%-12.0lf%-30s\n", x.maThuoc, x.tenThuoc, x.nhaSX, x.dangThuoc, x.donGia, x.congDung);
//}
//void docTTThuoc(FILE *fi, th &x)
//{
//	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%lf\n", &x.maThuoc, &x.tenThuoc, &x.nhaSX, &x.dangThuoc, &x.congDung, &x.donGia);
//}
//void ghiTTThuoc(FILE *fo, th x)
//{
//	fprintf(fo, "%-10s%-15s%-17s%-14s%-12.0lf%-30s\n", x.maThuoc, x.tenThuoc, x.nhaSX, x.dangThuoc, x.donGia, x.congDung);
//}
//void docDSThuoc(char const fNameIn[], th ds[], int &n)
//{
//	FILE *fi = fopen(fNameIn, "rt");
//	if (fi == NULL)
//	{
//		printf("Loi: mo file de doc du lieu.");
//		getch();
//		return;
//	}
//	fscanf(fi, "%d\n", &n);
//	for (int i = 0; i < n; i++)
//	{
//		th x;
//		docTTThuoc(fi, x);
//		ds[i] = x;
//	}
//	fclose(fi);
//}
//void ghiDSThuoc(char const fNameOut[], th ds[], int n)
//{
//	FILE *fo = fopen(fNameOut, "wt");
//	if (fo == NULL)
//	{
//		printf("Loi: mo file de ghi du lieu.");
//		getch();
//		return;
//	}
//	fprintf(fo, "%-5s%-10s%-15s%-17s%-14s%-12s%-30s\n", "STT", "MA THUOC", "TEN THUOC", "NHA SAN XUAT", "DANG THUOC", "DON GIA", "CONG DUNG");
//	for (int i = 0; i < n; i++)
//	{
//		fprintf(fo, "%-5d", i + 1);
//		ghiTTThuoc(fo, ds[i]);
//	}
//	fclose(fo);
//}
//void xuatDSThuoc(th ds[], int &n)
//{
//	printf("%-5s%-10s%-15s%-17s%-14s%-12s%-30s\n", "STT", "MA THUOC", "TEN THUOC", "NHA SAN XUAT", "DANG THUOC", "DON GIA", "CONG DUNG");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%-5d", i + 1);
//		xuatTTThuoc(ds[i]);
//	}
//}
//void hoanVi(th &x, th &y)
//{
//	th temp;
//	temp = x;
//	x = y;
//	y = temp;
//}
//void sxTangTheo_MaThuoc(th ds[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (stricmp(ds[i].maThuoc, ds[j].maThuoc) > 0)
//				hoanVi(ds[i], ds[j]);
//		}
//	}
//}
//int ktMaThuocT01(th a)
//{
//	char strMa[4];
//	strncpy(strMa, a.maThuoc, 3);
//	strMa[3] = '\0';
//	if (stricmp(strMa, "T01") == NULL)
//		return 1;
//	else
//		return 0;
//}
//void xuatThuocCoMaT01(th ds[], int& n)
//{
//	printf("%-5s%-10s%-15s%-17s%-14s%-12s%-30s\n", "STT", "MA THUOC", "TEN THUOC", "NHA SAN XUAT", "DANG THUOC", "DON GIA", "CONG DUNG");
//	for (int i = 0; i < n; i++)
//	{
//		if (ktMaThuocT01(ds[i]) == 1)
//		{
//			printf("%-5d", i + 1);
//			xuatTTThuoc(ds[i]);
//		}
//	}
//}
//
//void showMenu()
//{
//	printf("\nMenu");
//	printf("\n0. Thoat");
//	printf("\n1. Doc danh sach sinh vien tu file");
//	printf("\n2. Xuat danh sach ra man hinh");
//	printf("\n3. Sap xep ma Thuoc tang dan");
//	printf("\n4. Tim kiem thuoc co ma bat dau T01");
//}
//void process()
//{
//	th ds[MAX];
//	int n;
//	int cn;
//	do
//	{
//		showMenu();
//		printf("\nBan hay chon mot chuc nang bat ky: ");
//		scanf("%d", &cn);
//		switch (cn)
//		{
//		case 1:
//		{
//			docDSThuoc(fNameIn_DSThuoc, ds, n);
//			printf("DANH SACH THUOC DOC TU FILE.\n");
//			xuatDSThuoc(ds, n);
//			ghiDSThuoc(fNameOut_DSThuoc, ds, n);
//			break;
//		}
//		case 2:
//		{
//			printf("DANH SACH THUOC LA:\n");
//			xuatDSThuoc(ds, n);
//			break;
//		}
//		case 3:
//		{
//			sxTangTheo_MaThuoc(ds, n);
//			printf("DANH SACH THUOC SAU KHI SAP XEP LA:\n");
//			xuatDSThuoc(ds, n);
//			break;
//		}
//		case 4:
//		{
//			xuatThuocCoMaT01(ds, n);
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
//}