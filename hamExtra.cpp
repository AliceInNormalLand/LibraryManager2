#include <string.h>
#include <stdio.h>
#include "hamExtra.h"

#include "docGia.h"


// Tính tổng số ngày của 1 năm tới 1 ngày cụ thể
int tinhSoNgayTrongNam(int d, int m, int y) {
    int ngayTrongThang[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ngayTrongThang[2] = 29;

    int tongNgay = d;
    for (int i = 1; i < m; i++) {
        tongNgay += ngayTrongThang[i];
    }
    return tongNgay;
}

// Tổng số ngày tính từ năm 0 tới ngày đó
int tinhTongSoNgay(int d, int m, int y) {
    return y * 365 + y / 4 - y / 100 + y / 400 + tinhSoNgayTrongNam(d, m, y);
}

// Hàm tính tiền phạt
int tinhTienPhat(char ngayMuon[], char ngayTraThucTe[]) {
    int d1, m1, y1, d2, m2, y2;

    sscanf(ngayMuon, "%2d/%2d/%4d", &d1, &m1, &y1);
    sscanf(ngayTraThucTe, "%2d/%2d/%4d", &d2, &m2, &y2);

    int ngayMuonTotal = tinhTongSoNgay(d1, m1, y1);
    int ngayTraTotal = tinhTongSoNgay(d2, m2, y2);

    int soNgayMuon = ngayTraTotal - ngayMuonTotal;
    int tienPhat = 0;

    if (soNgayMuon > 7) {
        tienPhat = (soNgayMuon - 7) * 5000;
    }

    return tienPhat;
}

void cong7Ngay(char ngayMuon[], char ngayTraDuKien[]) {
    int d, m, y;
    sscanf(ngayMuon, "%2d/%2d/%4d", &d, &m, &y);

    d += 7;

    int ngayTrongThang[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ngayTrongThang[2] = 29;

    while (d > ngayTrongThang[m]) {
        d -= ngayTrongThang[m];
        m++;
        if (m > 12) {
            m = 1;
            y++;
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                ngayTrongThang[2] = 29;
            else
                ngayTrongThang[2] = 28;
        }
    }
    sprintf(ngayTraDuKien, "%02d/%02d/%04d", d, m, y);
}

// Hàm cập nhật số lượng sách sau khi mượn
void capNhatSauMuon(char maSachTV[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], maSachTV) == 0) {
            int soLuongSach = atoi(soLuong[i]);
            soLuongSach -= 1;
            sprintf(soLuong[i], "%d", soLuongSach); // chuyển thẳng số thành chuỗi
        }
    }
}

// Hàm cập nhật số lượng sách sau khi trả
void capNhatSauTra(char maSachTV[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], maSachTV) == 0) {
            int soLuongSach = atoi(soLuong[i]);
            soLuongSach += 1;
            sprintf(soLuong[i], "%d", soLuongSach); // chuyển thẳng số thành chuỗi
        }
    }
}

int tonTaiMaDocGia(char maDocGiaNhap[]) {
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(maDocGia[i], maDocGiaNhap) == 0) {
            return 1; // Mã độc giả đã tồn tại
        }
        return 0; // Chưa có
    }
}

// Hàm kiểm tra mã sách có tồn tại chưa
int tonTaiMaSach(char maSachNhap[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], maSachNhap) == 0) {
            return 1;
        }
    }
    return 0;
}

// Kiểm tra mã độc giả và mã sách của phiếu trả có trùng phiếu mượn chưa
int tonTaiMaDGVaMaSach(char maDocGia[], char maISBN[]) {
    int coMaDocGia = 0; // đánh dấu nếu tìm thấy mã độc giả

    for (int i = 0; i < soPhieuMuon; i++) {
        if (strcmp(maDocGiaPhieuMuon[i], maDocGia) == 0) {
            coMaDocGia = 1;
            if (strcmp(isbnPhieuMuon[i], maISBN) == 0) {
                return 1; // đúng cả mã độc giả và ISBN
            }
        }
    }
    if (coMaDocGia) return -1; // tìm thấy mã độc giả nhưng sai ISBN
    return 0; // không tìm thấy mã độc giả
}