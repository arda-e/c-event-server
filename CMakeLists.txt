cmake_minimum_required(VERSION 3.30)
project(web_server_c C)

set(CMAKE_C_STANDARD 11)

add_executable(web_server_c main.c
        server.c
        server.utils.h
        server.utils.c
        http_helpers.h
        http_helpers.c
        http_router.h
        http_router.c)
