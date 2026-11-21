#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#define MAX 100
void menu();
void nhapM2C(int a[][MAX], int& m, int& n);
void xuatM2C(int a[][MAX], int m, int n);
int ktChuSoDauLe(int n);
int tongCacSoChuSoDauLe(int a[][MAX], int m, int n);
int demCacSoChuSoChucLa5(int a[][MAX], int m, int n);
int ktSoHoanThien(int x);
void xuatCacSoHT(int a[][MAX], int m, int n);
int tongCacPTLonHonTriTuyetDoiCuaPTLienSauDo(int a[][MAX], int m, int n);
int tongCacPTCucTri(int a[][MAX], int m, int n);
int tong1Dong(int a[][MAX], int d, int n);
int tongDuongTren1Dong(int a[][MAX], int d, int n);
int tongTrenBien(int a[][MAX], int m, int n);
int soLanXuatHienx(int a[][MAX], int m, int n, int x);
int ktPhanTuCucDai(int a[][MAX], int m, int n, int d, int c);
int demCucDai(int a[][MAX], int m, int n);
int demCucTri(int a[][MAX], int m, int n);
int ktPTHoangHau(int a[][MAX], int m, int n, int d, int c);
int demPTHoangHau(int a[][MAX], int m, int n);
int maxDongk(int a[][MAX], int k, int n);
int minDongk(int a[][MAX], int k, int n);
int maxCotk(int a[][MAX], int m, int k);
int minCotk(int a[][MAX], int m, int k);
int ktPTYenNgua(int a[][MAX], int m, int n, int d, int c);
int demPTYenNgua(int a[][MAX], int m, int n);
int ktToanDuong(int a[][MAX], int m, int n);
int ktHangTang(int a[][MAX], int d, int n);
int ktCotGiam(int a[][MAX], int m, int c);
int ktDongGiam(int a[][MAX], int d, int n);
int ktGiamDanTheoCotVaDong(int a[][MAX], int m, int n);
void chiSoDongToanChan(int a[][MAX], int m, int n);
void cacDongGiamDan(int a[][MAX], int m, int n);
int soXuatHienNhieuNhat(int a[][MAX], int m, int n);
int tongCot(int a[][MAX], int m, int c);
int tongCotMin(int a[][MAX], int m, int n);
void cacCotTongMin(int a[][MAX], int m, int n);
int demSoHTTrenDong(int a[][MAX], int d, int n);
int soHTNhieuNhatTrenDong(int a[][MAX], int m, int n);
void cacDongNhieuSoHTNhat(int a[][MAX], int m, int n);
void hoanVi(int& a, int& b);
void doiCot(int a[][MAX], int m, int c1, int c2);
void doiDong(int a[][MAX], int d1, int d2, int n);
void sxZicZac(int a[][MAX], int m, int n);
void main()
{
	int a[MAX][MAX];
	int m, n, cn;
	do
	{
		menu();
		printf("\nChon chuc nang: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 0:
		{
			exit(1);
		}
		case 1:
		{
			nhapM2C(a, m, n);
			break;
		}
		case 2:
		{
			printf("\nPhan tu trong ma tran:\n");
			xuatM2C(a, m, n);
			break;
		}
		case 3:
		{
			printf("\nTong cac phan tu co chu so dau la chu so le: %d", tongCacSoChuSoDauLe(a, m, n));
			break;
		}
		case 4:
		{
			printf("\nSo cac phan tu co chu so hang chuc la 5: %d", demCacSoChuSoChucLa5(a, m, n));
			break;
		}
		case 5:
		{
			printf("\nCac so hoan thien trong ma tran: ");
			xuatCacSoHT(a, m, n);
			break;
		}
		case 6:
		{
			printf("\nTong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d", tongCacPTLonHonTriTuyetDoiCuaPTLienSauDo(a, m, n));
			break;
		}
		case 7:
		{
			printf("\nTong cac phan tu cuc tri cua ma tran: %d", tongCacPTCucTri(a, m, n));
			break;
		}
		case 8:
		{
			int d;
			do
			{
			printf("\nNhap dong can tinh tong: ");
			scanf("%d", &d);
			} while (d < 0 || d >= m);
			printf("\nTong gia tri tren dong %d ma tran: %d", d, tong1Dong(a, d, n));
			break;
		}
		case 9:
		{
			int d;
			do
			{
			printf("\nNhap dong can tinh tong: ");
			scanf("%d", &d);
			} while (d < 0 || d >= m);
			printf("\nTong gia tri duong tren dong %d ma tran: %d", d, tongDuongTren1Dong(a, d, n));
			break;
		}
		case 10:
		{
			printf("\nTong cac gia tri nam tren bien cua ma tran: %d", tongTrenBien(a, m, n));
			break;
		}
		case 11:
		{
			int x;
			printf("\nNhap gia tri can dem so lan xuat hien: ");
			scanf("%d", &x);
			printf("\nTan suat xuat hien cua gia tri %d trong ma tran: %d", x, soLanXuatHienx(a, m, n, x));
			break;
		}
		case 12:
		{
			printf("\nSo luong phan tu cuc dai trong ma tran: %d", demCucDai(a, m, n));
			break;
		}
		case 13: 
		{
			printf("\nSo luong phan tu cuc tri ma tran: %d", demCucTri(a, m, n));
			break;
		}
		case 14:
		{
			printf("\nSo luong gia tri 'hoang hau' tren ma tran: %d", demPTHoangHau(a, m, n));
			break;
		}
		case 15:
		{
			printf("\nSo luong 'yen ngua': %d", demPTYenNgua(a, m, n));
			break;
		}
		case 16:
		{
			if (ktToanDuong(a, m, n) == 1)
				printf("\nMa tran toan duong");
			else
				printf("\nMa tran khong toan duong");
			break;
		}
		case 17:
		{
			int d;
			do
			{
			printf("\nNhap hang can kiem tra: ");
			scanf("%d", &d);
			} while (d < 0 || d >= m);
			if (ktHangTang(a, d, n) == 1)
				printf("\nHang %d tang dan", d);
			else
				printf("\nHang %d khong tang dan", d);
			break;
		}
		case 18:
		{
			int c;
			do
			{
			printf("\nNhap cot can kiem tra: ");
			scanf("%d", &c);
			} while (c < 0 || c >= n);
			if (ktCotGiam(a, m, c) == 1)
				printf("\nCot %d giam dan", c);
			else
				printf("\nCot %d khong tang dan", c);
			break;
		}
		case 19:
		{
			int kq = ktGiamDanTheoCotVaDong(a, m, n);
			if (kq == 1)
				printf("\nCac gia tri trong ma tran giam dan theo cot va dong");
			else
				printf("\nCac gia tri trong ma tran khong giam dan theo cot va dong");
			break;
		}
		case 20:
		{
			printf("\nChi so cac dong chua toan gia tri chan: ");
			chiSoDongToanChan(a, m, n);
			break;
		}
		case 21:
		{
			printf("\nCac dong chua gia tri giam dan: ");
			cacDongGiamDan(a, m, n);
			break;
		}
		case 22:
		{
			printf("\nGia tri xuat hien nhieu nhat trong ma tran: %d", soXuatHienNhieuNhat(a, m, n));
			break;
		}
		case 23:
		{
			printf("\nCac cot co tong nho nhat trong ma tran: ");
			cacCotTongMin(a, m, n);
			break;
		}
		case 24:
		{
			printf("\nCac dong co nhieu so hoan thien nhat trong ma tran: ");
			cacDongNhieuSoHTNhat(a, m, n);
			break;
		}
		case 25:
		{
			int c1, c2;
			do
			{
				printf("\nNhap hai cot can hoan vi: ");
				scanf("%d %d", &c1, &c2);
			} while (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n);
			doiCot(a, m, c1, c2);
			printf("\nPhan tu trong ma tran:\n");
			xuatM2C(a, m, n);
			break;
		}
		case 26:
		{
			int d1, d2;
			do
			{
				printf("\nNhap hai dong can hoan vi: ");
				scanf("%d %d", &d1, &d2);
			} while (d1 < 0 || d1 >= m || d2 < 0 || d2 >= m);
			doiDong(a, d1, d2, n);
			printf("\nPhan tu trong ma tran:\n");
			xuatM2C(a, m, n);
			break;
		}
		case 27:
		{
			sxZicZac(a, m, n);
			printf("\nMa tran sau khi sap xep:\n");
			xuatM2C(a, m, n);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}
void menu()
{
	printf("\nMENU");
	printf("\n0. Thoat");
	printf("\n1. Nhap mang hai chieu");
	printf("\n2. Xuat mang hai chieu");
	printf("\n3. Tinh tong cac phan tu co chu so dau la chu so le");
	printf("\n4. Dem cac phan tu co chu so hang chuc la 5");
	printf("\n5. Liet ke cac so hoan thien trong ma tran");
	printf("\n6. Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no");
	printf("\n7. Tinh tong cac phan tu cuc tri cua ma tran");
	printf("\n8. Tinh tong gia tri tren 1 dong ma tran");
	printf("\n9. Tinh tong gia tri duong tren 1 dong ma tran");
	printf("\n10. Tinh tong cac gia tri nam tren bien cua ma tran");
	printf("\n11. Dem tan suat xuat hien cua 1 gia tri x trong ma tran");
	printf("\n12. Dem so luong phan tu cuc dai trong ma tran");
	printf("\n13. Dem so luong phan tu cuc tri ma tran");
	printf("\n14. Dem so luong gia tri 'hoang hau' tren ma tran");
	printf("\n15. Dem so luong 'yen ngua'");
	printf("\n16. Kiem tra ma tran co toan duong hay khong");
	printf("\n17. Kiem tra 1 hang ma tran co tang dan hay khong");
	printf("\n18. Kiem tra 1 cot ma tran co giam dan khong");
	printf("\n19. Kiem tra cac gia tri trong ma tran co giam dan theo cot va dong");
	printf("\n20. Liet ke chi so cac dong chua toan gia tri chan");
	printf("\n21. Liet ke cac dong chua gia tri giam dan");
	printf("\n22. Tim gia tri xuat hien nhieu nhat trong ma tran");
	printf("\n23. Liet ke cac cot co tong nho nhat trong ma tran");
	printf("\n24. Liet ke cac dong co nhieu so hoan thien nhat trong ma tran");
	printf("\n25. Hoan vi hai cot ma tran");
	printf("\n26. Hoan vi hai dong ma tran");
	printf("\n27. Sap xep cac phan tu cua ma tran theo hinh ziczac");
}
void nhapM2C(int a[][MAX], int& m, int& n)
{
	do
	{
		printf("\nNhap so dong so cot trong mang: ");
		scanf("%d %d", &m, &n);
	} while (m <= 0 || n <= 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("\na[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}
void xuatM2C(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}
int ktChuSoDauLe(int n) 
{ 
	while (n > 9 || n < -9)
	{ 
		n /= 10; 
	}
	if (n % 2 == 0) 
		return 0;
	return 1; 
}
int tongCacSoChuSoDauLe(int a[][MAX], int m, int n)
{
	int t = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktChuSoDauLe(a[i][j]) == 1)
				t = t + a[i][j];
		}
	}
	return t;
}
int demCacSoChuSoChucLa5(int a[][MAX], int m, int n)
{
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 100 / 10 == 5)
				d++;
		}
	}
	return d;
}
int ktSoHoanThien(int x)
{
	int t = 0;
	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
			t = t + i;
	}
	if (t == x)
		return 1;
	else
		return 0;
}
void xuatCacSoHT(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktSoHoanThien(a[i][j]) == 1)
				printf("%5d", a[i][j]);
		}
	}
}
int tongCacPTLonHonTriTuyetDoiCuaPTLienSauDo(int a[][MAX], int m, int n)
{
	int t = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == n - 1)
			{
				if (a[i][j] > abs(a[i + 1][0]))
					t = t + a[i][j];
			}
			else
			{
				if (a[i][j] > abs(a[i][j + 1]))
					t = t + a[i][j];
			}
		}
	}
	return t;
}
int ktPhanTuCucTri(int a[][MAX], int m, int n, int d, int c)
{
	int CucDai = 1, CucTieu = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (d + i >= 0 && c + j >= 0 && d + i < m && c + j < n && !(i == 0 && j == 0))
			{
				if (a[d][c] <= a[d + i][c + j])
				{
					CucDai = 0;
				}
				if (a[d][c] >= a[d + i][c + j])
				{
					CucTieu = 0;
				}
				if (CucDai == 0 && CucTieu == 0)
					return 0;
			}
		}
	}
	return 1;
}
int tongCacPTCucTri(int a[][MAX], int m, int n)
{
	int t = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPhanTuCucTri(a, m, n, i, j) == 1)
				t = t + a[i][j];
		}
	}
	return t;
}
int tong1Dong(int a[][MAX], int d, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t = t + a[d][i];
	}
	return t;
}
int tongDuongTren1Dong(int a[][MAX], int d, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[d][i] > 0)
			t = t + a[d][i];
	}
	return t;
}
int tongTrenBien(int a[][MAX], int m, int n) 
{
	int t = 0;
	for(int i = 0; i < n; i++)
	{
		t = t + a[0][i];
		t = t + a[m - 1][i];
	}
	for(int i = 1; i < m - 1; i++)
	{
		t = t + a[i][0];
		t = t + a[i][n - 1];
	}
	return t;
}
int soLanXuatHienx(int a[][MAX], int m, int n, int x)
{
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == x)
				d++;
		}
	}
	return d;
}
int ktPhanTuCucDai(int a[][MAX], int m, int n, int d, int c)
{
	int CucDai = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (d + i >= 0 && c + j >= 0 && d + i < m && c + j < n && !(i == 0 && j == 0))
			{
				if (a[d][c] <= a[d + i][c + j])
				{
					CucDai = 0;
				}
				if (CucDai == 0)
					return 0;
			}
		}
	}
	return 1;
}
int demCucDai(int a[][MAX], int m, int n)
{
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPhanTuCucDai(a, m, n, i, j) == 1)
				d++;
		}
	}
	return d;
}
int demCucTri(int a[][MAX], int m, int n)
{
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPhanTuCucTri(a, m, n, i, j) == 1)
				d++;
		}
	}
	return d;
}
int ktPTHoangHau(int a[][MAX], int m, int n, int d, int c)
{
	int x = a[d][c];
	for (int i = 0; i < n; i++)
	{
		if (a[d][i] > x)
		{
			return 0;
		}
	}
	for (int j = 0; j < m; j++)
	{
		if (a[j][c] > x)
		{
			return 0;
		}
	}
	int d1 = d + 1;
	int c1 = c + 1;
	while (c1 + 1 < n && d1 < m)
	{
		if (a[c1][d1] > x)
			return 0;
		c1++;
		d1++;
	}
	d1 = d - 1;
	c1 = c - 1;
	while (c1 - 1 >= 0 && d1 >= 0)
	{
		if (a[c1][d1] > x)
			return 0;
		c1--;
		d1--;
	}
	d1 = d + 1;
	c1 = c - 1;
	while (c1 - 1 >= 0 && d1 < m)
	{
		if (a[c1][d1] > x)
			return 0;
		c1--;
		d1++;
	}
	d1 = d - 1;
	c1 = c + 1;
	while (c1 + 1 < n && d1 >= 0)
	{
		if (a[c1][d1] > x)
			return 0;
		c1++;
		d1--;
	}
	return 1;
}
int demPTHoangHau(int a[][MAX], int m, int n)
{
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTHoangHau(a, m, n, i, j) == 1)
				d++;
		}
	}
	return d;
}
int maxDongk(int a[][MAX], int k, int n)
{
	int max = a[k][0];
	for (int i = 0; i < n; i++)
	{
		if (a[k][i] > max)
			max = a[k][i];
	}
	return max;
}
int minDongk(int a[][MAX], int k, int n)
{
	int min = a[k][0];
	for (int i = 0; i < n; i++)
	{
		if (a[k][i] < min)
			min = a[k][i];
	}
	return min;
}
int maxCotk(int a[][MAX], int m, int k)
{
	int max = a[0][k];
	for (int i = 0; i < m; i++)
	{
		if (a[i][k] > max)
			max = a[i][k];
	}
	return max;
}
int minCotk(int a[][MAX], int m, int k)
{
	int min = a[0][k];
	for (int i = 0; i < m; i++)
	{
		if (a[i][k] < min)
			min = a[i][k];
	}
	return min;
}
int ktPTYenNgua(int a[][MAX], int m, int n, int d, int c)
{
	if ((maxDongk(a, d, n) == a[d][c] && minCotk(a, m, c) == a[d][c]) || (minDongk(a, d, n) == a[d][c] && maxCotk(a, m, c) == a[d][c]))
		return 1;
	else
		return 0;
}
int demPTYenNgua(int a[][MAX], int m, int n)
{
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktPTYenNgua(a, m, n, i, j) == 1)
				d++;
		}
	}
	return d;
}
int ktToanDuong(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] <= 0)
				return 0;
		}
	}
	return 1;
}
int ktHangTang(int a[][MAX], int d, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[d][i] >= a[d][i + 1])
			return 0;
	}
	return 1;
}
int ktCotGiam(int a[][MAX], int m, int c)
{
	for (int i = 0; i < m - 1; i++)
	{
		if (a[i][c] <= a[i + 1][c])
			return 0;
	}
	return 1;
}
int ktDongGiam(int a[][MAX], int d, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[d][i] <= a[d][i + 1])
			return 0;
	}
	return 1;
}
int ktGiamDanTheoCotVaDong(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktCotGiam(a, m, j) == 0 || ktDongGiam(a, i, n) == 0)
				return 0;
		}
	}
	return 1;
}
void chiSoDongToanChan(int a[][MAX], int m, int n)
{
	int kt;
	for (int i = 0; i < m; i++)
	{
		kt = 1;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				kt = 0;
				break;
			}
		}
		if (kt == 1)
			printf("%5d", i);
	}
}
void cacDongGiamDan(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		if (ktDongGiam(a, i, n) == 1)
			printf("%5d", i);
	}
}
int demSoLanXuatHien(int a[][MAX], int m, int n, int x)
{
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == x)
				d++;
		}
	}
	return d;
}
int soXuatHienNhieuNhat(int a[][MAX], int m, int n)
{
	int max = demSoLanXuatHien(a, m, n, a[0][0]);
	int gt = a[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (demSoLanXuatHien(a, m, n, a[i][j]) > max)
			{
				max = demSoLanXuatHien(a, m, n, a[i][j]);
				gt = a[i][j];
			}
		}
	}
	return gt;
}
int tongCot(int a[][MAX], int m, int c)
{
	int t = 0;
	for (int i = 0; i < m; i++)
	{
		t = t + a[i][c];
	}
	return t;
}
int tongCotMin(int a[][MAX], int m, int n)
{
	int min = tongCot(a, m, 0);
	for (int i = 1; i < n; i++)
	{
		if (tongCot(a, m, i) < min)
			min = tongCot(a, m, i);
	}
	return min;
}
void cacCotTongMin(int a[][MAX], int m, int n)
{
	int min = tongCotMin(a, m, n);
	for (int i = 0; i < n; i++)
	{
		if (tongCot(a, m, i) == min)
			printf("%5d", i);
	}
}
int demSoHTTrenDong(int a[][MAX], int d, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (ktSoHoanThien(a[d][i]) == 1)
			dem++;
	}
	return dem;
}
int soHTNhieuNhatTrenDong(int a[][MAX], int m, int n)
{
	int max = demSoHTTrenDong(a, 0, n);
	for (int i = 1; i < m; i++)
	{
		if (demSoHTTrenDong(a, i, n) > max)
			max = demSoHTTrenDong(a, i, n);
	}
	return max;
}
void cacDongNhieuSoHTNhat(int a[][MAX], int m, int n)
{
	int max = soHTNhieuNhatTrenDong(a, m, n);
	for (int i = 0; i < m; i++)
	{
		if (demSoHTTrenDong(a, i, n) == max)
			printf("%5d", i);
	}
}
void hoanVi(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void doiCot(int a[][MAX], int m, int c1, int c2)
{
	for (int i = 0; i < m; i++)
	{
		hoanVi(a[i][c1], a[i][c2]);
	}
}
void doiDong(int a[][MAX], int d1, int d2, int n)
{
	for (int i = 0; i < n; i++)
	{
		hoanVi(a[d1][i], a[d2][i]);
	}
}
void sxZicZac(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m * n - 1; i++)
	{
		for (int j = i + 1; j < m * n; j++)
		{
			if (a[i / n][i % n] > a[j / n][j % n])
				hoanVi(a[i / n][i % n], a[j / n][j % n]);
		}
	}
}
