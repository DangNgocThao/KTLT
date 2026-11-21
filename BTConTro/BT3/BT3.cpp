#include "stdio.h"
#include "conio.h"
#include "string.h"
void main()
{
	char st[50], * p;
	int n;
	printf("\nNhap chuoi: ");
	gets_s(st);
	p = st;
	printf("\nChuoi vua nhap la: %s", p);
	getch();
}