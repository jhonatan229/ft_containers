#include <gtest/gtest.h>
#include "../includes/check_type.hpp"

TEST(check_type, Test_all_types)
{
	EXPECT_TRUE(ft::is_integral<bool>::value == true);
	EXPECT_TRUE(ft::is_integral<char>::value == true);
	EXPECT_TRUE(ft::is_integral<wchar_t>::value == true);
	EXPECT_TRUE(ft::is_integral<signed char>::value == true);
	EXPECT_TRUE(ft::is_integral<short int>::value == true);
	EXPECT_TRUE(ft::is_integral<int>::value == true);
	EXPECT_TRUE(ft::is_integral<long int>::value == true);
	EXPECT_TRUE(ft::is_integral<long long int>::value == true);
	EXPECT_TRUE(ft::is_integral<unsigned char>::value == true);
	EXPECT_TRUE(ft::is_integral<unsigned short int>::value == true);
	EXPECT_TRUE(ft::is_integral<unsigned int>::value == true);
	EXPECT_TRUE(ft::is_integral<unsigned long int>::value == true);
	EXPECT_TRUE(ft::is_integral<unsigned long long int>::value == true);
}