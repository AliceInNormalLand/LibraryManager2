#include <stdio.h>
#include <string.h>
#include "phieuTraSach.h"

#define MAX_PHIEUTRA 100
#define MAX_STRING 50

int maPhieuTra[MAX_PHIEUTRA];
char maDocGiaPhieuTra[MAX_PHIEUTRA][MAX_STRING];
char isbnPhieuTra[MAX_PHIEUTRA][MAX_STRING];
char ngayMuonPhieuTra[MAX_PHIEUTRA][MAX_STRING];
char ngayTraDuKienPhieuTra[MAX_PHIEUTRA][MAX_STRING];
char ngayTraThucTePhieuTra[MAX_PHIEUTRA][MAX_STRING];
char tinhTrangPhieuTra[MAX_PHIEUTRA][MAX_STRING];
int tienPhatPhieuTra[MAX_PHIEUTRA];

int soPhieuTra = 0;

// Hàm nhập phiếu trả sách
// Có thể nhập nhiều phiếu trả cùng lúc
// Nhập vào số lượng phiếu trả muốn tạo, nhập thông tin cho từng phiếu trả, cập nhật số phiếu trả
void nhapTraSach() {
    int soPhieuMoi;
    // Nhập số lượng phiếu muốn thêm
    while (1) {
        printf("\nNhap so luong phieu tra muon them: ");
        if (scanf("%d", &soPhieuMoi) == 1 && soPhieuMoi > 0) break;
        printf("Loi! Phai nhap so nguyen duong.\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    if (soPhieuTra + soPhieuMoi > MAX_PHIEUTRA) {
        printf("[X] Khong the them %d phieu. Toi da chi con cho %d phieu.\n", soPhieuMoi, MAX_PHIEUTRA - soPhieuTra);
        return;
    }

    for (int i = soPhieuTra; i < soPhieuTra + soPhieuMoi; i++) {
        printf("\nNhap thong tin phieu tra thu %d:\n", i + 1);


        // Mã độc giả + ISBN
        while (1) {
            printf("Ma phieu muon: ");
            // fgets(maPhieuTra[i], MAX_STRING, stdin);

            int daTonTaiTrongMang = 0;

            scanf_s("%d", &maPhieuTra[i]);
            for (int j = 0; j < soPhieuTra; j++) {
                for (int k = 0; k < soPhieuTra; k++) {
                    if (maPhieuTra[i] == maPhieuTra[j]) {
                        daTonTaiTrongMang = 1;
                        break;
                    }
                }
            }
            if (daTonTaiTrongMang) {
                printf("[X] Phieu muon nay da tra roi! Nhap lai!\n");
            }else {
                int daTonTai = 0;
                for (int j = 0; j < soPhieuMuon; j++) {
                    if (maPhieuTra[i] == maPhieuMuon[j]) {
                        strcpy(maDocGiaPhieuTra[i], maDocGiaPhieuMuon[j]);
                        strcpy(isbnPhieuTra[i], isbnPhieuMuon[j]);
                        strcpy(ngayMuonPhieuTra[i], ngayMuon[j]);
                        daTonTai = 1;
                        break;
                    }
                }
                if (daTonTai) {
                    break;
                }
                printf("[X] Khong co ma phieu muon! Nhap lai!\n");
            }
        }
        while (getchar() != '\n');
        // Tính ngày trả dự kiến
        cong7Ngay(ngayMuonPhieuTra[i], ngayTraDuKienPhieuTra[i]);
        printf("=> Ngay tra du kien: %s\n", ngayTraDuKienPhieuTra[i]);

        // Ngày trả thực tế
        printf("Ngay tra thuc te (dd/mm/yyyy): ");
        fgets(ngayTraThucTePhieuTra[i], MAX_STRING, stdin);
        ngayTraThucTePhieuTra[i][strcspn(ngayTraThucTePhieuTra[i], "\n")] = '\0';

        // Tình trạng
        printf("Tinh trang (qua han / da tra / mat): ");
        fgets(tinhTrangPhieuTra[i], MAX_STRING, stdin);
        tinhTrangPhieuTra[i][strcspn(tinhTrangPhieuTra[i], "\n")] = '\0';

        // Tiền phạt
        tienPhatPhieuTra[i] = 0;
        if (strcmp(tinhTrangPhieuTra[i], "mat") == 0) {
            tienPhatPhieuTra[i] = tinhTienPhatMatSach(isbnPhieuTra[i]) ; // Mất sách, phạt 200%
        }
        else if (strcmp(tinhTrangPhieuTra[i], "qua han") == 0) {
            tienPhatPhieuTra[i] = tinhTienPhat(ngayMuonPhieuTra[i], ngayTraThucTePhieuTra[i]);
        }

        printf("Tien phat: %d\n", tienPhatPhieuTra[i]);

        capNhatSauTra(isbnPhieuTra[i]);
    }
    soPhieuTra += soPhieuMoi;
}

// Hàm xuất phiếu trả sách
void xuatTraSach() {
    if (soPhieuTra == 0) {
        printf("\n[!] Chua co phieu tra nao!\n");
        return;
    }

    printf("\n%-15s %-15s %-15s %-15s %-20s %-20s %-20s %-10s\n",
           "Ma phieu muon", "Ma Doc Gia", "ISBN", "Ngay Muon", "Ngay Tra Du Kien",
           "Ngay Tra Thuc Te", "Tinh Trang", "Tien Phat");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuTra; i++) {
        printf("%-15d %-15s %-15s %-15s %-20s %-20s %-20s %-10d\n",
               maPhieuTra[i],
               maDocGiaPhieuTra[i],
               isbnPhieuTra[i],
               ngayMuonPhieuTra[i],
               ngayTraDuKienPhieuTra[i],
               ngayTraThucTePhieuTra[i],
               tinhTrangPhieuTra[i],
               tienPhatPhieuTra[i]);
    }
}

