#include <tests.hpp>

int main(int argc, char **argv)
{

	if (argc != 2)
		return 1;
	if (argv[1][0] == '1')
	{
		// time_t now = time(nullptr);
		// time_t mnow = now * 1000;
		make_my_check_type_test();
		make_my_iterator_test();
		make_my_map_test();
		make_my_vector_test();
		make_my_stack_test();
		make_my_perform_test();
		// time_t before = time(nullptr);
		// time_t mbefore = before * 1000;
		// std::cout << "\033[1;32mTOTAL TIME: " << (mbefore - mnow) <<"\033[0m" << std::endl;
	}
	else if (argv[1][0] == '2')
	{
		make_stl_iterator_test();
		make_stl_map_test();
		make_stl_vector_test();
		make_stl_perform_test();
	}
}
