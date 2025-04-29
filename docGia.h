#pragma once
#include "hamExtra.h"

#define MAX_USERS 100
#define MAX_DOC_GIA_ID_LENGTH 20
#define MAX_GENDER_LENGTH 10
#define MAX_TEXT_LENGTH 100
#define MAX_DATE_LENGTH 20
#define MAX_GENDER_LENGTH 10

//Khai báo biến toàn cục
extern int soDocGia;
extern char maDocGia[MAX_USERS][MAX_DOC_GIA_ID_LENGTH];
extern char gioiTinh[MAX_USERS][MAX_GENDER_LENGTH];
extern char cmnd[MAX_USERS][MAX_TEXT_LENGTH];
extern char birth[MAX_USERS][MAX_DATE_LENGTH];
extern char gioiTinh[MAX_USERS][MAX_GENDER_LENGTH];
extern char email[MAX_USERS][MAX_TEXT_LENGTH];
extern char diaChi[MAX_USERS][MAX_TEXT_LENGTH];
extern char ngayLapThe[MAX_USERS][MAX_DATE_LENGTH];
extern char ngayHetHan[MAX_USERS][MAX_DATE_LENGTH];

//Khai báo tên hàm
void themDocGia();
void xuatDanhSach();
void suaThongTinDocGia();
void xoaThongTinDocGia();
void timKiemDocGiaTheoCMND();
void timKiemDocGiaTheoHoTen();
void menuDocGia();
void quanLyDocGia();


