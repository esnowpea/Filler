cmake_minimum_required(VERSION 3.16)
project(Filler C)

set(CMAKE_C_STANDARD 90)

add_executable(Filler src/main.c src/parcing.c src/clear_malloc.c src/init.c src/find_place_piece.c)
target_include_directories(Filler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_include_directories(Filler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Libft/inc)
#find_library(FT ft)
set(FT ${CMAKE_CURRENT_SOURCE_DIR}/Libft/libft.a)
target_link_libraries(Filler ${FT})
