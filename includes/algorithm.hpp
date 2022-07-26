#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{
	template<class InputIterator1, class InputIterator2>
	bool equal(ImputIterator1 first1, InputIterator last, InputIterator first2){
		while(first1 != last){
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal( InputIterator1 first1, InputIterator1 last, InputIterator2 first2, BinaryPredicate pred ) {
		while (first1 != last) {
			if (!pred(*first1, *first2))
				return false;
			first1++; first2++;
		}
		return true;
	}
}

#endif