#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <iterator>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span(void);

		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

	template <typename Iterator>
	void	addRange(Iterator begin, Iterator end)
	{
		if (_numbers.size() + std::distance(begin, end) > _maxSize)
			throw std::runtime_error("Span does not have enough space");
		_numbers.insert(_numbers.end(), begin, end);
	}

	private:
		Span(void);

		unsigned int		_maxSize;
		std::vector<int>	_numbers;
};

#endif