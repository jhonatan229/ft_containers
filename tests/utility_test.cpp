#include <gtest/gtest.h>
#include "../includes/utility.hpp"

TEST(utility_test, testing_constructors) {
	ft::pair<int, char> test(3, 'c');
	EXPECT_EQ(test.first, 3);
}