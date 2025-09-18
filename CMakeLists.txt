cmake_minimum_required(VERSION 3.10)
project(cpp_project_in_github)

# コンパイラの標準を C++17 に設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# コンパイルオプションの読み込み
include(cmakes/compile_option.cmake)

# --- メイン実行ファイルの設定 ---
add_executable(cpp_project src/main.cpp)
target_include_directories(cpp_project PRIVATE include)

# --- テスト環境の設定（シンプル版） ---
enable_testing()

# ここでは runTests を作らず、main.cpp の引数モードをテストする
add_test(NAME Add_3_5 COMMAND cpp_project 3 5)
set_tests_properties(Add_3_5 PROPERTIES PASS_REGULAR_EXPRESSION "8")

