#pragma once

#include <stdio.h>
#include <string.h>
#include "phieuMuonSach.h"
#include "phieuTraSach.h"
#include "sach.h"
#include "docGia.h"

void menuThongKe();
int thongKeSachTV(char dsSach[][8][50], int soSach);
void thongKeLoaiSach(char dsSach[][8][50], int soSach);
int thongKeDocGia(char dsPhieuMuon[][4][50], int soPhieuMuon, int soDocGia);
void thongKeGioiTinh(char gioiTinh[][10], int soDocGia);
void thongKeSachMuon(int soPhieuMuon, int soPhieuTra);
int thongKeTreHan(int tienPhatPhieuTra[], int soPhieuTra);
void thongKeCoBan();

