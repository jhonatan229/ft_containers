#ifndef FT_MAP_H
#define FT_MAP_H
#include <memory>
#include "../includes/BSTNode.hpp"
#include "../iterators/ft_bidirectional_iterator.hpp"
#include "../iterators/ft_reverse_iterator.hpp"
#include "../includes/check_type.hpp"
#include "../includes/utility.hpp"

namespace ft
{

	template <class Key,
			  class T,
			  class Compare = std::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T>>>
	class map
	{

	private:
		// actual tree structure
		map_node *_root;
		map_node *_begin;
		map_node *_end;
		size_type _size;
		key_compare _compare;
		alloc_node _alloc;

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef bidirectional_iterator<value_type, pointer, reference> iterator;
		typedef bidirectional_iterator<value_type, const_pointer, const_reference> const_iterator;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef BSTNode<value_type> map_node;
		typedef typename Alloc::template rebind<map_node>::other alloc_node;

		class value_compare
		{
			friend class map;

		protected:
			Compare comp;

			value_compare(Compare c) : comp(c) {}

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};

		// empty -> Constructs an empty container, with no elements.
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _root(), _begin(), _end(), _size(0), _compare(comp), _alloc(alloc)
		{
			initialise_constructor();
		}

		// range -> Constructs a container with as many elements as the range [first,last)
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _root(), _begin(), _end(), _size(0), _compare(comp), _alloc(alloc)
		{
			initialise_constructor();
			insert(first, last);
		}

		// copy -> Constructs a container with a copy of each of the elements in x.
		map(const map &x) : _root(), _begin(), _end(), _size(0), _compare(x._compare), _alloc(x._alloc)
		{
			initialise_constructor();
			insert(x.begin(), x.end());
		}

		// assigment operator -> Assigns new contents to the container, replacing its current content.
		map &operator=(const map &x)
		{
			if (this != &x)
			{
				map tmp(x);
				swapContent(_root, tmp._root);
				swapContent(_begin, tmp._begin);
				swapContent(_end, tmp._end);
				swapContent(_size, tmp._size);
				swapContent(_compare, tmp._compare);
				swapContent(_alloc, tmp._alloc);
			}
			return *this;
		}

		// destructor -> Destroys the container object.
		~map()
		{
			if (!size())
			{
				_alloc.destroy(_begin);
				_alloc.deallocate(_begin, 1);
				_alloc.destroy(_end);
				_alloc.deallocate(_end, 1);
				_alloc.destroy(_root);
				_alloc.deallocate(_root, 1);
			}
			else
				clearTree(_root);
		}

		//-> If k matches the key of an element in the container, the function returns a reference to its mapped value.
		mapped_type &operator[](const key_type &k)
		{
			return (*((insert(make_pair(k, mapped_type()))).first)).second;
		}

		//-> Returns an iterator referring to the first element in the map container.
		iterator begin()
		{
			if (!size())
				return end();
			else
				return iterator(_begin->parent);
		}

		const_iterator begin() const
		{
			if (!size())
				return end();
			else
				return const_iterator(_begin->parent);
		}

		//-> Returns an iterator referring to the past-the-end element in the map container.
		iterator end() { return iterator(_end); }
		const_iterator end() const { return const_iterator(_end); }

		//-> Returns a reverse iterator pointing to the last element in the container (its reverse beginning).
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		//-> Returns a reverse iterator pointing to the theoretical element right before the first element in the map container (its reverse beginning).
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		//-> test whether container is empty
		bool empty() const { return _size == 0; }

		//-> Returns the number of elements in the map container.
		size_type size() const { return _size; }

		//-> return maximum size
		size_type max_size() const { return _alloc.max_size(); }
	};
}

#endif