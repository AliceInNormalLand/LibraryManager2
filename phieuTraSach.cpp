//
// Created by VICTUS on 4/13/2025.
//
#include <stdio.h>
#include <string.h>
#include "docGia.h"
#include "phieuMuonSach.h"
//#define MAX_DOCGIA 100
#define MAX_SACH 100
#define MAX_PHIEUTRA 100
#define MAX_STRING 50

// Danh sách mẫu
//char dsDocGia[MAX_DOCGIA][MAX_STRING] = {"DG01", "DG02", "DG03"};
//int soDocGia = 3;

//char dsSach[MAX_SACH][MAX_STRING] = {"SACH01", "SACH02", "SACH03"};
//int soSach = 3;

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

//Hàm kiểm tra mã sách có tồn tại
/*int tonTaiMaSach(char maSach[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(dsSach[i], maSach) == 0) return 1;
    }
    return 0;
}*/

//bool tonTaiMaDocGia(char * a);

// Hàm nhập phiếu mượn sách
void nhapTraSach() {
    int soPhieuMoi;

    // Nhập số phiếu muốn thêm
    while (1) {
        printf("Nhap so luong phieu muon them: ");
        if (scanf("%d", &soPhieuMoi) == 1 && soPhieuMoi > 0) break;
        printf("Loi! Phai nhap so nguyen duong.\n");
        while (getchar() != '\n'); // Xóa buffer
    }
    while (getchar() != '\n');  // Xóa ký tự thừa

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
            dsPhieuTra[i][1][strcspn(dsPhieuTra[i][1], "\n")] = 0;
            //neu ma so khac 0 mac dinh la true con 0 laf false
            if (tonTaiMaDocGia3(dsPhieuTra[i][0], dsPhieuTra[i][1]) == 1){
                break; // Tồn tại thì thoát vòng lặp
            }
            else if (tonTaiMaDocGia3(dsPhieuTra[i][0], dsPhieuTra[i][1]) == -1){
                printf("Co ma doc gia nhung ko muon sach, nhap lai\n");
            }
            else {
                printf("[X] Ma doc gia khong ton tai! Nhap lai.\n");
            }
        }

        // Nhập ngày mượn
        printf("Ngay muon: ");
        fgets(dsPhieuTra[i][2], MAX_STRING, stdin);
        dsPhieuTra[i][2][strcspn(dsPhieuTra[i][2], "\n")] = 0;

        // Nhập ngày trả dự kiến
        printf("Ngay tra du kien: ");
        fgets(dsPhieuTra[i][3], MAX_STRING, stdin);
        dsPhieuTra[i][3][strcspn(dsPhieuTra[i][3], "\n")] = 0;
    }
    soPhieuTra += soPhieuMoi;
}

// Hàm xuất danh sách phiếu mượn
void xuatTraSach() {
    printf("\n%-15s | %-20s | %-15s | %-15s\n", "Ma doc gia", "ISBN", "Ngay muon", "Ngay tra du kien");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuTra; i++) {
        printf("%-15s | %-20s | %-15s | %-15s\n",
            dsPhieuTra[i][0], dsPhieuTra[i][1], dsPhieuTra[i][2], dsPhieuTra[i][3]);
    }
}


