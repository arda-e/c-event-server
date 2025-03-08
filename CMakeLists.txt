cmake_minimum_required(VERSION 3.30)
project(web_server_c C)

set(CMAKE_C_STANDARD 11)

add_executable(web_server_c
        server.c
        server.utils.h
        server.utils.c
        http/http_helpers.h
        http/http_helpers.c
        http/http_router.h
        http/http_router.c)
