#include <stdio.h>
#include "header.h"
// Hàm main, chương trình sẽ bắt đầu từ hàm này
int main()
{
    char buffer[100];
    int chon;
    while (true)
    {
        menu();

        fgets(buffer, sizeof(buffer), stdin);

        // Kiểm tra nếu nhập đúng số nguyên
        if (sscanf(buffer, "%d", &chon) != 1) {
            printf("Vui long nhap mot so nguyen hop le!\n");
            continue; // Quay lại menu
        }

        switch (chon)
        {
            case 1: printf("|  QUAN LY DOC GIA  |");
            quanLyDocGia(); // Gọi tên hàm để sử dụng
            break;
            case 2: printf("|  QUAN LY SACH  |");
            quanLySach();
            break;
            case 3: printf("|  LAP PHIEU MUON SACH  |");
                DocMangTuTapTinPhieuMuon(danhSachPMuon, soPhieuMuon);
                nhapMuonSach();
                GhiTapTinPhieuMuon(danhSachPMuon, soPhieuMuon);
                xuatMuonSach();
            break;
            case 4: printf("|  LAP PHIEU TRA SACH  |");
                DocMangTuTapTinPhieuTra(danhSachPTra, soPhieuTra);
                nhapTraSach();
                GhiTapTinPhieuTra(danhSachPTra, soPhieuTra);
                xuatTraSach();
            break;
            case 5: printf("|  CAC THONG KE CO BAN  |");
            thongKeCoBan();
            break;
            case 6: printf("|  THOAT CHUONG TRINH  |");
            return 0;
            default: printf("Khong co chuc nang nay! Hay thu chuc nang khac."); break;
        }
    }
}
