#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hamExtra.h"

#define MAX_TEXTS_LENGTH 50
#define MAX_SACH 100

//Khai báo biến toàn cục
extern int soSach;
extern struct sach danhSachSach[MAX_SACH];

//Khai báo tên hàm
void menuSach();
void GhiTapTinSach(sach danhSachSach[], int soSach);
void DocMangTuTapTinSach(sach danhSachSach[], int& n);
void xemDanhSachSach();
void themSach();
void timKiemISBN();
void timKiemTen();
void chinhSuaSach();
void xoaSach();
void quanLySach();

//Moi nhat
struct sach {
    char ISBN[MAX_TEXTS_LENGTH];
    char tenSach[MAX_TEXTS_LENGTH];
    char tacGia[MAX_TEXTS_LENGTH];
    char nhaXuatBan[MAX_TEXTS_LENGTH];
    char namXuatBan[MAX_TEXTS_LENGTH];
    char theLoai[MAX_TEXTS_LENGTH];
    char giaSach[MAX_TEXTS_LENGTH];
    char soLuong[MAX_TEXTS_LENGTH];
};

