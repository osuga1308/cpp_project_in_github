cmake_minimum_required(VERSION 3.10)
project(cpp_project_in_github)

# コンパイラの標準を C++17 に設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# コンパイルオプションの読み込み
include(cmakes/compile_option.cmake)

# --- メイン実行ファイルの設定 ---
add_executable(cpp_project src/main.cpp src/calc.cpp)
target_include_directories(cpp_project PRIVATE include)

# --- テスト環境の設定 ---
enable_testing()

# GoogleTest を探す（Homebrew経由）
find_package(GTest REQUIRED HINTS /opt/homebrew/opt/googletest)

# テスト用実行ファイル
add_executable(runTests test/test_sample.cpp src/calc.cpp)
target_include_directories(runTests PRIVATE include /opt/homebrew/opt/googletest/include)

# GoogleTest と pthread をリンク
target_link_libraries(runTests
    /opt/homebrew/opt/googletest/lib/libgtest.a
    /opt/homebrew/opt/googletest/lib/libgtest_main.a
    pthread
)

# ctest で実行できるように登録
add_test(NAME runTests COMMAND runTests)

