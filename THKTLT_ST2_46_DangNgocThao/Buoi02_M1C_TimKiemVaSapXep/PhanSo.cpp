#include"PhanSo.h"
void doiDauPS(PS& x)
{
	if (x.mau < 0)
	{
		x.tu *= -1;
		x.mau *= -1;
	}
}
int timUSCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a == 0 || b == 0)
		return 1;
	while (a != b)
	{
		if (a >= b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
void rutGonPS(PS& x)
{
	int usclc = timUSCLN(x.tu, x.mau);
	x.tu /= usclc;
	x.mau /= usclc;
}
double tinhGiaTriPS(PS x)
{
	return (double)x.tu / x.mau;
}
void taoPS(PS& x)
{
	x.tu = rand() % 9 + 1;
	do
	{
		x.mau = rand() % 9 + 1;
	} while (x.mau == 0);
	doiDauPS(x);
	rutGonPS(x);
}
void xuatPS(PS x)
{
	printf(" %d/%d;", x.tu, x.mau);
}