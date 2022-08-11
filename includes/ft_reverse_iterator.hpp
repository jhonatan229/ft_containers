#if !defined(FT_REVERSE_ITERATOR_HPP)
#define FT_REVERSE_ITERATOR_HPP

#include "ft_iterator.hpp"

namespace ft
{

	template <typename Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
											 typename iterator_traits<Iterator>::value_type,
											 typename iterator_traits<Iterator>::difference_type,
											 typename iterator_traits<Iterator>::pointer,
											 typename iterator_traits<Iterator>::reference>
	{
	protected:
		Iterator current;

	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;

		reverse_iterator(){};
		explicit reverse_iterator(Iterator it) : current(it){};
		reverse_iterator(const reverse_iterator<Iterator> &rev_iter) : current(rev_iter.base()){};

		iterator_type base() const
		{
			return (current);
		}

		reference operator*(difference_type n) const
		{
			iterator_type tmp = current;
			return (*--tmp);
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(current - n));
		}

		reverse_iterator &operator++()
		{
			current--;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			current--;
			return (*this);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(current + n));
		}

		reverse_iterator &operator--()
		{
			current++;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			current++;
			return (*this);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			current += n;
			return (*this);
		}

		pointer operator->() const
		{
			return (&(operator*()));
		}

		reference operator[](difference_type n) const
		{
			return (*(*this + n));
		}
	};

	template<typename Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &it)
	{return (reverse_iterator<Iter>(it.base() - n));}

	template<typename Iter>
	typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (rhs.base() - lhs.base());}

	template<typename Iter>
	bool operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() == rhs.base());}

	template<typename Iter>
	bool operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() != rhs.base());}

	template<typename Iter>
	bool operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() > rhs.base());}

	template<typename Iter>
	bool operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() < rhs.base());}

	template<typename Iter>
	bool operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() >= rhs.base());}

	template<typename Iter>
	bool operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() <= rhs.base());}

}

#endif // FT_REVERSE_ITERATOR
