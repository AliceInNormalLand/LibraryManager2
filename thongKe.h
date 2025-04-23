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
int thongKeDocGia();
int thongKeGioiTinh();
int thongKeSachMuon();
int thongKeTreHan();
void thongKeCoBan();