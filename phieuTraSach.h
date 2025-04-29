#pragma once

#include "docGia.h"
#include "sach.h"
#include "phieuMuonSach.h"
#include "hamExtra.h"

#define MAX_PHIEUTRA 100
#define MAX_STRING 50

extern int maPhieuTra[MAX_PHIEUTRA];
extern char isbnPhieuTra[MAX_PHIEUTRA][MAX_STRING];
extern char maDocGiaPhieuTra[MAX_PHIEUTRA][MAX_STRING];
extern int tienPhatPhieuTra[MAX_PHIEUTRA];
extern char tinhTrangPhieuTra[MAX_PHIEUTRA][MAX_STRING];
extern char dsPhieuTra[100][7][50];
extern int soPhieuTra;

void nhapTraSach();
void xuatTraSach();

