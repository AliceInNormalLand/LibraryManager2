#pragma once

#include <stdio.h>
#include <string.h>
#include "phieuMuonSach.h"
#include "phieuTraSach.h"
#include "sach.h"
#include "docGia.h"

void menuThongKe();
int thongKeSachTV(sach danhSachSach[], int soSach);
void thongKeLoaiSach(sach danhSachSach[], int soSach);
void thongKeDocGia(phieuMuon danhSachPMuon, int soPhieuMuon, int tongDocGia);
void thongKeGioiTinh(docGia danhSachDocGia[], int soDocGia);
void thongKeSachMuon(int soPhieuMuon, int soPhieuTra);
int thongKeTreHan(int soPhieuTra);
void thongKeCoBan();

