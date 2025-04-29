#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "docGia.h"

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
char diaChi[MAX_USERS][MAX_TEXT_LENGTH] = {"123 Le Lai, TP.HCM", "456 Nguyen Thi Minh Khai, TP.HCM", "11 Hong Bang, TPHCM"};
char ngayLapThe[MAX_USERS][MAX_DATE_LENGTH] = {"01/01/2022", "15/02/2021", "12/09/2023"};
char ngayHetHan[MAX_USERS][MAX_DATE_LENGTH] = {"01/01/2026", "15/02/2025", "12/09/2027"};

//Số độc giả ban đầu là 3
int soDocGia = 3;

// Hàm thêm độc giả mới
// Nhập vào từng thuộc tính, mỗi thuộc tính là 1 mảng 1 chiều,
// Lưu lại dữ liệu trong từng mảng đó, cập nhật lại số lượng độc giả sau khi thêm
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

    // Nếu mã độc giả đã tồn tại trước đó thì bắt nhập lại mã khác
    if (tonTaiMaDocGia(maDocGia[soDocGia])) {
        printf("Ma doc gia da ton tai. Khong the them.\n");
        return;
    }

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

    // Nhập vào ngày lập thẻ và tự tính ngày hết hạn
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

// Hàm sửa thông tin độc giả
// Nhập vào mã độc giả muốn sửa, nếu có thì chỉnh sửa thông tin, nếu không thì thông báo không có mã đó
// Không sửa lại mã độc giả, các thông tin phải được nhập đầy đủ
// Nhập đúng theo định dạng được gợi ý, ví dụ dd/mm/yyyy -> 21/10/2002
void suaThongTinDocGia() {
    char id[MAX_DOC_GIA_ID_LENGTH];
    int found = 0;

    while (getchar() != '\n'); // <== thêm dòng này để ăn sạch '\n' trước khi nhập mới
    printf("\nNhap ma doc gia can sua: ");
    fgets(id, MAX_DOC_GIA_ID_LENGTH, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(maDocGia[i], id) == 0) {
            printf("\nChinh sua thong tin doc gia %d:\n", i + 1);

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

// Hàm xóa thông tin độc giả
// Nhập vào mã độc giả cần xóa, nếu có thì xóa thông tin, nếu không có thì thông báo không tìm thấy mã, quay về menu
void xoaThongTinDocGia() {
    char id[MAX_DOC_GIA_ID_LENGTH];
    int found = 0;
    while (getchar() != '\n');
    printf("\nNhap ma doc gia can xoa: ");
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

// Hàm tìm kiếm thông tin độc giả bằng số chứng minh nhân dân
// Nhập vào số CMND, xuất ra thông tin của độc giả tương ứng
void timKiemDocGiaTheoCMND() {
    char cmndToSearch[MAX_TEXT_LENGTH];
    int found = 0;
    while (getchar() != '\n'); // clear "\n"
    printf("\nNhap CMND doc gia can tim: ");
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

// Hàm tìm kiếm độc giả theo họ tên
// Nhập vào họ tên, xuất ra thông tin của độc giả tương ứng
void timKiemDocGiaTheoHoTen() {
    char hoTenToSearch[MAX_TEXT_LENGTH];
    int found = 0;
    while (getchar() != '\n');
    printf("\nNhap ho ten doc gia can tim: ");
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

// Hàm xuất Menu các chức năng trong quản lý độc giả
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

// Hàm xử lý khi gọi các chức năng
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
            default:
                printf("Lua chon khong hop le\n");
            break;
        }
    }
}
