#include <gtest/gtest.h>
#include "../containers/ft_vector.hpp"

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
}

