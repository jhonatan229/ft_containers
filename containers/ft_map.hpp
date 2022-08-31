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
		typedef bidirectional_iterator<value_type> iterator;
		typedef bidirectional_iterator<value_type> const_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef BSTNode<value_type> map_node;
		typedef typename Alloc::template rebind<map_node>::other alloc_node;

	private:
		// actual tree structure
		map_node *_root;
		map_node *_begin;
		map_node *_end;
		size_type _size;
		key_compare _compare;
		alloc_node _alloc;

	public:
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
				make_swap(_root, tmp._root);
				make_swap(_begin, tmp._begin);
				make_swap(_end, tmp._end);
				make_swap(_size, tmp._size);
				make_swap(_compare, tmp._compare);
				make_swap(_alloc, tmp._alloc);
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
				clear_tree(_root);
		}

		//-> If k matches the key of an element in the container, the function returns a reference to its mapped value.
		mapped_type &operator[](const key_type &k)
		{
			return (*((insert(make_pair(k, mapped_type()))).first)).second;
		}

		//-> Returns an iterator referring to the first element in the map container.
		iterator begin()
		{
			return (!size() ? end() : iterator(_begin->parent));
		}

		const_iterator begin() const
		{
			return (!size() ? end() : const_iterator(_begin->parent));
		}

		//-> Returns an iterator referring to the past-the-end element in the map container.
		iterator end()
		{
			return iterator(_end);
		}
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

		ft::pair<iterator, bool> insert(const value_type &val)
		{
			bool found = false;
			map_node *return_node = NULL;

			_root = new_insert(_root, NULL, val, found, return_node);
			setup_tree_begin_end();
			if (found)
				return ft::make_pair(iterator(return_node), false);
			else
				return ft::make_pair(iterator(return_node), true);
		}

		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return insert(val).first;
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (InputIterator iter(first); iter != last; iter++)
				insert(*iter);
		}

		size_type erase(const key_type &k)
		{
			bool found = false;
			_root = deleteNode(_root, k, found);
			setup_tree_begin_end();
			return (found ? 1 : 0);
		}

		void erase(iterator first, iterator last)
		{
			for (iterator iter(first); iter != last; iter++)
			{
				iterator tmp(iter);
				erase(tmp);
			}
		}

		void erase(iterator position)
		{
			erase(position->first);
		}

		void swap(map &x)
		{
			make_swap(_root, x._root);
			make_swap(_begin, x._begin);
			make_swap(_end, x._end);
			make_swap(_size, x._size);
			make_swap(_compare, x._compare);
			make_swap(_alloc, x._alloc);
		}

		void clear()
		{
			erase(begin(), end());
		}

		key_compare key_comp() const
		{
			return _compare;
		}

		value_compare value_comp() const
		{
			return value_compare(_compare);
		}

		iterator find(const key_type &k)
		{
			for (iterator iter = begin(); iter != end(); iter++)
			{
				if (iter->first == k)
					return iter;
			}
			return end();
		}

		const_iterator find(const key_type &k) const
		{
			for (const_iterator iter = begin(); iter != end(); iter++)
			{
				if (iter->first == k)
					return iter;
			}
			return end();
		}

		size_type count(const key_type &k) const
		{
			return (find(k) != end() ? 1 : 0);
		}

		iterator lower_bound(const key_type &k)
		{
			for (iterator iter = begin(); iter != end(); iter++)
			{
				if (!_compare(iter->first, k))
					return (iter);
			}
			return end();
		}
		const_iterator lower_bound(const key_type &k) const
		{
			for (const_iterator iter = begin(); iter != end(); iter++)
			{
				if (!_compare(iter->first, k))
					return (iter);
			}
			return end();
		}

		iterator upper_bound(const key_type &k)
		{
			for (iterator iter = begin(); iter != end(); iter++)
			{
				if (!_compare(k, iter->first))
					return (iter);
			}
			return end();
		}
		const_iterator upper_bound(const key_type &k) const
		{
			for (const_iterator iter = begin(); iter != end(); iter++)
			{
				if (!_compare(k, iter->first))
					return (iter);
			}
			return end();
		}

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			const_iterator lower = lower_bound(k);
			const_iterator upper = upper_bound(k);
			return make_pair(lower, upper);
		}
		pair<iterator, iterator> equal_range(key_type &k)
		{
			iterator lower = lower_bound(k);
			iterator upper = upper_bound(k);
			return make_pair(lower, upper);
		}

		allocator_type get_allocator() const
		{
			return _alloc;
		}

	private:
		void initialise_constructor()
		{
			_root = _alloc.allocate(1);
			_alloc.construct(_root, value_type());
			_begin = _alloc.allocate(1);
			_alloc.construct(_begin, value_type());
			_end = _alloc.allocate(1);
			_alloc.construct(_end, value_type());

			_begin->parent = _root;
			_end->parent = _root;
			_root->left = _begin;
			_root->right = _end;
		}

		void clear_tree(map_node *node)
		{
			if (node)
			{
				clear_tree(node->left);
				clear_tree(node->right);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
			}
		}

		template <class Type>
		void make_swap(Type &a, Type &b)
		{
			Type tmp(a);
			a = b;
			b = tmp;
		}

		map_node *find_higher_number(map_node *node)
		{
			map_node *current = node;
			while (current && current->right)
				current = current->right;
			return current;
		}

		map_node *find_smallest_number(map_node *node)
		{
			map_node *current = node;
			while (current && current->right)
				current = current->right;
			return current;
		}

		void setup_tree_begin_end()
		{
			map_node *leftest = find_smallest_number(_root);
			map_node *rightest = find_higher_number(_root);

			_begin->parent = leftest;
			_end->parent = rightest;
			if (leftest)
				leftest->left = _begin;
			if (rightest)
				rightest->right = _end;
		}

		map_node *search_key(const key_type &k)
		{
			map_node *tmp = _root;
			while (tmp && tmp != _begin && tmp != _end)
			{
				if (k == tmp->value.first)
					return tmp;
				if (k < tmp->value.first)
					tmp = tmp->left;
				else if (k > tmp->value.first)
					tmp = tmp->rights;
			}
			return NULL;
		}

		int max(int n1, int n2)
		{
			return (n1 > n2 ? n1 : n2);
		}

		int height(map_node *node)
		{
			if (!node || node == begin() || node == end() || size() == 0)
				return 0;
			return node->height;
		}

		int get_balance(map_node *node)
		{
			if (!node || node == begin() || node == end() || size() == 0)
				return 0;
			return height(node->left) - height(node->right);
		}

		void ajust_height(map_node *node)
		{
			if (node->left && node->left != _begin)
				node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
			if (node->right && node->right != _begin)
				node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
			if (node != _end && node != _begin)
				node->height = max(height(node->left), height(node->right)) + 1;
			if (node->parent)
				node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
		}

		map_node *right_rotate(map_node *node)
		{
			key_compare compare = key_compare();
			map_node *tmp = node->left;
			if (tmp && tmp != _begin)
			{
				node->left = tmp->right;
				if (tmp->right && tmp->right != _end)
					tmp->right->parent = node;
				tmp->right = node;
				tmp->parent = node->parant;
				node->parent = tmp;
				if (tmp->parent && compare(node->value.first, tmp->parent->value.first))
					tmp->parent->left = tmp;
				else if (tmp->parent && compare(tmp->parent->value.first, node->value.first))
					tmp->parent->right = tmp;
				node = tmp;
				ajust_height(node);
			}
			return node;
		}
		map_node *left_rotate(map_node *node)
		{
			key_compare compare = key_compare();
			map_node *tmp = node->right;
			if (tmp && tmp != _end)
			{
				node->right = tmp->left;
				if (tmp->left && tmp->left != _end)
					tmp->left->parent = node;
				tmp->left = node;
				tmp->parent = node->parant;
				node->parent = tmp;
				if (tmp->parent && compare(node->value.first, tmp->parent->value.first))
					tmp->parent->left = tmp;
				else if (tmp->parent && compare(tmp->parent->value.first, node->value.first))
					tmp->parent->right = tmp;
				node = tmp;
				ajust_height(node);
			}
			return node;
		}

		map_node *balance_insert_tree(map_node *node, const value_type &val)
		{
			key_compare comp = key_compare();
			int balance = get_balance(node);
			if (balance > 1 && node->left && node->left != _begin && comp(val.first, node->left->value.first))
				return (right_rotate(node));
			else if (balance > 1 && node->left && node->left != _begin && comp(node->left->value.first, val.first))
			{
				node->left = left_rotate(node->left);
				return right_rotate(node);
			}
			if (balance > 1 && node->right && node->right != _begin && comp(val.first, node->right->value.first))
				return (right_rotate(node));
			else if (balance > 1 && node->right && node->right != _begin && comp(node->right->value.first, val.first))
			{
				node->right = right_rotate(node->right);
				return left_rotate(node);
			}
			return node;
		}

		map_node *create_new_node(const value_type &val, map_node *parent, bool &found, map_node *&return_node)
		{
			map_node *new_node = _alloc.allocate(1);
			_alloc.construct(new_node);

			new_node->height = 1;
			new_node->parent = parent;
			found = false;
			return_node = new_node;
			_size++;
			return new_node;
		}

		map_node *new_insert(map_node *node, map_node *parent, const value_type &val, bool &found, map_node *&return_node)
		{
			key_compare compare = key_compare();
			if (!node || node == begin() || node == end() || size() == 0)
			{
				if (size() == 0)
				{
					_alloc.destroy(_root);
					_alloc.deallocate(_root, 1);
				}
				return create_new_node(val, parent, found, return_node);
			}
			if (compare(val.first, node->value.first))
				node->left = new_insert(node->left, node, val, found, return_node);
			else if (compare(node->value.first, val.first))
				node->right = new_insert(node->right, node, val, found, return_node);
			else
			{
				found = true;
				return_node = node;
				return node;
			}

			node->height = 1 + max(height(node->left), height(node->right));

			return balance_insert_tree(node, val);
		}

		map_node *balance_erase_tree(map_node *root)
		{
			int first_height = 0;
			int second_height = 0;

			if (root->left && root->left != begin())
				first_height = root->left->height;
			if (root->right && root->right != end())
				second_height = root->right->height;
			if (abs(first_height - second_height) > 1)
			{
				if (first_height < second_height)
				{
					int right_height_left = 0;
					int right_height_right = 0;
					if (root->right->right && root->right->right != end())
						right_height_right = root->right->right->height;
					if (root->right->left && root->right->left != begin())
						right_height_left = root->right->left->height;
					if (right_height_left > right_height_right)
					{
						root->right = right_rotate(root->right);
						root = left_rotate(root);
					}
					else
						root = left_rotate(root);
				}
				else
				{
					int left_height_left = 0;
					int left_height_right = 0;
					if (root->left->right && root->left->right != end())
						left_height_right = root->left->right->height;
					if (root->left->left && root->left->left != begin())
						left_height_left = root->left->left->height;
					if (left_height_left > left_height_right)
						root = right_rotate(root);
					else
					{
						root->left = left_rotate(root->left);
						root = right_rotate(root);
					}
				}
			}
			return root;
		}

		// map_node *delete_with_left_child(map_node *node){
		// 	if (node->parent)
		// }
	};
}

#endif