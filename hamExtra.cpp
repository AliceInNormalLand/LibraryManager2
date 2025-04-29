#include <string.h>
#include <stdio.h>
#include "hamExtra.h"
#include "docGia.h"

// Tính xem ngày thứ dd/mm/yyyy là ngày thứ bao nhiêu trong năm.
// Đầu vào là ngày, tháng, năm, đầu ra là ngày thứ mấy trong năm
int tinhSoNgayTrongNam(int d, int m, int y) {
    int ngayTrongThang[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ngayTrongThang[2] = 29;

    int tongNgay = d;
    for (int i = 1; i < m; i++) {
        tongNgay += ngayTrongThang[i];
    }
    return tongNgay;
}

// Tổng số ngày tính từ năm 0 tới ngày đó
// Đầu vào là ngày tháng năm của ngày mượn/ ngày trả thực tế
// Đầu ra là số ngày tính từ năm 0 tới ngày đó
int tinhTongSoNgay(int d, int m, int y) {
    return y * 365 + y / 4 - y / 100 + y / 400 + tinhSoNgayTrongNam(d, m, y);
}

// Hàm tính tiền phạt
// Đầu vào là ngày mượn và ngày trả thực tế
// Tính ra được ngày trễ hạn, nếu lớn hơn 0 thì lấy số ngày trễ hạn nhân 5000 ra tiền phạt
int tinhTienPhat(char ngayMuon[], char ngayTraThucTe[]) {
    int d1, m1, y1, d2, m2, y2;

    sscanf(ngayMuon, "%2d/%2d/%4d", &d1, &m1, &y1);
    sscanf(ngayTraThucTe, "%2d/%2d/%4d", &d2, &m2, &y2);

    int ngayMuonTotal = tinhTongSoNgay(d1, m1, y1);
    int ngayTraTotal = tinhTongSoNgay(d2, m2, y2);

    int soNgayMuon = ngayTraTotal - ngayMuonTotal;
    int tienPhat = 0;

    if (soNgayMuon > 7) {
        tienPhat = (soNgayMuon - 7) * 5000;
    }
    return tienPhat;
}

// Hàm tính tiền phạt khi mất sách
// Đầu vào là mã của sách được trả
// Kiểm tra tình trạng, nếu là "mat" thì lấy giá của sách nhân 2
int tinhTienPhatMatSach(char maSachNhap[]) {
    int tienPhat = 0;
    for (int i = 0; i < soSach ; i++) {
        if (strcmp(maSachNhap, ISBN[i]) == 0) {
            tienPhat = atoi(giaSach[i]) * 2;
            break;
        }
    }
    return tienPhat;
}

// Hàm xử lý việc tính toán 7 ngày sau là ngày nào (Hỗ trợ yêu cầu mỗi sách mượn tối đa 7 ngày)
// Đầu vào là ngày mượn và biến ngayTraDuKien để lưu ngày trả dự kiến
// Đầu ra là ngày trả dự kiến (bằng ngày mượn công thêm 7 ngày)
void cong7Ngay(char ngayMuon[], char ngayTraDuKien[]) {
    int d, m, y;
    sscanf(ngayMuon, "%2d/%2d/%4d", &d, &m, &y);

    d += 7;

    int ngayTrongThang[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ngayTrongThang[2] = 29;

    while (d > ngayTrongThang[m]) {
        d -= ngayTrongThang[m];
        m++;
        if (m > 12) {
            m = 1;
            y++;
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                ngayTrongThang[2] = 29;
            else
                ngayTrongThang[2] = 28;
        }
    }
    sprintf(ngayTraDuKien, "%02d/%02d/%04d", d, m, y);
}

// Hàm cập nhật số lượng sách sau khi mượn
// Đầu vào là mã sách từ phiếu mượn
// Đầu ra là số lượng sách của đầu sách tương ứng cộng 1
void capNhatSauMuon(char maSachTV[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], maSachTV) == 0) {
            int soLuongSach = atoi(soLuong[i]);
            soLuongSach -= 1;
            sprintf(soLuong[i], "%d", soLuongSach); // chuyển thẳng số thành chuỗi
        }
    }
}

// Hàm cập nhật số lượng sách của đầu sách tương ứng sau khi trả
// Đầu vào là mã sách từ phiếu trả
// Đầu ra là số lượng sách trừ 1
void capNhatSauTra(char maSachTV[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], maSachTV) == 0) {
            int soLuongSach = atoi(soLuong[i]);
            soLuongSach += 1;
            sprintf(soLuong[i], "%d", soLuongSach); // chuyển thẳng số thành chuỗi
        }
    }
}

// Hàm kiểm tra mã độc giả đã tồn tại chưa
// Đầu vào là mã độc giả cần kiểm tra
// Đầu ra là: nếu giống với mã độc giả trong danh sách độc giả thì trả về 1 ngược lại trả về 0
int tonTaiMaDocGia(char maDocGiaNhap[]) {
    for (int i = 0; i < soDocGia; i++) {
        if (strcmp(maDocGia[i], maDocGiaNhap) == 0) {
            return 1; // Mã độc giả đã tồn tại
        }
    }
    return 0; // Chưa có
}

// Hàm kiểm tra mã sách có tồn tại chưa
// Đầu vào là mã sách cần kiểm tra
// Đầu ra là: nếu giống với mã sách trong danh sách sách thì trả về 1 ngược lại trả về 0
int tonTaiMaSach(char maSachNhap[]) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(ISBN[i], maSachNhap) == 0) {
            return 1;
        }
    }
    return 0;
}

// Hàm nhập ngày lập thẻ để tính ngày hết hạn
// Đầu vào là chỉ số của thuộc tính ngày lập thẻ trong danh sách độc giả
// Đầu ra là ngày hết hạn (+ 48 tháng) tại chỉ số cột tương ứng
void nhapNgayLapThe(int index) {
    int d, m, y;

    printf("Nhap ngay lap the (dd/mm/yyyy): ");
    scanf_s("%d/%d/%d", &d, &m, &y);

    while (getchar() != '\n'); // Xóa bỏ ký tự thừa

    // Lưu lại ngày lập thẻ theo định dạng dd/mm/yyyy (không xài print vì print chỉ in ra, không lưu lại)
    sprintf(ngayLapThe[index], "%02d/%02d/%04d", d, m, y);

    // Cộng thêm 48 tháng
    m += 48;
    y += (m - 1) / 12;
    m = (m - 1) % 12 + 1;

    sprintf(ngayHetHan[index], "%02d/%02d/%04d", d, m, y);
}
