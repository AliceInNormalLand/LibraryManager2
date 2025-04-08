//
// Created by VICTUS on 4/8/2025.
//
#ifndef DOCGIA_H
#define DOCGIA_H
void menuDocGia();
void quanLyDocGia();
void nhapDanhSach(char a[][9][50], int* soDocGia);
void xuatDanhSach(char a[][9][50], int soDocGia);
const char* cacThuocTinh(int n);
void chinhSuaThongTin(char a[][9][50], int soDocGia, char s[]);
void xoaDocGia(char a[][9][50], int* soDocGia, char s[]);
void timKiemTheoCMND(char a[][9][50], int soDocGia, char s[]);
void timKiemTheoTen(char a[][9][50], int soDocGia, char s[]);
#endif //DOCGIA_H
