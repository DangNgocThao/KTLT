#include "stdio.h"
#include "conio.h"
#include "string.h"
void main()
{
	char hten[50];
	int nams, thangs;
	char gioitinh[50];
	printf("\nNhap ho va ten: ");
	gets_s(hten);
	int t = 0;
	while (t == 0)
	{
		try {
			printf("\nNhap gioi tinh: ");
			gets_s(gioitinh);
			t = 1;
			if (stricmp(gioitinh, "nu") != 0 && stricmp(gioitinh, "nam") != 0)
			{
				t = 0;
				throw "errcode";
			}
		}
		catch (char* st)
		{
			printf("Gioi tinh khong hop le");
		}
	}
	t = 0;
	while (t == 0)
	{
		try
		{
			printf("\nNhap thang sinh: ");
			scanf("%d", &thangs);
			t = 1;
			if (thangs < 1 || thangs > 12)
			{
				t = 0;
				throw "error_Thang";
			}
		}
		catch (char* st)
		{
			printf("Thang khong hop le");
		}

	}
	t = 0;
	while (t == 0)
	{
		try
		{
			printf("\nNhap nam sinh: ");
			scanf("%d", &nams);
			t = 1;
			if (stricmp(gioitinh, "nu") == 0)
			{
				if (nams > 2003 || nams < 1966)
				{
					t = 0;
					throw 101;
				}
			}
			else
			{
				if (nams > 2003 || nams < 1961)
				{
					t = 0;
					throw 101;
				}
			}
		}
		catch (int num)
		{
			printf("Nam khong hop le");
		}
	}
	printf("\nHo va Ten: ");
	puts(hten);
	printf("\nGioi tinh: ");
	puts(gioitinh);
	if (stricmp(gioitinh, "nu") == 0)
	{
		if (thangs > 0 && thangs < 9 && nams == 1966)
			printf("\nNam ve huu: 2021");
		else
			if ((thangs > 8 && thangs < 13 && nams == 1966) || (thangs > 0 && thangs < 5 && nams == 1967))
				printf("\nNam ve huu: 2022");
			else
				if (thangs > 4 && thangs < 13 && nams == 1967)
					printf("\nNam ve huu: 2023");
				else
					if (thangs > 0 && thangs < 9 && nams == 1968)
						printf("\nNam ve huu: 2024");
					else
						if ((thangs > 8 && thangs < 13 && nams == 1968) || (thangs > 0 && thangs < 6 && nams == 1969))
							printf("\nNam ve huu: 2025");
						else
							if (thangs > 5 && thangs < 13 && nams == 1969)
								printf("\nNam ve huu: 2026");
							else
								if (thangs > 0 && thangs < 9 && nams == 1970)
									printf("\nNam ve huu: 2027");
								else
									if ((thangs > 8 && thangs < 13 && nams == 1970) || (thangs > 0 && thangs < 5 && nams == 1971))
										printf("\nNam ve huu: 2028");
									else
										if (thangs > 5 && thangs < 13 && nams == 1971)
											printf("\nNam ve huu: 2029");
										else
											if (thangs > 0 && thangs < 9 && nams == 1972)
												printf("\nNam ve huu: 2030");
											else
												if ((thangs > 8 && thangs < 13 && nams == 1972) || (thangs > 0 && thangs < 5 && nams == 1973))
													printf("\nNam ve huu: 2031");
												else
													if (thangs > 5 && thangs < 13 && nams == 1973)
														printf("\nNam ve huu: 2032");
													else
														if (thangs > 0 && thangs < 9 && nams == 1974)
															printf("\nNam ve huu: 2033");
														else
															if ((thangs > 8 && thangs < 13 && nams == 1974) || (thangs > 0 && thangs < 5 && nams == 1975))
																printf("\nNam ve huu: 2034");
															else
																printf("\nNam ve huu: %d", nams + 60);
	}
	else
	{
		if (thangs > 0 && thangs < 10 && nams == 1961)
			printf("\nNam ve huu: 2021");
		else
			if ((thangs > 9 && thangs < 13 && nams == 1961) || (thangs > 0 && thangs < 7 && nams == 1962))
				printf("\nNam ve huu: 2022");
			else
				if ((thangs > 6 && thangs < 13 && nams == 1962) || (thangs > 0 && thangs < 4 && nams == 1963))
					printf("\nNam ve huu: 2023");
				else
					if (thangs > 3 && thangs < 13 && nams == 1963)
						printf("\nNam ve huu: 2024");
					else
						if (thangs > 0 && thangs < 10 && nams == 1964)
							printf("\nNam ve huu: 2025");
						else
							if ((thangs > 9 && thangs < 13 && nams == 1964) || (thangs > 0 && thangs < 7 && nams == 1965))
								printf("\nNam ve huu: 2026");
							else
								if ((thangs > 6 && thangs < 13 && nams == 1965) || (thangs > 0 && thangs < 4 && nams == 1966))
									printf("\nNam ve huu: 2027");
								else
									printf("\nNam ve huu: %d", nams + 62);
	}
	getch();
}