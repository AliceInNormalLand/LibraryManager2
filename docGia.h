//
// Created by VICTUS on 4/8/2025.
//
#pragma once
/*#define MAX_DOC_GIA 100
#include <string.h>
#include <stdlib.h>
extern char dsDocGia[MAX_DOC_GIA][9][50];  // Khai báo mảng toàn cục
extern int soDocGia;

void menuDocGia();
void quanLyDocGia();
const char* cacThuocTinh(int index);
int tonTaiMaDocGia(char dsDocGia[][9][50], int soDocGia, const char* ma);
void nhapDanhSach(char dsDocGia[][9][50], int* soDocGia);
void xuatDanhSach(char dsDocGia[][9][50], int soDocGia);
void chinhSuaThongTin(char dsDocGia[][9][50], int soDocGia, char s[]);
void xoaDocGia(char dsDocGia[][9][50], int* soDocGia, char s[]);
void timKiemTheoCMND(char dsDocGia[][9][50], int soDocGia, char s[]);
void timKiemTheoTen(char dsDocGia[][9][50], int soDocGia, char s[]);*/
#define MAX_USERS 100
#define MAX_DOC_GIA_ID_LENGTH 20
#define MAX_GENDER_LENGTH 10
extern int soDocGia;
extern char maDocGia[MAX_USERS][MAX_DOC_GIA_ID_LENGTH];
extern char gioiTinh[MAX_USERS][MAX_GENDER_LENGTH];
void nhapNgayLapThe(int index);
// Hàm thêm độc giả mới
void themDocGia();
// Hàm xuất danh sách độc giả
void xuatDanhSach();
void suaThongTinDocGia();
void xoaThongTinDocGia();
void timKiemDocGiaTheoCMND();
void timKiemDocGiaTheoHoTen();
void menuDocGia();
void quanLyDocGia();

