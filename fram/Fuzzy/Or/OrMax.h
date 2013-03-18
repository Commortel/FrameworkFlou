#ifndef ORMAX_H_
#define ORMAX_H_
#include "Or.h"

namespace Fuzzy {

	template<class T> class OrMax: public Or<T>
	{
	public:
		OrMax(){};
		virtual ~OrMax(){};

		T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template<class T>
	T OrMax<T>::evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();

		return (l >= r )? l : r ;
	}
}

#endif