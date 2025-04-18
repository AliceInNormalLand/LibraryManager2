#include <sec_api/stdio_s.h>
#include "docGia.h"
//
// Created by VICTUS on 4/8/2025.
//
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
        //printf("Doc gia thu %d:\n", i + 1);
        /*for (int j = 0; j < 9; j++) {
            printf("%s: %s\n", cacThuocTinh(j), dsDocGia[i][j]);
        }
        printf("--------------------------\n");*/
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
}