cmake_minimum_required(VERSION 3.14.5)
project(ACS_Hw1 C)

set(CMAKE_C_STANDARD 90)
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -Wall -fno-sanitize-recover=all")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -Wall -fno-sanitize-recover=all")

add_executable(ACS_Hw1 main.c number.c number.h fraction.c fraction.h polar.c polar.h complex_number.c complex_number.h container.c container.h rnd.h rnd.c data.h extdata.h)
