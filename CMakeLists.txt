cmake_minimum_required(VERSION 3.10)
project(library_manager)

set(CMAKE_CXX_STANDARD 20)

# Thêm tất cả các file .cpp từ thư mục src vào dự án
file(GLOB SOURCES "*.cpp")

# Tạo file thực thi từ các file nguồn
add_executable(library_manager ${SOURCES}
        phieuMuonSach.cpp
        phieuMuonSach.h
        phieuTraSach.cpp
        phieuTraSach.h
        thongKe.cpp
        hamExtra.cpp
        hamExtra.h
        thongKe.h)
