//
// Created by VICTUS on 4/18/2025.
//
#include <string.h>
#include <stdio.h>

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