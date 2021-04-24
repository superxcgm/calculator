#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../include/calculator.h"

TEST(CalculatorTest, ShouldReturn2When1Plus1) {
    EXPECT_EQ("2", Calculator::Calculate("1+1"));
}

TEST(CalculatorTest, ShouldReturn3When1Plus2) {
    EXPECT_EQ("3", Calculator::Calculate("1+2"));
}
