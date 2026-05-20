#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span big(10000);

		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++)
			big.addNumber(std::rand());

		std::cout << "Big shortest span: " << big.shortestSpan() << std::endl;
		std::cout << "Big longest span:  " << big.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span fail(1);

		fail.addNumber(42);
		std::cout << fail.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Expected error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::vector<int> values;

	for (int i = 0; i < 10000; i++)
		values.push_back(i);

	Span big(10000);
	big.addRange(values.begin(), values.end());

	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;

	return (0);
}