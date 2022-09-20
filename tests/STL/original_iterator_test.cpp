#include <tests.hpp>

void make_stl_iterator_test()
{
	std::cout << "\033[1;32m>>>>>>>>>>>>TEST STL ITERATOR<<<<<<<<<<<<<\033[0m" << std::endl;
	{

		std::cout << " - ITERATOR INCREMENT - " << std::endl;
		int ar[] = {1, 2, 3, 4, 5};
		std::vector<int> vec(ar, ar + 5);
		std::vector<int>::iterator it = vec.begin();

		std::cout << "TEST #1 - " << ((*it == 1) ? "✅" : "❌") << std::endl;
		++it;
		std::cout << "TEST #2 - " << ((*it == 2) ? "✅" : "❌") << std::endl;
		it++;
		std::cout << "TEST #3 - " << ((*it == 3) ? "✅" : "❌") << std::endl;
		++it;
		std::cout << "TEST #4 - " << ((*it == 4) ? "✅" : "❌") << std::endl;
		it++;
		std::cout << "TEST #5 - " << ((*it == 5) ? "✅" : "❌") << std::endl;

		std::cout << " - ITERATOR DECREMENT - " << std::endl;
		--it;
		std::cout << "TEST #1 - " << ((*it == 4) ? "✅" : "❌") << std::endl;
		it--;
		std::cout << "TEST #2 - " << ((*it == 3) ? "✅" : "❌") << std::endl;
		--it;
		std::cout << "TEST #3 - " << ((*it == 2) ? "✅" : "❌") << std::endl;
		it--;
		std::cout << "TEST #4 - " << ((*it == 1) ? "✅" : "❌") << std::endl;
	}

	{
		int ar[] = {1, 2, 3, 4, 5};
		std::vector<int> vec(ar, ar + 5);
		std::vector<int>::iterator it = vec.begin();
		std::cout << " - ITERATOR OPERATOR PLUS AND MINUS - " << std::endl;

		std::cout << "TEST #1 - " << ((*it == 1) ? "✅" : "❌") << std::endl;
		*it += 5;
		std::cout << "TEST #2 - " << ((*it == 6) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #3 - " << (((*it + 2) == 8) ? "✅" : "❌") << std::endl;
		*it -= 5;
		std::cout << "TEST #4 - " << ((*it == 1) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #5 - " << (((*it - 1) == 0) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #6 - " << ((it[4] == 5) ? "✅" : "❌") << std::endl;
	}
		{
		int ar[] = {1, 2, 3, 4, 5};
		std::vector<int> vec(ar, ar + 5);
		std::vector<int>::iterator it = vec.begin();

		std::vector<int> const cvec(ar, ar + 5);
		std::vector<int>::const_iterator cit = cvec.begin();

		int ar2[] = {10, 2, 3, 4, 5, 6};
		std::vector<int> const cvec2(ar2, ar2 + 6);
		std::vector<int>::const_iterator cit2 = cvec2.begin();
		std::cout << " - ITERATOR RELATIONAL OPERATORS - " << std::endl;

		std::cout << "TEST #1 - " << (((*it == *cit) == true) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << (((*it == *cit2) == false) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #3 - " << (((*it != *cit) == false) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #4 - " << (((*it != *cit2) == true) ? "✅" : "❌") << std::endl;

		std::cout << "TEST #5 - " << (((*it > *cit) == false) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #6 - " << (((*it > *cit2) == false) ? "✅" : "❌") << std::endl;

		std::cout << "TEST #7 - " << (((*it < *cit) == false) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #8 - " << (((*it < *cit2) == true) ? "✅" : "❌") << std::endl;

		std::cout << "TEST #8 - " << (((*it <= *cit) == true) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #9 - " << (((*it <= *cit2) == true) ? "✅" : "❌") << std::endl;

		std::cout << "TEST #10 - " << (((*it >= *cit) == true) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #11 - " << (((*it >= *cit2) == false) ? "✅" : "❌") << std::endl;
	}
}
