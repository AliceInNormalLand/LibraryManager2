#pragma once
#include "hamExtra.h"

#define MAX_USERS 100
#define MAX_TEXT_LENGTH 100
#define MAX_DOC_GIA_ID_LENGTH 20
#define MAX_DATE_LENGTH 20
#define MAX_GENDER_LENGTH 10

//Khai báo biến toàn cục
extern int soDocGia;
extern struct docGia danhSachDocGia[MAX_USERS];

//Khai báo tên hàm
void menuDocGia();
void DocMangTuTapTinDocGia(docGia danhSachDocGia[], int& n);
void GhiTapTinDocGia(docGia danhSachDocGia[], int slDocGia);
void themDocGia();
void xuatDanhSach();
void suaThongTinDocGia();
void xoaThongTinDocGia();
void timKiemDocGiaTheoCMND();
void timKiemDocGiaTheoHoTen();
void quanLyDocGia();


//Moi nhat
struct docGia{
    char maDocGia[MAX_DOC_GIA_ID_LENGTH];
    char hoTen[MAX_TEXT_LENGTH];
    char cmnd[MAX_TEXT_LENGTH];
    char ngaySinh[MAX_DATE_LENGTH];
    char gioiTinh[MAX_GENDER_LENGTH];
    char email[MAX_TEXT_LENGTH];
    char diaChi[MAX_TEXT_LENGTH];
    char ngayLapThe[MAX_DATE_LENGTH];
    char ngayHetHan[MAX_DATE_LENGTH];
};


