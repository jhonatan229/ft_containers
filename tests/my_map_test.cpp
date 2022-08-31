#include <gtest/gtest.h>
#include "../containers/ft_map.hpp"

TEST(map_tests, testing_constructor) {
	ft::map<std::string, int>my_map;
	EXPECT_EQ(my_map.size(), 0);
}