#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hamExtra.h"

#define MAX_TEXT_LENGTH 50
#define MAX_SACH 100

//Khai báo biến toàn cục
extern int soSach;
extern char ISBN[MAX_SACH][MAX_TEXT_LENGTH];
extern char ISBN[MAX_SACH][MAX_TEXT_LENGTH];
extern char tenSach[MAX_SACH][MAX_TEXT_LENGTH];
extern char tacGia[MAX_SACH][MAX_TEXT_LENGTH];
extern char nhaXuatBan[MAX_SACH][MAX_TEXT_LENGTH];
extern char namXuatBan[MAX_SACH][MAX_TEXT_LENGTH];
extern char theLoai[MAX_SACH][MAX_TEXT_LENGTH];
extern char giaSach[MAX_SACH][MAX_TEXT_LENGTH];
extern char soLuong[MAX_SACH][MAX_TEXT_LENGTH];

//Khai báo tên hàm
void xemDanhSachSach();
void themSach();
void timKiemISBN();
void timKiemTen();
void chinhSuaSach();
void xoaSach();
void menuSach();
void quanLySach();

