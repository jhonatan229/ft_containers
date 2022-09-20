#include <tests.hpp>

void make_my_perform_test()
{
	std::cout << "\033[1;32m>>>>>>>>>>>>TEST PERFORMANCE CONTAINERS<<<<<<<<<<<<<\033[0m" << std::endl;

	{
		std::cout << " - TEST MAP WITH 1000000 - " << std::endl;
		ft::map<int, int> my_map;
		ft::map<int, int> second_map;
		int i = 0;
		while (my_map.size() < 1000000)
		{
			i = rand() % 1000000;
			my_map.insert(ft::make_pair(i, i));
		}
		second_map = my_map;
		std::cout << "TEST #1 - " << ((my_map.size() == 1000000) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((my_map.begin()->first == 0) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #3 - " << ((my_map.end()->first == 0) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #4 - " << ((second_map.size() == 1000000) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #5 - " << ((second_map.begin()->first == 0) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST MAP erase into 1000000 itens - " << std::endl;
		ft::map<int, int> my_map;
		int i = 0;
		while (my_map.size() < 1000000)
		{
			i = rand() % 1000000;
			my_map.insert(ft::make_pair(i, i));
		}
		std::cout << "TEST #1 - " << ((my_map.erase(233454)) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((my_map.size() == 999999) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST MAP find into 1000000 itens - " << std::endl;
		ft::map<int, int> my_map;
		int i = 0;
		while (my_map.size() < 1000000)
		{
			i = rand() % 1000000;
			my_map.insert(ft::make_pair(i, i));
		}
		std::cout << "TEST #1 - " << ((my_map.find(453456)->first == 453456) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST MAP clear 1000000 itens - " << std::endl;
		ft::map<int, int> my_map;
		int i = 0;
		while (my_map.size() < 1000000)
		{
			i = rand() % 1000000;
			my_map.insert(ft::make_pair(i, i));
		}
		my_map.clear();
		std::cout << "TEST #1 - " << ((my_map.size() == 0) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR INSERT 1000000 itens - " << std::endl;
		ft::vector<int> my_vector;
		int i = 0;
		while (my_vector.size() < 1000000)
		{
			my_vector.push_back(i++);
		}
		std::cout << "TEST #1 - " << ((my_vector.size() == 1000000) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR CLEAR 1000000 itens - " << std::endl;
		ft::vector<int> my_vector;
		int i = 0;
		while (my_vector.size() < 1000000)
		{
			my_vector.push_back(i++);
		}
		std::cout << "TEST #1 - " << ((my_vector.size() == 1000000) ? "✅" : "❌") << std::endl;
		while (my_vector.size() > 0)
		{
			my_vector.pop_back();
		}
		std::cout << "TEST #1 - " << ((my_vector.size() == 0) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #1 - " << ((my_vector.empty()) ? "✅" : "❌") << std::endl;
	}
}