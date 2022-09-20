#include <tests.hpp>

int main(int argc, char **argv){

	if(argc != 2)
		return 1;
	if(argv[1][0] == '1'){
		make_my_check_type_test();
		make_my_iterator_test();
		make_my_map_test();
		make_my_vector_test();
	}
}
