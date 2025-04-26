//
// Created by VICTUS on 4/18/2025.
//

#ifndef THONGKE_H
#define THONGKE_H
#include <stdio.h>
#include <string.h>

#include "phieuMuonSach.h"
#include "phieuTraSach.h"
#include "sach.h"
#include "docGia.h"
#endif //THONGKE_H
void menuThongKe();
int thongKeSachTV(char dsSach[][8][50], int soSach);
void thongKeLoaiSach(char dsSach[][8][50], int soSach);
int thongKeDocGia(char dsPhieuMuon[][4][50], int soPhieuMuon, int soDocGia);
//int thongKeGioiTinh(char dsDocGia[][9][50], int soDocGia);
void thongKeGioiTinh(char gioiTinh[][10], int soDocGia);
int thongKeSachMuon(int soPhieuMuon, int soPhieuTra);
int thongKeTreHan(int tienPhatPhieuTra[], int soPhieuTra);
//int thongKeTreHan(char dsPhieuTra[][7][50], int soPhieuTra);
void thongKeCoBan();

