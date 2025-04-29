#pragma once

#include "sach.h"
#include "phieuMuonSach.h"

// Khai báo toàn cục
extern void capNhatSauMuon(char maSachTV[]);
extern void capNhatSauTra(char maSachTV[]);

//Khai báo hàm
int tinhSoNgayTrongNam(int d, int m, int y);
int tinhTongSoNgay(int d, int m, int y);
int tinhTienPhat(char ngayMuon[], char ngayTraThucTe[]);
int tinhTienPhatMatSach(char maSachNhap[]);
void cong7Ngay(char ngayMuon[], char ngayTraDuKien[]);
int tonTaiMaDocGia(char maDocGiaNhap[]);
int tonTaiMaSach(char maSachNhap[]);
void nhapNgayLapThe(int index);