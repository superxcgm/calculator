#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../include/calculator.h"

TEST(PlaceholderTest, ShouldReturn2When1Plus1) {
    EXPECT_EQ("2", Calculator::calculate("1+1"));
}
