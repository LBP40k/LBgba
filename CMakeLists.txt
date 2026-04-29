cmake_minimum_required(VERSION 3.23)
project(LBgba LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_PATH "C:/SDL2")

add_library(core STATIC
    src/arm7/arm7.cpp
    src/common/common.cpp
    src/mmu/mmu.cpp
)

add_executable(LBgba
    src/main.cpp
)

target_include_directories(core PUBLIC src)
target_include_directories(LBgba PRIVATE ${SDL2_PATH}/include)

target_link_directories(LBgba PRIVATE ${SDL2_PATH}/lib)

target_link_libraries(LBgba PRIVATE core SDL2 SDL2main)


add_custom_command(TARGET LBgba POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SDL2_PATH}/x86_64-w64-mingw32/bin/SDL2.dll"
    $<TARGET_FILE_DIR:LBgba>
)