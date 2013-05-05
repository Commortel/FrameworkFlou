#ifndef ANDMULT_H
#define ANDMULT_H

#include "And.h"

namespace Fuzzy
{
	template <class T>
	class AndMult : public And<T>
	{
		public:
			virtual T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template <class T>
	T AndMult<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->Evaluate();
		T r = right->Evaluate();

		return l*r;
	}
}

#endif