#include "thongKe.h"
#include <string>

// Hàm thống kê số lượng sách trong thư viện
// Đầu vào là số lượng của từng đầu sách và số lượng đầu sách
// Đầu ra là tổng số lượng của tất cả các đầu sách
int thongKeSachTV(char soLuongSach[][50], int soSach) {
    int tong = 0;
    for (int i = 0; i < soSach; i++) {
        tong += atoi(soLuongSach[i]);
    }
    printf("Tong so sach trong thu vien la: %d\n", tong);
    return tong;
}

// Hàm thống kê số lượng sách theo thể loại
// Đầu vào là thể loại và số đầu sách
// Đầu ra là số lượng theo từng thể loại sách
void thongKeLoaiSach(char theLoai[][50], int soSach) {
    for (int i = 0; i < soSach; i++) {
        int daTonTai = 0;

        for (int j = 0; j < i; j++) {
            if (strcmp(theLoai[i], theLoai[j]) == 0) {
                daTonTai = 1;
                break;
            }
        }

        if (!daTonTai) {
            int dem = 0;
            for (int k = 0; k < soSach; k++) {
                if (strcmp(theLoai[i], theLoai[k]) == 0) {
                    int soLuongS = atoi(soLuong[k]);
                    dem += soLuongS;
                }
            }
            printf("The loai: %s - So luong: %d\n", theLoai[i], dem);
        }
    }
}

// Thống kê số lượng độc giả
// Đầu vào là mã độc giả từ phiếu mượn, số lượng phiếu mượn và tổng số độc giả
// Đầu ra là tổng số độc giả hiện tại, số độc giả đang mượn sách
void thongKeDocGia(char maDocGiaPhieuMuon[][50], int soPhieuMuon, int tongDocGia) {
    printf("Tong so doc gia: %d\n", tongDocGia);
    printf("==========================================\n");
    printf("Bang thong ke doc gia muon sach\n");
    printf("==========================================\n");
    if (soPhieuMuon <= 0) {
        printf("Khong co doc gia nao muon het!");
    }
    else {
        for (int i = 0; i < soPhieuMuon; i++) {
            int daTonTai = 0;

            for (int j = 0; j < i; j++) {
                if (strcmp(maDocGiaPhieuMuon[i], maDocGiaPhieuMuon[j]) == 0) {
                    daTonTai = 1;
                    break;
                }
            }

            if (!daTonTai) {
                int dem = 0;
                for (int k = 0; k < soPhieuMuon; k++) {
                    if (strcmp(maDocGiaPhieuMuon[i], maDocGiaPhieuMuon[k]) == 0) {
                        dem++;
                    }
                }
                printf("Doc gia ma %s - So luot muon: %d\n", maDocGiaPhieuMuon[i], dem);
            }
        }
    }
}

// Thống kê số lương độc giả theo giới tính
// Đầu vào là giới tính và tổng số độc giả
// Đầu ra là tổng số độc giả theo từng giới tính
void thongKeGioiTinh(char gioiTinh[][10], int soDocGia) {
    for (int i = 0; i < soDocGia; i++) {
        int daTonTai = 0;

        for (int j = 0; j < i; j++) {
            if (strcmp(gioiTinh[i], gioiTinh[j]) == 0) {
                daTonTai = 1;
                break;
            }
        }

        if (!daTonTai) {
            int dem = 0;
            for (int k = 0; k < soDocGia; k++) {
                if (strcmp(gioiTinh[i], gioiTinh[k]) == 0) {
                    dem++;
                }
            }
            printf("Gioi tinh: %s - So luong: %d\n", gioiTinh[i], dem);
        }
    }
}

// Thống kê số sách đang được mượn
// Đầu vào là số lượng phiếu mượn và trả
// Đầu ra là bảng tất cả các mã sách với số lượng đang mượn và số lượng tồn kho tương ứng
void thongKeSachMuon(int soPhieuMuon, int soPhieuTra) {
    int dangMuon = soPhieuMuon - soPhieuTra;
    printf("So sach dang duoc muon la: %d\n", dangMuon);
    for (int i = 0; i < soSach; i++) {
        int dem = 0;
        for (int j = 0; j < soPhieuMuon; j++) {
            int daTonTai = 0;
            if (strcmp(ISBN[i], isbnPhieuMuon[j]) == 0) {
                for (int k = 0; k < soPhieuTra; k++) {
                    if (maPhieuMuon[j] == maPhieuTra[k]) {
                        daTonTai = 1;
                        break;
                    }
                }
                if (!daTonTai) {
                    dem++;
                }
            }
        }
        printf("Ma sach: %s | So sach dang muon: %d | Ton kho: %s\n", ISBN[i], dem, soLuong[i]);
    }
}

// Thống kê danh sách độc giả bị trễ hạn
// Đầu vào là số lượng phiếu trả
// Đầu ra là thông tin của các độc giả bị trễ hạn, sách họ mượn, tiền phạt của họ
int thongKeTreHan(int soPhieuTra) {
    int count = 0;
    printf("\n%-15s %-15s %-15s %-15s %-15s\n",
           "Ma phieu muon", "Ma Doc Gia", "ISBN", "Tinh trang", "Tien phat");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < soPhieuTra; i++) {
        if (strcmp(tinhTrangPhieuTra[i], "qua han") == 0) {
            printf("%-15d %-15s %-15s %-15s %-15d\n",
               maPhieuTra[i],
               maDocGiaPhieuTra[i],
               isbnPhieuTra[i],
               tinhTrangPhieuTra[i],
               tienPhatPhieuTra[i]);
            count++;
        }
    }
    printf("So doc gia bi tre han la: %d\n", count);

    return count;
}

// Hàm menu hiện các chức năng của thống kê cơ bản
void menuThongKe() {
    printf("\n================***================"); printf("\n");
    printf("BAN DANG THUC HIEN THONG KE CO BAN"); printf("\n");
    printf("\na.Thong ke so luong sach trong thu vien");
    printf("\nb.Thong ke so luong sach theo the loai");
    printf("\nc.Thong ke so luong doc gia");
    printf("\nd.Thong ke so luong doc gia theo gioi tinh");
    printf("\ne.Thong ke so sach dang duoc muon");
    printf("\nf.Thong ke danh sach doc gia bi tre han");
    printf("\ng.TRO LAI THU VIEN"); printf("\n");
    printf("\n================***================"); printf("\n");
}

// Hàm xử lý các lựa chọn
void thongKeCoBan() {
    char chon;
    while (true) {
        menuThongKe();
        printf("Nhap lua chon: ");
        scanf(" %c", &chon);

        switch (chon) {
            case 'a':
                printf("\n|  Ban dang: Thong ke tong so sach trong thu vien  |\n");
            thongKeSachTV(soLuong, soSach);
            break;

            case 'b':
                printf("\n|  Ban dang: Thong ke so luong sach theo the loai  |\n");
            thongKeLoaiSach(theLoai, soSach);
            break;

            case 'c':
                printf("\n|  Ban dang: Thong ke tong so doc gia va so luot muon  |\n");
            thongKeDocGia(maDocGiaPhieuMuon, soPhieuMuon, soDocGia);
            break;

            case 'd':
                printf("\n|  Ban dang: Thong ke so luong doc gia theo gioi tinh  |\n");
            thongKeGioiTinh(gioiTinh, soDocGia);
            break;

            case 'e':
                printf("\n|  Ban dang: Thong ke so sach dang duoc muon  |\n");
            thongKeSachMuon(soPhieuMuon, soPhieuTra);
            break;

            case 'f':
                printf("\n|  Ban dang: Thong ke so doc gia bi tre han  |\n");
            thongKeTreHan(soPhieuTra);
            break;

            case 'g':
                printf("\n|  TRO LAI MENU CHINH |\n");
            return;

            default:
                printf("\nLua chon khong hop le. Vui long thu lai.\n");
            break;
        }
        printf("\n");
    }
}