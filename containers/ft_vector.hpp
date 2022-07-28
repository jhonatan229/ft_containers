#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "ft_iterator.hpp"
#include "ft_reverse_iterator.hpp"
#include "check_type.hpp"
#include "algorithm.hpp"

namespace ft
{

	template <class T, class Alloc = std::allocator<T>>
	class vector
	{
	private:
		size_type _size;
		size_type _capacity;
		allocator_type _alloc;
		pointer _vec;

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::random_access_iterator<pointer> iterator;
		typedef ft::random_access_iterator<const_pointer> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

		explicit vector(const allocator_type &alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _vec(NULL) {}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc), _vec(_alloc.allocate(_size))
		{
			for (size_type i = 0; i < this->size; i++)
				this->_alloc.construct(this->_vec + i, val)
		}

		template <class InputIterator>
		vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
			   const allocator_type &alloc = allocator_type()) : _size(ft::distance(first, last)), _capacity(_size), _alloc(alloc), _vec(_alloc.allocate(_size))
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_vec + i, *(first + i));
		}
		vector(const vector &cpy) : _size(cpy._size), _capacity(cpy._capacity), _alloc(cp)
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_vec + i, cpy._vec[i]);
		}

		~vector()
		{
			clear();
			this->_alloc.deallocate(this->_vec, this->_capacity);
		}
		vector &operator=(const vector &rhs)
		{
			if (this != &rhs)
				return *this;
			if (this->_size != rhs._size)
			{
				if (this->_vec != NULL)
				{
					for (size_type i = 0; i < this->_size; i++)
						this->_alloc.destroy(this->_vec + i);
					this->_alloc.deallocate(this->_vec, _capacity);
				}
				this->_size = rhs._size;
				this->_capacity = rhs._capacity;
				this->_vec = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_vec + i, rhs._vec[i]);
			}
			return *this;
		}
	};
}

#endif