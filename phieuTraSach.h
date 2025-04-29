#pragma once

#include "docGia.h"
#include "sach.h"
#include "phieuMuonSach.h"
#include "hamExtra.h"

#define MAX_PHIEUTRA 100
#define MAX_STRING 50

extern char isbnPhieuTra[MAX_PHIEUTRA][MAX_STRING];
extern char maDocGiaPhieuTra[MAX_PHIEUTRA][MAX_STRING];
extern int tienPhatPhieuTra[MAX_PHIEUTRA];
extern char dsPhieuTra[100][7][50];
extern int soPhieuTra;

int tinhSoNgayTrongNam(int d, int m, int y);
int tinhTongSoNgay(int d, int m, int y);
int tinhTienPhat(char ngayMuon[], char ngayTraThucTe[]);
void cong7Ngay(char ngayMuon[], char ngayTraDuKien[]);
void nhapTraSach();
void xuatTraSach();

