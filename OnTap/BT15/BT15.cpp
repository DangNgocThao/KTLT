#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
int Distribute(int m, int n)
{
    if (n == 1)
        return 1;
    if (m == 1 || n == 0)
        return 0;
    if (m < n)
        return Distribute(m, m);
    return Distribute(m, n - 1) + Distribute(m - n, n);
}
void main()
{
    int m, n;
    printf("Nhap so phan thuong: ");
    scanf("%d", &m);
    printf("\nNhap so hoc sinh can chia thuong: ");
    scanf("%d", &n);
    printf("\nCo %d cach chia thuong", Distribute(m, n));
    getch();
}