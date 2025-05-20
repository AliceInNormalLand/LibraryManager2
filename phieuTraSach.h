#pragma once
#include "docGia.h"
#include "sach.h"
#include "phieuMuonSach.h"
#include "hamExtra.h"

#define MAX_PHIEUTRA 100
#define MAX_STRING 50

extern int soPhieuTra;
extern struct phieuTra danhSachPTra[MAX_PHIEUTRA];

void nhapTraSach();
void xuatTraSach();

struct phieuTra {
    int maPhieuTra;
    char maDocGiaPhieuTra[MAX_STRING];
    char isbnPhieuTra[MAX_STRING];
    char ngayMuonPhieuTra[MAX_STRING];
    char ngayTraDuKienPhieuTra[MAX_STRING];
    char ngayTraThucTePhieuTra[MAX_STRING];
    char tinhTrangPhieuTra[MAX_STRING];
    int tienPhatPhieuTra;
};

