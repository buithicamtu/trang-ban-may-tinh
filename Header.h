#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<string>
#include <stdlib.h>
using namespace std;
struct Sach
{
	string maSach;
	string tenSach;
	string tacGia;
	string nhaXB;
	int donGia;
};
struct NodeSach
{
	Sach data;
	NodeSach* next;
};
struct ListSach
{
	NodeSach* head;
	NodeSach* tail;
};
struct TheLoaiSach
{
	string maTheLoaiSach;
	string tenTheLoaiSach;
	int soSach;
	ListSach dsSach;
};
struct NodeTheLoaiSach
{
	TheLoaiSach data;
	NodeTheLoaiSach* next;
};
struct ListTheLoaiSach
{
	NodeTheLoaiSach* head;
	NodeTheLoaiSach* tail;
};
void insertTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach, TheLoaiSach data);
void insertSach(ListSach& dsSach, Sach data);
NodeTheLoaiSach* timTheoMaTheLoaiSach(ListTheLoaiSach dsTheLoaiSach, string maTheLoaiSach);
NodeSach* timTheoMaSach(ListTheLoaiSach dsTheLoaiSach, string maSach);
NodeTheLoaiSach* timTheLoaiSachTheoMaSach(ListTheLoaiSach dsTheLoaiSach, string maSach);
void taoRongdsTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach);
void taoRongdsSach(ListSach& dsSach);
void xuatDSSach(ListSach dsSach);
void xuatThongTin1TheLoaiSach(TheLoaiSach TheLoaiSach);
void xuatDanhSachThongTinTheLoaiSach(ListTheLoaiSach dsTheLoaiSach);
void themTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach);
void them1Sach(ListTheLoaiSach dsTheLoaiSach, ListSach& dsSach);
void them1SachVaoTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach);
void nhapDSSachChoTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach);
void xoaTheLoaiSachTheoMa(ListTheLoaiSach& dsTheLoaiSach, string maTheLoaiSach);
void xoaTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach);
void suaTheLoaiSach(ListTheLoaiSach& dsTheLoaiSach);
void timTheLoaiSach(ListTheLoaiSach dsTheLoaiSach);
void xuatDanhSachThongTinSachTheoMaTheLoaiSach(ListTheLoaiSach dsTheLoaiSach);
void xuatThongTinTheLoaiSachTheoMaSach(ListTheLoaiSach dsTheLoaiSach);
void menu();