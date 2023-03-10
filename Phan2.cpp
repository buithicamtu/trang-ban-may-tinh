#include"Header.h"
//#include <iostream>
//#include <iomanip>
//#include <conio.h>
//#include<string>
//#include <stdlib.h>
//using namespace std;
//struct Sach
//{
//	string maSach;
//	string tenSach;
//	string tacGia;
//	string nhaXB;
//	int donGia;
//};
//struct NodeSach
//{
//	Sach data;
//	NodeSach* next;
//};
//struct ListSach
//{
//	NodeSach* head;
//	NodeSach* tail;
//};
//struct TheLoaiSach
//{
//	string maTheLoaiSach;
//	string tenTheLoaiSach;
//	int soSach;
//	ListSach dsSach;
//};
//struct NodeTheLoaiSach
//{
//	TheLoaiSach data;
//	NodeTheLoaiSach* next;
//};
//struct ListTheLoaiSach
//{
//	NodeTheLoaiSach* head;
//	NodeTheLoaiSach* tail;
//};
void insertTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach, TheLoaiSach data)
{
	NodeTheLoaiSach* newNode = (NodeTheLoaiSach*)malloc(sizeof(NodeTheLoaiSach));
	newNode = new NodeTheLoaiSach{ data,NULL };
	if (dsTheLoaiSach.head == NULL)
	{
		dsTheLoaiSach.head = newNode;
		dsTheLoaiSach.tail = newNode;
		return;
	}
	dsTheLoaiSach.tail->next = newNode;
	dsTheLoaiSach.tail = newNode;
}
void insertSach(ListSach& dsSach, Sach data)
{
	NodeSach* newNode = (NodeSach*)malloc(sizeof(NodeSach));
	newNode = new NodeSach{ data,NULL };
	if (dsSach.head == NULL)
	{
		dsSach.head = newNode;
		dsSach.tail = newNode;
		return;
	}
	dsSach.tail->next = newNode;
	dsSach.tail = newNode;
}
NodeTheLoaiSach* timTheoMaTheLoaiSach(ListTheLoaiSach dsTheLoaiSach, string maTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
		return NULL;
	for (NodeTheLoaiSach* p = dsTheLoaiSach.head; p != NULL; p = p->next)
		if (p->data.maTheLoaiSach == maTheLoaiSach)
			return p;
	return NULL;
}
NodeSach* timTheoMaSach(ListTheLoaiSach dsTheLoaiSach, string maSach)
{
	for (NodeTheLoaiSach* k = dsTheLoaiSach.head; k != NULL; k = k->next)
		for (NodeSach* p = k->data.dsSach.head; p != NULL; p = p->next)
			if (p->data.maSach == maSach)
				return p;
	return NULL;
}
NodeTheLoaiSach* timTheLoaiSachTheoMaSach(ListTheLoaiSach dsTheLoaiSach, string maSach)
{
	for (NodeTheLoaiSach* k = dsTheLoaiSach.head; k != NULL; k = k->next)
		for (NodeSach* p = k->data.dsSach.head; p != NULL; p = p->next)
			if (p->data.maSach == maSach)
				return k;
	return NULL;
}
void taoRongdsTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach)
{
	dsTheLoaiSach.head = NULL;
	dsTheLoaiSach.tail = NULL;
}
void taoRongdsSach(ListSach& dsSach)
{
	dsSach.head = NULL;
	dsSach.tail = NULL;
}
void xuatDSSach(ListSach dsSach)
{
	if (dsSach.head == NULL)
	{
		cout << "Danh sach thong tin sach trong" << endl;
		return;
	}
	cout << "Danh sach thong tin sach \n";
	int i = 0;
	cout << "|" << setw(10) << "STT" << "|" << setw(10) << "Ma Sach" << "|" << setw(30) << "Ten sach" << "|" << setw(30) << "Tac gia" << "|" << setw(30) << "Nha xuat ban" << "|" << setw(15) << "Don gia" << "|" << endl;
	for (NodeSach* p = dsSach.head; p != NULL; p = p->next)
	{
		i++;
		cout << "|" << setw(10) << i << "|" << setw(10) << p->data.maSach << "|" << setw(30) << p->data.tenSach << "|" << setw(30) << p->data.tacGia << "|" << setw(30) << p->data.nhaXB << "|" << setw(15) << p->data.donGia << "|" << endl;
	}
}
void xuatThongTin1TheLoaiSach(TheLoaiSach TheLoaiSach)
{
	cout << "Thong tin the loai sach:" << endl;
	cout << "|" << setw(10) << "Ma" << "|" << setw(30) << "Ten the loai" << "|" << setw(20) << "Tong so sach" << "|" << endl;
	cout << "|" << setw(10) << TheLoaiSach.maTheLoaiSach << "|" << setw(30) << TheLoaiSach.tenTheLoaiSach << "|" << setw(20) << TheLoaiSach.soSach << "|" << endl;
	xuatDSSach(TheLoaiSach.dsSach);
}
void xuatDanhSachThongTinTheLoaiSach(ListTheLoaiSach dsTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
	{
		cout << "Danh sach the loai sach trong" << endl;
		return;
	}
	cout << "Danh sach thong tin the loai sach :\n";
	int i = 0;
	cout << "|" << setw(10) << "STT" << "|" << setw(10) << "Ma" << "|" << setw(30) << "Ten the loai" << "|" << setw(20) << "Tong so sach" << "|" << endl;
	for (NodeTheLoaiSach* p = dsTheLoaiSach.head; p != NULL; p = p->next)
	{
		i++;
		cout << "|" << setw(10) << i << "|" << setw(10) << p->data.maTheLoaiSach << "|" << setw(30) << p->data.tenTheLoaiSach << "|" << setw(20) << p->data.soSach << "|" << endl;
	}
}
void themTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach)
{
	TheLoaiSach d;
	cout << "Ban dang them 1 the loai sach moi : " << endl;
	do
	{
		cout << "Nhap ma the loai sach : ";
		cin >> d.maTheLoaiSach;
		if (timTheoMaTheLoaiSach(dsTheLoaiSach, d.maTheLoaiSach) == NULL)
		{
			break;
		}
		cout << "Ma the loai sach da ton tai, vui long nhap lai ! " << endl;
	} while (1);
	cout << "Nhap ten the loai sach : ";
	cin.ignore();
	getline(cin, d.tenTheLoaiSach);
	d.soSach = 0;
	taoRongdsSach(d.dsSach);
	insertTheLoaiSach(dsTheLoaiSach, d);
	cout << "Them the loai sach moi thanh cong";
}
void them1Sach(ListTheLoaiSach dsTheLoaiSach, ListSach& dsSach)
{
	cout << "Nhap thong tin sach can them : " << endl;
	Sach s;
	do
	{
		cout << "Nhap ma sach : ";
		cin >> s.maSach;
		if (timTheoMaSach(dsTheLoaiSach, s.maSach) == NULL)
		{
			break;
		}
		cout << "Ma sach da ton tai, vui long nhap lai ! " << endl;
	} while (1);
	cout << "Nhap ten sach : ";
	cin.ignore();
	getline(cin, s.tenSach);
	cout << "Nhap tac gia : ";
	getline(cin, s.tacGia);
	cout << "Nhap nha xuat ban : ";
	getline(cin, s.nhaXB);
	do
	{
		cout << "Nhap don gia(>=0) : ";
		cin >> s.donGia;
	} while (s.donGia < 0);
	insertSach(dsSach, s);
	cout << "Them sach moi thanh cong";
}
void them1SachVaoTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
	{
		cout << "Danh sach the loai sach trong" << endl;
		return;
	}
	xuatDanhSachThongTinTheLoaiSach(dsTheLoaiSach);
	cout << "Nhap ma the loai sach can them sach : ";
	string maTheLoaiSach;
	cin >> maTheLoaiSach;
	if (timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach) == NULL)
	{
		cout << "Ma the loai sach khong ton lai !\n";
		return;
	}
	NodeTheLoaiSach* k = timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach);
	them1Sach(dsTheLoaiSach, k->data.dsSach);
	k->data.soSach++;
	cout << "Them 1 sach vao the loai sach thanh cong " << endl;
}
void nhapDSSachChoTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
	{
		cout << "Danh sach the loai sach trong" << endl;
		return;
	}
	xuatDanhSachThongTinTheLoaiSach(dsTheLoaiSach);
	cout << "Nhap ma the loai sach can them sach : ";
	string maTheLoaiSach;
	cin >> maTheLoaiSach;
	if (timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach) == NULL)
	{
		cout << "Ma the loai sach khong ton lai !\n";
		return;
	}
	NodeTheLoaiSach* d = timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach);
	int choice;
	do
	{
		cout << "Ban co muon xoa danh sach thong tin sach truoc day khong ?" << endl;
		cout << "1. Co\n";
		cout << "2. Khong\n";
		cout << "Hay chon....";
		cin >> choice;
	} while (choice != 1 && choice != 2);
	if (choice == 1)
	{
		taoRongdsSach(d->data.dsSach);
		d->data.soSach = 0;
	}
	int n = 0;
	do
	{
		cout << "\nNhap so luong sach can them (>0): ";
		cin >> n;
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		cout << "Lan them thu " << i + 1 << endl;
		them1Sach(dsTheLoaiSach, d->data.dsSach);
	}
	d->data.soSach += n;
	cout << "Nhap danh sach thong tin sach cho the loai sach thanh cong " << endl;
}
void xoaTheLoaiSachTheoMa(ListTheLoaiSach& dsTheLoaiSach, string maTheLoaiSach)
{
	for (NodeTheLoaiSach* p = dsTheLoaiSach.head; p != NULL; p = p->next)
		if (p->data.maTheLoaiSach == maTheLoaiSach)
		{
			if (p == dsTheLoaiSach.head)
			{
				dsTheLoaiSach.head = dsTheLoaiSach.head->next;
			}
			else
			{
				if (p == dsTheLoaiSach.tail)
				{
					NodeTheLoaiSach* q = dsTheLoaiSach.head;
					while (q->next != dsTheLoaiSach.tail)
						q = q->next;
					q->next = NULL;
					dsTheLoaiSach.tail = q;
				}
				else
				{
					NodeTheLoaiSach* q = dsTheLoaiSach.head;
					while (q->next != p)
						q = q->next;
					q->next = p->next;
				}
			}
			cout << "Xoa the loai sach thanh cong \n";
			return;
		}
	cout << "Ma the loai sach khong ton tai !" << endl;
}
void xoaTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
	{
		cout << "Danh sach the loai sach trong" << endl;
		return;
	}
	xuatDanhSachThongTinTheLoaiSach(dsTheLoaiSach);
	cout << "Nhap ma the loai sach can xoa : ";
	string maTheLoaiSach;
	cin >> maTheLoaiSach;
	xoaTheLoaiSachTheoMa(dsTheLoaiSach, maTheLoaiSach);
}
void suaTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
	{
		cout << "Danh sach the loai sach trong" << endl;
		return;
	}
	xuatDanhSachThongTinTheLoaiSach(dsTheLoaiSach);
	cout << "Nhap ma the loai sach can sua : ";
	string maTheLoaiSach;
	cin >> maTheLoaiSach;
	if (timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach) == NULL)
	{
		cout << "Ma the loai sach khong ton lai !\n";
		return;
	}
	NodeTheLoaiSach* k = timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach);
	cout << "Nhap ten the loai sach moi : ";
	cin.ignore();
	getline(cin, k->data.tenTheLoaiSach);
	cout << "Cap nhat thong tin the loai sach thanh cong " << endl;
}
void timTheLoaiSach(ListTheLoaiSach dsTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
	{
		cout << "Danh sach the loai sach trong" << endl;
		return;
	}
	cout << "Nhap ma the loai sach tim : ";
	string maTheLoaiSach;
	cin >> maTheLoaiSach;
	if (timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach) == NULL)
	{
		cout << "Ma the loai sach khong ton lai !\n";
		return;
	}
	NodeTheLoaiSach* k = timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach);
	cout << "Thong tin the loai sach:" << endl;
	cout << "|" << setw(10) << "Ma" << "|" << setw(30) << "Ten the loai" << "|" << setw(20) << "Tong so sach" << "|" << endl;
	cout << "|" << setw(10) << k->data.maTheLoaiSach << "|" << setw(30) << k->data.tenTheLoaiSach << "|" << setw(20) << k->data.soSach << "|" << endl;
}
void xuatDanhSachThongTinSachTheoMaTheLoaiSach(ListTheLoaiSach dsTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
	{
		cout << "Danh sach the loai sach trong" << endl;
		return;
	}
	xuatDanhSachThongTinTheLoaiSach(dsTheLoaiSach);
	cout << "Nhap ma the loai sach: ";
	string maTheLoaiSach;
	cin >> maTheLoaiSach;
	if (timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach) == NULL)
	{
		cout << "Ma the loai sach khong ton lai !\n";
		return;
	}
	NodeTheLoaiSach* k = timTheoMaTheLoaiSach(dsTheLoaiSach, maTheLoaiSach);
	xuatThongTin1TheLoaiSach(k->data);
}
void xuatThongTinTheLoaiSachTheoMaSach(ListTheLoaiSach dsTheLoaiSach)
{
	if (dsTheLoaiSach.head == NULL)
	{
		cout << "Danh sach the loai sach trong" << endl;
		return;
	}
	string maSach;
	cout << "Nhap ma sach : ";
	cin >> maSach;
	if (timTheoMaSach(dsTheLoaiSach, maSach) == NULL)
	{
		cout << "Ma sach khong ton lai !\n";
		return;
	}
	NodeTheLoaiSach* k = timTheLoaiSachTheoMaSach(dsTheLoaiSach, maSach);
	cout << "Thong tin the loai sach:" << endl;
	cout << "|" << setw(10) << "Ma" << "|" << setw(30) << "Ten the loai" << "|" << setw(20) << "Tong so sach" << "|" << endl;
	cout << "|" << setw(10) << k->data.maTheLoaiSach << "|" << setw(30) << k->data.tenTheLoaiSach << "|" << setw(20) << k->data.soSach << "|" << endl;
}
void menu()
{
	cout << "\n\n";
	cout << "     Chuong trinh quan ly The loai sach-Sach\n";
	cout << "==============================================\n";
	cout << "1. Them the loai sach moi\n";
	cout << "2. Xoa the loai sach\n";
	cout << "3. Sua thong tin the loai sach\n";
	cout << "4. Tim the loai sach theo ma\n";
	cout << "5. Nhap danh sach sach theo vao 1 the loai sach\n";
	cout << "6. Xuat thong tin the loai sach theo ma sach\n";
	cout << "7. Them 1 sach vao the loai sach\n";
	cout << "8. Xuat danh sach thong tin the loai sach\n";
	cout << "9. Xuat danh sach thong tin sach theo ma the loai sach\n";
	cout << "0. Thoat\n";
	cout << "==============================================\n";
	cout << "Hay chon....";
}
//int main()
//{
//	ListTheLoaiSach dsTheLoaiSach;
//	taoRongdsTheLoaiSach(dsTheLoaiSach);
//	int choice;
//	do
//	{
//		menu();
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//		{
//			themTheLoaiSach(dsTheLoaiSach);
//			break;
//		}
//		case 2:
//		{
//			xoaTheLoaiSach(dsTheLoaiSach);
//			break;
//		}
//		case 3:
//		{
//			suaTheLoaiSach(dsTheLoaiSach);
//			break;
//		}
//		case 4:
//		{
//			timTheLoaiSach(dsTheLoaiSach);
//			break;
//		}
//		case 5:
//		{
//			nhapDSSachChoTheLoaiSach(dsTheLoaiSach);
//			break;
//		}
//		case 6:
//		{
//			xuatThongTinTheLoaiSachTheoMaSach(dsTheLoaiSach);
//			break;
//		}
//		case 7:
//		{
//			them1SachVaoTheLoaiSach(dsTheLoaiSach);
//			break;
//		}
//		case 8:
//		{
//			xuatDanhSachThongTinTheLoaiSach(dsTheLoaiSach);
//			break;
//		}
//		case 9:
//		{
//			xuatDanhSachThongTinSachTheoMaTheLoaiSach(dsTheLoaiSach);
//			break;
//		}
//		}
//	} while (choice != 0);
//	return 0;
//}

