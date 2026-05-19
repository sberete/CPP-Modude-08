#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
	}
	return (*this);
}

Span::~Span(void)
{
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>	tmp;
	unsigned int	minSpan;

	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");

	tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	minSpan = static_cast<unsigned int>(tmp[1] - tmp[0]);
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (static_cast<unsigned int>(tmp[i + 1] - tmp[i]) < minSpan)
			minSpan = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
	}
	return (minSpan);
}

unsigned int	Span::longestSpan(void) const
{
	std::vector<int>::const_iterator	minIt;
	std::vector<int>::const_iterator	maxIt;

	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");

	minIt = std::min_element(_numbers.begin(), _numbers.end());
	maxIt = std::max_element(_numbers.begin(), _numbers.end());

	return (static_cast<unsigned int>(*maxIt - *minIt));
}