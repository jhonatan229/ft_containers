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
	std::map<std::string, int>third_map = second_map;
	EXPECT_EQ(third_map.size(), 1);
	EXPECT_EQ(third_map.begin()->first, "jun");
}
TEST(map_tests, test_insert) {
	std::map<std::string, int>my_map;
	
	my_map.insert(std::make_pair("j", 234));
	my_map.insert({"a", 23});
	my_map["b"] = 25;
	my_map.insert(std::make_pair("a", 23));
	// for (std::map<std::string, int>::iterator it = my_map.begin(); it != my_map.end();it++){
	// 	std::cout << "value " << it->first << "\n";
	// }
	EXPECT_EQ(my_map.size(), 3);
}

TEST(map_tests, test_insert_100_itens) {
	std::map<int, int>my_map;
	int i = 0;
	while(my_map.size() < 100){
		i = rand() % 100;
		my_map.insert({i, i});
	}
	// for (std::map<int, int>::iterator it = my_map.begin(); it != my_map.end();it++){
	// 	std::cout << "value " << it->first << "\n";
	// }
	EXPECT_EQ(my_map.size(), 100);
	EXPECT_EQ(my_map.begin()->first, 0);
	EXPECT_EQ(my_map.end()->first, 100);
}

TEST(map_tests, test_find_number) {
	std::map<int, int>my_map;
	int i = 0;
	int need_find = 0;
	while(my_map.size() < 100){
		i = rand() % 1000;
		need_find = i;
		my_map.insert({i, i});
	}
	EXPECT_EQ(my_map.find(need_find)->first, need_find);
	std::map<int, int>::iterator it;
	do
	{
		i = rand() % 1000;
		it = my_map.find(i);
	} while (it != my_map.end());
	EXPECT_EQ(it, my_map.end());
}

TEST(map_tests, test_erase_number) {
	std::map<int, int>my_map;
	int i = 0;
	while(my_map.size() < 100){
		i = rand() % 100;
		my_map.insert({i, i});
	}
	int resp = my_map.erase(42);
	EXPECT_EQ(my_map.find(42), my_map.end());
	EXPECT_EQ(my_map.size(), 99);
	EXPECT_EQ(resp, 1);
	resp = my_map.erase(435);
	EXPECT_EQ(resp, 0);
}

TEST(map_tests, test_clear_map) {
	std::map<int, int>my_map;
	int i = 0;
	while(my_map.size() < 100){
		i = rand() % 100;
		my_map.insert({i, i});
	}
	my_map.clear();
	EXPECT_TRUE(my_map.empty());
	EXPECT_EQ(my_map.size(), 0);
}

TEST(map_tests, test_swap) {
	std::map<char, int>my_map;
	std::map<char, int>second_map;
	my_map['a'] = 23;
	second_map['j'] = 43;
	my_map.swap(second_map);
	EXPECT_EQ(my_map.begin()->first, 'j');
	EXPECT_EQ(second_map.begin()->first, 'a');
}


TEST(map_tests, test_lower_upper_bound) {
	std::map<int, int>my_map;
	int i = 0;
	while(my_map.size() < 100){
		i = rand() % 100;
		my_map.insert({i, i});
	}
	std::map<int, int>::iterator it =  my_map.upper_bound(44);
	EXPECT_EQ(it->first, 45);
	it = my_map.lower_bound(42);
	EXPECT_EQ(it->first, 42);
}

TEST(map_tests, test_equal_range) {
	std::map<int, int>my_map;
	int i = 0;
	while(my_map.size() < 100){
		i = rand() % 100;
		my_map.insert({i, i});
	}
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> it = my_map.equal_range(42);
	EXPECT_EQ(it.first->first, 42);
	EXPECT_EQ(it.second->first, 43);
}