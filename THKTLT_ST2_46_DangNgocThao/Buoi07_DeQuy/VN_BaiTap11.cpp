//#include <stdio.h>
//#include <conio.h>
//#include <math.h>
//int fibonacci(int n);
//int fibonacciBeHonn(int n);
//void main()
//{
//	int n, kq;
//	printf("\nNhap n: ");
//	scanf("%d", &n);
//	kq = fibonacciBeHonn(n);
//	if (kq == -1)
//		printf("\nKhong so Fibonacci lon nhat nho hon %d", n);
//	else
//		printf("\nSo Fibonacci lon nhat nho hon %d la %d", n, kq);
//	getch();
//}
//int fibonacci(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return fibonacci(n - 1) + fibonacci(n - 2);
//}
//int fibonacciBeHonn(int n)
//{
//	if (n <= 1)
//		return -1;
//	for (int i = 2; i <= n + 1; i++)
//	{
//		if (fibonacci(i) >= n)
//			return fibonacci(i - 1);
//	}
//}