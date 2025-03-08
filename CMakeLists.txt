cmake_minimum_required(VERSION 3.30)
project(web_server_c C)

set(CMAKE_C_STANDARD 11)

add_executable(web_server_c main.c
        server.c
        server.utils.h
        server.utils.c)
