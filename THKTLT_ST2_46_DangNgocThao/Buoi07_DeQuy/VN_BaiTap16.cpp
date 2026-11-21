//#include <stdio.h>
//#include <conio.h>
//#include <math.h>
//int tinhY(int n);
//int tinhY_DeQuy(int n);
//void menu();
//void process();
//void main()
//{
//	process();
//	getch();
//}
//int tinhY(int n)
//{
//	if (n == 1)return 1;
//	if (n == 2)return 2;
//	if (n == 3)return 3;
//	int y3 = 1, y2 = 2, y1 = 3, y;
//	for (int i = 4; i <= n; i++)
//	{
//		y = y1 + 2 * y2 + 3 * y3;
//		y3 = y2;
//		y2 = y1;
//		y1 = y;
//	}
//	return y;
//}
//int tinhY_DeQuy(int n)
//{
//	if (n == 1)return 1;
//	if (n == 2)return 2;
//	if (n == 3)return 3;
//	return tinhY_DeQuy(n - 1) + 2 * tinhY_DeQuy(n - 2) + 3 * tinhY_DeQuy(n - 3);
//}
//void menu()
//{
//	printf("\nMenu");
//	printf("\n0. Thoat");
//	printf("\n1. Tinh Yn");
//	printf("\n2. Tinh Yn de quy");
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
//				printf("\nNhap thu hang can tinh: ");
//				scanf("%d", &n);
//			} while (n < 1);
//			printf("\nYn = %d", tinhY(n));
//			break;
//		}
//		case 2:
//		{
//			do
//			{
//				printf("\nNhap thu hang can tinh: ");
//				scanf("%d", &n);
//			} while (n < 1);
//			printf("\nYn = %d", tinhY_DeQuy(n));
//			break;
//		}
//		default:
//			break;
//		}
//	} while (cn != 0);
//}
