#pragma once

#include <stdio.h>
#include <string.h>
#include "docGia.h"
#include "sach.h"
#include "hamExtra.h"

#define MAX_PHIEUMUON 100

extern int soPhieuMuon;
extern char maDocGiaPhieuMuon[MAX_PHIEUMUON][50];
extern char isbnPhieuMuon[MAX_PHIEUMUON][50];

void nhapMuonSach();
void xuatMuonSach();
