//
// Created by VICTUS on 4/13/2025.
//

#ifndef PHIEUMUONSACH_H
#define PHIEUMUONSACH_H
#include <stdio.h>
#include <string.h>
#include "docGia.h"
#include "sach.h"
#include "hamExtra.h"
#define MAX_PHIEUMUON 100
//extern char dsPhieuMuon[100][4][50];
extern int soPhieuMuon;
extern char maDocGiaPhieuMuon[MAX_PHIEUMUON][50];
extern char isbnPhieuMuon[MAX_PHIEUMUON][50];
#endif
int tonTaiMaDocGia2(char maDocGia[]);
int tonTaiMaSach(char maSach[]);
void nhapMuonSach();
void xuatMuonSach();
