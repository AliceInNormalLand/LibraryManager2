#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "docGia.h"

docGia danhSachDocGia[MAX_USERS];

//Số độc giả ban đầu là 0
int soDocGia = 0;

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
    DocMangTuTapTinDocGia(danhSachDocGia, soDocGia);
    while (true) {
        menuDocGia();
        scanf(" %c", &chon);
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
                GhiTapTinDocGia(danhSachDocGia, soDocGia);
            break;
            case 'c': printf("|  Ban dang: Chinh sua thong tin doc gia  |");
            suaThongTinDocGia();
                GhiTapTinDocGia(danhSachDocGia, soDocGia);
            break;
            case 'd': printf("|  Ban dang: Xoa thong tin doc gia  |");
            xoaThongTinDocGia();
                GhiTapTinDocGia(danhSachDocGia, soDocGia);
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

void GhiTapTinDocGia(docGia danhSachDocGia[], int soDocGia) {
    FILE* file;
    fopen_s(&file, "D:\\KHTN_NHAPMONLAPTRINH\\DanhSachDocGia.txt", "wt");
    fprintf(file, "%d\n", soDocGia);
    for (int i = 0; i < soDocGia; i++) {
        fprintf(file, "%s\n", danhSachDocGia[i].maDocGia);
        fprintf(file, "%s\n", danhSachDocGia[i].hoTen);
        fprintf(file, "%s\n", danhSachDocGia[i].cmnd);
        fprintf(file, "%s\n", danhSachDocGia[i].ngaySinh);
        fprintf(file, "%s\n", danhSachDocGia[i].gioiTinh);
        fprintf(file, "%s\n", danhSachDocGia[i].email);
        fprintf(file, "%s\n", danhSachDocGia[i].diaChi);
        fprintf(file, "%s\n", danhSachDocGia[i].ngayLapThe);
        fprintf(file, "%s\n", danhSachDocGia[i].ngayHetHan);
    }
    fclose(file);
}

void DocMangTuTapTinDocGia(docGia danhSachDocGia[], int& n) {
    FILE* file;
    fopen_s(&file, "D:\\KHTN_NHAPMONLAPTRINH\\DanhSachDocGia.txt", "rt");
    if (file != NULL) {
        fscanf_s(file, "%d", &n);
        fgetc(file);
        for (int i = 0; i < n; i++) {
            fgets(danhSachDocGia[i].maDocGia,MAX_DOC_GIA_ID_LENGTH,file);
            fgets(danhSachDocGia[i].hoTen,MAX_TEXT_LENGTH,file);
            fgets(danhSachDocGia[i].cmnd,MAX_TEXT_LENGTH,file);
            fgets(danhSachDocGia[i].ngaySinh,MAX_DATE_LENGTH,file);
            fgets(danhSachDocGia[i].gioiTinh,MAX_GENDER_LENGTH,file);
            fgets(danhSachDocGia[i].email,MAX_TEXT_LENGTH,file);
            fgets(danhSachDocGia[i].diaChi,MAX_TEXT_LENGTH,file);
            fgets(danhSachDocGia[i].ngayLapThe,MAX_DATE_LENGTH,file);
            fgets(danhSachDocGia[i].ngayHetHan,MAX_DATE_LENGTH,file);

            // Xoá ký tự '\n' cuối mỗi dòng nếu có
            danhSachDocGia[i].maDocGia[strcspn(danhSachDocGia[i].maDocGia, "\n")] = '\0';
            danhSachDocGia[i].hoTen[strcspn(danhSachDocGia[i].hoTen, "\n")] = '\0';
            danhSachDocGia[i].cmnd[strcspn(danhSachDocGia[i].cmnd, "\n")] = '\0';
            danhSachDocGia[i].ngaySinh[strcspn(danhSachDocGia[i].ngaySinh, "\n")] = '\0';
            danhSachDocGia[i].gioiTinh[strcspn(danhSachDocGia[i].gioiTinh, "\n")] = '\0';
            danhSachDocGia[i].email[strcspn(danhSachDocGia[i].email, "\n")] = '\0';
            danhSachDocGia[i].diaChi[strcspn(danhSachDocGia[i].diaChi, "\n")] = '\0';
            danhSachDocGia[i].ngayLapThe[strcspn(danhSachDocGia[i].ngayLapThe, "\n")] = '\0';
            danhSachDocGia[i].ngayHetHan[strcspn(danhSachDocGia[i].ngayHetHan, "\n")] = '\0';
        }
        fclose(file);
    }
    else {
        printf("Khong mo duoc tap tin");
    }
}

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
    fgets(danhSachDocGia[soDocGia].maDocGia, MAX_DOC_GIA_ID_LENGTH, stdin);
    danhSachDocGia[soDocGia].maDocGia[strcspn(danhSachDocGia[soDocGia].maDocGia, "\n")] = 0;

    // Nếu mã độc giả đã tồn tại trước đó thì bắt nhập lại mã khác
    if (tonTaiMaDocGia(danhSachDocGia[soDocGia].maDocGia)) {
        printf("Ma doc gia da ton tai. Khong the them.\n");
        return;
    }

    printf("Ho ten: ");
    fgets(danhSachDocGia[soDocGia].hoTen, MAX_TEXT_LENGTH, stdin);
    danhSachDocGia[soDocGia].hoTen[strcspn(danhSachDocGia[soDocGia].hoTen, "\n")] = 0;

    printf("CMND: ");
    fgets(danhSachDocGia[soDocGia].cmnd, MAX_TEXT_LENGTH, stdin);
    danhSachDocGia[soDocGia].cmnd[strcspn(danhSachDocGia[soDocGia].cmnd, "\n")] = 0;

    printf("Ngay sinh (dd/mm/yyyy): ");
    fgets(danhSachDocGia[soDocGia].ngaySinh, MAX_DATE_LENGTH, stdin);
    danhSachDocGia[soDocGia].ngaySinh[strcspn(danhSachDocGia[soDocGia].ngaySinh, "\n")] = 0;

    printf("Gioi tinh (Nam/Nu): ");
    fgets(danhSachDocGia[soDocGia].gioiTinh, MAX_GENDER_LENGTH, stdin);
    danhSachDocGia[soDocGia].gioiTinh[strcspn(danhSachDocGia[soDocGia].gioiTinh, "\n")] = 0;

    printf("Email: ");
    fgets(danhSachDocGia[soDocGia].email, MAX_TEXT_LENGTH, stdin);
    danhSachDocGia[soDocGia].email[strcspn(danhSachDocGia[soDocGia].email, "\n")] = 0;

    printf("Dia chi: ");
    fgets(danhSachDocGia[soDocGia].diaChi, MAX_TEXT_LENGTH, stdin);
    danhSachDocGia[soDocGia].diaChi[strcspn(danhSachDocGia[soDocGia].diaChi, "\n")] = 0;

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
            danhSachDocGia[i].maDocGia, danhSachDocGia[i].hoTen, danhSachDocGia[i].cmnd, danhSachDocGia[i].ngaySinh,
            danhSachDocGia[i].gioiTinh, danhSachDocGia[i].email, danhSachDocGia[i].diaChi, danhSachDocGia[i].ngayLapThe, danhSachDocGia[i].ngayHetHan);
    }
}

//Kiểm tra chuỗi dữ liệu nhập vào nếu không rỗng thì mới cập nhật
//Ngược lại thì giữ chuỗi cũ
void capNhatChuoiNeuNhap(char* truongDuLieu, int maxLen) {
    char temp[256];
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = 0;
    if (strlen(temp) > 0) {
        strncpy(truongDuLieu, temp, maxLen);
        truongDuLieu[maxLen - 1] = '\0'; // Đảm bảo kết thúc chuỗi
    }
}

// Hàm sửa thông tin độc giả
// Nhập vào mã độc giả muốn sửa, nếu có thì chỉnh sửa thông tin, nếu không thì thông báo không có mã đó
// Không sửa lại mã độc giả, các thông tin phải được nhập đầy đủ
// Nhập đúng theo định dạng được gợi ý, ví dụ dd/mm/yyyy -> 21/10/2002
void suaThongTinDocGia() {
    char id[MAX_DOC_GIA_ID_LENGTH];
    int found = 0;

    while (getchar() != '\n'); // Ăn sạch '\n' trước khi nhập mới
    printf("\nNhap ma doc gia can sua: ");
    fgets(id, MAX_DOC_GIA_ID_LENGTH, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(danhSachDocGia[i].maDocGia, id) == 0) {
            printf("\nChinh sua thong tin doc gia %d (de trong neu muon giu nguyen):\n", i + 1);

            printf("Ho ten (Hien tai: %s): ", danhSachDocGia[i].hoTen);
            capNhatChuoiNeuNhap(danhSachDocGia[i].hoTen, MAX_TEXT_LENGTH);

            printf("CMND (Hien tai: %s): ", danhSachDocGia[i].cmnd);
            capNhatChuoiNeuNhap(danhSachDocGia[i].cmnd, MAX_TEXT_LENGTH);

            printf("Ngay sinh (dd/mm/yyyy) (Hien tai: %s): ", danhSachDocGia[i].ngaySinh);
            capNhatChuoiNeuNhap(danhSachDocGia[i].ngaySinh, MAX_DATE_LENGTH);

            printf("Gioi tinh (Nam/Nu) (Hien tai: %s): ", danhSachDocGia[i].gioiTinh);
            capNhatChuoiNeuNhap(danhSachDocGia[i].gioiTinh, MAX_GENDER_LENGTH);

            printf("Email (Hien tai: %s): ", danhSachDocGia[i].email);
            capNhatChuoiNeuNhap(danhSachDocGia[i].email, MAX_TEXT_LENGTH);

            printf("Dia chi (Hien tai: %s): ", danhSachDocGia[i].diaChi);
            capNhatChuoiNeuNhap(danhSachDocGia[i].diaChi, MAX_TEXT_LENGTH);

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
        if (strcmp(danhSachDocGia[i].maDocGia, id) == 0) {
            // Xóa thông tin độc giả bằng cách dịch chuyển các phần tử còn lại về phía trước
            for (int j = i; j < soDocGia - 1; j++) {
                strcpy(danhSachDocGia[j].maDocGia, danhSachDocGia[j + 1].maDocGia);
                strcpy(danhSachDocGia[j].hoTen, danhSachDocGia[j + 1].hoTen);
                strcpy(danhSachDocGia[j].cmnd, danhSachDocGia[j + 1].cmnd);
                strcpy(danhSachDocGia[j].ngaySinh, danhSachDocGia[j + 1].ngaySinh);
                strcpy(danhSachDocGia[j].gioiTinh, danhSachDocGia[j + 1].gioiTinh);
                strcpy(danhSachDocGia[j].email, danhSachDocGia[j + 1].email);
                strcpy(danhSachDocGia[j].diaChi, danhSachDocGia[j + 1].diaChi);
                // Cập nhật ngày lập thẻ
                strcpy(danhSachDocGia[j].ngayLapThe, danhSachDocGia[j + 1].ngayLapThe);
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
        if (strcmp(danhSachDocGia[i].cmnd, cmndToSearch) == 0) {
            printf("\nThong tin doc gia:\n");
            printf("Ma doc gia: %s\n", danhSachDocGia[i].maDocGia);
            printf("Ho ten: %s\n", danhSachDocGia[i].hoTen);
            printf("CMND: %s\n", danhSachDocGia[i].cmnd);
            printf("Ngay sinh: %s\n", danhSachDocGia[i].ngaySinh);
            printf("Gioi tinh: %s\n", danhSachDocGia[i].gioiTinh);
            printf("Email: %s\n", danhSachDocGia[i].email);
            printf("Dia chi: %s\n", danhSachDocGia[i].diaChi);
            // Hiển thị ngày lập thẻ
            printf("Ngay lap the: %s\n", danhSachDocGia[i].ngayLapThe);
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
        if (strstr(danhSachDocGia[i].hoTen, hoTenToSearch) != NULL) {
            printf("\nThong tin doc gia:\n");
            printf("Ma doc gia: %s\n", danhSachDocGia[i].maDocGia);
            printf("Ho ten: %s\n", danhSachDocGia[i].hoTen);
            printf("CMND: %s\n", danhSachDocGia[i].cmnd);
            printf("Ngay sinh: %s\n", danhSachDocGia[i].ngaySinh);
            printf("Gioi tinh: %s\n", danhSachDocGia[i].gioiTinh);
            printf("Email: %s\n", danhSachDocGia[i].email);
            printf("Dia chi: %s\n", danhSachDocGia[i].diaChi);
            // Hiển thị ngày lập thẻ
            printf("Ngay lap the: %s\n", danhSachDocGia[i].ngayLapThe);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay doc gia voi ten nay.\n");
    }
}
