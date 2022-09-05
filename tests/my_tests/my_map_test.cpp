#include <gtest/gtest.h>
#include "../containers/ft_map.hpp"

TEST(map_tests, testing_constructor) {
	ft::map<std::string, int>my_map;
	EXPECT_EQ(my_map.size(), 0);
	EXPECT_TRUE(my_map.empty());
	my_map.insert(ft::make_pair("jun", 3));
	ft::map<std::string, int>second_map(my_map);
	EXPECT_EQ(second_map.size(), 1);
	EXPECT_EQ(second_map.begin()->first, "jun");
	ft::map<std::string, int>third_map = second_map;
	EXPECT_EQ(third_map.size(), 1);
	EXPECT_EQ(third_map.begin()->first, "jun");
}
TEST(map_tests, test_insert) {
	ft::map<std::string, int>my_map;
	
	my_map.insert(ft::make_pair("j", 234));
	my_map.insert(ft::make_pair("a", 23));
	my_map["b"] = 25;
	my_map.insert(ft::make_pair("a", 23));
	// for (ft::map<std::string, int>::iterator it = my_map.begin(); it != my_map.end();it++){
	// 	std::cout << "value " << it->first << "\n";
	// }
	EXPECT_EQ(my_map.size(), 3);
}   