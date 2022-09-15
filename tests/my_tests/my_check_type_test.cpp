#include <tests.hpp>

void make_my_check_type_test()
{
	std::cout << "TEST MY CHECK TYPE" << std::endl;
	std::cout << "TEST bool: ";
	std::cout << ((ft::is_integral<bool>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST char: ";
	std::cout << ((ft::is_integral<char>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST wchar_t: ";
	std::cout << ((ft::is_integral<wchar_t>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST signed char: ";
	std::cout << ((ft::is_integral<signed char>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST short int: ";
	std::cout << ((ft::is_integral<short int>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST int: ";
	std::cout << ((ft::is_integral<int>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST long int: ";
	std::cout << ((ft::is_integral<long int>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST long long int: ";
	std::cout << ((ft::is_integral<long long int>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST unsigned char: ";
	std::cout << ((ft::is_integral<unsigned char>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST unsigned short int: ";
	std::cout << ((ft::is_integral<unsigned short int>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST unsigned int: ";
	std::cout << ((ft::is_integral<unsigned int>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST unsigned long int: ";
	std::cout << ((ft::is_integral<unsigned long int>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
	std::cout << "TEST unsigned long long int: ";
	std::cout << ((ft::is_integral<unsigned long long int>::value == true) ? "✅" : "❌");
	std::cout << std::endl;
}