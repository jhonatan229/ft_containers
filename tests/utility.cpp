#include "utility.hpp"

TEST(teste, teste){
	pair<int, int> test = ft::make_pair(23, 43);
	EXPECT_EQ(test.first, 23)
}
