//
// Created by VICTUS on 4/8/2025.
//
#include "sach.h"

/*char dsSach[][8][50];  // Cấp phát bộ nhớ thật sự
int soSach = 0;*/

/*
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
*/


#include <stdio.h>
#include <string.h>

#define MAX_SACH 100
#define MAX_TEXT_LENGTH 50

// Danh sách sách
char ISBN[MAX_SACH][MAX_TEXT_LENGTH] = {
    "9786042034673",
    "9786042034680",
    "9786042034697"
};

char tenSach[MAX_SACH][MAX_TEXT_LENGTH] = {
    "Lap trinh C co ban",
    "Lap trinh huong doi tuong",
    "Cau truc du lieu"
};

char tacGia[MAX_SACH][MAX_TEXT_LENGTH] = {
    "Nguyen Van A",
    "Nguyen Van B",
    "Nguyen Van C"
};

char nhaXuatBan[MAX_SACH][MAX_TEXT_LENGTH] = {
    "NXB Giao Duc",
    "NXB Tre",
    "NXB Lao Dong"
};

char namXuatBan[MAX_SACH][MAX_TEXT_LENGTH] = {
    "2022",
    "2021",
    "2023"
};

char theLoai[MAX_SACH][MAX_TEXT_LENGTH] = {
    "Giao trinh",
    "Giao trinh",
    "Giao trinh"
};

char giaSach[MAX_SACH][MAX_TEXT_LENGTH] = {
    "75000",
    "85000",
    "95000"
};

char soLuong[MAX_SACH][MAX_TEXT_LENGTH] = {
    "10",
    "8",
    "5"
};

int soSach = 3; // Đang có 3 sách

// Hàm hiển thị danh sách sách
void xemDanhSachSach() {
    printf("\n===== DANH SACH SACH =====\n");
    for (int i = 0; i < soSach; i++) {
        printf("Sach %d:\n", i + 1);
        printf("ISBN: %s\n", ISBN[i]);
        printf("Ten sach: %s\n", tenSach[i]);
        printf("Tac gia: %s\n", tacGia[i]);
        printf("Nha xuat ban: %s\n", nhaXuatBan[i]);
        printf("Nam xuat ban: %s\n", namXuatBan[i]);
        printf("The loai: %s\n", theLoai[i]);
        printf("Gia sach: %s\n", giaSach[i]);
        printf("So luong: %s\n\n", soLuong[i]);
    }
}

// Hàm kiểm tra ISBN đã tồn tại chưa
int tonTaiISBN(const char* isbn) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) return 1;
    }
    return 0;
}

// Hàm thêm sách
void themSach() {
    int soMoi;
    printf("Nhap so luong sach muon them: ");
    scanf("%d", &soMoi);
    getchar(); // Xoa bo dem

    if (soSach + soMoi > MAX_SACH) {
        printf("Khong du bo nho de them!\n");
        return;
    }

    for (int i = soSach; i < soSach + soMoi; ) {
        char isbnTam[MAX_TEXT_LENGTH];

        printf("Nhap ISBN sach thu %d: ", i + 1);
        fgets(isbnTam, MAX_TEXT_LENGTH, stdin);
        isbnTam[strcspn(isbnTam, "\n")] = 0;

        if (tonTaiISBN(isbnTam)) {
            printf("ISBN da ton tai! Vui long nhap lai.\n");
            continue;
        }
        strcpy(ISBN[i], isbnTam);

        printf("Nhap ten sach: ");
        fgets(tenSach[i], MAX_TEXT_LENGTH, stdin);
        tenSach[i][strcspn(tenSach[i], "\n")] = 0;

        printf("Nhap tac gia: ");
        fgets(tacGia[i], MAX_TEXT_LENGTH, stdin);
        tacGia[i][strcspn(tacGia[i], "\n")] = 0;

        printf("Nhap nha xuat ban: ");
        fgets(nhaXuatBan[i], MAX_TEXT_LENGTH, stdin);
        nhaXuatBan[i][strcspn(nhaXuatBan[i], "\n")] = 0;

        printf("Nhap nam xuat ban: ");
        fgets(namXuatBan[i], MAX_TEXT_LENGTH, stdin);
        namXuatBan[i][strcspn(namXuatBan[i], "\n")] = 0;

        printf("Nhap the loai: ");
        fgets(theLoai[i], MAX_TEXT_LENGTH, stdin);
        theLoai[i][strcspn(theLoai[i], "\n")] = 0;

        printf("Nhap gia sach: ");
        fgets(giaSach[i], MAX_TEXT_LENGTH, stdin);
        giaSach[i][strcspn(giaSach[i], "\n")] = 0;

        printf("Nhap so luong: ");
        fgets(soLuong[i], MAX_TEXT_LENGTH, stdin);
        soLuong[i][strcspn(soLuong[i], "\n")] = 0;

        i++;
    }

    soSach += soMoi;
    printf("Da them thanh cong %d sach!\n", soMoi);
}

// Hàm tìm sách theo ISBN
void timKiemISBN() {
    char isbn[MAX_TEXT_LENGTH];
    printf("Nhap ISBN can tim: ");
    fgets(isbn, MAX_TEXT_LENGTH, stdin);
    isbn[strcspn(isbn, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) {
            printf("Tim thay sach:\n");
            printf("Ten sach: %s\n", tenSach[i]);
            printf("Tac gia: %s\n", tacGia[i]);
            found = 1;
            break;
        }
    }
    if (!found) printf("Khong tim thay sach voi ISBN nay!\n");
}

// Hàm tìm sách theo tên
void timKiemTen() {
    char ten[MAX_TEXT_LENGTH];
    printf("Nhap ten sach can tim: ");
    fgets(ten, MAX_TEXT_LENGTH, stdin);
    ten[strcspn(ten, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < soSach; i++) {
        if (strstr(tenSach[i], ten) != NULL) {
            printf("Tim thay sach:\n");
            printf("ISBN: %s\n", ISBN[i]);
            printf("Tac gia: %s\n", tacGia[i]);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay sach voi tu khoa nay!\n");
}

// Hàm chỉnh sửa sách
void chinhSuaSach() {
    char isbn[MAX_TEXT_LENGTH];
    printf("Nhap ISBN sach can sua: ");
    fgets(isbn, MAX_TEXT_LENGTH, stdin);
    isbn[strcspn(isbn, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) {
            printf("Nhap lai ten sach: ");
            fgets(tenSach[i], MAX_TEXT_LENGTH, stdin);
            tenSach[i][strcspn(tenSach[i], "\n")] = 0;

            printf("Nhap lai tac gia: ");
            fgets(tacGia[i], MAX_TEXT_LENGTH, stdin);
            tacGia[i][strcspn(tacGia[i], "\n")] = 0;

            printf("Nhap lai nha xuat ban: ");
            fgets(nhaXuatBan[i], MAX_TEXT_LENGTH, stdin);
            nhaXuatBan[i][strcspn(nhaXuatBan[i], "\n")] = 0;

            printf("Nhap lai nam xuat ban: ");
            fgets(namXuatBan[i], MAX_TEXT_LENGTH, stdin);
            namXuatBan[i][strcspn(namXuatBan[i], "\n")] = 0;

            printf("Nhap lai the loai: ");
            fgets(theLoai[i], MAX_TEXT_LENGTH, stdin);
            theLoai[i][strcspn(theLoai[i], "\n")] = 0;

            printf("Nhap lai gia sach: ");
            fgets(giaSach[i], MAX_TEXT_LENGTH, stdin);
            giaSach[i][strcspn(giaSach[i], "\n")] = 0;

            printf("Nhap lai so luong: ");
            fgets(soLuong[i], MAX_TEXT_LENGTH, stdin);
            soLuong[i][strcspn(soLuong[i], "\n")] = 0;

            printf("Sua thanh cong!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Khong tim thay sach!\n");
}

// Hàm xóa sách
void xoaSach() {
    char isbn[MAX_TEXT_LENGTH];
    printf("Nhap ISBN sach can xoa: ");
    fgets(isbn, MAX_TEXT_LENGTH, stdin);
    isbn[strcspn(isbn, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) {
            for (int j = i; j < soSach - 1; j++) {
                strcpy(ISBN[j], ISBN[j + 1]);
                strcpy(tenSach[j], tenSach[j + 1]);
                strcpy(tacGia[j], tacGia[j + 1]);
                strcpy(nhaXuatBan[j], nhaXuatBan[j + 1]);
                strcpy(namXuatBan[j], namXuatBan[j + 1]);
                strcpy(theLoai[j], theLoai[j + 1]);
                strcpy(giaSach[j], giaSach[j + 1]);
                strcpy(soLuong[j], soLuong[j + 1]);
            }
            soSach--;
            printf("Xoa sach thanh cong!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Khong tim thay sach!\n");
}

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
            xemDanhSachSach();
            break;
            case 'b':
                printf("THEM SACH MOI:\n");
            themSach();
            break;
            case 'c':
                printf("CHINH SUA THONG TIN SACH:\n");
            chinhSuaSach();
            break;
            case 'd':
                printf("XOA SACH:\n");
            xoaSach();
            break;
            case 'e':
                printf("TIM KIEM THEO ISBN:\n");
            timKiemISBN();
            break;
            case 'f':
                printf("TIM KIEM THEO TEN SACH:\n");
            timKiemTen();
            break;
            default:
                printf("Lua chon khong hop le\n");
            break;
        }
    }
    return chon;
}
//LOI O DAY NHA************************
void capNhatSoLuong(char maSachTV[]) {
    for (int i = 0; i < soSach; i++) {
        int soLuongSach = atoi(soLuong[i]);
        if (strcmp(ISBN[i], maSachTV) == 0) {
            soLuongSach -= 1;
            char chuoi[50];
            //soLuong[i] = itoa(soLuongSach, chuoi, 10);
        }
    }
}
