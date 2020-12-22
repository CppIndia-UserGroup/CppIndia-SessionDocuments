#include <iostream>
#include <calculator.h>
#include <gtest/gtest.h>

class CalculatorTest : public testing::Test
{
public:
	Calculator cal;
};

TEST_F(CalculatorTest, AdditionTest)
{
	EXPECT_EQ(cal.add(10, 20), 30);
	EXPECT_EQ(cal.subtract(10, 5), 5);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}