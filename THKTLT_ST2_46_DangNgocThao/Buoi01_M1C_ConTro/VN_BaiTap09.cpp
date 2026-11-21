#include "stdio.h"
#include "conio.h"
void main()
{
	float a, b, tong, hieu, tich, thuong;
	printf("\nNhap hai so a, b: ");
	scanf("%f %f", &a, &b);
	float* pa = &a;
	float* pb = &b;
	tong = *pa + *pb;
	hieu = *pa - *pb;
	tich = *pa * *pb;
	thuong = *pa / *pb;
	printf("\n%f + %f = %f, dia chi tong: %X", *pa, *pb, tong, &tong);
	printf("\n%f - %f = %f, dia chi hieu: %X", *pa, *pb, hieu, &hieu);
	printf("\n%f * %f = %f, dia chi tich: %X", *pa, *pb, tich, &tich);
	printf("\n%f / %f = %f, dia chi thuong: %X", *pa, *pb, thuong, &thuong);
	getch();
}