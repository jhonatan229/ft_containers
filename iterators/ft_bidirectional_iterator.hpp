#ifndef FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_HPP
#define FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_HPP

#include "ft_iterator.hpp"

namespace ft
{

	template <typename T>
	class bidirectional_iterator
	{

	private:
		iterator_type _ptr;;

	public:
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ft::ptrdiff_t difference_type;
		typedef T &reference;
		typedef T *pointer;
		typedef bidirectional_iterator<value_type> iterator;
		typedef bidirectional_iterator<value_type> if_const;
		typedef BSTNode<value_type> Node;
		typedef Node *iterator_type;

		bidirectional_iterator() : _ptr(NULL) {}
		bidirectional_iterator(iterator_type ptr) : _ptr(ptr) {}
		bidirectional_iterator(const bidirectional_iterator &x) { *this = x; }
		bidirectional_iterator &operator=(const bidirectional_iterator &x)
		{
			if (this != &x)
				_ptr = x._ptr;
			return *this;
		}
		~bidirectional_iterator() {}

		iterator_type getCurrent() const {return current;};
		operator if_const() const { return if_const(_ptr); }
		reference operator*() { return _ptr->value; }
		pointer operator->() { return &(_ptr->value); }

		iterator &operator++()
		{
			_ptr = _ptr->sucessor();
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			_ptr = _ptr->sucessor();
			return tmp;
		}

		iterator &operator--()
		{
			_ptr = _ptr->predecessor();
			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp = *this;
			_ptr = _ptr->predecessor();
			return tmp;
		}
	};

	template<typename Iter>
	bool operator==(const bidirectional_iterator<Iter> &lhs, const bidirectional_iterator<Iter> &rhs)
	{return (lhs.getCurrent() == rhs.getCurrent());}

	template<typename Iter>
	bool operator!=(const bidirectional_iterator<Iter> &lhs, const bidirectional_iterator<Iter> &rhs)
	{return (lhs.getCurrent() != rhs.getCurrent());}
}

#endif