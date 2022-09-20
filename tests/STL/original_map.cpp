#include <tests.hpp>

void make_stl_map_test()
{

	std::cout << "\033[1;32m>>>>>>>>>>>>TEST STL MAP<<<<<<<<<<<<<\033[0m" << std::endl;
	{
		std::map<std::string, int> my_map;
		std::cout << " - TEST MAP CONSTRUCTOR - " << std::endl;
		std::cout << "TEST #2 - " << ((my_map.size() == 0) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #3 - " << ((my_map.empty()) ? "✅" : "❌") << std::endl;
		my_map.insert(std::make_pair("jun", 3));
		std::map<std::string, int> second_map(my_map);
		std::cout << "TEST #4 - " << ((second_map.size() == 1) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #5 - " << ((second_map.begin()->first == "jun") ? "✅" : "❌") << std::endl;
		std::map<std::string, int> third_map = second_map;
		std::cout << "TEST #6 - " << ((third_map.size() == 1) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #7 - " << ((third_map.begin()->first == "jun") ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST MAP INSERT - " << std::endl;
		std::map<std::string, int> my_map;

		my_map.insert(std::make_pair("j", 234));
		my_map.insert(std::make_pair("a", 23));
		my_map["b"] = 25;
		my_map.insert(std::make_pair("a", 23));
		std::cout << "TEST #1 - " << ((my_map.size() == 3) ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST MAP INSERT (100 RANDOM ITENS) - " << std::endl;
		std::map<int, int> my_map;
		int i = 0;
		while (my_map.size() < 100)
		{
			i = rand() % 100;
			my_map.insert(std::make_pair(i, i));
		}
		std::cout << "TEST #1 - " << ((my_map.size() == 100) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((my_map.begin()->first == 0) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #3 - " << ((my_map.end()->first == 100) ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST MAP FIND NUMBERS - " << std::endl;
		std::map<int, int> my_map;
		int i = 0;
		int need_find = 0;
		while (my_map.size() < 100)
		{
			i = rand() % 1000;
			need_find = i;
			my_map.insert(std::make_pair(i, i));
		}
		std::cout << "TEST #1 - " << ((my_map.find(need_find)->first == need_find) ? "✅" : "❌") << std::endl;
		std::map<int, int>::iterator it;
		do
		{
			i = rand() % 1000;
			it = my_map.find(i);
		} while (it != my_map.end());
		std::cout << "TEST #2 - " << ((it == my_map.end()) ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST MAP ERASE NUMBERS - " << std::endl;
		std::map<int, int> my_map;
		int i = 0;
		while (my_map.size() < 100000)
		{
			i = rand() % 100000;
			my_map.insert(std::make_pair(i, i));
		}
		int resp = my_map.erase(34255);
		std::cout << "TEST #1 - " << ((my_map.find(34255) == my_map.end()) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((my_map.size() == 99999) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #3 - " << ((resp == 1) ? "✅" : "❌") << std::endl;
		resp = my_map.erase(222222345);
		std::cout << "TEST #4 - " << ((resp == 0) ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST MAP CLEAR TREE - " << std::endl;
		std::map<int, int> my_map;
		int i = 0;
		while (my_map.size() < 100)
		{
			i = rand() % 100;
			my_map.insert(std::make_pair(i, i));
		}
		my_map.clear();
		std::cout << "TEST #1 - " << ((my_map.empty()) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((my_map.size() == 0) ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST MAP SWAP - " << std::endl;
		std::map<char, int> my_map;
		std::map<char, int> second_map;
		my_map['a'] = 23;
		second_map['j'] = 43;
		my_map.swap(second_map);
		std::cout << "TEST #1 - " << ((my_map.begin()->first == 'j') ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((second_map.begin()->first == 'a') ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST MAP LOWER AND UPPER BOUND - " << std::endl;
		std::map<int, int> my_map;
		int i = 0;
		while (my_map.size() < 100)
		{
			i = rand() % 100;
			my_map.insert(std::make_pair(i, i));
		}
		std::map<int, int>::iterator it = my_map.upper_bound(44);
		std::cout << "TEST #1 - " << ((it->first == 45) ? "✅" : "❌") << std::endl;
		it = my_map.lower_bound(42);
		std::cout << "TEST #2 - " << ((it->first == 42) ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST MAP EQUAL RANGE - " << std::endl;
		std::map<int, int> my_map;
		int i = 0;
		while (my_map.size() < 100)
		{
			i = rand() % 100;
			my_map.insert(std::make_pair(i, i));
		}
		std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> it = my_map.equal_range(42);
		std::cout << "TEST #1 - " << ((it.first->first == 42) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((it.second->first == 43) ? "✅" : "❌") << std::endl;
	}
}
