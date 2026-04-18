cmake_minimum_required(VERSION 3.16)
project(SeniorShop)

set(CMAKE_CXX_STANDARD 17)

# Указываем папку с заголовками
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Список всех исходных файлов
set(SOURCES
        src/main.cpp
        src/Product.cpp
        src/User.cpp
        src/Admin.cpp
        src/Employee.cpp
        src/SuperAdmin.cpp
        src/Storage.cpp
        src/Account.cpp
        src/Official.cpp
        src/Getline.cpp
        src/Sale.cpp
        src/Check.cpp
        src/Shop.cpp
)

# Создаём исполняемый файл
add_executable(SeniorShop ${SOURCES})