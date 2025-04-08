#include <sec_api/stdio_s.h>
#include <string.h>
#include "Header.h"
#include <stdlib.h>
#include "docGia.h"
//
// Created by VICTUS on 4/8/2025.
//



void menuDocGia() {
    printf("\n================***================"); printf("\n");
    printf("BAN DANG THUC HIEN QUAN LY DOC GIA"); printf("\n");
    printf("\na.Xem danh sach doc gia trong thu vien");
    printf("\nb.Them doc gia");
    printf("\nc.Chinh sua thong tin doc gia");
    printf("\nd.Xoa thong tin doc gia");
    printf("\ne.Tim kiem doc gia theo CMND");
    printf("\nf.Tim kiem doc gia theo ho ten");
    printf("\ng.TRO LAI THU VIEN"); printf("\n");
    printf("\n================***================"); printf("\n");
    printf("\nChon mot chuc nang: ");
}

void quanLyDocGia() {
    static char danhSach[20][9][50]; // Mảng 2 chiều chứa danh sách độc giả
    static int soLuong = 0;
    char s[50]; // Sửa kiểu dữ liệu của s để lưu chuỗi
    char chon;
    while (true) {
        menuDocGia();
        scanf_s("%s", chon);
        switch (chon)
        {
            case 'a': printf("|  Ban dang: Xem danh sach do gia trong thu vien  |");
            xuatDanhSach(danhSach, soLuong);
            break;
            case 'b': printf("|  Ban dang: Them doc gia  |");
            nhapDanhSach(danhSach, &soLuong);
            break;
            case 'c': printf("|  Ban dang: Chinh sua thong tin doc gia  |");
            printf("Nhap ma doc gia can sua: ");
            scanf("%s", s);
            while (getchar() != '\n'); // Clear buffer
            chinhSuaThongTin(danhSach, soLuong, s);
            break;
            case 'd': printf("|  Ban dang: Xoa thong tin doc gia  |");
            printf("Nhap ma doc gia can xoa: ");
            scanf("%s", s);
            xoaDocGia(danhSach, &soLuong, s);
            break;
            case 'e': printf("|  Ban dang: Tim kiem doc gia theo CMND  |");
            printf("Nhap CMND can tim: ");
            scanf("%s", s);
            timKiemTheoCMND(danhSach, soLuong, s);
            break;
            case 'f': printf("|  Ban dang: Tim kiem doc gia theo ho ten  |");
            printf("Nhap ten hoac ho ten can tim: ");
            while (getchar() != '\n'); // clear buffer
            fgets(s, 50, stdin);
            s[strcspn(s, "\n")] = 0;
            timKiemTheoTen(danhSach, soLuong, s);
            break;
            case 'g': printf("|  TRO LAI MENU  |");

            break;
            default: printf("Khong co chuc nang nay! Hay thu chuc nang khac."); getchar(); getchar();
        }
    }
}

void nhapDanhSach(char a[][9][50], int* soDocGia) {
    int soLuongMoi;

    while (1) {
        printf("Nhap so luong doc gia moi: ");
        if (scanf("%d", &soLuongMoi) == 1) break;
        printf("Loi! Phai nhap so.\n");
        while (getchar() != '\n');
        printf("\n");
    }
    while (getchar() != '\n');

    for (int i = *soDocGia; i < *soDocGia + soLuongMoi; i++) {
        printf("\nNhap thong tin cho doc gia thu %d:\n", i + 1);
        for (int j = 0; j < 9; j++) {
            if (j == 7) { // Ngày lập thẻ
                printf("%s (ddmmyyyy): ", cacThuocTinh(j));
                char ngayNhap[9];
                fgets(ngayNhap, 9, stdin);
                while (getchar() != '\n'); // Xoá '\n' dư nếu có

                // Tách thành dd/mm/yyyy
                char day[3], month[3], year[5];
                strncpy(day, ngayNhap, 2); day[2] = '\0';
                strncpy(month, ngayNhap + 2, 2); month[2] = '\0';
                strncpy(year, ngayNhap + 4, 4); year[4] = '\0';

                sprintf(a[i][j], "%s/%s/%s", day, month, year);

                // Tính ngày hết hạn
                int d = atoi(day);
                int m = atoi(month) + 48;
                int y = atoi(year) + (m / 12);
                m = m % 12;
                if (m == 0) { m = 12; y--; }

                sprintf(a[i][8], "%02d/%02d/%04d", d, m, y); // Cột 8 là ngày hết hạn

            }
            else if (j == 8) {
                // Bỏ qua nhập "Ngày hết hạn"
                continue;
            }
            else {
                printf("%s: ", cacThuocTinh(j));
                fgets(a[i][j], 50, stdin);
                a[i][j][strcspn(a[i][j], "\n")] = 0;
            }
        }
    }
    *soDocGia += soLuongMoi;
}

void xuatDanhSach(char a[][9][50], int soDocGia) {
    printf("\n%-12s | %-15s | %-12s | %-10s | %-5s | %-15s | %-10s | %-15s | %-15s |\n",
        "Ma doc gia", "Ho va ten", "CMND", "Ngay sinh", "GT", "Email", "Dia chi", "Ngay lap the", "Ngay het han");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soDocGia; i++) {
        printf("%-12s | %-15s | %-12s | %-10s | %-5s | %-15s | %-10s | %-15s | %-15s |\n",
            a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5], a[i][6], a[i][7], a[i][8]);
    }
}

const char* cacThuocTinh(int n) {
    const char* thuocTinh[] = {
        "Ma doc gia", "Ho va ten", "CMND", "Ngay sinh", "Gioi tinh", "Email", "Dia chi", "Ngay lap the", "Ngay het han"
    };
    return (n >= 0 && n < 9) ? thuocTinh[n] : "";
}

void chinhSuaThongTin(char a[][9][50], int soDocGia, char s[]) {
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(a[i][0], s) == 0) {
            printf("Nhap thong tin moi cho doc gia (Ma doc gia: %s):\n", s);
            for (int j = 0; j < 9; j++) {
                if (j == 8) continue; // Bỏ qua nhập "Ngay Het Han"
                printf("%s (Cu: %s): ", cacThuocTinh(j), a[i][j]);
                fgets(a[i][j], 50, stdin);
                a[i][j][strcspn(a[i][j], "\n")] = 0;
            }

            // Xử lý lại Ngay Het Han từ Ngay Lap The
            char* ngayLap = a[i][7];
            char* ngayHet = a[i][8];

            // Copy ngay lap
            strncpy(ngayHet, ngayLap, 11);

            // Cộng thêm 48 tháng
            int d, m, y;
            sscanf(ngayLap, "%d/%d/%d", &d, &m, &y);
            m += 48;
            y += (m - 1) / 12;
            m = (m - 1) % 12 + 1;

            sprintf(ngayHet, "%02d/%02d/%04d", d, m, y);

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay doc gia voi ma: %s\n", s);
}

void xoaDocGia(char a[][9][50], int* soDocGia, char s[]) {
    for (int i = 0; i < *soDocGia; i++) {
        if (strcmp(a[i][0], s) == 0) {
            for (int j = i; j < *soDocGia - 1; j++) {
                for (int k = 0; k < 9; k++) {
                    strcpy(a[j][k], a[j + 1][k]);
                }
            }
            (*soDocGia)--;
            printf("Da xoa doc gia co ma: %s\n", s);
            return;
        }
    }
    printf("Khong tim thay doc gia voi ma: %s\n", s);
}

void timKiemTheoCMND(char a[][9][50], int soDocGia, char s[]) {
    int timThay = 0;
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(a[i][2], s) == 0) {
            timThay = 1;
            printf("Doc gia co CMND %s:\n", s);
            for (int j = 0; j < 9; j++) {
                printf("%s: %s\n", cacThuocTinh(j), a[i][j]);
            }
        }
    }
    if (!timThay) {
        printf("Khong tim thay doc gia co CMND: %s\n", s);
    }
}

void timKiemTheoTen(char a[][9][50], int soDocGia, char s[]) {
    int timThay = 0;
    for (int i = 0; i < soDocGia; i++) {
        if (strstr(a[i][1], s)) {
            timThay = 1;
            printf("Doc gia co ten giong '%s':\n", s);
            for (int j = 0; j < 9; j++) {
                printf("%s: %s\n", cacThuocTinh(j), a[i][j]);
            }
            printf("\n");
        }
    }
    if (!timThay) {
        printf("Khong tim thay doc gia ten giong '%s'\n", s);
    }
}