//
// Created by VICTUS on 4/8/2025.
//
#ifndef DOCGIA_H
#define DOCGIA_H
#define MAX_DOC_GIA 100
#define MAX_STRING 50
extern char dsDocGia[MAX_DOC_GIA][9][50];  // Khai báo mảng toàn cục
extern int soDocGia;
void menuDocGia();
void quanLyDocGia();
const char* cacThuocTinh(int index);
int tonTaiMaDocGia(char a[][9][50], int soLuong, const char* ma);
//int tonTaiMaDocGia(char a[][9][50], int soDocGia, const char* ma);
void nhapDanhSach();
void xuatDanhSach();
//void nhapDanhSach(char a[][9][50], int* soDocGia);
//void xuatDanhSach(char a[][9][50], int soDocGia);
//const char* cacThuocTinh(int n);
void chinhSuaThongTin(char a[][9][50], int soDocGia, char s[]);
void xoaDocGia(char a[][9][50], int* soDocGia, char s[]);
void timKiemTheoCMND(char a[][9][50], int soDocGia, char s[]);
void timKiemTheoTen(char a[][9][50], int soDocGia, char s[]);
#endif //DOCGIA_H
