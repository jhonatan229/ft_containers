#include <tests.hpp>

void make_my_stack_test()
{
	std::cout << "\033[1;32m>>>>>>>>>>>>TEST MY STACK<<<<<<<<<<<<<\033[0m" << std::endl;
	{
		std::cout << " - TEST STACK CONSTRUCTOR - " << std::endl;

		ft::stack<int, ft::vector<int> > my_stack;
		std::cout << "TEST #1 - " << ((my_stack.size() == 0) ? "✅" : "❌") << std::endl;

	}
	{
		std::cout << " - TEST STACK POP AND PUSH - " << std::endl;

		ft::vector<int> vec(5);
		ft::stack<int, ft::vector<int> > my_stack(vec);
		std::cout << "TEST #1 - " << ((my_stack.size() == 5) ? "✅" : "❌") << std::endl;
		my_stack.push(2);
		std::cout << "TEST #2 - " << ((my_stack.size() == 6) ? "✅" : "❌") << std::endl;
		my_stack.pop();
		std::cout << "TEST #3 - " << ((my_stack.size() == 5) ? "✅" : "❌") << std::endl;
	}
}
