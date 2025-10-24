cmake_minimum_required(VERSION 3.10)
project(Biblioteca LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Biblioteca
    src/main.cpp
    src/Libro.cpp
    src/Biblioteca.cpp
)

target_include_directories(Biblioteca PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
