#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vec;
	std::list<int>		lst;
	std::deque<int>		deq;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i * 2);
		lst.push_back(i * 3);
		deq.push_back(i * 4);
	}

	try
	{
		std::vector<int>::iterator it;

		it = easyfind(vec, 8);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it;

		it = easyfind(lst, 9);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::deque<int>::iterator it;

		it = easyfind(deq, 100);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}