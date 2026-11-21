//#include "stdio.h"
//#include "conio.h"
//#include "stdlib.h"
//#include "math.h"
//#include "time.h"
//#define MAX 100
//void menu()
//{
//	printf("\nMENU");
//	printf("\n0. Thoat");
//	printf("\n1. Tao va xuat ma tran a chua cac phan tu ngau nhien");
//	printf("\n2. Tinh va xuat tong gia tri tung dong");
//	printf("\n3. Xuat cac phan tu lon nhat tren tung cot");
//	printf("\n4. Xuat cac phan tu thuoc duong bien");
//	printf("\n5. Xuat cac phan tu cuc dai");
//	printf("\n6. Xuat cac phan tu hoang hau");
//	printf("\n7. Xuat cac phan tu la diem yen ngua");
//	printf("\n8. Xuat dong chi chua so chan");
//	printf("\n9. Sap xap mang a tang theo tung dong");
//	printf("\n10. Xuat cac cot chi chua so le");
//	printf("\n11. Tim phan tu lon nhat tren bien cua ma tran");
//	printf("\n12. So phan tu co chu so 2");
//	printf("\n13. Xuat cac phan tu cuc tieu trong ma tran");
//	printf("\n14. Sap xep cac dong co chi so le thi tang dan con cac dong co chi so chan thi giam dan");
//	printf("\n15. Sap xep cac cot co chi so le thi giam dan con cac cot co chi so chan thi tang dan");
//	printf("\n16. Kiem tra cac gia tri trong ma tran co giam dan theo cot va dong");
//	printf("\n17. Liet ke chi so cac dong chua toan gia tri chan");
//	printf("\n18. Liet ke cac dong chua gia tri giam dan");
//	printf("\n19. Tim gia tri xuat hien nhieu nhat trong ma tran");
//	printf("\n20. Tim cac chu so xuat hien nhieu nhat trong ma tran");
//	printf("\n21. Liet ke cac cot co tong nho nhat trong ma tran");
//	printf("\n22. Hoan vi hai cot trong ma tran");
//	printf("\n23. Hoan vi hai dong trong ma tran");
//}
//void nhapM2C(int a[][MAX], int& m, int& n)
//{
//	do
//	{
//		printf("\nNhap so dong so cot trong mang: ");
//		scanf("%d %d", &m, &n);
//	} while (m <= 0 || n <= 0);
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("\na[%d][%d] = ", i, j);
//			scanf("%d", &a[i][j]);
//		}
//	}
//}
//void taoM2C(int a[][MAX], int &m, int &n)
//{
//	do
//	{
//		printf("\nNhap so dong so cot trong mang: ");
//		scanf("%d %d", &m, &n);
//	} while (m <= 0 || n <= 0);
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			a[i][j] = rand() % 199 - 99;
//		}
//	}
//}
//void xuatM2C(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%5d", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//int tong1Dong(int a[][MAX], int d, int n)
//{
//	int t = 0;
//	for (int i = 0; i < n; i++)
//	{
//		t = t + a[d][i];
//	}
//	return t;
//}
//void xuatTongTungDong(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		printf("\nTong Dong %d: %d", i, tong1Dong(a, i, n));
//	}
//}
//int max1Cot(int a[][MAX], int m, int c)
//{
//	int max = a[0][c];
//	for (int i = 1; i < m; i++)
//	{
//		if (max < a[i][c])
//			max = a[i][c];
//	}
//	return max;
//}
//void xuatMaxTungCot(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("\nPhan tu lon nhat cot %d: %d", i, max1Cot(a, m, i));
//	}
//}
//void xuatBien(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
//				printf("%5d", a[i][j]);
//			else
//				printf("     ");
//		}
//		printf("\n");
//	}
//}
//int ktPhanTuCucDai(int a[][MAX], int m, int n, int d, int c)
//{
//	int CucDai = 1;
//	for (int i = -1; i <= 1; i++)
//	{
//		for (int j = -1; j <= 1; j++)
//		{
//			if (d + i >= 0 && c + j >= 0 && d + i < m && c + j < n && !(i == 0 && j == 0))
//			{
//				if (a[d][c] <= a[d + i][c + j])
//				{
//					CucDai = 0;
//				}
//				if (CucDai == 0)
//					return 0;
//			}
//		}
//	}
//	return 1;
//}
//void xuatPTCucDai(int a[][MAX], int m, int n)
//{
//	printf("\nCac phan tu cuc dai: ");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ktPhanTuCucDai(a, m, n, i, j) == 1)
//				printf("%5d", a[i][j]);
//		}
//	}
//}
//int ktPTHoangHau(int a[][MAX], int m, int n, int d, int c)
//{
//	int x = a[d][c];
//	for (int i = 0; i < n; i++)
//	{
//		if (a[d][i] > x)
//		{
//			return 0;
//		}
//	}
//	for (int j = 0; j < m; j++)
//	{
//		if (a[j][c] > x)
//		{
//			return 0;
//		}
//	}
//	int d1 = d + 1;
//	int c1 = c + 1;
//	while (c1 + 1 < n && d1 < m)
//	{
//		if (a[c1][d1] > x)
//			return 0;
//		c1++;
//		d1++;
//	}
//	d1 = d - 1;
//	c1 = c - 1;
//	while (c1 - 1 >= 0 && d1 >= 0)
//	{
//		if (a[c1][d1] > x)
//			return 0;
//		c1--;
//		d1--;
//	}
//	d1 = d + 1;
//	c1 = c - 1;
//	while (c1 - 1 >= 0 && d1 < m)
//	{
//		if (a[c1][d1] > x)
//			return 0;
//		c1--;
//		d1++;
//	}
//	d1 = d - 1;
//	c1 = c + 1;
//	while (c1 + 1 < n && d1 >= 0)
//	{
//		if (a[c1][d1] > x)
//			return 0;
//		c1++;
//		d1--;
//	}
//	return 1;
//}
//void xuatPTHoangHau(int a[][MAX], int m, int n)
//{
//	printf("\nCac phan tu hoang hau: ");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ktPTHoangHau(a, m, n, i, j) == 1)
//				printf("%5d", a[i][j]);
//		}
//	}
//}
//int min1Cot(int a[][MAX], int m, int c)
//{
//	int min = a[0][c];
//	for (int i = 1; i < m; i++)
//	{
//		if (min > a[i][c])
//			min = a[i][c];
//	}
//	return min;
//}
//int max1Dong(int a[][MAX], int d, int n)
//{
//	int max = a[d][0];
//	for (int i = 1; i < n; i++)
//	{
//		if (max < a[d][i])
//			max = a[d][i];
//	}
//	return max;
//}
//int min1Dong(int a[][MAX], int d, int n)
//{
//	int min = a[d][0];
//	for (int i = 1; i < n; i++)
//	{
//		if (min > a[d][i])
//			min = a[d][i];
//	}
//	return min;
//}
//int ktPTYenNgua(int a[][MAX], int m, int n, int d, int c)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if ((a[d][c] == min1Dong(a, i, n) && a[d][c] == max1Cot(a, m, j)) || (a[d][c] == max1Dong(a, i, n) && a[d][c] == min1Cot(a, m, j)))
//				return 1;
//		}
//	}
//	return 0;
//}
//void xuatPTYenNgua(int a[][MAX], int m, int n)
//{
//	printf("\nCac phan tu yen ngua: ");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ktPTYenNgua(a, m, n, i, j) == 1)
//				printf("%5d", a[i][j]);
//		}
//	}
//}
//int ktDongToanChan(int a[][MAX], int d, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (a[d][i] % 2 != 0)
//			return 0;
//	}
//	return 1;
//}
//void xuat1Dong(int a[][MAX], int d, int n)
//{
//	printf("\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%5d", a[d][i]);
//	}
//}
//void xuatDongToanChan(int a[][MAX], int m, int n)
//{
//	printf("\nDong chi chua so chan: ");
//	for (int i = 0; i < m; i++)
//	{
//		if (ktDongToanChan(a, i, n) == 1)
//			xuat1Dong(a, i, n);
//	}
//}
//void swap(int &a, int &b)
//{
//	int t = a;
//	a = b;
//	b = t;
//}
//void sx1DongTang(int a[][MAX], int d, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[d][i] > a[d][j])
//				swap(a[d][i], a[d][j]);
//		}
//	}
//}
//void sxDongTang(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		sx1DongTang(a, i, n);
//	}
//}
//int ktCotToanLe(int a[][MAX], int m, int c)
//{
//	for (int i = 0; i < m; i++)
//	{
//		if (a[i][c] % 2 == 0)
//			return 0;
//	}
//	return 1;
//}
//void xuatCotToanLe(int a[][MAX], int m, int n)
//{
//	printf("\nCac cot chi chua so le:\n");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ktCotToanLe(a, m, j) == 1)
//				printf("%5d", a[i][j]);
//			else
//				printf("     ");
//		}
//		printf("\n");
//	}
//}
//int MaxBien(int a[][MAX], int m, int n)
//{
//	int max = a[0][0];
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (max < a[i][j] && (i == 0 || i == m - 1 || j == 0 || j == n - 1))
//				max = a[i][j];
//		}
//	}
//	return max;
//}
//int ktCoChuSo2(int x)
//{
//	int cs = abs(x);
//	while (cs!=0)
//	{
//		if (cs % 10 == 2)
//			return 1;
//		cs /= 10;
//	}
//	return 0;
//}
//int demPTCoChuSo2(int a[][MAX], int m, int n)
//{
//	int d = 0;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ktCoChuSo2(a[i][j]) == 1)
//				d++;
//		}
//	}
//	return d;
//}
//int ktPhanTuCucTieu(int a[][MAX], int m, int n, int d, int c)
//{
//	int CucTieu = 1;
//	for (int i = -1; i <= 1; i++)
//	{
//		for (int j = -1; j <= 1; j++)
//		{
//			if (d + i >= 0 && c + j >= 0 && d + i < m && c + j < n && !(i == 0 && j == 0))
//			{
//				if (a[d][c] >= a[d + i][c + j])
//				{
//					CucTieu = 0;
//				}
//				if (CucTieu == 0)
//					return 0;
//			}
//		}
//	}
//	return 1;
//}
//void xuatCucTieu(int a[][MAX], int m, int n)
//{
//	printf("\nCac phan tu cuc tieu trong ma tran: ");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ktPhanTuCucTieu(a, m, n, i, j) == 1)
//				printf("%5d", a[i][j]);
//		}
//	}
//}
//void sx1DongGiam(int a[][MAX], int d, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[d][i] < a[d][j])
//				swap(a[d][i], a[d][j]);
//		}
//	}
//}
//void sx1CotTang(int a[][MAX], int m, int c)
//{
//	for (int i = 0; i < m - 1; i++)
//	{
//		for (int j = i + 1; j < m; j++)
//		{
//			if (a[i][c] > a[j][c])
//				swap(a[i][c], a[j][c]);
//		}
//	}
//}
//void sx1CotGiam(int a[][MAX], int m, int c)
//{
//	for (int i = 0; i < m - 1; i++)
//	{
//		for (int j = i + 1; j < m; j++)
//		{
//			if (a[i][c] < a[j][c])
//				swap(a[i][c], a[j][c]);
//		}
//	}
//}
//void sxDongLeTangChanGiam(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		if (i % 2 == 0)
//			sx1DongGiam(a, i, n);
//		else
//			sx1DongTang(a, i, n);
//	}
//}
//void sxCotLeGiamChanTang(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (i % 2 == 0)
//			sx1CotTang(a, m, i);
//		else
//			sx1CotGiam(a, m, i);
//	}
//}
//int ktCotGiam(int a[][MAX], int m, int c)
//{
//	for (int i = 0; i < m - 1; i++)
//	{
//		if (a[i][c] <= a[i + 1][c])
//			return 0;
//	}
//	return 1;
//}
//int ktDongGiam(int a[][MAX], int d, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (a[d][i] <= a[d][i + 1])
//			return 0;
//	}
//	return 1;
//}
//int ktGiamDanTheoCotVaDong(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ktCotGiam(a, m, j) == 0 || ktDongGiam(a, i, n) == 0)
//				return 0;
//		}
//	}
//	return 1;
//}
//void chiSoDongToanChan(int a[][MAX], int m, int n)
//{
//	int kt;
//	for (int i = 0; i < m; i++)
//	{
//		kt = 1;
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] % 2 != 0)
//			{
//				kt = 0;
//				break;
//			}
//		}
//		if (kt == 1)
//			printf("%5d", i);
//	}
//}
//void TachChuSo(int n, int b[])
//{
//	int ChuSo;
//	n = abs(n);
//	do
//	{
//		ChuSo = n % 10;
//		b[ChuSo]++;
//		n /= 10;
//	} while (n > 0);
//}
//void CacChuSoXuatHienNhieuNhat(int a[][MAX], int m, int n)
//{
//	int b[10] = { 0 };
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			TachChuSo(a[i][j], b);
//		}
//	}
//	int ChuSoXHNN = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (b[ChuSoXHNN] < b[i])
//			ChuSoXHNN = i;
//	}
//	printf("\nCac chu so xuat hien nhieu nhat: ");
//	for (int i = 0; i < 10; i++)
//	{
//		if (b[ChuSoXHNN] == b[i])
//			printf("%5d", i);
//	}
//}
//void cacDongGiamDan(int a[][MAX], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		if (ktDongGiam(a, i, n) == 1)
//			printf("%5d", i);
//	}
//}
//int demSoLanXuatHien(int a[][MAX], int m, int n, int x)
//{
//	int d = 0;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] == x)
//				d++;
//		}
//	}
//	return d;
//}
//int soXuatHienNhieuNhat(int a[][MAX], int m, int n)
//{
//	int max = demSoLanXuatHien(a, m, n, a[0][0]);
//	int gt = a[0][0];
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 1; j < n; j++)
//		{
//			if (demSoLanXuatHien(a, m, n, a[i][j]) > max)
//			{
//				max = demSoLanXuatHien(a, m, n, a[i][j]);
//				gt = a[i][j];
//			}
//		}
//	}
//	return gt;
//}
//int tongCot(int a[][MAX], int m, int c)
//{
//	int t = 0;
//	for (int i = 0; i < m; i++)
//	{
//		t = t + a[i][c];
//	}
//	return t;
//}
//int tongCotMin(int a[][MAX], int m, int n)
//{
//	int min = tongCot(a, m, 0);
//	for (int i = 1; i < n; i++)
//	{
//		if (tongCot(a, m, i) < min)
//			min = tongCot(a, m, i);
//	}
//	return min;
//}
//void cacCotTongMin(int a[][MAX], int m, int n)
//{
//	int min = tongCotMin(a, m, n);
//	for (int i = 0; i < n; i++)
//	{
//		if (tongCot(a, m, i) == min)
//			printf("%5d", i);
//	}
//}
//void hoanVi(int& a, int& b)
//{
//	int t = a;
//	a = b;
//	b = t;
//}
//void doiCot(int a[][MAX], int m, int c1, int c2)
//{
//	for (int i = 0; i < m; i++)
//	{
//		hoanVi(a[i][c1], a[i][c2]);
//	}
//}
//void doiDong(int a[][MAX], int d1, int d2, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		hoanVi(a[d1][i], a[d2][i]);
//	}
//}
//void main()
//{
//	int a[MAX][MAX];
//	int m, n, cn;
//	do
//	{
//		menu();
//		printf("\nChon chuc nang: ");
//		scanf("%d", &cn);
//		switch (cn)
//		{
//		case 0:
//		{
//			exit(1);
//		}
//		case 1:
//		{
//			taoM2C(a, m, n);
//			printf("\nNoi dung ma tran:\n");
//			xuatM2C(a, m, n);
//			break;
//		}
//		case 2:
//		{
//			xuatTongTungDong(a, m, n);
//			break;
//		}
//		case 3:
//		{
//			xuatMaxTungCot(a, m, n);
//			break;
//		}
//		case 4:
//		{
//			xuatBien(a, m, n);
//			break;
//		}
//		case 5:
//		{
//			xuatPTCucDai(a, m, n);
//			break;
//		}
//		case 6:
//		{
//			xuatPTHoangHau(a, m, n);
//			break;
//		}
//		case 7:
//		{
//			xuatPTYenNgua(a, m, n);
//			break;
//		}
//		case 8:
//		{
//			xuatDongToanChan(a, m, n);
//			break;
//		}
//		case 9:
//		{
//			sxDongTang(a, m, n);
//			xuatM2C(a, m, n);
//			break;
//		}
//		case 10:
//		{
//			xuatCotToanLe(a, m, n);
//			break;
//		}
//		case 11:
//		{
//			printf("\nPhan tu lon nhat tren bien cua ma tran: %d", MaxBien(a, m, n));
//			break;
//		}
//		case 12:
//		{
//			printf("\nCo %d phan tu co chu so 2", demPTCoChuSo2(a, m, n));
//			break;
//		}
//		case 13:
//		{
//			xuatCucTieu(a, m, n);
//			break;
//		}
//		case 14:
//		{
//			sxDongLeTangChanGiam(a, m, n);
//			printf("\nNoi dung ma tran:\n");
//			xuatM2C(a, m, n);
//			break;
//		}
//		case 15:
//		{
//			sxCotLeGiamChanTang(a, m, n);
//			printf("\nNoi dung ma tran:\n");
//			xuatM2C(a, m, n);
//			break;
//		}
//		case 16:
//		{
//			int kq = ktGiamDanTheoCotVaDong(a, m, n);
//			if (kq == 1)
//				printf("\nCac gia tri trong ma tran giam dan theo cot va dong");
//			else
//				printf("\nCac gia tri trong ma tran khong giam dan theo cot va dong");
//			break;
//		}
//		case 17:
//		{
//			printf("\nChi so cac dong chua toan gia tri chan: ");
//			chiSoDongToanChan(a, m, n);
//			break;
//		}
//		case 18:
//		{
//			printf("\nCac dong chua gia tri giam dan: ");
//			cacDongGiamDan(a, m, n);
//			break;
//		}
//		case 19:
//		{
//			printf("\nGia tri xuat hien nhieu nhat trong ma tran: %d", soXuatHienNhieuNhat(a, m, n));
//			break;
//		}
//		case 20:
//		{
//			CacChuSoXuatHienNhieuNhat(a, m, n);
//			break;
//		}
//		case 21:
//		{
//			printf("\nCac cot co tong nho nhat trong ma tran: ");
//			cacCotTongMin(a, m, n);
//			break;
//		}
//		case 22:
//		{
//			int c1, c2;
//			do
//			{
//				printf("\nNhap hai cot can hoan vi: ");
//				scanf("%d %d", &c1, &c2);
//			} while (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n);
//			doiCot(a, m, c1, c2);
//			printf("\nNoi dung ma tran:\n");
//			xuatM2C(a, m, n);
//			break;
//		}
//		case 23:
//		{
//			int d1, d2;
//			do
//			{
//				printf("\nNhap hai dong can hoan vi: ");
//				scanf("%d %d", &d1, &d2);
//			} while (d1 < 0 || d1 >= m || d2 < 0 || d2 >= m);
//			doiDong(a, d1, d2, n);
//			printf("\nNoi dung ma tran:\n");
//			xuatM2C(a, m, n);
//			break;
//		}
//		default:
//			break;
//		}
//	} while (1);
//	getch();
//}
