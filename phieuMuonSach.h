#pragma once

#include <stdio.h>
#include <string.h>
#include "docGia.h"
#include "sach.h"
#include "hamExtra.h"

#define MAX_PHIEUMUON 100
#define MAX_STRING 50

extern int soPhieuMuon;
extern struct phieuMuon danhSachPMuon[MAX_PHIEUMUON];

void GhiTapTinPhieuMuon(phieuMuon danhSachPMuon[], int soPhieuMuon);
void DocMangTuTapTinPhieuMuon(phieuMuon danhSachPMuon[], int& n);
void nhapMuonSach();
void xuatMuonSach();

struct phieuMuon {
    int maPhieuMuon;
    char maDocGiaPhieuMuon[MAX_STRING];
    char isbnPhieuMuon[MAX_STRING];
    char ngayMuon[MAX_STRING];
    char ngayTraDuKien[MAX_STRING];
};
