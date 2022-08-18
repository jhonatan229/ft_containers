#ifndef FT_RB_TREE_HPP
#define FT_RB_TREE_HPP

#include <ft_reverse_iterator.hpp>
#include <utility.hpp>
#include <functional.hpp>
#include <algorithm.hpp>
#include <memory>
#include <ft_rb_tree_iterator.hpp>

namespace ft
{
	template <class Key, class T, class KeyOfValue, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>>>
	class rb_tree
	{

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T *const_pointer;
		typedef const T &const_reference;
		typedef Alloc allocator_type;
		typedef Compare key_compare;
		typedef typename Alloc::value_type value_type;
		typedef Node<value_type, allocator_type> node_type;
		typedef node_type *ptr_node;
		typedef node_type const &ref_node;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef rbt_iterator<value_type> iterator;
		typedef rbt_const_iterator<value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::allocator<node_type> node_allocator_type;
	}

#endif