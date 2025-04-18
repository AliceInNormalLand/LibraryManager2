//
// Created by VICTUS on 4/13/2025.
//
#include <stdio.h>
#include <string.h>
#include "phieuTraSach.h"
//#define MAX_DOCGIA 100
#define MAX_SACH 100
#define MAX_PHIEUTRA 100
#define MAX_STRING 50

// Danh sách phiếu mượn
char dsPhieuTra[100][4][50];
int soPhieuTra = 0;

// Hàm kiểm tra mã độc giả có tồn tại
int tonTaiMaDocGia3(char maDocGia[], char maISBN[]) {
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(dsPhieuMuon[i][0], maDocGia) == 0) {
            if (strcmp(dsPhieuMuon[i][1], maISBN) == 0)
                {
                return 1;
            }
            else {
                return -1;
            }
        }
    }
    return 0;
}

void nhapTraSach() {
    int soPhieuMoi;

    while (1) {
        printf("\nNhap so luong phieu muon them: ");
        if (scanf("%d", &soPhieuMoi) == 1 && soPhieuMoi > 0) break;
        printf("Loi! Phai nhap so nguyen duong.\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    if (soPhieuTra + soPhieuMoi > MAX_PHIEUTRA) {
        printf("[X] Khong the them %d phieu. Toi da chi co the chua %d phieu.\n", soPhieuMoi, MAX_PHIEUTRA - soPhieuTra);
        return;
    }

    for (int i = soPhieuTra; i < soPhieuTra + soPhieuMoi; i++) {
        printf("Nhap thong tin phieu muon thu %d:\n", i + 1);

        // Mã độc giả
        while (1) {
            printf("Ma doc gia: ");
            fgets(dsPhieuTra[i][0], MAX_STRING, stdin);
            dsPhieuTra[i][0][strcspn(dsPhieuTra[i][0], "\n")] = '\0';

            printf("ISBN: ");
            fgets(dsPhieuTra[i][1], MAX_STRING, stdin);
            dsPhieuTra[i][1][strcspn(dsPhieuTra[i][1], "\n")] = '\0';

            if (tonTaiMaDocGia3(dsPhieuTra[i][0], dsPhieuTra[i][1]) == 1) break;
            else if (tonTaiMaDocGia3(dsPhieuTra[i][0], dsPhieuTra[i][1]) == -1)
                printf("Co ma doc gia nhung ko muon sach, nhap lai\n");
            else
                printf("[X] Ma doc gia khong ton tai! Nhap lai.\n");
        }

        // Ngày mượn
        printf("Ngay muon (dd/mm/yyyy): ");
        fgets(dsPhieuTra[i][2], MAX_STRING, stdin);
        dsPhieuTra[i][2][strcspn(dsPhieuTra[i][2], "\n")] = '\0';

        // Tính ngày trả dự kiến
        cong7Ngay(dsPhieuTra[i][2], dsPhieuTra[i][3]);

        printf("=> Ngay tra du kien: %s\n", dsPhieuTra[i][3]);

        // Ngày trả thực tế
        printf("Ngay tra thuc te (dd/mm/yyyy): ");
        fgets(dsPhieuTra[i][4], MAX_STRING, stdin);
        dsPhieuTra[i][4][strcspn(dsPhieuTra[i][4], "\n")] = '\0';

        // Tình trạng
        printf("Tinh trang (qua han/da tra/mat/dang muon): ");
        fgets(dsPhieuTra[i][5], MAX_STRING, stdin);
        dsPhieuTra[i][5][strcspn(dsPhieuTra[i][5], "\n")] = '\0';

        // Tiền phạt
        int tienPhat = 0;
        if (strcmp(dsPhieuTra[i][5], "mat") == 0) {
            tienPhat = 200; // Nếu mất sách thì phạt 200% giá sách (em ghi 200)
        }
        else if (strcmp(dsPhieuTra[i][5], "qua han") == 0) {
            tienPhat = tinhTienPhat(dsPhieuTra[i][2], dsPhieuTra[i][4]);
        }
        printf("Tien phat: %d\n", tienPhat);
    }

    soPhieuTra += soPhieuMoi;
}

void xuatTraSach() {
    printf("\n%-15s | %-20s | %-15s | %-15s | %-15s | %-12s | %-10s\n",
           "Ma doc gia", "ISBN", "Ngay muon", "Ngay tra du kien",
           "Ngay tra thuc te", "Tinh trang", "Tien phat");
    printf("------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuTra; i++) {
        int tienPhat = 0;
        if (strcmp(dsPhieuTra[i][5], "mat") == 0) {
            tienPhat = 200;
        } else if (strcmp(dsPhieuTra[i][5], "qua han") == 0) {
            tienPhat = tinhTienPhat(dsPhieuTra[i][2], dsPhieuTra[i][4]);
        }

        printf("%-15s | %-20s | %-15s | %-15s | %-15s | %-12s | %-10d\n",
               dsPhieuTra[i][0], dsPhieuTra[i][1], dsPhieuTra[i][2], dsPhieuTra[i][3],
               dsPhieuTra[i][4], dsPhieuTra[i][5], tienPhat);
    }
}

