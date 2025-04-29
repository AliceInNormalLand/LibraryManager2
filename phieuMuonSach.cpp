#include <stdio.h>
#include <string.h>
#include "phieuMuonSach.h"

#define MAX_SACH 100
#define MAX_PHIEUMUON 100
#define MAX_STRING 50

// Các mảng 1 chiều cần có:
int maPhieuMuon[MAX_PHIEUMUON];
char maDocGiaPhieuMuon[MAX_PHIEUMUON][50];
char isbnPhieuMuon[MAX_PHIEUMUON][50];
char ngayMuon[MAX_PHIEUMUON][50];
char ngayTraDuKien[MAX_PHIEUMUON][50];

int soPhieuMuon = 0; //Số phiếu mượn ban đầu

// Hàm nhập phiếu mượn sách
// Có thể nhập nhiều phiếu mượn cùng lúc
// Nhập vào số lượng phiếu mượn muốn tạo, nhập thông tin cho từng phiếu mượn, cập nhật số phiếu mượn
void nhapMuonSach() {
    int soPhieuMoi;

    // Nhập số phiếu muốn thêm
    while (1) {
        printf("\nNhap so luong phieu muon them: ");
        if (scanf("%d", &soPhieuMoi) == 1 && soPhieuMoi > 0) break;
        printf("Loi! Phai nhap so nguyen duong.\n");
        while (getchar() != '\n'); // Xóa buffer
    }
    while (getchar() != '\n'); // Xóa ký tự thừa

    if (soPhieuMuon + soPhieuMoi > MAX_PHIEUMUON) {
        printf("[X] Khong the them %d phieu. Chi duoc them toi da %d phieu nua.\n", soPhieuMoi, MAX_PHIEUMUON - soPhieuMuon);
        return;
    }

    for (int i = soPhieuMuon; i < soPhieuMuon + soPhieuMoi; i++) {

        printf("\nNhap thong tin phieu muon thu %d:\n", i + 1);
        // Tao ma phieu muon

        // Nhập mã độc giả
        while (1) {
            printf("Ma doc gia: ");
            fgets(maDocGiaPhieuMuon[i], sizeof(maDocGiaPhieuMuon[i]), stdin);
            maDocGiaPhieuMuon[i][strcspn(maDocGiaPhieuMuon[i], "\n")] = '\0';
            if (tonTaiMaDocGia(maDocGiaPhieuMuon[i])) {
                break;
            } else {
                printf("[X] Ma doc gia khong ton tai! Nhap lai.\n");
            }
        }

        // Nhập ISBN
        while (1) {
            printf("ISBN: ");
            fgets(isbnPhieuMuon[i], sizeof(isbnPhieuMuon[i]), stdin);
            isbnPhieuMuon[i][strcspn(isbnPhieuMuon[i], "\n")] = '\0';
            if (tonTaiMaSach(isbnPhieuMuon[i])) {
                break;
            } else {
                printf("[X] ISBN khong ton tai! Vui long nhap lai.\n");
            }
        }

        // Nhập ngày mượn
        printf("Ngay muon: ");
        fgets(ngayMuon[i], sizeof(ngayMuon[i]), stdin);
        ngayMuon[i][strcspn(ngayMuon[i], "\n")] = '\0';

        // Tính ngày trả dự kiến
        cong7Ngay(ngayMuon[i], ngayTraDuKien[i]);
        printf("Ngay tra du kien: %s\n", ngayTraDuKien[i]);

        maPhieuMuon[i] += i ;
        capNhatSauMuon(isbnPhieuMuon[i]);
    }
    soPhieuMuon += soPhieuMoi;
}

// Hàm xuất phiếu mượn sách
void xuatMuonSach() {
    printf("\n%-15s | %-15s | %-20s | %-15s | %-15s\n", "Ma phieu muon" , "Ma doc gia", "ISBN", "Ngay muon", "Ngay tra du kien");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuMuon; i++) {
        printf("%-15d | %-15s | %-20s | %-15s | %-15s\n",
            maPhieuMuon[i],maDocGiaPhieuMuon[i], isbnPhieuMuon[i], ngayMuon[i], ngayTraDuKien[i]);
    }
}