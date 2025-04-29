#include <stdio.h>
#include <string.h>
#include "phieuTraSach.h"

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

// Hàm nhập phiếu trả sách
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

            int check = tonTaiMaDGVaMaSach(maDocGiaPhieuTra[i], isbnPhieuTra[i]);
            if (check == 1) break;
            else if (check == -1)
                printf("[X] Co ma doc gia nhung khong muon sach nay! Nhap lai!\n");
            else
                printf("[X] Ma doc gia khong ton tai trong phieu muon! Nhap lai!\n");
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

    printf("\n%-5s %-15s %-15s %-15s %-20s %-20s %-20s %-10s\n",
           "STT", "Ma Doc Gia", "ISBN", "Ngay Muon", "Ngay Tra Du Kien",
           "Ngay Tra Thuc Te", "Tinh Trang", "Tien Phat");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuTra; i++) {
        printf("%-5d %-15s %-15s %-15s %-20s %-20s %-20s %-10d\n",
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

