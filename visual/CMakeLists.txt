cmake_minimum_required(VERSION 3.17)
project(visual_filler C)

set(CMAKE_C_STANDARD 90)

add_executable(visual_filler src/visual.c inc/visual.h src/parcing.c src/event_handler.c src/status_bar.c src/print_map.c)

target_include_directories(visual_filler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(visual_filler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(visual_filler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Libft/inc)
#find_library(FT ft)
set(FT ${CMAKE_CURRENT_SOURCE_DIR}/Libft/libft.a)
target_link_libraries(visual_filler ${FT})

target_include_directories(visual_filler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Libvisual/minilibx_macos/inc)
#find_library(MLX mlx)
set(MLX ${CMAKE_CURRENT_SOURCE_DIR}/Libvisual/minilibx_macos/libmlx.a)
target_link_libraries(visual_filler ${MLX})

target_include_directories(visual_filler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Libvisual/inc)
#find_library(VISUAL visual)
set(VISUAL ${CMAKE_CURRENT_SOURCE_DIR}/Libvisual/libvisual.a)
target_link_libraries(visual_filler ${VISUAL})

target_link_libraries(visual_filler "-framework OpenGL")

target_link_libraries(visual_filler "-framework AppKit")