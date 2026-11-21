#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
void menu()
{
	printf("\n0. Thoat");
	printf("\n1. Xuat gia tri tung ky tu cua chuoi thong qua con tro tro den chuoi");
	printf("\n2. Chuyen cac ky tu cua chuoi ve dang chu hoa");
	printf("\n3. Chuyen cac ky tu dau moi tu cua chuoi ve dang chu hoa");
}
void xuatTungKiTu(char *pa)
{
	int max = strlen(pa);
	for (int i = 0; i < max; i++)
	{
		printf("\n%c", *(pa + i));
	}
}
void chuHoa(char* pa)
{
	strupr(pa);
	printf("\nChuoi Hoa: %s", pa);
}
void kiTuDauHoa(char* pa)
{
	*pa = toupper(*pa);
	int max = strlen(pa);
	for (int i = 1; i < max; i++)
	{
		if (*(pa + i) == ' ' && *(pa + i + 1) != ' ')
			*(pa + i + 1) = toupper(*(pa + i + 1));
	}
	printf("\nChuoi ki tu dau moi tu viet hoa: %s", pa);
}
void main()
{
	char st[100];
	printf("\nNhap chuoi: ");
	gets_s(st);
	char* pa = st;
	int cn;
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
			xuatTungKiTu(pa);
			break;
		}
		case 2:
		{
			chuHoa(pa);
			break;
		}
		case 3:
		{
			kiTuDauHoa(pa);
			break;
		}
		default:
			break;
		}
	} while (1);
	getch();
}