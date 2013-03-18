#ifndef ORMAX_H
#define ORMAX_H

#include "Or.h"

namespace Fuzzy 
{
	template<class T> 
	class OrMax: public Or<T>
	{
		public:
			T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template<class T>
	T OrMax<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->Evaluate();
		T r = right->Evaluate();

		return (l >= r )? l : r ;
	}
}

#endif