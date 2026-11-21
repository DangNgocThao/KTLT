//#include <conio.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void taoMang1C_SoNguyen_TrongDoanXY(int * &a, int &n, int x, int y)
//{
//	do
//	{
//		printf("\nNhap so phan tu: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	a = (int *)malloc(n*sizeof(int));
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		*(a + i) = (rand() % (y - x + 1)) + x;
//	}
//}
//void xuatMang1C_SoNguyen(int* a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%4d", *(a + i));
//	}
//}
//void swap(int &x, int &y)
//{
//	int t = x;
//	x = y;
//	y = t;
//}
//void interchangeSort(int * &a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (*(a + i) > *(a + j))
//				swap(*(a + i), *(a + j));
//		}
//	}
//}
//int binarySearch_DQ(int *a, int n, int left, int right, int x)
//{
//	if (left > right) 
//		return -1; 
//	int mid = (left + right) / 2;
//	if (*(a + mid) == x)
//		return mid;
//	else if (*(a + mid) > x)
//		binarySearch_DQ(a, n, left, mid - 1, x);
//	else
//		binarySearch_DQ(a, n, mid + 1, right, x);
//}
//void main()
//{
//	int n;
//	int* a = new int;
//	taoMang1C_SoNguyen_TrongDoanXY(a, n, 0, 99);
//	interchangeSort(a, n);
//	printf("\nNoi dung cua mang la: ");
//	xuatMang1C_SoNguyen(a, n);
//	int x, kq;
//	printf("\nBan hay cho biet gia tri muon tim: ");
//	scanf("%d", &x);
//	kq = binarySearch_DQ(a, n, 0, n - 1, x);
//	if (kq == -1)
//		printf("\nKhong tim thay %d trong mang", x);
//	else
//		printf("\nTim thay %d trong mang tai vi tri %d", x, kq);
//	getch();
//}