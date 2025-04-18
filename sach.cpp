//
// Created by VICTUS on 4/8/2025.
//
#include "sach.h"

char dsSach[][8][50];  // Cấp phát bộ nhớ thật sự
int soSach = 0;

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
    char s[50];
    char chon;
    while (true) {
        menuSach();
        scanf(" %c", &chon);
        switch (chon) {
            case 'a':
                if (soSach < 1) {
                    printf("Danh sach trong!\n");
                    continue;
                }
                printf("DANH SACH SACH:\n");
            xuatSach(dsSach, soSach);
            break;
            case 'b':
                printf("THEM SACH MOI:\n");
            nhapSach(dsSach, &soSach);
            break;
            case 'c':
                printf("CHINH SUA THONG TIN SACH:\n");
            printf("Nhap ISBN can sua: ");
            scanf("%s", s);
            while (getchar() != '\n');
            chinhSuaSach(dsSach, soSach, s);
            break;
            case 'd':
                printf("XOA SACH:\n");
            printf("Nhap ISBN can xoa: ");
            scanf("%s", s);
            while (getchar() != '\n');
            xoaSach(dsSach, &soSach, s);
            break;
            case 'e':
                printf("TIM KIEM THEO ISBN:\n");
            printf("Nhap ISBN: ");
            scanf("%s", s);
            while (getchar() != '\n');
            timSachTheoISBN(dsSach, soSach, s);
            break;
            case 'f':
                printf("TIM KIEM THEO TEN SACH:\n");
            printf("Nhap ten sach: ");
            while (getchar() != '\n');
            fgets(s, 50, stdin);
            s[strcspn(s, "\n")] = 0;
            timSachTheoTen(dsSach, soSach, s);
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
    return tt[n];
}

bool tonTaiMaSach(char dsSach[][8][50], int soSach, const char* maCanKiem) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(dsSach[i][0], maCanKiem) == 0) {
            return true;
        }
    }
    return false;
}

void nhapSach(char dsSach[][8][50], int* soSach) {
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

            if (tonTaiMaSach(dsSach, *soSach, maSachTam)) {
                printf("[X] Ma sach da ton tai. Vui long nhap ma khac.\n");
            } else {
                strcpy(dsSach[i][0], maSachTam);
                break;
            }
        }

        // Nhập các thuộc tính còn lại
        for (int j = 1; j < 8; j++) {
            printf("%s: ", thuocTinhSach(j));
            fgets(dsSach[i][j], 50, stdin);
            dsSach[i][j][strcspn(dsSach[i][j], "\n")] = 0;
        }

        i++; // Tăng chỉ số sách sau khi nhập thành công
    }

    *soSach += soMoi;
}

void xuatSach(char dsSach[][8][50], int soSach) {
    printf("\n%-15s | %-20s | %-15s | %-15s | %-10s | %-10s | %-10s | %-8s\n",
        "ISBN", "Ten sach", "Tac gia", "Nha XB", "Nam XB", "The loai", "Gia", "So luong");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soSach; i++) {
        printf("%-15s | %-20s | %-15s | %-15s | %-10s | %-10s | %-10s | %-8s\n",
            dsSach[i][0], dsSach[i][1], dsSach[i][2], dsSach[i][3],
            dsSach[i][4], dsSach[i][5], dsSach[i][6], dsSach[i][7]);
    }
}

void chinhSuaSach(char dsSach[][8][50], int soSach, char isbn[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(dsSach[i][0], isbn) == 0) {
            printf("Nhap thong tin moi cho sach (ISBN: %s):\n", isbn);
            for (int j = 0; j < 8; j++) {
                printf("%s (Cu: %s): ", thuocTinhSach(j), dsSach[i][j]);
                fgets(dsSach[i][j], 50, stdin);
                dsSach[i][j][strcspn(dsSach[i][j], "\n")] = 0;
            }
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach co ISBN: %s\n", isbn);
}

void xoaSach(char dsSach[][8][50], int* soSach, char isbn[]) {
    for (int i = 0; i < *soSach; i++) {
        if (strcmp(dsSach[i][0], isbn) == 0) {
            for (int j = i; j < *soSach - 1; j++) {
                for (int k = 0; k < 8; k++) {
                    strcpy(dsSach[j][k], dsSach[j + 1][k]);
                }
            }
            (*soSach)--;
            printf("Da xoa sach co ISBN: %s\n", isbn);
            return;
        }
    }
    printf("Khong tim thay sach co ISBN: %s\n", isbn);
}

void timSachTheoISBN(char dsSach[][8][50], int soSach, char isbn[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(dsSach[i][0], isbn) == 0) {
            printf("Thong tin sach co ISBN %s:\n", isbn);
            for (int j = 0; j < 8; j++) {
                printf("%s: %s\n", thuocTinhSach(j), dsSach[i][j]);
            }
            return;
        }
    }
    printf("Khong tim thay sach voi ISBN: %s\n", isbn);
}

void timSachTheoTen(char dsSach[][8][50], int soSach, char ten[]) {
    int timThay = 0;
    for (int i = 0; i < soSach; i++) {
        if (strstr(dsSach[i][1], ten)) {
            timThay = 1;
            printf("\nSach co ten giong '%s':\n", ten);
            for (int j = 0; j < 8; j++) {
                printf("%s: %s\n", thuocTinhSach(j), dsSach[i][j]);
            }
        }
    }
    if (!timThay) {
        printf("Khong tim thay sach co ten giong '%s'\n", ten);
    }
}

