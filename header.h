#pragma once
#define MAX_SACH 1000
#define THUOC_TINH_SACH 6
#include <stdlib.h>

#include "menu.h"
#include "docGia.h"
#include "sach.h"
#include "phieuMuonSach.h"
#include "phieuTraSach.h"
void clearScreen();
void quanLyDocGia();
char quanLyDocGia(char c);
void nhapDanhSach(char a[][9][50], int* soDocGia);
void xuatDanhSach(char a[][9][50], int soDocGia);
const char* cacThuocTinh(int n);
void chinhSuaThongTin(char a[][9][50], int soDocGia, char s[]);
void xoaDocGia(char a[][9][50], int* soDocGia, char s[]);
void timKiemTheoCMND(char a[][9][50], int soDocGia, char s[]);
void timKiemTheoTen(char a[][9][50], int soDocGia, char s[]);

//void xemDanhSachSach(char a[][THUOC_TINH_SACH][100], int soSach);
//void themSach(char a[][THUOC_TINH_SACH][100], int* soSach);
//void chinhSuaSach(char a[][THUOC_TINH_SACH][100], int soSach, char isbn[]);
//void xoaSach(char a[][THUOC_TINH_SACH][100], int* soSach, char isbn[]);
//void timKiemSachTheoISBN(char a[][THUOC_TINH_SACH][100], int soSach, char isbn[]);
//void timKiemSachTheoTen(char a[][THUOC_TINH_SACH][100], int soSach, char ten[]);
//const char* thuocTinhSach(int n);
//char quanLySach(char c);

const char* thuocTinhSach(int n);

void nhapSach(char ds[][8][50], int* soSach);
void xuatSach(char ds[][8][50], int soSach);
void chinhSuaSach(char ds[][8][50], int soSach, char isbn[]);
void xoaSach(char ds[][8][50], int* soSach, char isbn[]);
void timSachTheoISBN(char ds[][8][50], int soSach, char isbn[]);
void timSachTheoTen(char ds[][8][50], int soSach, char ten[]);

char quanLySach(char c);


