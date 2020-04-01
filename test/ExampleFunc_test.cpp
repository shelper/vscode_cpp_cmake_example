#include "../ExampleFunc.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(TestExample, ExampleFunc_test)
{
    EXPECT_EQ(2, ExampleFunc(1, 1));
    std::cout << " test finished ";
}