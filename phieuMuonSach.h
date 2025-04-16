//
// Created by VICTUS on 4/13/2025.
//

#ifndef PHIEUMUONSACH_H
#define PHIEUMUONSACH_H
#include <stdio.h>
#include <string.h>
#include "docGia.h"
#include "sach.h"
#define MAX_PHIEUMUON 100
extern char dsPhieuMuon[100][4][50];
extern int soPhieuMuon;
#endif //PHIEUMUONSACH_H
//int tonTaiMaDocGia(char a[][9][50], int soDocGia, const char* ma);
int tonTaiMaDocGia2(char maDocGia[]);
//int tonTaiMaDocGia(char maDocGia[]);
int tonTaiMaSach(char maSach[]);
void nhapMuonSach();
void xuatMuonSach();
