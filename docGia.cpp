#include <sec_api/stdio_s.h>
//#include "docGia.h"
//
// Created by VICTUS on 4/8/2025.
//
//////OLDDDDD
/*
char dsDocGia[MAX_DOC_GIA][9][50];  // Cấp phát bộ nhớ thật sự
int soDocGia = 0;
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
    char s[50]; // Sửa kiểu dữ liệu của s để lưu chuỗi
    char chon;
    while (true) {
        menuDocGia();
        scanf
        (" %c", &chon);
        switch (chon)
        {
            case 'a':
                if (soDocGia < 1) {
                printf("Danh sach trong!\n");
                continue;
            }
            printf("|  Ban dang: Xem danh sach do gia trong thu vien  |");
            xuatDanhSach(dsDocGia, soDocGia);
            break;
            case 'b': printf("|  Ban dang: Them doc gia  |");
            nhapDanhSach(dsDocGia, &soDocGia);
            break;
            case 'c': printf("|  Ban dang: Chinh sua thong tin doc gia  |");
            printf("Nhap ma doc gia can sua: ");
            scanf("%s", s);
            while (getchar() != '\n'); // Clear buffer
            chinhSuaThongTin(dsDocGia, soDocGia, s);
            break;
            case 'd': printf("|  Ban dang: Xoa thong tin doc gia  |");
            printf("Nhap ma doc gia can xoa: ");
            scanf("%s", s);
            xoaDocGia(dsDocGia, &soDocGia, s);
            break;
            case 'e': printf("|  Ban dang: Tim kiem doc gia theo CMND  |");
            printf("Nhap CMND can tim: ");
            scanf("%s", s);
            timKiemTheoCMND(dsDocGia, soDocGia, s);
            break;
            case 'f': printf("|  Ban dang: Tim kiem doc gia theo ho ten  |");
            printf("Nhap ten hoac ho ten can tim: ");
            while (getchar() != '\n'); // clear buffer
            fgets(s, 50, stdin);
            s[strcspn(s, "\n")] = 0;
            timKiemTheoTen(dsDocGia, soDocGia, s);
            break;
            case 'g': printf("|  TRO LAI MENU  |\n");
            return;
            //break;
            default:
                printf("Lua chon khong hop le\n");
            break;
        }
    }
}

const char* cacThuocTinh(int index) {
    const char* thuocTinh[9] = {
        "Ma doc gia", "Ho ten", "CMND", "Email", "Dia chi",
        "Ngay sinh", "Gioi tinh", "Ngay lap the", "Ngay het han"
    };
    return thuocTinh[index];
}

int tonTaiMaDocGia(char dsDocGia[][9][50], int soDocGia, const char* ma) {
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(dsDocGia[i][0], ma) == 0) return 1;
    }
    return 0;
}

void nhapDanhSach(char dsDocGia[][9][50], int* soDocGia) {
    int soLuongMoi;

    while (1) {
        printf("\nNhap so luong doc gia moi: ");
        if (scanf("%d", &soLuongMoi) == 1) {
            if (*soDocGia + soLuongMoi > MAX_DOC_GIA) {
                printf("[X] Tong so doc gia vuot qua gioi han (%d). Chi duoc them toi da %d nguoi nua.\n",
                       MAX_DOC_GIA, MAX_DOC_GIA - *soDocGia);
            } else break;
        } else {
            printf("Loi! Phai nhap so.\n");
            while (getchar() != '\n');
        }
    }
    while (getchar() != '\n');

    for (int i = *soDocGia; i < *soDocGia + soLuongMoi; i++) {
        printf("\nNhap thong tin cho doc gia thu %d:\n", i + 1);
        for (int j = 0; j < 9; j++) {
            if (j == 7) { // Ngay lap the
                printf("%s (ddmmyyyy): ", cacThuocTinh(j));
                char ngayNhap[9];
                fgets(ngayNhap, 9, stdin);
                while (getchar() != '\n');

                char day[3], month[3], year[5];
                strncpy(day, ngayNhap, 2); day[2] = '\0';
                strncpy(month, ngayNhap + 2, 2); month[2] = '\0';
                strncpy(year, ngayNhap + 4, 4); year[4] = '\0';

                sprintf(dsDocGia[i][j], "%s/%s/%s", day, month, year);

                int d = atoi(day);
                int m = atoi(month) + 48;
                int y = atoi(year) + (m / 12);
                m = m % 12;
                if (m == 0) { m = 12; y--; }

                sprintf(dsDocGia[i][8], "%02d/%02d/%04d", d, m, y);

            } else if (j == 8) {
                continue;
            } else {
                if (j == 0) { // Ma doc gia
                    while (1) {
                        printf("%s: ", cacThuocTinh(j));
                        fgets(dsDocGia[i][j], 50, stdin);
                        dsDocGia[i][j][strcspn(dsDocGia[i][j], "\n")] = 0;

                        if (tonTaiMaDocGia(dsDocGia, i, dsDocGia[i][j])) {
                            printf("[X] Ma doc gia da ton tai. Nhap lai!\n");
                        } else break;
                    }
                } else {
                    printf("%s: ", cacThuocTinh(j));
                    fgets(dsDocGia[i][j], 50, stdin);
                    dsDocGia[i][j][strcspn(dsDocGia[i][j], "\n")] = 0;
                }
            }
        }
    }
    soDocGia += soLuongMoi;
}

void xuatDanhSach(char dsDocGia[][9][50], int soDocGia) {
    printf("\n==== DANH SACH DOC GIA ====\n");
    printf("\n%-12s | %-15s | %-12s | %-10s | %-5s | %-15s | %-10s | %-15s | %-15s |\n",
        "Ma doc gia", "Ho va ten", "CMND", "Ngay sinh", "GT", "Email", "Dia chi", "Ngay lap the", "Ngay het han");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soDocGia; i++) {
        printf("%-12s | %-15s | %-12s | %-10s | %-5s | %-15s | %-10s | %-15s | %-15s |\n",
            dsDocGia[i][0], dsDocGia[i][1], dsDocGia[i][2], dsDocGia[i][3], dsDocGia[i][4], dsDocGia[i][5], dsDocGia[i][6], dsDocGia[i][7], dsDocGia[i][8]);
    }
}

void chinhSuaThongTin(char dsDocGia[][9][50], int soDocGia, char s[]) {
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(dsDocGia[i][0], s) == 0) {
            printf("Nhap thong tin moi cho doc gia (Ma doc gia: %s):\n", s);
            for (int j = 0; j < 9; j++) {
                if (j == 8) continue; // Bỏ qua nhập "Ngay Het Han"
                printf("%s (Cu: %s): ", cacThuocTinh(j), dsDocGia[i][j]);
                fgets(dsDocGia[i][j], 50, stdin);
                dsDocGia[i][j][strcspn(dsDocGia[i][j], "\n")] = 0;
            }

            // Xử lý lại Ngay Het Han từ Ngay Lap The
            char* ngayLap = dsDocGia[i][7];
            char* ngayHet = dsDocGia[i][8];

            // Copy ngay lap
            strncpy(ngayHet, ngayLap, 11);

            // Cộng thêm 48 tháng
            int d, m, y;
            sscanf(ngayLap, "%d/%d/%d", &d, &m, &y); // FIXED

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

void xoaDocGia(char dsDocGia[][9][50], int* soDocGia, char s[]) {
    for (int i = 0; i < *soDocGia; i++) {
        if (strcmp(dsDocGia[i][0], s) == 0) {
            for (int j = i; j < *soDocGia - 1; j++) {
                for (int k = 0; k < 9; k++) {
                    strcpy(dsDocGia[j][k], dsDocGia[j + 1][k]);
                }
            }
            (*soDocGia)--;
            printf("Da xoa doc gia co ma: %s\n", s);
            return;
        }
    }
    printf("Khong tim thay doc gia voi ma: %s\n", s);
}

void timKiemTheoCMND(char dsDocGia[][9][50], int soDocGia, char s[]) {
    int timThay = 0;
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(dsDocGia[i][2], s) == 0) {
            timThay = 1;
            printf("Doc gia co CMND %s:\n", s);
            for (int j = 0; j < 9; j++) {
                printf("%s: %s\n", cacThuocTinh(j), dsDocGia[i][j]);
            }
        }
    }
    if (!timThay) {
        printf("Khong tim thay doc gia co CMND: %s\n", s);
    }
}

void timKiemTheoTen(char dsDocGia[][9][50], int soDocGia, char s[]) {
    int timThay = 0;
    for (int i = 0; i < soDocGia; i++) {
        if (strstr(dsDocGia[i][1], s)) {
            timThay = 1;
            printf("Doc gia co ten giong '%s':\n", s);
            for (int j = 0; j < 9; j++) {
                printf("%s: %s\n", cacThuocTinh(j), dsDocGia[i][j]);
            }
            printf("\n");
        }
    }
    if (!timThay) {
        printf("Khong tim thay doc gia ten giong '%s'\n", s);
    }
}*/

//////NEWWWWWWW
#define MAX_DOC_GIA 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_TEXT_LENGTH 100
#define MAX_DOC_GIA_ID_LENGTH 20
#define MAX_DATE_LENGTH 20
#define MAX_GENDER_LENGTH 10


// Tạo danh sách độc giả demo
char maDocGia[MAX_USERS][MAX_DOC_GIA_ID_LENGTH] = {"DG001", "DG002", "DG003"};
char hoTen[MAX_USERS][MAX_TEXT_LENGTH] = {"Nguyen Thi Lan", "Tran Minh Tu", "Nguyen Van C"};
char cmnd[MAX_USERS][MAX_TEXT_LENGTH] = {"123456789", "987654321", "456789125"};
char birth[MAX_USERS][MAX_DATE_LENGTH] = {"21/03/1998", "15/05/2000", "13/07/2001"};
char gioiTinh[MAX_USERS][MAX_GENDER_LENGTH] = {"Nu", "Nam", "Nam"};
char email[MAX_USERS][MAX_TEXT_LENGTH] = {"lannt@gmail.com", "tmtu@gmail.com", "nguyenvanc@gmail.com"};
char diaChi[MAX_USERS][MAX_TEXT_LENGTH] = {
    "123 Le Lai, TP.HCM",
    "456 Nguyen Thi Minh Khai, TP.HCM",
    "11 Hong Bang, TPHCM"
};
char ngayLapThe[MAX_USERS][MAX_DATE_LENGTH] = {"01/01/2022", "15/02/2021", "12/09/2023"};
char ngayHetHan[MAX_USERS][MAX_DATE_LENGTH] = {"01/01/2026", "15/02/2025", "12/09/2027"};

// Ban đầu đã có 3 độc giả mẫu
int soDocGia = 3;

// Hàm nhập ngày lập thẻ và tự động tính ngày hết hạn
void nhapNgayLapThe(int index) {
    char ngayNhap[9];
    printf("Ngay lap the (ddmmyyyy): ");
    fgets(ngayNhap, 9, stdin);
    while (getchar() != '\n'); // Clear buffer

    char day[3], month[3], year[5];
    strncpy(day, ngayNhap, 2); day[2] = '\0';
    strncpy(month, ngayNhap + 2, 2); month[2] = '\0';
    strncpy(year, ngayNhap + 4, 4); year[4] = '\0';

    sprintf(ngayLapThe[index], "%s/%s/%s", day, month, year);

    // Cộng thêm 48 tháng
    int d = atoi(day);
    int m = atoi(month) + 48;
    int y = atoi(year) + (m - 1) / 12;
    m = (m - 1) % 12 + 1;

    sprintf(ngayHetHan[index], "%02d/%02d/%04d", d, m, y);
}

// Hàm thêm độc giả mới
void themDocGia() {
    if (soDocGia >= MAX_USERS) {
        printf("Danh sach day!\n");
        return;
    }

    while (getchar() != '\n'); // <== thêm dòng này để ăn sạch '\n' trước khi nhập mới

    printf("\nNhap thong tin doc gia thu %d:\n", soDocGia + 1);

    printf("Ma doc gia: ");
    fgets(maDocGia[soDocGia], MAX_DOC_GIA_ID_LENGTH, stdin);
    maDocGia[soDocGia][strcspn(maDocGia[soDocGia], "\n")] = 0;

    printf("Ho ten: ");
    fgets(hoTen[soDocGia], MAX_TEXT_LENGTH, stdin);
    hoTen[soDocGia][strcspn(hoTen[soDocGia], "\n")] = 0;

    printf("CMND: ");
    fgets(cmnd[soDocGia], MAX_TEXT_LENGTH, stdin);
    cmnd[soDocGia][strcspn(cmnd[soDocGia], "\n")] = 0;

    printf("Ngay sinh (dd/mm/yyyy): ");
    fgets(birth[soDocGia], MAX_DATE_LENGTH, stdin);
    birth[soDocGia][strcspn(birth[soDocGia], "\n")] = 0;

    printf("Gioi tinh (Nam/Nu): ");
    fgets(gioiTinh[soDocGia], MAX_GENDER_LENGTH, stdin);
    gioiTinh[soDocGia][strcspn(gioiTinh[soDocGia], "\n")] = 0;

    printf("Email: ");
    fgets(email[soDocGia], MAX_TEXT_LENGTH, stdin);
    email[soDocGia][strcspn(email[soDocGia], "\n")] = 0;

    printf("Dia chi: ");
    fgets(diaChi[soDocGia], MAX_TEXT_LENGTH, stdin);
    diaChi[soDocGia][strcspn(diaChi[soDocGia], "\n")] = 0;

    nhapNgayLapThe(soDocGia);

    soDocGia++;
}

// Hàm xuất danh sách độc giả
void xuatDanhSach() {
    printf("\n==== DANH SACH DOC GIA ====\n");
    printf("\n%-6s | %-20s | %-10s | %-10s | %-5s | %-20s | %-30s | %-12s | %-12s |\n",
        "MaDG", "Ho Ten", "CMND", "Ngay sinh", "GT", "Email", "Dia chi", "Lap the", "Het han");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soDocGia; i++) {
        printf("%-6s | %-20s | %-10s | %-10s | %-5s | %-20s | %-30s | %-12s | %-12s |\n",
            maDocGia[i], hoTen[i], cmnd[i], birth[i], gioiTinh[i], email[i], diaChi[i], ngayLapThe[i], ngayHetHan[i]);
    }
}

void suaThongTinDocGia() {
    char id[MAX_DOC_GIA_ID_LENGTH];
    int found = 0;

    while (getchar() != '\n'); // <== thêm dòng này để ăn sạch '\n' trước khi nhập mới
    printf("Nhap ma doc gia can sua: ");
    fgets(id, MAX_DOC_GIA_ID_LENGTH, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(maDocGia[i], id) == 0) {
            printf("\nChinh sua thong tin doc gia %d:\n", i + 1);

            // printf("Ma doc gia: ");
            // fgets(maDocGia[i], MAX_DOC_GIA_ID_LENGTH, stdin);
            // maDocGia[i][strcspn(maDocGia[i], "\n")] = 0;

            printf("Ho ten: ");
            fgets(hoTen[i], MAX_TEXT_LENGTH, stdin);
            hoTen[i][strcspn(hoTen[i], "\n")] = 0;

            printf("CMND: ");
            fgets(cmnd[i], MAX_TEXT_LENGTH, stdin);
            cmnd[i][strcspn(cmnd[i], "\n")] = 0;

            printf("Ngay sinh (dd/mm/yyyy): ");
            fgets(birth[i], MAX_DATE_LENGTH, stdin);
            birth[i][strcspn(birth[i], "\n")] = 0;

            printf("Gioi tinh (Nam/Nu): ");
            fgets(gioiTinh[i], MAX_GENDER_LENGTH, stdin);
            gioiTinh[i][strcspn(gioiTinh[i], "\n")] = 0;

            printf("Email: ");
            fgets(email[i], MAX_TEXT_LENGTH, stdin);
            email[i][strcspn(email[i], "\n")] = 0;

            printf("Dia chi: ");
            fgets(diaChi[i], MAX_TEXT_LENGTH, stdin);
            diaChi[i][strcspn(diaChi[i], "\n")] = 0;

            nhapNgayLapThe(i);
            printf("Thong tin doc gia da duoc cap nhat.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay ma doc gia.\n");
    }
}

void xoaThongTinDocGia() {
    char id[MAX_DOC_GIA_ID_LENGTH];
    int found = 0;

    printf("Nhap ma doc gia can xoa: ");
    fgets(id, MAX_DOC_GIA_ID_LENGTH, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(maDocGia[i], id) == 0) {
            // Xóa thông tin độc giả bằng cách dịch chuyển các phần tử còn lại về phía trước
            for (int j = i; j < soDocGia - 1; j++) {
                strcpy(maDocGia[j], maDocGia[j + 1]);
                strcpy(hoTen[j], hoTen[j + 1]);
                strcpy(cmnd[j], cmnd[j + 1]);
                strcpy(birth[j], birth[j + 1]);
                strcpy(gioiTinh[j], gioiTinh[j + 1]);
                strcpy(email[j], email[j + 1]);
                strcpy(diaChi[j], diaChi[j + 1]);
                // Cập nhật ngày lập thẻ
                strcpy(ngayLapThe[j], ngayLapThe[j + 1]);
            }
            soDocGia--;  // Giảm số lượng độc giả
            printf("Thong tin doc gia da duoc xoa.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay ma doc gia.\n");
    }
}

void timKiemDocGiaTheoCMND() {
    char cmndToSearch[MAX_TEXT_LENGTH];
    int found = 0;

    printf("Nhap CMND doc gia can tim: ");
    fgets(cmndToSearch, MAX_TEXT_LENGTH, stdin);
    cmndToSearch[strcspn(cmndToSearch, "\n")] = 0;

    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(cmnd[i], cmndToSearch) == 0) {
            printf("\nThong tin doc gia:\n");
            printf("Ma doc gia: %s\n", maDocGia[i]);
            printf("Ho ten: %s\n", hoTen[i]);
            printf("CMND: %s\n", cmnd[i]);
            printf("Ngay sinh: %s\n", birth[i]);
            printf("Gioi tinh: %s\n", gioiTinh[i]);
            printf("Email: %s\n", email[i]);
            printf("Dia chi: %s\n", diaChi[i]);
            // Hiển thị ngày lập thẻ
            printf("Ngay lap the: %s\n", ngayLapThe[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia voi CMND nay.\n");
    }
}

void timKiemDocGiaTheoHoTen() {
    char hoTenToSearch[MAX_TEXT_LENGTH];
    int found = 0;

    printf("Nhap ho ten doc gia can tim: ");
    fgets(hoTenToSearch, MAX_TEXT_LENGTH, stdin);
    hoTenToSearch[strcspn(hoTenToSearch, "\n")] = 0;

    for (int i = 0; i < soDocGia; i++) {
        if (strstr(hoTen[i], hoTenToSearch) != NULL) {
            printf("\nThong tin doc gia:\n");
            printf("Ma doc gia: %s\n", maDocGia[i]);
            printf("Ho ten: %s\n", hoTen[i]);
            printf("CMND: %s\n", cmnd[i]);
            printf("Ngay sinh: %s\n", birth[i]);
            printf("Gioi tinh: %s\n", gioiTinh[i]);
            printf("Email: %s\n", email[i]);
            printf("Dia chi: %s\n", diaChi[i]);
            // Hiển thị ngày lập thẻ
            printf("Ngay lap the: %s\n", ngayLapThe[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia voi ten nay.\n");
    }
}

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
    char chon;
    while (true) {
        menuDocGia();
        scanf
        (" %c", &chon);
        switch (chon)
        {
            case 'a':
                if (soDocGia < 1) {
                printf("Danh sach trong!\n");
                continue;
            }
            printf("|  Ban dang: Xem danh sach do gia trong thu vien  |");
            xuatDanhSach();
            break;
            case 'b': printf("|  Ban dang: Them doc gia  |");
            themDocGia();
            break;
            case 'c': printf("|  Ban dang: Chinh sua thong tin doc gia  |");
            suaThongTinDocGia();
            break;
            case 'd': printf("|  Ban dang: Xoa thong tin doc gia  |");
            xoaThongTinDocGia();
            break;
            case 'e': printf("|  Ban dang: Tim kiem doc gia theo CMND  |");
            timKiemDocGiaTheoCMND();
            break;
            case 'f': printf("|  Ban dang: Tim kiem doc gia theo ho ten  |");
            timKiemDocGiaTheoHoTen();
            break;
            case 'g': printf("|  TRO LAI MENU  |\n");
            return;
            //break;
            default:
                printf("Lua chon khong hop le\n");
            break;
        }
    }
}
