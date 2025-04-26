//
// Created by VICTUS on 4/8/2025.
//
#define MAX_SACH 100
#ifndef SACH_H
#define SACH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*extern char dsSach[MAX_SACH][8][50];  // Cấp phát bộ nhớ thật sự
extern int soSach;

void menuSach();
char quanLySach();
const char* thuocTinhSach(int n);
bool tonTaiMaSach(char ds[][8][50], int soSach, const char* maCanKiem);
void nhapSach(char ds[][8][50], int* soSach);
void xuatSach(char ds[][8][50], int soSach);
void chinhSuaSach(char ds[][8][50], int soSach, char isbn[]);
void xoaSach(char ds[][8][50], int* soSach, char isbn[]);
void timSachTheoISBN(char ds[][8][50], int soSach, char isbn[]);
void timSachTheoTen(char ds[][8][50], int soSach, char ten[]);*/
#endif //SACH_H
#define MAX_TEXT_LENGTH 50
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
void xemDanhSachSach();

// Hàm kiểm tra ISBN đã tồn tại chưa
int tonTaiISBN(const char* isbn);

// Hàm thêm sách
void themSach();

// Hàm tìm sách theo ISBN
void timKiemISBN();

// Hàm tìm sách theo tên
void timKiemTen();

// Hàm chỉnh sửa sách
void chinhSuaSach();

// Hàm xóa sách
void xoaSach();

void menuSach();

char quanLySach();
