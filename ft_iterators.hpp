#if !defined(MUTANT_STACK_HPP)
#define MUTANT_STACK_HPP

namespace ft
{
	//template dos iteradores, é uma casca com os atributos que um iterator precisa;
	template<class Category, class T, class Distance, class Pointer, class Reference>
	struct iterator{
		typedef Category			iterator_category;
		typedef T					value_type;
		typedef Distance			difference_distance;
		typedef Pointer				pointer;
		typedef Reference			reference;
	}

	//tipos de acesso que um iterador pode receber, todo iterator tem um category, que dita, qual vão ser
	//as operações que esse iterador pode fazer
	struct input_iterator_tag{};
	struct output_itarator_tag{};
	struct forward_iterator_tag : public input_iterator_tag{};
	struct bidirectional_iterator_tag : public forward_iterator_tag{};
	struct random_access_iterator_tag : public bidirectional_iterator_tag{};


	//os tamplates de iterator_traits, existem 3 deles
	//O primeiro é o que se consome da classe Iterator.
	//Os outros dois vem de uma class T.
	template<class Iterator>
	struct iterator_traits{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_catedory;
	}

	template<class T>
	struct iterator_traits<T*>{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										*pointer;
		typedef t&										&reference;
		typedef random_access_iterator_tag				iterator_category;
	}

	template<class T>
	struct iterator_traits<const T*>{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								*pointer;
		typedef const t&								&reference;
		typedef random_access_iterator_tag				iterator_category;
	}


	template<class Iterator>
	//classe para o acesso random, que sera utilizado no container vector
	class random_access_iterator : public iterator< typename iterator_traits<Iterator>::iterator_category,
													typename iterator_traits<Iterator>::value_type,
													typename iterator_traits<Iterator>::difference_distance,
													typename iterator_traits<Iterator>::pointer,
													typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator	current;
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_distance	difference_distance;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			
			random_access_iterator(){};
			explicit random_access_iterator(Iterator it) : current(it){};
			//construtor de copia.
			random_access_iterator (const random_access_iterator<Iterator> &rai) : current (rai.getCurrent()) {};

			iterator_type	getCurrent() const 
			{return current;};

			reference				operator*()	const 
			{return *current;};

			random_access_iterator	operator+ (difference_type n) const
			{return random_access_iterator(current + n);}

			random_access_iterator	operator- (difference_type n) const
			{return random_access_iterator(current + n);};

			random_access_iterator	operator++ () const
			{
				current++;
				return(*this);
			}

			random_access_iterator	operator++ (int) const
			{
				current++;
				return(*this);
			}
			
			random_access_iterator	operator-- () const
			{
				current--;
				return(*this);
			}

			random_access_iterator	operator-- (int) const
			{
				current--;
				return(*this);
			}

			random_access_iterator	operator+= (difference_type n) const
			{
				current += n;
				return (*this);
			}

			random_access_iterator	operator-= (difference_type n) const
			{
				current -= n;
				return (*this);
			}

			pointer					operator->() const
			{return(&(this.operator*()))};

			reference				operator[](difference_type n) const
			{return (current[n]);};
	};

	
}

#endif
