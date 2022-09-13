#include <gtest/gtest.h>
#include <stack.hpp>
#include <vector.hpp>
#include <map.hpp>

TEST(performace_map, test_insert_1000000_itens) {
	std::map<int, int>my_map;
	std::map<int, int>second_map;
	int i = 0;
	while(my_map.size() < 1000000){
		i = rand() % 1000000;
		my_map.insert({i, i});
	}
	second_map = my_map;
	EXPECT_EQ(my_map.size(), 1000000);
	EXPECT_EQ(my_map.begin()->first, 0);
	EXPECT_EQ(my_map.end()->first, 1000000);
	EXPECT_EQ(second_map.size(), 1000000);
	EXPECT_EQ(second_map.begin()->first, 0);
	EXPECT_EQ(second_map.end()->first, 1000000);
}
TEST(performace_map, test_delete_into_1000000_itens) {
	std::map<int, int>my_map;
	int i = 0;
	while(my_map.size() < 1000000){
		i = rand() % 1000000;
		my_map.insert({i, i});
	}
	EXPECT_TRUE(my_map.erase(233454));
	EXPECT_EQ(my_map.size(), 999999);
}
TEST(performace_map, test_find_into_1000000_itens) {
	std::map<int, int>my_map;
	int i = 0;
	while(my_map.size() < 1000000){
		i = rand() % 1000000;
		my_map.insert({i, i});
	}
	EXPECT_EQ(my_map.find(453456)->first, 453456);
}
TEST(performace_map, test_clear_into_1000000_itens) {
	std::map<int, int>my_map;
	int i = 0;
	while(my_map.size() < 1000000){
		i = rand() % 1000000;
		my_map.insert({i, i});
	}
	my_map.clear();
	EXPECT_EQ(my_map.size(),0);
}
TEST(performace_vecto, test__1000000_itens) {
	std::vector<int>my_vector;

	int i = 0;
	while(my_vector.size() < 1000000){
		my_vector.push_back(i++);
	}
	EXPECT_EQ(my_vector.size(),1000000);
}
TEST(performace_vecto, test_clear_1000000_itens) {
	std::vector<int>my_vector;

	int i = 0;
	while(my_vector.size() < 1000000){
		my_vector.push_back(i++);
	}
	EXPECT_EQ(my_vector.size(),1000000);
	while(my_vector.size() > 0){
		my_vector.pop_back();
	}
	EXPECT_EQ(my_vector.size(),0);
	EXPECT_TRUE(my_vector.empty());
}