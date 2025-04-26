#include <stdio.h>
#include <string.h>
#include "phieuMuonSach.h"
//#define MAX_DOCGIA 100
#define MAX_SACH 100
#define MAX_PHIEUMUON 100
#define MAX_STRING 50

// Danh sách mẫu
//char dsDocGia[MAX_DOCGIA][MAX_STRING] = {"DG01", "DG02", "DG03"};
//int soDocGia = 3;

//char dsSach[MAX_SACH][MAX_STRING] = {"SACH01", "SACH02", "SACH03"};
//int soSach = 3;

// Danh sách phiếu mượn
char dsPhieuMuon[100][4][50];
int soPhieuMuon = 0;

int tonTaiMaDocGia2(char maDocGiaNhap[]) {
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(maDocGia[i], maDocGiaNhap) == 0) return 1;
    }
    return 0;
}


int tonTaiMaSach2(char maSachNhap[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], maSachNhap) == 0) return 1;
    }
    return 0;
}



//moi
// Các mảng 1 chiều cần có:
char maDocGiaPhieuMuon[MAX_PHIEUMUON][50];
char isbnPhieuMuon[MAX_PHIEUMUON][50];
char ngayMuon[MAX_PHIEUMUON][50];
char ngayTraDuKien[MAX_PHIEUMUON][50];
//int soPhieuMuon = 0;

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

        // Nhập mã độc giả
        while (1) {
            printf("Ma doc gia: ");
            fgets(maDocGiaPhieuMuon[i], sizeof(maDocGiaPhieuMuon[i]), stdin);
            maDocGiaPhieuMuon[i][strcspn(maDocGiaPhieuMuon[i], "\n")] = '\0';
            if (tonTaiMaDocGia2(maDocGiaPhieuMuon[i])) {
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
            if (tonTaiMaSach2(isbnPhieuMuon[i])) {
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
    }

    soPhieuMuon += soPhieuMoi;
}


void xuatMuonSach() {
    printf("\n%-15s | %-20s | %-15s | %-15s\n", "Ma doc gia", "ISBN", "Ngay muon", "Ngay tra du kien");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuMuon; i++) {
        printf("%-15s | %-20s | %-15s | %-15s\n",
            maDocGiaPhieuMuon[i], isbnPhieuMuon[i], ngayMuon[i], ngayTraDuKien[i]);
    }
}


// Hàm kiểm tra mã độc giả có tồn tại
/*int tonTaiMaDocGia2(char maDocGia[]) {
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(dsDocGia[i][0], maDocGia) == 0) return 1;
    }
    return 0;
}

// Hàm kiểm tra mã sách có tồn tại
int tonTaiMaSach2(char maSach[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(dsSach[i][0], maSach) == 0) return 1;
    }
    return 0;
}
*/

// Hàm nhập phiếu mượn sách
/*void nhapMuonSach() {
    int soPhieuMoi;

    // Nhập số phiếu muốn thêm
    while (1) {
        printf("\nNhap so luong phieu muon them: ");
        if (scanf("%d", &soPhieuMoi) == 1 && soPhieuMoi > 0) break;
        printf("Loi! Phai nhap so nguyen duong.\n");
        while (getchar() != '\n'); // Xóa buffer
    }
    while (getchar() != '\n');  // Xóa ký tự thừa

    if (soPhieuMuon + soPhieuMoi > MAX_PHIEUMUON) {
        printf("[X] Khong the them %d phieu. Toi da chi co the chua %d phieu.\n", soPhieuMoi, MAX_PHIEUMUON - soPhieuMuon);
        return;
    }

    for (int i = soPhieuMuon; i < soPhieuMuon + soPhieuMoi; i++) {
        printf("Nhap thong tin phieu muon thu %d:\n", i + 1);
        // Mã độc giả
        while (1) {
            printf("Ma doc gia: ");
            fgets(dsPhieuMuon[i][0], MAX_STRING, stdin);
            dsPhieuMuon[i][0][strcspn(dsPhieuMuon[i][0], "\n")] = '\0';
            if (tonTaiMaDocGia2(dsPhieuMuon[i][0])) {
                break; // Tồn tại thì thoát vòng lặp
            }
            else {
                printf("[X] Ma doc gia khong ton tai! Nhap lai.\n");
            }
        }

        // Nhập mã sách
        while (1) {
            printf("ISBN: ");
            fgets(dsPhieuMuon[i][1], MAX_STRING, stdin);
            dsPhieuMuon[i][1][strcspn(dsPhieuMuon[i][1], "\n")] = 0;
            if (tonTaiMaSach2(dsPhieuMuon[i][1])) {
                break;
            }
            else {
                printf("[X] Ma sach khong ton tai! Vui long nhap lai.\n");
            }
        }

        // Nhập ngày mượn
        printf("Ngay muon: ");
        fgets(dsPhieuMuon[i][2], MAX_STRING, stdin);
        dsPhieuMuon[i][2][strcspn(dsPhieuMuon[i][2], "\n")] = 0;

        // Tính ngày trả dự kiến
        cong7Ngay(dsPhieuMuon[i][2], dsPhieuMuon[i][3]);

        // Nhập ngày trả dự kiến
        printf("Ngay tra du kien: %s\n", dsPhieuMuon[i][3]);
    }
    soPhieuMuon += soPhieuMoi;
}

// Hàm xuất danh sách phiếu mượn
void xuatMuonSach() {
    printf("\n%-15s | %-20s | %-15s | %-15s\n", "Ma doc gia", "ISBN", "Ngay muon", "Ngay tra du kien");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuMuon; i++) {
        printf("%-15s | %-20s | %-15s | %-15s\n",
            dsPhieuMuon[i][0], dsPhieuMuon[i][1], dsPhieuMuon[i][2], dsPhieuMuon[i][3]);
    }
}
*/

