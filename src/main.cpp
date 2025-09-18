#include <iostream>
#include <limits>
#include <string>

// 文字列が整数かざっくりチェック（符号と数字のみ）
bool is_integer(const std::string& s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-') i = 1;
    if (i == s.size()) return false;
    for (; i < s.size(); ++i) if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    return true;
}

int main(int argc, char* argv[]) {
    // --- 引数モード: ./add_app 3 5 ---
    if (argc == 3) {
        std::string s1 = argv[1], s2 = argv[2];
        if (!is_integer(s1) || !is_integer(s2)) {
            std::cerr << "ERROR: invalid input\n";
            return 1;
        }
        long long a = std::stoll(s1);
        long long b = std::stoll(s2);
        std::cout << (a + b) << std::endl;
        return 0;
    }

    // --- 対話モード ---
    long long a, b;

    std::cout << "1つ目の整数を入力してください: ";
    while (!(std::cin >> a)) {
        std::cout << "整数を入力してください: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "2つ目の整数を入力してください: ";
    while (!(std::cin >> b)) {
        std::cout << "整数を入力してください: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "計算結果: " << (a + b) << std::endl;
    return 0;
}

