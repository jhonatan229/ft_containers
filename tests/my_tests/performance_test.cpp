#include <gtest/gtest.h>
#include <stack.hpp>
#include <vector.hpp>
#include <map.hpp>
#include <utility.hpp>

TEST(performace_map, test_insert_1000000_itens)
{
	ft::map<int, int> my_map;
	ft::map<int, int> second_map;
	int i = 0;
	while (my_map.size() < 1000000)
	{
		i = rand() % 1000000;
		my_map.insert({i, i});
	}
	second_map = my_map;
	EXPECT_EQ(my_map.size(), 1000000);
	EXPECT_EQ(my_map.begin()->first, 0);
	EXPECT_EQ(my_map.end()->first, 0);
	EXPECT_EQ(second_map.size(), 1000000);
	EXPECT_EQ(second_map.begin()->first, 0);
	EXPECT_EQ(second_map.end()->first, 0);
}

TEST(performace_map, test_find_into_1000000_itens)
{
	ft::map<int, int> my_map;
	ft::map<int, int> second_map;
	int i = 0;
	while (my_map.size() < 1000000)
	{
		i = rand() % 1000000;
		my_map.insert({i, i});
	}
	ft::map<int, int>::iterator result = my_map.find(45365);
	EXPECT_EQ(result->first, 45365);
}

TEST(performace_map, test_delete_and_erase_into_1000000_itens)
{
	ft::map<int, int> my_map;
	ft::map<int, int> second_map;
	int i = 0;
	while (my_map.size() < 1000000)
	{
		i = rand() % 1000000;
		my_map.insert({i, i});
	}
	size_t result = my_map.erase(45365);
	EXPECT_TRUE(result);
	my_map.clear();
	EXPECT_EQ(my_map.size(), 0);
}

TEST(performace_vector, test_insert_1000000_itens)
{
	ft::vector<int> my_vector;
	ft::vector<int> second_vector;
	int i = 0;
	while (my_vector.size() < 1000000)
	{
		my_vector.push_back(i++);
	}
	second_vector = my_vector;
	EXPECT_EQ(my_vector.size(), 1000000);
	EXPECT_EQ(my_vector[0], 0);
	EXPECT_EQ(second_vector.size(), 1000000);
	EXPECT_EQ(second_vector[0], 0);
}

TEST(performace_vector, test_insert_and_delete_1000000_itens)
{
	ft::vector<int> my_vector;
	ft::vector<int> second_vector;
	int i = 0;
	while (my_vector.size() < 1000000)
	{
		my_vector.push_back(i++);
	}
	second_vector = my_vector;
	while (my_vector.size() != 0)
	{
		my_vector.pop_back();
	}
	EXPECT_EQ(my_vector.size(), 0);
	EXPECT_EQ(second_vector.size(), 1000000);
	EXPECT_EQ(second_vector[0], 0);
}

TEST(performace_vector, test_find_into_1000000_itens)
{
	ft::vector<int> my_vector;
	ft::vector<int> second_vector;
	int i = 0;
	while (my_vector.size() < 1000000)
	{
		my_vector.push_back(i++);
	}
	int result = my_vector.at(45365);
	EXPECT_EQ(result, 45365);
}

TEST(performace_stack, test_insert_1000000_itens)
{
	ft::stack<int, ft::vector<int>> my_stack;
	ft::stack<int, ft::vector<int>> second_stack;
	int i = 0;
	while (my_stack.size() < 1000000)
	{
		my_stack.push(i++);
	}
	second_stack = my_stack;
	EXPECT_EQ(my_stack.size(), 1000000);
	EXPECT_EQ(second_stack.size(), 1000000);
}

TEST(performace_stack, test_insert_and_delete_1000000_itens)
{
	ft::stack<int, ft::vector<int>> my_stack;
	ft::stack<int, ft::vector<int>> second_stack;
	int i = 0;
	while (my_stack.size() < 1000000)
	{
		my_stack.push(i++);
	}
	second_stack = my_stack;
	while (my_stack.size() != 0)
	{
		my_stack.pop();
	}
	EXPECT_EQ(my_stack.size(), 0);
	EXPECT_EQ(second_stack.size(), 1000000);
}
