#include <stdio.h>
#include <conio.h>
double tienDien(int sc, int sm)
{
	int s = sm - sc;
	double t = 0;
	if (s <= 50)
		t = s * 1.678;
	else
		if (s <= 100)
			t = 83.9 + (s - 50) * 1.734;
		else
			if (s <= 200)
				t = 170.6 + (s - 100) * 2.014;
			else
				if (s <= 300)
					t = 372 + (s - 200) * 2.536;
				else
					if (s <= 400)
						t = 625.6 + (s - 300) * 2.834;
					else
						t = 909 + (s - 400) * 2.927;
	return t;
}
void main()
{
	int sc, sm;
	do
	{
		printf("\nNhap so dien cu, so dien moi: ");
		scanf("%d %d", &sc, &sm);
	} while (sc > sm);
	printf("\nTien dien: %.3lf", tienDien(sc, sm));
	getch();
}