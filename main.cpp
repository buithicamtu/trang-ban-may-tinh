#include"Header.h"
int main()
{
	ListTheLoaiSach dsTheLoaiSach;
	taoRongdsTheLoaiSach(dsTheLoaiSach);
	int choice;
	do
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			themTheLoaiSach(dsTheLoaiSach);
			break;
		}
		case 2:
		{
			xoaTheLoaiSach(dsTheLoaiSach);
			break;
		}
		case 3:
		{
			suaTheLoaiSach(dsTheLoaiSach);
			break;
		}
		case 4:
		{
			timTheLoaiSach(dsTheLoaiSach);
			break;
		}
		case 5:
		{
			nhapDSSachChoTheLoaiSach(dsTheLoaiSach);
			break;
		}
		case 6:
		{
			xuatThongTinTheLoaiSachTheoMaSach(dsTheLoaiSach);
			break;
		}
		case 7:
		{
			them1SachVaoTheLoaiSach(dsTheLoaiSach);
			break;
		}
		case 8:
		{
			xuatDanhSachThongTinTheLoaiSach(dsTheLoaiSach);
			break;
		}
		case 9:
		{
			xuatDanhSachThongTinSachTheoMaTheLoaiSach(dsTheLoaiSach);
			break;
		}
		}
	} while (choice != 0);
	return 0;
}