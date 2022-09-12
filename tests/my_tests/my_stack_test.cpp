#include <gtest/gtest.h>
#include "../containers/stack.hpp"
#include "../containers/vector.hpp"

TEST(stack_tests, testing_constructor) {
	ft::stack<int, ft::vector<int>>my_vec;
	EXPECT_EQ(my_vec.size(), 0);
}

TEST(stack_tests, testing_constructor_with_param) {
	ft::vector<int> vec(5);
	ft::stack<int, ft::vector<int>>my_stack(vec);

	EXPECT_EQ(my_stack.size(), 5);
	EXPECT_FALSE(my_stack.empty());

}
