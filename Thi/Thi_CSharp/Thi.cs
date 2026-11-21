using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Thi
{
	class Program
	{
		static void Main(string[] args)
		{
			thucThi();
		}
		static void menu()
		{
			Console.Write("\nMENU");
			Console.Write("\n0. Thoat");
			Console.Write("\n1. Tao mang hai chieu");
			Console.Write("\n2. Xuat mang hai chieu");
			Console.Write("\n3. Xuat cac phan tu cuc tri cua ma tran");
			Console.Write("\n4. Sap xep ma tran sao cho: cac cot co chi so le thi tang dan, con cac cot co chi so chan thi giam dan");
			Console.Write("\n5. Sap xep cho cac duong cheo song song voi duong cheo chinh va ca duong cheo chinh tang dan");
			Console.Write("\n6. Kiem tra cac gia tri trong ma tran co giam dan theo tung cot khong");
			Console.Write("\n7. Liet ke chi so cac dong chua toan gia tri chan");
			Console.Write("\n8. Xuat cac duong cheo song song voi duong cheo chinh");
			Console.Write("\n9. Tim gia tri xuat hien nhieu nhat trong ma tran");
			Console.Write("\n10. Tim cac chu so xuat hien nhieu nhat trong ma tran");
			Console.Write("\n11. Xuat cac duong cheo song song duong cheo phu");
			Console.Write("\n12. Hoan vi hai cot i va j trong ma tran");
		}
		static void thucThi()
		{
			const int MAX = 100;
			int[,] a = new int[MAX, MAX];
			int n = 0;
			int cn = 0;
			do
			{
				menu();
				Console.Write("\nChon chuc nang: ");
				cn = Convert.ToInt32(Console.ReadLine());
				switch (cn)
				{
					case 1:
						{
							taoMTV(a, ref n);
							Console.Write("\nPhan tu trong ma tran:\n");
							xuatMTV(a, n);
							break;
						}
					case 2:
						{
							Console.Write("\nPhan tu trong ma tran:\n");
							xuatMTV(a, n);
							break;
						}
					case 3:
						{
							Console.Write("\nCac phan tu cuc tri trong ma tran:\n");
							xuatCucTri(a, n);
							break;
						}
					case 4:
						{
							sxCotLeTangChanGiam(a, n);
							Console.Write("\nMa tran sau khi sap xep:\n");
							xuatMTV(a, n);
							break;
						}
					case 5:
						{
							sxDuongCheoSSCheoChinhTang(a, n);
							Console.Write("\nMa tran sau khi sap xep:\n");
							xuatMTV(a, n);
							break;
						}
					case 6:
						{
							if (ktCotGiam(a, n) == 1)
							{
								Console.Write("\nMa tran giam dan theo tung cot");
							}
							else
							{
								Console.Write("\nMa tran khong giam dan theo tung cot");
							}
							break;
						}
					case 7:
						{
							chiSoDongToanChan(a, n);
							break;
						}
					case 8:
						{
							Console.Write("\nCac duong cheo song song voi cheo chinh:\n");
							xuatDuongSSCheoChinh(a, n);
							break;
						}
					case 9:
						{
							Console.Write("\nGia tri xuat hien nhieu nhat trong ma tran: {0:D}", soXuatHienNhieuNhat(a, n));
							break;
						}
					case 10:
						{
							cacChuSoXuatHienNhieuNhat(a, n);
							break;
						}
					case 11:
						{
							Console.Write("\nCac duong cheo song song voi cheo phu:\n");
							xuatDuongSSCheoPhu(a, n);
							break;
						}
					case 12:
						{
							int c1 = 0;
							int c2 = 0;
							do
							{
								Console.Write("\nNhap cot thu nhat: ");
								c1 = Convert.ToInt32(Console.ReadLine());
								Console.Write("\nNhap cot thu hai: ");
								c2 = Convert.ToInt32(Console.ReadLine());
							} while (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n);
							doiCot(a, n, c1, c2);
							Console.Write("\nPhan tu trong ma tran:\n");
							xuatMTV(a, n);
							break;
						}
					default:
						break;
				}
			} while (cn != 0);
		}
		static void nhapMTV(int[,] a, ref int n)
		{
			do
			{
				Console.Write("\nNhap cap cua ma tran: ");
				n = Convert.ToInt32(Console.ReadLine());
			} while (n <= 0);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					Console.Write("\na[{0:D}][{1:D}] = ", i, j);
					a[i, j] = Convert.ToInt32(Console.ReadLine());
				}
			}
		}
		static void taoMTV(int[,] a, ref int n)
		{
			do
			{
				Console.Write("\nNhap cap cua ma tran: ");
				n = Convert.ToInt32(Console.ReadLine());
			} while (n <= 0);
			Random rand = new Random();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					a[i, j] = rand.Next(-50, 50);
				}
			}
		}
		static void xuatMTV(int[,] a, int n)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					Console.Write("{0,5:D}", a[i, j]);
				}
				Console.Write("\n\n");
			}
		}
		static int ktPhanTuCucTri(int[,] a, int n, int d, int c)
		{
			int CucDai = 1;
			int CucTieu = 1;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (d + i >= 0 && c + j >= 0 && d + i < n && c + j < n && !(i == 0 && j == 0))
					{
						if (a[d, c] <= a[d + i, c + j])
						{
							CucDai = 0;
						}
						if (a[d, c] >= a[d + i, c + j])
						{
							CucTieu = 0;
						}
						if (CucDai == 0 && CucTieu == 0)
						{
							return 0;
						}
					}
				}
			}
			return 1;
		}
		static void xuatCucTri(int[,] a, int n)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (ktPhanTuCucTri(a, n, i, j) == 1)
					{
						Console.Write("{0,5:D}", a[i, j]);
					}
					else
					{
						Console.Write("     ");
					}
				}
				Console.Write("\n\n");
			}
		}
		static void sx1CotTang(int[,] a, int n, int c)
		{
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (a[i, c] > a[j, c])
					{
						hoanVi(ref a[i, c], ref a[j, c]);
					}
				}
			}
		}
		static void sx1CotGiam(int[,] a, int n, int c)
		{
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (a[i, c] < a[j, c])
					{
						hoanVi(ref a[i, c], ref a[j, c]);
					}
				}
			}
		}
		static void sxCotLeTangChanGiam(int[,] a, int n)
		{
			for (int i = 0; i < n; i++)
			{
				if (i % 2 == 0)
				{
					sx1CotGiam(a, n, i);
				}
				else
				{
					sx1CotTang(a, n, i);
				}
			}
		}
		static void sx1DuongCheoSSCheoChinhTang(int[,] a, int n, int k)
		{
			if (k >= 0)
			{
				for (int i = 0; i + k < n - 1; i++)
				{
					for (int j = i + 1; j + k < n; j++)
					{
						if (a[k + i, i] > a[k + j, j])
						{
							hoanVi(ref a[k + i, i], ref a[k + j, j]);
						}
					}
				}
			}
			else
			{
				k = -k;
				for (int i = 0; i + k < n - 1; i++)
				{
					for (int j = i + 1; j + k < n; j++)
					{
						if (a[i, k + i] > a[j, k + j])
						{
							hoanVi(ref a[i, k + i], ref a[j, k + j]);
						}
					}
				}
			}
		}
		static void sxDuongCheoSSCheoChinhTang(int[,] a, int n)
		{
			for (int i = 2 - n; i < n - 1; i++)
			{
				sx1DuongCheoSSCheoChinhTang(a, n, i);
			}
		}
		static int soLanXuatHienx(int[,] a, int n, int x)
		{
			int d = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (a[i, j] == x)
					{
						d++;
					}
				}
			}
			return d;
		}
		static int kt1CotGiam(int[,] a, int n, int c)
		{
			for (int i = 0; i < n - 1; i++)
			{
				if (a[i, c] <= a[i + 1, c])
				{
					return 0;
				}
			}
			return 1;
		}
		static int ktCotGiam(int[,] a, int n)
		{
			for (int i = 0; i < n; i++)
			{
				if (kt1CotGiam(a, n, i) == 0)
				{
					return 0;
				}
			}
			return 1;
		}
		static void chiSoDongToanChan(int[,] a, int n)
		{
			int kt, d = 0;
			for (int i = 0; i < n; i++)
			{
				kt = 1;
				for (int j = 0; j < n; j++)
				{
					if (a[i, j] % 2 != 0)
					{
						kt = 0;
						break;
					}
				}
				if (kt == 1)
				{
					if (d == 0)
						Console.Write("\nChi so cac dong chua toan gia tri chan: ");
					Console.Write("{0,5:D}", i);
					d++;
				}
			}
			if (d == 0)
				Console.Write("\nKhong co dong nao chua toan gia tri chan");
		}
		static void xuatDuongSSCheoChinh(int[,] a, int n)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i != j && (i != 0 || j != n - 1) && (i != n - 1 || j != 0))
					{
						Console.Write("{0,5:D}", a[i, j]);
					}
					else
					{
						Console.Write("     ");
					}
				}
				Console.Write("\n\n");
			}
		}
		static int demSoLanXuatHien(int[,] a, int n, int x)
		{
			int d = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (a[i, j] == x)
					{
						d++;
					}
				}
			}
			return d;
		}
		static int soXuatHienNhieuNhat(int[,] a, int n)
		{
			int max = demSoLanXuatHien(a, n, a[0, 0]);
			int gt = a[0, 0];
			for (int i = 0; i < n; i++)
			{
				for (int j = 1; j < n; j++)
				{
					if (demSoLanXuatHien(a, n, a[i, j]) > max)
					{
						max = demSoLanXuatHien(a, n, a[i, j]);
						gt = a[i, j];
					}
				}
			}
			return gt;
		}
		static void tachChuSo(int n, int[] b)
		{
			int chuSo;
			n = Math.Abs(n);
			do
			{
				chuSo = n % 10;
				b[chuSo]++;
				n /= 10;
			} while (n > 0);
		}
		static void cacChuSoXuatHienNhieuNhat(int[,] a, int n)
		{
			int[] b = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					tachChuSo(a[i, j], b);
				}
			}
			int chuSoXuatHienNhieuNhat = 0;
			for (int i = 0; i < 10; i++)
			{
				if (b[chuSoXuatHienNhieuNhat] < b[i])
				{
					chuSoXuatHienNhieuNhat = i;
				}
			}
			Console.Write("\nCac chu so xuat hien nhieu nhat: ");
			for (int i = 0; i < 10; i++)
			{
				if (b[chuSoXuatHienNhieuNhat] == b[i])
				{
					Console.Write("{0,5:D}", i);
				}
			}
		}
		static void xuatDuongSSCheoPhu(int[,] a, int n)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i + j != n - 1 && (i != 0 || j != 0) && (i != n - 1 || j != n - 1))
					{
						Console.Write("{0,5:D}", a[i, j]);
					}
					else
					{
						Console.Write("     ");
					}
				}
				Console.Write("\n\n");
			}
		}
		static void hoanVi(ref int a, ref int b)
		{
			int t = a;
			a = b;
			b = t;
		}
		static void doiCot(int[,] a, int n, int c1, int c2)
		{
			for (int i = 0; i < n; i++)
			{
				hoanVi(ref a[i, c1], ref a[i, c2]);
			}
		}
	}
}