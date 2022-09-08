#include <gtest/gtest.h>
#include "../containers/ stack.hpp"
#include "../containers/ vector.hpp"

TEST(stack_tests, testing_constructor) {
	ft::stack<int, ft::vector<int>>my_vec;
	EXPECT_EQ(my_vec.size(), 0);
}

TEST(stack_tests, testing_constructor_with_param) {
	ft::vector<int> vec(5);
	ft::stack<int, ft::vector<int>>my_stack(vec);

	EXPECT_EQ(my_stack.size(), 5);
	EXPECT_TRUE(my_stack.empty());

}

TEST(stack_tests, testing_functions) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<int> vec(array1, array1 + 5);
	ft::stack<int, ft::vector<int>>my_stack(vec);
	EXPECT_EQ(my_stack., "one");
}
TEST(stack_tests, testing_push_back_pop_back) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::stack<std::string> vec1(array1, array1 + 5);	
	vec1.push_back("six");
	EXPECT_EQ(*(vec1.end() - 1), "six");
	EXPECT_EQ(vec1.size(), 6);
	vec1.pop_back();
	EXPECT_EQ(*(vec1.end() - 1), "five");
	EXPECT_EQ(vec1.size(), 5);
	
}
TEST(stack_tests, test_assign) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::stack<std::string> vec1(array1, array1 + 5);	
	ft::stack<std::string> vec2(array1, array1 + 3);
	vec1.assign(4, "val");
	for (size_t i = 0; i < vec1.size();i++){
		EXPECT_EQ(vec1[i], "val");
	}
	vec1.assign(vec2.begin(), vec2.end());
	EXPECT_EQ(vec1.size(), 3);
}

TEST(stack_tests, test_insert) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::stack<std::string> vec1(array1, array1 + 5);
	vec1.insert(vec1.begin() + 2, "ola");

	EXPECT_EQ(vec1.size(), 6);
	EXPECT_EQ(vec1[2], "ola");
}

TEST(stack_tests, test_erase) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::stack<std::string> vec1(array1, array1 + 5);
	EXPECT_EQ(vec1.size(), 5);
	vec1.erase(vec1.begin(), vec1.end());
	EXPECT_EQ(vec1.size(), 0);
	vec1.assign(3, "val");
	vec1.erase(vec1.begin() + 1);
	EXPECT_EQ(vec1.size(), 2);

}
TEST(stack_tests, test_swap) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::stack<std::string> vec1(array1, array1 + 5);
	ft::stack<std::string> vec2;
	vec2.assign(3, "val");
	vec1.swap(vec2);
	EXPECT_EQ(vec1.size(), 3);
	EXPECT_EQ(vec2.size(), 5);
}
TEST(stack_tests, test_clear) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::stack<std::string> vec1(array1, array1 + 5);
	EXPECT_EQ(vec1.size(), 5);
	vec1.clear();
	EXPECT_EQ(vec1.size(), 0);
}

