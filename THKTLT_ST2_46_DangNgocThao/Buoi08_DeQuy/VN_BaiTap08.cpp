//#include <stdio.h>
//#include <conio.h>
//#include <math.h>
//int timChuSoDau_DQ(int n);
//int demSo(int n);
//int timSoDaoNguoc_DQ(int n);
//int chuSoLonNhat_DQ(int n);
//int chuSoNhoNhat_DQ(int n);
//int ktToanLe_DQ(int n);
//int ktToanChan_DQ(int n);
//void menu();
//void process();
//void main()
//{
//	process();
//	getch();
//}
//int timChuSoDau_DQ(int n)
//{
//	if (n < 10)return n;
//	return timChuSoDau_DQ(n / 10);
//}
//int demSo(int n)
//{
//	int d = 0;
//	while (n != 0)
//	{
//		n = n / 10;
//		d++;
//	}
//	return d;
//}
//int timSoDaoNguoc_DQ(int n)
//{
//	if (n == 0) return n;
//	return (n % 10) * pow(10, demSo(n) - 1) + timSoDaoNguoc_DQ(n / 10);
//}
//int chuSoLonNhat_DQ(int n)
//{
//	if (n == 0)
//		return 0;
//	else
//		return n % 10 > chuSoLonNhat_DQ(n / 10) ? n % 10 : chuSoLonNhat_DQ(n / 10);
//}
//int chuSoNhoNhat_DQ(int n)
//{
//	if (n == 0)
//		return 0;
//	else
//		return n % 10 < chuSoNhoNhat_DQ(n / 10) ? n % 10 : chuSoNhoNhat_DQ(n / 10);
//}
//int ktToanLe_DQ(int n)
//{
//	if (n == 0)
//		return 1;
//	else
//		return n % 2 == 0 ? 0 : ktToanLe_DQ(n / 10);
//}
//int ktToanChan_DQ(int n)
//{
//	if (n == 0)
//		return 1;
//	else
//		return n % 2 == 1 ? 0 : ktToanChan_DQ(n / 10);
//}
//void menu()
//{
//	printf("\nMenu");
//	printf("\n0. Thoat");
//	printf("\n1. Tim chu so dau tien cua n");
//	printf("\n2. Tim chu so dao nguoc cua so nguyen duong n");
//	printf("\n3. Tim chu so lon nhat cua so nguyen duong n");
//	printf("\n4. Tim chu so nho nhat cua so nguyen duong n");
//	printf("\n5. Kiem tra so nguyen duong n co toan chu so le hay khong");
//	printf("\n6. Kiem tra so nguyen duong n co toan chu so chan hay khong");
//}
//void process()
//{
//	int n, cn;
//	do
//	{
//		menu();
//		printf("\nBan hay chon mot chuc nang bat ky: ");
//		scanf("%d", &cn);
//		switch (cn)
//		{
//		case 1:
//		{
//			do
//			{
//				printf("\nNhap so nguyen n: ");
//				scanf("%d", &n);
//			} while (n < 0);
//			printf("\nChu so dau tien cua n: %d", timChuSoDau_DQ(n));
//			break;
//		}
//		case 2:
//		{
//			do
//			{
//				printf("\nNhap so nguyen n: ");
//				scanf("%d", &n);
//			} while (n < 0);
//			printf("\nChu so dao nguoc cua n: %d", timSoDaoNguoc_DQ(n));
//			break;
//		}
//		case 3:
//		{
//			do
//			{
//				printf("\nNhap so nguyen n: ");
//				scanf("%d", &n);
//			} while (n < 0);
//			printf("\nChu so lon nhat trong n: %d", chuSoLonNhat_DQ(n));
//			break;
//		}
//		case 4:
//		{
//			do
//			{
//				printf("\nNhap so nguyen n: ");
//				scanf("%d", &n);
//			} while (n < 0);
//			printf("\nChu so nho nhat trong n: %d", chuSoNhoNhat_DQ(n));
//			break;
//		}
//		case 5:
//		{
//			do
//			{
//				printf("\nNhap so nguyen n: ");
//				scanf("%d", &n);
//			} while (n < 0);
//			int kq = ktToanLe_DQ(n);
//			if (kq == 1)
//				printf("\nSo nguyen duong n co toan chu so le");
//			else
//				printf("\nSo nguyen duong n khong co toan chu so le");
//			break;
//		}
//		case 6:
//		{
//			do
//			{
//				printf("\nNhap so nguyen n: ");
//				scanf("%d", &n);
//			} while (n < 0);
//			int kq = ktToanChan_DQ(n);
//			if (kq == 1)
//				printf("\nSo nguyen duong n co toan chu so chan");
//			else
//				printf("\nSo nguyen duong n khong co toan chu so chan");
//			break;
//		}
//		default:
//			break;
//		}
//	} while (cn != 0);
//}