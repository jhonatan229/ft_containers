#include <tests.hpp>
#include <sys/time.h>

int main(int argc, char **argv)
{

	if (argc != 2)
		return 1;
	if (argv[1][0] == '1')
	{
		struct timeval tp;
		gettimeofday(&tp, NULL);
		long int mbefore = tp.tv_sec * 1000 + tp.tv_usec / 1000;
		make_my_check_type_test();
		make_my_iterator_test();
		make_my_map_test();
		make_my_vector_test();
		make_my_stack_test();
		make_my_perform_test();
		struct timeval after;
		gettimeofday(&after, NULL);
		long int mafter = after.tv_sec * 1000 + after.tv_usec / 1000;
		std::cout << "\033[1;32mTOTAL TIME: " << (mafter - mbefore) <<" miliseconds\033[0m" << std::endl;
	}
	else if (argv[1][0] == '2')
	{
		struct timeval tp;
		gettimeofday(&tp, NULL);
		long int mbefore = tp.tv_sec * 1000 + tp.tv_usec / 1000;
		make_stl_iterator_test();
		make_stl_map_test();
		make_stl_vector_test();
		make_stl_perform_test();
		struct timeval after;
		gettimeofday(&after, NULL);
		long int mafter = after.tv_sec * 1000 + after.tv_usec / 1000;
		std::cout << "\033[1;32mTOTAL TIME: " << (mafter - mbefore) <<" miliseconds\033[0m" << std::endl;
	}
}
