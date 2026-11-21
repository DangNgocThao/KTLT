#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void taoMang1C_SoNguyen_TongDoanXY(int * &a, int &n, int x, int y)
{
	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", &n);
	} while (n <= 0);
	a = (int *)malloc(n*sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = (rand() % (y - x + 1)) + x;
	}
}
void taoMang1C_SoNguyen_ToanChan(int * &a, int &n)
{
	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", &n);
	} while (n <= 0);
	a = (int *)malloc(n*sizeof(int));
	srand((unsigned)time(NULL));
	int dem = 0;
	int i = 0;
	while (i < n)
	{
		dem++;
		int x = rand() % 101;
		if (x % 2 == 0)
		{
			*(a + i) = x;
			i++;
		}
	}
}
int linearSearch(int *a, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == x)
			return i;
	}
	return -1;
}
void xuatMang1C_SoNguyen(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", *(a + i));
	}
}
void swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}
void interchangeSort_TangDan(int * &a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) > *(a + j))
				swap(*(a + i), *(a + j));
		}
	}
}
void interchangeSort_GiamDan(int * &a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) < *(a + j))
				swap(*(a + i), *(a + j));
		}
	}
}
int binarySearch_MangTang(int *a, int n, int left, int right, int x)
{
	if (left > right) 
		return -1; 
	int mid = (left + right) / 2;
	if (*(a + mid) == x)
		return mid;
	else if (*(a + mid) > x)
		binarySearch_MangTang(a, n, left, mid - 1, x);
	else
		binarySearch_MangTang(a, n, mid + 1, right, x);
}
void selectionSort_TangDan(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + j) < *(a + vtm))
				vtm = j;
			swap(*(a + i), *(a + vtm));
		}
	}
}
void selectionSort_GiamDan(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + j) > *(a + vtm))
				vtm = j;
			swap(*(a + i), *(a + vtm));
		}
	}
}
void quickSort_TangDan(int *a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	int x = *(a + mid);
	do
	{
		while (*(a + i) < x)
			i++;
		while (*(a + j) > x)
			j--;
		if (i < j)
			swap(*(a + i), *(a + j));
		i++; 
		j--;
	} while (i < j);
	if (left < j)
		quickSort_TangDan(a, left, j);
	if (right > i)
		quickSort_TangDan(a, i, right);
}
void quickSort_GiamDan(int *a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	int x = *(a + mid);
	do
	{
		while (*(a + i) > x)
			i++;
		while (*(a + j) < x)
			j--;
		if (i < j)
			swap(*(a + i), *(a + j));
		i++;
		j--;
	} while (i < j);
	if (left < j)
		quickSort_GiamDan(a, left, j);
	if (right > i)
		quickSort_GiamDan(a, i, right);
}
int ktSoNguyenTo(int x)
{
	int d = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0)
			d++;
	}
	if (d == 2)
		return 1;
	else
		return 0;
}
void soNguyenToNhoHonx(int* a, int n, int x)
{
	int vtsnt = -1;
	for (int i = 0; i < n; i++)
	{
		if (ktSoNguyenTo(*(a + i)) == 1)
		{
			vtsnt = i;
			break;
		}
	}
	if (vtsnt == -1)
	{
		printf("\nKhong ton tai so nguyen to trong mang");
		return;
	}
	int d = 0;
	printf("\n");
	for (int i = vtsnt; i < n; i++)
	{
		if (ktSoNguyenTo(*(a + i)) == 1 && *(a + i) < x)
		{
			printf("%5d", *(a + i));
			d++;
		}
	}
	if (d == 0)
		printf("Khong co so nguyen to nho hon %d trong mang", x);
}
int ktChuSoDauLe(int x) 
{ 
	x = abs(x); 
	while (x >= 10) 
	{ 
		x /= 10;
	}
	if (x % 2 == 0)
		return 0;
	return 1;
}
int tongCacSoCoChuSoDauLe(int* a, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (ktChuSoDauLe(*(a + i) == 1))
			t = t + *(a + i);
	}
	return t;
}
int soLanXuatHien(int* a, int n, int x)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == x)
			d++;
	}
	return d;
}
void soLanXHCuaCacPT(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nSo lan xuat hien cua a[%d]: %d", i, soLanXuatHien(a, n, *(a + i)));
	}
}
void sapChanTangLeGiam(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) % 2 != 0 && *(a + j) % 2 == 0)
				swap(*(a + i), *(a + j));
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) > *(a + j) && *(a + i) % 2 == 0 && *(a + j) % 2 == 0)
					swap(*(a + i), *(a + j));
		}
	}
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (*(a + i) > *(a + j) && *(a + j) % 2 != 0)
				swap(*(a + i), *(a + j));
		}
	}
}
void dayConGiamDaiNhat(int* a, int n)
{
	int dodai = 1, dodaimax = 1, vtd = 0, vtc = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (*(a + i) > *(a + i + 1))
		{
			dodai++;
			if (dodai > dodaimax)
			{
				dodaimax = dodai;
				vtd = i + 2 - dodai;
				vtc = i + 2;
			}
		}
		else
			dodai = 1;
	}
	printf("\nday con giam dan dai nhat: ");
	for (int i = vtd; i < vtc; i++)
		printf("%5d", *(a + i));
}
int timMin(int* a, int n)
{
	int min = *a;
	for (int i = 1; i < n; i++)
	{
		if (min > *(a + i))
			min = *(a + i);
	}
	return min;
}
int timMinThuHai(int* a, int n)
{
	int min = timMin(a, n), min2 = *a;
	for (int i = 1; i < n; i++)
	{
		if (*(a + i) != min)
		{
			min2 = *(a + i);
		break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) != min && *(a + i) < min2)
			min2 = *(a + i);
	}
	return min2;
}
void timPTCo2ChuSoCuax(int* a, int n, int x)
{
	int d = 0;
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		int b = abs(*(a + i)), c, d1 = 0, d2 = 0;
		while (b != 0)
		{
			c = b % 10;
			b = b / 10;
			if (x % 10 == c)
				d1++;
			if (x / 10 == c)
				d2++;
		}
		if (d1 > 0 && d2 > 0)
		{
			printf("%5d", *(a + i));
			d++;
		}
	}
	if (d == 0)
		printf("Khong co phan tu nao chua hai chu so cua x");
}
void sapChanTangLeKhongDoi(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) % 2 == 0 && *(a + j) % 2 == 0 && *(a + i) > *(a + j))
				swap(*(a + i), *(a + j));
		}
	}
}
void sapLeDauChanCuoi(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) % 2 == 0 && *(a + j) % 2 != 0)
				swap(*(a + i), *(a + j));
		}
	}
}
//void menu()
//{
//	printf("\n**********************************************");
//	printf("\nMenu");
//	printf("\n0. Thoat chuong trinh");
//	printf("\n1. Tao mang so >= 15");
//	printf("\n2. Tao mang so chan");
//	printf("\n3. Tim kiem X bang giai thuat Linear Search");
//	printf("\n4. SX tang dan bang Interchange Sort");
//	printf("\n5. SX giam dan bang Interchange Sort");
//	printf("\n6. Tim kiem X bang giai thuat Binary Search");
//	printf("\n7. SX tang dan bang Selection Sort");
//	printf("\n8. SX giam dan bang Selection Sort");
//	printf("\n9. SX tang dan bang Quick Sort");
//	printf("\n10. SX giam giam bang Quick Sort");
//	printf("\n11. Liet ke cac so nguyen to nho hon x");
//	printf("\n12. Tong cac phan tu co chu so dau le");
//	printf("\n13. Liet ke so lan xuat hien cua cac phan tu");
//	printf("\n14. Sap xap chan tang le giam");
//	printf("\n15. Tim day con giam dan dai nhat trong mang");
//	printf("\n16. Tim so nho thu hai trong mang");
//	printf("\n17. Tim cac phan tu chua cac chu so cua x");
//	printf("\n18. Sap xep chan tang dan cac phan tu le giu nguyen vi tri");
//	printf("\n19. Sap xep le o dau mang chan o cuoi mang");
//	printf("\n**********************************************");
//}
//void process()
//{
//	int n;
//	int *a = new int;
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
//			taoMang1C_SoNguyen_TongDoanXY(a, n, 15, 100);
//			printf("\nNoi dung cua mang la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 2:
//		{
//			taoMang1C_SoNguyen_ToanChan(a, n);
//			printf("\nNoi dung cua mang la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 3:
//		{
//			int x, kq;
//			printf("\nBan hay cho biet gia tri muon tim: ");
//			scanf("%d", &x);
//			kq = linearSearch(a, n, x);
//			if (kq == -1)
//				printf("\nKhong tim thay %d trong mang", x);
//			else
//				printf("\nTim thay %d trong mang tai vi tri %d", x, kq);
//			break;
//		}
//		case 4:
//		{
//			interchangeSort_TangDan(a, n);
//			printf("\nNoi dung cua mang sau khi SX tang dan bang Interchange Sort la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 5:
//		{
//			interchangeSort_GiamDan(a, n);
//			printf("\nNoi dung cua mang sau khi SX giam dan bang Interchange Sort la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 6:
//		{
//			int x, kq;
//			printf("\nBan hay cho biet gia tri muon tim: ");
//			scanf("%d", &x);
//			kq = binarySearch_MangTang(a, n, 0, n - 1, x);
//			if (kq == -1)
//				printf("\nKhong tim thay %d trong mang", x);
//			else
//				printf("\nTim thay %d trong mang tai vi tri %d", x, kq);
//			break;
//		}
//		case 7:
//		{
//			selectionSort_TangDan(a, n);
//			printf("\nNoi dung cua mang sau khi SX tang dan bang Selection Sort la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 8:
//		{
//			selectionSort_GiamDan(a, n);
//			printf("\nNoi dung cua mang sau khi SX giam dan bang Selection Sort la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 9:
//		{
//			quickSort_TangDan(a, 0, n - 1);
//			printf("\nNoi dung cua mang sau khi SX tang dan bang Quick Sort la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 10:
//		{
//			quickSort_GiamDan(a, 0, n - 1);
//			printf("\nNoi dung cua mang sau khi SX giam dan bang Quick Sort la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 11:
//		{
//			int x;
//			printf("\nNhap so nguyen x: ");
//			scanf("%d", &x);
//			soNguyenToNhoHonx(a, n, x);
//			break;
//		}
//		case 12:
//		{
//			printf("\nTong cac phan tu co chu so dau le: %d", tongCacSoCoChuSoDauLe(a, n));
//			break;
//		}
//		case 13:
//		{
//			soLanXHCuaCacPT(a, n);
//			break;
//		}
//		case 14:
//		{
//			sapChanTangLeGiam(a, n);
//			printf("\nNoi dung cua mang la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 15:
//		{
//			dayConGiamDaiNhat(a, n);
//			break;
//		}
//		case 16:
//		{
//			printf("\nSo nho thu hai trong mang: %d", timMinThuHai(a, n));
//			break;
//		}
//		case 17:
//		{
//			int x;
//			do
//			{
//				printf("\nNhap gia tri x: ");
//				scanf("%d", &x);
//			} while (x < 10 || x > 99);
//			timPTCo2ChuSoCuax(a, n, x);
//			break;
//		}
//		case 18:
//		{
//			sapChanTangLeKhongDoi(a, n);
//			printf("\nNoi dung cua mang la: ");
//			xuatMang1C_SoNguyen(a, n);
//			break;
//		}
//		case 19:
//		{
//			sapLeDauChanCuoi(a, n);
//			printf("\nNoi dung cua mang la: ");
//			xuatMang1C_SoNguyen(a, n);
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