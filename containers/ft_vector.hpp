#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

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
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_vec + i, val);
		}

		template <class InputIterator>
		vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
			   const allocator_type &alloc = allocator_type()) : _size(ft::distance(first, last)), _capacity(_size), _alloc(alloc), _vec(_alloc.allocate(_size))
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_vec + i, *(first + i));
		}
			vector(const vector &cpy) : _size(cpy._size), _capacity(cpy._capacity), _alloc(cpy._alloc), _vec( _alloc.allocate(_capacity))
			{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_vec + i, cpy._vec[i]);
			}

			~vector()
			{
			clear();
			this->_alloc.deallocate(this->_vec, this->_capacity);
			}
			vector & operator=( const vector & rhs ) {
			if (this != &rhs)
			{
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
				}
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_vec + i, rhs._vec[i]);
			}
			return *this;
			}

			reference operator[](size_type n)
			{
			return (*(this->_vec + n));
			}

			const reference operator[](size_type n) const
			{
			return (*(this->_vec + n));
			}

			iterator begin()
			{
			return iterator(this->_vec);
			}

			const_iterator begin() const
			{
			return const_iterator(this->_vec);
			}

			iterator end()
			{
			return begin() + this->_size;
			}

			const_iterator end() const
			{
			return begin() + this->_size;
			}

			reverse_iterator rbegin()
			{
			return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
			return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
			return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
			return const_reverse_iterator(begin());
			}

			size_type size() const
			{
			return this->_size;
			}

			size_type max_size() const
			{
			return this->_alloc.max_size();
			}

			size_type capacity() const
			{
			return this->_capacity;
			}

			bool empty() const
			{
			return this->_size == 0;
			}

			reference at(size_type n)
			{
			if (n >= this->_size)
				throw std::out_of_range("ft::vector::at is out of range");
			return (*(this->_vec + n));
			}

			const_reference at(size_type n) const
			{
			if (n >= this->_size)
				throw std::out_of_range("ft::vector::at is out of range");
			return (*(this->_vec + n));
			}

			reference front()
			{
			return this->_vec[0];
			}

			const_reference front() const
			{
			return this->_vec[0];
			}

			reference back()
			{
			return this->_vec[this->_size - 1];
			}

			const_reference back() const
			{
			return this->_vec[this->_size - 1];
			}

			/** Resize faz oq o nome diz, reajusta o tamanho da lista, dependendo do tamanho 'n';
			 * se for maior que o tamanho atual da lista, é alocado mais memoria para a lista e adicionado
			 * o 'val' em cada espaço adicional;
			 * Caso o n for menor, noss lista vai diminuir, destruindo essas alocações extras que não são mais
			 * nesecitadas;
			 */
			void resize(size_type n, value_type val = value_type())
			{
			if (n > this->_size)
			{
				reserve(n);
				for (size_type i = this->_size; i < n; i++)
					this->_alloc.construct(this->_vec + i, val);
			}
			else if (n < this->_size)
				for (size_type i = n; i < this->_size; i++)
					this->_alloc.destroy(this->_vec + i);
			}

			/** ele reserva uma quantidade de espaço para nossa lista, caso o tamanho que ta vindo pelo parametro
			 * for maior que a capacidade atual;
			 */
			void reserve(size_type n)
			{
			if (n > max_size())
				throw std::length_error("ft::vector::reserve:: n is greates than max size");
			if (n > _capacity)
			{
				this->_capacity = n;
				pointer tmp = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(tmp + i, *(this->_vec + i));
				this->_alloc.deallocate(this->_vec, this->_size);
				this->_vec = tmp;
			}
			}

			/** modifica a lista atual e troca os valores pelos que tão vindo no parametro, do first ao last
			 * caso a capacidade da lista atual for menor que a quantidade de itens da nova lista,
			 * reserva mais memoria para a list;
			 */
			template <class InputIterator>
			void assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
			{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_vec + i);
			this->_alloc.deallocate(this->_vec, this->_size);
			this->_size = ft::distance(first, last);
			if (this->_capacity < this->_size)
				this->_capacity = this->_size;
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_vec + i, *(first + i));
			}

			/** mesma coisa do de cima, só muda os parametros, agora temos um tamanho fixo da lista e o valor que vai ser alocado
			 * em cada espaço.
			 */
			void assign(size_type n, const value_type &val)
			{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_vec + i);
			this->_alloc.deallocate(this->_vec, this->_size);
			this->_size = n;
			if (this->_capacity < this->_size)
				this->_capacity = this->_size;
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_capacity; i++)
				this->_alloc.construct(this->_vec + i, val);
			}

			/**adiciona um novo item no final da lista, caso o tamanho da lista ja tive no seu limite da capacidade
			 * é reservado mais um espaço na memoria;
			 */
			void push_back(const value_type &val)
			{
			if (this->_capacity == this->_size)
				reserve(this->_capacity ? this->_capacity * 2 : 10); // Ternario serve para exceção do capacity ser igual a 0, essa duplicação serve para deixar performatico o push_back
			this->_alloc.construct(&(*this->end()), val);
			this->_size++;
			}

			/**é apagado o ultimo item da lista.
			 */
			void pop_back()
			{
			if (this->_size <= 0)
				return;
			this->_alloc.destroy(&(*this->end()));
			this->_size--;
			}

			iterator insert(iterator position, const value_type &val)
			{
			size_type index = position - this->begin();
			if (this->_size == this->_capacity)
				reserve(this->_capacity ? this->_capacity * 2 : 10);
			for (size_type i = this->_size; i > index; i--)
				this->_alloc.construct(&(*this->begin()) + i, *(begin() + i - 1));
			this->_alloc.construct(&(*this->begin()) + index, val);
			this->_size++;
			return this->begin() + index;
			}

			/**o insert vai inserir novos valores na posição posterior da position, realocando todos os itens
			 * da frente, caso o tamanho da nossa lista for maior que a capacidade,
			 * sera preciso reservar mais memoria para a nossa lista
			 */
			void insert(iterator position, size_type n, const value_type &val)
			{
			if (n)
			{
				size_type index = position - this->begin();
				if (this->_size + n > this->_capacity)
				{
					reserve(this->_capacity ? this->_capacity * 2 : 10);
					while (n--)
						insert(this->begin() + index, val); // existe??}
					this->_size += n;
				}
			}
			}

			// enable if é usado para verificar se o tipo da variavel que esta vindo como parametro esta errada, caso esteja, ele vai tentar chamar outro
			// template, desativando esse template atual
			// TEMPLATE SÓ SÃO CONSTRUIDOS QUANDO CHAMADOS, CAUSANDO ERRO APENAS QUANDO SÃO CHAMADOS, (IN BUILD)
			// SFINAE
			template <class InputIterator>
			void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
						InputIterator last)
			{
			size_type index = position - this->begin();
			size_type n = ft::distance(first, last);
			if (this->_size + n > this->_capacity)
				reserve(this->_capacity ? this->_capacity * 2 : n + 1);
			for (size_type i = this->_size; i > index; i--)
				this->_alloc.construct(&(*this->begin()) + i + n - 1, *(this->begin() + i - 1));
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(&(*this->begin()) + index + i, *(first + i));
			this->_size += n;
			}

			/**apaga um item da nossa lista, independente do lugar que ele ta
			 * remaneja os outros itens se necessario.
			 * retorna a posição com o valor novo.
			 */
			iterator erase(iterator position)
			{
			this->_alloc.destroy(&(*position));
			iterator iter = position;
			while (iter != (this->end()))
			{
				this->_alloc.construct(&(*iter), *(iter + 1));
				iter++;
			}
			this->_size--;
			return position;
			}

			// não ficou claro
			iterator erase(iterator first, iterator last)
			{
			size_type n = ft::distance(first, last);
			for (size_type i = 0; (last + i) != this->end(); i++)
			{
				this->_alloc.destroy(&(*(first + i)));
				this->_alloc.construct(&(*(first + i)), *(last + i));
			}
			this->_size -= n;
			return first;
			}

			void swap(vector &another)
			{
			size_type tmp_size = another._size;
			size_type tmp_capacity = another._capacity;
			pointer tmp_vec = another._vec;

			another._size = this->_size;
			another._capacity = this->_capacity;
			another._vec = this->_vec;

			this->_size = tmp_size;
			this->_capacity = tmp_capacity;
			this->_vec = tmp_vec;
			}

			void clear()
			{
			for (iterator it = this->begin(); it != this->end(); it++)
				this->_alloc.destroy(&(*it));
			this->_size = 0;
			}

			allocator_type get_allocator() const
			{
			return this->_alloc;
			}
		private:
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;
			pointer _vec;
	};

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

}
#endif