#include "stdio.h"
#include "conio.h"
void nhapM1C(int ia[], int &in);
float tbcM1C(int ia[], int in);
int main()
{
	int ia[50], in;
	nhapM1C(ia, in);
	printf("\nTrung binh cong: %.2f", tbcM1C(ia, in));
	getch();
}
void nhapM1C(int ia[], int &in)
{
	do
	{
		printf("\nNhap vao gia tri n: ");
		scanf("%d", &in);
	} while (in < 1);
	for (int i = 0; i < in; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &ia[i]);
	}
}
float tbcM1C(int ia[], int in)
{
	float isum = 0;
	for (int i = 0; i < in; i++)
		isum += ia[i];
	return isum /= in;
}