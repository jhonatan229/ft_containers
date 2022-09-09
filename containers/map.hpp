#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include "../includes/BSTNode.hpp"
#include "../iterators/bidirectional_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../includes/check_type.hpp"
#include "../includes/utility.hpp"
#include "../includes/algorithm.hpp"

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
		typedef bidirectional_iterator<value_type, pointer, reference> iterator;
		typedef bidirectional_iterator<value_type, pointer, reference> const_iterator;
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
			return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
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
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		size_type erase(const key_type &k)
		{
			bool found = false;
			_root = delete_node(_root, k, found);
			setup_tree_begin_end();
			return (found ? 1 : 0);
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp(first);
				++first;
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
			iterator iter = end();
			while (--iter != begin())
			{
				if (iter->first <= k)
					return (iter);
			}

			// for (iterator iter = begin(); iter != end(); iter++)
			// {
			// }
			return end();
		}
		const_iterator lower_bound(const key_type &k) const
		{
			const_iterator iter = end();
			while (--iter != begin())
			{
				if (iter->first <= k)
					return (iter);
			}

			return end();
		}

		iterator upper_bound(const key_type &k)
		{
			for (iterator iter = begin(); iter != end(); iter++)
			{
				if (iter->first > k)
					return (iter);
			}
			return end();
		}

		const_iterator upper_bound(const key_type &k) const
		{
			for (const_iterator iter = begin(); iter != end(); iter++)
			{
				if (iter->first > k)
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
		pair<iterator, iterator> equal_range(const key_type &k)
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

		map_node *find_smallest_number(map_node *node)
		{
			map_node *current = node;
			while (current && current->left && current->left != _begin)
				current = current->left;
			return current;
		}

		map_node *find_higher_number(map_node *node)
		{
			map_node *current = node;
			while (current && current->right && current->right != _end)
				current = current->right;
			return current;
		}

		void setup_tree_begin_end()
		{

			map_node *leftest = find_smallest_number(_root);
			map_node *rightest = find_higher_number(_root);

			_begin->parent = leftest;
			if (leftest)
				leftest->left = _begin;

			_end->parent = rightest;
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
				else if (_compare(k, tmp->value.first))
					tmp = tmp->left;
				else if (_compare(tmp->value.first, k))
					tmp = tmp->right;
			}
			return NULL;
		}

		int max(int n1, int n2)
		{
			return (n1 > n2 ? n1 : n2);
		}

		int height(map_node *node)
		{
			if (!node || node == _begin || node == _end || size() == 0)
				return 0;
			return node->height;
		}

		int get_balance(map_node *node)
		{
			if (!node || node == _begin || node == _end || size() == 0)
				return 0;
			return height(node->left) - height(node->right);
		}

		// void ajust_height(map_node *node)
		// {
		// 	if (node->left && node->left != _begin)
		// 		node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
		// 	if (node->right && node->right != _begin)
		// 		node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
		// 	if (node != _end && node != _begin)
		// 		node->height = max(height(node->left), height(node->right)) + 1;
		// 	if (node->parent)
		// 		node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
		// }

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
				tmp->parent = node->parent;
				node->parent = tmp;
				if (tmp->parent && compare(node->value.first, tmp->parent->value.first))
					tmp->parent->left = tmp;
				else if (tmp->parent && compare(tmp->parent->value.first, node->value.first))
					tmp->parent->right = tmp;
				node = tmp;
				if (node->left && node->left != _begin)
					node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
				if (node->right && node->right != _end)
					node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
				if (node != _end && node != _begin)
					node->height = max(height(node->left), height(node->right)) + 1;
				if (node->parent)
					node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;			}
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
				tmp->parent = node->parent;
				node->parent = tmp;
				if (tmp->parent && compare(node->value.first, tmp->parent->value.first))
					tmp->parent->left = tmp;
				else if (tmp->parent && compare(tmp->parent->value.first, node->value.first))
					tmp->parent->right = tmp;
				node = tmp;
				if (node->left && node->left != _begin)
					node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
				if (node->right && node->right != _end)
					node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
				if (node != _end && node != _begin)
					node->height = max(height(node->left), height(node->right)) + 1;
				if (node->parent)
					node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
			}
			return node;
		}

		map_node *balance_insert_tree(map_node *node, const value_type &val)
		{
			key_compare compare = key_compare();
			int balance = get_balance(node);

			if (balance > 1 && node->left && node->left != _begin && compare(val.first, node->left->value.first))
				return right_rotate(node);
			else if (balance > 1 && node->left && node->left != _begin && compare(node->left->value.first, val.first))
			{
				node->left = left_rotate(node->left);
				return right_rotate(node);
			}
			if (balance < -1 && node->right && node->right != _end && compare(node->right->value.first, val.first))
				return left_rotate(node);
			else if (balance < -1 && node->right && node->right != _end && compare(val.first, node->right->value.first))
			{
				node->right = right_rotate(node->right);
				return left_rotate(node);
			}
			return node;
		}

		map_node *create_new_node(const value_type &val, map_node *parent, bool &found, map_node *&return_node)
		{
			map_node *new_node = _alloc.allocate(1);
			_alloc.construct(new_node, val);

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
			if (size() == 0)
			{
				_alloc.destroy(_root);
				_alloc.deallocate(_root, 1);
				return create_new_node(val, parent, found, return_node);
			}
			else if (!node || node == _begin || node == _end)
				return create_new_node(val, parent, found, return_node);
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

			if (root->left && root->left != _begin)
				first_height = root->left->height;
			if (root->right && root->right != _end)
				second_height = root->right->height;
			if (abs(first_height - second_height) > 1)
			{
				if (first_height < second_height)
				{
					int right_height_left = 0;
					int right_height_right = 0;
					if (root->right->right && root->right->right != _end)
						right_height_right = root->right->right->height;
					if (root->right->left && root->right->left != _begin)
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
					if (root->left->right && root->left->right != _end)
						left_height_right = root->left->right->height;
					if (root->left->left && root->left->left != _begin)
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

		map_node *delete_node_with_left_child(map_node *node)
		{
			if (node->parent)
			{
				if (_compare(node->parent->value.first, node->value.first))
					node->parent->right = node->left;
				else
					node->parent->left = node->left;
				node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
			}
			map_node *tmp = node->left;
			node->left->parent = node->parent;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			_size--;
			tmp = balance_erase_tree(tmp);
			return tmp;
		}

		map_node *delete_node_with_right_child(map_node *node)
		{
			if (node->parent)
			{
				if (_compare(node->parent->value.first, node->value.first))
					node->parent->right = node->right;
				else
					node->parent->left = node->right;
				node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
			}
			map_node *tmp = node->right;
			tmp->parent = node->parent;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			_size--;
			tmp = balance_erase_tree(tmp);
			return tmp;
		}
		map_node *delete_leaf_node(map_node *node)
		{
			if (node->parent)
			{
				if (_compare(node->parent->value.first, node->value.first))
					node->parent->right = NULL;
				else
					node->parent->left = NULL;
				node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
			}
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			_size--;
			return NULL;
		}

		map_node *delete_node_with_two_children(map_node *node, bool &found)
		{
			map_node *tmp = node->right;
			while (tmp && tmp->left)
				tmp = tmp->left;
			value_type value = tmp->value;
			node->right = delete_node(node->right, tmp->value.first, found);

			map_node *toAdd = _alloc.allocate(1);
			_alloc.construct(toAdd, value);

			toAdd->parent = node->parent;
			toAdd->right = node->right;
			toAdd->left = node->left;
			toAdd->height = node->height;

			if (node->parent && node->parent->left == node)
				node->parent->left = toAdd;
			if (node->parent && node->parent->right == node)
				node->parent->right = toAdd;
			if (node->left && node->left != _begin && node->left->parent == node)
				node->left->parent = toAdd;
			if (node->right && node->right != _end && node->right->parent == node)
				node->right->parent = toAdd;

			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			toAdd = balance_erase_tree(toAdd);
			return toAdd;
		}

		map_node *delete_node(map_node *node, const key_type &key, bool &found)
		{
			if (node && node != _begin && node != _end && size())
			{
				// found the node -> delete operations
				if (!_compare(node->value.first, key) && !_compare(key, node->value.first))
				{
					found = true;
					if ((!node->right || node->right == _end) && (node->left && node->left != _begin))
						return delete_node_with_left_child(node);
					else if ((!node->left || node->left == _begin) && (node->right && node->right != _end))
						return delete_node_with_right_child(node);
					else if ((!node->left || node->left == _begin) && (!node->right || node->right == _end))
						return delete_leaf_node(node);
					else
						return delete_node_with_two_children(node, found);
				}
				// node value smaller than key value -> move right
				else if (_compare(node->value.first, key))
				{
					node->right = delete_node(node->right, key, found);
					node = balance_erase_tree(node);
				}
				// node value bigger than key value -> move left
				else if (_compare(key, node->value.first))
				{
					node->left = delete_node(node->left, key, found);
					node = balance_erase_tree(node);
				}
				// update node height
				if (node)
					node->height = max(height(node->left), height(node->right)) + 1;
			}
			else
				found = false;
			return node;
		}
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		typename ft::map<Key, T>::const_iterator lhs_begin = lhs.begin();
		typename ft::map<Key, T>::const_iterator rhs_begin = rhs.begin();

		while (lhs_begin != lhs.end() && rhs_begin != rhs.end())
		{
			if (lhs_begin->first != rhs_begin->first || lhs_begin->second != rhs_begin->second)
				return false;
			++lhs_begin;
			++rhs_begin;
		}
		return true;
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs > rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	}
}

#endif