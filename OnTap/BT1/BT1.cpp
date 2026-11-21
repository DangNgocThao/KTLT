#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void nhapM1C(double*& a, int &n)
{
	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", &n);
	} while (n <= 0);
	a = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		printf("\na[%d] = ", i);
		scanf("%lf", a + i);
	}
}
void taoM1C(double*& a, int &n)
{
	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", &n);
	} while (n <= 0);
	a = (double*)malloc(n * sizeof(double));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = rand() * 199.0 / RAND_MAX - 99;
	}
}
void xuatM1C(double* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5.2lf	", *(a + i));
	}
}
int ktSNT(int n)
{
	int d = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			d++;
	}
	if (d == 2)
		return 1;
	else
		return 0;
}
void xuatPhanNguyenSNT(double* a, int n)
{
	printf("\nCac so co phan nguyen la so nguyen to: ");
	for (int i = 0; i < n; i++)
	{
		if (ktSNT((int)*(a + i)) == 1)
			printf("%5.2lf	", *(a + i));
	}
}
void xuatPhanThapPhan(double* a, int n)
{
	printf("\nPhan thap phan trong mang: ");
	for (int i = 0; i < n; i++)
	{
		int t = (*(a + i) - (int)*(a + i)) * 100000;
		t = abs(t);
		printf("%7d", t);
	}
}
int ktCoChuSo2(int x)
{
	int cs = abs(x);
	while (cs!=0)
	{
		if (cs % 10 == 2)
			return 1;
		cs /= 10;
	}
	return 0;
}
int demPTCoChuSo2(double* a, int n)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (ktCoChuSo2((int)*(a + i)) == 1)
			d++;
	}
	return d;
}
void xoaPT(double*& a, int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		*(a + i) = *(a + i + 1);
	}
	n--;
}
void xoaPTPhanNguyenLe(double*& a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		if ((int)*(a + i) % 2 != 0)
			xoaPT(a, n, i);
	}
}
int demPTx(double* a, int n, int vt)
{
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == *(a + vt))
			d++;
	}
	return d;
}
double timMax(double* a, int n)
{
	double max = *a;
	for (int i = 1; i < n; i++)
	{
		if (max < *(a + i))
			max = *(a + i);
	}
	return max;
}
double timMin(double* a, int n)
{
	double min = *a;
	for (int i = 1; i < n; i++)
	{
		if (min > *(a + i))
			min = *(a + i);
	}
	return min;
}
void xoaMaxMin(double*& a, int& n)
{
	double max = timMax(a, n), min = timMin(a, n);
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == max || *(a + i) == min)
			xoaPT(a, n, i);
	}
}
int timVTMax(double* a, int n)
{
	int vtmax = 0;
	for (int i = 1; i < n; i++)
	{
		if (*(a + vtmax) < *(a + i))
			vtmax = i;
	}
	return vtmax;
}
int timVTMin(double* a, int n)
{
	int vtmin = 0;
	for (int i = 1; i < n; i++)
	{
		if (*(a + vtmin) > *(a + i))
			vtmin = i;
	}
	return vtmin;
}
void themPT(double*& a, int& n, double x, int vt)
{
	for (int i = n; i > vt; i--)
	{
		*(a + i) = *(a + i - 1);
	}
	*(a + vt) = x;
	n++;
}
void themXSauMax(double*& a, int& n, double x)
{
	int vtmax = timVTMax(a, n);
	themPT(a, n, x, vtmax + 1);
}
void themXSauMin(double*& a, int& n, double x)
{
	int vtmin = timVTMin(a, n);
	themPT(a, n, x, vtmin);
}
void swap(double& a, double& b)
{
	double t = a;
	a = b;
	b = t;
}
void interchangeSort_TangDan(double*& a, int n)
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
void interchangeSort_GiamDan(double*& a, int n)
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
void selectionSort_TangDan(double* a, int n)
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
void selectionSort_GiamDan(double* a, int n)
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
void quickSort_TangDan(double* a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	double x = *(a + mid);
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
void quickSort_GiamDan(double* a, int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	double x = *(a + mid);
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
void menu()
{
	printf("\nMenu");
	printf("\n0. Thoat");
	printf("\n1. Nhap mang a");
	printf("\n2. Tao mang a");
	printf("\n3. Xuat mang a");
	printf("\n4. Xuat cac phan tu co phan nguyen la so nguyen to");
	printf("\n5. Xuat cac phan thap phan cua moi phan tu");
	printf("\n6. Dem so phan tu co phan nguyen chua chu so 2");
	printf("\n7. Xoa cac phan tu co phan nguyen la le");
	printf("\n8. Tim trong a co bao nhieu phan tu x");
	printf("\n9. Xoa phan tu max/min");
	printf("\n10. Them x vao sau so lon nhat cua a");
	printf("\n11. Them x vao truoc so nho nhat cua a");
	printf("\n12. Sap xep tang theo Interchange Sort");
	printf("\n13. Sap xep giam theo Interchange Sort");
	printf("\n14. Sap xep tang theo Selection Sort");
	printf("\n15. Sap xep giam theo Selection Sort");
	printf("\n16. Sap xep tang theo Quick Sort");
	printf("\n17. Sap xep giam theo Quick Sort");
}
void main()
{
	double* a = new double;
	int n, cn;
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
			nhapM1C(a, n);
			printf("\nCac phan tu trong mang: ");
			xuatM1C(a, n);
			break;
		}
		case 2:
		{
			taoM1C(a, n);
			printf("\nCac phan tu trong mang: ");
			xuatM1C(a, n);
			break;
		}
		case 3:
		{
			printf("\nCac phan tu trong mang: ");
			xuatM1C(a, n);
			break;
		}
		case 4:
		{
			xuatPhanNguyenSNT(a, n);
			break;
		}
		case 5:
		{
			xuatPhanThapPhan(a, n);
			break;
		}
		case 6:
		{
			printf("\nCo %d phan tu co phan nguyen chua chu so 2", demPTCoChuSo2(a, n));
			break;
		}
		case 7:
		{
			xoaPTPhanNguyenLe(a, n);
			printf("\nNoi dung sau khi xoa: ");
			xuatM1C(a, n);
			break;
		}
		case 8:
		{
			int vt;
			printf("\nNhap vi tri phan tu can dem: ");
			scanf("%d", &vt);
			printf("\n%.2lf co %d phan tu trong a", *(a + vt), demPTx(a, n, vt));
			break;
		}
		case 9:
		{
			xoaMaxMin(a, n);
			printf("\nNoi dung sau khi xoa: ");
			xuatM1C(a, n);
			break;
		}
		case 10:
		{
			double x;
			printf("\nNhap phan tu can them: ");
			scanf("%lf", &x);
			themXSauMax(a, n, x);
			printf("\nNoi dung sau khi them: ");
			xuatM1C(a, n);
			break;
		}
		case 11:
		{
			double x;
			printf("\nNhap phan tu can them: ");
			scanf("%lf", &x);
			themXSauMin(a, n, x);
			printf("\nNoi dung sau khi them: ");
			xuatM1C(a, n);
			break;
		}
		case 12:
		{
			interchangeSort_TangDan(a, n);
			printf("\nNoi dung sau sap xep: ");
			xuatM1C(a, n);
			break;
		}
		case 13:
		{
			interchangeSort_GiamDan(a, n);
			printf("\nNoi dung sau sap xep: ");
			xuatM1C(a, n);
			break;
		}
		case 14:
		{
			selectionSort_TangDan(a, n);
			printf("\nNoi dung sau sap xep: ");
			xuatM1C(a, n);
			break;
		}
		case 15:
		{
			selectionSort_GiamDan(a, n);
			printf("\nNoi dung sau sap xep: ");
			xuatM1C(a, n);
			break;
		}
		case 16:
		{
			quickSort_TangDan(a, 0, n - 1);
			printf("\nNoi dung sau sap xep: ");
			xuatM1C(a, n);
			break;
		}
		case 17:
		{
			quickSort_GiamDan(a, 0, n - 1);
			printf("\nNoi dung sau sap xep: ");
			xuatM1C(a, n);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}