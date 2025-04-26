//
// Created by VICTUS on 4/13/2025.
//
#include <stdio.h>
#include <string.h>
#include "phieuTraSach.h"
//#define MAX_DOCGIA 100
#define MAX_SACH 100
//#define MAX_PHIEUTRA 100
//#define MAX_STRING 50


#define MAX_PHIEUTRA 100
#define MAX_STRING 50

char maDocGiaPhieuTra[MAX_PHIEUTRA][MAX_STRING];
char isbnPhieuTra[MAX_PHIEUTRA][MAX_STRING];
char ngayMuonPhieuTra[MAX_PHIEUTRA][MAX_STRING];
char ngayTraDuKienPhieuTra[MAX_PHIEUTRA][MAX_STRING];
char ngayTraThucTePhieuTra[MAX_PHIEUTRA][MAX_STRING];
char tinhTrangPhieuTra[MAX_PHIEUTRA][MAX_STRING];
int tienPhatPhieuTra[MAX_PHIEUTRA];

int soPhieuTra = 0;

// tonTaiMaDocGia3, cong7Ngay, tinhTienPhat: giả sử đã có
int tonTaiMaDocGia3(char maDocGia[], char maISBN[]) {
    for (int i = 0; i < soPhieuMuon; i++) {
        if (strcmp(maDocGiaPhieuMuon[i], maDocGia) == 0) {  // so sánh mã độc giả
            if (strcmp(isbnPhieuMuon[i], maISBN) == 0) {    // so sánh ISBN
                return 1; // tìm đúng mã độc giả và ISBN
            }
            else {
                return -1; // tìm đúng mã độc giả nhưng ISBN sai
            }
        }
    }
    return 0; // không tìm thấy mã độc giả
}


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
            printf("Ma doc gia: ");
            fgets(maDocGiaPhieuTra[i], MAX_STRING, stdin);
            maDocGiaPhieuTra[i][strcspn(maDocGiaPhieuTra[i], "\n")] = '\0';

            printf("ISBN: ");
            fgets(isbnPhieuTra[i], MAX_STRING, stdin);
            isbnPhieuTra[i][strcspn(isbnPhieuTra[i], "\n")] = '\0';

            int check = tonTaiMaDocGia3(maDocGiaPhieuTra[i], isbnPhieuTra[i]);
            if (check == 1) break;
            else if (check == -1)
                printf("[X] Co ma doc gia nhung khong muon sach nay! Nhap lai!\n");
            else
                printf("[X] Ma doc gia khong ton tai! Nhap lai!\n");
        }

        // Ngày mượn
        printf("Ngay muon (dd/mm/yyyy): ");
        fgets(ngayMuonPhieuTra[i], MAX_STRING, stdin);
        ngayMuonPhieuTra[i][strcspn(ngayMuonPhieuTra[i], "\n")] = '\0';

        // Tính ngày trả dự kiến
        cong7Ngay(ngayMuonPhieuTra[i], ngayTraDuKienPhieuTra[i]);
        printf("=> Ngay tra du kien: %s\n", ngayTraDuKienPhieuTra[i]);

        // Ngày trả thực tế
        printf("Ngay tra thuc te (dd/mm/yyyy): ");
        fgets(ngayTraThucTePhieuTra[i], MAX_STRING, stdin);
        ngayTraThucTePhieuTra[i][strcspn(ngayTraThucTePhieuTra[i], "\n")] = '\0';

        // Tình trạng
        printf("Tinh trang (qua han / da tra / mat / dang muon): ");
        fgets(tinhTrangPhieuTra[i], MAX_STRING, stdin);
        tinhTrangPhieuTra[i][strcspn(tinhTrangPhieuTra[i], "\n")] = '\0';

        // Tiền phạt
        tienPhatPhieuTra[i] = 0;
        if (strcmp(tinhTrangPhieuTra[i], "mat") == 0) {
            tienPhatPhieuTra[i] = 200; // Mất sách, phạt 200%
        }
        else if (strcmp(tinhTrangPhieuTra[i], "qua han") == 0) {
            tienPhatPhieuTra[i] = tinhTienPhat(ngayMuonPhieuTra[i], ngayTraThucTePhieuTra[i]);
        }

        printf("Tien phat: %d\n", tienPhatPhieuTra[i]);
    }

    soPhieuTra += soPhieuMoi;
}


void xuatTraSach() {
    if (soPhieuTra == 0) {
        printf("\n[!] Chua co phieu tra nao!\n");
        return;
    }

    printf("\n%-5s %-15s %-15s %-15s %-15s %-15s %-15s %-10s\n",
           "STT", "Ma Doc Gia", "ISBN", "Ngay Muon", "Ngay Tra Du Kien",
           "Ngay Tra Thuc Te", "Tinh Trang", "Tien Phat");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuTra; i++) {
        printf("%-5d %-15s %-15s %-15s %-15s %-15s %-15s %-10d\n",
               i + 1,
               maDocGiaPhieuTra[i],
               isbnPhieuTra[i],
               ngayMuonPhieuTra[i],
               ngayTraDuKienPhieuTra[i],
               ngayTraThucTePhieuTra[i],
               tinhTrangPhieuTra[i],
               tienPhatPhieuTra[i]);
    }
}



// Danh sách phiếu mượn
/*char dsPhieuTra[100][7][50];
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
*/

