#include <gtest/gtest.h>

#include "src/calculator.h"


// Note : not all tests are here on purpose to illustrate code coverage


void test_addition(int const p_a, int const p_b)
{
    int result = add(p_a, p_b);
    ASSERT_EQ(result, p_a + p_b) << "Error: " << p_a << " + " << p_b << " == " << p_a+p_b << " and not " << result << "\n";
}

TEST(test_calculator_add, Test1)
{
    test_addition(5, 3);
    test_addition(15, 23);
}

TEST(test_calculator_add, SommeZero)
{
    test_addition(0, 1);
    test_addition(1, 0);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
