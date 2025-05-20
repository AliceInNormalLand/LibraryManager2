#include <stdio.h>
#include <string.h>
#include "sach.h"

// Danh sách sách demo
sach danhSachSach[MAX_SACH] = {
    {"S001", "Hoang tu be", "Saint Exupery", "NXB Giao Duc", "2022", "Van hoc Phap", "75000", "10"},
    {"S002", "Nha gia kim", "Paulo Coelho", "NXB Tre", "2021", "Triet hoc", "85000", "8"},
    {"S003", "Lap trinh C/C++", "Nguyen Van C", "NXB Lao Dong", "2023", "Triet hoc", "95000", "5"}
};

int soSach = 3; // Đang có 3 sách


// Hàm hiển thị danh sách sách
void xemDanhSachSach() {
    printf("\n===== DANH SACH SACH =====\n");
    for (int i = 0; i < soSach; i++) {
        printf("Sach %d:\n", i + 1);
        printf("ISBN: %s\n", danhSachSach[i].ISBN);
        printf("Ten sach: %s\n", danhSachSach[i].tenSach);
        printf("Tac gia: %s\n", danhSachSach[i].tacGia);
        printf("Nha xuat ban: %s\n", danhSachSach[i].nhaXuatBan);
        printf("Nam xuat ban: %s\n", danhSachSach[i].namXuatBan);
        printf("The loai: %s\n", danhSachSach[i].theLoai);
        printf("Gia sach: %s\n", danhSachSach[i].giaSach);
        printf("So luong: %s\n\n", danhSachSach[i].soLuong);
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
        strcpy(danhSachSach[i].ISBN, isbnTam);

        printf("Nhap ten sach: ");
        fgets(danhSachSach[i].tenSach, MAX_TEXT_LENGTH, stdin);
        danhSachSach[i].tenSach[strcspn(danhSachSach[i].tenSach, "\n")] = 0;

        printf("Nhap tac gia: ");
        fgets(danhSachSach[i].tacGia, MAX_TEXT_LENGTH, stdin);
        danhSachSach[i].tacGia[strcspn(danhSachSach[i].tacGia, "\n")] = 0;

        printf("Nhap nha xuat ban: ");
        fgets(danhSachSach[i].nhaXuatBan, MAX_TEXT_LENGTH, stdin);
        danhSachSach[i].nhaXuatBan[strcspn(danhSachSach[i].nhaXuatBan, "\n")] = 0;

        printf("Nhap nam xuat ban: ");
        fgets(danhSachSach[i].namXuatBan, MAX_TEXT_LENGTH, stdin);
        danhSachSach[i].namXuatBan[strcspn(danhSachSach[i].namXuatBan, "\n")] = 0;

        printf("Nhap the loai: ");
        fgets(danhSachSach[i].theLoai, MAX_TEXT_LENGTH, stdin);
        danhSachSach[i].theLoai[strcspn(danhSachSach[i].theLoai, "\n")] = 0;

        printf("Nhap gia sach: ");
        fgets(danhSachSach[i].giaSach, MAX_TEXT_LENGTH, stdin);
        danhSachSach[i].giaSach[strcspn(danhSachSach[i].giaSach, "\n")] = 0;

        printf("Nhap so luong: ");
        fgets(danhSachSach[i].soLuong, MAX_TEXT_LENGTH, stdin);
        danhSachSach[i].soLuong[strcspn(danhSachSach[i].soLuong, "\n")] = 0;

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
        if (strcmp(danhSachSach[i].ISBN, isbn) == 0) {
            printf("Tim thay sach:\n");
            printf("Ten sach: %s\n", danhSachSach[i].tenSach);
            printf("Tac gia: %s\n", danhSachSach[i].tacGia);
            printf("Nha xuat ban: %s\n", danhSachSach[i].nhaXuatBan);
            printf("Nam xuat ban: %s\n", danhSachSach[i].namXuatBan);
            printf("The loai: %s\n", danhSachSach[i].theLoai);
            printf("Gia sach: %s\n", danhSachSach[i].giaSach);
            printf("So luong: %s\n", danhSachSach[i].soLuong);
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
        if (strcmp(danhSachSach[i].tenSach, ten) == 0) {
            printf("Tim thay sach:\n");
            printf("ISBN: %s\n", danhSachSach[i].ISBN);
            printf("Tac gia: %s\n", danhSachSach[i].tacGia);
            printf("Nha xuat ban: %s\n", danhSachSach[i].nhaXuatBan);
            printf("Nam xuat ban: %s\n", danhSachSach[i].namXuatBan);
            printf("The loai: %s\n", danhSachSach[i].theLoai);
            printf("Gia sach: %s\n", danhSachSach[i].giaSach);
            printf("So luong: %s\n", danhSachSach[i].soLuong);
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
        if (strcmp(danhSachSach[i].ISBN, isbn) == 0) {
            printf("Nhap lai ten sach: ");
            fgets(danhSachSach[i].tenSach, MAX_TEXT_LENGTH, stdin);
            danhSachSach[i].tenSach[strcspn(danhSachSach[i].tenSach, "\n")] = 0;

            printf("Nhap lai tac gia: ");
            fgets(danhSachSach[i].tacGia, MAX_TEXT_LENGTH, stdin);
            danhSachSach[i].tacGia[strcspn(danhSachSach[i].tacGia, "\n")] = 0;

            printf("Nhap lai nha xuat ban: ");
            fgets(danhSachSach[i].nhaXuatBan, MAX_TEXT_LENGTH, stdin);
            danhSachSach[i].nhaXuatBan[strcspn(danhSachSach[i].nhaXuatBan, "\n")] = 0;

            printf("Nhap lai nam xuat ban: ");
            fgets(danhSachSach[i].namXuatBan, MAX_TEXT_LENGTH, stdin);
            danhSachSach[i].namXuatBan[strcspn(danhSachSach[i].namXuatBan, "\n")] = 0;

            printf("Nhap lai the loai: ");
            fgets(danhSachSach[i].theLoai, MAX_TEXT_LENGTH, stdin);
            danhSachSach[i].theLoai[strcspn(danhSachSach[i].theLoai, "\n")] = 0;

            printf("Nhap lai gia sach: ");
            fgets(danhSachSach[i].giaSach, MAX_TEXT_LENGTH, stdin);
            danhSachSach[i].giaSach[strcspn(danhSachSach[i].giaSach, "\n")] = 0;

            printf("Nhap lai so luong: ");
            fgets(danhSachSach[i].soLuong, MAX_TEXT_LENGTH, stdin);
            danhSachSach[i].soLuong[strcspn(danhSachSach[i].soLuong, "\n")] = 0;

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
        if (strcmp(danhSachSach[i].ISBN, isbn) == 0) {
            for (int j = i; j < soSach - 1; j++) {
                strcpy(danhSachSach[j].ISBN, danhSachSach[j + 1].ISBN);
                strcpy(danhSachSach[j].tenSach, danhSachSach[j + 1].tenSach);
                strcpy(danhSachSach[j].tacGia, danhSachSach[j + 1].tacGia);
                strcpy(danhSachSach[j].nhaXuatBan, danhSachSach[j + 1].nhaXuatBan);
                strcpy(danhSachSach[j].namXuatBan, danhSachSach[j + 1].namXuatBan);
                strcpy(danhSachSach[j].theLoai, danhSachSach[j + 1].theLoai);
                strcpy(danhSachSach[j].giaSach, danhSachSach[j + 1].giaSach);
                strcpy(danhSachSach[j].soLuong, danhSachSach[j + 1].soLuong);
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
            default:
                printf("Lua chon khong hop le\n");
            break;
        }
    }
}



