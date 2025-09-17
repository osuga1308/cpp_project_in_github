cmake_minimum_required(VERSION 3.10)
project(cpp_project_in_github)

# 追加する行（compile_option.cmakeを読み込む）
include(cmakes/compile_option.cmake)

add_executable(cpp_project src/main.cpp)

