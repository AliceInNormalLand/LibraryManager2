//
// Created by VICTUS on 4/13/2025.
//

#ifndef PHIEUTRASACH_H
#define PHIEUTRASACH_H
#include "docGia.h"
#include "phieuMuonSach.h"
#include "hamExtra.h"
#endif //PHIEUTRASACH_H
//moi
#define MAX_PHIEUTRA 100
extern int tienPhatPhieuTra[MAX_PHIEUTRA];

extern char dsPhieuTra[100][7][50];
extern int soPhieuTra;
int tonTaiMaDocGia3(char maDocGia[], char maISBN[]);
int tinhSoNgayTrongNam(int d, int m, int y);
int tinhTongSoNgay(int d, int m, int y);
int tinhTienPhat(char ngayMuon[], char ngayTraThucTe[]);
void cong7Ngay(char ngayMuon[], char ngayTraDuKien[]);
void nhapTraSach();
void xuatTraSach();

