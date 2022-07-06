#include <gtest/gtest.h>
#include <ft_iterator.hpp>

typedef ft::random_access_iterator<int *> iterator;
int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int array2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
iterator it(array1);

TEST(Test_my_iterator, first_position)
{
	EXPECT_EQ(*it, 1);
}

TEST(Test_my_iterator, testing_plus_operation)
{
	EXPECT_EQ(*it.operator+(1), 2);
}

TEST(Test_my_iterator, testing_minus_operation)
{
	it = it.operator+(1);
	EXPECT_EQ(*it.operator-(1), 1);
}

TEST(Test_my_iterator, testing_plusplus_operation)
{
	it++;
	EXPECT_EQ(*it, 3);
}

TEST(Test_my_iterator, testing_minusminus_operation)
{
	it--;
	EXPECT_EQ(*it, 2);
}

TEST(Test_my_iterator, testing_plusequal_operation)
{
	it+= 1;
	EXPECT_EQ(*it, 3);
}

TEST(Test_my_iterator, testing_minusequal_operation)
{
	it-= 1;
	EXPECT_EQ(*it, 2);
}

TEST(Test_my_iterator, testing_sum_operation)
{
	it = it + 2;
	EXPECT_EQ(*it, 4);
}

TEST(Test_my_iterator, testing_if_is_equal)
{
	EXPECT_EQ((*it == 4), true);
}

TEST(Test_my_iterator, testing_if_is_bigger)
{
	EXPECT_EQ((*it > 2), true);
}

TEST(Test_my_iterator, testing_if_is_smalest)
{
	EXPECT_EQ((*it < 7), true);
}

TEST(Test_my_iterator, testing_if_is_different)
{
	EXPECT_EQ((*it != 5), true);
}





