#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "vector.hpp"

namespace ft{
	template<class T, class Container = ft::vector<T>
	class stack{
		private:
			Container c;

		public:
			typedef typename Container::value_type		value_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
			typedef typename Container::size_type		size_type;
			typedef Container							container_type;

			template<typename T1, typename Container_1>
			friend bool operator==(const stack<T1, Container_1> &lhs, const stack<Container_1> &rhs);
			friend bool operator<(const stack<T1, Container_1> &lhs, const stack<Container_1> &rhs);

			explicit stack(const container_type &cotnr = container_type()): c(cotnr){}

			bool empty()const{
				return c.empty();
			}

			size_type size() const{
				return c.size();
			}

			reference top(){
				return c.back();
			}

			const_reference top() const{
				return c.back();
			}

			void push(const value_type &val){
				c.push_back(val);
			}

			void pop(){
				c.pop_back();
			}
	};

	template<class T, class Container>
	bool operator==( const stack<T, Container> & lhs, const stack<T, Container> & rhs ) {
		return lhs.c == rhs.c;
	}

	template<class T, class Container>
	bool operator!=( const stack<T, Container> & lhs, const stack<T, Container> & rhs ) {
		return !( rhs == lhs );
	}

	template<class T, class Container>
	bool operator<( const stack<T, Container> & lhs, const stack<T, Container> & rhs ) {
		return lhs.c < rhs.c;
	}
	template<class T, class Container>
	bool operator<=( const stack<T, Container> & lhs, const stack<T, Container> & rhs ) {
		return !(rhs < lhs);
	}
	template<class T, class Container>
	bool operator>( const stack<T, Container> & lhs, const stack<T, Container> & rhs ) {
		return rhs < lhs;
	}
	template<class T, class Container>
	bool operator>=( const stack<T, Container> & lhs, const stack<T, Container> & rhs ) {
		return !(lhs < rhs);
	}
}

#endif