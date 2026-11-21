#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 1000
void nhapChuoi(char a[]);
void xuatChuoi(char a[]);
int chieuDaiChuoi(char a[]);
int ktKiTuTrongChuoi(char a[], char c);
int demTu(char a[]);
int ktToanSo(char a[]);
void chuyenKiTuInHoa(char& c);
void chuyenKiTuInThuong(char& c);
void chuyenKiTuDauHoa(char a[]);
void xoaKT(char a[], int vt);
void chuanHoaChuoi(char a[]);
void timten(char a[], char b[]);
void catHoTen(char a[]);
int ktDoiXung(char a[]);
int vitri(char a[], char b[]);
void xoaHet1KT(char a[], char c);
void menu();
void process();
void main()
{
	process();
	getch();
}
void nhapChuoi(char a[])
{
	getc(stdin);
	gets_s(a, MAX);
}
void xuatChuoi(char a[])
{
	printf("%s", a);
}
int chieuDaiChuoi(char a[])
{
	int len = 0;
	while (a[len] != 0) len++;
	return len;
}
int ktKiTuTrongChuoi(char a[], char c)
{
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == c)
			return 1;
		i++;
	}
	return 0;
}
int demTu(char a[])
{
	if (strlen(a) == 0)
		return 0;
	int i = 0;
	while (a[i] == ' ')
	{
		i++;
	}
	int d = 1;
	while (a[i] != '\0')
	{
		if (a[i] == ' ' && a[i + 1] != ' ' && a[i + 1] != '\0')
			d++;
		i++;
	}
	return d;
}
int ktToanSo(char a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] < '0' || a[i] > '9')
			return 0;
		i++;
	}
	return 1;
}
void chuyenKiTuInHoa(char& c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
}
void chuyenKiTuInThuong(char& c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
}
void chuyenKiTuDauHoa(char a[])
{
	if (strlen(a) == 0)
		return;
	int i = 0;
	while (a[i] == ' ')
	{
		i++;
	}
	chuyenKiTuInHoa(a[i]);
	while (a[i] != '\0')
	{
		if (a[i] == ' ' && a[i + 1] != ' ' && a[i + 1] != '\0')
			chuyenKiTuInHoa(a[i + 1]);
		else
			chuyenKiTuInThuong(a[i + 1]);
		i++;
	}
}
void xoaKT(char a[], int vt)
{
	for (int i = vt; i < strlen(a); i++)
	{
		a[i] = a[i + 1];
	}
}
void chuanHoaChuoi(char a[])
{
	while (a[0] == ' ')
	{
		xoaKT(a, 0);
	}
	while (a[strlen(a) - 1] == ' ')
	{
		xoaKT(a, strlen(a) - 1);
	}
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			xoaKT(a, i);
			i--;
		}
	}
}
void timten(char a[], char b[])
{
	int n = strlen(a);
	char s[MAX];
	for (int i = n - 1; i >= 0; i--)
		if (a[i] == ' ')
		{
			strcpy(s, a + i + 1);
			break;
		}
	if (stricmp(s, b) == 0)
		printf("\nTen %s co trong chuoi %s", b, a);
	else
		printf("\nTen khong ton tai");
}
void catHoTen(char a[])
{
	int n = strlen(a);
	char b[MAX];
	for (int i = n - 1; i >= 0; i--)
		if (a[i] == ' ')
		{
			strcpy(b, a + i + 1);
			a[i] = '\0';
			break;
		}
	printf("\nHo lot: %s", a);
	printf("\nTen: %s", b);
}
int ktDoiXung(char a[])
{
	int n = strlen(a);
	for (int i = 0; i < n / 2; i++)
		if (a[i] != a[n - 1 - i]) return 0;
	return 1;
}
int vitri(char a[], char b[])
{
	int d = -1;
	if (strstr(a, b) != NULL)
		d = strlen(a) - strlen(strstr(a, b));
	return d;
}void chen(char a[], char b[], int vt)
{
	char c[MAX];
	strcpy(c, a + vt);
	strcpy(a + vt, b);
	strcat(a, c);
}
void xoaHet1KT(char a[], char c)
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == c)
			xoaKT(a, i);
	}
}
void menu()
{
	printf("\nMenu");
	printf("\n1. Nhap chuoi");
	printf("\n2. Xuat chuoi");
	printf("\n3. Kiem tra ki tu co trong chuoi khong");
	printf("\n4. Dem so tu");
	printf("\n5. Kiem tra chuoi toan so khong");
	printf("\n6. chuyen ki tu dau tien cua moi tu thanh in hoa va nhung tu con lai thanh chu thuong");
	printf("\n7. Chuan hoa chuoi");
	printf("\n8. Tim kiem ten trong chuoi ho ten");
	printf("\n9. Cat chuoi ho ten thanh 2 chuoi ho lot va ten");
	printf("\n10. Kiem tra chuoi doi xung");
	printf("\n11. tim vi tri xuat hien cua chuoi s2 trong chuoi s1. Neu khong co thi noi s2 vao sau s1");
	printf("\n12. Chen chuoi vao vi tri can chen");
	printf("\n13. Xoa ki tu muon xoa trong chuoi");
}
void process()
{
	char a[MAX];
	int cn;
	do
	{
		menu();
		printf("\nBan hay chon mot chuc nang bat ky: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 1:
		{
			printf("\nNhap noi dung chuoi: ");
			nhapChuoi(a);
			printf("\nChuoi vua nhap la: ");
			xuatChuoi(a);
			break;
		}
		case 2:
		{
			printf("\nNoi dung chuoi: ");
			xuatChuoi(a);
			break;
		}
		case 3:
		{
			char c;
			int kt;
			printf("\nNhap ki tu can kiem tra: ");
			getc(stdin);
			scanf("%c", &c);
			kt = ktKiTuTrongChuoi(a, c);
			if (kt == 1)
				printf("\nKi tu %c co trong chuoi %s", c, a);
			else
				printf("\nKi tu %c khong co trong chuoi %s", c, a);
			break;
		}
		case 4:
		{
			printf("\nSo tu trong chuoi: %d", demTu(a));
			break;
		}
		case 5:
		{
			int kt = ktToanSo(a);
			if (kt == 1)
				printf("\nChuoi toan so");
			else
				printf("\nChuoi khong toan so");
			break;
		}
		case 6:
		{
			chuyenKiTuDauHoa(a);
			printf("\nChuoi sau khi chuyen doi la: ");
			xuatChuoi(a);
			break;
		}
		case 7:
		{
			chuanHoaChuoi(a);
			printf("\nChuoi sau khi chuan hoa la: ");
			xuatChuoi(a);
			break;
		}
		case 8:
		{
			char b[MAX];
			printf("\nNhap ten can tim: ");
			nhapChuoi(b);
			chuanHoaChuoi(a);
			chuyenKiTuDauHoa(a);
			timten(a, b);
			break;
		}
		case 9:
		{
			printf("\nNhap chuoi ho ten can cat: ");
			nhapChuoi(a);
			chuanHoaChuoi(a);
			chuyenKiTuDauHoa(a);
			catHoTen(a);
			break;
		}
		case 10:
		{
			int kt = ktDoiXung(a);
			if (kt == 1)
				printf("\nChuoi doi xung");
			else
				printf("\nChuoi khong doi xung");
			break;
		}
		case 11:
		{
			char b[MAX];
			printf("\nNhap chuoi can tim vi tri xuat hien: ");
			nhapChuoi(b);
			int vt = vitri(a, b);
			if (vt == -1)
			{
				strcat(a, b);
				printf("\nChuoi sau khi noi: %s", a);
			}
			else
				printf("\nVi tri xuat hien cua chuoi %s trong chuoi %s la ki tu thu %d", b, a, vt + 1);
			break;
		}
		case 12:
		{
			int vt;
			char b[MAX];
			printf("\nNhap chuoi can chen: ");
			nhapChuoi(b);
			printf("\nNhap vi tri can chen: ");
			scanf("%d", &vt);
			chen(a, b, vt);
			printf("\nChuoi sau khi chen la: ");
			xuatChuoi(a);
			break;
		}
		case 13:
		{
			char c;
			printf("\nNhap ki tu can xoa: ");
			getc(stdin);
			scanf("%c", &c);
			xoaHet1KT(a, c);
			printf("\nChuoi sau xoa het ki tu %c la: ", c);
			xuatChuoi(a);
			break;
		}
		default:
			break;
		}
	} while (cn != 0);
}