#include <stdio.h>
#include <string.h>
#include "phieuTraSach.h"

phieuTra danhSachPTra[MAX_PHIEUTRA];

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

            int daTonTaiTrongMang = 0;

            scanf_s("%d", danhSachPTra[i].maPhieuTra);
            for (int j = 0; j < soPhieuTra; j++) {
                for (int k = 0; k < soPhieuTra; k++) {
                    if (danhSachPTra[i].maPhieuTra == danhSachPTra[j].maPhieuTra) {
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
                    if (danhSachPTra[i].maPhieuTra == danhSachPMuon[j].maPhieuMuon) {
                        strcpy(danhSachPTra[i].maDocGiaPhieuTra, danhSachPMuon[j].maDocGiaPhieuMuon);
                        strcpy(danhSachPTra[i].isbnPhieuTra, danhSachPMuon[j].isbnPhieuMuon);
                        strcpy(danhSachPTra[i].ngayMuonPhieuTra, danhSachPMuon[j].ngayMuon);
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
        cong7Ngay(danhSachPTra[i].ngayMuonPhieuTra, danhSachPTra[i].ngayTraDuKienPhieuTra);
        printf("=> Ngay tra du kien: %s\n", danhSachPTra[i].ngayTraDuKienPhieuTra);

        // Ngày trả thực tế
        printf("Ngay tra thuc te (dd/mm/yyyy): ");
        fgets(danhSachPTra[i].ngayTraThucTePhieuTra, MAX_STRING, stdin);
        danhSachPTra[i].ngayTraThucTePhieuTra[strcspn(danhSachPTra[i].ngayTraThucTePhieuTra, "\n")] = '\0';

        // Tình trạng
        printf("Tinh trang (qua han / da tra / mat): ");
        fgets(danhSachPTra[i].tinhTrangPhieuTra, MAX_STRING, stdin);
        danhSachPTra[i].tinhTrangPhieuTra[strcspn(danhSachPTra[i].tinhTrangPhieuTra, "\n")] = '\0';

        // Tiền phạt
        danhSachPTra[i].tienPhatPhieuTra = 0;
        if (strcmp(danhSachPTra[i].tinhTrangPhieuTra, "mat") == 0) {
            danhSachPTra[i].tienPhatPhieuTra = tinhTienPhatMatSach(danhSachPTra[i].isbnPhieuTra) ; // Mất sách, phạt 200%
        }
        else if (strcmp(danhSachPTra[i].tinhTrangPhieuTra, "qua han") == 0) {
            danhSachPTra[i].tienPhatPhieuTra = tinhTienPhat(danhSachPTra[i].ngayMuonPhieuTra, danhSachPTra[i].ngayTraThucTePhieuTra);
        }

        printf("Tien phat: %d\n", danhSachPTra[i].tienPhatPhieuTra);

        capNhatSauTra(danhSachPTra[i].isbnPhieuTra);
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
               danhSachPTra[i].maPhieuTra,
               danhSachPTra[i].maDocGiaPhieuTra,
               danhSachPTra[i].isbnPhieuTra,
               danhSachPTra[i].ngayMuonPhieuTra,
               danhSachPTra[i].ngayTraDuKienPhieuTra,
               danhSachPTra[i].ngayTraThucTePhieuTra,
               danhSachPTra[i].tinhTrangPhieuTra,
               danhSachPTra[i].tienPhatPhieuTra);
    }
}

