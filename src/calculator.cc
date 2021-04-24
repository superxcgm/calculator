#include "../include/calculator.h"
#include <tuple>
#include <optional>

static std::optional<std::tuple<int, int>> ReadOperand(const std::string &buffer, int start_pos) {
    int pos = start_pos;
    int ans = 0;
    while (pos != buffer.size()) {
        char ch = buffer[pos];
        if (ch >= '0' && ch <= '9') {
            ans = ans * 10 + (ch - '0');
            pos++;
        } else {
            return std::make_tuple(ans, pos);
        }
    }
    return std::make_tuple(ans, pos);
}

static const std::string int2string(int x) {
    std::string ans = "";
    bool negative = false;
    if (x < 0) {
        negative = true;
        x = -x;
    }
    while (x > 0) {
        ans.insert(ans.begin(), x % 10 + '0');
        x /= 10;
    }
    if (negative) {
        ans.insert(ans.begin(), '-');
    }
    return ans;
}

const std::string Calculator::Calculate(const std::string &expression_str) {
    auto op1_Optional = ReadOperand(expression_str, 0);
    auto [op1, pos] = *op1_Optional;
//    char opeartor = readOperator(expressionStr, pos);
    auto op2_Optional = ReadOperand(expression_str, pos + 1);
    int op2 = std::get<0>(*op2_Optional);

    return int2string(op1 + op2);
}
