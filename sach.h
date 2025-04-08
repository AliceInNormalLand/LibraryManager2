//
// Created by VICTUS on 4/8/2025.
//

#ifndef SACH_H
#define SACH_H
void menuSach();
const char* thuocTinhSach(int n);
void nhapSach(char ds[][8][50], int* soSach);
void xuatSach(char ds[][8][50], int soSach);
void chinhSuaSach(char ds[][8][50], int soSach, char isbn[]);
void xoaSach(char ds[][8][50], int* soSach, char isbn[]);
void timSachTheoISBN(char ds[][8][50], int soSach, char isbn[]);
void timSachTheoTen(char ds[][8][50], int soSach, char ten[]);
char quanLySach();
#endif //SACH_H
