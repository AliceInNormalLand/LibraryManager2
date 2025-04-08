#include <stdio.h>
#include "header.h"
#include <stdlib.h>

#include "menu.h"
#include "docGia.h"
#include "sach.h"


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

            break;
            case 4: printf("|  LAP PHIEU TRA SACH  |");

            break;
            case 5: printf("|  CAC THONG KE CO BAN  |");

            break;
            case 6: printf("|  THOAT CHUONG TRINH  |");

            break;
            default: printf("Khong co chuc nang nay! Hay thu chuc nang khac."); break;
        }
    }
    /*
    int n;
    char c;
    int m;
    int running = 1;  // Điều kiện chạy menu chính

    while (running)
    {
        printf("THU VIEN DAI HOC KHOA HOC TU NHIEN"); printf("\n");
        printf("\n================***================\n"); printf("\n");
        printf("\n1.QUAN LY DOC GIA");
        printf("\n2.QUAN LY SACH");
        printf("\n3.LAP PHIEU MUON SACH");
        printf("\n4.LAP PHIEU TRA SACH");
        printf("\n5.CAC THONG KE CO BAN");
        printf("\n6.THOAT CHUONG TRINH"); printf("\n");
        printf("\n================***================"); printf("\n");
        printf("\nChon mot chuc nang: ");
        scanf_s("%d", &n);  printf("\n");
        while (getchar() != '\n'); // 🛠 Xóa bộ nhớ đệm nhập

        switch (n)
        {
        case 1:
        {
            int running1 = 1; // 🛠 Reset chạy menu con khi quay lại

            while (running1)
            {
                printf("\n================***================"); printf("\n");
                printf("QUAN LY DOC GIA"); printf("\n");

                printf("\na.Xem danh sach doc gia trong thu vien");
                printf("\nb.Them doc gia");
                printf("\nc.Chinh sua thong tin doc gia");
                printf("\nd.Xoa thong tin doc gia");
                printf("\ne.Tim kiem doc gia theo CMND");
                printf("\nf.Tim kiem sach theo ho ten");
                printf("\ng.TRO LAI THU VIEN"); printf("\n");
                printf("\n================***================"); printf("\n");
                printf("\nChon mot chuc nang: ");

                scanf_s(" %c", &c, 1); // 🛠 Bỏ khoảng trắng trước `%c` để bỏ qua '\n'

                if (c == 'g')
                {
                    printf("Ban muon thoat chuong trinh chu?\n");
                    printf("Thoat(1) / Khong(0): ");
                    scanf_s("%d", &m);
                    while (getchar() != '\n'); // 🛠 Xóa bộ nhớ đệm nhập

                    if (m == 1)
                    {
                        running1 = 0; // Thoát menu con
                    }
                }
                else
                {
                    quanLyDocGia(c);
                }
            }
            break;
        }
        case 2:
        {
            clearScreen();
            int running1 = 1; // 🛠 Reset chạy menu con khi quay lại
            while (running1)
            {
                printf("\n================***================"); printf("\n");
                printf("QUAN LY DOC SACH"); printf("\n");

                printf("\na.Xem danh sach sach");
                printf("\nb.Them sach");
                printf("\nc.Chinh sua thong tin sach");
                printf("\nd.Xoa sach");
                printf("\ne.Tim kiem sach theo ISBN");
                printf("\nf.Tim kiem sach theo ho ten");
                printf("\ng.TRO LAI THU VIEN"); printf("\n");
                printf("\n================***================"); printf("\n");
                printf("\nChon mot chuc nang: ");

                scanf_s(" %c", &c, 1); // 🛠 Bỏ khoảng trắng trước `%c` để bỏ qua '\n'

                if (c == 'g')
                {
                    printf("Ban muon thoat chuong trinh chu?\n");
                    printf("Thoat(1) / Khong(0): ");
                    scanf_s("%d", &m);
                    while (getchar() != '\n'); // 🛠 Xóa bộ nhớ đệm nhập

                    if (m == 1)
                    {
                        running1 = 0; // Thoát menu con
                    }
                }
                else
                {
                    quanLySach(c);
                }
            }
            break;
            // quanLySach();
        }
        case 3:
            clearScreen();
            // lapPhieuMuonSach();
            break;
        case 4:
            clearScreen();
            // lapPhieuTraSach();
            break;
        case 5:
            clearScreen();
            // cacThongKeCoBan();
            break;
        case 6:
            printf("Ban muon thoat chuong trinh chu?\n");
            printf("Thoat(1) / Khong(0): ");
            scanf_s("%d", &m);
            while (getchar() != '\n'); // 🛠 Xóa bộ nhớ đệm nhập

            if (m == 1) {
                running = 0; // Kết thúc chương trình
            }
            break;
        default:
            printf("Lua chon khong hop le, nhan Enter de chon lai...");
            while (getchar() != '\n'); // 🛠 Xóa bộ nhớ đệm nhập
        }
    }
    return 0;*/
}
