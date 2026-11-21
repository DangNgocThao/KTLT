#include<time.h>
#include"PhanSo.h"
typedef struct HonSo
{
	int nguyen;
	PS PhanSo;
}HS;
void taoHS(HS& x)
{
	x.nguyen = (rand() % 19) - 9;
	taoPS(x.PhanSo);
}
void xuatHS(HS x)
{
	printf(" %d", x.nguyen);
	xuatPS(x.PhanSo);
}
void rutGonHS(HS& x)
{
	if (x.PhanSo.tu >= x.PhanSo.mau)
	{
		int n = (x.PhanSo.tu / x.PhanSo.mau);
		x.nguyen += n;
		x.PhanSo.tu -= n * x.PhanSo.mau;
	}
}
double tinhGiaTriHS(HS x)
{
	if (x.nguyen >= 0)
		return (double)x.nguyen + tinhGiaTriPS(x.PhanSo);
	else
		return (double)x.nguyen - tinhGiaTriPS(x.PhanSo);
}
void taoMang1C_HonSo(HS*& a, int& n)
{
	do
	{
		printf("Nhap so phan tu trong mang: ");
		scanf("%d", &n);
	} while (n <= 0);
	a = (HS*)malloc(n * sizeof(HS));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		HS x;
		taoHS(x);
		*(a + i) = x;
	}
}
void xuatMang1C_HonSo(HS* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		rutGonHS(*(a + i));
		xuatHS(*(a + i));
	}
}
void swap(HS& x, HS& y)
{
	HS t = x;
	x = y;
	y = t;
}
void interchangeSort_TangDan(HS*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tinhGiaTriHS(*(a + i)) > tinhGiaTriHS(*(a + j)))
				swap(*(a + i), *(a + j));
		}
	}
}
void interchangeSort_GiamDan(HS*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tinhGiaTriHS(*(a + i)) < tinhGiaTriHS(*(a + j)))
				swap(*(a + i), *(a + j));
		}
	}
}
void selectionSort_TangDan(HS* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tinhGiaTriHS(*(a + j)) < tinhGiaTriHS(*(a + vtm)))
				vtm = j;
			swap(*(a + i), *(a + vtm));
		}
	}
}
void selectionSort_GiamDan(HS* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtm = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tinhGiaTriHS(*(a + j)) > tinhGiaTriHS(*(a + vtm)))
				vtm = j;
			swap(*(a + i), *(a + vtm));
		}
	}
}
void quickSort_TangDan(HS* a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	HS x = *(a + mid);
	do
	{
		while (tinhGiaTriHS(*(a + i)) < tinhGiaTriHS(x))
			i++;
		while (tinhGiaTriHS(*(a + j)) > tinhGiaTriHS(x))
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
void quickSort_GiamDan(HS* a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	HS x = *(a + mid);
	do
	{
		while (tinhGiaTriHS(*(a + i)) > tinhGiaTriHS(x))
			i++;
		while (tinhGiaTriHS(*(a + j)) < tinhGiaTriHS(x))
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
void soSanh2HonSo(HS x, HS y)
{
	if (tinhGiaTriHS(x) > tinhGiaTriHS(y))
	{
		xuatHS(x);
		printf(" >");
		xuatHS(y);
	}
	else
		if (tinhGiaTriHS(x) < tinhGiaTriHS(y))
		{
			xuatHS(x);
			printf(" <");
			xuatHS(y);
		}
		else
		{
			xuatHS(x);
			printf(" =");
			xuatHS(y);
		}
}
void hsSangPS(HS& x)
{
	if (x.nguyen >= 0)
		x.PhanSo.tu = x.nguyen * x.PhanSo.mau + x.PhanSo.tu;
	else
		x.PhanSo.tu = x.nguyen * x.PhanSo.mau - x.PhanSo.tu;
}
void psSangHS(HS& x)
{
	x.nguyen = x.PhanSo.tu / x.PhanSo.mau;
	if (x.nguyen == 0)
		return;
	else
		x.PhanSo.tu = abs(x.PhanSo.tu - x.nguyen * x.PhanSo.mau);
}
void mangHSSangPS(HS* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		hsSangPS(*(a + i));
	}
	printf("\nMang chuyen sang phan so: ");
	for (int i = 0; i < n; i++)
	{
		xuatPS(a[i].PhanSo);
	}
}
void mangPSSangHS(HS* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		psSangHS(*(a + i));
	}
	printf("\nMang hon so: ");
	xuatMang1C_HonSo(a, n);
}
HS congHS(HS x, HS y)
{
	HS c;
	hsSangPS(x);
	hsSangPS(y);
	c.PhanSo.tu = x.PhanSo.tu * y.PhanSo.mau + y.PhanSo.tu * x.PhanSo.mau;
	c.PhanSo.mau = x.PhanSo.mau * y.PhanSo.mau;
	doiDauPS(c.PhanSo);
	rutGonPS(c.PhanSo);
	psSangHS(c);
	return c;
}
HS truHS(HS x, HS y)
{
	HS t;
	hsSangPS(x);
	hsSangPS(y);
	t.PhanSo.tu = x.PhanSo.tu * y.PhanSo.mau - y.PhanSo.tu * x.PhanSo.mau;
	t.PhanSo.mau = x.PhanSo.mau * y.PhanSo.mau;
	doiDauPS(t.PhanSo);
	rutGonPS(t.PhanSo);
	psSangHS(t);
	return t;
}
HS nhanHS(HS x, HS y)
{
	HS n;
	hsSangPS(x);
	hsSangPS(y);
	n.PhanSo.tu = x.PhanSo.tu * y.PhanSo.tu;
	n.PhanSo.mau = x.PhanSo.mau * y.PhanSo.mau;
	doiDauPS(n.PhanSo);
	rutGonPS(n.PhanSo);
	psSangHS(n);
	return n;
}
HS chiaHS(HS x, HS y)
{
	HS ch;
	hsSangPS(x);
	hsSangPS(y);
	ch.PhanSo.tu = x.PhanSo.tu * y.PhanSo.mau;
	ch.PhanSo.mau = x.PhanSo.mau * y.PhanSo.tu;
	doiDauPS(ch.PhanSo);
	rutGonPS(ch.PhanSo);
	psSangHS(ch);
	return ch;
}
void tinhHS(HS x, HS y)
{
	HS c, t, n, ch;
	c = congHS(x, y);
	t = truHS(x, y);
	n = nhanHS(x, y);
	ch = chiaHS(x, y);
	printf("\n%d %d/%d + %d %d/%d = %d %d/%d", x.nguyen, x.PhanSo.tu, x.PhanSo.mau, y.nguyen, y.PhanSo.tu, y.PhanSo.mau, c.nguyen, c.PhanSo.tu, c.PhanSo.mau);
	printf("\n%d %d/%d - %d %d/%d = %d %d/%d", x.nguyen, x.PhanSo.tu, x.PhanSo.mau, y.nguyen, y.PhanSo.tu, y.PhanSo.mau, t.nguyen, t.PhanSo.tu, t.PhanSo.mau);
	printf("\n%d %d/%d * %d %d/%d = %d %d/%d", x.nguyen, x.PhanSo.tu, x.PhanSo.mau, y.nguyen, y.PhanSo.tu, y.PhanSo.mau, n.nguyen, n.PhanSo.tu, n.PhanSo.mau);
	printf("\n%d %d/%d / %d %d/%d = %d %d/%d", x.nguyen, x.PhanSo.tu, x.PhanSo.mau, y.nguyen, y.PhanSo.tu, y.PhanSo.mau, ch.nguyen, ch.PhanSo.tu, ch.PhanSo.mau);
}
int linearSearch(HS* a, int n, HS x)
{
	for (int i = 0; i < n; i++)
	{
		if (tinhGiaTriHS(*(a + i)) == tinhGiaTriHS(x))
			return i;
	}
	return -1;
}
void sapPhanNguyenChanDauLeCuoi(HS* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].nguyen % 2 != 0 && a[j].nguyen % 2 == 0)
				swap(*(a + i), *(a + j));
		}
	}
}
int binarySearch_MangTang(HS* a, int n, HS x)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (tinhGiaTriHS(*(a + mid)) == tinhGiaTriHS(x))
			return mid;
		else
			if (tinhGiaTriHS(*(a + mid)) < tinhGiaTriHS(x))
				left = mid + 1;
			else 
				right = mid - 1;
	}
	return -1;
}
int binarySearch_MangGiam(HS* a, int n, HS x)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (tinhGiaTriHS(*(a + mid)) == tinhGiaTriHS(x))
			return mid;
		else
			if (tinhGiaTriHS(*(a + mid)) > tinhGiaTriHS(x))
				left = mid + 1;
			else
				right = mid - 1;
	}
	return -1;
}
void xoa(HS* a, int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		*(a + i) = *(a + i + 1);
	}
	n--;
}
void them_x(HS* a, int& n, HS x, int vt)
{
	for (int i = n; i > vt; i--)
	{
		*(a + i) = *(a + i - 1);
	}
	a[vt] = x;
	n++;
}
HS tongMang(HS* a, int n)
{
	HS t = *a;
	for (int i = 1; i < n; i++)
	{
		t = congHS(t, *(a + i));
	}
	return t;
}
HS timMax(HS* a, int n)
{
	HS max = *a;
	for (int i = 1; i < n; i++)
	{
		if (tinhGiaTriHS(max) < tinhGiaTriHS(*(a + i)))
			max = *(a + i);
	}
	return max;
}
HS timMin(HS* a, int n)
{
	HS min = *a;
	for (int i = 1; i < n; i++)
	{
		if (tinhGiaTriHS(min) > tinhGiaTriHS(*(a + i)))
			min = *(a + i);
	}
	return min;
}
void vtPTPhanNguyenChan(HS* a, int n)
{
	printf("\nVi tri cac phan tu co phan nguyen chan: ");
	for (int i = 0; i < n; i++)
	{
		if (a[i].nguyen % 2 == 0)
			printf("%5d", i);
	}
}
void vtMaxMin(HS* a, int n)
{
	HS max = timMax(a, n), min = timMin(a, n);
	printf("\nVi tri max: ");
	for (int i = 0; i < n; i++)
	{
		if (tinhGiaTriHS(max) == tinhGiaTriHS(*(a + i)))
		{
			printf("%d", i);
			break;
		}
	}
	printf("\nVi tri min: ");
	for (int i = 0; i < n; i++)
	{
		if (tinhGiaTriHS(min) == tinhGiaTriHS(*(a + i)))
		{
			printf("%d", i);
			break;
		}
	}
}
void menu()
{
 	printf("\n**********************************************");
	printf("\nMenu");
	printf("\n0. Thoat chuong trinh");
	printf("\n1. Tao mang hon so");
	printf("\n2. Xuat dang sach hon so");
	printf("\n3. So sanh 2 hon so");
	printf("\n4. Chuyen hon so sang phan so");
	printf("\n5. Chuyen phan so sang hon so");
	printf("\n6. Tinh tong, hieu, tich, thuong 2 hon so");
	printf("\n7. SX tang dan bang Interchange Sort");
	printf("\n8. SX giam dan bang Interchange Sort");
	printf("\n9. SX tang dan bang Selection Sort");
	printf("\n10. SX giam dan bang Selection Sort");
	printf("\n11. SX tang dan bang Quick Sort");
	printf("\n12. SX giam dan bang Quick Sort");
	printf("\n13. Tim hon so x trong mang bang Linear Search");
	printf("\n14. sap cac phan tu co phan nguyen chan len dau, phan tu co phan nguyen le o cuoi mang");
	printf("\n15. Tim hon so x bang Binary Search trong mang tang");
	printf("\n16. Tim hon so x bang Binary Search trong mang giam");
	printf("\n17. Xoa phan tu tai vi tri k");
	printf("\n18. Them x vao vi tri k");
	printf("\n19. Tong cac phan tu trong mang");
	printf("\n20. Tim phan tu lon nhat/nho nhat trong mang");
	printf("\n21. Xuat vi tri phan tu co phan nguyen chan");
	printf("\n22. Xuat vi tri cua phan tu lon nhat/nho nhat trong mang");
 	printf("\n**********************************************");
}
void process()
{
	int n;
	HS* a = new HS;
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
			taoMang1C_HonSo(a, n);
			printf("\nMang hon so vua tao la: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 2:
		{
			printf("\nMang hon so: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 3:
		{
			int x, y;
			do
			{
			printf("\nNhap vi tri 2 hon so can so sanh: ");
			scanf("%d %d", &x, &y);
			} while (x < 0 || x >= n || y < 0 || y >= n);
			soSanh2HonSo(*(a + x), *(a + y));
			break;
		}
		case 4:
		{
			mangHSSangPS(a, n);
			break;
		}
		case 5:
		{
			mangPSSangHS(a, n);
			break;
		}
		case 6:
		{
			int x, y;
			do
			{
				printf("\nNhap vi tri 2 hon so can so sanh: ");
				scanf("%d %d", &x, &y);
			} while (x < 0 || x >= n || y < 0 || y >= n);
			tinhHS(*(a + x), *(a + y));
			break;
		}
		case 7:
		{
			interchangeSort_TangDan(a, n);
			printf("\nMang sap xep tang dan bang Interchange Sort: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 8:
		{
			interchangeSort_GiamDan(a, n);
			printf("\nMang sap xep giam dan bang Interchange Sort: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 9:
		{
			selectionSort_TangDan(a, n);
			printf("\nMang sap xep tang dan bang Selection Sort: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 10:
		{
			selectionSort_GiamDan(a, n);
			printf("\nMang sap xep giam dan bang Selection Sort: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 11:
		{
			quickSort_TangDan(a, 0, n - 1);
			printf("\nMang sap xep tang dan bang Quick Sort: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 12:
		{
			quickSort_GiamDan(a, 0, n - 1);
			printf("\nMang sap xep giam dan bang Quick Sort: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 13:
		{
			HS x;
			printf("\nNhap hon so can tim: ");
			scanf("%d %d/%d", &x.nguyen, &x.PhanSo.tu, &x.PhanSo.mau);
			int kq = linearSearch(a, n, x);
			if (kq == -1)
				printf("\nkhong co hon so %d %d/%d trong mang", x.nguyen, x.PhanSo.tu, x.PhanSo.mau);
			else
				printf("\nTim thay %d %d/%d trong mang tai vi tri %d", x.nguyen, x.PhanSo.tu, x.PhanSo.mau, kq);
			break;
		}
		case 14:
		{
			sapPhanNguyenChanDauLeCuoi(a, n);
			printf("\nMang hon so: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 15:
		{
			HS x;
			printf("\nNhap hon so can tim: ");
			scanf("%d %d/%d", &x.nguyen, &x.PhanSo.tu, &x.PhanSo.mau);
			int kq = binarySearch_MangTang(a, n, x);
			if (kq == -1)
				printf("\nkhong co hon so %d %d/%d trong mang", x.nguyen, x.PhanSo.tu, x.PhanSo.mau);
			else
				printf("\nTim thay %d %d/%d trong mang tai vi tri %d", x.nguyen, x.PhanSo.tu, x.PhanSo.mau, kq);
			break;
		}
		case 16:
		{
			HS x;
			printf("\nNhap hon so can tim: ");
			scanf("%d %d/%d", &x.nguyen, &x.PhanSo.tu, &x.PhanSo.mau);
			int kq = binarySearch_MangGiam(a, n, x);
			if (kq == -1)
				printf("\nkhong co hon so %d %d/%d trong mang", x.nguyen, x.PhanSo.tu, x.PhanSo.mau);
			else
				printf("\nTim thay %d %d/%d trong mang tai vi tri %d", x.nguyen, x.PhanSo.tu, x.PhanSo.mau, kq);
			break;
		}
		case 17:
		{
			int vt;
			do
			{
				printf("\nNhap vi tri can xoa: ");
				scanf("%d", &vt);
			} while (vt < 0 || vt >= n);
			xoa(a, n, vt);
			printf("\nMang hon so: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 18:
		{
			HS x;
			int vt;
			printf("\nNhap hon so can them vao: ");
			scanf("%d %d/%d", &x.nguyen, &x.PhanSo.tu, &x.PhanSo.mau);
			do
			{
				printf("\nNhap vi tri can them: ");
				scanf("%d", &vt);
			} while (vt < 0 || vt > n);
			them_x(a, n, x, vt);
			printf("\nMang hon so: ");
			xuatMang1C_HonSo(a, n);
			break;
		}
		case 19:
		{
			HS t = tongMang(a, n);
			printf("\nTong cac phan tu trong mang: %d %d/%d", t.nguyen, t.PhanSo.tu, t.PhanSo.mau);
			break;
		}
		case 20:
		{
			HS max = timMax(a, n), min = timMin(a, n);
			printf("\nPhan tu lon nhat: %d %d/%d", max.nguyen, max.PhanSo.tu, max.PhanSo.mau);
			printf("\nPhan tu nho nhat: %d %d/%d", min.nguyen, min.PhanSo.tu, min.PhanSo.mau);
			break;
		}
		case 21:
		{
			vtPTPhanNguyenChan(a, n);
			break;
		}
		case 22:
		{
			vtMaxMin(a, n);
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
}