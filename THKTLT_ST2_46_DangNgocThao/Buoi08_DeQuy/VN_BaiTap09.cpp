//#include <stdio.h>
//#include <conio.h>
//#include <math.h>
//int toHop_DQ(int k, int n)
//{
//	if (k == 0 || k == n) return 1;
//	return toHop_DQ(k, n - 1) + toHop_DQ(k - 1, n - 1);
//}
//void main()
//{
//	int k, n;
//	do
//	{
//		printf("\nNhap n phan tu: ");
//		scanf("%d", &n);
//		printf("\nNhap chap k: ");
//		scanf("%d", &k);
//	} while (k > n || n < 0 || k < 0);
//	printf("\n%dC%d = %d", n, k, toHop_DQ(k, n));
//	getch();
//}