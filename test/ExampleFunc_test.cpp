#include "../ExampleFunc.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <filesystem>

TEST(TestExample, ExampleFunc_test)
{
    EXPECT_EQ(2, ExampleFunc(1, 1));
    std::cout << " Test finished in directory: " << std::filesystem::current_path() << std::endl;
}