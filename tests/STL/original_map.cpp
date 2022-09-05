#include <gtest/gtest.h>
#include <map>

TEST(map_tests, testing_constructor) {
	std::map<std::string, int>my_map;
	EXPECT_EQ(my_map.size(), 0);
	EXPECT_TRUE(my_map.empty());
	my_map.insert(std::make_pair("jun", 3));
	std::map<std::string, int>second_map(my_map);
	EXPECT_EQ(second_map.size(), 1);
	EXPECT_EQ(second_map.begin()->first, "jun");
}

TEST(map_tests, test_insert) {
	std::map<std::string, int>my_map;
	
	my_map.insert(std::make_pair("j", 234));
	my_map.insert(std::make_pair("a", 23));
	my_map["b"] = 25;
	my_map.insert(std::make_pair("a", 23));
	// for (std::map<std::string, int>::iterator it = my_map.begin(); it != my_map.end();it++){
	// 	std::cout << "value " << it->first << "\n";
	// }
	EXPECT_EQ(my_map.size(), 3);
}   