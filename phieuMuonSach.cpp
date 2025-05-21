#include <stdio.h>
#include <string.h>
#include "phieuMuonSach.h"

phieuMuon danhSachPMuon[MAX_PHIEUMUON];

int soPhieuMuon = 0; //Số phiếu mượn ban đầu

void GhiTapTinPhieuMuon(phieuMuon danhSachPMuon[], int soPhieuMuon) {
    FILE* file;
    fopen_s(&file, "D:\\KHTN_NHAPMONLAPTRINH\\DanhSachPhieuMuon.txt", "wt");
    fprintf(file, "%d\n", soPhieuMuon);
    for (int i = 0; i < soPhieuMuon; i++) {
        fprintf(file, "%d\n", danhSachPMuon[i].maPhieuMuon);
        fprintf(file, "%s\n", danhSachPMuon[i].maDocGiaPhieuMuon);
        fprintf(file, "%s\n", danhSachPMuon[i].isbnPhieuMuon);
        fprintf(file, "%s\n", danhSachPMuon[i].ngayMuon);
        fprintf(file, "%s\n", danhSachPMuon[i].ngayTraDuKien);
    }
    fclose(file);
}

void DocMangTuTapTinPhieuMuon(phieuMuon danhSachPMuon[], int& n) {
    FILE* file;
    fopen_s(&file, "D:\\KHTN_NHAPMONLAPTRINH\\DanhSachPhieuMuon.txt", "rt");
    if (file != NULL) {
        fscanf_s(file, "%d", &n);
        fgetc(file);
        for (int i = 0; i < n; i++) {
            fscanf_s(file, "%d", &danhSachPMuon[i].maPhieuMuon);
            fgets(danhSachPMuon[i].maDocGiaPhieuMuon,MAX_STRING,file);
            fgets(danhSachPMuon[i].isbnPhieuMuon,MAX_STRING,file);
            fgets(danhSachPMuon[i].ngayMuon,MAX_STRING,file);
            fgets(danhSachPMuon[i].ngayTraDuKien,MAX_STRING,file);

            // Xoá ký tự '\n' cuối mỗi dòng nếu có
            danhSachPMuon[i].maDocGiaPhieuMuon[strcspn(danhSachPMuon[i].maDocGiaPhieuMuon, "\n")] = '\0';
            danhSachPMuon[i].isbnPhieuMuon[strcspn(danhSachPMuon[i].isbnPhieuMuon, "\n")] = '\0';
            danhSachPMuon[i].ngayMuon[strcspn(danhSachPMuon[i].ngayMuon, "\n")] = '\0';
            danhSachPMuon[i].ngayTraDuKien[strcspn(danhSachPMuon[i].ngayTraDuKien, "\n")] = '\0';
        }
        fclose(file);
    }
    else {
        printf("Khong mo duoc tap tin");
    }
}

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
            fgets(danhSachPMuon[i].maDocGiaPhieuMuon, sizeof(danhSachPMuon[i].maDocGiaPhieuMuon), stdin);
            danhSachPMuon[i].maDocGiaPhieuMuon[strcspn(danhSachPMuon[i].maDocGiaPhieuMuon, "\n")] = '\0';
            if (tonTaiMaDocGia(danhSachPMuon[i].maDocGiaPhieuMuon)) {
                break;
            } else {
                printf("[X] Ma doc gia khong ton tai! Nhap lai.\n");
            }
        }

        // Nhập ISBN
        while (1) {
            printf("ISBN: ");
            fgets(danhSachPMuon[i].isbnPhieuMuon, sizeof(danhSachPMuon[i].isbnPhieuMuon), stdin);
            danhSachPMuon[i].isbnPhieuMuon[strcspn(danhSachPMuon[i].isbnPhieuMuon, "\n")] = '\0';
            if (tonTaiMaSach(danhSachPMuon[i].isbnPhieuMuon)) {
                break;
            } else {
                printf("[X] ISBN khong ton tai! Vui long nhap lai.\n");
            }
        }

        // Nhập ngày mượn
        printf("Ngay muon: ");
        fgets(danhSachPMuon[i].ngayMuon, sizeof(danhSachPMuon[i].ngayMuon), stdin);
        danhSachPMuon[i].ngayMuon[strcspn(danhSachPMuon[i].ngayMuon, "\n")] = '\0';

        // Tính ngày trả dự kiến
        cong7Ngay(danhSachPMuon[i].ngayMuon, danhSachPMuon[i].ngayTraDuKien);
        printf("Ngay tra du kien: %s\n", danhSachPMuon[i].ngayTraDuKien);

        danhSachPMuon[i].maPhieuMuon += i ;
        capNhatSauMuon(danhSachPMuon[i].isbnPhieuMuon);
    }
    soPhieuMuon += soPhieuMoi;
}

// Hàm xuất phiếu mượn sách
void xuatMuonSach() {
    printf("\n%-15s | %-15s | %-20s | %-15s | %-15s\n", "Ma phieu muon" , "Ma doc gia", "ISBN", "Ngay muon", "Ngay tra du kien");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < soPhieuMuon; i++) {
        printf("%-15d | %-15s | %-20s | %-15s | %-15s\n",
            danhSachPMuon[i].maPhieuMuon, danhSachPMuon[i].maDocGiaPhieuMuon, danhSachPMuon[i].isbnPhieuMuon,
            danhSachPMuon[i].ngayMuon, danhSachPMuon[i].ngayTraDuKien);
    }
}