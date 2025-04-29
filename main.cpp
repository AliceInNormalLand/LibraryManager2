#include <stdio.h>
#include "header.h"
// Hàm main, chương trình sẽ bắt đầu từ hàm này
int main()
{
    int chon;
    while (true)
    {
        menu();
        scanf("%d",&chon);
        switch (chon)
        {
            case 1: printf("|  QUAN LY DOC GIA  |");
            quanLyDocGia(); // Gọi tên hàm để sử dụng
            break;
            case 2: printf("|  QUAN LY SACH  |");
            quanLySach();
            break;
            case 3: printf("|  LAP PHIEU MUON SACH  |");
            nhapMuonSach();
            xuatMuonSach();
            break;
            case 4: printf("|  LAP PHIEU TRA SACH  |");
            nhapTraSach();
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
