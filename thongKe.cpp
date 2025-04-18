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
            thongKeDocGia(dsDocGia, soDocGia);
            break;
            case 'd': printf("|  Ban dang: Thong ke so luong doc gia theo gioi tinh  |");
            thongKeGioiTinh();
            break;
            case 'e': printf("|  Ban dang: Thong ke so sach dang duoc muon  |");
            thongKeSachMuon();
            break;
            case 'f': printf("|  Ban dang: Thong ke danh sach doc gia bị tre han  |");
            thongKeTreHan();
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
    int count = 0;
    for (int i = 0; i < soSach; i++) {
        count++;
    }
    return soSach;
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

int thongKeDocGia(char dsDocGia[][9][50], int soDocGia) {
    int count = 0;
    for (int i = 0; i < soDocGia; i++) {
        count++;
    }
    return count;
}

int thongKeGioiTinh() {

}

int thongKeSachMuon() {

}

int thongKeTreHan() {

}