# GNU / Clang 用のコンパイルオプション
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -O2)
endif()

# MSVC（Windows用コンパイラ）の場合
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/W4 /O2)
endif()

