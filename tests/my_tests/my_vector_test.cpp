#include <gtest/gtest.h>
#include "../containers/vector.hpp"

TEST(vector_tests, testing_constructor) {
	ft::vector<int>my_vec;
	EXPECT_EQ(my_vec.size(), 0);
	EXPECT_EQ(my_vec.capacity(), 0);
}

TEST(vector_tests, testing_constructor_with_param) {
	ft::vector<int> vec1(5);
	ft::vector<std::string> vec2(5, "fill");

	EXPECT_EQ(vec1.size(), 5);
	EXPECT_EQ(vec1.capacity(), 5);
	for(ft::vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++)
		EXPECT_EQ(*it, 0);

	EXPECT_EQ(vec2.size(), 5);
	EXPECT_EQ(vec2.capacity(), 5);
	for(ft::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
		EXPECT_EQ(*it, "fill");
}

TEST(vector_tests, testing_equal_operator) {
	int array1[] = {1, 2, 3, 4, 5};
	std::string array2[] = { "one", "two", "three", "four", "five"};

	ft::vector<int> vec1(array1, array1 + 5);
	ft::vector<std::string> vec2(array2, array2 + 5);

	ft::vector<int> vec3 = vec1;
	ft::vector<std::string> vec4 = vec2;

	EXPECT_EQ(vec3.size(), 5);
	EXPECT_EQ(vec3.capacity(), 5);
	for (int i  = 0; i < 5; i++)
		EXPECT_EQ(vec3[i], array1[i]);
		
	EXPECT_EQ(vec4.size(), 5);
	EXPECT_EQ(vec4.capacity(), 5);
	for (int i  = 0; i < 5; i++)
		EXPECT_EQ(vec4[i], array2[i]);
}
TEST(vector_tests, testing_copy_operator) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);

	ft::vector<std::string> vec2(vec1);
		
	EXPECT_EQ(vec2.size(), 5);
	EXPECT_EQ(vec2.capacity(), 5);
	for (int i  = 0; i < 5; i++)
		EXPECT_EQ(vec2[i], array1[i]);
}

TEST(vector_tests, testing_get_positions) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);	
	EXPECT_EQ(vec1[0], "one");
	EXPECT_EQ(vec1.capacity(), 5);
	EXPECT_EQ(vec1.at(1), "two");
	EXPECT_EQ(vec1.front(), "one");
	EXPECT_EQ(vec1.back(), "five");
}
TEST(vector_tests, testing_push_back) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);	
	vec1.push_back("six");
	EXPECT_EQ(*(vec1.end() - 1), "six");
	EXPECT_EQ(vec1.size(), 6);	
}
TEST(vector_tests, testing__pop_back) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);	
	vec1.pop_back();
	EXPECT_EQ(vec1.size(), 4);
	
}
TEST(vector_tests, test_assign) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);	
	ft::vector<std::string> vec2(array1, array1 + 3);
	vec1.assign(4, "val");
	for (size_t i = 0; i < vec1.size();i++){
		EXPECT_EQ(vec1[i], "val");
	}
	vec1.assign(vec2.begin(), vec2.end());
	EXPECT_EQ(vec1.size(), 3);
}

TEST(vector_tests, test_insert) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);
	vec1.insert(vec1.begin() + 2, "ola");

	EXPECT_EQ(vec1.size(), 6);
	EXPECT_EQ(vec1[2], "ola");
}

TEST(vector_tests, test_erase) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);
	EXPECT_EQ(vec1.size(), 5);
	vec1.erase(vec1.begin(), vec1.end());
	EXPECT_EQ(vec1.size(), 0);
	vec1.assign(3, "val");
	vec1.erase(vec1.begin() + 1);
	EXPECT_EQ(vec1.size(), 2);

}
TEST(vector_tests, test_swap) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);
	ft::vector<std::string> vec2;
	vec2.assign(3, "val");
	vec1.swap(vec2);
	EXPECT_EQ(vec1.size(), 3);
	EXPECT_EQ(vec2.size(), 5);
}
TEST(vector_tests, test_clear) {
	std::string array1[] = { "one", "two", "three", "four", "five"};

	ft::vector<std::string> vec1(array1, array1 + 5);
	EXPECT_EQ(vec1.size(), 5);
	vec1.clear();
	EXPECT_EQ(vec1.size(), 0);
}

