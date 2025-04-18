//
// Created by VICTUS on 4/8/2025.
//
#ifndef DOCGIA_H
#define DOCGIA_H
#define MAX_DOC_GIA 100
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
void timKiemTheoTen(char dsDocGia[][9][50], int soDocGia, char s[]);
#endif //DOCGIA_H
