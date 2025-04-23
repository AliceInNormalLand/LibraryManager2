//
// Created by VICTUS on 4/17/2025.
//
#include "thongKe.h"

void menuThongKe() {
    printf("\n================***================"); printf("\n");
    printf("BAN DANG THUC HIEN THONG KE CO BAN"); printf("\n");
    printf("\na.Thong ke so luong sach trong thu vien");
    printf("\nb.Thong ke so luong sach theo the loai");
    printf("\nc.Thong ke so luong doc gia");
    printf("\nd.Thong ke so luong doc gia theo gioi tinh");
    printf("\ne.Thong ke so sach dang duoc muon");
    printf("\nf.Thong ke danh sach doc gia bi tre han");
    printf("\ng.TRO LAI THU VIEN"); printf("\n");
    printf("\n================***================"); printf("\n");
    printf("\nChon mot chuc nang: ");
}

void thongKeCoBan() {
    char s[50]; // Sửa kiểu dữ liệu của s để lưu chuỗi
    char chon;
    while (true) {
        menuThongKe();
        scanf
        (" %c", &chon);
        switch (chon)
        {
            case 'a':
            printf("|  Ban dang: Thong ke so luong sach trong thu vien  |");
            thongKeSachTV(dsSach, soSach);
            break;
            case 'b': printf("|  Ban dang: Thong ke so luong sach theo the loai  |");
            thongKeLoaiSach(dsSach, soSach);
            break;
            case 'c': printf("|  Ban dang: Thong ke so luong doc gia  |");
            thongKeDocGia(dsPhieuMuon, soPhieuMuon, soDocGia);
            break;
            case 'd': printf("|  Ban dang: Thong ke so luong doc gia theo gioi tinh  |");
            thongKeGioiTinh(dsDocGia, soDocGia);
            break;
            case 'e': printf("|  Ban dang: Thong ke so sach dang duoc muon  |");
            thongKeSachMuon(soPhieuMuon, soPhieuTra);
            break;
            case 'f': printf("|  Ban dang: Thong ke danh sach doc gia bị tre han  |");
            thongKeTreHan(dsPhieuTra, soPhieuTra);
            break;
            case 'g': printf("|  TRO LAI MENU  |\n");
            return;
            default:
                printf("Lua chon khong hop le\n");
            break;
        }
    }
}

int thongKeSachTV(char dsSach[][8][50], int soSach) {
    int tong = 0;
    for (int i = 0; i < soSach; i++) {
        tong += dsSach[i][7];
    }
    printf("Tong so sach trong thu vien la: %d", tong);
}

void thongKeLoaiSach(char dsSach[][8][50], int soSach) {
    for (int i = 0; i < soSach; i++) {
        int daTonTai = 0;

        // Kiểm tra loại sách này đã xuất hiện trước đó chưa
        for (int j = 0; j < i; j++) {
            if (strcmp(dsSach[i][5], dsSach[j][5]) == 0) {
                daTonTai = 1;
                break;
            }
        }

        if (!daTonTai) {
            int dem = 0;
            // Đếm số quyển thuộc loại sách này
            for (int k = 0; k < soSach; k++) {
                if (strcmp(dsSach[i][5], dsSach[k][5]) == 0) {
                    dem++;
                }
            }

            printf("Loai sach: %s - So luong: %d\n", dsSach[i][5], dem);
        }
    }
}

int thongKeDocGia(char dsPhieuMuon[][4][50], int soPhieuMuon, int soDocGia) {
    printf("Tong so doc gia: %d", soDocGia);
    for (int i = 0; i < soPhieuMuon; i++) {
        int daTonTai = 0;
        // Kiểm tra loại sách này đã xuất hiện trước đó chưa
        for (int j = 0; j < i; j++) {
            if (strcmp(dsPhieuMuon[i][0], dsPhieuMuon[j][0]) == 0) {
                daTonTai = 1;
                break;
            }
        }

        if (!daTonTai) {
            int dem = 0;
            // Đếm số quyển thuộc loại sách này
            for (int k = 0; k < soPhieuMuon; k++) {
                if (strcmp(dsPhieuMuon[i][0], dsPhieuMuon[k][0]) == 0) {
                    dem++;
                }
            }

            printf("Doc gia co ma: %s - So luong da muon: %d\n", dsPhieuMuon[i][0], dem);
        }
    }
}

int thongKeGioiTinh(char dsDocGia[][9][50], int soDocGia) {
    for (int i = 0; i < soDocGia; i++) {
        int daTonTai = 0;

        // Kiểm tra loại sách này đã xuất hiện trước đó chưa
        for (int j = 0; j < i; j++) {
            if (strcmp(dsDocGia[i][6], dsDocGia[j][6]) == 0) {
                daTonTai = 1;
                break;
            }
        }

        if (!daTonTai) {
            int dem = 0;
            // Đếm số quyển thuộc loại sách này
            for (int k = 0; k < soDocGia; k++) {
                if (strcmp(dsDocGia[i][6], dsDocGia[k][6]) == 0) {
                    dem++;
                }
            }

            printf("Gioi tinh: %s - So luong: %d\n", dsDocGia[i][6], dem);
        }
    }
}

int thongKeSachMuon(int soPhieuMuon, int soPhieuTra) {
    printf("So sach dang duoc muon la: %d", soPhieuMuon - soPhieuTra);
}

int thongKeTreHan(char dsPhieuTra[][7][50], int soPhieuTra) {
    int count = 0;
    for (int i = 0; i < soPhieuTra; i++) {
        if (dsPhieuTra[i][6] > 0) {
            count++;
        }
    }
    printf("So doc gia bi tre han la: %d", count);
}