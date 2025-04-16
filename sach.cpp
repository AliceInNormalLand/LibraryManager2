//
// Created by VICTUS on 4/8/2025.
//
#define MAX_SACH 1000
#define THUOC_TINH_SACH 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sach.h"

void menuSach() {
    printf("\n================***================\n"); printf("\n");
    printf("QUAN LY DOC SACH"); printf("\n");
    printf("a.Xem danh sach sach\n");
    printf("b.Them sach\n");
    printf("c.Chinh sua thong tin sach\n");
    printf("d.Xoa sach\n");
    printf("e.Tim kiem sach theo ISBN\n");
    printf("f.Tim kiem sach theo ho ten\n");
    printf("g.TRO LAI THU VIEN\n"); printf("\n");
    printf("================***================\n"); printf("\n");
    printf("\nChon mot chuc nang: ");
}

char quanLySach() {
    static char danhSach[100][8][50];
    static int soLuong = 0;
    char s[50];
    char chon;
    while (true) {
        menuSach();
        scanf(" %c", &chon);
        switch (chon) {
            case 'a':
                if (soLuong < 1) {
                    printf("Danh sach trong!\n");
                    continue;
                }
                printf("DANH SACH SACH:\n");
            xuatSach(danhSach, soLuong);
            break;
            case 'b':
                printf("THEM SACH MOI:\n");
            nhapSach(danhSach, &soLuong);
            break;
            case 'c':
                printf("CHINH SUA THONG TIN SACH:\n");
            printf("Nhap ISBN can sua: ");
            scanf("%s", s);
            while (getchar() != '\n');
            chinhSuaSach(danhSach, soLuong, s);
            break;
            case 'd':
                printf("XOA SACH:\n");
            printf("Nhap ISBN can xoa: ");
            scanf("%s", s);
            while (getchar() != '\n');
            xoaSach(danhSach, &soLuong, s);
            break;
            case 'e':
                printf("TIM KIEM THEO ISBN:\n");
            printf("Nhap ISBN: ");
            scanf("%s", s);
            while (getchar() != '\n');
            timSachTheoISBN(danhSach, soLuong, s);
            break;
            case 'f':
                printf("TIM KIEM THEO TEN SACH:\n");
            printf("Nhap ten sach: ");
            while (getchar() != '\n');
            fgets(s, 50, stdin);
            s[strcspn(s, "\n")] = 0;
            timSachTheoTen(danhSach, soLuong, s);
            break;
            default:
                printf("Lua chon khong hop le\n");
            break;
        }
    }
    return chon;
}

const char* thuocTinhSach(int n) {
    const char* tt[] = {
        "ISBN", "Ten sach", "Tac gia", "Nha xuat ban",
        "Nam xuat ban", "The loai", "Gia sach", "So luong"
    };
    return (n >= 0 && n < 8) ? tt[n] : "";
}

bool tonTaiMaSach(char ds[][8][50], int soSach, const char* maCanKiem) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ds[i][0], maCanKiem) == 0) {
            return true;
        }
    }
    return false;
}

void nhapSach(char ds[][8][50], int* soSach) {
    int soMoi;

    while (1) {
        printf("Nhap so luong sach muon them: ");
        if (scanf("%d", &soMoi) == 1) break;
        printf("Loi! Phai nhap so.\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    if (*soSach + soMoi > MAX_SACH) {
        printf("[X] Khong the them %d sach. Danh sach chi co the chua toi da %d sach.\n", soMoi, MAX_SACH);
        return;
    }

    for (int i = *soSach; i < *soSach + soMoi; ) {
        char maSachTam[50];

        // Nhập mã sách
        printf("Nhap thong tin cho sach thu %d:\n", i + 1);
        while (1) {
            printf("%s: ", thuocTinhSach(0));
            fgets(maSachTam, 50, stdin);
            maSachTam[strcspn(maSachTam, "\n")] = 0;

            if (tonTaiMaSach(ds, *soSach, maSachTam)) {
                printf("[X] Ma sach da ton tai. Vui long nhap ma khac.\n");
            } else {
                strcpy(ds[i][0], maSachTam);
                break;
            }
        }

        // Nhập các thuộc tính còn lại
        for (int j = 1; j < 8; j++) {
            printf("%s: ", thuocTinhSach(j));
            fgets(ds[i][j], 50, stdin);
            ds[i][j][strcspn(ds[i][j], "\n")] = 0;
        }

        i++; // Tăng chỉ số sách sau khi nhập thành công
    }

    *soSach += soMoi;
}


void xuatSach(char ds[][8][50], int soSach) {
    printf("\n%-15s | %-20s | %-15s | %-15s | %-10s | %-10s | %-10s | %-8s\n",
        "ISBN", "Ten sach", "Tac gia", "Nha XB", "Nam XB", "The loai", "Gia", "So luong");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soSach; i++) {
        printf("%-15s | %-20s | %-15s | %-15s | %-10s | %-10s | %-10s | %-8s\n",
            ds[i][0], ds[i][1], ds[i][2], ds[i][3],
            ds[i][4], ds[i][5], ds[i][6], ds[i][7]);
    }
}

void chinhSuaSach(char ds[][8][50], int soSach, char isbn[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ds[i][0], isbn) == 0) {
            printf("Nhap thong tin moi cho sach (ISBN: %s):\n", isbn);
            for (int j = 0; j < 8; j++) {
                printf("%s (Cu: %s): ", thuocTinhSach(j), ds[i][j]);
                fgets(ds[i][j], 50, stdin);
                ds[i][j][strcspn(ds[i][j], "\n")] = 0;
            }
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach co ISBN: %s\n", isbn);
}

void xoaSach(char ds[][8][50], int* soSach, char isbn[]) {
    for (int i = 0; i < *soSach; i++) {
        if (strcmp(ds[i][0], isbn) == 0) {
            for (int j = i; j < *soSach - 1; j++) {
                for (int k = 0; k < 8; k++) {
                    strcpy(ds[j][k], ds[j + 1][k]);
                }
            }
            (*soSach)--;
            printf("Da xoa sach co ISBN: %s\n", isbn);
            return;
        }
    }
    printf("Khong tim thay sach co ISBN: %s\n", isbn);
}

void timSachTheoISBN(char ds[][8][50], int soSach, char isbn[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ds[i][0], isbn) == 0) {
            printf("Thong tin sach co ISBN %s:\n", isbn);
            for (int j = 0; j < 8; j++) {
                printf("%s: %s\n", thuocTinhSach(j), ds[i][j]);
            }
            return;
        }
    }
    printf("Khong tim thay sach voi ISBN: %s\n", isbn);
}

void timSachTheoTen(char ds[][8][50], int soSach, char ten[]) {
    int timThay = 0;
    for (int i = 0; i < soSach; i++) {
        if (strstr(ds[i][1], ten)) {
            timThay = 1;
            printf("\nSach co ten giong '%s':\n", ten);
            for (int j = 0; j < 8; j++) {
                printf("%s: %s\n", thuocTinhSach(j), ds[i][j]);
            }
        }
    }
    if (!timThay) {
        printf("Khong tim thay sach co ten giong '%s'\n", ten);
    }
}

