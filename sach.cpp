#include <stdio.h>
#include <string.h>
#include "sach.h"

#define MAX_SACH 100
#define MAX_TEXT_LENGTH 50

// Danh sách sách demo
char ISBN[MAX_SACH][MAX_TEXT_LENGTH] = {"S001", "S002", "S003"};
char tenSach[MAX_SACH][MAX_TEXT_LENGTH] = {"Hoang tu be", "Nha gia kim", "Lap trinh C/C++"};
char tacGia[MAX_SACH][MAX_TEXT_LENGTH] = {"Saint Exupery", "Paulo Coelho", "Nguyen Van C"};
char nhaXuatBan[MAX_SACH][MAX_TEXT_LENGTH] = {"NXB Giao Duc", "NXB Tre", "NXB Lao Dong"};
char namXuatBan[MAX_SACH][MAX_TEXT_LENGTH] = {"2022", "2021", "2023"};
char theLoai[MAX_SACH][MAX_TEXT_LENGTH] = {"Van hoc Phap", "Triet hoc", "Triet hoc"};
char giaSach[MAX_SACH][MAX_TEXT_LENGTH] = {"75000", "85000", "95000"};
char soLuong[MAX_SACH][MAX_TEXT_LENGTH] = {"10", "8", "5"};

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

// Hàm thêm sách
// Có thể nhập một lúc nhiều sách
// Nhập vào số lượng sách muốn thêm trong 1 lần, sau đó nhập thông tin của từng sách theo thứ tự
// Sau khi nhập xong thì cập nhật số đầu sách hiện tại
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

        if (tonTaiMaSach(isbnTam)) {
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
// Nhập mã sách xuất ra thông tin sách tương ứng, nếu không có thì báo lỗi
void timKiemISBN() {
    char isbn[MAX_TEXT_LENGTH];
    while (getchar() != '\n'); // <== thêm dòng này để ăn sạch '\n' trước khi nhập mới
    printf("Nhap ISBN can tim: ");
    fgets(isbn, MAX_TEXT_LENGTH, stdin);
    isbn[strcspn(isbn, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) {
            printf("Tim thay sach:\n");
            printf("Ten sach: %s\n", tenSach[i]);
            printf("Tac gia: %s\n", tacGia[i]);
            printf("Nha xuat ban: %s\n", nhaXuatBan[i]);
            printf("Nam xuat ban: %s\n", namXuatBan[i]);
            printf("The loai: %s\n", theLoai[i]);
            printf("Gia sach: %s\n", giaSach[i]);
            printf("So luong: %s\n", soLuong[i]);
            found = 1;
            break;
        }
    }
    if (!found) printf("Khong tim thay sach voi ISBN nay!\n");
}

// Hàm tìm sách theo tên
// Nhập tên sách xuất ra thông tin sách tương ứng, nếu không có thì báo lỗi
void timKiemTen() {
    char ten[MAX_TEXT_LENGTH];
    while (getchar() != '\n'); // <== thêm dòng này để ăn sạch '\n' trước khi nhập mới
    printf("Nhap ten sach can tim: ");
    fgets(ten, MAX_TEXT_LENGTH, stdin);
    ten[strcspn(ten, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < soSach; i++) {
        if (strcmp(tenSach[i], ten) == 0) {
            printf("Tim thay sach:\n");
            printf("ISBN: %s\n", ISBN[i]);
            printf("Tac gia: %s\n", tacGia[i]);
            printf("Nha xuat ban: %s\n", nhaXuatBan[i]);
            printf("Nam xuat ban: %s\n", namXuatBan[i]);
            printf("The loai: %s\n", theLoai[i]);
            printf("Gia sach: %s\n", giaSach[i]);
            printf("So luong: %s\n", soLuong[i]);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay sach voi tu khoa nay!\n");
}

// Hàm chỉnh sửa sách
// Nhập mã sách cần chỉnh sửa, tiến hành sửa thông tin sách, KHÔNG sửa được mã sách
// Nếu không tìm thấy mã sách thì báo lỗi
void chinhSuaSach() {
    char isbn[MAX_TEXT_LENGTH];
    while (getchar() != '\n'); // <== thêm dòng này để ăn sạch '\n' trước khi nhập mới
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
// Nhập mã sách cần xóa, tiến hành xóa thông tin sách
// Nếu không tìm thấy mã sách thì báo lỗi
void xoaSach() {
    char isbn[MAX_TEXT_LENGTH];
    while (getchar() != '\n'); // <== thêm dòng này để ăn sạch '\n' trước khi nhập mới
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

// Hàm xuất Menu các chức năng trong quản lý sách
void menuSach() {
    printf("\n================***================\n"); printf("\n");
    printf("QUAN LY DOC SACH"); printf("\n");
    printf("a.Xem danh sach sach\n");
    printf("b.Them sach\n");
    printf("c.Chinh sua thong tin sach\n");
    printf("d.Xoa sach\n");
    printf("e.Tim kiem sach theo ISBN\n");
    printf("f.Tim kiem sach theo ten sach\n");
    printf("g.TRO LAI THU VIEN\n"); printf("\n");
    printf("================***================\n"); printf("\n");
    printf("\nChon mot chuc nang: ");
}

// Hàm xử lý khi gọi các chức năng
void quanLySach() {
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
            case 'g': printf("|  TRO LAI MENU  |\n");
            return;
            //break;
            default:
                printf("Lua chon khong hop le\n");
            break;
        }
    }
}



