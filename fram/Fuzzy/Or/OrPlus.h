#ifndef ORPLUS_H
#define ORPLUS_H

#include "Or.h"

namespace Fuzzy 
{
	template<class T> 
	class OrPlus: public Or<T>
	{
		public:
			T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template<class T>
	T OrPlus<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->Evaluate();
		T r = right->Evaluate();

		return ((l+r)<1)? (l+r):1;
	}
}

#endif