//1 1способ
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if (!in.is_open() || !out.is_open()) {
        return 1;
    }

    std::set<char> forbidden = {'u', 's', 'e', 'r', 'a', 'g', 'm', 'n', 't'};

    std::string line;
    bool first = true;
    while (std::getline(in, line)) {
        if (!first) out << '\n';
        first = false;

        for (char c : line) {
            char lower = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
            if (forbidden.find(lower) == forbidden.end()) {
                out << c;
            }
        }
    }

    in.close();
    out.close();
    return 0;
}

//1 2способ
#include <fstream>
#include <string>
#include <cctype>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if (!in.is_open() || !out.is_open()) {
        return 1;
    }

    // flag[c] == true  →  символ c (в нижнем регистре) запрещён
    bool forbidden[256] = {false};
    for (char ch : std::string("user agreement")) {
        forbidden[static_cast<unsigned char>(ch)] = true;
    }

    std::string s;
    std::getline(in, s, '\0');  // читаем весь файл

    for (char c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        char lower = static_cast<char>(std::tolower(uc));
        if (!forbidden[static_cast<unsigned char>(lower)]) {
            out << c;  // символ разрешён — выводим оригинал
        }
    }

    return 0;
}


//2
#include <fstream>
#include <string>

int main() {
    std::ifstream in1("input1.txt");
    std::ifstream in2("input2.txt");
    std::ofstream out("output.txt");

    if (!in1.is_open() || !in2.is_open() || !out.is_open()) {
        return 1;
    }

    std::string X, Y;
    std::getline(in1, X);
    std::getline(in2, Y);

    
    if (!X.empty() && X.back() == '\r') X.pop_back();
    if (!Y.empty() && Y.back() == '\r') Y.pop_back();

    if (X.find(Y) != std::string::npos) {
        out << "yes";
    } else {
        out << "no";
    }

    return 0;
}

//3
#include <fstream>
#include <string>
#include <algorithm>

int divideByTwo(std::string& s) {
    std::string result;
    int carry = 0;
    for (char c : s) {
        int cur = carry * 10 + (c - '0');
        result.push_back(char('0' + cur / 2));
        carry = cur % 2;
    }
    // Убираем ведущие нули
    size_t pos = result.find_first_not_of('0');
    if (pos == std::string::npos) {
        s = "0";
    } else {
        s = result.substr(pos);
    }
    return carry;  // остаток от деления на 2 = текущий бит
}


std::string toBinary(const std::string& dec) {
    if (dec == "0") return "0";

    std::string num = dec;
    std::string bits;
    while (num != "0") {
        bits.push_back(char('0' + divideByTwo(num)));
    }
    std::reverse(bits.begin(), bits.end());
    return bits;
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if (!in.is_open() || !out.is_open()) {
        return 1;
    }

    std::string s;
    std::getline(in, s);

    // Убираем возможный '\r' (CRLF)
    if (!s.empty() && s.back() == '\r') s.pop_back();

    std::string result;
    result.reserve(s.size() * 4);  // грубая оценка, чтобы меньше реаллокаций

    size_t i = 0;
    while (i < s.size()) {
        if (s[i] >= '0' && s[i] <= '9') {
            // Собираем всё число целиком
            size_t j = i;
            while (j < s.size() && s[j] >= '0' && s[j] <= '9') ++j;
            std::string number = s.substr(i, j - i);
            result += toBinary(number);
            i = j;
        } else {
            result.push_back(s[i]);
            ++i;
        }
    }

    out << result;
    return 0;
}