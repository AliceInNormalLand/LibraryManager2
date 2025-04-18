#include <stdio.h>
#include "header.h"
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
            quanLyDocGia();
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

            break;
            case 6: printf("|  THOAT CHUONG TRINH  |");

            break;
            default: printf("Khong co chuc nang nay! Hay thu chuc nang khac."); break;
        }
    }
}
