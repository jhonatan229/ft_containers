#include <tests.hpp>

void make_stl_vector_test()
{

	std::cout << "\033[1;32m>>>>>>>>>>>>TEST STL VECTOR<<<<<<<<<<<<<\033[0m" << std::endl;
	{
		std::cout << " - TEST VECTOR CONSTRUCTOR - " << std::endl;
		std::vector<int> my_vec;
		std::cout << "TEST #1 - " << ((my_vec.size() == 0) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((my_vec.capacity() == 0) ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST VECTOR CONSTRUCTOR WITH PARAMS - " << std::endl;
		std::vector<int> vec1(5);
		std::vector<std::string> vec2(5, "fill");
		std::cout << "TEST #1 - " << ((vec1.size() == 5) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((vec1.capacity() == 5) ? "✅" : "❌") << std::endl;
		for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++)
			std::cout << "  TEST #3 - " << ((*it == 0) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #4 - " << ((vec2.size() == 5) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #5 - " << ((vec2.capacity() == 5) ? "✅" : "❌") << std::endl;
		for (std::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
			std::cout << "  TEST #6 - " << ((*it == "fill") ? "✅" : "❌") << std::endl;
	}

	{
		std::cout << " - TEST VECTOR EQUAL OPERATOR - " << std::endl;
		int array1[] = {1, 2, 3, 4, 5};
		std::string array2[] = {"one", "two", "three", "four", "five"};
		std::vector<int> vec1(array1, array1 + 5);
		std::vector<std::string> vec2(array2, array2 + 5);
		std::vector<int> vec3 = vec1;
		std::vector<std::string> vec4 = vec2;
		std::cout << "TEST #1 - " << ((vec3.size() == 5) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((vec3.capacity() == 5) ? "✅" : "❌") << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << "	TEST #3 - " << ((vec3[i] == array1[i]) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #4 - " << ((vec4.size() == 5) ? "✅" : "❌") << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << "	TEST #5 - " << ((vec4[i] == array2[i]) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR COPY OPERATOR - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		std::vector<std::string> vec2(vec1);
		std::cout << "TEST #1 - " << ((vec2.size() == 5) ? "✅" : "❌") << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << "	TEST #2 - " << ((vec2[i] == array1[i]) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR GET POSITION - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		std::cout << "TEST #1 - " << ((vec1[0] == "one") ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((vec1.at(1) == "two") ? "✅" : "❌") << std::endl;
		std::cout << "TEST #3 - " << ((vec1.front() == "one") ? "✅" : "❌") << std::endl;
		std::cout << "TEST #4 - " << ((vec1.back() == "five") ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR PUSH BACK - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		vec1.push_back("six");
		std::cout << "TEST #1 - " << ((vec1.back() == "six") ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((vec1.size() == 6) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR POP BACK - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		vec1.pop_back();
		std::cout << "TEST #1 - " << ((vec1.back() == "four") ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((vec1.size() == 4) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR ASSIGN - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		std::vector<std::string> vec2(array1, array1 + 3);
		vec1.assign(4, "val");
		for (size_t i = 0; i < vec1.size(); i++)
		{
			std::cout << "	TEST #1 - " << ((vec1[i] == "val") ? "✅" : "❌") << std::endl;
		}
		vec1.assign(vec2.begin(), vec2.end());
		std::cout << "TEST #2 - " << ((vec1.size() == 3) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR INSERT - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		vec1.insert(vec1.begin() + 2, "ola");
		std::cout << "TEST #1 - " << ((vec1.size() == 6) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((vec1[2] == "ola") ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR ERASE - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		std::cout << "TEST #1 - " << ((vec1.size() == 5) ? "✅" : "❌") << std::endl;
		vec1.erase(vec1.begin(), vec1.end());
		std::cout << "TEST #2 - " << ((vec1.size() == 0) ? "✅" : "❌") << std::endl;
		vec1.assign(3, "val");
		vec1.erase(vec1.begin() + 1);
		std::cout << "TEST #3 - " << ((vec1.size() == 2) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR CLEAR - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		std::cout << "TEST #1 - " << ((vec1.size() == 5) ? "✅" : "❌") << std::endl;
		vec1.clear();
		std::cout << "TEST #2 - " << ((vec1.size() == 0) ? "✅" : "❌") << std::endl;
	}
	{
		std::cout << " - TEST VECTOR SWAP - " << std::endl;
		std::string array1[] = {"one", "two", "three", "four", "five"};
		std::vector<std::string> vec1(array1, array1 + 5);
		std::vector<std::string> vec2;
		vec2.assign(3, "val");
		vec1.swap(vec2);
		std::cout << "TEST #1 - " << ((vec1.size() == 3) ? "✅" : "❌") << std::endl;
		std::cout << "TEST #2 - " << ((vec2.size() == 5) ? "✅" : "❌") << std::endl;
	}
}
