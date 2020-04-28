#include "../ExampleFunc.hpp"
#include <gtest/gtest.h>

TEST(TestExample, ExampleFunc_test)
{
    EXPECT_EQ(2, ExampleFunc(1, 1));
}