#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../include/calculator.h"

const std::string PARSE_ERROR = "parse error";

TEST(CalculatorTest, ShouldReturn2When1Plus1) {
    EXPECT_EQ("2", Calculator::Calculate("1+1"));
}

TEST(CalculatorTest, ShouldReturn3When1Plus2) {
    EXPECT_EQ("3", Calculator::Calculate("1+2"));
}

TEST(CalculatorTest, ShouldReturn1When2Substract1) {
    EXPECT_EQ("1", Calculator::Calculate("2-1"));
}

TEST(CalculatorTest, ShouldReturn6When2Multiply3) {
    EXPECT_EQ("6", Calculator::Calculate("2*3"));
}

TEST(CalculatorTest, ShouldReturn3When6Div2) {
    EXPECT_EQ("3", Calculator::Calculate("6/2"));
}

TEST(CalculatorTest, ShouldComplainWhenDiv0) {
    EXPECT_EQ("Divide by zero", Calculator::Calculate("6/0"));
}

TEST(CalculatorTest, ShouldIgnoreExtraSpaces) {
    EXPECT_EQ("2", Calculator::Calculate(" 1 + 1 "));
}

TEST(CalculatorTest, ShouldComplainWhenOp1Invalid) {
    EXPECT_EQ(PARSE_ERROR, Calculator::Calculate("*"));
}

TEST(CalculatorTest, ShouldComplainWhenOp2Invalid) {
    EXPECT_EQ(PARSE_ERROR, Calculator::Calculate("1+*"));
}

TEST(CalculatorTest, ShouldComplainWhenOperatorInvalid) {
    EXPECT_EQ(PARSE_ERROR, Calculator::Calculate("1$2"));
}

TEST(CalculatorTest, ShouldReturn2WhenMinus4Plus6) {
    EXPECT_EQ("2", Calculator::Calculate("-4+6"));
}

TEST(CalculatorTest, ShouldReturn2When6PlusMinus4) {
    EXPECT_EQ("2", Calculator::Calculate("6+-4"));
}