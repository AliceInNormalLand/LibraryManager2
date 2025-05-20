#pragma once

#include <stdio.h>
#include <string.h>
#include "docGia.h"
#include "sach.h"
#include "hamExtra.h"

#define MAX_SACH 100
#define MAX_PHIEUMUON 100
#define MAX_STRING 50

extern int soPhieuMuon;
extern struct phieuMuon danhSachPMuon[MAX_PHIEUMUON];

void nhapMuonSach();
void xuatMuonSach();

struct phieuMuon {
    int maPhieuMuon;
    char maDocGiaPhieuMuon[50];
    char isbnPhieuMuon[50];
    char ngayMuon[50];
    char ngayTraDuKien[50];
};
