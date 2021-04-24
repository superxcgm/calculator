#include "../include/calculator.h"
#include <tuple>
#include <optional>

static std::optional<std::tuple<int, int>> ReadOperand(const std::string &buffer, int start_pos) {
    int pos = start_pos;
    int ans = 0;
    bool haveValue = false;
    bool negative = false;
    while (pos != buffer.size() && buffer[pos] == ' ')
        pos++;
    while (pos != buffer.size()) {
        char ch = buffer[pos];
        if (ch >= '0' && ch <= '9') {
            haveValue = true;
            ans = ans * 10 + (ch - '0');
        } else if (ch == '-' && !haveValue) {
            negative = true;
        } else if (haveValue) {
            return std::make_tuple(negative ? ans * -1 : ans, pos);
        } else {
            return std::nullopt;
        }
        pos++;
    }
    return std::make_tuple(negative ? ans * -1 : ans, pos);
}

static std::optional<std::tuple<char, int>> ReadOperator(const std::string &buffer, int start_pos) {
    int pos = start_pos;
    while (pos != buffer.size() && buffer[pos] == ' ')
        pos++;
    if (std::string("+-*/").find(buffer[pos]) == std::string::npos) {
        return std::nullopt;
    }
    return std::make_tuple(buffer[pos], pos + 1);
}

static const std::string Int2String(int x) {
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

static std::optional<int> operate(int op1, char c_operator, int op2) {
    switch (c_operator) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            if (op2 == 0) {
                return std::nullopt;
            }
            return op1 / op2;
    }
}

static const std::string PARSE_ERROR = "parse error";

const std::string Calculator::Calculate(const std::string &expression_str) {
    // Todo: 这里option的处理看起来很丑，看能不能优化
    auto op1_opt = ReadOperand(expression_str, 0);
    if (!op1_opt.has_value()) {
        return PARSE_ERROR;
    }
    auto[op1, pos] = *op1_opt;
    auto operator_opt = ReadOperator(expression_str, pos);
    if (!operator_opt.has_value()) {
        return PARSE_ERROR;
    }
    auto c_opeartor = std::get<0>(*operator_opt);
    auto op2_opt = ReadOperand(expression_str, std::get<1>(*operator_opt));
    if (!op2_opt.has_value()) {
        return PARSE_ERROR;
    }
    int op2 = std::get<0>(*op2_opt);
    auto result_opt = operate(op1, c_opeartor, op2);
    if (!result_opt.has_value()) {
        return "Divide by zero";
    }
    return Int2String(*result_opt);
}
