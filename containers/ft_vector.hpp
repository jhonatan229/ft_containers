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

		reference operator[] (size_type n){
			return(*(this->_vec + n));
		}

		const reference operator[](size_type n) const{
			return(*(this->_vec + n));
		}

		iterator begin() {
				return iterator(this->_vec);
			}

			const_iterator begin() const {
				return const_iterator(this->_vec);
			}

			iterator end() {
				return begin() + this->_size;
			}

			const_iterator end() const {
				return begin() + this->_size;
			}

			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			}

			reverse_iterator rend() {
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
			}

			size_type size() const {
				return this->_size;
			}

			size_type max_size() const {
				return this->_alloc.max_size();
			}

			size_type capacity()const{
				return this->_capacity;
			}

			bool empty() const{
				return this->_size == 0;
			}

			reference at(size_type n){
				if(n >= this->_size)
					throw std::out_of_range("ft::vector::at is out of range");
				return (*(this->_vec + n));
			}

			const_reference at(size_type n) const{
				if(n >= this->_size)
					throw std::out_of_range("ft::vector::at is out of range");
				return (*(this->_vec + n));
			}

			reference front(){
				return this->_vec[0];
			}

			const_reference front() const{
				return this->_vec[0];
			}

			reference back(){
				return this->_vec[this->_size - 1];
			}

			const_reference back() const{
				return this->_vec[this->_size - 1];
			}

			/** Resize faz oq o nome diz, reajusta o tamanho da lista, dependendo do tamanho 'n';
			 * se for maior que o tamanho atual da lista, é alocado mais memoria para a lista e adicionado
			 * o 'val' em cada espaço adicional;
			 * Caso o n for menor, noss lista vai diminuir, destruindo essas alocações extras que não são mais
			 * nesecitadas;
			*/
			void resize(size_type n, value_type val = value_type()){
				if(n > this->_size){
					reserve(n);
					for (size_type i = this->_size; i < n; i++)
						this->_alloc.construct(this->_vec + i, val);
				}
				else if(n < this->_size)
					for (size_type i = n; i < this->_size; i++)
						this->_alloc.destroy(this->_vec + i);
			}

			void reseve(size_type n){
				if (n > max_size())
					throw std::length_error("ft::vector::reserve:: n is greates than max size");
				if (n > _capacity) {
					this->_capacity = n;
					pointer tmp = this->_alloc.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++)
						this->_alloc.construct(tmp + i, *(this->_vec + i));
					this->_alloc.deallocate(this->_vec, this->_size);
					this->_vec = tmp;
				}
			}

	};
}

#endif