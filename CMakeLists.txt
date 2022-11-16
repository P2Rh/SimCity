cmake_minimum_required(VERSION 3.23)
project(SimCity C)

set(CMAKE_C_STANDARD 99)

add_executable(SimCity main.c mesFonctions.c maBiblio.h)

target_link_libraries(SimCity -lmingw32 -lalleg44)